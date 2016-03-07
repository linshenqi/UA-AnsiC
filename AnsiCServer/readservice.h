#ifndef _readservice_
#define _readservice_


#define RESET_SESSION_COUNTER	msec_counter=0; 


OpcUa_StatusCode my_Read(
							OpcUa_Endpoint             a_hEndpoint,
							OpcUa_Handle               a_hContext,
							const OpcUa_RequestHeader* a_pRequestHeader,
							OpcUa_Double               a_nMaxAge,
							OpcUa_TimestampsToReturn   a_eTimestampsToReturn,
							OpcUa_Int32                a_nNoOfNodesToRead,
							const OpcUa_ReadValueId*   a_pNodesToRead,
							OpcUa_ResponseHeader*      a_pResponseHeader,
							OpcUa_Int32*               a_pNoOfResults,
							OpcUa_DataValue**          a_pResults,
							OpcUa_Int32*               a_pNoOfDiagnosticInfos,
							OpcUa_DiagnosticInfo**     a_pDiagnosticInfos);
OpcUa_StatusCode  fill_Variant_for_value_attribute(_VariableKnoten_*  , OpcUa_String* , OpcUa_DataValue* );

OpcUa_StatusCode fill_datatype_arraytype_in_my_Variant(OpcUa_DataValue* ,OpcUa_Byte, OpcUa_Byte,OpcUa_Int);

OpcUa_StatusCode assigne_Timestamp(OpcUa_DataValue* ,OpcUa_TimestampsToReturn );



#endif /*_readservice_*/