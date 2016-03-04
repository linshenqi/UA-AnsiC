/** 
  @file opcua_p_memory.h
  @brief Defines memory allocation functions for the Linux platform.

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

#ifndef _OpcUa_P_Memory_H_
#define _OpcUa_P_Memory_H_ 1

#include <opcua_platformdefs.h>

OPCUA_BEGIN_EXTERN_C

/** 
 * @see OpcUa_Memory_Alloc
 */
OpcUa_Void* OPCUA_DLLCALL OpcUa_P_Memory_Alloc(         OpcUa_UInt32 nSize);

/** 
 * @brief Reallocates a new block of memory
 *
 * @param pBuffer [in] The existing memory block.
 * @param nSize   [in] The size of the block to allocate.
 */
OpcUa_Void* OPCUA_DLLCALL OpcUa_P_Memory_ReAlloc(       OpcUa_Void*  pBuffer, 
                                                        OpcUa_UInt32 nSize);

/** 
 * @see OpcUa_Memory_Free
 */
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Memory_Free(           OpcUa_Void* pvBuffer);

/** 
 * @see OpcUa_Memory_MemCpy
 */
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Memory_MemCpy(   OpcUa_Void*  pBuffer,
                                                        OpcUa_UInt32 nSizeInBytes,
                                                        OpcUa_Void*  pSource,
                                                        OpcUa_UInt32 nCount);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_P_Memory_H_ */

