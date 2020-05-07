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

extern structVehicleProfile* gf_VDM_GetVehicleProfile(void);

#pragma pack(1)
typedef struct _structMessagToyota
{
  uint8 bInnovaGroup;
  enumProtocol eProtocol;
  uint32  iBaudrate;
  uint16 sMessageId;
} structMessagToyota;
#pragma pack()
typedef struct _structToyotaMesg
{
  uint16 sListMessageId[2];
  uint8 bNumItem;
} structToyotaMesg;
const structMessagToyota strtMessagToyota[] = 
{ 
  { einnovagroup_GROUP_ABS,eprotocol_PROTOCOL_KW2000,9600 ,emessageid_8_Toyota },  
  { einnovagroup_GROUP_ABS, eprotocol_PROTOCOL_CAN,500 , emessageid_105_Toyota},
  
  { einnovagroup_GROUP_ENH_ECM, eprotocol_PROTOCOL_ISO9141,10400 , emessageid_1_Toyota}, 
  { einnovagroup_GROUP_ENH_ECM, eprotocol_PROTOCOL_VPW,10400 , emessageid_1_Toyota},
  { einnovagroup_GROUP_ENH_ECM,eprotocol_PROTOCOL_KW2000,9600 , emessageid_1_Toyota},  
  { einnovagroup_GROUP_ENH_ECM, eprotocol_PROTOCOL_KW2000,10400 , emessageid_61_Toyota},
  { einnovagroup_GROUP_ENH_ECM, eprotocol_PROTOCOL_CAN ,500 ,emessageid_61_Toyota},
  { einnovagroup_GROUP_ENH_ECM, eprotocol_PROTOCOL_CAN ,500 ,emessageid_234_Toyota},
  
  { einnovagroup_GROUP_SRS, eprotocol_PROTOCOL_KW2000 ,9600 ,emessageid_15_Toyota},
  { einnovagroup_GROUP_SRS, eprotocol_PROTOCOL_KW2000, 10400, emessageid_63_Toyota }, 
  { einnovagroup_GROUP_SRS,eprotocol_PROTOCOL_CAN ,500 ,emessageid_188_Toyota}, 
  { einnovagroup_INNOVA_GROUP_UNKNOW,0xFFFF ,0 ,0xFFFF}, 
};
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
static structToyotaMesg* __MappingMessageId(structOemProfile *p_strtOemProfile)
{
  structToyotaMesg strtToyotaMesg;
  strtToyotaMesg.bNumItem=0;
  uint16 sInnovaGroup=p_strtOemProfile->bSelInnGroup;
  uint8 sIdxMapping = 0;
  if (sInnovaGroup==einnovagroup_GROUP_ENH_TCM)
    sInnovaGroup=einnovagroup_GROUP_ENH_ECM;
  while (strtMessagToyota[sIdxMapping].bInnovaGroup != einnovagroup_INNOVA_GROUP_UNKNOW)
  { 
    if (strtMessagToyota[sIdxMapping].bInnovaGroup==sInnovaGroup)
    {
      if (strtMessagToyota[sIdxMapping].eProtocol == p_strtOemProfile->Protocol)
      {
        if (strtMessagToyota[sIdxMapping].iBaudrate == p_strtOemProfile->iLinkedBaudRate)
        {
          strtToyotaMesg.sListMessageId[strtToyotaMesg.bNumItem] = strtMessagToyota[sIdxMapping].sMessageId;
          strtToyotaMesg.bNumItem++;
          if (strtToyotaMesg.bNumItem==3) //max item
            break;
        }     
      }
    }
    if (strtToyotaMesg.bNumItem!=0)
      break;
    sIdxMapping++;
  }
  return &strtToyotaMesg;
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
  structToyotaMesg *pstrtToyotaMesg;
  pstrtToyotaMesg = __MappingMessageId(p_strtOemProfile);
  memset(p_strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  structOemInfo_Toyota *pstrtOemInfo_Toyota;
  pstrtOemInfo_Toyota = (structOemInfo_Toyota*) p_strtOemProfile->OemInfo;
#if TOYOTA_use_sManufacturer
  {
    p_strtKeyInfo->sManufacturer = p_strtMFRVinProfile->eManufacturer;
  }  
#endif
#if SUPPORTED_TOOL_3100J
  p_strtKeyInfo->sOption3 = pstrtToyotaMesg->sListMessageId[0];
#else
  p_strtKeyInfo->sOption3 = p_strtOemProfile->iProfileID;
#endif  
  if (pstrtOemInfo_Toyota->eStatus == VALID_CODE)
    p_strtKeyInfo->sOption4 = pstrtOemInfo_Toyota->eType;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_TOYOTA_Adapter_DTC_GetDef
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
uint32 gf_TOYOTA_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                    structOemProfile *p_strtOemProfile,
                                    enumOBDLanguage eMemLanguage,
                                    structListDTCType *pstrtListDTCType,
                                    void *pDef,
                                    uint32 iDefSize,
                                    structListAddressDTC* pstrtListAddrDTC)

{
  structOemInfo_Toyota *pstrtOemInfo_Toyota;
  pstrtOemInfo_Toyota = (structOemInfo_Toyota*) p_strtOemProfile->OemInfo;
  structListAddressDTC* pstrtListAddressDTC;
  uint32 iLenDef = 0;
  uint8 bNumLoop = 1;
  enumInnovaGroups eInnovaGroup;
  enumSystem eListECUType[2];
  enumManufacturer eManufacture;
  eManufacture = p_strtMFRVinProfile->eManufacturer;
  structKeyInfo strtKeyInfo;
  enumInnovagroup *pListInnGroup;
  if (pstrtOemInfo_Toyota->eStatus == VALID_CODE)
  {
    bNumLoop=2;
    eListECUType[0] = pstrtOemInfo_Toyota->eType;
    eListECUType[1] = 0xFFFF; 
  }
  else
    eListECUType[0] = 0xFFFF;
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
    strtKeyInfo.sOption3 = p_strtOemProfile->iProfileID;
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
    for (uint8 i=0; i<bNumLoop;i++)
    {
      strtKeyInfo.sOption4 =  eListECUType[i];
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
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: __HasCodeDTC

*Input        :
*Output       :
-------------------------------------------------------------------------------*/
static enumbool __HasCodeDTC(structKeyInfo *pstrtKeyFilterInfo,
                             enumInnovaGroups eInnovaGroup)
{
  enumbool eResult = eFALSE;
  char bPath_maindtc_bin[50];
  uint8* group;
  uint8 bNumFolderVersion;
  uint32 iAddrKey;
  FRESULT res;
  structNwSHeader strtHeader;
  structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
  group = __DtcGetMappingString(eInnovaGroup, ROM_dtcinfo_inngrp_map);
  if (eInnovaGroup==GROUP_N_A)
    bNumFolderVersion=VDM_NWDTC_GET_LIST_VERSION();
  else
    bNumFolderVersion=VDM_DTC_GET_LIST_VERSION();
  for(uint8 bIdxVersion =0;bIdxVersion<bNumFolderVersion;bIdxVersion++)
  {
    gf_VDM_DTCPathSetIdx(bIdxVersion);
    if (eInnovaGroup==GROUP_N_A)
      sprintf(bPath_maindtc_bin, PATH_ALL_MAINDTC_BIN, group);
    else
      sprintf(bPath_maindtc_bin, PATH_MAINDTC_BIN, group);
    pstrtFileBinHandle->path = bPath_maindtc_bin;
#ifdef  _MSC_VER
    FILE_BIN_Open(pstrtFileBinHandle->fp,
                  pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#else
    pstrtFileBinHandle->pf_Open(pstrtFileBinHandle->fp,
                                pstrtFileBinHandle->path, pstrtFileBinHandle->mode);
#endif
    
    res = gf_SYS_Util_ReadFile(pstrtFileBinHandle, 0x00, (uint8*) &strtHeader,
                               sizeof(strtHeader));
    if (res == FR_OK)
    {
      uint8 strRam[144];
      iAddrKey = gf_SYS_GetFirstKey(sizeof(strtHeader),
                                    strtHeader.iNumberLine, (uint8*) pstrtKeyFilterInfo,
                                    strtHeader.bKeySize, strRam, strtHeader.bBaseSize,
                                    pstrtFileBinHandle);
      if (iAddrKey == _BST_NOT_FOUND_KEY_)
      {      
        eResult = eFALSE;  
      }
      else
      {
        eResult = eTRUE;
      }
#ifdef  _MSC_VER
      FILE_BIN_Close(pstrtFileBinHandle->fp);
#else
      pstrtFileBinHandle->pf_Close(pstrtFileBinHandle->fp);
#endif
    }
  }
  return eResult;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_FilterDTC_Type07_Toyota
*Input        : structOemProfile * p_strtOemProfile
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang March 09, 2016
-------------------------------------------------------------------------------*/
#if  (!_MSC_VER)
void gf_FilterDTC_Toyota(structOemProfile * p_strtOemProfile);
void gf_FilterDTC_Toyota(structOemProfile * p_strtOemProfile)
{
  uint8 bBytePosDTC=0;
  uint8 bByteProfilePosDTC=0;
  uint8 bFrameDTC;
  uint8 bNumDTC =0;
  enumbool eResult = eFALSE;
  enumBufferName eBufferName;
  enumInnovaGroups eInnovaGroup;
  structDtcParser strtDtcParser;
  uint8 strDTC[SIZE_OF_OEM_DTC];
  structKeyInfo strtKeyFilterInfo;
  eInnovaGroup=GROUP_N_A;
  bFrameDTC = p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc+1;
  memset(&strDTC,0,SIZE_OF_OEM_DTC);
  memset(&strtKeyFilterInfo, 0xFF, sizeof(structKeyInfo));
  strtKeyFilterInfo.sManufacturer = emanufacturer_Toyota;
  structVehDB * p_strtVehDB = gf_VDM_GetActive_DB(gf_VDM_GetVehicleProfile());
  if (p_strtVehDB->DtcReadType == edtcreadtype_ReadDTCType_ID0000_Toyota)
  {
    if ((p_strtOemProfile->iProfileID==emessageid_89_Toyota)||
        (p_strtOemProfile->iProfileID==emessageid_90_Toyota))
      strtKeyFilterInfo.sOption3 = p_strtOemProfile->iProfileID;
    else
      return;
  }
  else if(p_strtVehDB->DtcReadType == edtcreadtype_ReadDTCType_ID0002_Toyota)
  {
    if (p_strtOemProfile->iProfileID==emessageid_55_Toyota)
      strtKeyFilterInfo.sOption3 = p_strtOemProfile->iProfileID;
    else
      return;
  }
  else if (p_strtVehDB->DtcReadType == edtcreadtype_ReadDTCType_ID0007_Toyota)
  {
    if ((p_strtOemProfile->iProfileID==emessageid_74_Toyota)||
        (p_strtOemProfile->iProfileID==emessageid_76_Toyota)||
          (p_strtOemProfile->iProfileID==emessageid_88_Toyota)||
            (p_strtOemProfile->iProfileID==emessageid_129_Toyota)||
              (p_strtOemProfile->iProfileID==emessageid_237_Toyota)||
                (p_strtOemProfile->iProfileID==emessageid_238_Toyota)||
                  (p_strtOemProfile->iProfileID==emessageid_239_Toyota)||
                    (p_strtOemProfile->iProfileID==emessageid_301_Toyota)||
                      (p_strtOemProfile->iProfileID==emessageid_715_Toyota))
      strtKeyFilterInfo.sOption3 = p_strtOemProfile->iProfileID;
    else
      return;
  }
  else
    return;
  for (uint8 bIndexDTC = 0; bIndexDTC<=p_strtOemProfile->strtOEMDTCBuffer.NumberDTC-1;bIndexDTC++)
  {
    strtDtcParser.pDtc = gf_VDM_DTC_GetRawFromOemProfile(p_strtOemProfile,
                                                         &strtDtcParser.bFrameDtc,
                                                         bIndexDTC);
    gf_VDM_DTC_GetDtcStringFromOemProfile(p_strtOemProfile,
                                          &eBufferName,
                                          bIndexDTC,
                                          &strtDtcParser);
    
    memcpy(strtKeyFilterInfo.bMainDTCString, strtDtcParser.arrDtcOutPut, 15);
    eResult = __HasCodeDTC(&strtKeyFilterInfo, eInnovaGroup);
    if (eResult==eTRUE)
    {
      for (uint8 bFormat=0;bFormat<=p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc;bFormat++)
      {
        bBytePosDTC = bNumDTC*bFrameDTC+bFormat;
        bByteProfilePosDTC = bIndexDTC*bFrameDTC+bFormat;
        strDTC[bBytePosDTC]=p_strtOemProfile->strtOEMDTCBuffer.DTC[bByteProfilePosDTC];            
      }
      bNumDTC++;
    }
  }
  memcpy(p_strtOemProfile->strtOEMDTCBuffer.DTC,&strDTC,SIZE_OF_OEM_DTC);
  p_strtOemProfile->strtOEMDTCBuffer.NumberDTC = bNumDTC;
}
#endif