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
#if SUZUKI_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if SUZUKI_use_sSystem
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if SUZUKI_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
  }
#endif
#if SUZUKI_use_sProtocol
  {
    if (p_strtOemProfile->Protocol == eprotocol_PROTOCOL_GMLAN )
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
uint32 gf_SUZUKI_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                    structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                                    structListDTCType *pstrtListDTCType, 
                                    void *pDef, 
                                    uint32 iDefSize,
                                    structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
  uint32 iLenDef = 0;
  enumInnovaGroups eInnovaGroup;
  enumManufacturer eManufacture;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
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
  // strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefMain);  
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    for (uint8 binDex=0; binDex<2;binDex++)
    {
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      if (binDex==0)
        memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString, 
               strlen(pstrtListDTCType->bDTCString));
      else if (binDex==1)
        strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefMain);
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
  return iLenDef;
}
