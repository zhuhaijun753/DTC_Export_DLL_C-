#ifndef __BATTERY_RESET_ENUMERATION_H__
#define __BATTERY_RESET_ENUMERATION_H__



// =====================================================================================================
//	 								BATTERY RESET PROCEDURE
// =====================================================================================================

typedef enum	__enumBATResetStatus
{
  eBAT_RESET_NONE				= 0,
  
  eBAT_RESET_NOTSUPPORT   		= 1,	/* the procedure text requested was not supported*/
  eBAT_RESET_OK	        		= 2,	/* the procedure text was supported and get OK*/
  
  eBAT_RESET_BUFF_OVER_FLOW    	= 3,	/* the procedure text was supported, buffer to store text is over flow*/
  
  eBAT_RESET_MAX				= 0xFF
} enumBATResetStatus;

typedef enum	__enumBRP_GetInfoUnit
{
    eBAT_RESET_PROCEDURE_NONE					            =	0,
	
    eBAT_RESET_PROCEDURE_GET_GENERAL_INFORMATION_TEXT    	=   1,
    eBAT_RESET_PROCEDURE_GET_BEFORE_DISCONNECTION_TEXT   	=   2,
    eBAT_RESET_PROCEDURE_GET_BEFORE_CONNECTION_TEXT      	=   3,
    eBAT_RESET_PROCEDURE_GET_AFTER_CONNECTION_TEXT      	=   4,
    
    eBAT_RESET_PROCEDURE_MAX                    	        =   0XFF,
}enumBRP_GetInfoUnit;



// =====================================================================================================
//	 								BATTERY RESET SERVICE
// =====================================================================================================

typedef enum	__enumBRS_LiveData_Status
{
  eBRS_LIVE_DATA_NONE				= 0,
  
  eBRS_LIVE_DATA_NOTSUPPORT   		= 1,	/* Live data was not supported*/
  eBRS_LIVE_DATA_OK	        		= 2,	/* Live data was supported and get OK*/
  
  eBRS_LIVE_DATA_MAX				= 0xFF
} enumBRS_LiveData_Status;


typedef enum _enumBRS_GetInfoUnit
{
    eBAT_RESET_SERVICE_GET_NONE					=	0,
	
    eBAT_RESET_SERVICE_GET_SUB_FUNCTION    		=   1,
    eBAT_RESET_SERVICE_GET_SUPPORT_REQ1   		=   2,
    eBAT_RESET_SERVICE_GET_COMMAND_RESET      	=   3,
    eBAT_RESET_SERVICE_GET_LIVEDATA      		=   4,
	eBAT_RESET_SERVICE_GET_DESCRIPTION_TEXT 	=   5,
    eBAT_RESET_SERVICE_GET_SUCCESS_TEXT  		=   6,
    eBAT_RESET_SERVICE_GET_FAILURE_TEXT			=   7,
    
    eBAT_RESET_SERVICE_GET_MAX                  =   0XFF,
	
} enumBRS_GetInfoUnit;

// =====================================================================================================



#endif
