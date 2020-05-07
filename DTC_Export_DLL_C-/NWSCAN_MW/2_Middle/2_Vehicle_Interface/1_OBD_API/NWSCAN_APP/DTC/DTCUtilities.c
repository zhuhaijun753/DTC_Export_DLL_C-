/*******************************************************************************
================================================================================
Lap Dang Dev
* Filename: DTCUtilities.c
* Description:
* Layer:
* Accessibility:
* Created on: Oct 17, 2015
*      Author: Lap Dang
================================================================================
*******************************************************************************/
#define DTCUTILITIES_C_
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
#include "DTCDefinition.h"
#include "DTCUtilities.h"
#include <stdlib.h>
#include "DTCDefinitionConfig.h"
#include "DTCUtilities.h"
#ifdef _MSC_VER
#include <stdio.h>
#include <windows.h>
typedef enum
{
  NWS = 1,
  YMME = 2,
  DTC_DEF_ALL_MAKE = 3,
  HYBRID = 4,
  TRIPCYCLE = 5,
  ACTIVETEST = 6,
  SPECIALFUNCTION = 7,
  OILRESET = 8,
  DLCLOCATOR = 9,
  VINDECOD = 10,
  BATTERYRESET = 11
    
}enumKeyType;
typedef int(__cdecl *VDS_aes_decrypt)(enumKeyType eKeyType, char* input, char* output, int length);
//__declspec(dllimport) int VDS_aes_decrypt(enumKeyType eKeyType, unsigned char* input, unsigned char* output, int length);
#else
#include <2_Middle\0_Middle_Utilities\AES\aes256.h>
#endif

const structDtcInfoPath ROM_dtcinfo_inngrp_map[] = {
  {
    GROUP_ABS, "ABS"
  },
  {
    GROUP_SRS, "SRS"
  },
  {
    GROUP_OBDII, "OBDII"
  },
  {
    GROUP_ENH_TCM, "ENH"
  },
  {
    GROUP_ENH_ECM, "ENH"
  },
  {
    GROUP_ENH_PCM, "ENH"
  },
  
  {
    GROUP_N_A, "NWS"
  },
  {
    GROUP_OBDI, "OBD1"
  },
  {
    DTC_GROUP_ALL, "All"
  },
  
  {
    GROUP_MAX, 0
  }
};

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_CheckDupplicateAddr
*Input        :
*Output       :
*Description  :
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
enumbool gf_CheckDupplicateAddr(uint32 Lap Dangem,
                                structListAddressDTC *pstrtListAddressDTC)
{
  uint8 i;
  if (Lap Dangem == 0xFFFFFFFF)
    return eTRUE;
  
  for (i = 0; i < pstrtListAddressDTC->bNoItem; i++)
  {
    if (Lap Dangem == pstrtListAddressDTC->ListItem[i])
    {
      return eTRUE;
    }
  }
  return eFALSE;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void *gf_DtcGetMappingString(uint16 sID, const structDtcInfoPath*pData)
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
void *gf_DtcGetMappingString(uint16 sID, const structDtcInfoPath*pData)
{
  for (uint8 i = 0; pData[i].pString != Null; i++)
  {
    if (pData[i].sID == sID)
      return pData[i].pString;
  }
  return Null;
}
#define KEY_SIZE_DTC_LIBRARY 18
#pragma pack(1)
typedef struct _structDTCDefMappingAddr
{
  structKeyInfo Key;
  uint32 iMainAddr;
  uint8 bInnovaGroup;
  uint32 iSubAddr;
} structDTCDefMappingAddr;
#pragma pack()
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: uint8 gf_GetListAddressDTC(structListAddressDTC *pstrtListAddressDTC,
structKeyInfo *p_strtKeyInfo,
void *pPathFile,
enumbool eUseDTCLibrary)
*Input        :
*Output       :
*Description  :
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
uint8 gf_GetListAddressDTC(structListAddressDTC *pstrtListAddressDTC,
                           structKeyInfo *p_strtKeyInfo, 
                           void *pPathFile, 
                           enumbool eUseDTCLibrary,
                           enumbool IsMainDTC)
{
  structDTCDefMappingAddr structDTCDefMappingAddr;
  uint8 pPath[20];
  uint32 iLineIdx = 0;
  FRESULT res;
  uint32 iAddr;
  structNwSHeader strtHeader;
  structKeyInfo strtReadKey;
  uint8 eResult;
  memcpy(&pPath,pPathFile,20);
#ifdef  _MSC_VER
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  pstrtFileBinHandle->path = pPathFile;
  eResult =FILE_BIN_Open(pstrtFileBinHandle->fp, pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
  if (eResult != fresult_OK)
  {
    return 0;
  }
  
  res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00, (uint8*)&strtHeader,
                             sizeof(structNwSHeader));
  if (res != FR_OK)
  {
    return 0;
  }
  //bKeySizeBk=strtHeader.bKeySize;
  uint8 strRam[255];
  if (eUseDTCLibrary == eTRUE)
  {
    strtHeader.bKeySize = KEY_SIZE_DTC_LIBRARY;
    //SizeCompare= KEY_SIZE_DTC_LIBRARY;
  }
  
  uint32 iAddrKey = gf_SYS_GetFirstKey(sizeof(strtHeader),    // Get first key
                                       strtHeader.iNumberLine, 
                                       (uint8*)p_strtKeyInfo, 
                                       strtHeader.bKeySize,
                                       strRam, strtHeader.bBaseSize, pstrtFileBinHandle);
  if (iAddrKey == _BST_NOT_FOUND_KEY_)
  {
    FILE_BIN_Close(pstrtFileBinHandle->fp);
    return 0;
  }
  else   // Get multi Address
  {
    do
    {
      //strtHeader.bKeySize=bKeySizeBk;
      if (gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                               iAddrKey,
                               (uint8*)&structDTCDefMappingAddr, 
                               strtHeader.bBaseSize)
          != FR_OK)
      {
        FILE_BIN_Close(pstrtFileBinHandle->fp);
        break;
      }
      else
      {
        iAddrKey = iAddrKey + strtHeader.bBaseSize;
        if (IsMainDTC == eTRUE)
        {
          iAddr = structDTCDefMappingAddr.iMainAddr;
        }
        else
        {
          iAddr = structDTCDefMappingAddr.iSubAddr;
        }
        if (gf_CheckDupplicateAddr(iAddr, pstrtListAddressDTC) == eFALSE)
        {
#if SUPPORT_TOOL_F_BASIC_MX
          if ((p_strtKeyInfo->sManufacturer==emanufacturer_Toyota)&&(eUseDTCLibrary == eTRUE))
          {
            if ((structDTCDefMappingAddr.Key.sSystem!=esystem_SRS_____Airbag_Toyota)||
                (structDTCDefMappingAddr.Key.sSystem!=esystem_ECM_Toyota)||
                  (structDTCDefMappingAddr.Key.sSystem!=esystem_ABS_Toyota))
              goto TOYOTA_BASIC_MEXICO;
          }
#endif 
          pstrtListAddressDTC->ListItem[pstrtListAddressDTC->bNoItem] = iAddr;
          pstrtListAddressDTC->bNoItem++;
          if (pstrtListAddressDTC->bNoItem >= MAX_LIST_ADDRESS_DTC)
            break;
          if (p_strtKeyInfo->sManufacturer == emanufacturer_Mercedes_Benz) // Only get 1 Definition
            break;
        }
      }
    TOYOTA_BASIC_MEXICO:      
      gf_SYS_Util_ReadFile(pstrtFileBinHandle, iAddrKey,
                           (uint8*)&strtReadKey, sizeof(structKeyInfo));
      if (memcmp(&strtReadKey, p_strtKeyInfo, strtHeader.bKeySize) != 0)
      {
        break;
      }
      iLineIdx++;
    } while (iLineIdx < strtHeader.iNumberLine);
  }
  FILE_BIN_Close(pstrtFileBinHandle->fp);
  //TODO need implement this function
#else
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  pstrtFileBinHandle->path = pPathFile;
  if (pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                  pstrtFileBinHandle->path, pstrtFileBinHandle->mode) != FR_OK)
  {
    return 0;
  }
  res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00, (uint8*) &strtHeader,
                             sizeof(strtHeader));
  if (res != FR_OK)
  {
    return 0;
  }
  //bKeySizeBk=strtHeader.bKeySize;
  uint8 strRam[255];
  if (eUseDTCLibrary == eTRUE)
  {
    strtHeader.bKeySize = KEY_SIZE_DTC_LIBRARY;
    //SizeCompare= KEY_SIZE_DTC_LIBRARY;
  }
  
  uint32 iAddrKey = gf_SYS_GetFirstKey(
                                       sizeof(strtHeader),    // Get first key
                                       strtHeader.iNumberLine, (uint8*) p_strtKeyInfo, strtHeader.bKeySize,
                                       strRam, strtHeader.bBaseSize, pstrtFileBinHandle);
  if (iAddrKey == _BST_NOT_FOUND_KEY_)
  {
    pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
    return 0;
  }
  else   // Get multi Address
  {
    do
    {
      //strtHeader.bKeySize=bKeySizeBk;
      if (gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                               iAddrKey,
                               (uint8*) &structDTCDefMappingAddr, strtHeader.bBaseSize)
          != FR_OK)
      {
        pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
        break;
      }
      else
      {
        iAddrKey = iAddrKey + strtHeader.bBaseSize;
        if (IsMainDTC == eTRUE)
        {
          iAddr = structDTCDefMappingAddr.iMainAddr;
        }
        else
        {
          iAddr = structDTCDefMappingAddr.iSubAddr;
        }
        if (gf_CheckDupplicateAddr(iAddr, pstrtListAddressDTC)  == eFALSE)
        {
#if SUPPORT_TOOL_F_BASIC_MX
          if ((p_strtKeyInfo->sManufacturer==emanufacturer_Toyota)&&(eUseDTCLibrary == eTRUE)
              &&(pPath[19]==0x31))
          {
            if ((structDTCDefMappingAddr.Key.sSystem!=esystem_SRS_____Airbag_Toyota)&&
                (structDTCDefMappingAddr.Key.sSystem!=esystem_ECM_Toyota)&&
                  (structDTCDefMappingAddr.Key.sSystem!=esystem_ABS_Toyota))
              goto TOYOTA_BASIC_MEXICO;
          }
#endif 
          pstrtListAddressDTC->ListItem[pstrtListAddressDTC->bNoItem] = iAddr;
          pstrtListAddressDTC->bNoItem++;
          if (pstrtListAddressDTC->bNoItem >= MAX_LIST_ADDRESS_DTC)
            break;
          //  if (p_strtKeyInfo->sManufacturer == emanufacturer_Mercedes_Benz) // Only get 1 Definition 
          //    break;
          //(aTienTran request get all Def 17Feb2016)
        }
      }
    TOYOTA_BASIC_MEXICO: 
      gf_SYS_Util_ReadFile(pstrtFileBinHandle, iAddrKey,
                           (uint8*) &strtReadKey, sizeof(structKeyInfo));
      if (memcmp(&strtReadKey, p_strtKeyInfo, strtHeader.bKeySize) != 0)
      {
        break;
      }
      iLineIdx++;
    }
    while (iLineIdx < strtHeader.iNumberLine);
  }
  
  pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
  return pstrtListAddressDTC->bNoItem;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: structDTCString*gf_DTC_GetSplitStrDTC(structListDTCType *pstrtListDTCType)
*Input        :
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang  11:32:53 AM
*
*
*
*
-------------------------------------------------------------------------------*/
structDTCString*gf_DTC_GetSplitStrDTC(structListDTCType *pstrtListDTCType)
{
  static structDTCString strtDTCString;
  memset(&strtDTCString, 0, sizeof(structDTCString));
  //A-B
  uint8 bLenDTC = strlen(pstrtListDTCType->bDTCString);
  uint8 bMainLen = 0;
  uint8 bSubLen = 0;
  for (int i = 0; i < bLenDTC; i++)
  {
    if (pstrtListDTCType->bDTCString[i] == '-')
    {
      i++;
      for (; i < bLenDTC; i++)
      {
        bSubLen++;
      }
    }
    else
    {
      bMainLen++;
    }
  }
  
  memcpy(strtDTCString.strDefMain, pstrtListDTCType->bDTCString, bMainLen);
  if (bSubLen > 0)
    memcpy(strtDTCString.strDefSub,
           &pstrtListDTCType->bDTCString[bMainLen + 1], bSubLen);
  
  return &strtDTCString;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: enumbool gf_DTC_IsHasSubCode(structDTCString*pstrtDTCString)
*Input        :
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang  11:40:09 AM
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_DTC_IsHasSubCode(structDTCString*pstrtDTCString)
{
  if (pstrtDTCString->strDefSub[0] > 0)
    return eTRUE;
  else
    return eFALSE;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_DTC_SeverityLevel 
*Input        : enumInnovaGroups eInnovaGroup, 
structListAddressDTC* pstrtListAddressDTC,
structListDTCType *pstrtListDTCType
*Output       : void
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
enumbool gf_DTC_SeverityLevel(enumInnovaGroups eInnovaGroup, 
                              structListAddressDTC* pstrtListAddressDTC,
                              structListDTCType *pstrtListDTCType)
{
  structSeverity strtSeverity;
  enumbool eResult = eFALSE;
  uint8 strRam[255];
  void *PathPatern = null;
  char bPath_Severity[50];
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  uint8 bNumFolderVersion;
  uint8* group;
  FRESULT res;
  structNwSHeader strtHeader;
  memset(&strtSeverity.StrDTC_Code,0,SIZE_MAINCODE);
  strtSeverity.bSeverity=0xFF;
  memcpy(&strtSeverity.StrDTC_Code,pstrtListDTCType->bDTCString,SIZE_MAINCODE);  
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  if (group == null)
    return eFALSE;
  pstrtListDTCType->bSeverity = 0xFF;
  if (eInnovaGroup == GROUP_N_A)
    bNumFolderVersion = VDM_NWDTC_GET_LIST_VERSION();
  else
    bNumFolderVersion = VDM_DTC_GET_LIST_VERSION();
  for (uint8 bIdxVersion = 0; bIdxVersion < bNumFolderVersion; bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    PathPatern = PATH_SEVERITY_DTC;      
    sprintf(bPath_Severity, PathPatern, group);
    pstrtFileBinHandle->path = bPath_Severity;
#ifdef  _MSC_VER
    FILE_BIN_Open(pstrtFileBinHandle->fp,
                  pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
    pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
    res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00,
                               (uint8*) &strtHeader, sizeof(strtHeader));
    if (res == FR_OK)
    {
      for (uint8 bNoItem = 0; bNoItem < pstrtListAddressDTC->bNoItem; bNoItem++)
      {
        strtSeverity.iAddress = pstrtListAddressDTC->ListItem[bNoItem];
        uint32 iAddrKey = gf_SYS_GetFirstKey(sizeof(strtHeader),    // Get first key
                                             strtHeader.iNumberLine, 
                                             (uint8*)&strtSeverity, 
                                             19,
                                             strRam, strtHeader.bBaseSize, pstrtFileBinHandle);
        if (iAddrKey != _BST_NOT_FOUND_KEY_)
        {
          gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                               iAddrKey,
                               (uint8*)&strtSeverity, 
                               sizeof(strtSeverity));
          if (pstrtListDTCType->bSeverity == 0xFF)
          {
            pstrtListDTCType->bSeverity= strtSeverity.bSeverity;
          }
          else 
          {
            if ((strtSeverity.bSeverity>pstrtListDTCType->bSeverity)&&(strtSeverity.bSeverity!=0xFF))
              pstrtListDTCType->bSeverity= strtSeverity.bSeverity;
          }
          eResult = eTRUE;
        }    
      }
    }
  }
#ifdef  _MSC_VER
  FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
  pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
  return eResult;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: static structListAddressDTC * gf_DTC_FindListID(enumInnovaGroups eInnovaGroup,
structKeyInfo *p_strtKeyInfo, structListAddressDTC* pstrtListAddressDTC,
enumbool IsMainDef)
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
structListAddressDTC * gf_DTC_FindListID(enumInnovaGroups eInnovaGroup,
                                         structKeyInfo *p_strtKeyInfo, 
                                         structListAddressDTC* pstrtListAddressDTC,
                                         enumbool IsMainDef)
{
  void *PathPatern = null;
  char bPath_dtc[50];
  if (pstrtListAddressDTC == Null)
    return null;
  pstrtListAddressDTC->bNoItem = 0;
  if(!IsMainDef)
  {
    pstrtListAddressDTC->IsHasDTCSub=eTRUE;
    pstrtListAddressDTC->IsFoundDTCSubID=eFALSE;
  }
  else
  {
    pstrtListAddressDTC->IsFoundDTC=eFALSE;
  }
  uint8 bNumFolderVersion;
  uint8* group;
  
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  if (group == null)
    return Null;
  if (eInnovaGroup == GROUP_N_A)
  {
    bNumFolderVersion = VDM_NWDTC_GET_LIST_VERSION();
  }
  else
  {
    bNumFolderVersion = VDM_DTC_GET_LIST_VERSION();
  }
  for (uint8 bIdxVersion = 0; bIdxVersion < bNumFolderVersion; bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    if (eInnovaGroup == GROUP_N_A)
    {
      if (IsMainDef)
        PathPatern = PATH_ALL_MAINDTC_BIN;
      else
      {
        if (p_strtKeyInfo->sManufacturer == emanufacturer_Mercedes_Benz) //Mercedes
          PathPatern = PATH_ALL_MAINDTC_BIN;
        else
          PathPatern = PATH_ALL_SUBDTC_BIN;
      }
    }
    else
    {
      if (IsMainDef)
        PathPatern = PATH_MAINDTC_BIN;
      else
      {
        if (p_strtKeyInfo->sManufacturer == emanufacturer_Mercedes_Benz) //Mercedes
          PathPatern = PATH_MAINDTC_BIN;
        else
          PathPatern = PATH_SUBDTC_BIN;
      }
    }
    
    
    sprintf(bPath_dtc, PathPatern, group);
    
    if (gf_GetListAddressDTC(pstrtListAddressDTC, p_strtKeyInfo, bPath_dtc,
                             eFALSE, IsMainDef) > 0)
    {
      break;
    }
  }
  if (pstrtListAddressDTC->bNoItem>0)
  {
    if(!IsMainDef)
    {
      pstrtListAddressDTC->IsFoundDTCSubID=eTRUE;
    }
    else
    {
      pstrtListAddressDTC->IsFoundDTC=eTRUE;
    }
    return pstrtListAddressDTC;
  }
  else
    return Null;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: uint16 gf_Get_DTC_Definiton(structListAddressDTC* pstrtListAddressDTC,
enumInnovaGroups eInnovaGroup, enumOBDLanguage eMemLanguage, char *pDef,
uint32 iDefSize, enumbool IsMainDTC)
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
uint16 gf_Get_DTC_Definition(structListAddressDTC* pstrtListAddressDTC,
                             enumInnovaGroups eInnovaGroup,
                             enumOBDLanguage eMemLanguage, char *pDef,
                             uint32 iDefSize,
                             enumbool IsMainDTC)
{
  uint8 bTotalLen_DTCLib=0,bLenDTCLib=0,bLenBuff_DTCLib=0;
  enumbool eDifferentDef;
  void *PathPatern = null;
  uint16 sLenDef = 0, sIndexLenDef=0;
  enumbool eUseDefaultLang=eFALSE;
#ifdef _MSC_VER
  HINSTANCE hinstLib;
  hinstLib = LoadLibrary(L"Encrypter");
  if (hinstLib != null)
  {
    VDS_aes_decrypt VDS_aes_decrypt_fp = (VDS_aes_decrypt)GetProcAddress(hinstLib, "VDS_aes_decrypt");
#endif	
    char bPath_dtc[50];
    char bPath_English_dtc[50];
    char bMainDTCDef[1024] = "";
    char strTempData[1024] = "";
    uint8 blanguage;
    
    structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
    structMappingAddress_DTC strtMappingAddress_DTC;
    uint8 bNumFolderVersion;
    uint8* group;
    uint8 NumDef = 0;
    FRESULT res;
    structNwSHeader strtHeader;
    blanguage = (uint8) eMemLanguage;
    group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
    if (group == null)
      return eFALSE;
    if (eInnovaGroup == GROUP_N_A)
      bNumFolderVersion = VDM_NWDTC_GET_LIST_VERSION();
    else
      bNumFolderVersion = VDM_DTC_GET_LIST_VERSION();
    for (uint8 bIdxVersion = 0; bIdxVersion < bNumFolderVersion; bIdxVersion++)
    {
      gf_VDM_DTCPathSetIdx(bIdxVersion);
      if (eInnovaGroup == GROUP_N_A)
      {
        if (IsMainDTC)
          PathPatern = PATH_ALL_M_DTC;
        else
          PathPatern = PATH_ALL_S_DTC;
      }
      else
      {
        if (IsMainDTC)
          PathPatern = PATH_M_DTC;
        else
          PathPatern = PATH_S_DTC;
      }
      sprintf(bPath_dtc, PathPatern, group, blanguage);
      sprintf(bPath_English_dtc, PathPatern, group, 1);
      pstrtFileBinHandle->path = bPath_dtc;
#ifdef  _MSC_VER
      FILE_BIN_Open(pstrtFileBinHandle->fp,
                    pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
      pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                  pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
      res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00,
                                 (uint8*) &strtHeader, sizeof(strtHeader));
      if (res == FR_OK)
      {
        for (uint8 bNoDtc = 0; bNoDtc < pstrtListAddressDTC->bNoItem; bNoDtc++)
        {
          eDifferentDef=eTRUE;
          memset(&strtMappingAddress_DTC, 0xFF,
                 sizeof(structMappingAddress_DTC));
          gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                               pstrtListAddressDTC->ListItem[bNoDtc],
                               (uint8*) &strtMappingAddress_DTC,
                               sizeof(structMappingAddress_DTC));
          if ((strtMappingAddress_DTC.iMappingAddr == 0xFFFFFFFF)&&
              (eMemLanguage!=eMEM_LANGUAGE_ENGLISH)) // Mix definition with other language
          {
            if (pstrtListAddressDTC->bNoItem>1)
            {
              eUseDefaultLang=eTRUE;
#ifdef  _MSC_VER
              FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
              pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
              pstrtFileBinHandle->path = bPath_English_dtc;
#ifdef  _MSC_VER
              FILE_BIN_Open(pstrtFileBinHandle->fp,
                            pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
              pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                          pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
              if (gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00,
                                       (uint8*) &strtHeader, sizeof(strtHeader))==FR_OK)
              {
                gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                                     pstrtListAddressDTC->ListItem[bNoDtc],
                                     (uint8*) &strtMappingAddress_DTC,
                                     sizeof(structMappingAddress_DTC));
              }
            }
          }
          else
          {
            eUseDefaultLang=eFALSE;
          }
          if (strtMappingAddress_DTC.iMappingAddr != 0xFFFFFFFF)
          {
            NumDef++;
            strtMappingAddress_DTC.sLen = MIN(strtMappingAddress_DTC.sLen, iDefSize);
            memset(bMainDTCDef, 0x00, strtMappingAddress_DTC.sLen + 1);
            memset(strTempData, 0x00, strtMappingAddress_DTC.sLen + 1);
            
            res = gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                                       strtMappingAddress_DTC.iMappingAddr,
                                       (uint8*) strTempData, strtMappingAddress_DTC.sLen);
            
            if (strtHeader.eEnEncrypt == eTRUE)
            {
#ifdef _MSC_VER
              VDS_aes_decrypt_fp(DTC_DEF_ALL_MAKE, strTempData,bMainDTCDef, strtMappingAddress_DTC.sLen);
#else
              VDS_aes_decrypt(DTC_DEF_ALL_MAKE, strTempData, bMainDTCDef, strtMappingAddress_DTC.sLen);
#endif
            }
            else
            {
              memcpy(bMainDTCDef,strTempData,strtMappingAddress_DTC.sLen);
            }
            if (sLenDef + strtMappingAddress_DTC.sLen > iDefSize)
              break;
            // Remove multidef in DTC OBDII Lib            
            if (pstrtListAddressDTC->strtListDef.eReadOBD2Lib==eTRUE)
            {
              if (pstrtListAddressDTC->strtListDef.bNumItem==0)
                bTotalLen_DTCLib=strtMappingAddress_DTC.sLen;
              else
              {
                bTotalLen_DTCLib = pstrtListAddressDTC->strtListDef.Len[pstrtListAddressDTC->strtListDef.bNumItem-1] 
                  + strtMappingAddress_DTC.sLen;
                sIndexLenDef=4*pstrtListAddressDTC->strtListDef.bNumItem +
                  pstrtListAddressDTC->strtListDef.Len[pstrtListAddressDTC->strtListDef.bNumItem-1];
                if (pstrtListAddressDTC->strtListDef.bNumItem==1)
                  sLenDef=4*pstrtListAddressDTC->strtListDef.bNumItem+pstrtListAddressDTC->strtListDef.Len[pstrtListAddressDTC->strtListDef.bNumItem-1];
              }
              pstrtListAddressDTC->strtListDef.Len[pstrtListAddressDTC->strtListDef.bNumItem]=bTotalLen_DTCLib;                                          
              for (uint8 bIndex=0;bIndex<pstrtListAddressDTC->strtListDef.bNumItem;bIndex++)
              {
                if (bIndex==0)
                {
                  bLenBuff_DTCLib=pstrtListAddressDTC->strtListDef.Len[bIndex]; 
                }
                else
                {
                  bLenDTCLib=pstrtListAddressDTC->strtListDef.Len[bIndex-1];
                  bLenBuff_DTCLib=pstrtListAddressDTC->strtListDef.Len[bIndex]-pstrtListAddressDTC->strtListDef.Len[bIndex-1]; 
                }
                if (strtMappingAddress_DTC.sLen==bLenBuff_DTCLib)
                {
                  if (memcmp(&pDef[3*(bIndex+1)+bIndex+bLenDTCLib]
                             ,bMainDTCDef,strtMappingAddress_DTC.sLen)==0)
                  {
                    pstrtListAddressDTC->strtListDef.Len[pstrtListAddressDTC->strtListDef.bNumItem]=0;
                    pstrtListAddressDTC->strtListDef.bNumItem--;
                    eDifferentDef=eFALSE;
                    break;
                  }
                }
              }
              pstrtListAddressDTC->strtListDef.bNumItem++; 
              if ((pstrtListAddressDTC->strtListDef.bNumItem!=0)&&(eDifferentDef))
              {
                if (pstrtListAddressDTC->strtListDef.bNumItem==1)
                  sLenDef=4*pstrtListAddressDTC->strtListDef.bNumItem+pstrtListAddressDTC->strtListDef.Len[pstrtListAddressDTC->strtListDef.bNumItem-1];
                else            
                  sLenDef=4*pstrtListAddressDTC->strtListDef.bNumItem + bTotalLen_DTCLib;
              }
              NumDef=pstrtListAddressDTC->strtListDef.bNumItem;
              if (eDifferentDef)
               sprintf(&pDef[sIndexLenDef], "%d. %s\n", NumDef,bMainDTCDef);
            }
            else
            // Remove multidef in DTC OBDII Lib
              sLenDef += sprintf(&pDef[sLenDef], "%d. %s\n", NumDef,bMainDTCDef);
            //strcat(p_MainDTCDefBuffer, bMainMultiDTCDef);
          }
          if (eUseDefaultLang==eTRUE)
          {
#ifdef  _MSC_VER
            FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
            pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
            pstrtFileBinHandle->path = bPath_dtc;
#ifdef  _MSC_VER
            FILE_BIN_Open(pstrtFileBinHandle->fp,
                          pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
            pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                        pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
          }
        }
        if (pstrtListAddressDTC->bNoItem > 0)
          break;
      }
      else
      {
#ifdef  _MSC_VER
        FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
        pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
        if (bIdxVersion == bNumFolderVersion-1)
          return 0;
      }
    }
    if (NumDef == 1)
    {
      if (pstrtListAddressDTC->strtListDef.eReadOBD2Lib!=eTRUE)     
      {
        if (sLenDef > 3)
        {
          gf_Util_ShiftLeftBuff(pDef, sLenDef, 3);
          sLenDef -= 3; //remove \n
        }
        else
        {
          sLenDef = 0;
        }
      }
    }
    if (sLenDef > 0) //Trim \n
    {
      if (pstrtListAddressDTC->strtListDef.eReadOBD2Lib!=eTRUE)
      {
        pDef[sLenDef] = 0;
        sLenDef--;
      }
    }
    if((sLenDef>0) && (sLenDef<0xFFFF))
    {
      if(!IsMainDTC)
      {
        pstrtListAddressDTC->IsFoundDTCSubDef=eTRUE;
      }
      else
      {
        pstrtListAddressDTC->IsFoundDTCMainDef=eTRUE;
      }
    }
#ifdef _MSC_VER
    FreeLibrary(hinstLib);
  }
#endif
  return sLenDef;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_DTC_GetListInnGroup
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
enumInnovagroup *gf_DTC_GetListInnGroup(structOemProfile *p_strtOemProfile)
{
  //	    einnovagroup_GROUP_ABS  = 2,
  //	    einnovagroup_GROUP_SRS  = 4,
  //	    einnovagroup_GROUP_ENH_TCM  = 8,
  //	    einnovagroup_GROUP_ENH_ECM  = 16,
  //	    einnovagroup_GROUP_ENH_PCM  = 16,
  static const enumInnovagroup listinngroupOBD1[2] = {
    einnovagroup_GROUP_OBDI, einnovagroup_UNKNOWN };
  static const enumInnovagroup listinngroupOBD2[2] = {
    einnovagroup_GROUP_OBDII, einnovagroup_UNKNOWN };
  static const enumInnovagroup listinngroup[6] = { einnovagroup_GROUP_ABS,
  einnovagroup_GROUP_SRS, einnovagroup_GROUP_ENH_PCM,
  DTC_GROUP_ALL,einnovagroup_INNOVA_GROUP_UNKNOW, einnovagroup_UNKNOWN };
  
  if (p_strtOemProfile->bSelInnGroup == einnovagroup_GROUP_OBDI)
    return  (enumInnovagroup *)listinngroupOBD1;
  else if (p_strtOemProfile->bSelInnGroup == einnovagroup_GROUP_OBDII)
    return  (enumInnovagroup *)listinngroupOBD2;
  else
    return (enumInnovagroup *) listinngroup;
}
