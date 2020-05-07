/*
* GM_Adapter_DtcDef.c
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
  if ((p_strtMFRVinProfile->eManufacturer==emanufacturer_Opel)||
      (p_strtMFRVinProfile->eManufacturer==emanufacturer_Daewoo))
    p_strtKeySubInfo->sManufacturer=emanufacturer_GM;
  else
    p_strtKeySubInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  if (p_strtOemProfile->Protocol == PROTOCOL_KW)
    p_strtKeySubInfo->bProtocol = PROTOCOL_KW2000;
  else if ((p_strtOemProfile->Protocol == PROTOCOL_GMLAN)
           || (p_strtOemProfile->Protocol == PROTOCOL_SWCAN))
    p_strtKeySubInfo->bProtocol = PROTOCOL_CAN;
  else
    p_strtKeySubInfo->bProtocol = p_strtOemProfile->Protocol;
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
  if (p_strtOemProfile->Protocol == PROTOCOL_ALDL)
  {
    p_strtKeyInfo->bYear = p_strtMFRVinProfile->eYear;
    p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
    p_strtKeyInfo->sOption1 = p_strtMFRVinProfile->eMake;
    if (p_strtOemProfile->sSystem == esystem_Powertrain_GM)
      p_strtKeyInfo->sOption2 = p_strtMFRVinProfile->eEngine;
  }
#if GM_use_sManufacturer
  {
   if ((p_strtMFRVinProfile->eManufacturer==emanufacturer_Opel)||
      (p_strtMFRVinProfile->eManufacturer==emanufacturer_Daewoo))
    p_strtKeyInfo->sManufacturer=emanufacturer_GM;
   else
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if GM_use_sModel
  {
    if ((p_strtMFRVinProfile->eManufacturer == emanufacturer_GM)
        && (p_strtMFRVinProfile->eModel == emodel_Vibe_GM))
    {
      p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
    }
  }
#endif
#if GM_use_sSystem
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if GM_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
  }
#endif
#if GM_use_sProtocol
  {
    if (p_strtOemProfile->Protocol == PROTOCOL_KW)
      p_strtKeyInfo->bProtocol = PROTOCOL_KW2000;
    else if ((p_strtOemProfile->Protocol == PROTOCOL_GMLAN)
             || (p_strtOemProfile->Protocol == PROTOCOL_SWCAN))
      p_strtKeyInfo->bProtocol = PROTOCOL_CAN;
    else
      p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
  }
#endif
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_GM_Adapter_DTC_GetDef
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
uint32 gf_GM_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                structListDTCType *pstrtListDTCType, void *pDefOut, uint32 iDefSize,structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC=null;
  char*pDef = (char*) pDefOut;
  uint32 iLenDef = 0;
  enumInnovagroup *pListInnGroup;
  structDTCString *pstrtDTCString;
  uint32 iTemp;
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
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
  
  pstrtDTCString = gf_DTC_GetSplitStrDTC(pstrtListDTCType);
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    
    //strtKeyInfo.bProtocol = p_strtOemProfile->Protocol;
    pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, &strtKeyInfo,
                                            pstrtListAddrDTC, eTRUE);
    
    if (pstrtListAddressDTC != Null)
    {
      return gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                  eMemLanguage, pDef, iDefSize, eTRUE);
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
        //strtKeyInfo.bProtocol = p_strtOemProfile->Protocol;
        
        pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup,
						&strtKeyInfo, pstrtListAddrDTC, eTRUE);
        if (pstrtListAddressDTC != null)
        {
          iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC,
                                         eInnovaGroup, eMemLanguage, pDef, iDefSize, eTRUE);
          break;
        }
        if (pstrtListAddressDTC != null)
          break;
        else
          bIdxGroup++;
      }
      if (pstrtListAddressDTC == null) //If not found Main def , will ignore sub def also
      {
        return 0;
      }
      
      ///Found sub def
//#warning need to remove when update database      
      if (pstrtDTCString->strDefSub[0]==0x30&&pstrtDTCString->strDefSub[1]==0x30)
      {
        return iLenDef;
      }
      __DTC_YmmeSubSearch(p_strtMFRVinProfile, p_strtOemProfile,
                          &strtKeyInfo);
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefSub);
      pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
      bIdxGroup = 0;
      while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
      {
        
        //strtKeyInfo.bProtocol = p_strtOemProfile->Protocol;
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
        bIdxGroup++;
      }
    }
  }
  return iLenDef;
}

