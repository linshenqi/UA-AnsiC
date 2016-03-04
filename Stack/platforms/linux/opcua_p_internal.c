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
/* P-Layer internal helper functions.                                                                 */
/******************************************************************************************************/

/* System Headers */

/* UA platform definitions */
#include <opcua_p_internal.h>

#define UINT64 long long

/*============================================================================
 * Calculate DateTime Difference
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_GetDateTimeDiff( OpcUa_DateTime  a_Value1,
                                                        OpcUa_DateTime  a_Value2,
                                                        OpcUa_DateTime* a_pResult)
{
    UINT64 ullValue1 = 0;
    UINT64 ullValue2 = 0;
    UINT64 ullResult = 0;

    OpcUa_ReturnErrorIfArgumentNull(a_pResult);

    a_pResult->dwLowDateTime = (OpcUa_UInt32)0;
    a_pResult->dwHighDateTime = (OpcUa_UInt32)0;

    ullValue1 = a_Value1.dwHighDateTime;
    ullValue1 = (ullValue1 << 32) + a_Value1.dwLowDateTime;

    ullValue2 = a_Value2.dwHighDateTime;
    ullValue2 = (ullValue2 << 32) + a_Value2.dwLowDateTime;

    if(ullValue1 > ullValue2)
    {
        return OpcUa_BadInvalidArgument;
    }

    ullResult = ullValue2 - ullValue1;

    a_pResult->dwLowDateTime = (OpcUa_UInt32)(ullResult & 0x00000000FFFFFFFFll);
    a_pResult->dwHighDateTime = (OpcUa_UInt32)((ullResult & 0xFFFFFFFF00000000ll) >> 32);    

    return OpcUa_Good;
}

/*============================================================================
 * Calculate DateTime Difference In Seconds (Rounded)
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_GetDateTimeDiffInSeconds32(  OpcUa_DateTime  a_Value1,
                                                                    OpcUa_DateTime  a_Value2,
                                                                    OpcUa_UInt32*   a_puResult)
{
    UINT64 ullValue1 = 0;
    UINT64 ullValue2 = 0;
    UINT64 ullResult = 0;

    OpcUa_ReturnErrorIfArgumentNull(a_puResult);

    *a_puResult = (OpcUa_UInt32)0;

    ullValue1 = a_Value1.dwHighDateTime;
    ullValue1 = (ullValue1 << 32) + a_Value1.dwLowDateTime;

    ullValue2 = a_Value2.dwHighDateTime;
    ullValue2 = (ullValue2 << 32) + a_Value2.dwLowDateTime;

    if(ullValue1 > ullValue2)
    {
        return OpcUa_BadInvalidArgument;
    }

    ullResult = (UINT64)((ullValue2 - ullValue1 + 5000000) / 10000000);

    if(ullResult > (UINT64)OpcUa_UInt32_Max)
    {
        return OpcUa_BadOutOfRange;
    }

    *a_puResult = (OpcUa_UInt32)(ullResult & 0x00000000FFFFFFFF);

    return OpcUa_Good;
}

