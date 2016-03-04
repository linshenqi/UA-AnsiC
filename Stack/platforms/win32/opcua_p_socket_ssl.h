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
/** @file Internally used definitions and types for the platform layer network implementation         */
/******************************************************************************************************/
#ifndef _OpcUa_Socket_Ssl_H_
#define _OpcUa_Socket_Ssl_H_ 1

OPCUA_BEGIN_EXTERN_C

#if OPCUA_P_SOCKETMANAGER_SUPPORT_SSL

/*============================================================================
 * Create a SSL server socket
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_CreateSslServer(  OpcUa_SocketManager              pSocketManager,
                                                                       OpcUa_StringA                    sAddress,
                                                                       OpcUa_Boolean                    bListenOnAllInterfaces,
                                                                       OpcUa_ByteString*                pServerCertificate,
                                                                       OpcUa_Key*                       pServerPrivateKey,
                                                                       OpcUa_Void*                      pPKIConfig,
                                                                       OpcUa_Socket_EventCallback       pfnSocketCallBack,
                                                                       OpcUa_Socket_CertificateCallback pfnCertificateCallBack,
                                                                       OpcUa_Void*                      pCallbackData,
                                                                       OpcUa_Socket*                    pSocket);

/*============================================================================
 * Create a SSL client socket
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_CreateSslClient(  OpcUa_SocketManager              pSocketManager,
                                                                       OpcUa_StringA                    sRemoteAddress,
                                                                       OpcUa_UInt16                     uLocalPort,
                                                                       OpcUa_ByteString*                pClientCertificate,
                                                                       OpcUa_Key*                       pClientPrivateKey,
                                                                       OpcUa_Void*                      pPKIConfig,
                                                                       OpcUa_Socket_EventCallback       pfnSocketCallBack,
                                                                       OpcUa_Socket_CertificateCallback pfnCertificateCallBack,
                                                                       OpcUa_Void*                      pCallbackData,
                                                                       OpcUa_Socket*                    pSocket);

#endif /* OPCUA_P_SOCKETMANAGER_SUPPORT_SSL */

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Socket_Ssl_H_ */

