/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename: VehicleInterface.c
Description: main operation of tool start from here
layer: Main Application Layer
Accessability:connect to Middle layer UserInterface.c Only
===============================================================================
******************************************************************************/
/*
===============================================================================
                                INCLUDED FILES
===============================================================================
*/
#define __OEM_SETUP_C

#include <string.h>
#include "PlatFormType.h"
#include "InnovaLib.h"
#include "VehicleSupported.h"
#include "VehiclePrototype.h"
#include "VehicleOEMSupport.h"
#include "OEM_Setup.h"
extern const char ApiVersion[20];
/*

===============================================================================
                            FUNCTION/ PROCEDURE
===============================================================================
*/
void InitNopEcmTcmProfile(structControllerProfile * p_strtEcmCtrl)
{
}

/*------------------------------------------------------------------------------
Engineer:   Hai Tran
Historical: 05 Dec 2010
Function Name:  gf_Init_OEM_Profile
Description:    init all of OEM module of manufacter
Input:      pointer to structVehicleProfile
Output:     eTrue if Vehicle support OEM
------------------------------------------------------------------------------*/

void gf_Init_OEM_Profile(structVehicleProfile * p_strtVeh)
{
#ifdef __USE_OEM_MODULE
  uint8 bVehIdx = 0,bModIdx = 0;
  const structOEMModule   *p_strtOEMModule;
  while (strtVehicleOEMModule[bVehIdx].eVehicle != GENERIC )
    {
    if (p_strtVeh->strtVehicleId.Manufacture == strtVehicleOEMModule[bVehIdx].eVehicle )
    {
      p_strtOEMModule = strtVehicleOEMModule[bVehIdx].p_strtOEMModule;
      while (p_strtOEMModule->Init_X_OEM_Profile != null)
      {
        Init_X_OEM_Profile[bModIdx] = p_strtOEMModule->Init_X_OEM_Profile;
        bModIdx++;
        p_strtOEMModule++;
      }
      break;
    }
    bVehIdx++;
  }
#endif
}
/*------------------------------------------------------------------------------
Engineer:   Hai Tran
Historical: 05 Dec 2010
Function Name:  gf_Search_Index_OEM_Module
Description:    find index module of manufacter
Input:      enumVehicle eVehicle,enumController eOEMModule
Output:
------------------------------------------------------------------------------*/
enumbool gf_Search_Index_OEM_Module(enumVehicle eVehicle,enumController eOEMModule,uint8 *bIdx)
{
    enumbool eResult = eFALSE;
    #ifdef __USE_OEM_MODULE
    uint8 bVehIdx = 0;
    *bIdx = 0;
    const structOEMModule   *p_strtOEMModule;
    p_strtOEMModule = strtVehicleOEMModule[bVehIdx].p_strtOEMModule;
    while (strtVehicleOEMModule[bVehIdx].eVehicle != null )
    {
        if (strtVehicleOEMModule[bVehIdx].eVehicle == eVehicle)
        {
            p_strtOEMModule = strtVehicleOEMModule[bVehIdx].p_strtOEMModule;
            while (p_strtOEMModule->Init_X_OEM_Profile != null)
            {
                if (p_strtOEMModule->eCtrlType == eOEMModule)
                {
                    eResult = eTRUE;
        break;
                }
                else
                {
                    p_strtOEMModule++;
                    *bIdx+=1;
                }
            }
        break;
    }
        bVehIdx++;
    }
    #endif
    return eResult;
}

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 06 Sept 2011
*Function name  : __AbsSrsLightInit
*Description    : use to init abs srs light profile
*Input          : structVehicleProfile * p_strtVeh
*Output         :
-----------------------------------------------------------------------------*/
static void __AbsSrsLightInit(structVehicleProfile * p_strtVeh)
{
#ifdef _ENABLE_ABS_SRS_LIGHT
    static ROM_Str NoneVersion='\0';
    uint8 bIdxVehicle=0;
    p_strtVeh->pMakeVersion = &NoneVersion;
    while(strtVehicleAbsSrsLight[bIdxVehicle].eVehicle!=GENERIC)
    {
        if(strtVehicleAbsSrsLight[bIdxVehicle].eVehicle==p_strtVeh->strtVehicleId.Manufacture)
        {
            if(strtVehicleAbsSrsLight[bIdxVehicle].Init_X_Airbagstatus_Profile!=Null)
            {
                strtVehicleAbsSrsLight[bIdxVehicle].Init_X_Airbagstatus_Profile(&p_strtVeh->strtAirbagstatusCtrl);
            }
            if(strtVehicleAbsSrsLight[bIdxVehicle].Init_X_Absstatus_Profile!=Null)
            {
                strtVehicleAbsSrsLight[bIdxVehicle].Init_X_Absstatus_Profile(&p_strtVeh->strtAbsstatusCtrl);
            }
        }
        bIdxVehicle++;
    }
#warning enable abs srs light
#endif
}

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 06 Sept 2011
*Function name  : gf_Init_Vehicle_Module
*Description    : use to build / modified support vehicle
*Input          : structVehicleProfile * p_strtVeh
*Output         :
-----------------------------------------------------------------------------*/
void gf_Init_Vehicle_Module(structVehicleProfile * p_strtVeh)
{
    static ROM_Str NoneVersion='\0';
    uint8 bIdxVehicle=0;
    p_strtVeh->pMakeVersion = &NoneVersion;
#ifdef __USE_OEM_MODULE
    structControllerBuffer  * p_strtOEMBuffer;
    structControllerProfile * p_strtCtrlProfile;
    uint8 bIdxModule=0;
    bIdxVehicle=0;
    //memset(Init_X_OEM_Profile,NULL,sizeof(Init_X_OEM_Profile));
#endif
    __AbsSrsLightInit(p_strtVeh);
    while(strtVehicleModule[bIdxVehicle].eVehicle!=GENERIC)
    {
        if(strtVehicleModule[bIdxVehicle].eVehicle==p_strtVeh->strtVehicleId.Manufacture)
        {
            strtVehicleModule[bIdxVehicle].Init_X_Abs_Profile(&(p_strtVeh->strtAbsCtrl));
            strtVehicleModule[bIdxVehicle].Init_X_Srs_Profile(&(p_strtVeh->strtSrsCtrl));
            strtVehicleModule[bIdxVehicle].Init_X_Ecm_Profile(&(p_strtVeh->strtEcmCtrl));
            strtVehicleModule[bIdxVehicle].Init_X_Tcm_Profile(&(p_strtVeh->strtTcmCtrl));
            p_strtVeh->pMakeVersion =strtVehicleModule[bIdxVehicle].pVersion;

#ifdef __USE_OEM_MODULE
            //Execute function to assign OEM Module profile to specific module of seperate Manufacture
            gf_Init_OEM_Profile(p_strtVeh);
            while(Init_X_OEM_Profile[bIdxModule]!= NULL)
            {
                Init_X_OEM_Profile[bIdxModule](&(p_strtVeh->strtOEMProfile[bIdxModule]));
                p_strtCtrlProfile = &p_strtVeh->strtOEMProfile[bIdxModule];
                p_strtOEMBuffer   =  p_strtCtrlProfile->p_strtDataBuffer;
                if(p_strtOEMBuffer != Null)
                {
                    p_strtOEMBuffer->Manufacture = p_strtVeh->strtVehicleId.Manufacture;
                }
                bIdxModule++;
            }
#endif
            switch(p_strtVeh->strtVehicleId.Manufacture)
            {
            case FORD:
#ifdef _SUPPORT_FORD
                InitFordEnhanceProfile(p_strtVeh);
#ifdef _SUPPORT_FORD_OBD1
                InitFordOBD1Profile(&(p_strtVeh->strtEcmCtrl));
#endif
#endif
                break;
            case GM:
#ifdef _SUPPORT_GM
                InitGmEnhanceProfile(p_strtVeh);
#ifdef _SUPPORT_GM_OBD1
                InitGMOBD1Profile(&(p_strtVeh->strtEcmCtrl));
#endif
#endif
                break;
            case CHRYSLER:
#ifdef _SUPPORT_CHRYSLER

                InitChryslerEnhanceProfile(p_strtVeh);
#ifdef _SUPPORT_CHRYSLER_OBD1
                InitChryslerOBD1Profile(&(p_strtVeh->strtEcmCtrl));
#endif
#endif
                break;
            case HONDA:
#ifdef _SUPPORT_HONDA
                InitHondaEnhanceProfile(p_strtVeh);
#ifdef _SUPPORT_HONDA_OBD1
                InitHondaOBD1Profile(&(p_strtVeh->strtEcmCtrl));
#endif
#endif
                break;
            case TOYOTA:
#ifdef _SUPPORT_TOYOTA
                InitToyotaEnhanceProfile(p_strtVeh);
#ifdef _SUPPORT_TOYOTA_OBD1
                InitToyotaOBD1Profile(&(p_strtVeh->strtEcmCtrl));
#endif
#endif
                break;
            default:
                break;
            }
            break;
        }
        bIdxVehicle++;
    }
}

#if 0 /*Duplicated from API Build 53*/
/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 06 Sept 2011
*Function name  : gf_Init_Vehicle_Module
*Description    : use to build / modified support vehicle
*Input          : structVehicleProfile * p_strtVeh
*Output         :
-----------------------------------------------------------------------------*/
const char * gf_GetOBDAPI_Version(void)
{
    return (const char*)ApiVersion;
}
#endif