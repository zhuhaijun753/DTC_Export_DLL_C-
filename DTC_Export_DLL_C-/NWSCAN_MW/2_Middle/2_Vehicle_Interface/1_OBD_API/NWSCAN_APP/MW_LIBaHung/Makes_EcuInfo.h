/*******************************************************************************
================================================================================
                              Lap Dang Dev
 * Filename: Makes_EcuInfo.h
 * Description:
 * Layer:
 * Accessibility:
 * Created on: Oct 5, 2015
 *      Author: Lap Dang
================================================================================
*******************************************************************************/

#ifndef MAKES_ECUINFO_H_
#define MAKES_ECUINFO_H_
#include "OBD_API\LIB\PlatFormType.h"
#include "OBD_API\LIB\SYS_Utility.h"
#include "OBD_API\LIB\VBI_Utility.h"
#include "OBD_API\LIB\VDM_Adapter.h"
#include "OBD_API\LIB\VBI_Default_App.h"
#include "OBD_API\LIB\VCI_App.h"
#include "nwscan_enumerations.h"

#pragma pack(1)

#define MAX_LIST_ECU_RENAULT   4
#define MAX_ECU_SUPPORTED   36
#define MAX_HONDA_LEN_STR_ECU_ID   30
typedef struct _structOemInfo_Honda
{
        uint8 			bECUIDType;
        enumECUTypes 	        eECUTYpe;
        uint8 			strECUID[MAX_HONDA_LEN_STR_ECU_ID];
        enumbool 		IsShowItem; //use for body sub system
        uint8 			Resever[OEM_INFO_LEN-
								(1+2+MAX_HONDA_LEN_STR_ECU_ID + 1+4+1+1 )];
        uint32 iMappingAddr;
        enumParsertype_Honda eParserType;
        uint8 bStatus;
} structOemInfo_Honda;
#pragma pack()

#pragma pack(1)
typedef struct _structOemInfo_Nissan
{
	enumProgramIds_Nissan eProgID;
        uint8 bECUPartID;
        uint8 Reserve[OEM_INFO_LEN - 4];
        uint8 bStatus;
} structOemInfo_Nissan;
#pragma pack()

#pragma pack(1)
typedef struct _structOemInfo_Renault
{
	uint8 bVdiag;
        uint8 bProgramId;
        uint16 eDTCTable;
        uint16  sDTCLookup;
        uint16  sEcuId;
        uint16  sEcuId_Extra[MAX_LIST_ECU_RENAULT];
        uint8 Reserve[OEM_INFO_LEN - 17];
        uint8 bStatus;
} structOemInfo_Renault;
#pragma pack()

#pragma pack(1)
#define MB_ID_SIZE          5
#define MB_HW_SIZE          3
#define MB_SW_SIZE          3
#define MB_DIAG_SIZE        3
#define MB_SUPPLIER_SIZE    1

typedef struct _structMercedesInfo
{

        uint8 strEcuId[MB_ID_SIZE];

        uint8 strDiagVersion[MB_DIAG_SIZE];

        uint8 strHWVersion[MB_HW_SIZE]; //Week Year

        uint8 strSWVersion[MB_SW_SIZE]; //Week Year

        enumMercedes_Suppliers eEcuSupplier;

        enumMercedes_Qualifiers eQualifier;

        uint32 iModelTypes;
        union
		{
        	uint8 bStatus;
        	struct
			{
        		enumbool blValidECUData:1;
        		enumbool blFoundDB:1;
        		enumbool blIsFoundBaseVariant:1;
			}strtStatus;
		};

        uint8 bReserve[OEM_INFO_LEN
                - (MB_ID_SIZE +MB_DIAG_SIZE+ MB_HW_SIZE + MB_SW_SIZE  + 1+2+4+1+1)];
        uint8 bValidCode;
} structOemInfo_Mercedes;
#pragma pack()


#pragma pack(1)
#define CHRYSLER_PARTNUMBER_LEN	11
typedef struct _structOemInfo_Chrysler
{
        uint8 bVariant;
        uint8 bVersion;
        uint8 strPartnumber[CHRYSLER_PARTNUMBER_LEN];/*byte0=Len + data [1->10]*/
        uint16 sChryslerIsoCode;
        uint8 bReserve[OEM_INFO_LEN - 3-CHRYSLER_PARTNUMBER_LEN];
        uint8 bStatus;
} structOemInfo_Chrysler;
#pragma pack()

#pragma pack(1)
typedef struct _structDTCVariant
{
        enumMessageIds eMsgID;
        enumVariants_BMW eVariant;
        enumCommands eCMDReadNumDTC;
        uint8 ReadNumberDtcPos;
        enumCommandList eReadDtcs;
        enumBmwReadDtcTypes eReadType;
        uint8 bOffset;
        uint8 bDtcFrame;
        uint8 bDtcFormat;
        uint8 bDTcPos;
        enumLookupTables eLUT;
        enumDTCType eDtcDispType;
        enumCommandList eCMDErases;
        enumBmwEraseDtcTypes eEraseType;
        enumCommands_BMW eCMDExit;
        enumBmwParserDtcTypes eParserDtcType;

} structDTCVariant;

typedef struct _structOemInfo_Bmw
{
        enumbool IsUsedExtendDB;
        structDTCVariant strtDTCVarProfile;
        uint8 reserve[OEM_INFO_LEN - (sizeof(structDTCVariant) + 2)];
        enumValidCode eStatus;
} structOemInfo_Bmw;
#pragma pack()

#pragma pack(1)
#define VOLVO_ECU_ID_LEN	11
typedef struct _structVolvoEcuID
{
        uint8 ECUID_Parser[VOLVO_ECU_ID_LEN];
        uint16 sECUID_Value;
        uint8 bReserve[OEM_INFO_LEN - (VOLVO_ECU_ID_LEN+2+1)];
        uint8 bStatus;
} structOemInfo_Volvo;
#pragma pack()

#pragma pack(1)
typedef struct _structOemInfo_Toyota
{
	enumECUTypes eType;
	uint8 bReserve[OEM_INFO_LEN-3];
	enumValidCode eStatus;
}structOemInfo_Toyota;
#pragma pack()

#pragma pack(1)
#define MAX_SIZE_VAG_NUMBER	12
#define MAX_SIZE_VAG_WORKSHOP_CODE	7
typedef struct _structOemInfo_VAG
{
        enumEcuIds eECUID;
        uint16 sSoftCode;
        uint16 sECUWorkShopCode;
        uint8 bECUWorkShop[MAX_SIZE_VAG_WORKSHOP_CODE];
        uint8 bChryslerVariant;
        uint8 bChryslerVersion;
        uint8 bVAGNumber[MAX_SIZE_VAG_NUMBER];
        enumEcuIds eECUID_Default;
        uint8 bReserve[OEM_INFO_LEN -
					   	   (2+2+2+MAX_SIZE_VAG_WORKSHOP_CODE+1+1+1+MAX_SIZE_VAG_NUMBER+2)];
        uint8 bStatus;
} structOemInfo_VAG;
#pragma pack()

#pragma pack(1)
typedef struct _structOemInfo_Mitsubishi
{
        uint16 sSCC;
        uint8 bReserve[OEM_INFO_LEN - 3];
        uint8 bStatus;
} structOemInfo_Mitsubishi;
#pragma pack()
#endif /* MAKES_ECUINFO_H_ */
