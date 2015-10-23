/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 15899 $ of $
 *
 * $Id:$
 */
/** @defgroup interface: Routines to interface to Net-SNMP
 *
 * \warning This code should not be modified, called directly,
 *          or used to interpret functionality. It is subject to
 *          change at any time.
 * 
 * @{
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 */
#ifndef JMFCNAMESPACETABLE_INTERFACE_H
#define JMFCNAMESPACETABLE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "jmfcNamespaceTable.h"


    /*
     ********************************************************************
 * Table declarations
 */

    /*
     * PUBLIC interface initialization routine 
     */
    void           
        _jmfcNamespaceTable_initialize_interface
        (jmfcNamespaceTable_registration * user_ctx, u_long flags);
    void           
        _jmfcNamespaceTable_shutdown_interface
        (jmfcNamespaceTable_registration * user_ctx);

    jmfcNamespaceTable_registration
        *jmfcNamespaceTable_registration_get(void);

    jmfcNamespaceTable_registration
        *jmfcNamespaceTable_registration_set
        (jmfcNamespaceTable_registration * newreg);

netsnmp_container *jmfcNamespaceTable_container_get( void );
int jmfcNamespaceTable_container_size( void );

    jmfcNamespaceTable_rowreq_ctx
        *jmfcNamespaceTable_allocate_rowreq_ctx(void);
    void           
        jmfcNamespaceTable_release_rowreq_ctx(jmfcNamespaceTable_rowreq_ctx
                                              * rowreq_ctx);

    int             jmfcNamespaceTable_index_to_oid(netsnmp_index *
                                                    oid_idx,
                                                    jmfcNamespaceTable_mib_index
                                                    * mib_idx);
    int             jmfcNamespaceTable_index_from_oid(netsnmp_index *
                                                      oid_idx,
                                                      jmfcNamespaceTable_mib_index
                                                      * mib_idx);

/*
 * access to certain internals. use with caution!
 */
    void           
        jmfcNamespaceTable_valid_columns_set(netsnmp_column_info *vc);


#ifdef __cplusplus
}
#endif
#endif /* JMFCNAMESPACETABLE_INTERFACE_H */
