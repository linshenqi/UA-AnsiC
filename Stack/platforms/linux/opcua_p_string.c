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
/* Modify the content of this file according to the socket implementation on your system.             */
/* This is the Win32 version                                                                          */
/******************************************************************************************************/

/* System Headers */
#include <stdio.h> 
#include <string.h>

/* UA platform definitions */
#include <opcua_p_internal.h>

/* own headers */
#include <opcua_string.h>
#include <opcua_p_string.h>

/*============================================================================
 * Copy uintCount Characters from a OpcUa_StringA to another OpcUa_StringA
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_String_strncpy(OpcUa_StringA strDestination, OpcUa_UInt32 uiDestSize, OpcUa_StringA strSource, OpcUa_UInt32 uiLength)
{
#if OPCUA_USE_SAFE_FUNCTIONS
    if(strncpy_s(strDestination, uiDestSize + 1, strSource, uiLength) != 0 )
    {
        return OpcUa_Bad;
    }
#else /* OPCUA_USE_SAFE_FUNCTIONS */
    OpcUa_ReferenceParameter(uiDestSize);

    if(strncpy(strDestination, strSource, uiLength) != strDestination)
    {
        return OpcUa_Bad;
    }
#endif /* OPCUA_USE_SAFE_FUNCTIONS */
    return OpcUa_Good;
}

/*============================================================================
 * Append uintCount Characters from a OpcUa_String to another OpcUa_String.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_String_strncat(OpcUa_StringA strDestination, OpcUa_UInt32 uiDestSize, OpcUa_StringA strSource, OpcUa_UInt32 uiLength)
{
    #if OPCUA_USE_SAFE_FUNCTIONS
        if(strncat_s(strDestination, uiDestSize, strSource, uiLength) != 0 )
        {
            return OpcUa_Bad;
        }
    #else /* OPCUA_USE_SAFE_FUNCTIONS */
        OpcUa_ReferenceParameter(uiDestSize);

        if(strncat(strDestination, strSource, uiLength) != strDestination)
        {
            return OpcUa_Bad;
        }
    #endif /* OPCUA_USE_SAFE_FUNCTIONS */

    return OpcUa_Good;
}

/*============================================================================
 * Get the Length from a OpcUa_String
 *===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_strlen(OpcUa_StringA a_pCString)
{
    return (OpcUa_Int32) strlen(a_pCString);
}

/*============================================================================
 * Compare two OpcUa_Strings Case Sensitive
 *===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_strncmp(OpcUa_StringA string1, OpcUa_StringA string2, OpcUa_UInt32 uiLength)
{
    return (OpcUa_Int32)strncmp(string1, string2, uiLength);
}

/*============================================================================
* Compare two OpcUa_Strings NOT Case Sensitive
*===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_strnicmp(OpcUa_StringA string1, OpcUa_StringA string2, OpcUa_UInt32 uiLength)
{
    return (OpcUa_Int32) strncasecmp(string1, string2, uiLength);
}

/*============================================================================
 * Write Values to a OpcUa_String
 *===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_vsnprintf(OpcUa_StringA sDest, OpcUa_UInt32 nCount, const OpcUa_StringA sFormat, varg_list vaList)
{
    return (OpcUa_Int32) vsnprintf(sDest, nCount, sFormat, vaList);
}


/*============================================================================
 * Write Values to a OpcUa_String
 *===========================================================================*/
/* OPCUA_DLLCALL with varglist wont work ... -> vsnprintf */
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_String_snprintf(  OpcUa_StringA a_sTarget,
                                                    OpcUa_UInt32  a_nCount,
                                                    OpcUa_StringA a_sFormat,
                                                    ...)
{
    OpcUa_Int   nRetval;
    va_list     vaList;

    va_start(vaList, a_sFormat);
    nRetval = vsnprintf(a_sTarget, a_nCount, a_sFormat, vaList);
    va_end( vaList );

    return (OpcUa_Int32)nRetval;
}


