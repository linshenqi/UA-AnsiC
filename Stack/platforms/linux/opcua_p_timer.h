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

#ifndef _OpcUa_P_Timer_H_
#define _OpcUa_P_Timer_H_ 1

#include <sys/select.h>

OPCUA_BEGIN_EXTERN_C

/*============================================================================
 * Defines
 *===========================================================================*/
/** @brief The maximum time between processing timers. */
#define OPCUA_P_TIMER_MAX_TIMER_WAIT 500

/** @brief The number of timers available to the system. */
#define OPCUA_P_TIMER_NO_OF_TIMERS   200

/*============================================================================
 * The Timer Type
 *===========================================================================*/
typedef struct _OpcUa_P_InternalTimer
{
    /** @brief  */
    OpcUa_Boolean           bUsed;
    /** @brief  */
    OpcUa_UInt32            msecInterval;
    /** @brief  */
    OpcUa_P_Timer_Callback* TimerCallback;
    /** @brief  */
    OpcUa_P_Timer_Callback* KillCallback;
    /** @brief  */
    OpcUa_Void*             CallbackData;
    /** @brief  */
    OpcUa_UInt32            uLastFired;
    /** @brief  */
    OpcUa_UInt32            uDueTime;

} OpcUa_P_InternalTimer;

/*============================================================================
 * Create A Timer
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Timer_Create(    OpcUa_Timer*            phTimer, 
                                                        OpcUa_UInt32            msecInterval, 
                                                        OpcUa_P_Timer_Callback* fpTimerCallback,
                                                        OpcUa_P_Timer_Callback* fpKillCallback,
                                                        OpcUa_Void*             pvCallbackData);

/*============================================================================
 * Delete A Timer
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Timer_Delete(    OpcUa_Timer*            phTimer);

/*============================================================================
 * Initialize the Timer System
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_InitializeTimers(OpcUa_Void);

/*============================================================================
 * Cleanup the Timer System
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Timer_CleanupTimers(void);

#if !OPCUA_MULTITHREADED
/*============================================================================
 * Select wrapper used in singlethreaded configuration.
 *===========================================================================*/
int OpcUa_P_Socket_TimeredSelect( OpcUa_RawSocket  MaxFds, 
                                  fd_set*          pFdSetRead, 
                                  fd_set*          pFdSetWrite, 
                                  fd_set*          pFdSetException,
                                  struct timespec* pTimeout,
                                  sigset_t*        pOldMask);
#endif /* OPCUA_MULTITHREADED */

OPCUA_END_EXTERN_C
#endif /* _OpcUa_P_Timer_H_ */


