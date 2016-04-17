/* Copyright (c) 1996-2016, OPC Foundation. All rights reserved.

   The source code in this file is covered under a dual-license scenario:
     - RCL: for OPC Foundation members in good-standing
     - GPL V2: everybody else

   RCL license terms accompanied with this source code. See http://opcfoundation.org/License/RCL/1.00/

   GNU General Public License as published by the Free Software Foundation;
   version 2 of the License are accompanied with this source code. See http://opcfoundation.org/License/GPLv2

   This source code is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
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

