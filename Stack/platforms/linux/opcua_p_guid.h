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
/******************************************************************************************************/

/*============================================================================
 * CreateGuid
 *===========================================================================*/
/**
* Create a GUID in binary format.
*/
OpcUa_Guid* OPCUA_DLLCALL OpcUa_P_Guid_Create(OpcUa_Guid* Guid);

