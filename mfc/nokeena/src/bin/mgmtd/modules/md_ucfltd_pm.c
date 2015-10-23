/*
 *
 * Filename:  md_ucfltd_pm.c
 * Date:      2011-09-29
 * Author:    Bijoy Chandrasekharan
 *
 * (C) Copyright 2011 Nokeena Networks, Inc.
 * All rights reserved.
 *
 *
 */

/* ------------------------------------------------------------------------- */
/* md_ucfltd_pm.c: shows how to add new instances of wildcard nodes to
 * the initial database, and how to override defaults for nodes
 * created by Samara base components.  Also shows how to add a process
 * of yours to be launched and monitored by Process Manager.
 *
 * This module does not register any nodes of its own: it's sole
 * purpose is to add/change nodes in the initial database.  But there
 * would be no problem if we did want to register nodes here.
 */

#include "common.h"
#include "dso.h"
#include "md_mod_reg.h"
#include "md_upgrade.h"
#include "nkn_mgmt_common.h"

#define        UCFLTD_PATH         "/opt/nkn/sbin/ucfltd"
#define        UCFLTD_WORKING_DIR  "/coredump/ucfltd"
#define        UCFLTD_CONFIG_FILE  "/config/nkn/nkn.ucflt.conf"
#define        DEFAULT_WEBADMIN_PORT   "8080"

int md_ucfltd_pm_init(const lc_dso_info *info, void *data);
static md_upgrade_rule_array *md_ucfltd_pm_ug_rules = NULL;

/* ------------------------------------------------------------------------- */
/* In initial values, we are not required to specify values for nodes
 * underneath wildcards for which we want to accept the default.
 * Here we are just specifying the ones where the default is not what
 * we want, or where we don't want to rely on the default not changing.
 */
const bn_str_value md_ucfltd_pm_initial_values[] = {
    /* .....................................................................
     * ucfltd daemon: basic launch configuration.
     */
    {"/pm/process/ucfltd/launch_enabled", bt_bool, "true"},
    {"/pm/process/ucfltd/auto_launch", bt_bool, "true"},
    {"/pm/process/ucfltd/working_dir", bt_string, UCFLTD_WORKING_DIR},
    {"/pm/process/ucfltd/launch_path", bt_string, UCFLTD_PATH},
    {"/pm/process/ucfltd/launch_uid", bt_uint16, "0"},
    {"/pm/process/ucfltd/launch_gid", bt_uint16, "0"},
    {"/pm/process/ucfltd/kill_timeout", bt_duration_ms, "12000"},
    {"/pm/process/ucfltd/launch_params/1/param", bt_string, "-f"},
    {"/pm/process/ucfltd/launch_params/2/param", bt_string, UCFLTD_CONFIG_FILE},
    {"/pm/process/ucfltd/initial_launch_order", bt_int32, NKN_LAUNCH_ORDER_UCFLTD},
    {"/pm/process/ucfltd/initial_launch_timeout", bt_duration_ms, NKN_LAUNCH_TIMEOUT_UCFLTD},
    /* .....................................................................
     * Other samara node overrides
     */
    /* Set open files limit to a large value */
    {"/pm/process/ucfltd/fd_limit", bt_uint32, "64000"},
    /* 1000 MB = 1000 * 1024 * 1024 ; */
    {"/pm/process/ucfltd/memory_size_limit", bt_int64, "1048576000" },
    {"/pm/process/ucfltd/description", bt_string, "URL Category Filter"},
    {"/pm/process/ucfltd/environment/set/LD_LIBRARY_PATH", bt_string, "LD_LIBRARY_PATH"},
    {"/pm/process/ucfltd/environment/set/LD_LIBRARY_PATH/value", bt_string, "/opt/nkn/lib:/lib/nkn"},

    /* Set additional library paths that need to be saved in case of a core dump */
    {"/pm/process/ucfltd/save_paths/1", bt_uint8, "1"},
    {"/pm/process/ucfltd/save_paths/1/path", bt_string, "/lib/nkn"},
    {"/pm/process/ucfltd/save_paths/2", bt_uint8, "2"},
    {"/pm/process/ucfltd/save_paths/2/path", bt_string, "/opt/nkn/lib"},
};


/* ------------------------------------------------------------------------- */
static int
md_ucfltd_pm_add_initial(md_commit *commit, mdb_db *db, void *arg)
{
    int err = 0;

    err = mdb_create_node_bindings
        (commit, db, md_ucfltd_pm_initial_values,
         sizeof(md_ucfltd_pm_initial_values) / sizeof(bn_str_value));
    bail_error(err);

 bail:
    return(err);
}


/* ------------------------------------------------------------------------- */
int
md_ucfltd_pm_init(const lc_dso_info *info, void *data)
{
    int err = 0;
    md_module *module = NULL;
    md_reg_node *node = NULL;
    md_upgrade_rule *rule = NULL;
    md_upgrade_rule_array *ra = NULL;

    /*
     * Commit order of 200 is greater than the 0 used by most modules,
     * including md_pm.c.  This is to ensure that we can override some
     * of PM's global configuration, such as liveness grace period.
     *
     * We need modrf_namespace_unrestricted to allow us to set nodes
     * from our initial values function that are not underneath our
     * module root.
     */
    err = mdm_add_module(
	    "ucfltd_pm",			// module_name
	    0,				// module_version
	    "/nkn/ucfltd",			// root_node_name
	    NULL,				// root_config_name
	    0,				// md_mod_flags
	    NULL,				// side_effects_func
	    NULL,				// side_effects_arg
	    NULL,				// check_func
	    NULL,				// check_arg
	    NULL,				// apply_func
	    NULL,				// apply_arg
	    300,				// commit_order
	    0,				// apply_order
	    md_generic_upgrade_downgrade,	// updown_func
	    &md_ucfltd_pm_ug_rules,		// updown_arg
	    md_ucfltd_pm_add_initial,	// initial_func
	    NULL,				// initial_arg
	    NULL,				// mon_get_func
	    NULL,				// mon_get_arg
	    NULL,				// mon_iterate_func
	    NULL,				// mon_iterate_arg
	    &module);			// ret_module
    bail_error(err);

    /* Upgrade processing nodes */
    err = md_upgrade_rule_array_new(&md_ucfltd_pm_ug_rules);
    bail_error(err);
    ra = md_ucfltd_pm_ug_rules;

bail:
    return(err);
}

