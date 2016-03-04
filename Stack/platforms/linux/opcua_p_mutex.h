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

#if OPCUA_MUTEX_ERROR_CHECKING
    #define OpcUa_P_Mutex_Create(xMutex)  OpcUa_P_Mutex_CreateImp( xMutex, __FILE__, __LINE__)
    #define OpcUa_P_Mutex_Delete(xMutex)  OpcUa_P_Mutex_DeleteImp( xMutex, __FILE__, __LINE__)
    #define OpcUa_P_Mutex_Lock(xMutex)    OpcUa_P_Mutex_LockImp(   xMutex, __FILE__, __LINE__)
    #define OpcUa_P_Mutex_Unlock(xMutex)  OpcUa_P_Mutex_UnlockImp( xMutex, __FILE__, __LINE__)
#else /* OPCUA_MUTEX_ERROR_CHECKING */
    #define OpcUa_P_Mutex_Create(xMutex)  OpcUa_P_Mutex_CreateImp( xMutex)
    #define OpcUa_P_Mutex_Delete(xMutex)  OpcUa_P_Mutex_DeleteImp( xMutex)
    #define OpcUa_P_Mutex_Lock(xMutex)    OpcUa_P_Mutex_LockImp(   xMutex)
    #define OpcUa_P_Mutex_Unlock(xMutex)  OpcUa_P_Mutex_UnlockImp( xMutex)
#endif /* OPCUA_MUTEX_ERROR_CHECKING */

#if OPCUA_MUTEX_ERROR_CHECKING
    OpcUa_StatusCode    OPCUA_DLLCALL OpcUa_P_Mutex_CreateImp(   OpcUa_Mutex*    phMutex, char* file, int line);
    OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Mutex_DeleteImp(   OpcUa_Mutex*    phMutex, char* file, int line);
    OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Mutex_LockImp(     OpcUa_Mutex     hMutex,  char* file, int line);
    OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Mutex_UnlockImp(   OpcUa_Mutex     hMutex,  char* file, int line);
#else
    OpcUa_StatusCode    OPCUA_DLLCALL OpcUa_P_Mutex_CreateImp(   OpcUa_Mutex*    phMutex);
    OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Mutex_DeleteImp(   OpcUa_Mutex*    phMutex);
    OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Mutex_LockImp(     OpcUa_Mutex     hMutex);
    OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Mutex_UnlockImp(   OpcUa_Mutex     hMutex);
#endif
