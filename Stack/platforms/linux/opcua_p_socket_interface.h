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

#ifndef _OpcUa_Socket_Interface_H_
#define _OpcUa_Socket_Interface_H_ 1

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Create a new socket manager or initialize the global one (OpcUa_Null first).
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_Create(        OpcUa_SocketManager*    pSocketManager,
                                                                    OpcUa_UInt32            nSockets,
                                                                    OpcUa_UInt32            nFlags);

/*============================================================================
 *
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_SocketManager_Delete(              OpcUa_SocketManager*    pSocketManager);

/*============================================================================
 * Create a server socket
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_CreateServer(  OpcUa_SocketManager         pSocketManager,
                                                                    OpcUa_StringA               sAddress,
                                                                    OpcUa_Boolean               bListenOnAllInterfaces,
                                                                    OpcUa_Socket_EventCallback  pfnSocketCallBack,
                                                                    OpcUa_Void*                 pCallbackData,
                                                                    OpcUa_Socket*               pSocket);

/*============================================================================
 * Create a client socket
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_CreateClient(  OpcUa_SocketManager         pSocketManager,
                                                                    OpcUa_StringA               sRemoteAddress,
                                                                    OpcUa_UInt16                uLocalPort,
                                                                    OpcUa_Socket_EventCallback  pfnSocketCallBack,
                                                                    OpcUa_Void*                 pCallbackData,
                                                                    OpcUa_Socket*               pSocket);

/*============================================================================
 * Signal a certain event on a socket.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_SignalEvent(   OpcUa_SocketManager pSocketManager,
                                                                    OpcUa_UInt32        uEvent,
                                                                    OpcUa_Boolean       bAllManagers);

/*============================================================================
 *
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_ServeLoop(     OpcUa_SocketManager     pSocketManager,
                                                                    OpcUa_UInt32            msecTimeout,
                                                                    OpcUa_Boolean           bRunOnce);

/*============================================================================
 * Create a new signal socket
 *===========================================================================*/
OpcUa_StatusCode OpcUa_P_SocketManager_NewSignalSocket(OpcUa_SocketManager a_pSocketManager);

/*============================================================================
 * Break server loop(s) and issue event(s).
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_SocketManager_InterruptLoop( OpcUa_SocketManager pSocketManager,
                                                                    OpcUa_UInt32        uEvent,
                                                                    OpcUa_Boolean       bAllManagers);

/*============================================================================
 * Get last socket error
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_GetLastError(         OpcUa_Socket    pSocket);

/*============================================================================
 * Read Socket.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_Read(                 OpcUa_Socket    pSocket,
                                                                    OpcUa_Byte*     pBuffer,
                                                                    OpcUa_UInt32    nBufferSize,
                                                                    OpcUa_UInt32*   pBytesRead);

/*============================================================================
 * Write Socket.
 *===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_Socket_Write(                     OpcUa_Socket    pSocket,
                                                                    OpcUa_Byte*     pBuffer,
                                                                    OpcUa_UInt32    uBufferSize,
                                                                    OpcUa_Boolean   bBlock);

/*============================================================================
 * Close Socket.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_Close(                OpcUa_Socket pSocket);

/*============================================================================
 * Get IP Address and Port Number of the Peer
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_GetPeerInfo(          OpcUa_Socket pSocket,
                                                                    OpcUa_CharA* a_achPeerInfoBuffer,
                                                                    OpcUa_UInt32 a_uiPeerInfoBufferSize);

/*============================================================================
 * Initialize the platform network interface
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_InitializeNetwork(    OpcUa_Void);

/*============================================================================
 * Clean the platform network interface up.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_CleanupNetwork(       OpcUa_Void);

/*============================================================================
 * Convert a text encoded internet address to its binary representation.
 *===========================================================================*/
OpcUa_UInt32 OPCUA_DLLCALL OpcUa_P_Socket_InetAddr(                 OpcUa_StringA sRemoteAddress);

/*============================================================================
 * Get the name of the local host.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_GetHostName(          OpcUa_CharA* pBuffer,
                                                                    OpcUa_UInt32 uiBufferLength);

/*============================================================================
 * Set socket user data
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Socket_SetUserData(          OpcUa_Socket pSocket,
                                                                    OpcUa_Void*  pvUserData);

OPCUA_END_EXTERN_C

#endif /* _OpcUa_Socket_Interface_H_ */
