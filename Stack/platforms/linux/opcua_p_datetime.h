/******************************************************************************************************/
/* (c) Copyright 2005-2008 The OPC Foundation                                                         */
/* ALL RIGHTS RESERVED.                                                                               */
/*                                                                                                    */
/* DISCLAIMER:                                                                                        */
/*  This code is provided by the OPC Foundation solely to assist in                                   */
/*  understanding and use of the appropriate OPC Specification(s) and may be                          */
/*  used as set forth in the License Grant section of the OPC Specification.                          */
/*  This code is provided as-is and without warranty or support of any sort                           */
/*  and is subject to the Warranty and Liability Disclaimers which appear                             */
/*  in the printed OPC Specification.                                                                 */
/******************************************************************************************************/
/* Platform Portability Layer                                                                         */
/* Modify the content of this file according to the event implementation on your system.              */
/* This is the Linux implementation                                                                   */
/******************************************************************************************************/

/**
* @brief Checks wether the given DateTime value is valid/set
*/
OpcUa_Boolean   OpcUa_P_DateTime_Set(     OpcUa_DateTime value);

/**
* @brief Sets the given DateTime value to unset/invalid
*/
OpcUa_Void      OpcUa_P_DateTime_UnSet(   OpcUa_DateTime* pValue);

/**
 * @brief Returns the current time in UTC.
 */
OpcUa_DateTime  OpcUa_P_DateTime_UtcNow(void);

/**
 * @brief Returns the time in OpcUa_TimeVal format.
 */
OpcUa_Void      OpcUa_P_DateTime_GetTimeOfDay(OpcUa_TimeVal*  pValue);

/**
* @brief Converts the given OpcUa_DateTime into a ascii string.
* 
* @param DateTime   [in]        The DateTime value to convert.
* @param Buffer     [in/out]    At least 20+1 bytes of buffer. 
* @param DateTime   [in]        The length of the given buffer.
*
* @return Error Code
*/
OpcUa_StatusCode OpcUa_P_DateTime_GetStringFromDateTime(OpcUa_DateTime datetime, 
                                                        OpcUa_StringA  buffer,
                                                        OpcUa_UInt32   length);


/**
* @brief Converts the given (ascii) string into OpcUa_DateTime format.
*
* @param DateTimeString [in]    Buffer containing the DateTime string. Must not be OpcUa_Null!
* @param DateTime      [out]    Pointer to the OpcUa_DateTime value in which the converted value will be stored.
*
* @return Status Code.
*/
OpcUa_StatusCode  OpcUa_P_DateTime_GetDateTimeFromString( OpcUa_StringA   DateTimeString, 
                                                        OpcUa_DateTime* DateTime);
