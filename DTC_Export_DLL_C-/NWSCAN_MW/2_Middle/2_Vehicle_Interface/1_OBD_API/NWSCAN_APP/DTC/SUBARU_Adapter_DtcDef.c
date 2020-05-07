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

#if  !_MSC_VER
extern uint8 gf_VDM_OemProfileDtcGetOffSetDtcFrame(structOemProfile * p_strtOemProfile);
#endif
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
                             structKeyInfo *p_strtKeyInfo,
                             uint8 bIndexLoop)
{
  // memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  uint8 DTCSubInfo[4];
  uint8 bOffSet=0;
  uint8 bIndex=0;
  memset(&DTCSubInfo, 0, sizeof(DTCSubInfo));
#if SUBARU_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }
#endif
  p_strtKeyInfo->sOption3 = p_strtOemProfile->iProfileID;
  //gf_VDM_OemProfileDtcGetOffSetDtcFrame(p_strtOemProfile);
  bOffSet = p_strtOemProfile->strtOEMDTCBuffer.bOffSetRawDtc;
  bIndex = (pstrtListDTCType->bDTCIndex)*(p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc + 1); //1:Byte status
  if (bOffSet!=0)
  {
    if ((p_strtOemProfile->strtOEMDTCBuffer.DTC[bIndex]!=0)||
        (p_strtOemProfile->strtOEMDTCBuffer.DTC[bIndex+1]!=0))
    {
      DTCSubInfo[1]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bIndex+1]/0x10+0x30;
      DTCSubInfo[0]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bIndex+1]%0x10+0x30;
      DTCSubInfo[3]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bIndex]/0x10+0x30;
      DTCSubInfo[2]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bIndex]%0x10+0x30;
      if (bIndexLoop==1)
        DTCSubInfo[3]=0x2A;
      if (bIndexLoop==2)
      {
        DTCSubInfo[3]=0x2A;
        DTCSubInfo[4]=0x2A;
      }
      memcpy(&p_strtKeyInfo->sOption2,&DTCSubInfo,4); 
    }
  }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_SUBARU_Adapter_DTC_GetDef
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
uint32 gf_SUBARU_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                    structOemProfile *p_strtOemProfile,
                                    enumOBDLanguage eMemLanguage,
                                    structListDTCType *pstrtListDTCType,
                                    void *pDef,
                                    uint32 iDefSize,
                                    structListAddressDTC* pstrtListAddrDTC)

{
  structListAddressDTC* pstrtListAddressDTC;
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
  //  __DTC_YmmeSearch(p_strtMFRVinProfile,
  //                   p_strtOemProfile,
  //                   pstrtListDTCType,
  //                   &strtKeyInfo);  
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString, strlen(pstrtListDTCType->bDTCString));
  
  pListInnGroup = gf_DTC_GetListInnGroup(p_strtOemProfile);
  uint8 bIdxGroup = 0;
  while (pListInnGroup[bIdxGroup] != einnovagroup_UNKNOWN)
  {
    eInnovaGroup = pListInnGroup[bIdxGroup];
    for (uint8 bIndexLoop=0;bIndexLoop<3;bIndexLoop++)
    { 
      __DTC_YmmeSearch(p_strtMFRVinProfile,
                       p_strtOemProfile,
                       pstrtListDTCType,
                       &strtKeyInfo,
                       bIndexLoop);
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
