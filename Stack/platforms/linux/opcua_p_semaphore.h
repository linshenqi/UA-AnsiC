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


OpcUa_StatusCode    OPCUA_DLLCALL OpcUa_P_Semaphore_Create( OpcUa_Semaphore*    phRawSemaphore, 
                                                            OpcUa_UInt32        uInitalValue,
                                                            OpcUa_UInt32        uMaxRange);

OpcUa_Void          OPCUA_DLLCALL OpcUa_P_Semaphore_Delete( OpcUa_Semaphore*    phRawSemaphore);

OpcUa_StatusCode    OPCUA_DLLCALL OpcUa_P_Semaphore_Wait(   OpcUa_Semaphore     hRawSemaphore);

OpcUa_StatusCode    OPCUA_DLLCALL OpcUa_P_Semaphore_TimedWait(OpcUa_Semaphore   hRawSemaphore, 
                                                            OpcUa_UInt32        msecTimeout);

OpcUa_StatusCode    OPCUA_DLLCALL OpcUa_P_Semaphore_Post(   OpcUa_Semaphore     hRawSemaphore,
                                                            OpcUa_UInt32        uReleaseCount);

