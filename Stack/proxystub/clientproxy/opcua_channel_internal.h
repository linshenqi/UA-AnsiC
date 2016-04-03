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

#ifdef OPCUA_HAVE_CLIENTAPI

#include <opcua_credentials.h>
#include <opcua_connection.h>
#include <opcua_stringtable.h>
#include <opcua_encodeableobject.h>
#include <opcua_decoder.h>

#define OPCUA_CHANNEL_USE_STATE 0

#if OPCUA_CHANNEL_USE_STATE
enum _OpcUa_Channel_State
{
    eOpcUa_Channel_State_Invalid,
    eOpcUa_Channel_State_Connecting,
    eOpcUa_Channel_State_Connected,
    eOpcUa_Channel_State_Disconnecting,
    eOpcUa_Channel_State_Disconnected,
    eOpcUa_Channel_State_Reconnecting
};
typedef enum _OpcUa_Channel_State OpcUa_Channel_State;
#endif

/**
  @brief Manages the state of a client session with a server.
*/
struct _OpcUa_InternalChannel
{
    /*! @brief The url of the server endpoint. */
    OpcUa_String                                Url;

    /*! @brief The credentials that must be passed to the transport layer (e.g. SSL). */
    OpcUa_ClientCredential*                     TransportCredential;

    /*! @brief The timeout, in milliseconds, for network operations. */
    OpcUa_UInt32                                NetworkTimeout;

    /*! @brief The client's application certificate. */
    OpcUa_X509Credential*                       ClientCertificate;

    /*! @brief The server's application certificate (if known). */
    OpcUa_X509Credential*                       ServerCertificate;

    /*! @brief The transport connection to the server. */
    OpcUa_Connection*                           TransportConnection;

    /*! @brief The secure channel for the session. */
    OpcUa_Connection*                           SecureConnection;

    /*! @brief The encoder used for messages sent via the channel */
    OpcUa_Encoder*                              Encoder;

    /*! @brief The decoder used for messages received via the channel */
    OpcUa_Decoder*                              Decoder;

    /*! @brief The timeout for the session in milliseconds. */
    OpcUa_UInt32                                SessionTimeout;

    /*! @brief A mutex used to synchronous access to the session. */
    OpcUa_Mutex                                 Mutex;

#if OPCUA_CHANNEL_USE_STATE
    /*! @brief The state of the channel. */
    OpcUa_Channel_State                         State;

    /*! @brief Handle to transport data during asynchronous calls */
    OpcUa_Handle                                hAsyncContext;
#else
    /*! @brief  */
    OpcUa_Channel_PfnConnectionStateChanged*    pfCallback;
    /*! @brief  */
    OpcUa_Void*                                 pvCallbackData;
#endif
};

typedef struct _OpcUa_InternalChannel OpcUa_InternalChannel;

#endif /* OPCUA_HAVE_CLIENTAPI */
