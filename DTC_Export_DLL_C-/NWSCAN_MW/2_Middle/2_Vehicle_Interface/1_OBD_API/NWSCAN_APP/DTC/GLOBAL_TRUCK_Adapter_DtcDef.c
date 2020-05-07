/*
* GM_Adapter_DtcDef.c
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
  
#if TRUCK_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
#if TRUCK_use_sModel
  {
    p_strtKeyInfo->sModel = p_strtMFRVinProfile->eModel;
  }
#endif
#if TRUCK_use_sSystem
  {
    p_strtKeyInfo->sSystem = p_strtOemProfile->sSystem;
  }
#endif
#if TRUCK_use_sSubSystem
  {
    p_strtKeyInfo->sSubSystem = p_strtOemProfile->sSubSystem;
  }
#endif
#if TRUCK_use_sProtocol
  {
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
uint32 gf_GLOBAL_TRUCK_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                          structOemProfile *p_strtOemProfile, 
                                          enumOBDLanguage eMemLanguage,
                                          structListDTCType *pstrtListDTCType, 
                                          void *pDefOut, 
                                          uint32 iDefSize,
                                          structListAddressDTC* pstrtListAddrDTC)

{
  uint8 bNumloop = 2;
  structListAddressDTC* pstrtListAddressDTC=null;
  char*pDef = (char*) pDefOut;
  uint32 iLenDef = 0;
  enumInnovagroup *pListInnGroup;
  structDTCString *pstrtDTCString;
  uint32 iTemp;
  enumInnovaGroups eInnovaGroup;
  eInnovaGroup = p_strtOemProfile->bSelInnGroup;
  structKeyInfo strtKeyInfo;
  enumSystem eListSystem[2];
  eListSystem[0] = p_strtOemProfile->sSystem;
  eListSystem[1] = 0xFFFF;
  if (eMemLanguage == 0)
    eMemLanguage = eMEM_LANGUAGE_ENGLISH;               //Default language
  if (pDef == null)
    return 0;
  else
    ((uint8*) pDef)[0] = 0;
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  __DTC_YmmeSearch(p_strtMFRVinProfile, p_strtOemProfile,
                   pstrtListDTCType, &strtKeyInfo);
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString,
         strlen(pstrtListDTCType->bDTCString));
  
  pstrtDTCString = gf_DTC_GetSplitStrDTC(pstrtListDTCType);
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    for (uint8 i =0; i < bNumloop; i++)
    {
      strtKeyInfo.sSystem = eListSystem[i]; 
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
        for (uint8 i =0; i < bNumloop; i++)
        {
          strtKeyInfo.sSystem = eListSystem[i]; 
          pstrtListAddressDTC = gf_DTC_FindListID(eInnovaGroup,
                                                  &strtKeyInfo, pstrtListAddrDTC, eTRUE);
          
          if (pstrtListAddressDTC != null)
          {
            iLenDef = gf_Get_DTC_Definition(pstrtListAddressDTC,
                                            eInnovaGroup, eMemLanguage, pDef, iDefSize, eTRUE);
            break;
          }
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
      __DTC_YmmeSearch(p_strtMFRVinProfile, p_strtOemProfile,
                       pstrtListDTCType, &strtKeyInfo);
      memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
      strcpy(strtKeyInfo.bMainDTCString, pstrtDTCString->strDefSub);
      pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
      bIdxGroup = 0;
      while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
      {
        eInnovaGroup = pListInnGroup[bIdxGroup];
        for (uint8 i =0; i < bNumloop; i++)
        {
          strtKeyInfo.sSystem = eListSystem[i]; 
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

