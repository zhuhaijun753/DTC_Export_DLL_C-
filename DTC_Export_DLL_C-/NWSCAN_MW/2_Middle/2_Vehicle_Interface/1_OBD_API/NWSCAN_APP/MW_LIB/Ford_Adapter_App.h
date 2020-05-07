/******************************************************************************
 ===============================================================================
                         Lap Dang Dev
 * Filename : Ford_Adapter_App.h
 * Description:
 
 *  Created on: Lap Dang  Feb 7, 2015
 *
 *  Version         : V01.00.00
===============================================================================
******************************************************************************/

#ifndef _FORD_ADAPTER_APP_H_
#define _FORD_ADAPTER_APP_H_


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_Ford_ReadRPM
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
sint32 gf_Ford_ReadRPM(structVehicleProfile * p_strtVehicleProfile);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_FordEnhancedGetResult_CM
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_FordEnhancedGetResult_CM(structVehicleProfile * p_strtVehicleProfile);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_Ford_StartRoutine_KOEO
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_Ford_StartRoutine_KOEO(structVehicleProfile * p_strtVehicleProfile);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_FordEnhancedGetResult_KOEO
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_FordEnhancedGetResult_KOEO(structVehicleProfile * p_strtVehicleProfile);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_Ford_StartRoutine_KOER
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_Ford_StartRoutine_KOER(structVehicleProfile * p_strtVehicleProfile);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_FordEnhancedGetResult_KOER
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_FordEnhancedGetResult_KOER(structVehicleProfile * p_strtVehicleProfile);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_Ford_StartRoutine_KOEO_Injector
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_Ford_StartRoutine_KOEO_Injector(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_FordEnhancedGetResult_KOEO_Injector
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_FordEnhancedGetResult_KOEO_Injector(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_Ford_StartRoutine_KOER_GlowPlug
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_Ford_StartRoutine_KOER_GlowPlug(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_FordEnhancedGetResult_KOER_GlowPlug
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
enumbool gf_FordEnhancedGetResult_KOER_GlowPlug(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_IsFordEnhance
*Input        : structVehicleProfile * p_strtVehicleProfile
*Output       : eTRUE : support special ford enhance type
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Nov 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_IsFordEnhance(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_FordGetEnhanceType
*Input        : structVehicleProfile *pstrtVehicleProfile
*Output       : enumFordEnhType
*Description  :
*get enhanced type of ford
*
*
*Historical   :
*     1. Creation Lap Dang Nov 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumFordEnhType gf_VDM_FordGetEnhanceType(structVehicleProfile *pstrtVehicleProfile);


enumbool gf_VDM_IsOemProfileExistDtc(void);


/*------------------------------------------------------------------------------
*Engineer     : Thuyet Nguyen
*Function name: gf_FordEnh_ClearDtcStatus
*Input        : void
*Output       : void
*Description  :
*Detection : Select Vehicle for Test
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
-------------------------------------------------------------------------------*/
void gf_FordEnh_ClearDtcStatus(enumBufferName eBuffName,structVehicleProfile * p_strtVehicleProfile);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: enumbool gf_VDM_FordOBD1_Koeo(structVehicleProfile * p_strtVehicleProfile)
*Input        : structVehicleProfile * p_strtVehicleProfile
*Output       : enumbool
*Description  :
*Link to ford ecm koeo obd1
*
*
*Historical   :
*     1. Creation Lap Dang Mar 16, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_FordOBD1_Koeo(structVehicleProfile * p_strtVehicleProfile);

#endif /* 2_MIDDLE_2_VEHICLE_INTERFACE_1_OBD_API_NWSCAN_APP_MW_LIB_FORD_ADAPTER_APP_H_ */
