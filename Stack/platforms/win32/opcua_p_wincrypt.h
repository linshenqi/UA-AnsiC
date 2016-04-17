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

#ifndef _OpcUa_P_WinCrypt_H_
#define _OpcUa_P_WinCrypt_H_ 1

OPCUA_BEGIN_EXTERN_C

/** 
  @brief Initializes the WinCrypt library.
*/
OpcUa_StatusCode OpcUa_P_WinCrypt_Initialize();

/** 
  @brief Initializes the WinCrypt library.
*/
OpcUa_StatusCode OpcUa_P_WinCrypt_Cleanup();

/**
  @brief Adds random data to the destination buffer..

    if keyLen > 0 then random data of the given length is generated.
    if keyLen == 0 then nothing will be generated.
    if keyLen < 0 then default setting from the CryptoProvider is used.

    if there are no default settings then an error is returned.
 
  @param pProvider        [in]  The crypto provider handle.
  @param keyLen           [in]  The desired length of the random key.
  
  @param pKey             [out] The generated random key.
 */
OpcUa_StatusCode OpcUa_P_WinCrypt_Random_Key_Generate(  OpcUa_CryptoProvider* pProvider,
                                                        OpcUa_Int32           keyLen,
                                                        OpcUa_Key*            pKey);

OPCUA_END_EXTERN_C

#endif

