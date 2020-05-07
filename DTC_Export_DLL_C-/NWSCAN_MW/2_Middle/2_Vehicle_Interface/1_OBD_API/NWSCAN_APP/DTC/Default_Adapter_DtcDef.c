/*
* Default_Adapter_DtcDef.c
*
*  Created on: Jul 29, 2015
*      Author: Lap Dang
*/
#define _DTC_DEF_DEFAULT_CONFIG_C_
#include "NWSCAN_APP\LIB\PlatFormType.h"
#include "NWSCAN_APP\DTC\DTC_Config.h"
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\enums.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMMESelection.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMME_Structure.h>
#include <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Structure.h>
#include "NWSCAN_APP\MW_LIB\Makes_Adapter_App.h"
#include <2_Middle\0_Middle_Utilities\AES\aes256.h>
#include "DTCDefinition.h"
#include "DTCUtilities.h"
#include <stdlib.h>
#include "DTCDefinitionConfig.h"

extern const structDtcInfoPath ROM_dtcinfo_inngrp_map[];

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __DTC_YmmeSearch
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static void __DTC_YmmeSearch(structMFRVinProfile * p_strtMFRVinProfile,
                             structOemProfile *p_strtOemProfile, structListDTCType *pstrtListDTCType,
                             structKeyInfo *p_strtKeyInfo)
{
  uint16 sIdx = 0;
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  while (strtDTCYmmeUsing[sIdx].sVehicle != emanufacturer_UNKNOWN)
  {
    if (strtDTCYmmeUsing[sIdx].sVehicle
        == p_strtMFRVinProfile->eManufacturer)
    {
      if (strtDTCYmmeUsing[sIdx].use_sManufacturer == eTRUE)
      {
        p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
      }
      if (strtDTCYmmeUsing[sIdx].use_sModel == eTRUE)
      {
        p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
      }
      if (strtDTCYmmeUsing[sIdx].use_sSystem == eTRUE)
      {
        p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
      }
      if (strtDTCYmmeUsing[sIdx].use_sSubSystem == eTRUE)
      {
        p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
      }
      if (strtDTCYmmeUsing[sIdx].use_sProtocol == eTRUE)
      {
        p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
      }
      if (strtDTCYmmeUsing[sIdx].use_sProtocol == eTRUE)
      {
        p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
      }
      switch (strtDTCYmmeUsing[sIdx].eOption1)
      {
      case eMFR_FIELD_Trim:
        p_strtKeyInfo->sOption1 = p_strtMFRVinProfile->eTrim;
        break;
        
      case eMFR_FIELD_Transmission:
        p_strtKeyInfo->sOption1 = p_strtMFRVinProfile->eTransmission;
        break;
        
      case eMFR_FIELD_Bodycode:
        p_strtKeyInfo->sOption1 = p_strtMFRVinProfile->eBodyCode;
        break;
        
      case eMFR_FIELD_Engine:
        p_strtKeyInfo->sOption1 = p_strtMFRVinProfile->eEngine;
        break;
      default:
        break;
      }
      
      switch (strtDTCYmmeUsing[sIdx].eOption2)
      {
      case eMFR_FIELD_Trim:
        p_strtKeyInfo->sOption2 = p_strtMFRVinProfile->eTrim;
        break;
        
      case eMFR_FIELD_Transmission:
        p_strtKeyInfo->sOption2 = p_strtMFRVinProfile->eTransmission;
        break;
        
      case eMFR_FIELD_Bodycode:
        p_strtKeyInfo->sOption2 = p_strtMFRVinProfile->eBodyCode;
        break;
        
      case eMFR_FIELD_Engine:
        p_strtKeyInfo->sOption2 = p_strtMFRVinProfile->eEngine;
        break;
      default:
        break;
      }
      
      /*
      *
      enumTrim             eTrim;              //2 bytes
      enumBodyCode         eBodyCode;          //2 bytes
      enumEngine           eEngine;            //2 bytes
      enumTransmission     eTransmission;       //2 bytes
      
      enumMakeGroup        eMakeGroup;          //1 byte
      
      * */
    }
    sIdx++;
  }
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __DtcGetMappingString
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static void *__DtcGetMappingString(uint16 sID, const structDtcInfoPath*pData)
{
  for (uint8 i = 0; pData[i].pString != Null; i++)
  {
    if (pData[i].sID == sID)
      return pData[i].pString;
  }
  return Null;
}

#pragma pack(1)
typedef struct _structMakeManufacture
{
enumMFRMake eMake;
  enumMFRManufacturer eManufacture;
} structMakeManufacture;
#pragma pack()
  
const structMakeManufacture strtMakeManufacture[] = { { emake_Ford,
emanufacturer_Ford }, { emake_Lincoln, emanufacturer_Ford }, {
emake_Mercury, emanufacturer_Ford }, { emake_Toyota,
emanufacturer_Toyota }, { emake_Scion, emanufacturer_Toyota }, {
  emake_Lexus, emanufacturer_Toyota }, { emake_Buick, emanufacturer_GM },
{ emake_Cadillac, emanufacturer_GM }, { emake_AM_____General,
  emanufacturer_GM }, { emake_Chevrolet, emanufacturer_GM }, {
  emake_Daewoo, emanufacturer_GM },
{ emake_Geo, emanufacturer_GM }, { emake_GMC, emanufacturer_GM }, {
    emake_Hummer, emanufacturer_GM }, { emake_Oldsmobile,
  emanufacturer_GM }, { emake_Pontiac, emanufacturer_GM }, {
  emake_Saab, emanufacturer_GM },
    { emake_Saturn, emanufacturer_GM }, { emake_Mercedes_Benz,
    emanufacturer_Mercedes_Benz }, { emake_Chrysler,
  emanufacturer_Chrysler },
    { emake_Dodge, emanufacturer_Chrysler }, { emake_Eagle,
    emanufacturer_Chrysler },
  { emake_Jeep, emanufacturer_Chrysler }, { emake_Plymouth,
    emanufacturer_Chrysler }, { emake_Ram, emanufacturer_Chrysler },
    { emake_SRT, emanufacturer_Chrysler }, { emake_Honda,
  emanufacturer_Honda }, { emake_Acura, emanufacturer_Honda }, {
    emake_Audi, emanufacturer_Volkswagen }, { emake_Volkswagen,
    emanufacturer_Volkswagen }, { emake_BMW, emanufacturer_BMW }, {
    emake_Mini, emanufacturer_BMW }, { emake_Mazda,
    emanufacturer_Mazda }, { emake_Hyundai, emanufacturer_Hyundai },
      { emake_Kia, emanufacturer_Hyundai }, { emake_Nissan,
    emanufacturer_Nissan },
    { emake_Infiniti, emanufacturer_Nissan }, { emake_Volvo,
      emanufacturer_Volvo }, { emake_Suzuki, emanufacturer_Suzuki }, {
    emake_Porsche, emanufacturer_Porsche }, { emake_Subaru,
    emanufacturer_Subaru }, { emake_Mitsubishi,
        emanufacturer_Mitsubishi },
    { emake_Isuzu, emanufacturer_Isuzu }, { emake_UNKNOWN,
    emanufacturer_UNKNOWN } };
        /*------------------------------------------------------------------------------
    *Engineer     : Lap Dang
*Function name: __Make_Mapping_Manufacture
*Input        :

*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static enumManufacturer __Make_Mapping_Manufacture(enumMake eMake)
{
  uint16 sIdxMapping = 0;
  while (strtMakeManufacture[sIdxMapping].eMake != emake_UNKNOWN)
  {
    
    if (strtMakeManufacture[sIdxMapping].eMake == eMake)
      return strtMakeManufacture[sIdxMapping].eManufacture;
    sIdxMapping++;
  }
  return emanufacturer_MAX;
}
#pragma pack(1)
typedef struct _structMappingSystem
{
  enumManufacturer eManufacture;
  uint8 bSystemOBDII;
  enumSystem eSystem;
} structMappingSystem;
#pragma pack()
#define MAPPING_SYSTEM_OBD2(man)  {emanufacturer_##man,OBD2_ECM,esystem_ECM_##man},\
{emanufacturer_##man,OBD2_TCM,esystem_TCM_##man}

const structMappingSystem strtMappingSystem[] = {
  //MAPPING_SYSTEM_OBD2(BMW),
  MAPPING_SYSTEM_OBD2(Chrysler),
  MAPPING_SYSTEM_OBD2(Ford),
  //MAPPING_SYSTEM_OBD2(GM),
  MAPPING_SYSTEM_OBD2(Honda),
  //MAPPING_SYSTEM_OBD2(Hyundai),
  //MAPPING_SYSTEM_OBD2(Mazda),
  //MAPPING_SYSTEM_OBD2(Mercedes_Benz),
  //MAPPING_SYSTEM_OBD2(Nissan),
  //MAPPING_SYSTEM_OBD2(Toyota),
  //MAPPING_SYSTEM_OBD2(Volkswagen),
  //MAPPING_SYSTEM_OBD2(Volvo),
  //MAPPING_SYSTEM_OBD2(Isuzu),
  //MAPPING_SYSTEM_OBD2(Mitsubishi),
  MAPPING_SYSTEM_OBD2(Subaru),
  //MAPPING_SYSTEM_OBD2(Suzuki),
  //MAPPING_SYSTEM_OBD2(Porsche),
  //MAPPING_SYSTEM_OBD2(Others),
  //MAPPING_SYSTEM_OBD2(MAX),
  //MAPPING_SYSTEM_OBD2(Generic),
  //MAPPING_SYSTEM_OBD2(Jaguar Land Rover),
  //MAPPING_SYSTEM_OBD2(BYD),
  //MAPPING_SYSTEM_OBD2(Chery),
  //MAPPING_SYSTEM_OBD2(Daihatsu),
  //MAPPING_SYSTEM_OBD2(Ssangyong),
  //MAPPING_SYSTEM_OBD2(Rover Group),
  //MAPPING_SYSTEM_OBD2(SAIC),
  //MAPPING_SYSTEM_OBD2(Fiat),
  //MAPPING_SYSTEM_OBD2(Peugeot),
  //MAPPING_SYSTEM_OBD2(Daewoo),
  //MAPPING_SYSTEM_OBD2(Lifan),
  //MAPPING_SYSTEM_OBD2(Faw),
  //MAPPING_SYSTEM_OBD2(MG),
  //MAPPING_SYSTEM_OBD2(Opel),
  //MAPPING_SYSTEM_OBD2(Renault),
  //MAPPING_SYSTEM_OBD2(Mercedes),
  //MAPPING_SYSTEM_OBD2(),
};
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_GetSystem
*Input        : enumManufacturer eManufacture
enumSystem System
*Output       : enumSystem
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
enumSystem gf_GetSystem(enumManufacturer eManufacture, enumSystem System)
{
  uint16 sIdxMapping = 0;
  while (strtMappingSystem[sIdxMapping].eManufacture != emanufacturer_UNKNOWN)
  {
    if (strtMappingSystem[sIdxMapping].eManufacture == eManufacture)
    {
      if (strtMappingSystem[sIdxMapping].bSystemOBDII == System)
        return strtMappingSystem[sIdxMapping].eSystem;
    }
    sIdxMapping++;
  }
  return System;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __GetSystem
*Input        : enumManufacturer eManufacture
enumSystem System
*Output       : enumSystem
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static structListAddressDTC * __DTC_LIB_FindListID(enumInnovaGroups eInnovaGroup, structKeyInfo *p_strtKeyInfo,
                                                   structListAddressDTC* pstrtListAddressDTC, enumbool IsMainDef)
{
  void *PathPatern = null;
  char bPath_dtc[50];
  if (pstrtListAddressDTC == Null)
    return null;
  pstrtListAddressDTC->bNoItem = 0;
  uint8 bNumFolderVersion;
  uint8* group;
  
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  if (group == null)
    return Null;
  if (eInnovaGroup == GROUP_N_A)
  {
    bNumFolderVersion = VDM_NWDTC_GET_LIST_VERSION();
    if (IsMainDef)
      PathPatern = PATH_ALL_MAINDTC_BIN;
    else
      PathPatern = PATH_ALL_SUBDTC_BIN;
  }
  else
  {
    bNumFolderVersion = VDM_DTC_GET_LIST_VERSION();
    if (IsMainDef)
      PathPatern = PATH_MAINDTC_BIN;
    else
      PathPatern = PATH_SUBDTC_BIN;
  }
  for (uint8 bIdxVersion = 0; bIdxVersion < bNumFolderVersion; bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    
    sprintf(bPath_dtc, PathPatern, group);
    
    if (gf_GetListAddressDTC(pstrtListAddressDTC, p_strtKeyInfo, bPath_dtc,
                             eTRUE, IsMainDef) > 0)
    {
      break;
    }
  }
  if (pstrtListAddressDTC->bNoItem)
    return pstrtListAddressDTC;
  else
    return Null;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_OBDII_GetDef
*Input        : structMFRVinProfile * p_strtMFRVinProfile,
structOemProfile *p_strtOemProfile,
enumOBDLanguage      eMemLanguage,
void *pStrDispDtc,
uint32 sDefSize

*Output       : void *pDef
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
#if _MSC_VER
__declspec(dllexport) uint32 __stdcall  gf_VDM_DTC_OBDII_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                                                structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                                                structListDTCType *pstrtListDTCType, void *pDef, uint32 sDefSize)
#else
uint32  gf_VDM_DTC_OBDII_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                structListDTCType *pstrtListDTCType, void *pDef, uint32 sDefSize)
#endif
{
  uint32 iLenDef = 0;
  structListAddressDTC* pstrtListAddressDTC;
  structListAddressDTC strtListAddressDTC;
  strtListAddressDTC.strtListDef.eReadOBD2Lib=0;
  uint8 bNumLoop = 2;
  //enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  enumManufacturer eManufactureBK = p_strtMFRVinProfile->eManufacturer;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  // eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  enumSystem eListSystem[2];
  enumSystem eListProtocol[2];
  enumManufacturer eListManufacture[2];
  if (eManufacture == emanufacturer_UNKNOWN)
    eManufacture = emanufacturer_MAX;
  structKeyInfo strtKeyInfo;
  if (pDef == null)
    return 0;
  else
    ((uint8*) pDef)[0] = 0;
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString,
         strlen(pstrtListDTCType->bDTCString));
  strtKeyInfo.sManufacturer = eManufacture;
  eListProtocol[0] = p_strtOemProfile->Protocol;
  eListProtocol[1] = PROTOCOL_MAX;
  eListSystem[0] = p_strtOemProfile->sSystem;
  eListSystem[1] = eNWSCAN_SYSTEM_MAX;
  if ((p_strtOemProfile->Protocol == PROTOCOL_ISO9141)
      && (p_strtMFRVinProfile->eManufacturer == emanufacturer_GM))
  {
    eListProtocol[0] = PROTOCOL_KW2000;   // For make GM
  }
  // GetSystem
  eListSystem[0] = gf_GetSystem(p_strtMFRVinProfile->eManufacturer,
                                p_strtOemProfile->sSystem);
  
  eListManufacture[0] = p_strtMFRVinProfile->eManufacturer;
  eListManufacture[1] = eNWSCAN_MANUFACTURE_MAX;
  if (p_strtMFRVinProfile->eManufacturer == emanufacturer_UNKNOWN)
  {
    bNumLoop = 1;
    eListSystem[0] = eNWSCAN_SYSTEM_MAX;
    eListManufacture[0] = eNWSCAN_MANUFACTURE_MAX;
    eListProtocol[0] = PROTOCOL_MAX;
    strtKeyInfo.sManufacturer = eNWSCAN_MANUFACTURE_MAX;
  }
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;  //Default language
  for (uint8 bIdxManufacture = 0; bIdxManufacture < bNumLoop; bIdxManufacture++)
  {
    strtKeyInfo.sModel = 0xFFFF;
    if (eListManufacture[bIdxManufacture]
        == emanufacturer_Volkswagen)
    {
      if (p_strtMFRVinProfile->eModel == emodel_Routan_Volkswagen)
        strtKeyInfo.sModel = emodel_Routan_Volkswagen;
    }
    else if (eListManufacture[bIdxManufacture] == emanufacturer_GM)
    {
      if (p_strtMFRVinProfile->eModel == emodel_Vibe_GM)
      {
        strtKeyInfo.sModel = emodel_Vibe_GM;
      }
    }
    
    if ((eListManufacture[bIdxManufacture] == emanufacturer_Hyundai)||
        (eListManufacture[bIdxManufacture]==emanufacturer_Jaguar_____Land_____Rover))
      strtKeyInfo.sManufacturer = p_strtMFRVinProfile->eMake;
    else
      strtKeyInfo.sManufacturer = eListManufacture[bIdxManufacture];
    eManufacture = eListManufacture[bIdxManufacture];
    p_strtMFRVinProfile->eManufacturer = eManufacture;
    for (uint8 bIdxSystem = 0; bIdxSystem < bNumLoop; bIdxSystem++)
    {
      strtKeyInfo.sSystem = eListSystem[bIdxSystem];
      for (uint8 bIdxProtocol = 0; bIdxProtocol < bNumLoop; bIdxProtocol++)
      {
        strtKeyInfo.bProtocol = eListProtocol[bIdxProtocol];
        
        pstrtListAddressDTC = gf_DTC_FindListID(GROUP_OBDII,
                                                &strtKeyInfo, &strtListAddressDTC, eTRUE);
        if (pstrtListAddressDTC != Null)
        {
          
          iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC,
                                          GROUP_OBDII, eMemLanguage, pDef, sDefSize, eTRUE);
          p_strtMFRVinProfile->eManufacturer = eManufactureBK;
          return iLenDef;
        }
      }
    }
  }
  
  p_strtMFRVinProfile->eManufacturer = eManufactureBK;
  return iLenDef;
}
//TODO : port to buildable for app project , need to clean after update new lib UI

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_Default_Adapter_DTC_GetDef
*Input        : structMFRVinProfile * p_strtMFRVinProfile,
structOemProfile *p_strtOemProfile,
enumOBDLanguage      eMemLanguage,
void *pStrDispDtc,
uint32 sDefSize
*Output       : void *pDef,
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
uint32 gf_Default_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                     structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                     structListDTCType *pstrtListDTCType, void *pDef, uint32 iDefSize,
                                     structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  uint32 iLenDef = 0;
  enumInnovagroup *pListInnGroup;
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;               //Default language
  if (pDef == null)
    return 0;
  else
    ((uint8*) pDef)[0] = 0;
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  if (p_strtOemProfile->bSelInnGroup == GROUP_OBDI)
  {
    strtKeyInfo.sManufacturer = eManufacture;
    strtKeyInfo.sSystem = p_strtOemProfile->sSystem;
  }
  else
  {
    __DTC_YmmeSearch(p_strtMFRVinProfile, p_strtOemProfile,
                     pstrtListDTCType, &strtKeyInfo);
  }
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString,
         strlen(pstrtListDTCType->bDTCString));
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, &strtKeyInfo,
                                            pstrtListAddrDTC, eTRUE);
    
    if (pstrtListAddressDTC != Null)
    {
      return gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                   eMemLanguage, pDef, iDefSize, eTRUE);
    }
    bIdxGroup++;
  }
  return iLenDef;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_Library_GetDef
*Input        : enumManufacturer  eManufacture,
enumOBDLanguage   eMemLanguage,
void *pStrDispDtc,
uint32 sDefSize
*Output       : void *pDef
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static uint32 gf_VDM_DTC_Library_GetDef(enumMake eMake,
                                        enumOBDLanguage eMemLanguage, void *pStrDispDtc, void *pDef,
                                        uint32 sDefSize, enumInnovaGroups eInnovaGroup,
                                        structListAddressDTC* pstrtListAddrDTC)
{
  enumInnovaGroups eListInnovaGroup[5];
  structListAddressDTC* pstrtListAddressDTC;
  uint8 bNumLoop = 2;
  uint32 iLenDef = 0;
  uint16 bYear = 0xFFFF;
  enumManufacturer eManufacture;
  eManufacture = __Make_Mapping_Manufacture(eMake);
  enumSystem eListManufacture[2];
#ifdef  _MSC_VER
  structMFRVinProfile *pstrtMFRVinProfile = VehicleData_YMMEProfile(bYear, eManufacture);
#else
  structMFRVinProfile *pstrtMFRVinProfile = VehicleData_YMMEProfile_Get();
#endif  
  if (pstrtMFRVinProfile == null)
    return 0;
  uint16 sBKStatus = pstrtMFRVinProfile->ValidStatus;
  uint16 sBKManufacture = pstrtMFRVinProfile->eManufacturer;
  pstrtMFRVinProfile->eManufacturer = eManufacture;
  pstrtMFRVinProfile->ValidStatus = VALID_CODE;
  
  eListManufacture[0] = eManufacture;
  eListManufacture[1] = eNWSCAN_MANUFACTURE_MAX;
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;
  structKeyInfo strtKeyInfo;
  
  if (pDef == null)
  {
    pstrtMFRVinProfile->eManufacturer = sBKManufacture;
    pstrtMFRVinProfile->ValidStatus = sBKStatus;
    return 0;
  }
  else
    ((uint8*) pDef)[0] = 0;
  if (eInnovaGroup!=GROUP_OBDI)
  {
    eListInnovaGroup[0] = GROUP_OBDII;
    eListInnovaGroup[1] = GROUP_ENH_PCM;
    eListInnovaGroup[2] = GROUP_ABS;
    eListInnovaGroup[3] = GROUP_SRS;  
    eListInnovaGroup[4] = DTC_GROUP_ALL;
  }
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pStrDispDtc, strlen(pStrDispDtc));
  
  for (uint8 bIdxMenufacture = 0; bIdxMenufacture < bNumLoop;bIdxMenufacture++)
  {
    eManufacture = eListManufacture[bIdxMenufacture];
    if (eListManufacture[bIdxMenufacture] == emanufacturer_Hyundai)
      strtKeyInfo.sManufacturer = eMake;
    else
      strtKeyInfo.sManufacturer = eListManufacture[bIdxMenufacture];    
    pstrtMFRVinProfile->eManufacturer = eListManufacture[bIdxMenufacture]; 
    for (uint8 i = 0; i < 5; i++)
    {
      if (eInnovaGroup!=GROUP_OBDI)
        eInnovaGroup = eListInnovaGroup[i];
      pstrtListAddressDTC = __DTC_LIB_FindListID(eInnovaGroup, &strtKeyInfo,
                                                 pstrtListAddrDTC, eTRUE);
      if (pstrtListAddressDTC != Null)
      {
        iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                        eMemLanguage, pDef, sDefSize, eTRUE);
        if (eInnovaGroup==GROUP_OBDI)
          break;
      }
        if (eInnovaGroup==GROUP_OBDI)
          break;
    }
  }
  if (pstrtListAddrDTC->strtListDef.eReadOBD2Lib==eTRUE)     
  {
      if (pstrtListAddrDTC->strtListDef.bNumItem == 1)
      {
          if (iLenDef > 3)
          {
              gf_Util_ShiftLeftBuff(pDef, iLenDef, 3);
              iLenDef -= 3; //remove \n      
          }
          else
          {
              iLenDef = 0;
          }
      }
      uint8* b_tempabc = (uint8*) pDef;
      b_tempabc[iLenDef-1] = 0;
      iLenDef--;
  }
  pstrtMFRVinProfile->eManufacturer = sBKManufacture;
  pstrtMFRVinProfile->ValidStatus = sBKStatus;
  return iLenDef;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_Library_GetDef_OBD2
*Input        : enumManufacturer  eManufacture,
enumOBDLanguage   eMemLanguage,
void *pStrDispDtc,
uint32 sDefSize
*Output       : void *pDef
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
#ifdef _MSC_VER
__declspec(dllexport) uint32 __stdcall  gf_VDM_DTC_Library_GetDef_OBD2(enumMake eMake,
                                                                       enumOBDLanguage eMemLanguage, void *pStrDispDtc, void *pDef,
                                                                       uint32 sDefSize)
#else
uint32 gf_VDM_DTC_Library_GetDef_OBD2(enumMake eMake,
                                      enumOBDLanguage eMemLanguage, 
                                      void *pStrDispDtc, 
                                      void *pDef,
                                      uint32 sDefSize)
#endif
{
  structListAddressDTC strtListAddressDTC;
  memset(&strtListAddressDTC, 0, sizeof(structListAddressDTC));
  strtListAddressDTC.strtListDef.eReadOBD2Lib=eTRUE;
  enumInnovaGroups eInnovaGroup = GROUP_OBDII;
  uint32 sLenDef = 0;
  sLenDef = gf_VDM_DTC_Library_GetDef(eMake, 
                                      eMemLanguage, 
                                      pStrDispDtc,
                                      pDef, 
                                      sDefSize, 
                                      eInnovaGroup, 
                                      &strtListAddressDTC);
  return sLenDef;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_Library_GetDef_OBD1
*Input        : enumManufacturer  eManufacture,
enumOBDLanguage   eMemLanguage,
void *pStrDispDtc,
uint32 sDefSize
*Output       : void *pDef
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
#ifdef _MSC_VER
__declspec(dllexport) uint32 __stdcall  gf_VDM_DTC_Library_GetDef_OBD1(enumMake eMake,
                                                                       enumOBDLanguage eMemLanguage, void *pStrDispDtc, void *pDef,
                                                                       uint32 sDefSize)
#else
uint32  gf_VDM_DTC_Library_GetDef_OBD1(enumMake eMake,
                                       enumOBDLanguage eMemLanguage, void *pStrDispDtc, void *pDef,
                                       uint32 sDefSize)
#endif
{
  
  structListAddressDTC strtListAddressDTC;
  memset(&strtListAddressDTC, 0, sizeof(structListAddressDTC));
  uint32 len = gf_VDM_DTC_Library_GetDef(eMake, eMemLanguage, pStrDispDtc, pDef,
                                         sDefSize,
                                         GROUP_OBDI, &strtListAddressDTC);
  return len;
}

