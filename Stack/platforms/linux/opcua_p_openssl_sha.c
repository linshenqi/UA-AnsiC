/*============================================================================
 (c) Copyright 2005-2008 The OPC Foundation
 ALL RIGHTS RESERVED.

 DISCLAIMER:
  This code is provided by the OPC Foundation solely to assist in 
  understanding and use of the appropriate OPC Specification(s) and may be 
  used as set forth in the License Grant section of the OPC Specification.
  This code is provided as-is and without warranty or support of any sort
  and is subject to the Warranty and Liability Disclaimers which appear
  in the printed OPC Specification.
*/

/* UA platform definitions */
#include <opcua_p_internal.h>
#include <opcua_p_memory.h>

#if OPCUA_REQUIRE_OPENSSL

/* System Headers */
#include <openssl/hmac.h>
#include <openssl/sha.h>

/* own headers */
#include <opcua_p_openssl.h>

/*============================================================================
 * OpcUa_P_OpenSSL_SHA1_Generate
 *===========================================================================*/
/* SHA-1: 160 Bit output */
OpcUa_StatusCode OpcUa_P_OpenSSL_SHA1_Generate(
    OpcUa_CryptoProvider*         a_pProvider,
    OpcUa_Byte*                   a_pData,
    OpcUa_UInt32                  a_dataLen,
    OpcUa_Byte*                   a_pMessageDigest)
{
OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "SHA1_Generate");

    OpcUa_ReferenceParameter(a_pProvider);
    
    OpcUa_ReturnErrorIfArgumentNull(a_pData);
    
    SHA1(a_pData, a_dataLen, a_pMessageDigest);
    
    OpcUa_ReturnErrorIfNull(a_pMessageDigest,OpcUa_Bad);

OpcUa_ReturnStatusCode;

OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_SHA1_160_Generate
 *===========================================================================*/
/* SHA-2: 160 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_SHA1_160_Generate(
    OpcUa_CryptoProvider*         a_pProvider,
    OpcUa_Byte*                   a_pData,
    OpcUa_UInt32                  a_dataLen,
    OpcUa_Byte*                   a_pMessageDigest)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "SHA160_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_pData);
    
    SHA1(a_pData, a_dataLen, a_pMessageDigest);

    OpcUa_ReturnErrorIfNull(a_pMessageDigest,OpcUa_Bad);

OpcUa_ReturnStatusCode;

OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_SHA2_224_Generate
 *===========================================================================*/
/* SHA-2: 224 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_SHA2_224_Generate(
    OpcUa_CryptoProvider*         a_pProvider,
    OpcUa_Byte*                   a_pData,
    OpcUa_UInt32                  a_dataLen,
    OpcUa_Byte*                   a_pMessageDigest)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "SHA2_224_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_pData);

    SHA224(a_pData, a_dataLen, a_pMessageDigest);

    OpcUa_ReturnErrorIfNull(a_pMessageDigest,OpcUa_Bad);

OpcUa_ReturnStatusCode;

OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_SHA2_256_Generate
 *===========================================================================*/
/* SHA-2: 256 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_SHA2_256_Generate(
    OpcUa_CryptoProvider*         a_pProvider,
    OpcUa_Byte*                   a_pData,
    OpcUa_UInt32                  a_dataLen,
    OpcUa_Byte*                   a_pMessageDigest)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "SHA2_256_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_pData);

    SHA256(a_pData, a_dataLen, a_pMessageDigest);

    OpcUa_ReturnErrorIfNull(a_pMessageDigest,OpcUa_Bad);

OpcUa_ReturnStatusCode;

OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_SHA2_384_Generate
 *===========================================================================*/
/* SHA-2: 384 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_SHA2_384_Generate(
    OpcUa_CryptoProvider*         a_pProvider,
    OpcUa_Byte*                   a_pData,
    OpcUa_UInt32                  a_dataLen,
    OpcUa_Byte*                   a_pMessageDigest)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "SHA2_384_Generate");

    OpcUa_ReferenceParameter(a_pProvider);
    
    OpcUa_ReturnErrorIfArgumentNull(a_pData);

    SHA384(a_pData, a_dataLen, a_pMessageDigest);

    OpcUa_ReturnErrorIfNull(a_pMessageDigest,OpcUa_Bad);

OpcUa_ReturnStatusCode;

OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}


/*============================================================================
 * OpcUa_P_OpenSSL_SHA2_512_Generate
 *===========================================================================*/
/* SHA-2: 512 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_SHA2_512_Generate(
    OpcUa_CryptoProvider*         a_pProvider,
    OpcUa_Byte*                   a_pData,
    OpcUa_UInt32                  a_dataLen,
    OpcUa_Byte*                   a_pMessageDigest)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "SHA2_512_Generate");

    OpcUa_ReferenceParameter(a_pProvider);
    
    OpcUa_ReturnErrorIfArgumentNull(a_pData);

    SHA512(a_pData, a_dataLen, a_pMessageDigest);

    OpcUa_ReturnErrorIfNull(a_pMessageDigest,OpcUa_Bad);

OpcUa_ReturnStatusCode;

OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

#endif /* OPCUA_REQUIRE_OPENSSL */
