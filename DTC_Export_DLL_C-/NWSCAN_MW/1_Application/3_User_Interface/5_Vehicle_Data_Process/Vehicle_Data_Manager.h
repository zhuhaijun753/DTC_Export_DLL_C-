/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: Vehicle_Data_Manager.h
Description: this file declare all prototype and variables used for processing 
                vehicle data
Layer: Application-Middle
Accessibility: Application and Middle should access this interface
================================================================================
*******************************************************************************/

#ifndef     __VEHICLE_DATA_MANAGER_H__
#define     __VEHICLE_DATA_MANAGER_H__

#include    "Vehicle_Data_Structure.h"
#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\LIB\InnovaOBDApp.h>
#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\LIB\VBI_Utility.h>
#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\LIB\SYS_Utility.h>
#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\LIB\VDM_Adapter.h>

#include        "enums.h"
#include    "ymme_enumeration.h"
#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\MW_LIB\OBDII_Adapter_App.h>
#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\MW_LIB\Makes_Adapter_App.h>

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/







/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
/*
buffer to handle all vehicle data, application just access this 
or through interface for all
*/
extern structVehicleDataBuffer     g_strtVehicleDataBuffer;


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 07 2014 Lap Dang init
*Function name: VehicleData_Initialization
*Descrtiption : this function is called to init all data buffer 
                involving to vehicle data 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void    VehicleData_Initialization(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan1515
*Function name: VehicleData_IsValid()
*Descrtiption : Check to see whether vehicle data is valid or not
                vehicle data is valid if one of field valid
                    - 
*Input        : none
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_IsValid(void);
















/*==============================================================================
                   VEHICLE DATA ACCESS FUNCTIONs
==============================================================================*/

/*==============================================================================
                   VEHICLE DATA ACCESS FUNCTIONs - VIN, YMME PROFILE
            all functions involving to access VIN+YMME profile
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Nov0814
*Function name: VehicleData_YMMEProfile_Set()
*Descrtiption : Set YMME profile of the current selected vehicle 
                - copy all info form pointer to ymme profile
*Input        : structMFRVinProfile *p_strtYMMEProfile - pointer to 
                  the YMME Profile need to set to
*Output       :  none
------------------------------------------------------------------------------*/
void  VehicleData_YMMEProfile_Set(structMFRVinProfile * p_strtYMMEProfile);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Nov0814
*Function name: VehicleData_YMMEProfile_Get()
*Descrtiption : Get YMME profile of the current selected vehicle
*Input        : none
*Output       : structMFRVinProfile *p_strtYMMEProfile - pointer to 
                                        the current selected vehicle YMME Profile
------------------------------------------------------------------------------*/
structMFRVinProfile * VehicleData_YMMEProfile_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Nov0814
*Function name: VehicleData_YMMEProfile_VINString_Set()
*Descrtiption : Set YMME profile VIN string of the current selected vehicle 
                
*Input        : uint8 * p_bVINString - pointer to VIN string need to set to profile
*Output       : none 
------------------------------------------------------------------------------*/
void  VehicleData_YMMEProfile_VINString_Set(uint8 * p_bVINString);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Nov0814
*Function name: VehicleData_YMMEProfile_VINString_Get()
*Descrtiption : Get VIN string of the current selected vehicle
*Input        : none
*Output       : uint8 * - pointer to VIN string of the current selected vehicle YMME Profile
                        - this string may be null string in case no VIN saved
------------------------------------------------------------------------------*/
uint8 * VehicleData_YMMEProfile_VINString_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan1515
*Function name: VehicleData_YMMEProfile_IsValid()
*Descrtiption : check to see whether YMME profile is valid
*Input        : none
*Output       : enumbool - status of YMME profile

------------------------------------------------------------------------------*/
enumbool VehicleData_YMMEProfile_IsValid(void);


///*------------------------------------------------------------------------------
//*Engineer     : Lap Dangruong
//*Historical   : Nov0814
//*Function name: VehicleData_YMMEProfile_MakeCheckValid()
//*Descrtiption : check to see whether the input make is valid
//                Make is valid when it is in the valid range of enumMFRMake
//*Input        : enumMFRMake eMAKE - Make value need to be checked
//*Output       : enumbool - valid status
//------------------------------------------------------------------------------*/
//enumbool VehicleData_YMMEProfile_MakeCheckValid(enumMFRMake eMAKE);
//








/*==============================================================================
                    VEHICLE DATA ACCESS FUNCTIONs
            OBD2 DATA INVOLVING FUNCTIONs
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : December 30 2014
*Function name: VehicleDataManager_LDFFDataSupportedItem_Get()
*Descrtiption : Get LD - FF supoprted item (use for both LD and FF, both OBD2 and OEM)
*Input        : enumLDFFType eLDFFType - type of LD FF need to be get supported item
                structOBDLdPIDData * p_strtLDFFSupport - pointer to buffer to stored supported item
*Output       : enumbool - valid status
------------------------------------------------------------------------------*/
#if 1//Jan1915 Lap Dang changed follow new API from thuyet
enumbool VehicleDataManager_LDFFDataSupportedItem_Get(enumLDFFType eLDFFType,
                                                      structOBDLdPIDData * p_strtLDFFSupport,
                                                      uint8 bUnit);
#else
enumbool VehicleDataManager_LDFFDataSupportedItem_Get(enumLDFFType eLDFFType, structOBDLdPIDData * p_strtLDFFSupport);
#endif
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : December 30 2014
*Function name: VehicleDataManager_LDFFDataNameValueItem_Get()
*Descrtiption : Get LD - FF item name and value (use for both LD and FF, both OBD2 and OEM)
*Input        : enumLDFFType eLDFFType - type of LD FF need to be get item name and value
                structOBDLdPIDData * p_strtLDFFSupport - pointer to buffer to stored item
*Output       : enumbool - valid status
------------------------------------------------------------------------------*/
enumbool VehicleDataManager_LDFFDataNameValueItem_Get(enumLDFFType eLDFFType,
                                                      structOBDLdPIDData * p_strtLDFFSupport,
                                                      uint8 bUnit);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : December 30 2014
*Function name: VehicleDataManager_LDFF_ReadLiveValue_Get()
*Descrtiption : Get LD - FF live value
*Input        : enumLDFFType eLDFFType - type of LD FF need to be get value
                structOBDLdPIDData * p_strtLDFFSupport - pointer to buffer to stored item
                uint8    bUnit - unit system to get value
                uint16   sStartIdx - start item in p_strtLDFFSupport to get data
                uint16   sNoReadItem - number items to get data
*Output       : enumbool - valid status
------------------------------------------------------------------------------*/
enumbool VehicleDataManager_LDFF_ReadLiveValue_Get(enumLDFFType eLDFFType,
                                                   structOBDLdPIDData * p_strtLDFFSupport,
                                                   uint8    bUnit,
                                                   uint16   sStartIdx,
                                                   uint16   sNoReadItem);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 10 2015
*Function name: VehicleDataManager_LDFFDataNameValueItem_Get()
*Descrtiption : Get LD - FF item name full term(use for both LD and FF, both OBD2 and OEM)
*Input        : enumLDFFType eLDFFType - type of LD FF need to be get item name and value
                structOBDLdPIDData * p_strtLDFFSupport - pointer to buffer to stored item
                uint8 bIdxItem - index of item in support list which get before
                uint8 * p_bDescription - pointer to buffer to store item name full term
                uint8 * p_bLenStr - pointer to variable store length of buffer
*Output       : enumbool - valid status
------------------------------------------------------------------------------*/
enumbool VehicleDataManager_LDFFItemNameFullTerm_Get(enumLDFFType eLDFFType,
                                                     structOBDLdPIDData * p_strtLDFFSupport,
                                                     uint16 sIdxItem,
                                                     enumMemoryLanguage eLanguage,
                                                     uint8 * p_bDescription,
                                                     uint8 * p_bLenStr);
                
                                                      

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Nov0814
*Function name: VehicleDataManager_OBD2_ECM_DTCBuff_Get()
*Descrtiption : Get pointer to oem profile buffer of OBD2 ECM
*Input        : none
*Output       : structOemProfile * - pointer to oem profile buffer of OBD2 ECM

------------------------------------------------------------------------------*/          
structOemProfile* VehicleDataManager_OBD2_ECM_DTCBuff_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Nov0814
*Function name: VehicleDataManager_OBD2_TCM_DTCBuff_Get()
*Descrtiption : Get pointer to oem profile buffer of OBD2 TCM
*Input        : none
*Output       : structOemProfile * - pointer to oem profile buffer of OBD2 TCM

------------------------------------------------------------------------------*/          
structOemProfile* VehicleDataManager_OBD2_TCM_DTCBuff_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan3015
*Function name: VehicleDataManager_OBD2_ECM_Address_Get()
*Descrtiption : return ECU address of buffer of OBD2 ECM
*Input        : none
*Output       : uint32 - address of OBD2 ECM buffer

------------------------------------------------------------------------------*/          
uint32 VehicleDataManager_OBD2_ECM_Address_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan3015
*Function name: VehicleDataManager_OBD2_TCM_Address_Get()
*Descrtiption : return ECU address of buffer of OBD2 TCM
*Input        : none
*Output       : uint32 - address of OBD2 TCM buffer

------------------------------------------------------------------------------*/          
uint32 VehicleDataManager_OBD2_TCM_Address_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 27 2014
*Function name: VehicleData_OBD2_Sid1_IsValid()
*Descrtiption : Check to see whether OBD2 SID 1 is valid
*Input        : none
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OBD2_Sid1_IsValid(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 27 2014
*Function name: VehicleData_OBD2_Sid2_IsValid()
*Descrtiption : Check to see whether OBD2 SID 2 is valid
*Input        : none
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OBD2_Sid2_IsValid(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 27 2014
*Function name: VehicleData_OBD2_Sid37A_IsValid()
*Descrtiption : Check to see whether OBD2 SID 3,7,A is valid
*Input        : none
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OBD2_Sid37A_IsValid(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 27 2014
*Function name: VehicleData_OBD2_Sid9_IsValid()
*Descrtiption : Check to see whether OBD2 SID 9 is valid
*Input        : none
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OBD2_Sid9_IsValid(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 31 2015
*Function name: VehicleData_OBD2_Sid9_CalID_List_InString_Get()
*Descrtiption : Check to see whether OBD2 SID 9 CAL ID is valid
                and copy CAL ID to the list
*Input        : structCalIDList   * p_strtCalIDList - pointer to structure to store cal id list
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool    VehicleData_OBD2_Sid9_CalID_List_InString_Get(structCalIDList   * p_strtCalIDList);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 31 2015
*Function name: VehicleData_OBD2_Sid9_CVN_List_InString_Get()
*Descrtiption : Check to see whether OBD2 SID 9 CVN is valid
                and copy CVN to the list
*Input        : structCVNList   * p_strtCVNList - pointer to structure to store CVN list
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool    VehicleData_OBD2_Sid9_CVN_List_InString_Get(structCVNList   * p_strtCVNList);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. February 02 2015
*Function name: VehicleData_Available_Module_Info_Get
*Descrtiption : get available module list info (currently just module address and protocol)
*Input        : structAvailModuleList * p_strtAvailModuleList - pointer to buffer to store valid modules
*Output       : enumbool - status of valid, valid if has at least 1 module valid
*-----------------------------------------------------------------------------*/
enumbool    VehicleData_Available_Module_Info_Get(structAvailModuleList * p_strtAvailModuleList);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. February 02 2015
*Function name: VehicleData_OBD2_Sid9_IPT_IsSupport
*Descrtiption : check to see whether IPT Data in OBD2 is supported
*Input        : none
*Output       : enumbool - status of IPT support
*-----------------------------------------------------------------------------*/
enumbool    VehicleData_OBD2_Sid9_IPT_IsSupport(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. February 02 2015
*Function name: VehicleData_OBD2_Sid9_IPT_InString_Get
*Descrtiption : parse IPT data from OBD2 data buff and copy to string list buff
*Input        : structIPTList * p_strtIPTList - pointer to buffer to store IPT
*Output       : uint8 - number IPT
*-----------------------------------------------------------------------------*/
enumbool    VehicleData_OBD2_Sid9_IPT_InString_Get(structIPTList * p_strtIPTList);






/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 31 2015
*Function name: VehicleData_OBD2_PCM_IsValid()
*Descrtiption : Check to see whether OBD2 PCM buffer is valid
*Input        : uint8 bPcmBuffIndx - PCM buffer index need to check valid
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OBD2_PCM_IsValid(uint8 bPcmBuffIndx);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan1515 
*Function name: VehicleData_OBD2_IsValid()
*Descrtiption : Check to see whether OBD2 is valid
*Input        : none
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OBD2_IsValid(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 19 2014
*Function name: VehicleDataManager_OBD2_Query()
*Descrtiption : 
*Input        : none
*Output       : enumbool - query success or not

------------------------------------------------------------------------------*/ 
enumbool    VehicleDataManager_OBD2_Query(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan0915
*Function name: VehicleDataManager_OBD2_EngineRunning_Get()
*Descrtiption : Check to see as if OBD2 Engine is Running
            
*Input        : none
*Output       : uint32 - speed of engine

------------------------------------------------------------------------------*/ 
uint32 VehicleDataManager_OBD2_EngineRunning_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 19 2014
*Function name: VehicleDataManager_OBD2_Link()
*Descrtiption : Link to OBD2 (detected before)
                - Read DTC 3, 7, A
                - Read Sid 1, PID 1
                - Read Freeze Frame (Sid 2)
                - Read VIN (just VIN string)
*Input        : none
*Output       : enumbool - link success or not

------------------------------------------------------------------------------*/ 
enumbool    VehicleDataManager_OBD2_Link(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 30 2015
*Function name: VehicleDataManager_OBD2_ReadVehicleInfo()
*Descrtiption : Just read vehicle infor in service 9

*Input        : none
*Output       : enumbool - link success or not

------------------------------------------------------------------------------*/ 
enumbool VehicleDataManager_OBD2_ReadVehicleInfo(void);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 19 2014
*Function name: VehicleDataManager_OBD2_ReadDTC()
*Descrtiption : Just read DTC of OBD2
                - Read DTC 3, 7, A
            use this in case hidden link
            
*Input        : none
*Output       : enumbool - link success or not

------------------------------------------------------------------------------*/ 
enumbool VehicleDataManager_OBD2_ReadDTC(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 19 2014
*Function name: VehicleDataManager_OBD2_EraseDTC()
*Descrtiption : Erase OBD2 DTCs
            
*Input        : none
*Output       : enumbool - erase success or not

------------------------------------------------------------------------------*/ 
enumbool VehicleDataManager_OBD2_EraseDTC(void);




/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 19 2014
*Function name: VehicleDataManager_OBD2_MonitorIcon_Get()
*Descrtiption : Return the monitor icon data (SID 1, PID 1)
            
*Input        : none
*Output       : uint8 * - pointer to the data address contain Sid1, Pid1

------------------------------------------------------------------------------*/
enumbool VehicleDataManager_OBD2_MonitorIcon_Get(enumMFRSystem eSystem,
                                                 uint8 * pDTCRaw);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 20 2014
*Function name: VehicleDataManager_OBD2_FreezeFrameDTC_Get()
*Descrtiption : check to see whether tool got FF DTC
                 - copy FF DTC (as raw) to target buffer in case FF DTC exists
            
*Input        : uint8 * pDTCRaw - pointer to raw buff to store FF DTC as raw
*Output       : enumbool - status of FF DTC 
                    eTRUE - have FF DTC
                    eFALSE - do not have FF DTC

------------------------------------------------------------------------------*/
enumbool VehicleDataManager_OBD2_FreezeFrameDTC_Get(enumMFRSystem eSystem,
                                                    uint8 * pDTCRaw);












/*==============================================================================
                    VEHICLE DATA ACCESS FUNCTIONs
            OEM PROFILEs DATA INVOLVING FUNCTIONs
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Feb0515
*Function name: VehicleDataManager_OEMProfileBuffers_Get()
*Descrtiption : Get pointer to all oem profile buffers
*Input        : none
*Output       : structOemProfile * - pointer first adress of buffer used to store all oem profile buffers

------------------------------------------------------------------------------*/          
structOemProfile* VehicleDataManager_OEMProfileBuffers_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 29 2015
*Function name: VehicleDataManager_ActiveProfile_Set()
*Descrtiption : set initialization profile for linking for the new active group system
            
*Input        : 1 - enumInnovaGroups eLinkGroup - group of system preapare to link

*Output       : none

------------------------------------------------------------------------------*/
void VehicleDataManager_ActiveGroup_Profile_Set(enumInnovaGroups eLinkGroup);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : November 19 2014
*Function name: VehicleDataManager_GroupOEMSystem_Link()
*Descrtiption : Link to group of oem system

*Input        : enumInnovaGroups eLinkGroup - group of system need to link
*Output       : enumbool - link success or not

------------------------------------------------------------------------------*/ 
enumbool    VehicleDataManager_GroupOEMSystem_Link(enumInnovaGroups eLinkGroup);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : January 30 2015
*Function name: VehicleDataManager_GroupOEMSystem_EraseDTC()
*Descrtiption : Erase DTCs of group of system
            
*Input        : none
*Output       : enumbool - erase success or not

------------------------------------------------------------------------------*/ 
enumbool VehicleDataManager_GroupOEMSystem_EraseDTC(enumInnovaGroups eLinkGroup);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Feb0415
*Function name: VehicleData_OEMProfile_IsValid()
*Descrtiption : Check to see whether the OEM profile is valid
*Input        : structOemProfile *p_strtOemProfileBuff - pointer to buff need to check valid
*Output       : enumbool - status of valid

------------------------------------------------------------------------------*/ 
enumbool VehicleData_OEMProfile_IsValid(structOemProfile *p_strtOemProfileBuff);











extern void UserBreakFunction_Register(enumSystemStatus (*fCheckBreakFunc)(void));
extern enumSystemStatus UserBreakFunction_StatusCheck(void);

//#warning those functions will be in OBD API
////Function to query 
//extern enumProtocol gf_VBI_OBD2_Query(structVehicleDataBuffer *p_strtVehicleDataBuffer);
////Read MonitorIcon
//extern enumbool gf_VBI_OBD2_ReadMonitorIcon(structVehicleDataBuffer *p_strtVehicleDataBuffer);
////Read VIN number
//extern enumbool gf_VBI_OBD2_ReadVIN(structVehicleDataBuffer *p_strtVehicleDataBuffer);
////Function to read dtc
//extern enumbool gf_VBI_OBD2_ReadDtc(structVehicleDataBuffer *p_strtVehicleDataBuffer);
////Function to Erase
//extern enumbool gf_VBI_OBD2_EraseDtc(structVehicleDataBuffer *p_strtVehicleDataBuffer);
////Function to read other vehicle info in Sid9(CalID, CVN, IPT...)
//extern enumbool gf_VBI_OBD2_ReadVINInfo(structVehicleDataBuffer *p_strtVehicleDataBuffer);

//#ifndef p_strtNWScanLinkProfile
//#define p_strtNWScanLinkProfile           (&g_strtNWScanLinkProfile)
//#endif
extern structLinkProfile         g_strtNWScanLinkProfile;
extern structVehicleProfile      g_strtNWScanVehicleProfile;
extern uint8 strResBufferData[NUM_RES_BUF][MAX_LEN_RES_BUFF];
void gf_UI_SYS_DisplayQueryRegister(structLinkProfile * p_strtLinkProfile,
        void (*DisplayFunction)(structVehDB * strtVehDB,uint8 b_Total,uint8 b_Present));
void gf_UI_SYS_FlashLinkIconRegister(structLinkProfile * p_strtLinkProfile,void(*pflash)(void));

#endif