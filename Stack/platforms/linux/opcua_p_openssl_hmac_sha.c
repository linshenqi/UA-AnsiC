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


/* own headers */
#include <opcua_p_openssl.h>

/*============================================================================
 * OpcUa_P_OpenSSL_HMAC_SHA1_Generate
 *===========================================================================*/
/* HMAC-SHA-1: 160 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_HMAC_SHA1_Generate(
    OpcUa_CryptoProvider* a_pProvider,
    OpcUa_Byte*           a_pData,
    OpcUa_UInt32          a_dataLen,
    OpcUa_Key*            a_key,
    OpcUa_ByteString*     a_pMac)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "HMAC_SHA1_Generate");

    OpcUa_ReferenceParameter(a_pProvider);


    OpcUa_ReturnErrorIfArgumentNull(a_key);
    OpcUa_ReturnErrorIfArgumentNull(a_key->Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pMac);

    if(a_key->Key.Length < 1)
    {
        uStatus = OpcUa_BadInvalidArgument;
        OpcUa_GotoErrorIfBad(uStatus);
    }

    if((OpcUa_Int32)a_dataLen < 1)
    {
        uStatus = OpcUa_BadInvalidArgument;
        OpcUa_GotoErrorIfBad(uStatus);
    }

    if(a_pMac->Data == OpcUa_Null)
    {
        a_pMac->Length = 20;
        OpcUa_ReturnStatusCode;
    }

    HMAC(EVP_sha1(),a_key->Key.Data,a_key->Key.Length,a_pData,a_dataLen,a_pMac->Data,(unsigned int*)&(a_pMac->Length));

    if(a_pMac->Length <= 0) 
        uStatus = OpcUa_Bad;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}


/*============================================================================
 * OpcUa_P_OpenSSL_HMAC_SHA1_160_Generate
 *===========================================================================*/
/* HMAC-SHA-2: 160 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_HMAC_SHA1_160_Generate(
    OpcUa_CryptoProvider* a_pProvider,
    OpcUa_Byte*           a_pData,
    OpcUa_UInt32          a_dataLen,
    OpcUa_Key             a_key,
    OpcUa_ByteString*     a_pMac)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "HMAC_SHA160_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_key.Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pMac);
    
    if(a_pMac->Data == OpcUa_Null)
    {
        a_pMac->Length = 20;    
        OpcUa_ReturnStatusCode;
    }

    HMAC(EVP_sha1(),a_key.Key.Data,a_key.Key.Length,a_pData,a_dataLen,a_pMac->Data,(unsigned int*)&(a_pMac->Length));

    if(a_pMac->Length <= 0) 
        uStatus = OpcUa_Bad;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;

OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_HMAC_SHA2_224_Generate
 *===========================================================================*/
/* HMAC-SHA-2: 224 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_HMAC_SHA2_224_Generate(
    OpcUa_CryptoProvider* a_pProvider,
    OpcUa_Byte*           a_pData,
    OpcUa_UInt32          a_dataLen,
    OpcUa_Key             a_key,
    OpcUa_ByteString*     a_pMac)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "HMAC_SHA224_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_key.Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pMac);
    
    if(a_pMac->Data == OpcUa_Null)
    {
        a_pMac->Length = 28;
        OpcUa_ReturnStatusCode;
    }

    HMAC(EVP_sha224(),a_key.Key.Data,a_key.Key.Length,a_pData,a_dataLen,a_pMac->Data,(unsigned int*)&(a_pMac->Length));

    if(a_pMac->Length <= 0) 
        uStatus = OpcUa_Bad;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;

OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_HMAC_SHA2_256_Generate
 *===========================================================================*/
/* HMAC-SHA-2: 256 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_HMAC_SHA2_256_Generate(
    OpcUa_CryptoProvider* a_pProvider,
    OpcUa_Byte*           a_pData,
    OpcUa_UInt32          a_dataLen,
    OpcUa_Key*            a_key,
    OpcUa_ByteString*     a_pMac)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "HMAC_SHA256_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_key);
    OpcUa_ReturnErrorIfArgumentNull(a_key->Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pMac);
    
    if(a_pMac->Data == OpcUa_Null)
    {
        a_pMac->Length = 32;
        OpcUa_ReturnStatusCode;
    }

    HMAC(EVP_sha256(),a_key->Key.Data,a_key->Key.Length,a_pData,a_dataLen,a_pMac->Data,(unsigned int*)&(a_pMac->Length));
    
    if(a_pMac->Length <= 0) 
    {
        OpcUa_GotoErrorWithStatus(OpcUa_Bad);
    }

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;

OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_HMAC_SHA2_384_Generate
 *===========================================================================*/
/* HMAC-SHA-2: 384 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_HMAC_SHA2_384_Generate(
    OpcUa_CryptoProvider* a_pProvider,
    OpcUa_Byte*           a_pData,
    OpcUa_UInt32          a_dataLen,
    OpcUa_Key             a_key,
    OpcUa_ByteString*     a_pMac)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "HMAC_SHA384_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_key.Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pMac);
    
    if(a_pMac->Data == OpcUa_Null)
    {
        a_pMac->Length = 48;
        OpcUa_ReturnStatusCode;
    }

    HMAC(EVP_sha384(),a_key.Key.Data,a_key.Key.Length,a_pData,a_dataLen,a_pMac->Data,(unsigned int*)&(a_pMac->Length));
    
    if(a_pMac->Length <= 0) 
        uStatus = OpcUa_Bad;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;

OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_HMAC_SHA2_512_Generate
 *===========================================================================*/
/* HMAC-SHA-2: 512 Bits output */
OpcUa_StatusCode OpcUa_P_OpenSSL_HMAC_SHA2_512_Generate(
    OpcUa_CryptoProvider* a_pProvider,
    OpcUa_Byte*           a_pData,
    OpcUa_UInt32          a_dataLen,
    OpcUa_Key             a_key,
    OpcUa_ByteString*     a_pMac)
{
    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "HMAC_SHA512_Generate");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_key.Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pMac);

    if(a_pMac->Data == OpcUa_Null)
    {
        a_pMac->Length = 64;
        OpcUa_ReturnStatusCode;
    }

    HMAC(EVP_sha512(),a_key.Key.Data,a_key.Key.Length,a_pData,a_dataLen,a_pMac->Data,(unsigned int*)&(a_pMac->Length));

    if(a_pMac->Length <= 0) 
        uStatus = OpcUa_Bad;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;

OpcUa_FinishErrorHandling;
}

#endif /* OPCUA_REQUIRE_OPENSSL */
