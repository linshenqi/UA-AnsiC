/******************************************************************************************************/
/* (c) Copyright 2005 The OPC Foundation                                                              */
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
/* Modify the content of this file according to the mutex implementation on your system.              */
/* Hint: Emulate with binary semaphore                                                                */
/* This is the Linux-pthreads implementation.                                                         */
/******************************************************************************************************/
#include <opcua_platformdefs.h>
#include <opcua.h>

#include <opcua_mutex.h>
#include <opcua_p_mutex.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* see opcua_platformdefs.h */
#include <pthread.h>

/*============================================================================
 * Initialize the mutex.
 *===========================================================================*/

/* add errorchecking */

OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Mutex_Initialize(OpcUa_Mutex hMutex)
{
    OpcUa_StatusCode    uStatus     = OpcUa_Good;
    pthread_mutex_t*    pPosixMutex = (pthread_mutex_t*)(hMutex);
    int                 result;
    pthread_mutexattr_t att;

    /* initialize and set mutex attribute object */
    result = pthread_mutexattr_init(&att);
    if(result != 0)
    {
        return OpcUa_Bad;
    }

    result = pthread_mutexattr_settype(&att, PTHREAD_MUTEX_RECURSIVE_NP);
    if(result != 0)
    {
        pthread_mutexattr_destroy(&att);
        return OpcUa_Bad;
    }

    /* initialize mutex with the attribute object */
    result = pthread_mutex_init(pPosixMutex, &att); /* code */
    if(result != 0)
    {
        uStatus = OpcUa_Bad;
    }

    /* delete the temporary attribute object */
    result = pthread_mutexattr_destroy(&att); /* code */
    if(result != 0)
    {
        uStatus = OpcUa_Bad;
    }

    return uStatus;
}

/*============================================================================
 * Allocate the mutex.
 *===========================================================================*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Mutex_Create(OpcUa_Mutex* a_phMutex)
{
    OpcUa_StatusCode uStatus        = OpcUa_Good;
    OpcUa_Mutex      hMutex;

    if(a_phMutex == OpcUa_Null)
    {
        return OpcUa_BadInvalidArgument;
    }

    hMutex = (OpcUa_Mutex)malloc(sizeof(pthread_mutex_t));
    OpcUa_ReturnErrorIfAllocFailed(hMutex);

    uStatus = OpcUa_P_Mutex_Initialize(hMutex);

    if(OpcUa_IsBad(uStatus))
    {
        free(hMutex);
    }
    else
    {
        *a_phMutex = hMutex;
    }

    return uStatus;
}

/*============================================================================
 * Clear the mutex.
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Mutex_Clear(OpcUa_Mutex hMutex)
{
    if(hMutex != OpcUa_Null)
    {
        pthread_mutex_t*   pPosixMutex = (pthread_mutex_t*)hMutex;

        pthread_mutex_destroy(pPosixMutex);
    }
}

/*============================================================================
 * Clear and free the mutex.
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Mutex_Delete(OpcUa_Mutex* a_phMutex)
{
    if( a_phMutex == OpcUa_Null || *a_phMutex == OpcUa_Null)
    {
        return;
    }
    else
    {
        OpcUa_P_Mutex_Clear(*a_phMutex);
        free(*a_phMutex);
        *a_phMutex = OpcUa_Null;
    }
}

/*============================================================================
 * Lock the mutex.
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Mutex_Lock(OpcUa_Mutex hMutex)
{
    if(hMutex != OpcUa_Null)
    {
        pthread_mutex_t*    pPosixMutex = (pthread_mutex_t*)hMutex;

        pthread_mutex_lock(pPosixMutex);
    }
}

/*============================================================================
 * Unlock the mutex.
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Mutex_Unlock(OpcUa_Mutex hMutex)
{
    if(hMutex != OpcUa_Null)
    {
        pthread_mutex_t*    pPosixMutex = (pthread_mutex_t*)hMutex;

        pthread_mutex_unlock(pPosixMutex);
    }
}
