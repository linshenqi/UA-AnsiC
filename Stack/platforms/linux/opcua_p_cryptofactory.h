/*============================================================================
  @file opcua_p_cryptofactory.h
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
#ifndef _OpcUa_P_CryptoFactory_H_
#define _OpcUa_P_CryptoFactory_H_ 1

OPCUA_BEGIN_EXTERN_C

/** 
  @brief OpcUa_CryptoFactory_CreateCryptoProvider.
  
  @param securityPolicy     [in]  The security policy.
  @param pProvider          [out] The resulting CryptoProvider.
*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_CryptoFactory_CreateCryptoProvider(  OpcUa_StringA           Uri,
                                                                            OpcUa_CryptoProvider*   pProvider);

/** 
  @brief OpcUa_CryptoFactory_DeleteCryptoProvider.
  
  @param pProvider         [out] The resulting CryptoProvider.
*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_CryptoFactory_DeleteCryptoProvider(  OpcUa_CryptoProvider* pProvider);

/* HA: 22.02.2009 -> STACK_INTEGRATION */
/* the following 2 functions are commented by an #if 0 in the LINUX version!*/ 

/** 
  @brief OpcUa_CryptoFactory_GetEncryptionMethods.
  
  @param ppSignatureMethods                [out] The pointer for encryption methods.
  @param pSignatureMethodsCount         [out] The amount of available signature methods.
*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_CryptoFactory_GetEncryptionMethods(    OpcUa_StringA**                 ppEncryptionMethods,
                                                                            OpcUa_UInt*                  pEncryptionMethodsCount);

/** 
  @brief OpcUa_CryptoFactory_GetEncryptionMethods.
  
  @param pSignatureMethods                [out] The pointer for encryption methods.
  @param pSignatureMethodsCount         [out] The amount of available signature methods.
*/
OpcUa_StatusCode OPCUA_DLLCALL OpcUa_P_CryptoFactory_GetSignatureMethods(    OpcUa_StringA**                 pSignatureMethods,
                                                                            OpcUa_UInt*                  pSignatureMethodsCount);
/* HA: 22.02.2009 -> STACK_INTEGRATION */

/*============================================================================
 * The OpcUa_CryptoProvider interface.
 *===========================================================================*/

typedef struct _OpcUa_CryptoProviderConfig
{
    OpcUa_Int32  SymmetricKeyLength;
    OpcUa_UInt32 MinimumAsymmetricKeyLength;
    OpcUa_UInt32 MaximumAsymmetricKeyLength;
    OpcUa_UInt32 DerivedEncryptionKeyLength;
    OpcUa_UInt32 DerivedSignatureKeyLength;

    OpcUa_Void*  WindowsCryptoProvHandle;   /* Windows CryptoProvider Handle ->wincrypt.h */
}
OpcUa_CryptoProviderConfig;


OPCUA_END_EXTERN_C

#endif

