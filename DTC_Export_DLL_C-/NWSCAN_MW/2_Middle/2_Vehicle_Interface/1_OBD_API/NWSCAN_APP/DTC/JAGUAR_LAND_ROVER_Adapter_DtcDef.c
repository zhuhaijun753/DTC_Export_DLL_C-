/*
* Default_Adapter_DtcDef.c
*
*  Created on: Jul 29, 2015
*      Author: Lap Dang
*/

#include "NWSCAN_APP\LIB\PlatFormType.h"
#include "NWSCAN_APP\DTC\DTC_Config.h"
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include "NWSCAN_APP\MW_LIB\Makes_Adapter_App.h"
#include <2_Middle\0_Middle_Utilities\AES\aes256.h>
#include "DTCDefinition.h"
#include "DTCUtilities.h"
#include <stdlib.h>
#include "DTCDefinitionConfig.h"

#define MAX_SUBSYSTEM_LIST	2
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
#if JAGUAR_LAND_ROVER_use_bYear
  {
    p_strtKeyInfo->bYear=p_strtMFRVinProfile->eYear;
  }
#endif
#if JAGUAR_LAND_ROVER_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if JAGUAR_LAND_ROVER_use_sModel
  {
    p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
  }
#endif
#if JAGUAR_LAND_ROVER_use_sSystem
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if JAGUAR_LAND_ROVER_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
  }
#endif
#if JAGUAR_LAND_ROVER_use_sProtocol
  {
    p_strtKeyInfo->bProtocol = p_strtOemProfile->Protocol;
  }
#endif	
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_FIAT_Adapter_DTC_GetDef
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
uint32 gf_JAGUAR_LAND_ROVER_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                               structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                               structListDTCType *pstrtListDTCType, 
                                               void *pDef, 
                                               uint32 iDefSize,
                                               structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  uint32 iLenDef = 0;
  uint16 sListModel[2];
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  sListModel[0]= p_strtMFRVinProfile->eModel;
  sListModel[1]=0xFFFF;
  enumInnovagroup *pListInnGroup;
  structDTCString *pstrtDTCString;
  structKeyInfo strtKeyInfo;
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;               //Default language
  if (pDef == null)
    return 0;
  else
    ((uint8*) pDef)[0] = 0;
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  pstrtDTCString = gf_DTC_GetSplitStrDTC(pstrtListDTCType);                                             
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
  strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefMain);  
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    for (uint8 i = 0; i < 2; i++)
    {
      strtKeyInfo.sModel = sListModel[i];
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
        for (uint8 i = 0; i < 2; i++)
        {
          strtKeyInfo.sModel = sListModel[i];
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
    }
  }
  return iLenDef;
}
