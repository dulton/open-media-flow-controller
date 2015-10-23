/*
 *
 * Filename:    md_zebra_pm.c
 * Date:        2011-09-09
 * Author:      Manikandan Vengatachalam
 *
 * (C) Copyright 2011 Juniper Networks, Inc.
 * All rights reserved
 *
 */

/*----------------------------------------------------------------------------
 * md_zebra_pm.c: shows how the bgpd module is added to
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
#define ZEBRA_PATH          "/usr/local/sbin/zebra"
#define ZEBRA_WORKING_DIR   "/coredump/zebra"

/*----------------------------------------------------------------------------
 * PRIVATE VARIABLE DECLARATIONS
 *---------------------------------------------------------------------------*/
static md_upgrade_rule_array *md_zebra_pm_ug_rules = NULL;

static const bn_str_value md_zebra_pm_initial_values[] = {
    /*
     * zebra : basic launch configuration.
     */
    {"/pm/process/zebra/launch_enabled", bt_bool, "true"},
    {"/pm/process/zebra/auto_launch", bt_bool, "true"},
    {"/pm/process/zebra/delete_trespassers", bt_bool, "false"},
    {"/pm/process/zebra/working_dir", bt_string, ZEBRA_WORKING_DIR},
    {"/pm/process/zebra/launch_path", bt_string, ZEBRA_PATH},
    {"/pm/process/zebra/launch_uid", bt_uint16, "0"},
    {"/pm/process/zebra/launch_gid", bt_uint16, "0"},
    {"/pm/process/zebra/initial_launch_order", bt_int32, ZEBRA_LAUNCH_ORDER},
    {"/pm/process/zebra/initial_launch_timeout", bt_duration_ms, ZEBRA_LAUNCH_TIMEOUT},
};

/*----------------------------------------------------------------------------
 * FUNCTION DECLARATIONS
 *---------------------------------------------------------------------------*/
int md_zebra_pm_init(const lc_dso_info *info, void *data);


static int md_nkn_pm_add_initial(md_commit *commit, mdb_db *db, void *arg)
{
    int err = 0;

    err = mdb_create_node_bindings(
	    commit,
	    db,
	    md_zebra_pm_initial_values,
	    sizeof(md_zebra_pm_initial_values)/ sizeof(bn_str_value));
    bail_error(err);

bail:
    return err;
}

int
md_zebra_pm_init(const lc_dso_info *info, void *data)
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
                    "zebra",
                    2,
                    "/pm/nokeena/zebra",
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
                    &md_zebra_pm_ug_rules,
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
    err = md_upgrade_rule_array_new(&md_zebra_pm_ug_rules);
    bail_error(err);

    ra = md_zebra_pm_ug_rules;

    MD_NEW_RULE(ra, 1, 2);
    rule->mur_upgrade_type =        MUTT_DELETE;
    rule->mur_name =                "/pm/process/zebra/launch_params/1/param";
    MD_ADD_RULE(ra);

    MD_NEW_RULE(ra, 1, 2);
    rule->mur_upgrade_type =        MUTT_MODIFY;
    rule->mur_name =                "/pm/process/zebra/auto_launch";
    rule->mur_new_value_type =      bt_bool;
    rule->mur_new_value_str =       "true";
    MD_ADD_RULE(ra);

bail:
    return err;
}

