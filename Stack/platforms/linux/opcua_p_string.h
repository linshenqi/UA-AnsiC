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
* Copy uintCount Characters from a OpcUa_StringA to another OpcUa_StringA
*===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_String_strncpy(OpcUa_StringA strDestination, OpcUa_UInt32 uiDestSize, OpcUa_StringA strSource, OpcUa_UInt32 uiLength);

/*============================================================================
* Append uintCount Characters from a OpcUa_String to another OpcUa_String.
*===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_String_strncat(OpcUa_StringA strDestination, OpcUa_UInt32 uiDestSize, OpcUa_StringA strSource, OpcUa_UInt32 uiLength);

/*============================================================================
* Get the Length from a OpcUa_String
*===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_strlen(OpcUa_StringA   a_pCString);

/*============================================================================
* Compare two OpcUa_Strings Case Sensitive
*===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_strncmp(OpcUa_StringA string1, OpcUa_StringA string2, OpcUa_UInt32 uiLength);

/*============================================================================
* Compare two OpcUa_Strings NOT Case Sensitive
*===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_strnicmp(OpcUa_StringA string1, OpcUa_StringA string2, OpcUa_UInt32 uiLength);

/*============================================================================
* Print a list of values into a string.
*===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_vsnprintf(OpcUa_StringA sDest, OpcUa_UInt32 uCount, const OpcUa_StringA sFormat, varg_list argptr);

/*============================================================================
* Print a list of values into a string with a max length.
*===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_snprintf(OpcUa_StringA sTarget, OpcUa_UInt32  nCount, OpcUa_StringA sFormat, ...);

