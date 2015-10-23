/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $ 
 *
 * $Id:$
 */
/** \page MFD helper for jmfcInterfaceTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "jmfcInterfaceTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "jmfcInterfaceTable_interface.h"

oid jmfcInterfaceTable_oid[] = { JMFCINTERFACETABLE_OID };
int jmfcInterfaceTable_oid_size = OID_LENGTH(jmfcInterfaceTable_oid);

    jmfcInterfaceTable_registration  jmfcInterfaceTable_user_context;

void initialize_table_jmfcInterfaceTable(void);
void shutdown_table_jmfcInterfaceTable(void);


/**
 * Initializes the jmfcInterfaceTable module
 */
void
init_jmfcInterfaceTable(void)
{
    DEBUGMSGTL(("verbose:jmfcInterfaceTable:init_jmfcInterfaceTable","called\n"));

    /*
     * TODO:300:o: Perform jmfcInterfaceTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("jmfcInterfaceTable"))
        initialize_table_jmfcInterfaceTable();

} /* init_jmfcInterfaceTable */

/**
 * Shut-down the jmfcInterfaceTable module (agent is exiting)
 */
void
shutdown_jmfcInterfaceTable(void)
{
    if (should_init("jmfcInterfaceTable"))
        shutdown_table_jmfcInterfaceTable();

}

/**
 * Initialize the table jmfcInterfaceTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_jmfcInterfaceTable(void)
{
    jmfcInterfaceTable_registration * user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:jmfcInterfaceTable:initialize_table_jmfcInterfaceTable","called\n"));

    /*
     * TODO:301:o: Perform jmfcInterfaceTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize jmfcInterfaceTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("jmfcInterfaceTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    _jmfcInterfaceTable_initialize_interface(user_context, flags);
} /* initialize_table_jmfcInterfaceTable */

/**
 * Shutdown the table jmfcInterfaceTable 
 */
void
shutdown_table_jmfcInterfaceTable(void)
{
    /*
     * call interface shutdown code
     */
    _jmfcInterfaceTable_shutdown_interface(&jmfcInterfaceTable_user_context);
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int
jmfcInterfaceTable_rowreq_ctx_init(jmfcInterfaceTable_rowreq_ctx *rowreq_ctx,
                           void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:jmfcInterfaceTable:jmfcInterfaceTable_rowreq_ctx_init","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:210:o: |-> Perform extra jmfcInterfaceTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
} /* jmfcInterfaceTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void jmfcInterfaceTable_rowreq_ctx_cleanup(jmfcInterfaceTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:jmfcInterfaceTable:jmfcInterfaceTable_rowreq_ctx_cleanup","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:211:o: |-> Perform extra jmfcInterfaceTable rowreq cleanup.
     */
} /* jmfcInterfaceTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
jmfcInterfaceTable_pre_request(jmfcInterfaceTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:jmfcInterfaceTable:jmfcInterfaceTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform jmfcInterfaceTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* jmfcInterfaceTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
jmfcInterfaceTable_post_request(jmfcInterfaceTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:jmfcInterfaceTable:jmfcInterfaceTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform jmfcInterfaceTable post-request actions.
     */

    return MFD_SUCCESS;
} /* jmfcInterfaceTable_post_request */


/** @{ */
