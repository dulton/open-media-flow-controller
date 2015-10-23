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
#ifndef JMFCNAMESPACEHTTPSERVERTABLE_INTERFACE_H
#define JMFCNAMESPACEHTTPSERVERTABLE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "jmfcNamespaceHttpServerTable.h"


    /*
     ********************************************************************
 * Table declarations
 */

    /*
     * PUBLIC interface initialization routine 
     */
    void           
        _jmfcNamespaceHttpServerTable_initialize_interface
        (jmfcNamespaceHttpServerTable_registration * user_ctx,
                                    u_long flags);
    void           
        _jmfcNamespaceHttpServerTable_shutdown_interface
        (jmfcNamespaceHttpServerTable_registration * user_ctx);

    jmfcNamespaceHttpServerTable_registration
        *jmfcNamespaceHttpServerTable_registration_get(void);

    jmfcNamespaceHttpServerTable_registration
        *jmfcNamespaceHttpServerTable_registration_set
        (jmfcNamespaceHttpServerTable_registration * newreg);

netsnmp_container *jmfcNamespaceHttpServerTable_container_get( void );
int jmfcNamespaceHttpServerTable_container_size( void );

    jmfcNamespaceHttpServerTable_rowreq_ctx
        *jmfcNamespaceHttpServerTable_allocate_rowreq_ctx(void);
    void           
        jmfcNamespaceHttpServerTable_release_rowreq_ctx
        (jmfcNamespaceHttpServerTable_rowreq_ctx * rowreq_ctx);

    int             jmfcNamespaceHttpServerTable_index_to_oid(netsnmp_index
                                                              * oid_idx,
                                                              jmfcNamespaceHttpServerTable_mib_index
                                                              * mib_idx);
    int            
        jmfcNamespaceHttpServerTable_index_from_oid(netsnmp_index *
                                                    oid_idx,
                                                    jmfcNamespaceHttpServerTable_mib_index
                                                    * mib_idx);

/*
 * access to certain internals. use with caution!
 */
    void           
        jmfcNamespaceHttpServerTable_valid_columns_set(netsnmp_column_info
                                                       *vc);


#ifdef __cplusplus
}
#endif
#endif /* JMFCNAMESPACEHTTPSERVERTABLE_INTERFACE_H */
