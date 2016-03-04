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

#include <memory.h>
#include "opcua_platformdefs.h"
#include "opcua_statuscodes.h"
#include "opcua_errorhandling.h"
#include "opcua_trace.h"

/*============================================================================
 * OpcUa_Boolean_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Boolean_P_NativeToWire(OpcUa_Boolean_Wire* wire, OpcUa_Boolean* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    *wire = *native;

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Boolean_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Boolean_P_WireToNative(OpcUa_Boolean_Wire* native, OpcUa_Boolean_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    *native = *wire;

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_SByte_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_SByte_P_NativeToWire(OpcUa_SByte_Wire* wire, OpcUa_SByte* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    *wire = *native;

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_SByte_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_SByte_P_WireToNative(OpcUa_SByte* native, OpcUa_SByte_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    *native = *wire;

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Byte_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Byte_P_NativeToWire(OpcUa_Byte_Wire* wire, OpcUa_Byte* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    *wire = *native;

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Byte_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Byte_P_WireToNative(OpcUa_Byte* native, OpcUa_Byte_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    *native = *wire;

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Int16_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Int16_P_NativeToWire(OpcUa_Int16_Wire* wire, OpcUa_Int16* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_Int16));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Int16_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Int16_P_WireToNative(OpcUa_Int16* native, OpcUa_Int16_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_Int16));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_UInt16_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_UInt16_P_NativeToWire(OpcUa_UInt16_Wire* wire, OpcUa_UInt16* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_UInt16));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_UInt16_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_UInt16_P_WireToNative(OpcUa_UInt16* native, OpcUa_UInt16_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_UInt16));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Int32_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Int32_P_NativeToWire(OpcUa_Int32_Wire* wire, OpcUa_Int32* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_Int32));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Int32_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Int32_P_WireToNative(OpcUa_Int32* native, OpcUa_Int32_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_Int32));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_UInt32_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_UInt32_P_NativeToWire(OpcUa_UInt32_Wire* wire, OpcUa_UInt32* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_UInt32));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_UInt32_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_UInt32_P_WireToNative(OpcUa_UInt32* native, OpcUa_UInt32_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_UInt32));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Int64_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Int64_P_NativeToWire(OpcUa_Int64_Wire* wire, OpcUa_Int64* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_Int64));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Int64_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Int64_P_WireToNative(OpcUa_Int64* native, OpcUa_Int64_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_Int64));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_UInt64_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_UInt64_P_NativeToWire(OpcUa_UInt64_Wire* wire, OpcUa_UInt64* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_UInt64));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_UInt64_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_UInt64_P_WireToNative(OpcUa_UInt64* native, OpcUa_UInt64_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_UInt64));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Float_P_NativeToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Float_P_NativeToWire(OpcUa_Float_Wire* wire, OpcUa_Float* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_Float));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Float_P_WireToNative
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Float_P_WireToNative(OpcUa_Float* native, OpcUa_Float_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_Float));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_Double_P_NativeToWire
 *===========================================================================*/

OpcUa_StatusCode OpcUa_Double_P_NativeToWire(OpcUa_Double_Wire* wire, OpcUa_Double* native)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(wire, native, sizeof(OpcUa_Double));

    return OpcUa_Good;
}

/*============================================================================
 * OpcUa_String_P_WireToWire
 *===========================================================================*/
OpcUa_StatusCode OpcUa_Double_P_WireToNative(OpcUa_Double* native, OpcUa_Double_Wire* wire)
{
    OpcUa_DeclareErrorTraceModule(OpcUa_Module_BinarySerializer);
    OpcUa_ReturnErrorIfArgumentNull(wire);
    OpcUa_ReturnErrorIfArgumentNull(native);

    OpcUa_SwapBytes(native, wire, sizeof(OpcUa_Double));

    return OpcUa_Good;
}
