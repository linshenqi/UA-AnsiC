/** 
  @file opcua_soapsecurechannel.h
  @brief Defines functions used to manage a connection to a server.

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


struct _OpcUa_SoapSecureChannel
{
    OpcUa_UInt32 SecureChannelId;
};

typedef struct _OpcUa_SoapSecureChannel OpcUa_SoapSecureChannel;
