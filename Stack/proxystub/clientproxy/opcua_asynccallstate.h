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

#ifndef _OpcUa_AsyncCallState_H_
#define _OpcUa_AsyncCallState_H_ 1
#ifdef OPCUA_HAVE_CLIENTAPI

OPCUA_BEGIN_EXTERN_C

/** 
  @brief Manages the state of an asynchronous request.
*/
struct _OpcUa_AsyncCallState
{
    /*! @brief The channel used to send the asynchronous service call. */
    OpcUa_Void* Channel;

#if 0 /* not required */
    /*! @brief The name of the service. */
    OpcUa_StringA Name;
#endif

    /*! @brief The request sent to the server. */
    OpcUa_Void* RequestData;

    /*! @brief The type of request sent to the server. */
    OpcUa_EncodeableType* RequestType;

    /*! @brief The response returned from the server. */
    OpcUa_Void* ResponseData;
    
    /*! @brief The type of response returned from the server. */
    OpcUa_EncodeableType* ResponseType;
    
    /*! @brief The status associated with the service call. */
    OpcUa_StatusCode Status;

    /*! @brief A mutex used to synchronous access to the call state. */
    OpcUa_Mutex WaitMutex;
    
    /*! @brief A semaphore that is released when the call completes. */
    OpcUa_Semaphore WaitCondition;

    /*! @brief The application callback provided with the request. */
    OpcUa_Channel_PfnRequestComplete* Callback;

    /*! @brief The data to pass to the application callback. */
    OpcUa_Void* CallbackData;
};

typedef struct _OpcUa_AsyncCallState OpcUa_AsyncCallState;

/** 
  @brief Creates a new asynchronous call state object.

  @param hChannel     [in]  Handle of the channel over which the request is sent.
  @param pRequestData [in]  The request data associated with the call.
  @param pRequestType [in]  The type of request data (pointer a readonly structure).
  @param ppAsyncState [out] The new call state.
*/
OpcUa_StatusCode OpcUa_AsyncCallState_Create(
    OpcUa_Void*             hChannel,
    OpcUa_Void*             pRequestData,
    OpcUa_EncodeableType*   pRequestType,
    OpcUa_AsyncCallState**  ppAsyncState);

/** 
  @brief Deletes a asynchronous call state object.

  @param ppCallState [in/out] The  call state to delete.
*/
OpcUa_Void OpcUa_AsyncCallState_Delete(OpcUa_AsyncCallState** ppCallState);

/** 
  @brief Waits for an aynchronous call to complete.

  If this call fails the caller must delete the async state object. 

  @param pAsyncState [in] The asynchronous call to wait on.
  @param uTimeout    [in] The maximum wait time in milliseconds.
*/
OpcUa_StatusCode OpcUa_AsyncCallState_WaitForCompletion(
    OpcUa_AsyncCallState* pAsyncState,
    OpcUa_UInt32          uTimeout);

/** 
  @brief Signals that an asynchronous call is complete.

  If this call fails the caller must delete the async state object. 

  @param pAsyncState      [in] The asynchronous call to signal.
  @param uOperationStatus [in] The status of the operation.
*/
OpcUa_StatusCode OpcUa_AsyncCallState_SignalCompletion(
    OpcUa_AsyncCallState* pAsyncState,
    OpcUa_StatusCode      uOperationStatus);

OPCUA_END_EXTERN_C

#endif /* OPCUA_HAVE_CLIENTAPI */
#endif /* _OpcUa_AsyncCallState_H_ */
