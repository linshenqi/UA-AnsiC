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
/* Modify the content of this file according to the guid implementation on your system or emulate     */
/* the uuid generation process in this file.                                                          */
/******************************************************************************************************/

#include <stdlib.h>
#include <time.h>

/* UA platform definitions */
#include <opcua_p_internal.h>

/* own headers */
#include <opcua_guid.h>
#include <opcua_p_guid.h>
/*============================================================================
 * CreateGuid
 *===========================================================================*/
/**
* CreateGuid generates a global unique identifier.
*/
OpcUa_Guid* OpcUa_P_Guid_Create(OpcUa_Guid* guid)
{
    unsigned int *data = (unsigned int*)guid;
    int chunks = 16 / sizeof(unsigned int);
    static const int intbits = sizeof(int)*8;
    static int randbits = 0;
    if (!randbits)
    {
        int max = RAND_MAX;
        do { ++randbits; } while ((max=max>>1));
        srand(time(NULL));
        rand(); /* Skip first */
    }

    while (chunks--)
    {
        unsigned int randNumber = 0;
        int filled;
        for (filled = 0; filled < intbits; filled += randbits)
            randNumber |= (unsigned int)rand()<<filled;
         *(data+chunks) = randNumber;
    }

    guid->Data4[0] = (guid->Data4[0] & 0x3F) | 0x80; /* UV_DCE */
    guid->Data3 = (guid->Data3 & 0x0FFF) | 0x4000;   /* UV_Random */

    return guid;
}

