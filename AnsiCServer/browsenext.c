/* serverstub (basic includes for implementing a server based on the stack) */
#include <opcua_serverstub.h>
#include <opcua_string.h>
#include <opcua_memory.h>
#include "adressraum.h"
#include "browseservice.h"
#include "mytrace.h"
#include "general_header.h"







/*============================================================================
 * A stub method which implements the BrowseNext service.
 *===========================================================================*/
OpcUa_StatusCode my_BrowseNext(
    OpcUa_Endpoint             a_hEndpoint,
    OpcUa_Handle               a_hContext,
    const OpcUa_RequestHeader* a_pRequestHeader,
    OpcUa_Boolean              a_bReleaseContinuationPoints,
    OpcUa_Int32                a_nNoOfContinuationPoints,
    const OpcUa_ByteString*    a_pContinuationPoints,
    OpcUa_ResponseHeader*      a_pResponseHeader,
    OpcUa_Int32*               a_pNoOfResults,
    OpcUa_BrowseResult**       a_pResults,
    OpcUa_Int32*               a_pNoOfDiagnosticInfos,
    OpcUa_DiagnosticInfo**     a_pDiagnosticInfos)
{
	extern OpcUa_Int			Continuation_Point_Identifier;
	OpcUa_Int m;
	extern OpcUa_UInt32		securechannelId;
	extern OpcUa_UInt32		session_flag;
	extern OpcUa_Double		msec_counter;
	extern OpcUa_String*	p_user_name;
	extern enum
	{
		free_to_use=0,
		occupied=1
	}continuation_point;

    OpcUa_InitializeStatus(OpcUa_Module_Server, "OpcUa_ServerApi_BrowseNext");

	
	
    /* validate arguments. */
    OpcUa_ReturnErrorIfArgumentNull(a_hEndpoint);
    OpcUa_ReturnErrorIfArgumentNull(a_hContext);
    OpcUa_ReturnErrorIfArgumentNull(a_pRequestHeader);
    OpcUa_ReferenceParameter(a_bReleaseContinuationPoints);
    OpcUa_ReturnErrorIfArrayArgumentNull(a_nNoOfContinuationPoints, a_pContinuationPoints);
    OpcUa_ReturnErrorIfArgumentNull(a_pResponseHeader);
    OpcUa_ReturnErrorIfArgumentNull(a_pNoOfResults);
    OpcUa_ReturnErrorIfArgumentNull(a_pResults);
    OpcUa_ReturnErrorIfArgumentNull(a_pNoOfDiagnosticInfos);
    OpcUa_ReturnErrorIfArgumentNull(a_pDiagnosticInfos);

	*a_pNoOfDiagnosticInfos=0;
	*a_pDiagnosticInfos=OpcUa_Null;

	RESET_SESSION_COUNTER

#ifndef NO_DEBUGING_
	MY_TRACE("\n\n\nBROWSENEXTSERVICE=========================================\n");
	if(p_user_name!=OpcUa_Null)
		MY_TRACE("\nUser:%s\n",OpcUa_String_GetRawString(p_user_name)); 
#endif /*_DEBUGING_*/


	if(OpcUa_IsBad(session_flag))
	{
		//teile client mit , dass Session geschlossen ist
#ifndef NO_DEBUGING_
		MY_TRACE("\nSession nicht aktiv\n"); 
#endif /*_DEBUGING_*/
		uStatus=OpcUa_BadSessionNotActivated;
		OpcUa_GotoError;
	}

	uStatus=check_authentication_token(a_pRequestHeader);
	if(OpcUa_IsBad(uStatus))
	{
#ifndef NO_DEBUGING_
		MY_TRACE("\nAuthentication Token ungültig.\n"); 
#endif /*_DEBUGING_*/
		OpcUa_GotoError;
	}

	if(a_bReleaseContinuationPoints==OpcUa_False)
	{
		*a_pResults=OpcUa_Memory_Alloc(a_nNoOfContinuationPoints*sizeof(OpcUa_BrowseResult));
		OpcUa_GotoErrorIfAllocFailed((*a_pResults))

		*a_pNoOfResults=a_nNoOfContinuationPoints;

		continuation_point=free_to_use;

		for(m=0;m<a_nNoOfContinuationPoints;m++)
		{
			OpcUa_BrowseResult_Initialize((*a_pResults+m));
			if((a_pContinuationPoints+m)->Data!=OpcUa_Null)
			{
				if((((_my_continuationpoint_*)(a_pContinuationPoints+m)->Data)->Cont_Point_Identiefer)==Continuation_Point_Identifier)
				{
					#ifndef NO_DEBUGING_
						MY_TRACE("\nContinuationPoint (Identifier:%d) wurde uebergeben.\n",(((_my_continuationpoint_*)(a_pContinuationPoints+m)->Data)->Cont_Point_Identiefer)); 
					#endif /*_DEBUGING_*/
					(*a_pResults+m)->StatusCode=browse(&(((_my_continuationpoint_*)(a_pContinuationPoints+m)->Data)->NodeToBrowse),(*a_pResults+m),((_my_continuationpoint_*)(a_pContinuationPoints+m)->Data)->Aktuelle_Ref);
				}
				else
				{
					(*a_pResults+m)->StatusCode=OpcUa_BadContinuationPointInvalid;
					#ifndef NO_DEBUGING_
						MY_TRACE("\n%d. ContinuationPoint Identifier ungueltig!!!\n",m); 
					#endif /*_DEBUGING_*/
				}

			}
			else
			{
				(*a_pResults+m)->StatusCode=OpcUa_BadContinuationPointInvalid;
				#ifndef NO_DEBUGING_
					MY_TRACE("\n%d. ContinuationPoint ungueltig!!!\n",m); 
				#endif /*_DEBUGING_*/
			}
		}
	}
	else
	{
		Continuation_Point_Identifier=0;
		#ifndef NO_DEBUGING_
			MY_TRACE("\nBrowseNext aufgerufen, Cont.Point zu loeschen");
			MY_TRACE("\n..................ContinuationPoint geloescht.\n");
		#endif /*_DEBUGING_*/
	}
	uStatus = response_header_ausfuellen(a_pResponseHeader,a_pRequestHeader,uStatus);
	if(OpcUa_IsBad(uStatus))
	{
       a_pResponseHeader->ServiceResult=OpcUa_BadInternalError;
	}
#ifndef NO_DEBUGING_
	MY_TRACE("\nSERVICE===ENDE============================================\n\n\n"); 
#endif /*_DEBUGING_*/

	RESET_SESSION_COUNTER

    OpcUa_ReturnStatusCode;
    OpcUa_BeginErrorHandling;

    
	uStatus = response_header_ausfuellen(a_pResponseHeader,a_pRequestHeader,uStatus);
	if(OpcUa_IsBad(uStatus))
	{
       a_pResponseHeader->ServiceResult=OpcUa_BadInternalError;
	}
#ifndef NO_DEBUGING_
	MY_TRACE("\nSERVICEENDE (IM SERVICE SIND FEHLER AUFGETRETTEN)===========\n\n\n"); 
#endif /*_DEBUGING_*/
	
	RESET_SESSION_COUNTER
    OpcUa_FinishErrorHandling;
}
