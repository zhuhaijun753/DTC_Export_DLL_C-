/******************************************************************************
 ===============================================================================
                         INNOVA ELECTRONICS VIETNAM
 * Filename : Honda_Adapter_App.h
 * Description:
 
 *  Created on: HungVo  Feb 7, 2015
 *
 *  Version         : V01.00.00
===============================================================================
******************************************************************************/

#ifndef _HONDA_ADAPTER_APP_H_
#define _HONDA_ADAPTER_APP_H_


/*------------------------------------------------------------------------------
 *Engineer     : HungVo
 *Function name: gf_Honda_getListOption
 *Input        : structVehicleProfile *pstrtVehicleProfile,uint8 *pList
 *Output       : uint8 : number selection
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation HungVo Nov 4, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint8 gf_Honda_getListOption(structVehicleProfile *pstrtVehicleProfile,
        uint8 *pList);

/*------------------------------------------------------------------------------
 *Engineer     : HungVo
 *Function name: gf_HondaCatchingDtcAsOption
 *Input        : structVehicleProfile *pstrtVehicleProfile
 *Input          enumHondaOptions eOption
 *Output       : enumbool : success or fail
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation HungVo Nov 4, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_HondaCatchingDtcAsOption(structVehicleProfile *pstrtVehicleProfile,
        enumHondaOptions eOption);


/*------------------------------------------------------------------------------
 *Engineer     : HungVo
 *Function name: gf_HondaBodyDisplayUnitInfo
 *Input        : structVehicleProfile *pstrtVehicleProfile,structBodyInfoResult *pstrtBodyInfoResult,uint8 bSizeBodyInfoResult
 *Output       : uint8 : number item result pstrtBodyInfoResult
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation HungVo Nov 4, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint8 gf_HondaBodyDisplayUnitInfo(structVehicleProfile *pstrtVehicleProfile,
        structBodyInfoResult *pstrtBodyInfoResult, uint8 bSizeBodyInfoResult);

/*------------------------------------------------------------------------------
*Engineer     : HungVo
*Function name: gf_VDM_IsHondaBodySpecial
*Input        : enumManufacturer eManufacture,structOemProfile *p_strtOemProfiles
*Output       : eTRUE : special honda body kw
*Description  :
*strtVehDB->EcuInfoParserType == eecuinfotype_ECUType_ID0036 &sSystem ==eSYSTEM_HONDA_SPECIAL
*
*
*Historical   :
*     1. Creation HungVo Nov 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_IsHondaBodySpecial(enumManufacturer eManufacture,structOemProfile *p_strtOemProfiles);

/*------------------------------------------------------------------------------
 *Engineer     : HungVo
 *Function name: gf_VDM_Dtc_GetStringBufferName
 *Input        :structDtcParser *pstrtDtcParser,uint8 *pOutBuffName,uint16 sSizeStringOut
 *Output       : void*
 *Description  :
 *get string buffer name
 *
 *
 *Historical   :
 *     1. Creation HungVo Nov 4, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void* gf_VDM_Dtc_GetStringBufferName(structDtcParser *pstrtDtcParser,
        uint8 *pOutBuffName, uint16 sSizeStringOut);

void gf_VDM_Honda_Body_Retreive_Dtc(structVehicleProfile * p_VehicleProfile);

#endif /* 2_MIDDLE_2_VEHICLE_INTERFACE_1_OBD_API_NWSCAN_APP_MW_LIB_HONDA_ADAPTER_APP_H_ */
