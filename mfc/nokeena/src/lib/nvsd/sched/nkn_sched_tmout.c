/*
 * (C) Copyright 2009 Nokeena Networks, Inc
 *
 * This file contains code which implements the timeout functionality for
 * the scheduler
 *
 * Author: Jeya ganesh babu
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/prctl.h>
#include "glib.h"
#include "nkn_sched_api.h"
#include "nkn_sched_task.h"
#include "assert.h"
#include "nkn_defs.h"
#include "nkn_debug.h"
#include "nkn_memalloc.h"
#ifdef UNIT_TEST
#define NKN_ASSERT assert
#else
#include "nkn_assert.h"
#endif

TAILQ_HEAD(nkn_sched_tmout_q, nkn_sched_tmout_obj_s) sched_tmout_q;
TAILQ_HEAD(nkn_sched_tmout_xfer_q, nkn_sched_tmout_obj_s) sched_tmout_xfer_q;
static pthread_t sched_tmout_thrd_obj;
static pthread_cond_t sched_timeout_cond;
static pthread_mutex_t sched_timeout_mutex;
int32_t glob_sched_def_timeout	    = 1;
int32_t sched_def_min_timeout	    = 1 * 1000 * 1000; /* 1 msec */
uint64_t glob_sched_timeout_calls   = 0;
uint64_t glob_sched_timeout_wakeup  = 0;
uint64_t glob_sched_timeout_xfers   = 0;
AO_t glob_nkn_tmout_obj_created   = 0;
AO_t glob_nkn_tmout_obj_deleted   = 0;

/* 
 * This is the main timeout thread.
 * Waits for entry in the sched_tmout_xfer_q. if entry is present, moves
 * it to the sorted sched_tmout_q. Does the timeout functionality based
 * on the first entry
 */
void *
nkn_sched_timeout_thread(void *dummy __attribute((unused)))
{
    struct timespec	    abstime;
    nkn_sched_tmout_obj_t   *tmout_objp;

    prctl(PR_SET_NAME, "nvsd-sched-tmout", 0, 0, 0);

    while(1) {
	pthread_mutex_lock(&sched_timeout_mutex);
	/* Pull from the xfer q and populate the tmout_q */
	while((tmout_objp = TAILQ_FIRST(&sched_tmout_xfer_q)) != NULL) {
	    nkn_sched_tmout_add_to_tmout_q(tmout_objp);
	    TAILQ_REMOVE(&sched_tmout_xfer_q, tmout_objp, xfer_entry);
	}
	/* Get the first entry and do the time check, as well 
	 * find the abstime to be given to cond_timedwait */
	tmout_objp = TAILQ_FIRST(&sched_tmout_q);
	NKN_ASSERT(glob_sched_def_timeout < 10);
	clock_gettime(CLOCK_MONOTONIC, &abstime);
	if(!tmout_objp) {
	    abstime.tv_sec += glob_sched_def_timeout;
	    abstime.tv_nsec = 0;
	} else {
	    if(tmout_objp->abstime.tv_sec) {
		if((abstime.tv_sec > tmout_objp->abstime.tv_sec)  ||
		    ((abstime.tv_sec == tmout_objp->abstime.tv_sec) &&
		    (abstime.tv_nsec >= tmout_objp->abstime.tv_nsec))) {
			nkn_sched_tmout_task_timed_wakeup(tmout_objp->tid);
		    TAILQ_REMOVE(&sched_tmout_q, tmout_objp, tmout_entry);
		    nkn_sched_tmout_cleanup_tmout_obj(tmout_objp);
		    pthread_mutex_unlock(&sched_timeout_mutex);
		    continue;
		} else {
		    abstime.tv_sec  = tmout_objp->abstime.tv_sec;
		    abstime.tv_nsec = tmout_objp->abstime.tv_nsec;
		}
	    } else {
		abstime.tv_sec += glob_sched_def_timeout;
		abstime.tv_nsec = 0;
	    }
	}
	pthread_cond_timedwait(&sched_timeout_cond, &sched_timeout_mutex,
		&abstime);
	pthread_mutex_unlock(&sched_timeout_mutex);
    }
}

/*
 * Function to add an object into the nkn_tmout_q in the sorted order
 */
void
nkn_sched_tmout_add_to_tmout_q(nkn_sched_tmout_obj_t *tmout_objp)
{
    nkn_sched_tmout_obj_t *tmp_objp = NULL, *prev_objp = NULL;

    tmp_objp = TAILQ_FIRST(&sched_tmout_q);
    while(tmp_objp) {
	if((tmp_objp->abstime.tv_sec > tmout_objp->abstime.tv_sec)
		|| ((tmp_objp->abstime.tv_sec == tmout_objp->abstime.tv_sec)
		&& (tmp_objp->abstime.tv_nsec > tmout_objp->abstime.tv_nsec)))
	    break;
	prev_objp = tmp_objp;
	tmp_objp = TAILQ_NEXT(tmp_objp, tmout_entry);
    }
    if(prev_objp)
	TAILQ_INSERT_AFTER(&sched_tmout_q, prev_objp, tmout_objp, tmout_entry);
    else
	TAILQ_INSERT_HEAD(&sched_tmout_q, tmout_objp, tmout_entry);
    glob_sched_timeout_xfers ++;
    return;
}

#ifdef UNIT_TEST
long tmout_sec[7];
long tmout_nsec[7];
#endif

/* 
 * Function to wakeup a task from wait
 */
void
nkn_sched_tmout_task_timed_wakeup(nkn_task_id_t tid)
{
#ifdef UNIT_TEST
    int ret_val = 0;
#endif
    glob_sched_timeout_wakeup ++;
#ifdef UNIT_TEST
    {
	struct timespec abstime;
	ret_val = clock_gettime(CLOCK_MONOTONIC, &abstime);
	assert(ret_val == 0);
	tmout_sec[(int)tid] = abstime.tv_sec;
	tmout_nsec[(int)tid] = abstime.tv_nsec;
    }
#endif
    nkn_task_set_state(tid, TASK_STATE_RUNNABLE);
}

/* 
 * Constructor function for the tmout_obj
 */
nkn_sched_tmout_obj_t *
nkn_sched_tmout_create_tmout_obj()
{
    nkn_sched_tmout_obj_t   *tmout_objp;
#ifdef UNIT_TEST
    tmout_objp = (nkn_sched_tmout_obj_t *) calloc (1,
		    sizeof(nkn_sched_tmout_obj_t));
#else
    tmout_objp = (nkn_sched_tmout_obj_t *) nkn_calloc_type (1,
		    sizeof(nkn_sched_tmout_obj_t), mod_sched_tmout_obj);
#endif
    if(tmout_objp == NULL) {
#ifndef UNIT_TEST
        DBG_LOG(SEVERE, MOD_SCHED, "Memory allocation failed");
        DBG_ERR(SEVERE, "Memory allocation failed");
#endif
	return NULL;
    }
    AO_fetch_and_add1(&glob_nkn_tmout_obj_created);
    return tmout_objp;
}

/* 
 * Destructor function for the tmout_obj
 */
void
nkn_sched_tmout_cleanup_tmout_obj(nkn_sched_tmout_obj_t *tmout_objp)
{
    if(tmout_objp) {
	free(tmout_objp);
	AO_fetch_and_add1(&glob_nkn_tmout_obj_deleted);
    } else {
	NKN_ASSERT(0);
    }
}

/* 
 * Function to add an entry into the tmout_xfer_q
 */
int
nkn_sched_tmout_add_to_tmout_queue(nkn_task_id_t tid, int msecs)
{
    nkn_sched_tmout_obj_t   *tmout_objp;
    int			    tmout_secs = 0;
    int			    ret_val = 0;

    tmout_objp = nkn_sched_tmout_create_tmout_obj();

    if(tmout_objp == NULL) {
	return -1;
    }
    tmout_objp->tid = tid;
    tmout_objp->msecs = msecs;
    ret_val = clock_gettime(CLOCK_MONOTONIC, &tmout_objp->abstime);
    NKN_ASSERT(ret_val == 0);
    tmout_secs = msecs / 1000;
    tmout_objp->abstime.tv_sec += tmout_secs;
    tmout_objp->abstime.tv_nsec += (msecs - (tmout_secs * 1000)) * 1000 * 1000;
    pthread_mutex_lock(&sched_timeout_mutex);
    glob_sched_timeout_calls ++;
    TAILQ_INSERT_TAIL(&sched_tmout_xfer_q, tmout_objp, xfer_entry);
    pthread_cond_signal(&sched_timeout_cond);
    pthread_mutex_unlock(&sched_timeout_mutex);
    return 0;
}

/*
 * Initializer function for the scheduler timout functionality
 */
int
nkn_sched_tmout_init()
{
    int ret;
    pthread_condattr_t a;

    ret = pthread_mutex_init(&sched_timeout_mutex, NULL);
    if(ret < 0) {
#ifndef UNIT_TEST
        DBG_LOG(SEVERE, MOD_SCHED, "Timeout mutex not created.");
        DBG_ERR(SEVERE, "Timeout mutex not created.");
#endif
        return -1;
    }
    pthread_condattr_init(&a);
    pthread_condattr_setclock(&a, CLOCK_MONOTONIC);

    pthread_cond_init(&sched_timeout_cond, &a);
    TAILQ_INIT(&sched_tmout_xfer_q);
    TAILQ_INIT(&sched_tmout_q);
    if ((ret = pthread_create(&sched_tmout_thrd_obj, NULL,
			      nkn_sched_timeout_thread, NULL))) {
        return -1;
    }
    return 0;
}

#ifdef UNIT_TEST
int
main(int argc, char **argv)
{
    struct timespec abstime;
    int		    i;
    int		    ret_val = 0;
    nkn_sched_tmout_init();
    ret_val = clock_gettime(CLOCK_MONOTONIC, &abstime);
    assert(ret_val == 0);
    printf("Test started at %ldsec %ldnsec\n", abstime.tv_sec, abstime.tv_nsec);
    fflush(stdout);
    nkn_task_timed_wait(0, 0);
    nkn_task_timed_wait(1, 2 );
    nkn_task_timed_wait(2, 1 );
    nkn_task_timed_wait(3, 5 );
    nkn_task_timed_wait(4, 1 * 10 );
    nkn_task_timed_wait(5, 6);
    nkn_task_timed_wait(6, 7);

    while(1) {
	sleep(10);
	if(glob_sched_timeout_wakeup == 7) {
	    for(i=0;i<7;i++)
		printf("Test %d timout at %ldsec %ldnsec\n",
			i, tmout_sec[i], tmout_nsec[i]);
	    break;
	}
    }
}

void
nkn_task_set_state(nkn_task_id_t tid, nkn_task_state_t state)
{
}

#endif
