/******************************************************************************************************/
/* (c) Copyright 2005-2008 The OPC Foundation                                                         */
/* ALL RIGHTS RESERVED.                                                                               */
/*                                                                                                    */
/* DISCLAIMER:                                                                                        */
/*  This code is provided by the OPC Foundation solely to assist in                                   */
/*  understanding and use of the appropriate OPC Specification(s) and may be                          */
/*  used as set forth in the License Grant section of the OPC Specification.                          */
/*  This code is provided as-is and without warranty or support of any sort                           */
/*  and is subject to the Warranty and Liability Disclaimers which appear                             */
/*  in the printed OPC Specification.                                                                 */
/******************************************************************************************************/
/* Platform Portability Layer                                                                         */
/******************************************************************************************************/


/*============================================================================
 * Trace Initialize
 *===========================================================================*/
/**
 * Initialize all ressources needed for tracing.
 */
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Trace_Initialize(void);

/*============================================================================
 * Trace Initialize
 *===========================================================================*/
/**
 * Clear all ressources needed for tracing.
 */
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Trace_Clear(void);

/*============================================================================
 * Tracefunction
 *===========================================================================*/
/**
 * Writes the given string to the trace device, if the given trace level is
 * activated in the header file.
 */
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Trace(
#if OPCUA_TRACE_FILE_LINE_INFO
                                        OpcUa_UInt32 level,
                                        OpcUa_CharA* sFile,
                                        OpcUa_UInt32 line,
#endif
                                        OpcUa_CharA* a_sMessage);

