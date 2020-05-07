/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/
#define __DTCDEFINITION_C_
#include "NWSCAN_APP\LIB\PlatFormType.h"
#include "NWSCAN_APP\DTC\DTC_Config.h"
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
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
*Function name: gf_VDM_DTC_OEM_GetDef
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
#ifdef  _MSC_VER
__declspec(dllexport) uint32 __stdcall  gf_VDM_DTC_OEM_GetDef(structMFRVinProfile *p_strtMFRVinProfile,
                                                              structOemProfile *p_strtOemProfile,
															  enumOBDLanguage eMemLanguage,
                                                              structListDTCType *pstrtListDTCType,
															  void *pDef, 
															  uint32 iDefSize)
{
	///structMFRVinProfile *p_strtMFRVinProfile = &strtMFRVinProfile;
	//structOemProfile *p_strtOemProfile = &strtOemProfile;
	//structListDTCType *pstrtListDTCType = &strtListDTCType;
	structListAddressDTC strtListAddressDTC;
	memset(&strtListAddressDTC, 0, sizeof(structListAddressDTC));
	enumbool IsCheckOBD2 = eTRUE;
	uint32 iLenREt = 0;
	uint16 sIdxLib = 0;
	while (ROM_dtcinfo_Manuf_map[sIdxLib].pString != null)
	{
		if (ROM_dtcinfo_Manuf_map[sIdxLib].sID
			== p_strtMFRVinProfile->eManufacturer)
		{
			iLenREt =
				ROM_dtcinfo_Manuf_map[sIdxLib].gf_Vehicle_Adapter_DTC_GetDef(p_strtMFRVinProfile, 
					p_strtOemProfile, 
					eMemLanguage,
					pstrtListDTCType, 
					pDef, 
					iDefSize,
					&strtListAddressDTC);
			IsCheckOBD2 = ROM_dtcinfo_Manuf_map[sIdxLib].IsUseGenericExt;
			break;
		}
		sIdxLib++;

	}
	if ((strtListAddressDTC.IsHasDTCSub == eTRUE)
		&& (eMemLanguage != eMEM_LANGUAGE_ENGLISH))
	{
		if ((strtListAddressDTC.IsFoundDTC == eTRUE)
			&& (strtListAddressDTC.IsFoundDTCSubID == eTRUE))
		{
			if (strtListAddressDTC.IsFoundDTCMainDef == eFALSE
				|| strtListAddressDTC.IsFoundDTCSubDef == eFALSE)
			{
				return 0;
			}
		}
	}
	if (IsCheckOBD2 == eFALSE)
	{
		return iLenREt;
	}
	//if main dtc not found will check in obd2 if obd2 configure enable
	if (strtListAddressDTC.IsFoundDTC == eFALSE)
	{
		iLenREt = gf_VDM_DTC_OBDII_GetDef(p_strtMFRVinProfile, p_strtOemProfile,
			eMemLanguage, pstrtListDTCType, pDef, iDefSize);
		return iLenREt;
	}

	return iLenREt;
}
#else
uint32 gf_VDM_DTC_OEM_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                             structOemProfile *p_strtOemProfile, enumOBDLanguage eMemLanguage,
                             structListDTCType *pstrtListDTCType, void *pDef, uint32 iDefSize)
{
	structListAddressDTC strtListAddressDTC;
	memset(&strtListAddressDTC, 0, sizeof(structListAddressDTC));
	enumbool IsCheckOBD2 = eTRUE;
	uint32 iLenREt = 0;
	uint16 sIdxLib = 0;
	while (ROM_dtcinfo_Manuf_map[sIdxLib].pString != null)
	{
		if (ROM_dtcinfo_Manuf_map[sIdxLib].sID
			== p_strtMFRVinProfile->eManufacturer)
		{
			iLenREt =
				ROM_dtcinfo_Manuf_map[sIdxLib].gf_Vehicle_Adapter_DTC_GetDef(
					p_strtMFRVinProfile, p_strtOemProfile, eMemLanguage,
					pstrtListDTCType, pDef, iDefSize,
					&strtListAddressDTC);
			IsCheckOBD2 = ROM_dtcinfo_Manuf_map[sIdxLib].IsUseGenericExt;
			break;
		}
		sIdxLib++;

	}
	if ((strtListAddressDTC.IsHasDTCSub == eTRUE)
		&& (eMemLanguage != eMEM_LANGUAGE_ENGLISH))
	{
		if ((strtListAddressDTC.IsFoundDTC == eTRUE)
			&& (strtListAddressDTC.IsFoundDTCSubID == eTRUE))
		{
			if (strtListAddressDTC.IsFoundDTCMainDef == eFALSE
				|| strtListAddressDTC.IsFoundDTCSubDef == eFALSE)
			{
				return 0;
			}
		}
	}
	if (IsCheckOBD2 == eFALSE)
	{
		return iLenREt;
	}
	//if main dtc not found will check in obd2 if obd2 configure enable
	if (strtListAddressDTC.IsFoundDTC == eFALSE)
	{
		iLenREt = gf_VDM_DTC_OBDII_GetDef(p_strtMFRVinProfile, p_strtOemProfile,
			eMemLanguage, pstrtListDTCType, pDef, iDefSize);
		return iLenREt;
	}

	return iLenREt;
}
#endif


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_Dtc_GetSeverity
*Input        : structMFRVinProfile * p_strtMFRVinProfile,
structOemProfile *pstrtOemProfile,
structListDTCType *pstrtListDTCType
*Output       :
*Description  :
-------------------------------------------------------------------------------*/
enumbool gf_VDM_DTC_GetSeverity(structMFRVinProfile * p_strtMFRVinProfile,
                                structOemProfile *p_strtOemProfile,
                                structListDTCType *pstrtListDTCType)
{
  structListAddressDTC* pstrtListAddressDTC;
  structListAddressDTC strtListAddressDTC;
  pstrtListDTCType->bSeverity=0xFF;
  memset(pstrtListDTCType->bReseve,0,sizeof(pstrtListDTCType->bReseve));
  enumbool bResult = eFALSE;
  uint8 bNumLoop = 2;
  if (pstrtListDTCType == null)
    return null;
  structKeyInfo strtKeyInfo;
  enumSystem eListSystem[2];
  enumSystem eListProtocol[2];
  enumManufacturer eListManufacture[2];
  memset(&strtKeyInfo, 0xFF, sizeof(structKeyInfo));
  memset(strtKeyInfo.bMainDTCString, 0, SIZE_MAINCODE);
  memcpy(strtKeyInfo.bMainDTCString, pstrtListDTCType->bDTCString,
         strlen(pstrtListDTCType->bDTCString));
  eListProtocol[0] = p_strtOemProfile->Protocol;
  eListProtocol[1] = PROTOCOL_MAX;
  eListSystem[0] = p_strtOemProfile->sSystem;
  eListSystem[1] = eNWSCAN_SYSTEM_MAX;
  enumManufacturer eManufactureBK = p_strtMFRVinProfile->eManufacturer;
  if ((p_strtOemProfile->Protocol == PROTOCOL_ISO9141)
      && (p_strtMFRVinProfile->eManufacturer == emanufacturer_GM))
  {
    eListProtocol[0] = PROTOCOL_KW2000;   // For make GM
  }
  // GetSystem
  eListSystem[0] = gf_GetSystem(p_strtMFRVinProfile->eManufacturer,
                                p_strtOemProfile->sSystem);
  eListManufacture[0] = p_strtMFRVinProfile->eManufacturer;
  eListManufacture[1] = eNWSCAN_MANUFACTURE_MAX;
  if (p_strtMFRVinProfile->eManufacturer == emanufacturer_UNKNOWN)
  {
    bNumLoop = 1;
    eListSystem[0] = eNWSCAN_SYSTEM_MAX;
    eListManufacture[0] = eNWSCAN_MANUFACTURE_MAX;
    eListProtocol[0] = PROTOCOL_MAX;
    strtKeyInfo.sManufacturer = eNWSCAN_MANUFACTURE_MAX;
  }
  for (uint8 bIdxManufacture = 0; bIdxManufacture < bNumLoop;bIdxManufacture++)
  {
    if (eListManufacture[bIdxManufacture] == emanufacturer_Volkswagen)
    {
      if (p_strtMFRVinProfile->eModel == emodel_Routan_Volkswagen)
        strtKeyInfo.sModel = emodel_Routan_Volkswagen;
    }
    else if (eListManufacture[bIdxManufacture] == emanufacturer_GM)
    {
      if (p_strtMFRVinProfile->eModel == emodel_Vibe_GM)
        strtKeyInfo.sModel = emodel_Vibe_GM;
    }
    
    if ((eListManufacture[bIdxManufacture] == emanufacturer_Hyundai)||
        (eListManufacture[bIdxManufacture]==emanufacturer_Jaguar_____Land_____Rover))
      strtKeyInfo.sManufacturer = p_strtMFRVinProfile->eMake;
    else
      strtKeyInfo.sManufacturer = eListManufacture[bIdxManufacture];
    
    p_strtMFRVinProfile->eManufacturer = eListManufacture[bIdxManufacture];
    for (uint8 bIdxSystem = 0; bIdxSystem < bNumLoop; bIdxSystem++)
    {
      strtKeyInfo.sSystem = eListSystem[bIdxSystem];
      for (uint8 bIdxProtocol = 0; bIdxProtocol < bNumLoop; bIdxProtocol++)
      {
        strtKeyInfo.bProtocol = eListProtocol[bIdxProtocol];
        
        pstrtListAddressDTC = gf_DTC_FindListID(GROUP_OBDII,
						&strtKeyInfo, &strtListAddressDTC, eTRUE);
        if (pstrtListAddressDTC != Null)
        {
          bResult = gf_DTC_SeverityLevel(GROUP_OBDII, 
                                         pstrtListAddressDTC,
                                         pstrtListDTCType); 
          p_strtMFRVinProfile->eManufacturer = eManufactureBK;
          return bResult;
        }
      }
    }
  }
  p_strtMFRVinProfile->eManufacturer = eManufactureBK;
  return bResult;
}


