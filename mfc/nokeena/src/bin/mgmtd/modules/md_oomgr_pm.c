/*
 *
 * Filename:    md_oomgr_pm.c
 * Date:        2008-11-13
 * Author:      Dhruva Narasimhan
 *
 * (C) Copyright 2008 Nokeena Networks, Inc.
 * All rights reserved/
 *
 */

/*----------------------------------------------------------------------------
 * md_oomgr_pm.c: shows how the nkn_oomgr module is added to
 * the initial PM database.
 *
 * This module does not register any nodes of its own. Its sole purpose
 * is to add/change nodes in the initial database.
 *---------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 * HEADER FILES
 *---------------------------------------------------------------------------*/
#include "common.h"
#include "dso.h"
#include "md_mod_reg.h"
#include "md_upgrade.h"
#include "nkn_mgmt_common.h"

/*----------------------------------------------------------------------------
 * PREPROCESSOR MACROS/CONSTANTS
 *---------------------------------------------------------------------------*/
#define NKN_OOMGR_PATH          "/opt/nkn/sbin/nkn_oomgr"
#define NKN_OOMGR_WORKING_DIR   "/coredump/nkn_oomgr"
#define DEFAULT_SERVER_IP       "127.0.0.1"
#define DEFAULT_SERVER_PORT     "80"


/*----------------------------------------------------------------------------
 * PRIVATE VARIABLE DECLARATIONS
 *---------------------------------------------------------------------------*/
static md_upgrade_rule_array *md_oomgr_pm_ug_rules = NULL;

static const bn_str_value md_oomgr_pm_initial_values[] = {
        /*
         * nknoomgr : basic launch configuration.
         */
        {"/pm/process/nknoomgr/launch_enabled", bt_bool, "true"},
        {"/pm/process/nknoomgr/auto_launch", bt_bool, "true"},
        {"/pm/process/nknoomgr/working_dir", bt_string, NKN_OOMGR_WORKING_DIR},
        {"/pm/process/nknoomgr/launch_path", bt_string, NKN_OOMGR_PATH},
        {"/pm/process/nknoomgr/launch_uid", bt_uint16, "0"},
        {"/pm/process/nknoomgr/launch_gid", bt_uint16, "0"},
        {"/pm/process/nknoomgr/launch_params/1/param", bt_string, "-D"},
        {"/pm/process/nknoomgr/launch_params/2/param", bt_string, "-c"},

        {"/pm/process/nknoomgr/initial_launch_order", bt_int32, NKN_LAUNCH_ORDER_OOMGR},
        {"/pm/process/nknoomgr/initial_launch_timeout", bt_duration_ms, NKN_LAUNCH_TIMEOUT_OOMGR},

};

/*----------------------------------------------------------------------------
 * FUNCTION DECLARATIONS
 *---------------------------------------------------------------------------*/
int md_oomgr_pm_init(const lc_dso_info *info, void *data);


static int md_nkn_pm_add_initial(md_commit *commit, mdb_db *db, void *arg)
{
    int err = 0;

    err = mdb_create_node_bindings(
	    commit,
	    db,
	    md_oomgr_pm_initial_values,
	    sizeof(md_oomgr_pm_initial_values)/ sizeof(bn_str_value));
    bail_error(err);

bail:
    return err;
}

int
md_oomgr_pm_init(const lc_dso_info *info, void *data)
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
	    "oomgr_pm",
	    2,
	    "/pm/nokeena/oomgr",
	    NULL,
	    modrf_namespace_unrestricted,
	    NULL,
	    NULL,
	    NULL,
	    NULL,
	    NULL,
	    NULL,
	    200,
	    0,
	    md_generic_upgrade_downgrade,
	    &md_oomgr_pm_ug_rules,
	    md_nkn_pm_add_initial,
	    NULL,
	    NULL,
	    NULL,
	    NULL,
	    NULL,
	    &module);
    bail_error(err);


    /**********************************************************************
     *              UPGRADE RULES
     *********************************************************************/
    err = md_upgrade_rule_array_new(&md_oomgr_pm_ug_rules);
    bail_error(err);

    ra = md_oomgr_pm_ug_rules;

    MD_NEW_RULE(ra, 1, 2);
    rule->mur_upgrade_type =        MUTT_MODIFY;
    rule->mur_name =                "/pm/process/nknoomgr/initial_launch_order";
    rule->mur_new_value_type =      bt_int32;
    rule->mur_new_value_str =       NKN_LAUNCH_ORDER_OOMGR;
    MD_ADD_RULE(ra);

    MD_NEW_RULE(ra, 1, 2);
    rule->mur_upgrade_type =        MUTT_MODIFY;
    rule->mur_name =                "/pm/process/nknoomgr/initial_launch_timeout";
    rule->mur_new_value_type =      bt_duration_ms;
    rule->mur_new_value_str =       NKN_LAUNCH_TIMEOUT_OOMGR;
    MD_ADD_RULE(ra);


bail:
    return err;
}

