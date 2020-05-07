/*
* Default_Adapter_DtcDef.c
*
*  Created on: Jul 29, 2015
*      Author: Lap Dang
*/

#include "NWSCAN_APP\LIB\PlatFormType.h"
#include "NWSCAN_APP\DTC\DTC_Config.h"
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
//#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\enums.h>
//#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMMESelection.h>
//#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMME_Structure.h>
//#include <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Structure.h>
//#include "NWSCAN_APP\Common\SystemData.h"
//#include <NWSCAN_APP\Adapter\Common\NwS_Struct.h>
//#include "NWSCAN_APP\Adapter\Makes\Utilities\Makes_VCI_Utilities.h"
#include "NWSCAN_APP\MW_LIB\Makes_Adapter_App.h"
#include <2_Middle\0_Middle_Utilities\AES\aes256.h>
#include "DTCDefinition.h"
#include "DTCUtilities.h"
#include <stdlib.h>
#include "DTCDefinitionConfig.h"
//#include <NWSCAN_APP/Adapter/Common/VDM_Util_DB_Parser.h>
//#include <NWSCAN_APP/Adapter/Makes/Chrysler/NwS_Chrysler_Utility.h>
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __DTC_YmmeSubSearch
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static void __DTC_YmmeSubSearch(structMFRVinProfile *p_strtMFRVinProfile,
                                structOemProfile *p_strtOemProfile, structKeyInfo *p_strtKeySubInfo)
{
  memset(p_strtKeySubInfo, 0xFF, sizeof(structKeyInfo));
  memset(p_strtKeySubInfo->bMainDTCString, 0x00,
         sizeof(p_strtKeySubInfo->bMainDTCString));
  p_strtKeySubInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  if (p_strtMFRVinProfile->eManufacturer == emanufacturer_Chrysler)
  {
    p_strtKeySubInfo->sSystem = p_strtOemProfile->sSystem;
    p_strtKeySubInfo->sSubSystem = p_strtOemProfile->sSubSystem;  
    p_strtKeySubInfo->bProtocol = p_strtOemProfile->Protocol;
  }
}

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
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
#if CHRYSLER_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if CHRYSLER_use_sSystem
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if CHRYSLER_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
  }
#endif
#if CHRYSLER_use_sProtocol
  {
    p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
  }
#endif
}
#define MAX_PROTOCOL_LIST	2
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __HasCodeDTC

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
static uint8 __HasCodeDTC(structKeyInfo *pstrtKeyFilterInfo,
                             enumInnovaGroups eInnovaGroup)
{
  uint8 eResult = 0;   //eFALSE
  char bPath_maindtc_bin[50];
  uint8* group;
  uint8 bNumFolderVersion;
  uint32 iAddrKey;
  FRESULT res;
  structNwSHeader strtHeader;
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  if (eInnovaGroup==GROUP_N_A)
    bNumFolderVersion=VDM_NWDTC_GET_LIST_VERSION();
  else
    bNumFolderVersion=VDM_DTC_GET_LIST_VERSION();
  if (bNumFolderVersion==0)  //Not found folder DTC, display all DTC
    return 2;
  for(uint8 bIdxVersion =0;bIdxVersion<bNumFolderVersion;bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    if (eInnovaGroup==GROUP_N_A)
      sprintf(bPath_maindtc_bin, PATH_ALL_MAINDTC_BIN, group);
    else
      sprintf(bPath_maindtc_bin, PATH_MAINDTC_BIN, group);
    pstrtFileBinHandle->path = bPath_maindtc_bin;
#ifdef  _MSC_VER
    FILE_BIN_Open(pstrtFileBinHandle->fp,
                  pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
    pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
    
    res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00, (uint8*) &strtHeader,
                               sizeof(strtHeader));
    if (res == FR_OK)
    {
      uint8 strRam[144];
      iAddrKey = gf_SYS_GetFirstKey(sizeof(strtHeader),
                                    strtHeader.iNumberLine, (uint8*) pstrtKeyFilterInfo,
                                    strtHeader.bKeySize, strRam, strtHeader.bBaseSize,
                                    pstrtFileBinHandle);
      if (iAddrKey == _BST_NOT_FOUND_KEY_)
      {      
        eResult = 0;  //eFALSE
      }
      else
      {
        eResult = 1;  //eTRUE
      }
#ifdef  _MSC_VER
	  FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
	  pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
    }
    else
    {
      return 2;  //No database
    }
  }
  return eResult;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_FilterDTC_MSISO_Chrysler
*Input        : structOemProfile * p_strtOemProfile
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
void gf_FilterDTC_MSISO_Chrysler(structOemProfile * p_strtOemProfile);
void gf_FilterDTC_MSISO_Chrysler(structOemProfile * p_strtOemProfile)
{
  uint8 bBytePosDTC=0;
  uint8 bByteProfilePosDTC=0;
  uint8 bFrameDTC;
  uint8 bNumDTC =0;
  uint8 eResult = 0;
  enumBufferName eBufferName;
  enumInnovaGroups eInnovaGroup;
  structDtcParser strtDtcParser;
  uint8 strDTC[SIZE_OF_OEM_DTC];
  structKeyInfo strtKeyFilterInfo;
  eInnovaGroup=p_strtOemProfile->bSelInnGroup;
  bFrameDTC = p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc+1;
  memset(&strDTC,0,SIZE_OF_OEM_DTC);
  memset(&strtKeyFilterInfo, 0xFF, sizeof(structKeyInfo));
  strtKeyFilterInfo.sManufacturer = emanufacturer_Chrysler;
  strtKeyFilterInfo.sSystem = p_strtOemProfile->sSystem;
  strtKeyFilterInfo.sSubSystem = p_strtOemProfile->sSubSystem;
  strtKeyFilterInfo.bProtocol = p_strtOemProfile->Protocol;
  for (uint8 bIndexDTC = 0; bIndexDTC<=p_strtOemProfile->strtOEMDTCBuffer.NumberDTC-1;bIndexDTC++)
  {
    strtDtcParser.pDtc = gf_VDM_DTC_GetRawFromOemProfile(p_strtOemProfile,
                                                         &strtDtcParser.bFrameDtc,
                                                         bIndexDTC);
    gf_VDM_DTC_GetDtcStringFromOemProfile(p_strtOemProfile,
                                          &eBufferName,
                                          bIndexDTC,
                                          &strtDtcParser);
    
    memcpy(strtKeyFilterInfo.bMainDTCString, strtDtcParser.arrDtcOutPut, 15);
    eResult = __HasCodeDTC(&strtKeyFilterInfo, 
                           eInnovaGroup);
    if (eResult==2) //No database
      break;
    if (eResult==1) // has code DTC
    {
      for (uint8 bFormat=0;bFormat<=p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc;bFormat++)
      {
        bBytePosDTC = bNumDTC*bFrameDTC+bFormat;
        bByteProfilePosDTC = bIndexDTC*bFrameDTC+bFormat;
        strDTC[bBytePosDTC]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bByteProfilePosDTC];            
      }
      bNumDTC++;
    }
  }
  if ((eResult!=2)&&(p_strtOemProfile->strtOEMDTCBuffer.NumberDTC!=0))
  {
    memcpy(p_strtOemProfile->strtOEMDTCBuffer.DTC,&strDTC,SIZE_OF_OEM_DTC);
    p_strtOemProfile->strtOEMDTCBuffer.NumberDTC = bNumDTC;
  }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_OEM_GetDef
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
uint32 gf_CHRYSLER_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                      structOemProfile *p_strtOemProfile, 
                                      enumOBDLanguage eMemLanguage,
                                      structListDTCType *pstrtListDTCType, 
                                      void *pDefOut, 
                                      uint32 iDefSize,
                                      structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  char*pDef = (char*) pDefOut;
  //structListAddressDTC strtListAddressDTC;
  structDTCString *pstrtDTCString;
  enumInnovagroup *pListInnGroup;
  //uint8 bNumLoopGroup = 4;
  uint32 iLenDef = 0;
  uint32 iTemp;
  enumSystem eListProtocol[2];
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;               //Default language
  if (pDef == null)
    return 0;
  else
    pDef[0] = 0;
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
  eListProtocol[0] = p_strtOemProfile->Protocol;
  eListProtocol[1] = eprotocol_PROTOCOL_MAX;
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString,
         strlen(pstrtListDTCType->bDTCString));
  
  pstrtDTCString = gf_DTC_GetSplitStrDTC(pstrtListDTCType);
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    for (uint8 i = 0; i < MAX_PROTOCOL_LIST; i++)
    {
      strtKeyInfo.bProtocol = eListProtocol[i];
      pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, &strtKeyInfo,
                                              pstrtListAddrDTC, eTRUE);
      
      if (pstrtListAddressDTC != Null)
      {
        return gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                     eMemLanguage, pDef, iDefSize, eTRUE);
      }
    }
    bIdxGroup++;
  }
  
  if (pstrtListAddressDTC == null)  //Not Found
  {
    if (gf_DTC_IsHasSubCode(pstrtDTCString))  //Has Sub COde
    {
      __DTC_YmmeSearch(p_strtMFRVinProfile, p_strtOemProfile,
                       pstrtListDTCType, &strtKeyInfo);
      
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefMain);
      pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
      bIdxGroup = 0;
      while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
      {
        eInnovaGroup = pListInnGroup[bIdxGroup];
        for (uint8 i = 0; i < MAX_PROTOCOL_LIST; i++)
        {
          strtKeyInfo.bProtocol = eListProtocol[i];
          
          pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup,
                                                  &strtKeyInfo, pstrtListAddrDTC, eTRUE);
          if (pstrtListAddressDTC != null)
          {
            iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC,
                                            eInnovaGroup, eMemLanguage, pDef, iDefSize,
                                            eTRUE);
            break;
          }
        }
        if (pstrtListAddressDTC != null)
          break;
        bIdxGroup++;
      }
      if (pstrtListAddressDTC == null) //If not found Main def , will ignore sub def also
      {
        return 0;
      }
      
      ///Found sub def
      __DTC_YmmeSubSearch(p_strtMFRVinProfile, p_strtOemProfile,
                          &strtKeyInfo);
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefSub);
      pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
      bIdxGroup = 0;
      while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
      {
        
        for (uint8 i = 0; i < MAX_PROTOCOL_LIST; i++)
        {
          strtKeyInfo.bProtocol = eListProtocol[i];
          eInnovaGroup = pListInnGroup[bIdxGroup];
          pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup,
                                                  &strtKeyInfo, pstrtListAddrDTC, eFALSE);
          if (pstrtListAddressDTC != null)
          {
            pDef[iLenDef++] = ' ';
            pDef[iLenDef++] = '-';
            pDef[iLenDef++] = ' ';
            iTemp = gf_Get_DTC_Definition(pstrtListAddressDTC,
                                          eInnovaGroup, eMemLanguage,
                                          &((uint8*) pDef)[iLenDef], iDefSize, eFALSE);
            if (iTemp == 0)
            {
              iLenDef -= 3;
              pDef[iLenDef] = 0;
            }
            iLenDef += iTemp;
            return iLenDef;
          }
        }
        if (pstrtListAddressDTC != null)
          break;
        bIdxGroup++;
        
      }
    }
  }
  return iLenDef;
}
