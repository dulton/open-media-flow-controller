/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $ 
 *
 * $Id:$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "jmfcNamespaceHttpClientTable.h"
#include "jmfcNamespaceHttpClientTable_data_access.h"


#include "snmp_util.h"

/** @ingroup interface
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table jmfcNamespaceHttpClientTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * JUNIPER-MFC-MIB::jmfcNamespaceHttpClientTable is subid 2 of jmfcNamespace.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.2636.1.2.1.4.2, length: 12
 */

/**
 * initialization for jmfcNamespaceHttpClientTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param jmfcNamespaceHttpClientTable_reg
 *        Pointer to jmfcNamespaceHttpClientTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
jmfcNamespaceHttpClientTable_init_data
    (jmfcNamespaceHttpClientTable_registration *
     jmfcNamespaceHttpClientTable_reg)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_init_data", "called\n"));

    /*
     * TODO:303:o: Initialize jmfcNamespaceHttpClientTable data.
     */
    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     * if you are the sole writer for the file, you could
     * open it here. However, as stated earlier, we are assuming
     * the worst case, which in this case means that the file is
     * written to by someone else, and might not even exist when
     * we start up. So we can't do anything here.
     */
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/

    return MFD_SUCCESS;
}                               /* jmfcNamespaceHttpClientTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
jmfcNamespaceHttpClientTable_container_init(netsnmp_container **
                                            container_ptr_ptr,
                                            netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_container_init", "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to jmfcNamespaceHttpClientTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to jmfcNamespaceHttpClientTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up jmfcNamespaceHttpClientTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = JMFCNAMESPACEHTTPCLIENTTABLE_CACHE_TIMEOUT;        /* seconds */
}                               /* jmfcNamespaceHttpClientTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before jmfcNamespaceHttpClientTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
jmfcNamespaceHttpClientTable_container_shutdown(netsnmp_container *
                                                container_ptr)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_container_shutdown", "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to jmfcNamespaceHttpClientTable_container_shutdown\n");
        return;
    }

}                               /* jmfcNamespaceHttpClientTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement jmfcNamespaceHttpClientTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  jmfcNamespaceHttpClientTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
jmfcNamespaceHttpClientTable_container_load(netsnmp_container * container)
{
    jmfcNamespaceHttpClientTable_rowreq_ctx *rowreq_ctx;
    size_t          count = 0;

    /*
     * temporary storage for index values
     */
    /*
     * jmfcNamespaceName(2)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/h
     */
    char            jmfcNamespaceName[32];
    size_t          jmfcNamespaceName_len;


    /*
     * this example code is based on a data source that is a
     * text file to be read and parsed.
     */
    int err = 0, num_names = 0, idx = 0, rc = 0;
    tstr_array *names = NULL;
    const char *ns_name = NULL;
    node_name_t cnt_name = {0};
    uint64 value = 0;
    struct counter64 cnt64;

    DEBUGMSGTL(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_container_load","called\n"));

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    err = snmp_ns_get_names(&names);
    if (err) {
	rc = MFD_RESOURCE_UNAVAILABLE;
	bail_error(err);
    }
    num_names = tstr_array_length_quick(names);
    /* there are no namespaces, this is not an error */
    if (0 == num_names) {
	rc = MFD_END_OF_DATA;
	bail_error(0);
    }

    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/
    /*
     * TODO:351:M: |-> Load/update data in the jmfcNamespaceHttpClientTable container.
     * loop over your jmfcNamespaceHttpClientTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    while (1) {
        /*
         ***************************************************
         ***             START EXAMPLE CODE              ***
         ***---------------------------------------------***/

	if (idx >=  num_names) {
	    rc = MFD_END_OF_DATA;
        break;
	}
	ns_name = tstr_array_get_str_quick(names, idx);
	if (NULL == ns_name) {
	    idx++;
	    continue;
	}
	/* XXX - check for buffer overrun */
	bzero(jmfcNamespaceName, sizeof(jmfcNamespaceName));
	strncpy(jmfcNamespaceName, ns_name, sizeof(jmfcNamespaceName));
	jmfcNamespaceName[sizeof(jmfcNamespaceName) -1 ] = '\0';
	jmfcNamespaceName_len = strlen(jmfcNamespaceName);

        /*
         ***---------------------------------------------***
         ***              END  EXAMPLE CODE              ***
         ***************************************************/

        /*
         * TODO:352:M: |   |-> set indexes in new jmfcNamespaceHttpClientTable rowreq context.
         * data context will be set from the param (unless NULL,
         *      in which case a new data context will be allocated)
         */
        rowreq_ctx =
            jmfcNamespaceHttpClientTable_allocate_rowreq_ctx();
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if (MFD_SUCCESS !=
            jmfcNamespaceHttpClientTable_indexes_set(rowreq_ctx,
                                                     jmfcNamespaceName,
                                                     jmfcNamespaceName_len))
        {
            snmp_log(LOG_ERR,
                     "error setting index while loading "
                     "jmfcNamespaceHttpClientTable data.\n");
            jmfcNamespaceHttpClientTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate jmfcNamespaceHttpClientTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
        /*
         * TRANSIENT or semi-TRANSIENT data:
         * copy data or save any info needed to do it in row_prep.
         */
        /*
         * setup/save data for jmfcNamespaceHttpClientRequests
         * jmfcNamespaceHttpClientRequests(1)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.requests",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientRequests.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientRequests.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientResponses
         * jmfcNamespaceHttpClientResponses(2)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.responses",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientResponses.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientResponses.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientCacheHit
         * jmfcNamespaceHttpClientCacheHit(3)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.cache_hits",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientCacheHit.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientCacheHit.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientCacheMiss
         * jmfcNamespaceHttpClientCacheMiss(4)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.cache_miss",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientCacheMiss.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientCacheMiss.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientCachePartialHit
         * jmfcNamespaceHttpClientCachePartialHit(5)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.cache_partial",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientCachePartialHit.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientCachePartialHit.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientInBytes
         * jmfcNamespaceHttpClientInBytes(6)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.in_bytes",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientInBytes.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientInBytes.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientOutBytes
         * jmfcNamespaceHttpClientOutBytes(7)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.out_bytes",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientOutBytes.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientOutBytes.low =
            cnt64.low;

    /*
     * setup/save data for jmfcNamespaceHttpClientConns
     * jmfcNamespaceHttpClientConns(8)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.conns",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientConns.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientConns.low =
            cnt64.low;

    /** no mapping */
    /*
     * setup/save data for jmfcNamespaceHttpClientActiveConns
     * jmfcNamespaceHttpClientActiveConns(9)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.active_conns",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceHttpClientActiveConns.high =
	    cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientActiveConns.low =
	    cnt64.low;

    /** no mapping */
    /*
     * setup/save data for jmfcNamespaceHttpClientIdleConns
     * jmfcNamespaceHttpClientIdleConns(10)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.idle_conns",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceHttpClientIdleConns.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientIdleConns.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientStatus2xx
         * jmfcNamespaceHttpClientStatus2xx(11)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_2xx",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceHttpClientStatus2xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientStatus2xx.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientStatus3xx
         * jmfcNamespaceHttpClientStatus3xx(12)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_3xx",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceHttpClientStatus3xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientStatus3xx.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientStatus4xx
         * jmfcNamespaceHttpClientStatus4xx(13)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_4xx",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceHttpClientStatus4xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientStatus4xx.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientStatus5xx
         * jmfcNamespaceHttpClientStatus5xx(14)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_5xx",
		tstr_array_get_str_quick(names, idx));

	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClientStatus5xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClientStatus5xx.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClient404Count
         * jmfcNamespaceHttpClient404Count(15)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_404",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClient404Count.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClient404Count.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClient302Count
         * jmfcNamespaceHttpClient302Count(16)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_302",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClient302Count.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClient302Count.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClient304Count
         * jmfcNamespaceHttpClient304Count(17)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_304",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClient304Count.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClient304Count.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClient206Count
         * jmfcNamespaceHttpClient206Count(18)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_206",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClient206Count.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClient206Count.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClient200Count
         * jmfcNamespaceHttpClient200Count(19)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.resp_200",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceHttpClient200Count.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceHttpClient200Count.low =
            cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientTunBytes
         * jmfcNamespaceHttpClientTunBytes(20)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.out_bytes_tunnel",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
       rowreq_ctx->data.jmfcNamespaceHttpClientTunBytes.high = cnt64.high;
       rowreq_ctx->data.jmfcNamespaceHttpClientTunBytes.low = cnt64.low;

        /*
         * setup/save data for jmfcNamespaceHttpClientTunReq
         * jmfcNamespaceHttpClientTunReq(21)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.tunnels",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
       rowreq_ctx->data.jmfcNamespaceHttpClientTunReq.high = cnt64.high;
       rowreq_ctx->data.jmfcNamespaceHttpClientTunReq.low = cnt64.low;

        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
        ++count;
	++idx;
    }

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/

    DEBUGMSGT(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_container_load", "inserted %d records\n", (int)count));
bail:
    return rc;
}                               /* jmfcNamespaceHttpClientTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
jmfcNamespaceHttpClientTable_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_container_free", "called\n"));

    /*
     * TODO:380:M: Free jmfcNamespaceHttpClientTable container data.
     */
}                               /* jmfcNamespaceHttpClientTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
jmfcNamespaceHttpClientTable_row_prep
    (jmfcNamespaceHttpClientTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceHttpClientTable:jmfcNamespaceHttpClientTable_row_prep", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* jmfcNamespaceHttpClientTable_row_prep */

/** @} */
