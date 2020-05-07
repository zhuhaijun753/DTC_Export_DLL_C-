#ifndef __BATTERY_RESET_STRUCTURE_H__
#define __BATTERY_RESET_STRUCTURE_H__

#include <PlatFormType.h>
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>

#include "enums.h"


// =====================================================================================================
//	 								BATTERY RESET PROCEDURE
// =====================================================================================================

#pragma pack(1)
typedef struct _structBatteryResetProcedure
{
    enumMake         eMake;
    enumYear         eYear;
    enumModel        eModel;
    enumTrim         eTrim;
    enumEngine       eEngine;
    
    uint16           sGeneralInfo_ID;
    uint16           sBeforeDisconnection_ID;
    uint16           sBeforeConnection_ID;
    uint16           sAfterConnection_ID;
    uint16           sService_ID;
} structBatteryResetProcedure;
#pragma pack()

typedef struct _structBRP_CheckSupport
{
  enumMake         eMake;
  enumYear         eYear;
  enumModel        eModel;
  enumTrim         eTrim;
  enumEngine       eEngine;
} structBRP_CheckSupport;

#pragma pack(1)
typedef struct _structSearchText
{
	uint16	sSearch_ID;
	
	uint32  iStartAddress;
	uint16	sLength;
} structSearchText;
#pragma pack()


// =====================================================================================================
//	 								BATTERY RESET SERVICE
// =====================================================================================================

#pragma pack(1)
typedef struct _structText
{
	uint32  iStartAddress;
	uint16	sLength;
} structText;
#pragma pack()

#pragma pack(1)
typedef struct _structBatteryResetService
{
	uint16           	sService_ID;	
	enumProtocol 		eProtocol;
    enumDLC             eCanH_Pin;          // 2 bytes
    enumDLC             eCanL_Pin;          // 2 bytes
	enumVariant 		eVariant;
	
    structText 		    strtSubFunction;	
	enumCommand 		eSupportRequest;					
	uint16 				sCommand_ID;
	uint16 				sLiveData_ID1;
	uint16 				sLiveData_ID2;
	uint16 				sDescriptionText_ID;
	uint16 				sSuccessText_ID;
	uint16 				sFailureText_ID;
} structBatteryResetService;
#pragma pack()


#pragma pack(1)
typedef struct _structBRS_Livedata
{
	uint16 				sLiveData_ID;
	
	structText 		    strtLiveData_Name;	
	uint16        		sSID_ID;	
	uint16 		        sPID_ID;
	uint8				bBytePos;
	uint8				bByteSize;
	enumFormula			eFormula;        // 2bytes
	uint8				bCoefficient_A;
	uint8				bCoefficient_B;
} structBRS_Livedata;
#pragma pack()


typedef struct _structBRS_CheckSupport
{
    uint16           	sService_ID;	
	enumProtocol 		eProtocol;
    enumDLC             eCanH_Pin;          // 2 bytes
    enumDLC             eCanL_Pin;          // 2 bytes
	enumVariant 		eVariant;
} structBRS_CheckSupport;


#endif
