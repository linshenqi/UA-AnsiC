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

#include <stdlib.h>
#include <memory.h>     
#include <errno.h>      /* for errornumbers when using save functions */

#include <opcua_p_internal.h>


/*============================================================================
 * OpcUa_Memory_Alloc
 *===========================================================================*/
OpcUa_Void* OPCUA_DLLCALL OpcUa_P_Memory_Alloc(OpcUa_UInt32 nSize)
{
    return malloc(nSize);
}

/*============================================================================
 * OpcUa_Memory_ReAlloc
 *===========================================================================*/
OpcUa_Void* OPCUA_DLLCALL OpcUa_P_Memory_ReAlloc(OpcUa_Void* pBuffer, OpcUa_UInt32 nSize)
{
    return realloc(pBuffer, nSize);
}

/*============================================================================
 * OpcUa_Memory_Free
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Memory_Free(OpcUa_Void* pBuffer)
{
    if (pBuffer != NULL)
    {
        free(pBuffer);
    }
}

/*============================================================================
 * OpcUa_Memory_MemCpy
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Memory_MemCpy(
    OpcUa_Void*  pBuffer, 
    OpcUa_UInt32 nSizeInBytes, 
    OpcUa_Void*  pSource, 
    OpcUa_UInt32 nCount)
{
    if(     pBuffer == OpcUa_Null
        ||  pSource == OpcUa_Null)
    {
        return OpcUa_BadInvalidArgument;
    }

    if(nSizeInBytes < nCount)
    {
        return OpcUa_BadOutOfRange;
    }

    if(memcpy(pBuffer, pSource, nCount) != pBuffer)
    {
        return OpcUa_BadInvalidArgument;
    }

    return OpcUa_Good;
}

