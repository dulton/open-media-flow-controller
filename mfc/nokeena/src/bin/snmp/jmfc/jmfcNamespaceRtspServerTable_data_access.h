/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12854 $ of $
 *
 * $Id:$
 */
#ifndef JMFCNAMESPACERTSPSERVERTABLE_DATA_ACCESS_H
#define JMFCNAMESPACERTSPSERVERTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern "C" {
#endif


    /*
     *********************************************************************
 * function declarations
 */

    /*
     *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table jmfcNamespaceRtspServerTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * JUNIPER-MFC-MIB::jmfcNamespaceRtspServerTable is subid 5 of jmfcNamespace.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.2636.1.2.1.4.5, length: 12
*/


    int            
        jmfcNamespaceRtspServerTable_init_data
        (jmfcNamespaceRtspServerTable_registration *
         jmfcNamespaceRtspServerTable_reg);


    /*
     * TODO:180:o: Review jmfcNamespaceRtspServerTable cache timeout.
     * The number of seconds before the cache times out
     */
#define JMFCNAMESPACERTSPSERVERTABLE_CACHE_TIMEOUT   15

    void           
        jmfcNamespaceRtspServerTable_container_init(netsnmp_container **
                                                    container_ptr_ptr,
                             netsnmp_cache *cache);
    void           
        jmfcNamespaceRtspServerTable_container_shutdown(netsnmp_container *
                                                        container_ptr);

    int            
        jmfcNamespaceRtspServerTable_container_load(netsnmp_container *
                                                    container);
    void           
        jmfcNamespaceRtspServerTable_container_free(netsnmp_container *
                                                    container);

    int            
        jmfcNamespaceRtspServerTable_cache_load(netsnmp_container *
                                                container);
    void           
        jmfcNamespaceRtspServerTable_cache_free(netsnmp_container *
                                                container);

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
     *********************************************************************
 * Since we have no idea how you really access your data, we'll go with
 * a worst case example: a flat text file.
 */
#define MAX_LINE_SIZE 256
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    int            
        jmfcNamespaceRtspServerTable_row_prep
        (jmfcNamespaceRtspServerTable_rowreq_ctx * rowreq_ctx);



#ifdef __cplusplus
}
#endif
#endif /* JMFCNAMESPACERTSPSERVERTABLE_DATA_ACCESS_H */
