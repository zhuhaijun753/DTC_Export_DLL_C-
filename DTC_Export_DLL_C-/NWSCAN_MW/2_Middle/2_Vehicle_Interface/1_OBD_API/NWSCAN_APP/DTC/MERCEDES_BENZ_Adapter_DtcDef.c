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
//#include <NWSCAN_APP/Adapter/Makes/Mercedes/NwS_Mercedes_Utility.h>

#define SIZE_YEAR_MANUFACTURE   3
#define SIZE_MAINCODE 15
#pragma pack(1)
typedef struct _structKeySystemInfo         //Key_Info
{
  uint16 sModel;
  uint16 sOption1;
  uint32 sOption2;
  uint16 sOption3;
  uint16 sOption4;
  uint16 sSystem;
  uint16 sSubSystem;
  uint16 bProtocol;
} structKeySystemInfo;
#pragma pack()

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
                             structOemProfile *p_strtOemProfile,
                             structListDTCType *pstrtListDTCType,
                             structKeyInfo *p_strtKeyInfo)
{
  structOemInfo_Mercedes *pstrtMercedesInfo;
  pstrtMercedesInfo = (structOemInfo_Mercedes *) p_strtOemProfile->OemInfo;
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  
#if MERCEDES_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if MERCEDES_use_sModel
  {
    p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
  }
#endif
  if (pstrtMercedesInfo->bValidCode==VALID_CODE)
  {
    p_strtKeyInfo->sOption4 = pstrtMercedesInfo->eQualifier;  
    p_strtKeyInfo->sOption2=pstrtMercedesInfo->iModelTypes; 
  }
  p_strtKeyInfo->sOption3 = p_strtOemProfile->iProfileID;  
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __HasSubCode

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
static enumbool __HasSubCode(structKeyInfo *pstrtKeyFilterInfo)
{
  enumbool eResult = eFALSE;
  for (uint8 i = 0; i < SIZE_MAINCODE; i++)
  {
    if (pstrtKeyFilterInfo->bMainDTCString[i] == '-')
    {
      eResult = eTRUE;
      break;
    }
  }
  return eResult;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __HasCodeDTC

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
static uint8 __HasCodeDTC(structOemProfile * p_strtOemProfile,
                             structKeyInfo *pstrtKeyFilterInfo,
                             enumInnovaGroups eInnovaGroup,                               
                             enumbool IsParserOneRawData)
{
  uint8 eResult = eFALSE;
  uint16 iOption4;
  uint32 sOption2;
  char bPath_maindtc_bin[50];
  uint8* group;
  uint8 bNumFolderVersion;
  uint32 iAddrKey;
  uint8 strDTCCode[SIZE_MAINCODE];
  FRESULT res;
  structNwSHeader strtHeader;
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  structOemInfo_Mercedes *pstrtMercedesInfo;
  pstrtMercedesInfo = (structOemInfo_Mercedes *) p_strtOemProfile->OemInfo;
  if (pstrtMercedesInfo->bValidCode==VALID_CODE)
    pstrtKeyFilterInfo->sOption4 = pstrtMercedesInfo->eQualifier;
  pstrtKeyFilterInfo->sOption2=pstrtMercedesInfo->iModelTypes; 
  if (eInnovaGroup==GROUP_N_A)
    bNumFolderVersion=VDM_NWDTC_GET_LIST_VERSION();
  else
    bNumFolderVersion=VDM_DTC_GET_LIST_VERSION();
  if (bNumFolderVersion==0)  //Not found folder DTC, display all DTC
    return 2; //No database
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
    memcpy(&strDTCCode,pstrtKeyFilterInfo->bMainDTCString,SIZE_MAINCODE);
    iOption4 = pstrtKeyFilterInfo->sOption4;
    sOption2 = pstrtKeyFilterInfo->sOption2;
    if (res == FR_OK)
    {
      uint8 strRam[144];
      for (uint8 i=0;i<2;i++)
      {
        if (i==1)
          pstrtKeyFilterInfo->sOption4 = 0xFFFF;
        else
          pstrtKeyFilterInfo->sOption4 = iOption4;
        for (uint8 j=0;j<2;j++)
        {
          if (j == 1)
            pstrtKeyFilterInfo->sOption2 = 0xFFFFFFFF;
          else
            pstrtKeyFilterInfo->sOption2 = sOption2;
          iAddrKey = gf_SYS_GetFirstKey(sizeof(strtHeader),
                                        strtHeader.iNumberLine, (uint8*) pstrtKeyFilterInfo,
                                        strtHeader.bKeySize, strRam, strtHeader.bBaseSize,
                                        pstrtFileBinHandle); 
          if (iAddrKey != _BST_NOT_FOUND_KEY_)
          {
            // have code in databse, need to display in tool
            eResult = 1;  //eTRUE
#ifdef  _MSC_VER
			FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
			pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
            return eResult;
            
          }
        }
      }
      // haven't code in databse, continue search (if has subcode)
      if( !__HasSubCode(pstrtKeyFilterInfo))
      {
        eResult = 1; //eTRUE
#ifdef  _MSC_VER
		FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
		pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
        return eResult;
      }
      if (iAddrKey == _BST_NOT_FOUND_KEY_)
      {
        if (IsParserOneRawData==eFALSE)
        {
         eResult = 1; //eTRUE
#ifdef  _MSC_VER
		 FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
		 pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
         return eResult; 
        }
      }
    }
    else
      return 2; //No database
  }
  return eResult;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __DTC_GetSplitStrDTC

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
static structDTCString* __DTC_GetSplitStrDTC(uint8 *bStringCode)
{
  static structDTCString strtDTCString;
  memset(&strtDTCString, 0, sizeof(structDTCString));
  //A-B
  uint8 bMainLen = 0;
  uint8 bSubLen = 0;
  for (int i = 0; i < SIZE_MAINCODE; i++)
  {
    if (bStringCode[i] == '-')
    {
      i++;
      for (; i < SIZE_MAINCODE; i++)
      {
        bSubLen++;
      }
    }
    else
    {
      bMainLen++;
    }
  } 
  memcpy(strtDTCString.strDefMain, &bStringCode[0], bMainLen);
  if (bSubLen > 0)
    memcpy(strtDTCString.strDefSub,
           &bStringCode[bMainLen + 1], bSubLen);
  
  return &strtDTCString;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __IsDTCParser_OneRawData

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
static enumbool __IsDTCParser_OneRawData(uint8* PreCode,
                                         uint8* CurrCode,
                                         uint8* NextCode)
{
  enumbool eResult = eFALSE;
  uint8 bStringCode_Pre[15];
  uint8 bStringCode_Curr[15];
  uint8 bStringCode_Next[15];
  memset(&bStringCode_Pre,0,15);
  memset(&bStringCode_Curr,0,15);
  memset(&bStringCode_Next,0,15);
  structDTCString *pstrtDTCString;
  
  pstrtDTCString = __DTC_GetSplitStrDTC(PreCode);
  memcpy(&bStringCode_Pre,pstrtDTCString->strDefMain,5);
  
  pstrtDTCString = __DTC_GetSplitStrDTC(CurrCode);
  memcpy(&bStringCode_Curr,pstrtDTCString->strDefMain,5);
  
  pstrtDTCString = __DTC_GetSplitStrDTC(NextCode);
  memcpy(&bStringCode_Next,pstrtDTCString->strDefMain,5);
  
  if ((memcmp(&bStringCode_Curr,&bStringCode_Pre,15)==0)||
      (memcmp(&bStringCode_Curr,&bStringCode_Next,15)==0))
  {
    eResult = eTRUE;
  }
  return  eResult;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __FilterDTC_Mercedes

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
void gf_FilterDTC_Mercedes(structOemProfile * p_strtOemProfile);
void gf_FilterDTC_Mercedes(structOemProfile * p_strtOemProfile)
{
  enumbool IsParserOneRawData = eFALSE;
  uint8 bBytePos=0;
  uint8 bByteProfilePos=0;
  uint8 bFrame;
  uint8 bNumberDTC =0;
  uint8 bPreStringDTC[15], bNextStringDTC[15];
  uint8 eResult = 0; //eFALSE
  enumBufferName eBufferName;
  enumInnovaGroups eInnovaGroup;
  structDtcParser strtDtcParser;
  uint8 strDTC[SIZE_OF_OEM_DTC];
  structKeyInfo strtKeyFilterInfo;
  eInnovaGroup=p_strtOemProfile->bSelInnGroup;
  bFrame = p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc+1;
  memset(&strDTC,0,SIZE_OF_OEM_DTC);
  memset(&bPreStringDTC,0,SIZE_MAINCODE);
  memset(&bNextStringDTC,0,SIZE_MAINCODE);
  memset(&strtKeyFilterInfo, 0xFF, sizeof(structKeyInfo));
  strtKeyFilterInfo.sManufacturer = emanufacturer_Mercedes_Benz;
  strtKeyFilterInfo.sOption3 = p_strtOemProfile->iProfileID;
  
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
    // NextDtcCode
    if (bIndexDTC<p_strtOemProfile->strtOEMDTCBuffer.NumberDTC-1)
    {
      strtDtcParser.pDtc = gf_VDM_DTC_GetRawFromOemProfile(p_strtOemProfile,
                                                           &strtDtcParser.bFrameDtc,
                                                           bIndexDTC+1);
      gf_VDM_DTC_GetDtcStringFromOemProfile(p_strtOemProfile,
                                            &eBufferName,
                                            bIndexDTC+1,
                                            &strtDtcParser);
      memcpy(&bNextStringDTC, strtDtcParser.arrDtcOutPut, 15);
    }
    else
    {
      memcpy(&bNextStringDTC, 0, 15);
    }
    // PreDtcCode
    if (bIndexDTC>0)
    {
      strtDtcParser.pDtc = gf_VDM_DTC_GetRawFromOemProfile(p_strtOemProfile,
                                                           &strtDtcParser.bFrameDtc,
                                                           bIndexDTC-1);
      gf_VDM_DTC_GetDtcStringFromOemProfile(p_strtOemProfile,
                                            &eBufferName,
                                            bIndexDTC-1,
                                            &strtDtcParser);
      memcpy(&bPreStringDTC, strtDtcParser.arrDtcOutPut, 15);
    }
    if (p_strtOemProfile->strtOEMDTCBuffer.NumberDTC!=1)
    {
      IsParserOneRawData = __IsDTCParser_OneRawData(&bPreStringDTC,
                                                    &strtKeyFilterInfo.bMainDTCString,
                                                    &bNextStringDTC);
    }
    eResult = __HasCodeDTC(p_strtOemProfile,
                           &strtKeyFilterInfo, 
                           eInnovaGroup,  
                           IsParserOneRawData);
    if (eResult==2) // No database
      break;
    if (eResult==1) //Has code DTC
    {
      for (uint8 bFormat=0;bFormat<=p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc;bFormat++)
      {
        bBytePos = bNumberDTC*bFrame+bFormat;
        bByteProfilePos = bIndexDTC*bFrame+bFormat;
        strDTC[bBytePos]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bByteProfilePos];            
      }
      bNumberDTC++;
    }
  }
  if ((eResult!=2)&&(p_strtOemProfile->strtOEMDTCBuffer.NumberDTC!=0))
  {
   memcpy(p_strtOemProfile->strtOEMDTCBuffer.DTC,&strDTC,SIZE_OF_OEM_DTC);
   p_strtOemProfile->strtOEMDTCBuffer.NumberDTC = bNumberDTC;
  }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __GetListAddressDTC_Mercedes

*Input        :
*Output       :
*Description  :
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static uint8 __GetListAddressDTC_Mercedes(structListAddressDTC *pstrtListAddressDTC,
                                          structKeyInfo *p_strtKeyInfo, 
                                          void *pPathFile)
{
  uint32 iMainAddr;
  FRESULT res;
  uint8 i =0;
  uint8 bLenMainCode=0;
  structKeySystemInfo strtKeyInfoInput;
  structKeySystemInfo strtKeyInfoRead;
  structNwSHeader strtHeader;
  structKeyInfo strtReadKey;
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  pstrtFileBinHandle->path = pPathFile;
#ifdef  _MSC_VER
  if (FILE_BIN_Open(pstrtFileBinHandle->fp,
                    pstrtFileBinHandle->path, pstrtFileBinHandle->mode) != FR_OK)
#else
    if (pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                    pstrtFileBinHandle->path, pstrtFileBinHandle->mode) != FR_OK)
#endif
    {
      return 0;
    }
  while (p_strtKeyInfo->bMainDTCString[i]!=0x00)
  {
    bLenMainCode++;
    i++;
    if(p_strtKeyInfo->bMainDTCString[i]==0x00)
      break;
  }
  res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00, (uint8*) &strtHeader,
                             sizeof(strtHeader));
  if (res != FR_OK)
    return 0;
  uint8 strRam[255];
  // Get first key
  uint32 iAddrKey = gf_SYS_GetFirstKey(sizeof(strtHeader),    
                                       strtHeader.iNumberLine, 
                                       (uint8*) p_strtKeyInfo, 
                                       SIZE_YEAR_MANUFACTURE+bLenMainCode,
                                       strRam, 
                                       strtHeader.bBaseSize, 
                                       pstrtFileBinHandle);
  if (iAddrKey == _BST_NOT_FOUND_KEY_)
  {
#ifdef  _MSC_VER
    FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
    pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
    return 0;
  }
  else
  {
    do
    {
      strtKeyInfoInput.sModel=p_strtKeyInfo->sModel;
      strtKeyInfoInput.sOption1=p_strtKeyInfo->sOption1;
      strtKeyInfoInput.sOption2=p_strtKeyInfo->sOption2;
      strtKeyInfoInput.sOption3=p_strtKeyInfo->sOption3;
      strtKeyInfoInput.sOption4=p_strtKeyInfo->sOption4;
      strtKeyInfoInput.sSystem=p_strtKeyInfo->sSystem;
      strtKeyInfoInput.sSubSystem=p_strtKeyInfo->sSubSystem;
      strtKeyInfoInput.bProtocol=p_strtKeyInfo->bProtocol;
      gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                           iAddrKey + SIZE_YEAR_MANUFACTURE + SIZE_MAINCODE,
                           (uint8*)&strtKeyInfoRead,
                           sizeof(structKeySystemInfo));
      if (memcmp(&strtKeyInfoInput, &strtKeyInfoRead, sizeof(structKeySystemInfo)) == 0)
      {
        if (gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                                 iAddrKey+strtHeader.bKeySize,
                                 (uint8*) &iMainAddr, 
                                 strtHeader.bBaseSize)!= FR_OK)
        {
#ifdef  _MSC_VER
          FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
          pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
        }
        else
        {
          if (gf_CheckDupplicateAddr(iMainAddr, pstrtListAddressDTC) == eFALSE)
          {
            pstrtListAddressDTC->ListItem[pstrtListAddressDTC->bNoItem] = iMainAddr;
            pstrtListAddressDTC->bNoItem++;
            break;
          }
        }
      }
        iAddrKey=iAddrKey+strtHeader.bBaseSize;
        gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                             iAddrKey,
                             (uint8*)&strtReadKey,
                             sizeof(structKeyInfo));
    }
    while (memcmp(&strtReadKey, p_strtKeyInfo, SIZE_YEAR_MANUFACTURE+bLenMainCode) == 0);
  }
#ifdef  _MSC_VER
  FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
  pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
  return pstrtListAddressDTC->bNoItem;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __DTC_FindListIDMercedes

*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static structListAddressDTC * __DTC_FindListIDMercedes(enumInnovaGroups eInnovaGroup,
                                                       structKeyInfo *p_strtKeyInfo, 
                                                       structListAddressDTC* pstrtListAddressDTC)
{
  void *PathPatern = null;
  char bPath_dtc[50];
  if (pstrtListAddressDTC == Null)
    return null;
  pstrtListAddressDTC->bNoItem = 0;
  pstrtListAddressDTC->IsFoundDTC=eFALSE;
  uint8 bNumFolderVersion;
  uint8* group;
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  if (group == null)
    return Null;
  if (eInnovaGroup == GROUP_N_A)
    bNumFolderVersion = VDM_NWDTC_GET_LIST_VERSION();
  else
    bNumFolderVersion = VDM_DTC_GET_LIST_VERSION();
  for (uint8 bIdxVersion = 0; bIdxVersion < bNumFolderVersion; bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    if (eInnovaGroup == GROUP_N_A)
      PathPatern = PATH_ALL_MAINDTC_BIN;
    else
      PathPatern = PATH_MAINDTC_BIN;
    sprintf(bPath_dtc, PathPatern, group);
    if (__GetListAddressDTC_Mercedes(pstrtListAddressDTC, 
                                     p_strtKeyInfo, 
                                     bPath_dtc) > 0)
    {
      break;
    }
  }
  if (pstrtListAddressDTC->bNoItem>0)
  {
    pstrtListAddressDTC->IsFoundDTC=eTRUE;
    return pstrtListAddressDTC;
  }
  else
    return Null;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_MERCEDES_BENZ_Adapter_DTC_GetDef
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
uint32 gf_MERCEDES_BENZ_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                           structOemProfile *p_strtOemProfile,
                                           enumOBDLanguage eMemLanguage,
                                           structListDTCType *pstrtListDTCType,
                                           void *pDefOut,
                                           uint32 iDefSize,
                                           structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  char*pDef = (char*) pDefOut;
  uint32 iOption2;
  uint8 bNumLoop=2;
  uint32 iLenDef = 0;
  uint32 iTemp;
  enumSystem eListOption4[2];
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
  structDTCString *pstrtDTCString;
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;               //Default language
  if (pDef == null)
    return 0;
  else
    ((uint8*) pDef)[0] = 0;
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  if (p_strtOemProfile->bSelInnGroup == GROUP_OBDI)
  {
    strtKeyInfo.sManufacturer= eManufacture;
    strtKeyInfo.sSystem=p_strtOemProfile->sSystem;
  }
  else
  {
    __DTC_YmmeSearch(p_strtMFRVinProfile,
                     p_strtOemProfile,
                     pstrtListDTCType,
                     &strtKeyInfo);
  }
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString, strlen(pstrtListDTCType->bDTCString));
  eListOption4[0] = strtKeyInfo.sOption4;
  eListOption4[1] = 0xFFFF;
  iOption2 = strtKeyInfo.sOption2;
  for (uint8 bIdxOption4 = 0; bIdxOption4 < bNumLoop; bIdxOption4++)
  {
    strtKeyInfo.sOption4=eListOption4[bIdxOption4];
    for (uint8 bIdxBMCode = 0; bIdxBMCode < bNumLoop; bIdxBMCode++)
    {
      if (bIdxBMCode==0)
        strtKeyInfo.sOption2 = iOption2;
      else
        strtKeyInfo.sOption2=0xFFFFFFFF;
      pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, &strtKeyInfo,
                                              pstrtListAddrDTC, eTRUE);
      if (pstrtListAddressDTC != Null)
      {
        // Read MainCode
        iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,      
                                        eMemLanguage, pDef, iDefSize, eTRUE);
        // Read SubCode
        pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup,&strtKeyInfo, 
                                                pstrtListAddrDTC, eFALSE);
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
        if (iLenDef!=0)
          return iLenDef;
      //  break;
      }
      else
      {
        pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, &strtKeyInfo,
                                                pstrtListAddrDTC, eFALSE);
        if (pstrtListAddressDTC != Null)
        {
          iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                          eMemLanguage, pDef, iDefSize, eFALSE);
          break;
        }
      }
      // Split MainCode
      pstrtDTCString = gf_DTC_GetSplitStrDTC(pstrtListDTCType);
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefMain);
      pstrtListAddressDTC = __DTC_FindListIDMercedes(eInnovaGroup,
                                                     &strtKeyInfo, 
                                                     pstrtListAddrDTC);
      if (pstrtListAddressDTC != Null)
      {
        iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                        eMemLanguage, pDef, iDefSize, eTRUE);
        break;
      }
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString, strlen(pstrtListDTCType->bDTCString));
    }
    if (pstrtListAddressDTC != null)
      break;
  }
  return iLenDef;
}
