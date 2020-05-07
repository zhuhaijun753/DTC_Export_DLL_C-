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
//#include <NWSCAN_APP/Adapter/Makes/Volvo/NwS_Volvo_Utility.h>
#pragma pack(1)
typedef struct _structECUDefault
{
  uint8 bYear;
  uint16 sManufacture;
  uint16 sModel;
  uint16 sOption1;
  uint16 sSystem;
  uint16 sProtocol;
  uint16 sOption3;
} structECUDefault;
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
  structOemInfo_Volvo *pstrtVolvoEcuID;
  pstrtVolvoEcuID = (structOemInfo_Volvo *) p_strtOemProfile->OemInfo;
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  
#if VOLVO_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
  if (p_strtOemProfile->Protocol == PROTOCOL_KW)
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
    p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
  }
  else
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
    p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
    if (pstrtVolvoEcuID->bStatus == 0xAA)
      p_strtKeyInfo->sOption3 = pstrtVolvoEcuID->sECUID_Value;
    
  }
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __GetEcuDefault
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static uint16 __GetEcuDefault(structMFRVinProfile * p_strtMFRVinProfile,
                              structOemProfile *p_strtOemProfile)
{
  structECUDefault strtECUDefault;
  uint8 strRam[sizeof(structECUDefault)*3];
  strtECUDefault.sOption3=0xFFFF;
  uint32 iAddr;
  structNwSHeader strtHeader;
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  FRESULT res;
  uint8 bNumFolderVersion = VDM_ECU_VOLVO_GET_LIST_VERSION();
  for (uint8 bIdxVersion = 0; bIdxVersion < bNumFolderVersion; bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    //sprintf(bPath_ecuID_bin, PATH_OK_VOLVO_ECUID_DEFAULT);
    pstrtFileBinHandle->path = PATH_OK_VOLVO_ECUID_DEFAULT;
#ifdef  _MSC_VER
    FILE_BIN_Open(pstrtFileBinHandle->fp,
                  pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
    pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
    
    strtECUDefault.bYear = p_strtMFRVinProfile->eYear;
    strtECUDefault.sManufacture = p_strtMFRVinProfile->eManufacturer;
    strtECUDefault.sModel = p_strtMFRVinProfile->eModel;
    strtECUDefault.sOption1 = p_strtMFRVinProfile->eEngine;
    strtECUDefault.sSystem = p_strtOemProfile->sSystem;
    strtECUDefault.sProtocol = p_strtOemProfile->Protocol;
    
    res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00, (uint8*) &strtHeader,
                               sizeof(strtHeader));
    if (res == FR_OK)
    {
      iAddr = gf_SYS_GetFirstKey(sizeof(strtHeader),
                                 strtHeader.iNumberLine, 
                                 (uint8*) &strtECUDefault,
                                 strtHeader.bKeySize,
                                 strRam, 
                                 strtHeader.bBaseSize,
                                 pstrtFileBinHandle);
      while (iAddr != _BST_NOT_FOUND_KEY_)
      {
        if (gf_SYS_Util_ReadFile(pstrtFileBinHandle,
                                 iAddr, &strtECUDefault, sizeof(structECUDefault)) == FR_OK)
        {
#ifdef  _MSC_VER
          FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
          pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
          return strtECUDefault.sOption3;
        }
      }
    }
#ifdef  _MSC_VER
    FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
    pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
  }
  return strtECUDefault.sOption3;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VOLVO_Adapter_DTC_GetDef
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
uint32 gf_VOLVO_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                   structOemProfile *p_strtOemProfile,
                                   enumOBDLanguage eMemLanguage,
                                   structListDTCType *pstrtListDTCType,
                                   void *pDef,
                                   uint32 iDefSize,
                                   structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC=null;
  uint32 iLenDef = 0;
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
  enumInnovagroup *pListInnGroup;
  //structListAddressDTC strtListAddressDTC;
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
  
  
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, 
                                            &strtKeyInfo,
                                            pstrtListAddrDTC, 
                                            eTRUE);
    
    if (pstrtListAddressDTC != Null)
    {
      return gf_Get_DTC_Definition(pstrtListAddressDTC, 
                                   eInnovaGroup,
                                   eMemLanguage, 
                                   pDef, 
                                   iDefSize, 
                                   eTRUE);
    }
    bIdxGroup++;
  }
  
  if (pstrtListAddressDTC == Null)
  {
    pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
    uint8 bIdxGroup = 0;
    while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
    {
      eInnovaGroup = pListInnGroup[bIdxGroup];
      strtKeyInfo.sOption3=__GetEcuDefault(p_strtMFRVinProfile,
                                           p_strtOemProfile);
      pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, 
                                              &strtKeyInfo,
                                              pstrtListAddrDTC, 
                                              eTRUE);
      
      if (pstrtListAddressDTC != Null)
      {
        return gf_Get_DTC_Definition(pstrtListAddressDTC, 
                                     eInnovaGroup,
                                     eMemLanguage, 
                                     pDef, 
                                     iDefSize, 
                                     eTRUE);
      }
      bIdxGroup++;
    }
  }
  return iLenDef;
}
