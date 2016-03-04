/*============================================================================
  @file opcua_p_crypto.h
  @brief 

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


#ifndef _OpcUa_P_Crypto_H_
#define _OpcUa_P_Crypto_H_ 1

OPCUA_BEGIN_EXTERN_C

/* MESSAGE DIGEST */
#define OPCUA_P_SHA_160 160
#define OPCUA_P_SHA_224 224
#define OPCUA_P_SHA_256 256
#define OPCUA_P_SHA_384 384
#define OPCUA_P_SHA_512 512

/* SecurityPolicies */
#define OpcUa_SecurityPolicy_None           "http://opcfoundation.org/UA/SecurityPolicy#None"
#define OpcUa_SecurityPolicy_Basic128       "http://opcfoundation.org/UA/SecurityPolicy#Basic128"
#define OpcUa_SecurityPolicy_Basic128Rsa15  "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
#define OpcUa_SecurityPolicy_Basic192       "http://opcfoundation.org/UA/SecurityPolicy#Basic192"
#define OpcUa_SecurityPolicy_Basic192Rsa15  "http://opcfoundation.org/UA/SecurityPolicy#Basic192Rsa15"
#define OpcUa_SecurityPolicy_Basic256       "http://opcfoundation.org/UA/SecurityPolicy#Basic256"
#define OpcUa_SecurityPolicy_Basic256Rsa15  "http://opcfoundation.org/UA/SecurityPolicy#Basic256Rsa15"
#define OpcUa_SecurityPolicy_Basic256Sha256 "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256"

/* Signature Algorithm Uris */
#define OpcUa_AlgorithmUri_Signature_RsaSha1   "http://www.w3.org/2000/09/xmldsig#rsa-sha1"
#define OpcUa_AlgorithmUri_Signature_RsaSha256 "http://www.w3.org/2001/04/xmldsig-more#rsa-sha256"

/* Encryption Algorithms Uris */
#define OpcUa_AlgorithmUri_Encryption_RsaOaep  "http://www.w3.org/2001/04/xmlenc#rsa-oaep"
#define OpcUa_AlgorithmUri_Encryption_Rsa15    "http://www.w3.org/2001/04/xmlenc#rsa-1_5"

/* Encryption Algs */
#define OpcUa_P_NoEncryption_Name                   ""
#define OpcUa_P_NoEncryption_Id                     0

#define OpcUa_P_AES_128_CBC_Name                    "AES-128-CBC"
#define OpcUa_P_AES_128_CBC_Id                      1

#define OpcUa_P_AES_256_CBC_Name                    "AES-256-CBC"
#define OpcUa_P_AES_256_CBC_Id                      2

#define OpcUa_P_RSA_PKCS1_V15_Name                  "RSA-PKCS-#1-V1.5"
#define OpcUa_P_RSA_PKCS1_V15_Id                    3

#define OpcUa_P_RSA_OAEP_Name                       "RSA-OAEP"
#define OpcUa_P_RSA_OAEP_Id                         4

#define OpcUa_P_DES3_Name                           "3DES"
#define OpcUa_P_DES3_Id                             5

#define OpcUa_P_EncryptionMethodsCount              5

/* Signature Algs */
#define OpcUa_P_NoSignature_Name                    ""
#define OpcUa_P_NoSignature_Id                      0

#define OpcUa_P_RSA_PKCS1_V15_SHA1_Name             "RSA-PKCS-#1-V1.5-SHA1"
#define OpcUa_P_RSA_PKCS1_V15_SHA1_Id               6

#define OpcUa_P_RSA_PKCS1_V15_SHA256_Name           "RSA-PKCS-#1-V1.5-SHA256"
#define OpcUa_P_RSA_PKCS1_V15_SHA256_Id             7 

#define OpcUa_P_HMAC_SHA1_Name                      "HMAC-SHA1"
#define OpcUa_P_HMAC_SHA1_Id                        8 

#define OpcUa_P_HMAC_SHA256_Name                    "HMAC-SHA256"
#define OpcUa_P_HMAC_SHA256_Id                      9

#define OpcUa_P_RSA_PKCS1_OAEP_SHA1_Name            "RSA-PKCS-#1-OAEP-SHA1"
#define OpcUa_P_RSA_PKCS1_OAEP_SHA1_Id              10

#define OpcUa_P_RSA_PKCS1_OAEP_SHA256_Name          "RSA-PKCS-#1-OAEP-SHA256"
#define OpcUa_P_RSA_PKCS1_OAEP_SHA256_Id            11 

#define OpcUa_P_SignatureMethodsCount               6

/* PRF Algs */
#define OpcUa_P_PSHA1_Name                          "P-SHA1"
#define OpcUa_P_PSHA1_Id                            12

#define OpcUa_P_PRFMethodsCount                     1

OPCUA_END_EXTERN_C

#endif
