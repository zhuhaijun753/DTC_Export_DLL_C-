#ifndef __OIL_RESET_ENUMERATION_H__
#define __OIL_RESET_ENUMERATION_H__

#include <PlatFormType.h>
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include <YMME_Structure.h>
#include <string.h>
#include <enums.h>
#include <1_OBD_API\NWSCAN_APP\LIB\SYS_Utility.h>

/*enum Navigation*/
typedef enum __enumNavigationStatus
{
	eNAVIGATION_NONE	=	0,
	
	eNAVIGATION_YES		=	1,/*vechile has Navigation*/
	eNAVIGATION_NO		=	2,/*vehicle doen't have navigation*/
	
	eNAVIGATION_MAX		=	0xFF,
}enumNavigationStatus;


/*enumeration status - status to respond to UI*/
typedef enum __enumOilResetStatus
{
	eOIL_RESET_NONE                 = 0,
    
	eOIL_RESET_NORMAL               = 1, /*function is ok*/
	eOIL_RESET_ERROR_VECU           = 2,/*error link vehicle without VECU*/
	eOIL_RESET_ERROR_VBUS           = 3,/*Error or No Error depend on user define*/
	eOIL_RESET_USER_BREAK           = 4,/*Depending on user define*/
	eOIL_RESET_ERROR_DATA           = 5,/*data not correct*/
	eOIL_RESET_ERROR_TIMEOUT        = 6,/*time out getting data*/
	eOIL_RESET_ERROR_OVER_FLOW      = 7,/*supported, buffer is over flow*/
	eOIL_RESET_NOT_SUPPORT          = 8,/*not supported*/
	    
	eOIL_RESET_MAX         = 0xFF,
}enumOilResetStatus;

#pragma pack(1)
typedef struct _structOilResetProcedureYMME
{
  enumMake                 eMake;
  uint8                    eYear;
  enumModel                eModel;
  enumTrim		   eTrim;
  enumEngine               eEngine;
  enumBodyCode             eBodyCode;
  enumNavigationStatus     eNavigateStatus;
  enumSystem	           eSystem;
  enumSubSystem            eSubSystem;
  enumbool                 blIs_Service_Supported;
  uint16                   sProcedureType_ID;
  uint16                   sMessage_ID;
} structOilResetProcedureYMME;
#pragma pack()

#pragma pack(1)
typedef struct _structOilResetProcedureInfo
{
    uint16         sProcedure_ID;
    uint32         iStartAddr;
    uint16         sLength;
} structOilResetProcedureInfo;
#pragma pack()

#pragma pack(1)
typedef struct _structYMME_OilReset
{
  enumMake           eMake;
  uint8           eYear;
  enumModel          eModel;
  enumTrim           eTrim;
  enumEngine         eEngine;
  enumBodyCode           eBodyCode;
//  enumNavigationStatus  eNavigateStatus;
} structYMME_OilReset;
#pragma pack()

#pragma pack(1)
typedef struct _structOilResetService
{
  uint16	sMessage_ID;
  uint16	sECU_Varient;
  uint16	sRx;
  uint16	sTx;
  uint8	        bStep;
  uint8         bNumStep;
  uint8	        bRepeatStep;
  uint8	        bRepeatTime;
  uint16	enumCMD_Req_Reset;
  enumbool      blSpecialCMD;
} structOilResetService;
#pragma pack()

#pragma pack(1)
typedef struct _structOilResetServiceKey
{
  uint16	sMessage_ID;
  uint16	sECU_Varient;
  uint16	sRx;
  uint16	sTx;
  uint8	        bStep;
} structOilResetServiceKey;
#pragma pack()

#endif
