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
#include <openssl/des.h>

/* own headers */
#include <opcua_p_openssl.h>

/*  DES_ede3_cbc_encrypt() implements outer triple CBC DES encryption with three keys. 
    This means that each DES operation inside the CBC mode is really an 
    C=E(ks3,D(ks2,E(ks1,M))). This mode is used by SSL. http://www.openssl.org/docs/crypto/des.html# */

/*============================================================================
 * OpcUa_P_OpenSSL_DES_CBC_Encrypt
 *===========================================================================*/
OpcUa_StatusCode OpcUa_P_OpenSSL_3DES_Encrypt(  OpcUa_CryptoProvider*   a_pProvider,
                                                OpcUa_Byte*             a_pPlainText,
                                                OpcUa_UInt32            a_plainTextLen,
                                                OpcUa_Key               a_key,
                                                OpcUa_Byte*             a_pInitalVector,
                                                OpcUa_Byte*             a_pCipherText,
                                                OpcUa_UInt32*           a_pCipherTextLen)
{
    DES_key_schedule    ks1;
    DES_key_schedule    ks2;
    DES_key_schedule    ks3;
    
    DES_cblock*         desKey              = OpcUa_Null;

OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "");

    OpcUa_ReturnErrorIfArgumentNull(a_pPlainText);
    OpcUa_ReturnErrorIfArgumentNull(a_key.Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pInitalVector);
    OpcUa_ReturnErrorIfArgumentNull(a_pCipherTextLen);

    OpcUa_ReferenceParameter(a_pProvider);

    if(a_pCipherText == OpcUa_Null)
    {
        *a_pCipherTextLen = a_plainTextLen;
        OpcUa_ReturnStatusCode;
    }

    /* get key(s) */
    desKey = (DES_cblock*)a_key.Key.Data;

    /* set keys */
    DES_set_key_unchecked(&desKey[0], &ks1);
    DES_set_key_unchecked(&desKey[1], &ks2);
    DES_set_key_unchecked(&desKey[2], &ks3);

    /* encrypt data */
    DES_ede3_cbc_encrypt(   a_pPlainText,                   /* input                    */
                            a_pCipherText,                  /* output                   */
                            a_plainTextLen,                 /* input length             */
                            &ks1,                           /* key schedule 1           */
                            &ks2,                           /* key schedule 2           */
                            &ks3,                           /* key schedule 3           */
                            (DES_cblock*)a_pInitalVector,   /* initialization vector    */
                            DES_ENCRYPT);                   /* do encrypt               */

    if(a_pCipherTextLen != OpcUa_Null)
    {
        *a_pCipherTextLen = a_plainTextLen;
    }

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}


/*============================================================================
 * OpcUa_P_OpenSSL_DES_CBC_decrypt
 *===========================================================================*/
OpcUa_StatusCode OpcUa_P_OpenSSL_3DES_Decrypt(  OpcUa_CryptoProvider*   a_pProvider,
                                                OpcUa_Byte*             a_pCipherText,
                                                OpcUa_UInt32            a_cipherTextLen,
                                                OpcUa_Key               a_key,
                                                OpcUa_Byte*             a_pInitalVector,
                                                OpcUa_Byte*             a_pPlainText,
                                                OpcUa_UInt32*           a_pPlainTextLen)
{
    DES_key_schedule    ks1;
    DES_key_schedule    ks2;
    DES_key_schedule    ks3;
    
    DES_cblock*         desKey              = OpcUa_Null;

OpcUa_InitializeStatus(OpcUa_Module_P_OpenSSL, "DES_CBC_Decrypt");

    OpcUa_ReturnErrorIfArgumentNull(a_pCipherText);
    OpcUa_ReturnErrorIfArgumentNull(a_key.Key.Data);
    OpcUa_ReturnErrorIfArgumentNull(a_pInitalVector);
    OpcUa_ReturnErrorIfArgumentNull(a_pPlainTextLen);
    
    OpcUa_ReferenceParameter(a_pProvider);
    
    /* get key(s) */
    desKey = (DES_cblock*)a_key.Key.Data;

    if(a_pPlainText == OpcUa_Null)
    {
        *a_pPlainTextLen = a_cipherTextLen;
        OpcUa_ReturnStatusCode;
    }

    /* set keys */
    DES_set_key_unchecked(&desKey[0], &ks1);
    DES_set_key_unchecked(&desKey[1], &ks2);
    DES_set_key_unchecked(&desKey[2], &ks3);
    
    /* decrypt ciphertext */
    DES_ede3_cbc_encrypt(   a_pCipherText,                  /* input                    */
                            a_pPlainText,                   /* output                   */
                            a_cipherTextLen,                /* input length             */
                            &ks1,                           /* key schedule 1           */
                            &ks2,                           /* key schedule 2           */
                            &ks3,                           /* key schedule 3           */
                            (DES_cblock*)a_pInitalVector,   /* initialization vector    */
                            DES_DECRYPT);                   /* do decrypt               */
    
    if(a_pPlainTextLen != OpcUa_Null)
    {
        *a_pPlainTextLen = a_cipherTextLen;
    }

OpcUa_ReturnStatusCode;
OpcUa_BeginErrorHandling;
OpcUa_FinishErrorHandling;
}

#endif /* OPCUA_REQUIRE_OPENSSL */
