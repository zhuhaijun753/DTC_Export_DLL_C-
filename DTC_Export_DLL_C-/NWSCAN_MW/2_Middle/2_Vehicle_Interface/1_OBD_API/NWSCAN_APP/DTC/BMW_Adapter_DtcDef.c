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
//#include <NWSCAN_APP/Adapter/Makes/BMW/NwS_Bmw_Utility.h>
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
  structOemInfo_Bmw *pstrtBmwEcuInfo;
  pstrtBmwEcuInfo = (structOemInfo_Bmw *) p_strtOemProfile->OemInfo;
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
#if BMW_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if BMW_use_sModel
  {
    p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
  }
#endif
#if BMW_use_sSystem
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
  if (pstrtBmwEcuInfo->eStatus == VALID_CODE)
    p_strtKeyInfo->sOption4 = pstrtBmwEcuInfo->strtDTCVarProfile.eVariant;
#if BMW_use_sSubSystem
    {
      p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
    }
#endif
#if BMW_use_sProtocol
    {
      p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
    }
#endif
    p_strtKeyInfo->sOption3 = pstrtBmwEcuInfo->strtDTCVarProfile.eMsgID;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_BMW_Adapter_DTC_GetDef
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
uint32 gf_BMW_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                 structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                 structListDTCType *pstrtListDTCType, void *pDef, uint32 iDefSize,structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  uint32 iLenDef = 0;
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  enumInnovagroup *pListInnGroup;
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
