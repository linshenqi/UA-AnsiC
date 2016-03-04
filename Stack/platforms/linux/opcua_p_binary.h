/*============================================================================
// (c) Copyright 2005-2008 The OPC Foundation
// ALL RIGHTS RESERVED.
//
// DISCLAIMER:
//  This code is provided by the OPC Foundation solely to assist in 
//  understanding and use of the appropriate OPC Specification(s) and may be 
//  used as set forth in the License Grant section of the OPC Specification.
//  This code is provided as-is and without warranty or support of any sort
//  and is subject to the Warranty and Liability Disclaimers which appear
//  in the printed OPC Specification.
*/

#ifndef _OpcUa_P_Binary_H_
#define _OpcUa_P_Binary_H_ 1


OPCUA_BEGIN_EXTERN_C


/*============================================================================
 * OpcUa_Boolean_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Boolean_P_NativeToWire(OpcUa_Boolean_Wire* wire, OpcUa_Boolean* native);

/*============================================================================
 * OpcUa_Boolean_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Boolean_P_WireToNative(OpcUa_Boolean_Wire* native, OpcUa_Boolean_Wire* wire);

/*============================================================================
 * OpcUa_SByte_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SByte_P_NativeToWire(OpcUa_SByte_Wire* wire, OpcUa_SByte* native);

/*============================================================================
 * OpcUa_SByte_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_SByte_P_WireToNative(OpcUa_SByte* native, OpcUa_SByte_Wire* wire);

/*============================================================================
 * OpcUa_Byte_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Byte_P_NativeToWire(OpcUa_Byte_Wire* wire, OpcUa_Byte* native);

/*============================================================================
 * OpcUa_Byte_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Byte_P_WireToNative(OpcUa_Byte* native, OpcUa_Byte_Wire* wire);

/*============================================================================
 * OpcUa_Int16_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Int16_P_NativeToWire(OpcUa_Int16_Wire* wire, OpcUa_Int16* native);

/*============================================================================
 * OpcUa_Int16_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Int16_P_WireToNative(OpcUa_Int16* native, OpcUa_Int16_Wire* wire);

/*============================================================================
 * OpcUa_UInt16_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UInt16_P_NativeToWire(OpcUa_UInt16_Wire* wire, OpcUa_UInt16* native);

/*============================================================================
 * OpcUa_UInt16_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UInt16_P_WireToNative(OpcUa_UInt16* native, OpcUa_UInt16_Wire* wire);

/*============================================================================
 * OpcUa_Int32_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Int32_P_NativeToWire(OpcUa_Int32_Wire* wire, OpcUa_Int32* native);

/*============================================================================
 * OpcUa_Int32_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Int32_P_WireToNative(OpcUa_Int32* native, OpcUa_Int32_Wire* wire);

/*============================================================================
 * OpcUa_UInt32_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UInt32_P_NativeToWire(OpcUa_UInt32_Wire* wire, OpcUa_UInt32* native);

/*============================================================================
 * OpcUa_UInt32_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UInt32_P_WireToNative(OpcUa_UInt32* native, OpcUa_UInt32_Wire* wire);

/*============================================================================
 * OpcUa_Int64_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Int64_P_NativeToWire(OpcUa_Int64_Wire* wire, OpcUa_Int64* native);

/*============================================================================
 * OpcUa_Int64_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Int64_P_WireToNative(OpcUa_Int64* native, OpcUa_Int64_Wire* wire);

/*============================================================================
 * OpcUa_UInt64_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UInt64_P_NativeToWire(OpcUa_UInt64_Wire* wire, OpcUa_UInt64* native);

/*============================================================================
 * OpcUa_UInt64_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_UInt64_P_WireToNative(OpcUa_UInt64* native, OpcUa_UInt64_Wire* wire);

/*============================================================================
 * OpcUa_Float_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Float_P_NativeToWire(OpcUa_Float_Wire* wire, OpcUa_Float* native);

/*============================================================================
 * OpcUa_Float_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Float_P_WireToNative(OpcUa_Float* native, OpcUa_Float_Wire* wire);

/*============================================================================
 * OpcUa_Double_P_NativeToWire
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Double_P_NativeToWire(OpcUa_Double_Wire* wire, OpcUa_Double* native);

/*============================================================================
 * OpcUa_Double_P_WireToNative
 *===========================================================================*/
OPCUA_EXPORT OpcUa_StatusCode OpcUa_Double_P_WireToNative(OpcUa_Double* native, OpcUa_Double_Wire* wire);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_P_Binary_H_ */

