/*
 * @file diameter_avp.h
 * @brief
 * diameter_avp.h - declarations for diameter avps and functionts
 *
 * Yuvaraja Mariappan, Dec 2014
 *
 * Copyright (c) 2015, Juniper Networks, Inc.
 * All rights reserved.
 *
 */

#ifndef _DIAMETER_AVP_H
#define _DIAMETER_AVP_H

#include "sys/jnx/types.h"
#include "jnx/diameter_avp_common_defs.h"
#include "jnx/diameter_base_api.h"
#include "jnx/dia_avp_dict_api.h"

#define AAA_DIAM_MAX_SUPPORTED_AVPS (AAA_DIAM_AVP_MAX-1)

#define AAA_DIAM_MAX_PARENT_AVPS	    7
#define AAA_DIAM_MAX_DIC_NAME_SIZE	    32
#define AAA_DIAM_MAX_AVP_NAME_LEN	    255

/* Flags indicating Apps. */
#define AAA_DIAM_DICT_APP_GX    1
#define AAA_DIAM_DICT_APP_GY    2

typedef enum aaa_diam_avp_list_e {
	AAA_DIAM_AVP_UNDEFINED = 0,
	/* List all the Grouped AVPs in the beginning */
	/* Gx specific Grouped AVPs */
	AAA_DIAM_AVP_SUPPORTED_FEATURES,
	AAA_DIAM_AVP_PACKET_FILTER_INFORMATION,
	AAA_DIAM_AVP_QOS_INFORMATION,
	AAA_DIAM_AVP_ALLOCATION_RETENTION_PRIORITY,
	AAA_DIAM_AVP_DEFAULT_EPS_BEARER_QOS,
	AAA_DIAM_AVP_TFT_PACKET_FILTER_INFORMATION,
	AAA_DIAM_AVP_CHARGING_RULE_REPORT,
	AAA_DIAM_AVP_EVENT_REPORT_INDICATION,
	AAA_DIAM_AVP_ACCESS_NETWORK_CHARGING_IDENTIFIER_GX,
	AAA_DIAM_AVP_CHARGING_RULE_REMOVE,
	/*---------------- 10 ----------------*/
	AAA_DIAM_AVP_CHARGING_RULE_INSTALL,
	AAA_DIAM_AVP_CHARGING_RULE_DEFINITION,
	AAA_DIAM_AVP_FLOW_INFORMATION,
	AAA_DIAM_AVP_FLOWS,
	AAA_DIAM_AVP_CHARGING_INFORMATION,
	AAA_DIAM_AVP_FINAL_UNIT_INDICATION,
	AAA_DIAM_AVP_REDIRECT_SERVER,
	AAA_DIAM_AVP_USER_CSG_INFORMATION,
	AAA_DIAM_AVP_TRACE_DATA,
	AAA_DIAM_AVP_USAGE_MONITORING_INFO,
	/*---------------- 20 ----------------*/
	AAA_DIAM_AVP_COA_INFORMATION,
	AAA_DIAM_AVP_TUNNEL_INFO,
	/* Gy specific Grouped AVPs */
	AAA_DIAM_AVP_SUBSCRIPTION_ID,
	AAA_DIAM_AVP_MULT_SERVICES_CREDIT_CTRL,
	AAA_DIAM_AVP_GRANTED_SERVICE_UNIT,
	AAA_DIAM_AVP_REQ_SERVICE_UNIT,
	AAA_DIAM_AVP_USED_SERVICE_UNIT,
	AAA_DIAM_AVP_GSU_POOL_REF,
	AAA_DIAM_AVP_CC_MONEY,
	AAA_DIAM_AVP_ENVELOPE,
	/*---------------- 30 ----------------*/
	AAA_DIAM_AVP_UNIT_VALUE,
	AAA_DIAM_AVP_TRIGGER,
	AAA_DIAM_AVP_AF_CORRELATION_INFO,
	AAA_DIAM_AVP_SERVICE_SPECIFIC_INFO,
	AAA_DIAM_AVP_USER_EQUIPMENT_INFO,
	AAA_DIAM_AVP_PROXY_INFO,
	AAA_DIAM_AVP_SERVICE_INFO,
	AAA_DIAM_AVP_AOC_INFO,
	AAA_DIAM_AVP_AOC_COST_INFO,
	AAA_DIAM_AVP_ACCUMULATED_COST,
	/*---------------- 40 ----------------*/
	AAA_DIAM_AVP_INCREMENTAL_COST,
	AAA_DIAM_AVP_TARIFF_INFO,
	AAA_DIAM_AVP_CURRENT_TARIFF,
	AAA_DIAM_AVP_SCALE_FACTOR,
	AAA_DIAM_AVP_RATE_ELEMENT,
	AAA_DIAM_AVP_UNIT_COST,
	AAA_DIAM_AVP_NEXT_TARIFF,
	AAA_DIAM_AVP_AOC_SUBSCRIPTION_INFO,
	AAA_DIAM_AVP_AOC_SERVICE,
	AAA_DIAM_AVP_PS_INFORMATION,
	/*---------------- 50 ----------------*/
	AAA_DIAM_AVP_PS_FURNISH_CHARGE_INFO,
	AAA_DIAM_AVP_OFFLINE_CHARGING,
	AAA_DIAM_AVP_TIME_QUOTA_MECHANISM,
	AAA_DIAM_AVP_TRAFFIC_DATA_VOL,
	AAA_DIAM_AVP_SERVICE_DATA_CONTAINER,
	AAA_DIAM_AVP_FAILED_AVP,
	AAA_DIAM_AVP_TERMINAL_INFO,
	AAA_DIAM_AVP_E2E_SEQUENCE,
	AAA_DIAM_AVP_EXPERIMENTAL_RESULT,
	AAA_DIAM_AVP_VENDOR_SPECIFIC_APP_ID,
	/*---------------- 60 ----------------*/
	/* List of other Gx AVPs */
	AAA_DIAM_AVP_USAGE_MONITORING_LEVEL,
	AAA_DIAM_AVP_USAGE_MONITORING_REPORT,
	AAA_DIAM_AVP_USAGE_MONITORING_SUPPORT,
	AAA_DIAM_AVP_COA_IP_ADDR,
	AAA_DIAM_AVP_TUNNEL_HEADER_LEN,
	AAA_DIAM_AVP_TUNNEL_HEADER_FILTER,
	AAA_DIAM_AVP_VENDOR_ID,
	AAA_DIAM_AVP_FEATURE_LIST_ID,
	AAA_DIAM_AVP_FEATURE_LIST,
	AAA_DIAM_AVP_NETWORK_REQUEST_SUPPORT,
	/*---------------- 70 ----------------*/
	AAA_DIAM_AVP_PCC_RULE_STATUS,
	AAA_DIAM_AVP_RULE_FAILURE_CODE,
	AAA_DIAM_AVP_RULE_ACTIVATION_TIME,
	AAA_DIAM_AVP_RULE_DEACTIVATION_TIME,
	AAA_DIAM_AVP_RESOURCE_ALLOCATION_NOTIFICATION,
	AAA_DIAM_AVP_CHARGING_CORRELATION_INDICATOR,
	AAA_DIAM_AVP_PACKET_FILTER_CONTENT,
	AAA_DIAM_AVP_PACKET_FILTER_IDENTIFIER,
	AAA_DIAM_AVP_PRECEDENCE,
	AAA_DIAM_AVP_TOS_TRAFFIC_CLASS,
	/*---------------- 80 ----------------*/
	AAA_DIAM_AVP_SECURITY_PARAMETER_INDEX,
	AAA_DIAM_AVP_FLOW_LABEL,
	AAA_DIAM_AVP_FLOW_DIRECTION,
	AAA_DIAM_AVP_PACKET_FILTER_OPERATION,
	AAA_DIAM_AVP_3GPP_SGSN_ADDRESS,
	AAA_DIAM_AVP_3GPP_USER_LOCATION_INFO,
	AAA_DIAM_AVP_3GPP_MS_TIMEZONE,
	AAA_DIAM_AVP_RAI,
	AAA_DIAM_AVP_EVENT_TRIGGER,
	AAA_DIAM_AVP_MAX_REQUESTED_BANDWIDTH_UL,
	/*---------------- 90 ----------------*/
	AAA_DIAM_AVP_MAX_REQUESTED_BANDWIDTH_DL,
	AAA_DIAM_AVP_GUARANTEED_BITRATE_UL,
	AAA_DIAM_AVP_GUARANTEED_BITRATE_DL,
	AAA_DIAM_AVP_TRACE_REFERENCE,
	AAA_DIAM_AVP_TRACE_DEPTH,
	AAA_DIAM_AVP_TRACE_NE_TYPE_LIST,
	AAA_DIAM_AVP_TRACE_INTERFACE_LIST,
	AAA_DIAM_AVP_TRACE_EVENT_LIST,
	AAA_DIAM_AVP_OMC_ID,
	AAA_DIAM_AVP_TRACE_COLLECTION_ENTITY,
	/*---------------- 100 ----------------*/
	AAA_DIAM_AVP_BEARER_IDENTIFIER,
	AAA_DIAM_AVP_BEARER_OPERATION,
	AAA_DIAM_AVP_FRAMED_IP_ADDRESS,
	AAA_DIAM_AVP_FRAMED_IPV6_PREFIX,
	AAA_DIAM_AVP_IP_CAN_TYPE,
	AAA_DIAM_AVP_3GPP_RAT_TYPE,
	AAA_DIAM_AVP_QOS_CLASS_IDENTIFIER,
	AAA_DIAM_AVP_APN_AGGREGATE_MAX_BITRATE_UL,
	AAA_DIAM_AVP_APN_AGGREGATE_MAX_BITRATE_DL,
	AAA_DIAM_AVP_QOS_NEGOTIATION,
	/*---------------- 110 ----------------*/
	AAA_DIAM_AVP_QOS_UPGRADE,
	AAA_DIAM_AVP_AN_GW_ADDRESS,
	AAA_DIAM_AVP_3GPP_SGSN_MCC_MNC,
	AAA_DIAM_AVP_3GPP_SGSN_IPV6_ADDRESS,
	AAA_DIAM_AVP_PDN_CONNECTION_ID,
	AAA_DIAM_AVP_BEARER_USAGE,
	AAA_DIAM_AVP_ONLINE,
	AAA_DIAM_AVP_OFFLINE,
	AAA_DIAM_AVP_TFT_FILTER,
	AAA_DIAM_AVP_CHARGING_RULE_NAME,
	/*---------------- 120 ----------------*/
	AAA_DIAM_AVP_CHARGING_RULE_BASE_NAME,
	AAA_DIAM_AVP_ACCESS_NETWORK_CHARGING_ADDRESS,
	AAA_DIAM_AVP_BEARER_CONTROL_MODE,
	AAA_DIAM_AVP_SERVICE_IDENTIFIER,
	AAA_DIAM_AVP_RATING_GROUP,
	AAA_DIAM_AVP_FLOW_DESCRIPTION,
	AAA_DIAM_AVP_PACKET_FILTER_USAGE,
	AAA_DIAM_AVP_FLOW_STATUS,
	AAA_DIAM_AVP_REPORTING_LEVEL,
	AAA_DIAM_AVP_METERING_METHOD,
	/*---------------- 130 ----------------*/
	AAA_DIAM_AVP_AF_CHARGING_IDENTIFIER,
	AAA_DIAM_AVP_MEDIA_COMPONENT_NUMBER,
	AAA_DIAM_AVP_FLOW_NUMBER,
	AAA_DIAM_AVP_FINAL_UNIT_ACTION,
	AAA_DIAM_AVP_AF_SIGNALLING_PROTOCOL,
	AAA_DIAM_AVP_PRIMARY_EVENT_CHARGING_FUNCTION_NAME,
	AAA_DIAM_AVP_SECONDARY_EVENT_CHARGING_FUNCTION_NAME,
	AAA_DIAM_AVP_PRIMARY_CHARGING_COLLECTION_FUNCTION_NAME,
	AAA_DIAM_AVP_SECONDARY_CHARGING_COLLECTION_FUNCTION_NAME,
	AAA_DIAM_AVP_REVALIDATION_TIME,
	/*---------------- 140 ----------------*/
	AAA_DIAM_AVP_PRIORITY_LEVEL,
	AAA_DIAM_AVP_PREEMPTION_CAPABILITY,
	AAA_DIAM_AVP_PREEMPTION_VULNERABILITY,
	AAA_DIAM_AVP_ACCESS_NETWORK_CHARGING_IDENTIFIER_VALUE,
	AAA_DIAM_AVP_MONITORING_KEY,
	AAA_DIAM_AVP_RESTRICTION_FILTER_RULE,
	AAA_DIAM_AVP_FILTER_ID,
	AAA_DIAM_AVP_REDIRECT_ADDRESS_TYPE,
	AAA_DIAM_AVP_REDIRECT_SERVER_ADDRESS,
	AAA_DIAM_AVP_RAT_TYPE,
	/*---------------- 150 ----------------*/
	AAA_DIAM_AVP_CSG_ID,
	AAA_DIAM_AVP_CSG_ACCESS_MODE,
	AAA_DIAM_AVP_CSG_MEMBERSHIP_INDICATION,
	/* List of other Gy AVPs */
	AAA_DIAM_AVP_SESSION_ID,
	AAA_DIAM_AVP_ORIGIN_HOST,
	AAA_DIAM_AVP_ORIGIN_REALM,
	AAA_DIAM_AVP_DEST_REALM,
	AAA_DIAM_AVP_AUTH_APP_ID,
	AAA_DIAM_AVP_ORIGIN_STATE_ID,
	AAA_DIAM_AVP_SERVICE_CTX_ID,
	/*---------------- 160 ----------------*/
	AAA_DIAM_AVP_CC_REQ_TYPE,
	AAA_DIAM_AVP_CC_REQ_NUM,
	AAA_DIAM_AVP_DEST_HOST,
	AAA_DIAM_AVP_USER_NAME,
	AAA_DIAM_AVP_EVENT_TIMESTAMP,
	AAA_DIAM_AVP_SUBSCRIPTION_ID_TYPE,
	AAA_DIAM_AVP_SUBSCRIPTION_ID_DATA,
	AAA_DIAM_AVP_TERMINATION_CAUSE,
	AAA_DIAM_AVP_MULT_SERVICES_ID,
	AAA_DIAM_AVP_TARIFF_CHANGE_USAGE,
	/*---------------- 170 ----------------*/
	AAA_DIAM_AVP_VALIDITY_TIME,
	AAA_DIAM_AVP_RESULT_CODE,
	AAA_DIAM_AVP_TARIFF_TIME_CHANGE,
	AAA_DIAM_AVP_CC_TIME,
	AAA_DIAM_AVP_CC_TOTAL_OCTETS,
	AAA_DIAM_AVP_CC_INPUT_OCTETS,
	AAA_DIAM_AVP_CC_OUTPUT_OCTETS,
	AAA_DIAM_AVP_CC_SERVICE_SPECIFIC_UNITS,
	AAA_DIAM_AVP_GSU_POOL_ID,
	AAA_DIAM_AVP_CC_UNIT_TYPE,
	/*---------------- 180 ----------------*/
	AAA_DIAM_AVP_CURRENCY_CODE,
	AAA_DIAM_AVP_VALUE_DIGITS,
	AAA_DIAM_AVP_EXPONENT,
	AAA_DIAM_AVP_REPORTING_REASON,
	AAA_DIAM_AVP_TRIGGER_TYPE,
	AAA_DIAM_AVP_ENVELOPE_START_TIME,
	AAA_DIAM_AVP_ENVELOPE_END_TIME,
	AAA_DIAM_AVP_SERVICE_SPECIFIC_DATA,
	AAA_DIAM_AVP_SERVICE_SPECIFIC_TYPE,
	AAA_DIAM_AVP_USER_EQUIPMENT_INFO_TYPE,
	/*---------------- 190 ----------------*/
	AAA_DIAM_AVP_USER_EQUIPMENT_INFO_VALUE,
	AAA_DIAM_AVP_PROXY_HOST,
	AAA_DIAM_AVP_PROXY_STATE,
	AAA_DIAM_AVP_ROUTE_RECORD,
	AAA_DIAM_AVP_REASON_CODE,
	AAA_DIAM_AVP_UNIT_QUOTA_THRESHOLD,
	AAA_DIAM_AVP_AOC_SERVICE_OBLIGATORY_TYPE,
	AAA_DIAM_AVP_AOC_SERVICE_TYPE,
	AAA_DIAM_AVP_AOC_FORMAT,
	AAA_DIAM_AVP_PREFERRED_AOC_CURRENCY,
	/*---------------- 200 ----------------*/
	AAA_DIAM_AVP_3GPP_CHARGING_ID,
	AAA_DIAM_AVP_NODE_ID,
	AAA_DIAM_AVP_3GPP_PDP_TYPE,
	AAA_DIAM_AVP_PDP_ADDRESS,
	AAA_DIAM_AVP_DYNAMIC_ADDRESS_FLAG,
	AAA_DIAM_AVP_SGSN_ADDRESS,
	AAA_DIAM_AVP_GGSN_ADDRESS,
	AAA_DIAM_AVP_SGW_ADDRESS,
	AAA_DIAM_AVP_CG_ADDRESS,
	AAA_DIAM_AVP_SERVING_NODE_TYPE,
	/*---------------- 210 ----------------*/
	AAA_DIAM_AVP_SGW_CHANGE,
	AAA_DIAM_AVP_3GPP_IMSI_MCC_MNC,
	AAA_DIAM_AVP_IMSI_UNAUTH_FLAG,
	AAA_DIAM_AVP_3GPP_GGSN_MCC_MNC,
	AAA_DIAM_AVP_3GPP_NSAPI,
	AAA_DIAM_AVP_CALLED_STATION_ID,
	AAA_DIAM_AVP_3GPP_SELECTION_MODE,
	AAA_DIAM_AVP_3GPP_CHARGING_CHAR,
	AAA_DIAM_AVP_CHARGING_CHAR_SEL_MODE,
	AAA_DIAM_AVP_PS_FREE_FORMAT_DATA,
	/*---------------- 220 ----------------*/
	AAA_DIAM_AVP_PS_APPEND_FREE_FORMAT_DATA,
	AAA_DIAM_AVP_PDP_CTXT_TYPE,
	AAA_DIAM_AVP_QUOTA_CONSUMPTION_TIME,
	AAA_DIAM_AVP_TIME_QUOTA_TYPE,
	AAA_DIAM_AVP_BASE_TIME_INTERVAL,
	AAA_DIAM_AVP_ENVELOPE_REPORTING,
	AAA_DIAM_AVP_ACCOUNTING_INPUT_OCTETS,
	AAA_DIAM_AVP_ACCOUNTING_INPUT_PKTS,
	AAA_DIAM_AVP_ACCOUNTING_OUTPUT_OCTETS,
	AAA_DIAM_AVP_ACCOUNTING_OUTPUT_PKTS,
	/*---------------- 230 ----------------*/
	AAA_DIAM_AVP_CHANGE_TIME,
	AAA_DIAM_AVP_LOCAL_SEQ_NUM,
	AAA_DIAM_AVP_TIME_FIRST_USAGE,
	AAA_DIAM_AVP_TIME_LAST_USAGE,
	AAA_DIAM_AVP_TIME_USAGE,
	AAA_DIAM_AVP_START_TIME,
	AAA_DIAM_AVP_STOP_TIME,
	AAA_DIAM_AVP_CHANGE_CONDITION,
	AAA_DIAM_AVP_DIAGNOSTICS,
	AAA_DIAM_AVP_CC_SESSION_FAILOVER,
	/*---------------- 240 ----------------*/
	AAA_DIAM_AVP_TIME_QUOTA_THRESHOLD,
	AAA_DIAM_AVP_VOL_QUOTA_THRESHOLD,
	AAA_DIAM_AVP_QUOTA_HOLDING_TIME,
	AAA_DIAM_AVP_CREDIT_CTRL_FAIL_HANDLING,
	AAA_DIAM_AVP_REDIRECT_HOST,
	AAA_DIAM_AVP_REDIRECT_HOST_USAGE,
	AAA_DIAM_AVP_REDIRECT_MAX_CACHE_TIME,
	AAA_DIAM_AVP_REAUTH_REQ_TYPE,
	AAA_DIAM_AVP_ERROR_MESSAGE,
	AAA_DIAM_AVP_IMEI,
	/*---------------- 250 ----------------*/
	AAA_DIAM_AVP_SOFTWARE_VERSION,
	/* Other AVPs from RFC3588 */
	AAA_DIAM_AVP_ACCT_INTERIM_INTERVAL,
	AAA_DIAM_AVP_ACCT_REALTIME_REQUIRED,
	AAA_DIAM_AVP_ACCT_MULTI_SESSION_ID,
	AAA_DIAM_AVP_ACCT_RECORD_NUM,
	AAA_DIAM_AVP_ACCT_RECORD_TYPE,
	AAA_DIAM_AVP_ACCT_SESSION_ID,
	AAA_DIAM_AVP_ACCT_SUB_SESSION_ID,
	AAA_DIAM_AVP_ACCT_APPLICATION_ID,
	AAA_DIAM_AVP_AUTH_REQUEST_TYPE,
	/*---------------- 260 ----------------*/
	AAA_DIAM_AVP_AUTH_LIFETIME,
	AAA_DIAM_AVP_AUTH_GRACE_PERIOD,
	AAA_DIAM_AVP_CLASS,
	AAA_DIAM_AVP_DISCONNECT_CAUSE,
	AAA_DIAM_AVP_ERROR_REPORTING_HOST,
	AAA_DIAM_AVP_EXPERIMENTAL_RESULT_CODE,
	AAA_DIAM_AVP_FIRMWARE_REVISION,
	AAA_DIAM_AVP_HOST_IP_ADDR,
	AAA_DIAM_AVP_INBAND_SECURITY_ID,
	AAA_DIAM_AVP_MULTI_ROUND_TIME_OUT,
	/*---------------- 270 ----------------*/
	AAA_DIAM_AVP_PRODUCT_NAME,
	AAA_DIAM_AVP_SESSION_TIMEOUT,
	AAA_DIAM_AVP_SESSION_BINDING,
	AAA_DIAM_AVP_SESSION_SERVER_FAILOVER,
	AAA_DIAM_AVP_SESSION_REL_CAUSE,
	AAA_DIAM_AVP_MANDATORY_CAPABILITY,
	AAA_DIAM_AVP_OPTIONAL_CAPABILITY,
	AAA_DIAM_AVP_REASON_INFO,
	AAA_DIAM_AVP_SUPPORTED_VENDOR_ID,
	AAA_DIAM_AVP_DIRECT_DEBITING_FAILURE_HANDLING,
	/*---------------- 280 ----------------*/
	AAA_DIAM_AVP_LOW_BALANCE_INDICATION,
	AAA_DIAM_AVP_3GPP_SESSION_STOP_IND,
	AAA_DIAM_AVP_VF_USER_AGENT,
	AAA_DIAM_AVP_VF_USER_URL,
	AAA_DIAM_AVP_VF_TRAFFIC_REDIRECTED,
	AAA_DIAM_AVP_NAS_PORT,
	AAA_DIAM_AVP_CSG_INFORMATION_REPORTING,
	AAA_DIAM_AVP_3GPP_GPRS_NEGOTIATED_QOS_PROFILE,
	AAA_DIAM_AVP_3GPP_GGSN_ADDRESS,
	AAA_DIAM_AVP_ERICSSON_RULE_SPACE_SUGGESTION,
	/*---------------- 290 ----------------*/
	AAA_DIAM_AVP_ERICSSON_GX_CAPABILITY_LIST,
	AAA_DIAM_AVP_ERICSSON_CREDIT_INSTANCE_ID,
	AAA_DIAM_AVP_ERICSSON_SERVICE_START_TIMESTAMP,
	AAA_DIAM_AVP_ERICSSON_CUMULATIVE_USED_SERVICE_UNIT,
	AAA_DIAM_AVP_ERICSSON_RULE_SPACE_DECISION,
	AAA_DIAM_AVP_MIP_HA_TO_MN_MSA,

	/* RADIUS ordinals (for WAG/TDF) */
	AAA_DIAM_AVP_ACCT_DELAY_TIME,
	AAA_DIAM_AVP_ACCT_INPUT_GIGAWORDS,
	AAA_DIAM_AVP_ACCT_OUTPUT_GIGAWORDS,
	AAA_DIAM_AVP_ACCT_STATUS_TYPE,
	AAA_DIAM_AVP_CHAP_CHALLENGE,
	/*---------------- 300 ----------------*/
	AAA_DIAM_AVP_CHAP_PASSWORD,
	AAA_DIAM_AVP_CALLING_STATION_ID,
	AAA_DIAM_AVP_CHARGEABLE_USER_IDENTITY,
	AAA_DIAM_AVP_DELEGATED_IPV6_PREFIX,
	AAA_DIAM_AVP_EAP_MESSAGE,
	AAA_DIAM_AVP_ERROR_CAUSE,
	AAA_DIAM_AVP_FRAMED_COMPRESSION,
	AAA_DIAM_AVP_FRAMED_IP_NETMASK,
	AAA_DIAM_AVP_FRAMED_IPV6_POOL,
	AAA_DIAM_AVP_FRAMED_IPV6_ROUTE,
	/*---------------- 310 ----------------*/
	AAA_DIAM_AVP_FRAMED_INTERFACE_ID,
	AAA_DIAM_AVP_FRAMED_MTU,
	AAA_DIAM_AVP_FRAMED_POOL,
	AAA_DIAM_AVP_FRAMED_PROTOCOL,
	AAA_DIAM_AVP_FRAMED_ROUTE,
	AAA_DIAM_AVP_IDLE_TIMEOUT,
	AAA_DIAM_AVP_MESSAGE_AUTHENTICATOR,
	AAA_DIAM_AVP_NAS_IP_ADDRESS,
	AAA_DIAM_AVP_NAS_IPV6_ADDRESS,
	AAA_DIAM_AVP_NAS_IDENTIFIER,
	/*---------------- 320 ----------------*/
	AAA_DIAM_AVP_NAS_PORT_TYPE,
	AAA_DIAM_AVP_OPERATOR_NAME,
	AAA_DIAM_AVP_REPLY_MESSAGE,
	AAA_DIAM_AVP_SERVICE_TYPE,
	AAA_DIAM_AVP_STATE,
	AAA_DIAM_AVP_TERMINATION_ACTION,
	AAA_DIAM_AVP_TUNNEL_ASSIGNMENT_ID,
	AAA_DIAM_AVP_TUNNEL_CLIENT_AUTH_ID,
	AAA_DIAM_AVP_TUNNEL_CLIENT_ENDPOINT,
	AAA_DIAM_AVP_TUNNEL_MEDIUM_TYPE,
	/*---------------- 330 ----------------*/
	AAA_DIAM_AVP_TUNNEL_PASSWORD,
	AAA_DIAM_AVP_TUNNEL_PREFERENCE,
	AAA_DIAM_AVP_TUNNEL_PRIVATE_GROUP_ID,
	AAA_DIAM_AVP_TUNNEL_SERVER_AUTH_ID,
	AAA_DIAM_AVP_TUNNEL_SERVER_ENDPOINT,
	AAA_DIAM_AVP_TUNNEL_TYPE,
	AAA_DIAM_AVP_USER_PASSWORD,
	AAA_DIAM_AVP_VENDOR_SPECIFIC,
	AAA_DIAM_AVP_3GPP_IMSI,
	AAA_DIAM_AVP_3GPP_PDPTYPE,
	/*---------------- 340 ----------------*/
	AAA_DIAM_AVP_3GPP_CG_ADDRESS,
	AAA_DIAM_AVP_3GPP_CHARGING_GATEWAY_IPV6_ADDRESS,
	AAA_DIAM_AVP_3GPP_GGSN_IPV6_ADDRESS,
	AAA_DIAM_AVP_3GPP_IPV6_DNS_SERVER,
	AAA_DIAM_AVP_3GPP_IMEISV,
	AAA_DIAM_AVP_3GPP_PACKET_FILTER,
	AAA_DIAM_AVP_LOCAL_ADDRESS_POOL,
	AAA_DIAM_AVP_PRIMARY_DNS,
	AAA_DIAM_AVP_SECONDARY_DNS,
	AAA_DIAM_AVP_INGRESS_POLICY_NAME,
	/*---------------- 350 ----------------*/
	AAA_DIAM_AVP_EGRESS_POLICY_NAME,
	AAA_DIAM_AVP_REDIRECT_VROUTER_NAME,
	AAA_DIAM_AVP_IPV6_PRIMARY_DNS,
	AAA_DIAM_AVP_IPV6_SECONDARY_DNS,
	AAA_DIAM_AVP_DHCP_OPTIONS,
	AAA_DIAM_AVP_DHCP_MAC_ADDRESS,
	AAA_DIAM_AVP_DHCP_GI_ADDRESS,
	AAA_DIAM_AVP_LI_ACTION,
	AAA_DIAM_AVP_INTERCEPTON_IDENTIFIER,
	AAA_DIAM_AVP_MD_IP_ADDRESS,
	/*---------------- 360 ----------------*/
	AAA_DIAM_AVP_MD_PORT_NUMBER,
	AAA_DIAM_AVP_3GPP_CAMEL_CHARGING_INFO,
	AAA_DIAM_AVP_3GPP_NEGOTIATED_DSCP,
	AAA_DIAM_AVP_3GPP_ALLOCATE_IP_TYPE,
	AAA_DIAM_AVP_MS_MPPE_SEND_KEY,
	AAA_DIAM_AVP_MS_MPPE_RECV_KEY,
	AAA_DIAM_AVP_APPLICATION_DETECTION_INFO,
	AAA_DIAM_AVP_TDF_APPLICATION_IDENTIFIER,
	AAA_DIAM_AVP_TDF_APPLICATION_IDENTIFIER_BASE,
	AAA_DIAM_AVP_TDF_APPLICATION_INSTANCE_IDENTIFIER,
	/*---------------- 370 ----------------*/
	AAA_DIAM_AVP_ADC_RULE_INSTALL,
	AAA_DIAM_AVP_ADC_RULE_REMOVE,
	AAA_DIAM_AVP_ADC_RULE_DEFINITION,
	AAA_DIAM_AVP_ADC_RULE_BASE_NAME,
	AAA_DIAM_AVP_ADC_RULE_NAME,
	AAA_DIAM_AVP_ADC_RULE_REPORT,
	AAA_DIAM_AVP_MUTE_NOTIFICATION,
	AAA_DIAM_AVP_SERVICE_CHAIN_IDENTIFIER,
	AAA_DIAM_AVP_LRF_PROFILE_NAME,
	AAA_DIAM_AVP_HCM_PROFILE_NAME,
	/*---------------- 380 ----------------*/
	AAA_DIAM_AVP_FORWARDING_CLASS_NAME,
	AAA_DIAM_AVP_REDIRECT_INFO,
	AAA_DIAM_AVP_REDIRECT_SUPPORT,
	AAA_DIAM_AVP_REDIRECT_VRF,
	AAA_DIAM_AVP_NAS_PORT_ID,
	AAA_DIAM_AVP_REQ_BURST_SIZE_UL,
	AAA_DIAM_AVP_REQ_BURST_SIZE_DL,
	AAA_DIAM_AVP_STEERING_INFO,
	AAA_DIAM_AVP_STEERING_VRF_UL,
	AAA_DIAM_AVP_STEERING_VRF_DL,
	/*---------------- 390 ----------------*/
	AAA_DIAM_AVP_STEERING_IP_ADDRESS,
	AAA_DIAM_AVP_KEEP_EXISTING_STEERING,
	AAA_DIAM_AVP_UNKNOWN_POLICY_ACTIVATION_AVP,
	AAA_DIAM_AVP_UNKNOWN_POLICY_DEACTIVATION_AVP,
	AAA_DIAM_AVP_UNKNOWN_POLICY_REPORTING_AVP,

	/* Add AVPs above this always */
	AAA_DIAM_AVP_MAX
} aaa_diam_avp_list_t;

enum ccr_type {
	INITIAL_REQUEST = 1,
	UPDATE_REQUEST,
	TERMINATION_REQUEST,
};

extern diameter_avp_dict_handle diameter_dictionary;

diameter_avp_rc_t diameter_add_octet_string(aaa_diam_avp_list_t avp_ordinal,
			diameter_avp_payload_handle payload, uint8_t *str,
			uint32_t size, diameter_avp_message_handle msg_hdl);

diameter_avp_rc_t diameter_add_uint32(aaa_diam_avp_list_t avp_ordinal,
			diameter_avp_payload_handle payload_hdl,
			uint32_t val, diameter_avp_message_handle msg_hdl);

diameter_avp_rc_t diameter_get_diam_identity(diameter_avp_payload_handle payload_hdl,
			aaa_diam_avp_list_t avp_ordinal, uint16_t avp_index,
			diameter_avp_variant_t **avp, uint8_t **str, uint32_t *size);

int diameter_get_group(diameter_avp_payload_handle payload_hdl,
			aaa_diam_avp_list_t avp_ordinal, uint16_t avp_index,
			diameter_avp_variant_t **avp,
			diameter_avp_payload_handle *grp_hdl);

int diameter_get_enum(diameter_avp_payload_handle payload_hdl,
			aaa_diam_avp_list_t avp_ordinal,
			diameter_avp_variant_t **avp,
			uint16_t avp_index, int32_t *val);

void *diameter_dict_data_alloc(uint32_t size);

uint32_t diameter_dict_data_release(diameter_avp_data_handle buffer);

void diameter_dict_data_get_size(diameter_avp_data_handle buffer, uint32_t *size);

void diameter_dict_data_get_ptr(diameter_avp_data_handle buffer,
			uint32_t offset, uint8_t **pdata);

uint32_t diameter_dict_data_copy(diameter_avp_data_handle buffer,
			uint32_t offset, const void *data, uint32_t len);

void diameter_dict_get_handle(char *name, diameter_avp_dict_handle *dict_hdl);

void diameter_dict_init(uint32_t aaa_diam_avp_max);

#endif /* !_DIAMETER_AVP_H */
