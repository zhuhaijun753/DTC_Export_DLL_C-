/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : DTCDefinition.h
Description     : 
Engineer        : LapDang - 09-Sep 2014
History         :
|-Version     |   Date       |  Engineer   |        Note                     -|
V1.0.0         09 Sep 2014     Lap Dang        initialize
===============================================================================
******************************************************************************/
#ifndef _DTC_DEFINITION_H
#define _DTC_DEFINITION_H
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include <DTC_APP/DTC_Adapter_App.h>

#define SIZE_MAINCODE 15
#define BYTE_RESERVE 9

#pragma pack(1)
typedef struct _structListDef
{
  enumbool eReadOBD2Lib;
  uint8 Len[10];
  uint8 bNumItem;
}structListDef;
#pragma pack()

#pragma pack(1)
#define MAX_LIST_ADDRESS_DTC   10
typedef struct _structListAddressDTC
{
    uint8  bNoItem;
    enumbool IsFoundDTC;
    enumbool IsFoundDTCMainDef;
    enumbool IsHasDTCSub;
    enumbool IsFoundDTCSubID;
    enumbool IsFoundDTCSubDef;   
    uint32 ListItem[MAX_LIST_ADDRESS_DTC];
    structListDef strtListDef;
    
}structListAddressDTC;

typedef struct _structDTCYmme
{
    uint8  bYear;
    uint16 sManufacturer;
    uint16 sModel;
    uint16 sOption1;
    uint32 iOption2;
    uint16 sOption3;
    uint16 sOption4;
    uint16 sSystem;
    uint16 sSubSystem;
    uint16 sProtocol;
} structDTCYmme;
#pragma pack()

#pragma pack(1)
typedef struct _structStringCode
{
    uint8 bStringMainCode[SIZE_MAINCODE];
    uint8 bStringSubCode[3];
} structStringCode;
#pragma pack()

#pragma pack(1)
typedef struct _structKeyInfo         //Key_Info
{
    uint8  bYear;
    uint16 sManufacturer;
    uint8 bMainDTCString[SIZE_MAINCODE]; 
    uint16 sModel;
    uint16 sOption1;
    uint32 sOption2;
    uint16 sOption3;
    uint16 sOption4;
    uint16 sSystem;
    uint16 sSubSystem;
    uint16 bProtocol; 
} structKeyInfo;
#pragma pack()


#pragma pack(1)
#define MAX_NUM_BYTE_DTC_YMME_CONFIG	3
typedef struct _structDTCYmmeUsing
{
    uint16 sVehicle;
    union
    {
       struct
       {  
        enumbool use_sManufacturer:1;
        enumbool use_sModel:1;
        enumbool bit0_2:1;
        enumbool use_sSystem:1;

        enumbool use_sSubSystem:1;
        enumbool use_sProtocol:1;
        enumbool bit0_6:1;
        enumbool bit0_7:1;

        enumMFRField eOption1;
        enumMFRField eOption2;
       
       };
       uint8 bData[MAX_NUM_BYTE_DTC_YMME_CONFIG];
    };
}structDTCYmmeUsing;
#pragma pack()

#pragma pack(1)
typedef struct _structHeader_DTCbin     //Save header dtc.bin
{
    uint32 NumberLine;
    uint8 BaseSize;
    uint8 KeySize;
    uint8 EnableEncrypt;
    uint8 Reserve[BYTE_RESERVE];   
} structHeader_DTCbin;
#pragma pack()

#pragma pack(1)
typedef struct _structAddress_DTC      // Out Address DTC_Definition     
{
  uint32  iMainAddress;   
  uint8   bGroupSystem;
  uint32  iSubAddress;   // For Mercedes
} structAddress_DTC;
#pragma pack()


#pragma pack(1)
typedef struct _structMappingAddress_DTC      // Out Mapping Address DTC_Definition     
{
  uint32  iMappingAddr;
  uint16  sLen; 
} structMappingAddress_DTC;
#pragma pack()

#pragma pack(1)
typedef struct _structMercedes_DTC      // Out Mapping Address DTC_Definition
{
  uint8 bMainDTCString[SIZE_MAINCODE];
  structAddress_DTC strtAddress_DTC;
} structMercedes_DTC;
#pragma pack()

#pragma pack(1)
typedef struct _structSeverity
{
    uint32 iAddress;
    uint8 StrDTC_Code[SIZE_MAINCODE];
    uint8 bSeverity;
} structSeverity;
#pragma pack()

#pragma pack(1)
typedef struct _structDtcInfoPath
{
  uint16 sID;
  uint8 *pString;
  uint32 (*gf_Vehicle_Adapter_DTC_GetDef)(structMFRVinProfile * p_strtMFRVinProfile,
                                          structOemProfile *p_strtOemProfile,
                                          enumOBDLanguage eMemLanguage,
                                          structListDTCType *pstrtListDTCType,
                                          void *pDef,
                                          uint32 iDefSize,
                                          structListAddressDTC* pstrtListAddressDTC);
  enumbool IsUseGenericExt;
} structDtcInfoPath;
#pragma pack()

#define MAX_LEN_DEF_PARSE	20
#pragma pack(1)
typedef struct _structDTCString
{
	uint8 strDefMain[MAX_LEN_DEF_PARSE];
	uint8 strDefSub[MAX_LEN_DEF_PARSE];
}structDTCString;
#pragma pack()



#endif
