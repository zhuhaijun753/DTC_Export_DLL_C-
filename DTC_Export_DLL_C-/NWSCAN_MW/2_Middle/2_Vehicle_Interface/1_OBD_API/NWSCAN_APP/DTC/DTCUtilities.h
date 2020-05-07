/*******************************************************************************
================================================================================
                              Lap Dang Dev
 * Filename: DTCUtilities.h
 * Description:
 * Layer:
 * Accessibility:
 * Created on: Oct 17, 2015
 *      Author: Lap Dang
================================================================================
*******************************************************************************/

#ifndef DTCUTILITIES_H_
#define DTCUTILITIES_H_

#define DTC_GROUP_ALL	0xFE

enumbool gf_CheckDupplicateAddr(uint32 Lap Dangem, structListAddressDTC *pstrtListAddressDTC);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: uint8 gf_GetListAddressDTC(structListAddressDTC *pstrtListAddressDTC,
                           structKeyInfo *p_strtKeyInfo,
                           void *pPathFile,
                           enumbool eUseDTCLibrary)
*Input        :
*Output       :
*Description  :
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
uint8 gf_GetListAddressDTC(structListAddressDTC *pstrtListAddressDTC,
                           structKeyInfo *p_strtKeyInfo,
                           void *pPathFile,
                           enumbool eUseDTCLibrary,
			   enumbool IsMainDTC);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void *gf_DtcGetMappingString(uint16 sID, const structDtcInfoPath*pData)
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
void *gf_DtcGetMappingString(uint16 sID, const structDtcInfoPath*pData);

#define __DtcGetMappingString   gf_DtcGetMappingString

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structDTCString*gf_DTC_GetSplitStrDTC(structListDTCType *pstrtListDTCType)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  11:32:53 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structDTCString*gf_DTC_GetSplitStrDTC(structListDTCType *pstrtListDTCType);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumbool gf_DTC_IsHasSubCode(structDTCString*pstrtDTCString)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  11:40:09 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_DTC_IsHasSubCode(structDTCString*pstrtDTCString);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: static structListAddressDTC * gf_DTC_FindListID(enumInnovaGroups eInnovaGroup,
		structKeyInfo *p_strtKeyInfo, structListAddressDTC* pstrtListAddressDTC,
		enumbool IsMainDef)
 *Input        :
 *Output       :
 *Description  :
 *
 *Historical   :
 *     1. Creation Lap Dang Sep 09, 2014
 -------------------------------------------------------------------------------*/
structListAddressDTC * gf_DTC_FindListID(enumInnovaGroups eInnovaGroup,
		structKeyInfo *p_strtKeyInfo, structListAddressDTC* pstrtListAddressDTC,
		enumbool IsMainDef);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: uint16 gf_Get_DTC_Definiton(structListAddressDTC* pstrtListAddressDTC,
		enumInnovaGroups eInnovaGroup, enumOBDLanguage eMemLanguage, char *pDef,
		uint32 iDefSize, enumbool IsMainDTC)
 *Input        :
 *Output       :
 *Description  :
 *
 *Historical   :
 *     1. Creation Lap Dang Sep 09, 2014
 -------------------------------------------------------------------------------*/
uint16 gf_Get_DTC_Definition(structListAddressDTC* pstrtListAddressDTC,
                             enumInnovaGroups eInnovaGroup, 
                             enumOBDLanguage eMemLanguage, 
                             char *pDef,
                             uint32 iDefSize, 
                             enumbool IsMainDTC);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_DTC_GetListInnGroup
 *Input        : structOemProfile *p_strtOemProfile
 *Output       : enumInnovagroup
 *Description  :
 *
 *Historical   :
 *     1. Creation Lap Dang Sep 09, 2014
 -------------------------------------------------------------------------------*/
enumInnovagroup *gf_DTC_GetListInnGroup(structOemProfile *p_strtOemProfile);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_DTC_SeverityLevel 
*Input        : enumInnovaGroups eInnovaGroup, 
                structListAddressDTC* pstrtListAddressDTC,
                structListDTCType *pstrtListDTCType
*Output       : void
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
enumbool gf_DTC_SeverityLevel(enumInnovaGroups eInnovaGroup, 
                          structListAddressDTC* pstrtListAddressDTC,
                          structListDTCType *pstrtListDTCType);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_GetSystem 
*Input        : enumManufacturer eManufacture, enumSystem System                
*Output       : enumSystem
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Sep 09, 2014
-------------------------------------------------------------------------------*/
enumSystem gf_GetSystem(enumManufacturer eManufacture, enumSystem System);

#endif /* DTCUTILITIES_H_ */
