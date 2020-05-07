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
//#include <NWSCAN_APP/Adapter/Makes/Hyundai/NwS_Hyundai_Utility.h>

#pragma pack(1)
typedef struct _structSubSystemHuyndai
{
  enumSubSystem eRootSubSystem;
  enumSubSystem eSubSystemMapping;
} structSubSystemHuyndai;
#pragma pack()

const structSubSystemHuyndai strtSubSystemHuyndai[]=
{
  {esubsystem_4WD_TOD__Hyundai,esubsystem_4WD_Hyundai},
  {esubsystem_4WD_EST__Hyundai,esubsystem_4WD_Hyundai},
  {esubsystem_ABS_MGH_25__Hyundai,esubsystem_ABS_Hyundai},
  {esubsystem_ABS_MGH_40__Hyundai,esubsystem_ABS_Hyundai},
  {esubsystem_ABS_MEB_2__Hyundai,esubsystem_ABS_Hyundai},
  {esubsystem_AFLS_HID__Hyundai,esubsystem_AFLS_Hyundai},
  {esubsystem_AFLS_LED__Hyundai,esubsystem_AFLS_Hyundai},
  {esubsystem_AT__June1_1999__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT_June1_1999___Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT______Non_____SULEV__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT______SULEV__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT_4Speed__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT_5Speed__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT_W_ISG__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_AT_DTC__Hyundai,esubsystem_AT_Hyundai},
  {esubsystem_BCM_5DR__Hyundai,esubsystem_BCM_Hyundai},
  {esubsystem_BCM_Koup__Hyundai,esubsystem_BCM_Hyundai},
  {esubsystem_ECM_Non_____SULEV__Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_ECM_SULEV__Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_ECM_______January1_2003__Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_ECM______January1_2003___Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_ECM______A_T__Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_ECM______M_T__Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_ECM_Ulev__Hyundai,esubsystem_ECM_Hyundai},
  {esubsystem_EPS__Sep232011__Hyundai,esubsystem_EPS_Hyundai},
  {esubsystem_EPS_Sep242011___Hyundai,esubsystem_EPS_Hyundai},
  {esubsystem_ESC_MEB_2__Hyundai,esubsystem_ESC_Hyundai},
  {esubsystem_IPM_W_O_____PIC__Hyundai,esubsystem_IPM_Hyundai},
  {esubsystem_IPM_W_PIC__Hyundai,esubsystem_IPM_Hyundai},
  {esubsystem_PDM______W______ESCL__Hyundai,esubsystem_PDM_Hyundai},
  {esubsystem_PDM______W_O_____ESCL__Hyundai,esubsystem_PDM_Hyundai},
  {esubsystem_SKU______W______ESCL__Hyundai,esubsystem_SKU_Hyundai},
  {esubsystem_SKU______W_O_____ESCL__Hyundai,esubsystem_SKU_Hyundai},
  {esubsystem_PSB_L_Hyundai,esubsystem_PSB___________L_Hyundai},
  {esubsystem_PSB_R_Hyundai,esubsystem_PSB___________R_Hyundai},
  {esubsystem_PSD_LH_Hyundai,esubsystem_PSD___________LH_Hyundai},
  {esubsystem_PSD_RH_Hyundai,esubsystem_PSD___________RH_Hyundai},
  {0xFFFF,0xFFFF},
};
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __GetSubSystem
*Input        : enumSystem System
*Output       : enumSystem
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
static enumSubSystem __GetSubSystem(enumSubSystem eSubSystem)
{
  uint16 sIdxMapping=0;
  while(strtSubSystemHuyndai[sIdxMapping].eRootSubSystem!=0xFFFF) 
  {
    if(strtSubSystemHuyndai[sIdxMapping].eRootSubSystem==eSubSystem)
      return strtSubSystemHuyndai[sIdxMapping].eSubSystemMapping;
    sIdxMapping++;
  }
  return eSubSystem;
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
                             structOemProfile *p_strtOemProfile,
                             structListDTCType *pstrtListDTCType,
                             structKeyInfo *p_strtKeyInfo)
{
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  
#if HYUNDAI_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eMake;
  }
#endif
#if HYUNDAI_use_sSystem
  {    
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if HYUNDAI_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = __GetSubSystem(p_strtOemProfile->sSubSystem);
  }   
#endif
  
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_HUYNDAI_Adapter_DTC_GetDef
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
uint32 gf_HYUNDAI_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                     structOemProfile *p_strtOemProfile,
                                     enumOBDLanguage eMemLanguage,
                                     structListDTCType *pstrtListDTCType,
                                     void *pDef,
                                     uint32 iDefSize,
                                     structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  uint32 iLenDef = 0;
  structDTCString *pstrtDTCString;
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
  //structListAddressDTC strtListAddressDTC;
  enumInnovagroup *pListInnGroup;
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
    pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup, &strtKeyInfo,
                                            pstrtListAddrDTC, eTRUE);
  
    if (pstrtListAddressDTC != Null)
    {
      return gf_Get_DTC_Definition(pstrtListAddressDTC, eInnovaGroup,
                                  eMemLanguage, pDef, iDefSize, eTRUE);
    }
    bIdxGroup++;
  }
  pstrtDTCString = gf_DTC_GetSplitStrDTC(pstrtListDTCType);
  memset(strtKeyInfo.bMainDTCString,0,SIZE_MAINCODE);
  strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefMain);
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  bIdxGroup = 0;
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
