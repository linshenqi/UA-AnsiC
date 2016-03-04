/**
  @file opcua_p_utilities.h
  @brief Defines utility functions for the WIN32 platform.

  (c) Copyright 2005-2008 The OPC Foundation
  ALL RIGHTS RESERVED.

  DISCLAIMER:
  This code is provided by the OPC Foundation solely to assist in 
  understanding and use of the appropriate OPC Specification(s) and may be 
  used as set forth in the License Grant section of the OPC Specification.
  This code is provided as-is and without warranty or support of any sort
  and is subject to the Warranty and Liability Disclaimers which appear
  in the printed OPC Specification.
*/

#ifndef _OpcUa_P_Utilities_H_
#define _OpcUa_P_Utilities_H_ 1

OPCUA_BEGIN_EXTERN_C

/** 
 * @see OpcUa_P_QSort
 */
OpcUa_Void OPCUA_DLLCALL OpcUa_P_QSort( OpcUa_Void*       pElements,
                                        OpcUa_UInt32      nElementCount,
                                        OpcUa_UInt32      nElementSize,
                                        OpcUa_PfnCompare* pfnCompare,
                                        OpcUa_Void*       pContext);

/**
 * @see OpcUa_P_BSearch
 */
OpcUa_Void* OPCUA_DLLCALL OpcUa_P_BSearch(  OpcUa_Void*       pKey,
                                            OpcUa_Void*       pElements,
                                            OpcUa_UInt32      nElementCount,
                                            OpcUa_UInt32      nElementSize,
                                            OpcUa_PfnCompare* pfnCompare,
                                            OpcUa_Void*       pContext);

/**
 * @see OpcUa_P_GetLastError
 */
OpcUa_UInt32 OPCUA_DLLCALL OpcUa_P_GetLastError(void);

/**
 * @see OpcUa_P_GetTickCount
 */
OpcUa_UInt32 OPCUA_DLLCALL OpcUa_P_GetTickCount(void);

/**
 * @see OpcUa_P_CharAToInt
 */
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_CharAToInt(   OpcUa_StringA sValue);

/**
 * @see OpcUa_P_ParseUrl
 */
OpcUa_StatusCode OpcUa_P_ParseUrl(  OpcUa_StringA   psUrl,
                                    OpcUa_StringA*  psIpAddress,
                                    OpcUa_UInt16*   puPort);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_P_Utilities_H_ */

