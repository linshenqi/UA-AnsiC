/* ========================================================================
 * Copyright (c) 2005-2009 The OPC Foundation, Inc. All rights reserved.
 *
 * OPC Foundation MIT License 1.00
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * The complete license agreement can be found here:
 * http://opcfoundation.org/License/MIT/1.00/
 * ======================================================================*/

/******************************************************************************************************/
/* Platform Portability Layer                                                                         */
/* Modify the content of this file according to the socket implementation on your system.             */
/******************************************************************************************************/

/* System Headers */
#include <windows.h>
#include <stdlib.h>

#ifdef _WIN32_WCE
#include "winsock2.h"
#endif

/* UA platform definitions */
#include <opcua_p_internal.h>
#include <opcua_p_memory.h>

/* own headers */
#include <opcua_p_utilities.h>

/* maximum number of characters per port including \0 */
#define MAX_PORT_LENGTH 16

#if defined(_WIN32_WCE) && _WIN32_WCE < 0x700
/*
 * The following function bsearch is copied from the file wce_bsearch.c
 * The following license applies.
 *
 * Created by Mateusz Loskot (mateusz@loskot.net)
 *
 * Copyright (c) 2006 Mateusz Loskot
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * MIT License:
 * http://opensource.org/licenses/mit-license.php
 *
 */
void* bsearch(const void *key, const void *base, size_t num, size_t width,
                    int (*compare)(const void *, const void *))
{
    size_t left;
    size_t middle;
    size_t right;
    int res;

    /* input parameters validation */
    /*assert(key != NULL);*/
    /*assert(base != NULL);*/
    /*assert(compare != NULL);*/

    res = 0;
    left = 0;
    right = num - 1;

    while (left <= right)
    {
        middle = (left + right) / 2;

        res = compare(((char*) base + (width * middle)), key);
        if (res > 0)
        {
            /* search from middle to left */
            right = middle - 1;
        }
        else if (res < 0)
        {
            /* search from middle to right */
            left = middle + 1;
        }
        else if (res == 0)
        {
            /* middle points to the key element. */
            return ((char*) base + (width * middle));
        }
    }

    /* key not found */
    return NULL;
}
#endif


/*============================================================================
 * Quick Sort
 *===========================================================================*/
OpcUa_Void OPCUA_DLLCALL OpcUa_P_QSort( OpcUa_Void*       pElements,
                                        OpcUa_UInt32      nElementCount,
                                        OpcUa_UInt32      nElementSize,
                                        OpcUa_PfnCompare* pfnCompare,
                                        OpcUa_Void*       pContext)
{
    /*qsort_s(pElements, nElementCount, nElementSize, pfnCompare, pContext);*/
    OpcUa_ReferenceParameter(pContext);
    qsort(pElements, nElementCount, nElementSize, pfnCompare);
}

/*============================================================================
 * Binary Search on sorted array
 *===========================================================================*/
OpcUa_Void* OPCUA_DLLCALL OpcUa_P_BSearch(  OpcUa_Void*       pKey,
                                            OpcUa_Void*       pElements,
                                            OpcUa_UInt32      nElementCount,
                                            OpcUa_UInt32      nElementSize,
                                            OpcUa_PfnCompare* pfnCompare,
                                            OpcUa_Void*       pContext)
{
    /*return bsearch_s(pKey, pElements, nElementCount, nElementSize, pfnCompare, pContext);*/
    OpcUa_ReferenceParameter(pContext);
    return bsearch(pKey, pElements, nElementCount, nElementSize, pfnCompare);
}

/*============================================================================
 * Access to errno
 *===========================================================================*/
OpcUa_UInt32 OPCUA_DLLCALL OpcUa_P_GetLastError()
{
#ifdef _WIN32_WCE
    return GetLastError();
#else /* _WIN32_WCE */
    return errno;
#endif /* _WIN32_WCE */
}

/*============================================================================
 * OpcUa_GetTickCount
 *===========================================================================*/
OpcUa_UInt32 OPCUA_DLLCALL OpcUa_P_GetTickCount()
{
    return GetTickCount();
}

/*============================================================================
 * OpcUa_CharAToInt
 *===========================================================================*/
OpcUa_Int32 OPCUA_DLLCALL OpcUa_P_CharAToInt(OpcUa_StringA sValue)
{
    return (OpcUa_Int32)atoi(sValue);
}

/*============================================================================
 * OpcUa_P_ParseUrl
 *===========================================================================*/
OpcUa_StatusCode OpcUa_P_ParseUrl(  OpcUa_StringA   a_psUrl,
                                    OpcUa_StringA*  a_psIpAdress,
                                    OpcUa_UInt16*   a_puPort)
{
    OpcUa_StringA   sHostName         = OpcUa_Null;
    OpcUa_UInt32    uHostNameLength   = 0;

    OpcUa_CharA*    pcCursor          = OpcUa_Null;

    OpcUa_Int       nIndex1           = 0;
    OpcUa_Int       nIpStart          = 0;

    struct hostent* pHostEnt          = OpcUa_Null;

OpcUa_InitializeStatus(OpcUa_Module_Utilities, "P_ParseUrl");

    OpcUa_ReturnErrorIfArgumentNull(a_psUrl);
    OpcUa_ReturnErrorIfArgumentNull(a_psIpAdress);
    OpcUa_ReturnErrorIfArgumentNull(a_puPort);

    *a_psIpAdress = OpcUa_Null;

    /* check for // (end of protocol header) */
    pcCursor = strstr(a_psUrl, "//");

    if(pcCursor != OpcUa_Null)
    {
        /* begin of host address */
        pcCursor += 2;
        nIndex1 = (OpcUa_Int)(pcCursor - a_psUrl);
    }

    /* skip protocol prefix and store beginning of ip adress */
    nIpStart = nIndex1;

    /* skip host address */
    while(      a_psUrl[nIndex1] != ':'
            &&  a_psUrl[nIndex1] != '/'
            &&  a_psUrl[nIndex1] != 0)
    {
        nIndex1++;
    }

    uHostNameLength = nIndex1 - nIpStart;
    sHostName       = (OpcUa_StringA)OpcUa_P_Memory_Alloc(uHostNameLength + 1);
    if(sHostName == NULL)
    {
        OpcUa_GotoErrorWithStatus(OpcUa_BadOutOfMemory);
    }

    memcpy(sHostName, &a_psUrl[nIpStart], uHostNameLength);
    sHostName[uHostNameLength] = '\0';

    /* scan port */
    if(a_psUrl[nIndex1] == ':')
    {
        OpcUa_Int       nIndex2 = 0;
        OpcUa_CharA*    sPort   = OpcUa_Null;
        OpcUa_CharA sBuffer[MAX_PORT_LENGTH];

        /* skip delimiter */
        nIndex1++;

        /* store beginning of port */
        sPort = &a_psUrl[nIndex1];

        /* search for end of port */
        while(      a_psUrl[nIndex1] != '/'
                &&  a_psUrl[nIndex1] != 0
                &&  nIndex2          <  6)
        {
            nIndex1++;
            nIndex2++;
        }

        /* convert port */
        OpcUa_P_Memory_MemCpy(sBuffer, MAX_PORT_LENGTH-1, sPort, nIndex2);
        sBuffer[nIndex2] = 0;
        *a_puPort = (OpcUa_UInt16)OpcUa_P_CharAToInt(sBuffer);
    }
    else
    {
        /* return default port */
        *a_puPort = OPCUA_TCP_DEFAULT_PORT;
    }

    pHostEnt = gethostbyname(sHostName);

    if(pHostEnt == NULL)
    {
        unsigned long ulInetAddr = inet_addr(sHostName);

        if(ulInetAddr != INADDR_NONE)
        {
            /* sHostName is already numeric */
            *a_psIpAdress = sHostName;
            OpcUa_ReturnStatusCode;
        }
    }

    OpcUa_P_Memory_Free(sHostName);

    if(pHostEnt == NULL)
    {
        /* hostname could not be resolved */
        OpcUa_GotoErrorWithStatus(OpcUa_BadHostUnknown);
    }

    *a_psIpAdress = OpcUa_P_Memory_Alloc(16);
    if(*a_psIpAdress == NULL)
    {
        OpcUa_GotoErrorWithStatus(OpcUa_BadOutOfMemory);
    }

#if OPCUA_USE_SAFE_FUNCTIONS
    sprintf_s(*a_psIpAdress, 16,
#else /* OPCUA_USE_SAFE_FUNCTIONS */
    sprintf(*a_psIpAdress,
#endif /* OPCUA_USE_SAFE_FUNCTIONS */
            "%u.%u.%u.%u",
            (unsigned char)(*((*pHostEnt).h_addr_list))[0],
            (unsigned char)(*((*pHostEnt).h_addr_list))[1],
            (unsigned char)(*((*pHostEnt).h_addr_list))[2],
            (unsigned char)(*((*pHostEnt).h_addr_list))[3]);

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

