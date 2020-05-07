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
//#include <NWSCAN_APP/Adapter/Makes/Honda/NwS_Honda_Utility.h>
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
  structOemInfo_Honda *pstrtecuinfo;
  pstrtecuinfo = (structOemInfo_Honda *) p_strtOemProfile->OemInfo;
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  
#if HONDA_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if HONDA_use_sModel
  {  
    if (p_strtMFRVinProfile->eModel==emodel_Passport_Honda)
      p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
  }
#endif
#if HONDA_use_sSystem
  { 
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if HONDA_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
  }
#endif
#if HONDA_use_sProtocol
  {
    if ((p_strtOemProfile->Protocol == PROTOCOL_VPW)||(p_strtOemProfile->Protocol == PROTOCOL_ALDL))     
      p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
  }   
#endif	  
  if (pstrtecuinfo->bStatus == 0xAA)
  {
    p_strtKeyInfo->sOption3 = pstrtecuinfo->eECUTYpe;
  }
  else
  {
    if (p_strtOemProfile->sSystem==esystem_BODY_____ELECTRICAL_Honda)
      p_strtKeyInfo->sOption3 = pstrtListDTCType->sDTCTypeList[0];
  }
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_HONDA_Adapter_DTC_GetDef
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
uint32 gf_HONDA_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                   structOemProfile *p_strtOemProfile,
                                   enumOBDLanguage eMemLanguage,
                                   structListDTCType *pstrtListDTCType,
                                   void *pDef,
                                   uint32 iDefSize,
                                   structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  uint8 bNumLoop = 2;
  uint32 iLenDef = 0;
  //uint8 bCheckgroup = 0;
  enumSystem eListSubsystem[2];
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  eListSubsystem[0] = p_strtOemProfile->sSubSystem;
  eListSubsystem[1] = eSubSystem_MAX;
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
    for (uint8 bIdxSystem=0;bIdxSystem<bNumLoop;bIdxSystem++)
    {
      strtKeyInfo.sSubSystem=eListSubsystem[bIdxSystem];
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
    }
    bIdxGroup++;
  }
  return iLenDef;
}
