/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: Vehicle_Data_Structure.h
Description: this file declares all structures involving to OBD2 data
these data structure is used for both UI and middle ware
these data will be saved to memory for reviewing purpose
Layer:  Application - Middleware
Accessibility: 
================================================================================
*******************************************************************************/
#ifndef     __LIVEDATA_ADAPTER_APP_H__
#define     __LIVEDATA_ADAPTER_APP_H__
#include <YMMESelection.h>
#include <MW_LIB\OBDIILDFFUtility.h>
#include <5_Vehicle_Data_Process\Vehicle_Data_Structure.h>
/*
===============================================================================
FUNCTION/ TO READ OBDII & OEM LIVEDATA
===============================================================================
*/
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_GetPidSupport
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/
extern enumLDStatus gf_VBI_MWLD_GetPidSupport(structMFRVinProfile * p_strtMFRVinProfile,
                                              structOemProfile * p_strtOemProfile,
                                              structOBDLdPIDData * p_strtOBDLdPIDData,
                                              structOBDLdItemDisp * p_strtOBDLdItemDisp);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_FindItemString
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/
extern enumLDStatus gf_VBI_MWLD_FindItemString(structMFRVinProfile * p_strtMFRVinProfile,
                                               structOemProfile * p_strtOemProfile,
                                               structOBDLdPIDData * p_strtOBDLdPIDData,
                                               structOBDLdItemDisp * p_strtOBDLdItemDisp,
                                               uint8 bLanguage,uint8 bUnitID);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_ReadData
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/  
extern enumLDStatus gf_VBI_MWLD_ReadData(structMFRVinProfile * p_strtMFRVinProfile,
                                         structOemProfile * p_strtOemProfile,
                                         structOBDLdPIDData * p_strtOBDLdPIDData,
                                         structOBDLdItemDisp * p_strtOBDLdItemDisp);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_GetValue
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/  
extern enumLDStatus gf_VBI_MWLD_GetValue(structMFRVinProfile * p_strtMFRVinProfile,
                                         structOemProfile * p_strtOemProfile,
                                         structOBDLdPIDData * p_strtOBDLdPIDData,
                                         structOBDLdItemDisp * p_strtOBDLdItemDisp,
                                         uint8 bLanguage,uint8 bUnitID);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_Description
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/  
extern enumLDStatus gf_VBI_MWLD_Description(uint16 sIdxItem,
                                            structMFRVinProfile * p_strtMFRVinProfile,
                                            structOemProfile * p_strtOemProfile,
                                            structOBDLdPIDData * p_strtOBDLdPIDData,
                                            structOBDLdItemDisp * p_strtOBDLdItemDisp,
                                            uint8 bLanguage,uint8 bUnitID,
                                            uint8 *pDescription,
                                            uint8 *pbLenStr,uint8* p_Unit);

/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_ItemProfileByIndex
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/  
extern enumLDStatus gf_VBI_MWLD_ItemProfileByIndex(structLDItemValue * p_strtLDItemValue,
                                                   structMFRVinProfile * p_strtMFRVinProfile,
                                                   structOemProfile * p_strtOemProfile,
                                                   structOBDLdPIDData * p_strtOBDLdPIDData,
                                                   structOBDLdItemDisp * p_strtOBDLdItemDisp,
                                                   uint8* p_Unit);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Mar 28 , 2015
*Function name: gf_VBI_MWLD_ValueByIndex
*Descrtiption :
*Input        : 
*             : 
*Output       :
*-----------------------------------------------------------------------------*/  
extern enumLDStatus gf_VBI_MWLD_ItemValueByIndex(structLDItemValue * p_strtLDItemValue,
                                                 structMFRVinProfile * p_strtMFRVinProfile,
                                                 structOemProfile * p_strtOemProfile,
                                                 structOBDLdPIDData * p_strtOBDLdPIDData,
                                                 structOBDLdItemDisp * p_strtOBDLdItemDisp);
/*
===============================================================================
FUNCTION/ TO READ OBDII FREEZE FRAME
===============================================================================
*/
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Jan 12 2015
*Function name: gf_VBI_OBD2FF_ReadData
*Descrtiption : Read FF data
*Input        : structOemProfile * p_strtOemProfile
*             : 
*Output       : structOBDLdPIDData *p_strtOBDLdPIDData
*-----------------------------------------------------------------------------*/
extern enumbool gf_VBI_OBD2FF_ReadData(structVehDataOBD2Data *p_strtVehData_OBD2Data);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Jan 12 2015
*Function name: gf_VBI_OBD2FF_FindItem
*Descrtiption : Find FF Items supported
*Input        : structOemProfile * p_strtOemProfile,
structOBDLdPIDData * p_strtOBDLdPIDData,
structOBDLdItemDisp* p_strtOBDLdItemDisp,
*Output       : structOBDLdItemDisp *p_strtOBDLdItemDisp
*-----------------------------------------------------------------------------*/
extern enumbool gf_VBI_OBD2FF_FindItem(structVehDataOBD2Data *p_strtVehData_OBD2Data,
                                       structOBDLdItemDisp* p_strtOBDLdItemDisp,
                                       uint8 bLanguage,uint8 bUnitID);
/*------------------------------------------------------------------------------
*Engineer     : ThuyetHN
*Historical   : 1. Jan 12 2015
*Function name: gf_VBI_OBD2FF_Description
*Descrtiption : get FF descriptions
*Input        : uint16 sIdxItem,
structOBDLdPIDData * p_strtOBDLdPIDData,
structOBDLdItemDisp* p_strtOBDLdItemDisp,
*Output       : pDescription,pbLenStr
*-----------------------------------------------------------------------------*/
extern enumbool gf_VBI_OBD2FF_Description(uint16 sIdxItem,
                                          structOBDLdPIDData * p_strtOBDLdPIDData,
                                          structOBDLdItemDisp* p_strtOBDLdItemDisp,
                                          uint8 bLanguage,uint8 bUnitID,
                                          uint8 *pDescription,
                                          uint8 *pbLenStr);
#endif