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
/* Posix                                                                                              */
/******************************************************************************************************/

/*============================================================================
 * Create a platform thread
 *===========================================================================*/
OpcUa_StatusCode    OpcUa_P_Thread_Create(      OpcUa_RawThread* pThread);

/*============================================================================
 * Delete Raw Thread
 *===========================================================================*/
OpcUa_Void          OpcUa_P_Thread_Delete(      OpcUa_RawThread* pRawThread);

/*============================================================================
 * Start Thread
 *===========================================================================*/
OpcUa_StatusCode    OpcUa_P_Thread_Start(   OpcUa_RawThread             pThread, 
                                            OpcUa_PfnInternalThreadMain pfnStartFunction, 
                                            OpcUa_Void*                 pArguments);

/*============================================================================
 * Send the thread to sleep.
 *===========================================================================*/
OpcUa_Void          OpcUa_P_Thread_Sleep(   OpcUa_UInt32                msecTimeout);

/*============================================================================
 * Get Current Thread Id
 *===========================================================================*/
/* the return type "unsigned long" is necessary to hold a "pthread_t" value */
unsigned long       OpcUa_P_Thread_GetCurrentThreadId(  OpcUa_Void);

