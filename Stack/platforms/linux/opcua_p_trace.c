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

/* System Headers */
 #include <stdio.h>

/* UA platform definitions */
#include <opcua_p_internal.h>

/* additional UA dependencies */
#include <opcua_p_mutex.h>
#include <opcua_p_thread.h>

/* own headers */
#include <opcua_p_trace.h>
#include <opcua_p_datetime.h>

OPCUA_EXPORT OpcUa_P_TraceHook g_OpcUa_P_TraceHook;

/*============================================================================
 * Trace Initialize
 *===========================================================================*/
/**
* Initialize all ressources needed for tracing.
*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_Trace_Initialize(OpcUa_Void)
{
    return OpcUa_Good;
}

/*============================================================================
 * Trace Clear
 *===========================================================================*/
/**
* Clear all ressources needed for tracing.
*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_Trace_Clear(OpcUa_Void)
{
    return;
}

/*============================================================================
 * Tracefunction
 *===========================================================================*/
/**
 * Writes the given string to the trace device, if the given trace level is
 * activated in the header file.
 */

OpcUa_Void OPCUA_DLLCALL OpcUa_P_Trace(
#if OPCUA_TRACE_FILE_LINE_INFO
                                        OpcUa_UInt32 level,
                                        OpcUa_CharA* sFile,
                                        OpcUa_UInt32 line,
#endif
                                        OpcUa_CharA* a_sMessage)
{
#if OPCUA_TRACE_FILE_LINE_INFO
    OpcUa_ReferenceParameter(level);
    OpcUa_ReferenceParameter(sFile);
    OpcUa_ReferenceParameter(line);
#endif

    /* send to tracehook if registered */
    if(g_OpcUa_P_TraceHook != OpcUa_Null)
    {
        g_OpcUa_P_TraceHook(a_sMessage);
    }
    else /* send to console */
    {
        char dtbuffer[25];
        OpcUa_DateTime timestamp;

        timestamp = OpcUa_P_DateTime_UtcNow();
        OpcUa_P_DateTime_GetStringFromDateTime(timestamp, dtbuffer, 25);

        printf("|%ld| %s %s", OpcUa_P_Thread_GetCurrentThreadId(), &dtbuffer[11], a_sMessage);
    }
}

