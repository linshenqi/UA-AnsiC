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
#include <memory.h>
#include <openssl/aes.h>

/* own headers */
#include <opcua_p_openssl.h>

/*** AES SYMMETRIC ENCRYPTION ***/

/*============================================================================
 * OpcUa_P_OpenSSL_AES_CBC_Encrypt
 *===========================================================================*/
OpcUa_StatusCode OpcUa_P_OpenSSL_AES_CBC_Encrypt(
    OpcUa_CryptoProvider*   a_pProvider,
    OpcUa_Byte*             a_pPlainText,
    OpcUa_UInt32            a_plainTextLen,
    OpcUa_Key*              a_key,
    OpcUa_Byte*             a_pInitalVector,
    OpcUa_Byte*             a_pCipherText,
    OpcUa_UInt32*           a_pCipherTextLen)
{
    AES_KEY         key;
    
    OpcUa_Byte*     pInitalVector = OpcUa_Null;
    OpcUa_UInt32    keyLenInBits  = 0;

    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "AES_CBC_Encrypt");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_pPlainText);
    OpcUa_ReturnErrorIfArgumentNull(a_key);
    OpcUa_ReturnErrorIfArgumentNull(a_key->Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pInitalVector);
    OpcUa_ReturnErrorIfArgumentNull(a_pCipherTextLen);

    if((((OpcUa_Int)a_plainTextLen) < 0) || (a_key->Key.Length < 0))
    {
        uStatus = OpcUa_BadInvalidArgument;
        OpcUa_GotoErrorIfBad(uStatus);
    }

    keyLenInBits = (a_key->Key.Length*8);

    /* we have to pass the key length in bits instead of bytes */
    if(AES_set_encrypt_key(a_key->Key.Data, keyLenInBits, &key) < 0)
    {
        uStatus = OpcUa_Bad;
        OpcUa_GotoErrorIfBad(uStatus);
    }

    *a_pCipherTextLen = a_plainTextLen;

    /* if just the output length is needed for the caller of this function */
    if(a_pCipherText == OpcUa_Null)
    {
        OpcUa_ReturnStatusCode;
    }

    /* copy the IV because the AES_cbc_encrypt function overwrites it. */
    pInitalVector = (OpcUa_Byte*)OpcUa_P_Memory_Alloc(16);
    OpcUa_ReturnErrorIfAllocFailed(pInitalVector);
    OpcUa_P_Memory_MemCpy(pInitalVector, 16, a_pInitalVector, 16);

    /* encrypt data */
    AES_cbc_encrypt(    a_pPlainText,
                        a_pCipherText,
                        *a_pCipherTextLen,
                        &key,
                        pInitalVector,
                        AES_ENCRYPT);

    OpcUa_ReturnErrorIfNull(a_pCipherText, OpcUa_Bad);

    OpcUa_P_Memory_Free(pInitalVector);
    pInitalVector = OpcUa_Null;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;

    OpcUa_P_Memory_Free(pInitalVector);
    pInitalVector = OpcUa_Null;

OpcUa_FinishErrorHandling;
}

/*============================================================================
 * OpcUa_P_OpenSSL_AES_CBC_decrypt
 *===========================================================================*/
OpcUa_StatusCode OpcUa_P_OpenSSL_AES_CBC_Decrypt(
    OpcUa_CryptoProvider*   a_pProvider,
    OpcUa_Byte*             a_pCipherText,
    OpcUa_UInt32            a_cipherTextLen,
    OpcUa_Key*              a_key,
    OpcUa_Byte*             a_pInitalVector,
    OpcUa_Byte*             a_pPlainText,
    OpcUa_UInt32*           a_pPlainTextLen)
{
    AES_KEY         key;
    OpcUa_Byte*     pInitalVector = OpcUa_Null;

    OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "AES_CBC_Decrypt");

    OpcUa_ReferenceParameter(a_pProvider);

    OpcUa_ReturnErrorIfArgumentNull(a_pCipherText);
    OpcUa_ReturnErrorIfArgumentNull(a_key);
    OpcUa_ReturnErrorIfArgumentNull(a_key->Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pInitalVector);

    if(a_pPlainText == OpcUa_Null)
    {
        *a_pPlainTextLen = a_cipherTextLen;
        OpcUa_ReturnStatusCode;
    }

    /* we have to pass the key length in bits instead of bytes */
    if(AES_set_decrypt_key(a_key->Key.Data,(a_key->Key.Length*8),&key) < 0)
    {
        OpcUa_GotoErrorWithStatus(OpcUa_Bad);
    }

    /* copy the IV because the AES_cbc_encrypt function overwrites it. */
    pInitalVector = (OpcUa_Byte*)OpcUa_P_Memory_Alloc(16);
    OpcUa_ReturnErrorIfAllocFailed(pInitalVector);
    OpcUa_P_Memory_MemCpy(pInitalVector, 16, a_pInitalVector, 16);
    
    /* decrypt ciphertext */ 
    AES_cbc_encrypt(    a_pCipherText,
                        a_pPlainText,
                        a_cipherTextLen,
                        &key,
                        pInitalVector,
                        AES_DECRYPT);

    /* get real message length */
    *a_pPlainTextLen = a_cipherTextLen;
    
    OpcUa_P_Memory_Free(pInitalVector);
    pInitalVector = OpcUa_Null;

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;
    
    OpcUa_P_Memory_Free(pInitalVector);
    pInitalVector = OpcUa_Null;

OpcUa_FinishErrorHandling;
}

#endif /* OPCUA_REQUIRE_OPENSSL */
