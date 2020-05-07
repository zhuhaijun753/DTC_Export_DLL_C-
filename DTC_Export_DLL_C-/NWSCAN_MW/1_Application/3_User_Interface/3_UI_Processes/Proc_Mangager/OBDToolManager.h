/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __OBD_TOOL_MANAGER_H__
#define __OBD_TOOL_MANAGER_H__

#include    "LedDriver.h"
#include    "Cable_ID.h"
#include    "OBDToolSetting.h"

#include        "enums.h"
#include    "ymme_enumeration.h"

#include    <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Structure.h>
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/



typedef enum _enumSystemState
{
    SYSTEM_STATE_INITIALIZE,
    SYSTEM_STATE_LINK_OBD2_MODE,
    SYSTEM_STATE_LINK_OBD1_MODE,
    SYSTEM_STATE_REVIEW_OBD2_MODE,
    SYSTEM_STATE_REVIEW_OBD1_MODE,
    SYSTEM_STATE_USB_MODE,
}enumSystemState;

//#warning Lap Dang just declares for testing at first, aThang should declare this on common structure
typedef enum    __enumMFRGroupSystem
{
    eMFRGroupSystem_NONE    = 0,
    
    eMFRGroupSystem_OBD2        = 1,
    eMFRGroupSystem_ENHANCED    = 2,
    eMFRGroupSystem_ECM         = 3,
    eMFRGroupSystem_TCM         = 4,
    eMFRGroupSystem_ABS         = 5,
    eMFRGroupSystem_SRS         = 6,
    eMFRGroupSystem_OBD1        = 7,
    
    eMFRGroupSystem_NWS_MANUAL      = 8,
    eMFRGroupSystem_NWS_ALL         = 9,
    
    eMFRGroupSystem_MAX     = 0xFF
    
}enumMFRGroupSystem;


#pragma pack(1)
/*this structure to handle module info just with basis info
    details info should be process and store on structDTCManger
*/
typedef struct  __structSystemHandler
{
    /*valid status for system - set this field valid if any info valid*/
    uint8                   bValidStatus;/*0xAA: Valid, others: invalid*/
    
    /*May added group system here???*/
    enumMFRGroupSystem      eGroupSystem;
    /*this field handles system type*/
    enumMFRSystem           eSystemType;
    /*this field handles sub-system type*/
    enumMFRSubSystem        eSubSystemType;
    
    /*status of first time linked*/
    enumbool                blIsFirstTimeLinked;

    /*number of DTCs*/
    uint8                   bNoOfDTC;
//    /*current DTC index - from 1*/
//    uint8               bCurDTCIdx;

    /*if FF DTC exist, place it on first poLap Dangion for displaying*/
    enumbool                IsFFDTCExist;

    /*pointer to oem profile buff - store almost info of system
        currently, this oem profile just valid if linked successful
    */
    structOemProfile        *p_strtOemProfile;
    
    
}structSystemHandler;
#pragma pack()

#pragma pack(1)
/*should use common ram buff to store all dtc info
and point all those pointers to that buff*/
typedef struct
{
    //GUI DTC type
    GUI_DTC_TYPE    GUIDTCType;
    //pointer to DTC code string
    uint8   *p_strDTCCode;
    //pointer to Make string
    uint8   *p_strMake;
    //pointer to System string
    uint8   *p_strSystem;
    //pointer to DTC type name string
    uint8   *p_strDTCType;
    //pointer to DTC Def. string
    uint8   *p_strDTCDef;
    
} structDTCInfo;

typedef struct
{
    //Index of DTC in OEM profile - start by zero
    uint8   bDTCIndex;//1byte
    //pointer to system handle for this DTC
    structSystemHandler     *p_strtSystemHandler;
} structDTCProfile;

#define     GROUP_SYSTEM_NUMBER_OF_DTC_MAX     (60)
typedef struct
{
    /*valid status for group system - set this field valid if system in group valid*/
    uint8                   bValidStatus;/*0xAA: Valid, others: invalid*/
    
    /*May added group system here???*/
    enumMFRGroupSystem      eActiveGroupSystem;
    /*this field handles system type*/
    enumMFRSystem           eCurSystemType;
    /*this field handles sub-system type*/
    enumMFRSubSystem        eCurSubSystemType;

    /*if FF DTC exist, place it on first poLap Dangion for displaying*/
    enumbool                IsFFDTCExist;

    /*number of dtc of current active module - should be get each time change system*/
    uint8                   bGroupNoDTC;
    /*current dtc index - should be get and set each time change system*/
    uint8                   bGroupCurDTCIdx;

    /*list of pointer point to system handler of All DTC in group
        - based on the pointer in this list to get current dtc to display on screen
        - This DTC list should be re-arranged follow UI requirement such as
            - some system/subsystem on group need arrange dtc follow dtc type
    */
    structDTCProfile        strtDTCProfile_GroupDTCList[GROUP_SYSTEM_NUMBER_OF_DTC_MAX];
    
    /*structure to store DTC info for displaying on screen
        2 buffs - one for current and another one for next dtc
    */
    structDTCInfo           strtCurrentDTCInfo;
    structDTCInfo           strtNextDTCInfo;
    
    
} structDTCManager;
#pragma pack()

//#warning
//This stucture is used to handle all data needed for processing UI Flow
//All needed variables must be declare in this structure
#define     NUMBER_SYSTEM_SUB_SYSTEM_MAX        (NUM_OEM_PROFILE_MAX+2)
#pragma pack(1)
typedef struct
{
    /*this field handles main state of tool - obd2/obd1/link/review...*/
    enumSystemState eSystemState;
    
    /*this field handles first time tool configure*/
    enumbool        blIsFirstSettingConfig;
    
    /*this field handle cable ID plug into the tool*/
    enumCableId     eCableID;
    
    /*this field show whether tool support Freezeframe Key*/
    enumbool        blIsFFHotKey;
    
    /*this field show the status of battery*/
    enumbool        blIsLowBattery;

    /*this field handle status whether need to save memory for last time*/
    enumbool        blIsPendingSaving;
    
    /*those fields below are to handle relink status enable/disable*/
    enumbool        blAutoReLinkEnable;
    enumbool        blHiddenRelinkEnable;
    
    /*monitor icons raw*/
    uint8           g_MonitorIcon[4];
    /*MIL status*/
    enumbool        blIsMilOn;
    /*Led status*/
    enumLedType     eLedStatus;
    
    
    /*structure to handle system (controller) data for UI processing*/
//    /*pointer to the current active system - processing with UI*/
//    structSystemHandler     *p_strtSysHandler_ActSys;
    /*this is stack buffer to store all system info need for displaying
       -->After linking system, need process data and store in those buffers
    */
    structSystemHandler     strtSystemHandler_SystemList[NUMBER_SYSTEM_SUB_SYSTEM_MAX];
    /*set this flag if any controller valid*/
    enumbool                blVehicleDataValid;
    
    /*
        structure to handle current active group of system dtc display
        This should be re-process each time UI changes the active system
        process this struct for display from strtSystemHandler_SystemList
    */
    structDTCManager        strtActSysDTCDisp;
    
    /*variable counts link failed time to display contact technical...*/
    uint8           bLinkFailTime;
    
    /*April1214 Lap Dang added, display these feature dynamic based on YMME*/
    enumbool        blOilResetSup;
    enumbool        blBatteryResetSup;
    
    
    /*counter for processing UI purpose*/
    uint32          iProcCmdLoop;
    
    
} structOBDToolManager;
#pragma pack()

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
//This variable handle all UI processing involving to vehicle data, link status...
extern __no_init structOBDToolManager g_strtToolManager;

/*
those variables below are used for processing display UI
they currently are pointers to raw buffer with lenght of 1024 bytes
*/
extern void* const MLTextBuffer[NUM_LANG_SUPPORT];
extern void* const MLTextBufferNext[NUM_LANG_SUPPORT];

///*common ram buffer to used for process UI
//currently this ram buff size is 4KB
//*/
//extern void* const MLCommonRamBuff[NUM_LANG_SUPPORT];



/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

enumbool IsOBD1OnVehicle(enumCableId eCable);
enumbool IsOBD2OnVehicle(enumCableId eCable, enumbool blVECU);

void ToolUserInit(void);
void SystemState_Process(void);


//check to see if review mode
enumbool IsSystemReViewOBD1Mode(void);

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 22, 2011
*Function name: EnvironmentRestore
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void EnvironmentRestore(void);

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: IMMonLedSetStatus
*Descrtiption :
*Input        : enumbool blDisplayEnable
*Output       :
*-----------------------------------------------------------------------------*/
void IMMonLedSetStatus(enumbool blDisplayEnable);

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: IMMonLedGetStatus
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
enumbool IMMonLedGetStatus(void);


/*==============================================================================
                        TOOL MANAGER SETTING INFORMATION
        SYSTEM/SUBSYSTEM HANDLER
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 11 2014
*Function name: ToolManager_SystemHandler_OBD2_Set
*Descrtiption : set system handler for OBD2
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_SystemHandler_OBD2_Set(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 11 2014
*Function name: ToolManager_SystemHandler_OBD2_Set
*Descrtiption : set system handler for OBD2
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
enumbool ToolManager_SystemHandler_OBD2_CheckValid(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 11 2014
*Function name: ToolManager_SystemHandler_OBD2_Protocol_Get
*Descrtiption : return protocol of OBD2
*Input        : None
*Output       : enumProtocol - protocol of OBD2
*-----------------------------------------------------------------------------*/
enumProtocol ToolManager_SystemHandler_OBD2_Protocol_Get(void);




/*==============================================================================
                        TOOL MANAGER SETTING INFORMATION
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_SystemState_EnterLinkOBD2Mode
*Descrtiption : first time enter to OBD2 Mode - set up param and state
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_SystemState_EnterLinkOBD2Mode(void);









/*==============================================================================
                        TOOL MANAGER SETTING INFORMATION
        SYSTEM/SUBSYSTEM HANDLER
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 11 2014
*Function name: ToolManager_SystemHandler_OBD2_Set
*Descrtiption : set system handler for OBD2
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_SystemHandler_OBD2_Set(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_Query
*Descrtiption : 
            - Query to chek OBD2 protocol
            
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
#define     ToolManager_ActiveGroupSystem_OBD2_Query      (VehicleDataManager_OBD2_Query)
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_Link
*Descrtiption : 
            - Link to OBD2 to get data
            - Then process data for system handler if link success
*Input        : None
*Output       : enumbool - status of linking
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_OBD2_Link(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 30 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_Link
*Descrtiption : 
            - Read Vehicle Info in service 9 OBD2
*Input        : None
*Output       : enumbool - status of linking
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_OBD2_ReadVehicleInfo(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 30 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_Pcm1Address_Get
*Descrtiption : get PCM buffer 1 (ECM) address
*Input        : None
*Output       : uint32 - address of PCM buffer 1 (ECM)
*-----------------------------------------------------------------------------*/
uint32 ToolManager_ActiveGroupSystem_OBD2_Pcm1Address_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 30 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_Pcm2Address_Get
*Descrtiption : get PCM buffer 2 (TCM) address
*Input        : None
*Output       : uint32 - address of PCM buffer 2 (TCM)
*-----------------------------------------------------------------------------*/
uint32 ToolManager_ActiveGroupSystem_OBD2_Pcm2Address_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 31 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_CalID_ListStr_Get
*Descrtiption : get CAL ID string list
*Input        : structCalIDList * p_strtCalIDList - pointer to buffer to store cal ID
*Output       : uint8 - number CAL ID
*-----------------------------------------------------------------------------*/
uint8 ToolManager_ActiveGroupSystem_OBD2_CalID_ListStr_Get(structCalIDList * p_strtCalIDList);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 31 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_CalID_ListStr_Get
*Descrtiption : get CVN string list
*Input        : structCVNList * p_strtCVNList - pointer to buffer to store CVN
*Output       : uint8 - number CVN
*-----------------------------------------------------------------------------*/
uint8 ToolManager_ActiveGroupSystem_OBD2_CVN_ListStr_Get(structCVNList * p_strtCVNList);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. February 02 2015
*Function name: ToolManager_Vehicle_AvailableModule_Info_Get
*Descrtiption : get available module list info (currently just module address and protocol)
*Input        : structAvailModuleList * p_strtAvailModuleList - pointer to buffer to store valid modules
*Output       : uint8 - number valid module
*-----------------------------------------------------------------------------*/
uint8 ToolManager_Vehicle_AvailableModule_Info_Get(structAvailModuleList * p_strtAvailModuleList);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. February 02 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_IPT_IsSupport
*Descrtiption : check to see whether IPT is supported
*Input        : none
*Output       : enumbool - status of IPT support
*-----------------------------------------------------------------------------*/
enumbool    ToolManager_ActiveGroupSystem_OBD2_IPT_IsSupport(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. February 02 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_IPT_ListStr_Get
*Descrtiption : get IPT string list
*Input        : structIPTList * p_strtIPTList - pointer to buffer to store IPT
*Output       : uint8 - number IPT
*-----------------------------------------------------------------------------*/
uint8 ToolManager_ActiveGroupSystem_OBD2_IPT_ListStr_Get(structIPTList * p_strtIPTList);




/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_ReadDTC
*Descrtiption : 
            - Just read OBD2 DTC (sid3, 7, A)
            - Then process data for system handler if read dtc success
*Input        : None
*Output       : enumbool - status of linking
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_OBD2_ReadDTC(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 05 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_ErasingDTC
*Descrtiption : Erase OBD2 DTCs
*Input        : None
*Output       : enumbool - status of erasing
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_OBD2_ErasingDTC(void);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_IsValid
*Descrtiption : check to see whether OBD2 data is valid
*Input        : None
*Output       : enumbool - status of OBD2 data (eTRUE - Valid; eFALSE - invalid)
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_OBD2_IsValid(void);






















/*==============================================================================
                        TOOL MANAGER SETTING INFORMATION
        PROCESS ENTER TO some Modes of tool
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_SystemState_EnterLinkOBD2Mode
*Descrtiption : first time enter to OBD2 Mode - set up param and state
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_SystemState_EnterLinkOBD2Mode(void);



/*==============================================================================
                        TOOL MANAGER SETTING - LINK STATE
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolManager_SystemState_Set
*Descrtiption : get current link state - field eSystemState in g_strtToolManager

*Input        : none
*Output       : enumSystemState - state of tool
*-----------------------------------------------------------------------------*/
void ToolManager_SystemState_Set(enumSystemState eSystemState);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolManager_SystemState_Get
*Descrtiption : get current link state - field eSystemState in g_strtToolManager

*Input        : none
*Output       : enumSystemState - state of tool
*-----------------------------------------------------------------------------*/
enumSystemState ToolManager_SystemState_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 19 2014
*Function name: ToolManager_EnterSystemMode
*Descrtiption : Disable interupt
                - Free Timer
                - Button

*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void ToolManager_EnterSystemMode(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 19 2014
*Function name: ToolManager_LeaveSystemMode
*Descrtiption : Enable interupt
                - Free Timer
                - Button

*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void ToolManager_LeaveSystemMode(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2015
*Function name: ToolManager_FreeTimerStop
*Descrtiption : Disable interupt timer during linking
                - Free Timer

*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void ToolManager_FreeTimerStop(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2015
*Function name: ToolManager_TimerRestore
*Descrtiption : restore interupt timer status
                - Free Timer

*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void ToolManager_TimerRestore(void);






/*==============================================================================
                        TOOL MANAGER SETTING INFORMATION
        OTHER CONFIGURATION - need for handle UI
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_AutoRelink_Set
*Descrtiption : set field auto relink blAutoReLinkEnable config in g_strtToolManager structure
                this field is used to check to auto relink current active group system
               
*Input        : enumbool blValue - logic value need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_AutoRelink_Set(enumbool blValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_AutoRelink_Get
*Descrtiption : Get blAutoReLinkEnable field in g_strtToolManager
                this field is used to check to auto relink current active group system

*Input        : none
*Output       : enumbool - status of auto relink setting
*-----------------------------------------------------------------------------*/
enumbool ToolManager_AutoRelink_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_HiddenRelink_Set
*Descrtiption : set field auto hidden relink blHiddenRelinkEnable config in g_strtToolManager structure
                this field is used to check to auto hidden relink current active group system
               
*Input        : enumbool blValue - logic value need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_HiddenRelink_Set(enumbool blValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_AutoRelink_Get
*Descrtiption : Get blHiddenRelinkEnable field in g_strtToolManager
                this field is used to check to auto hidden relink current active group system

*Input        : none
*Output       : enumbool - status of auto hidden relink setting
*-----------------------------------------------------------------------------*/
enumbool ToolManager_HiddenRelink_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_MILStatus_Set
*Descrtiption : set field MIL status in g_strtToolManager structure
                this field is used to check whether vehicle MIL On/Off
               
*Input        : enumbool blValue - logic value need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_MILStatus_Set(enumbool blValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_MILStatus_Get
*Descrtiption : Get blIsMilOn field in g_strtToolManager
                this field is used to check whether vehicle MIL On/Off

*Input        : none
*Output       : enumbool - status of  MIL setting
*-----------------------------------------------------------------------------*/
enumbool ToolManager_MILStatus_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_MILStatus_Set
*Descrtiption : set field eLedStatus status in g_strtToolManager structure
                this field is used to check status of LED is displayed on tool
               
*Input        : enumLedType blValue - Led type value need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_LEDStatus_Set(enumLedType blValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 10 2014
*Function name: ToolManager_MILStatus_Get
*Descrtiption : Get blIsMilOn field in g_strtToolManager
                this field is used to check status of LED is displayed on tool

*Input        : none
*Output       : enumLedType - status of  LED setting
*-----------------------------------------------------------------------------*/
enumLedType ToolManager_LEDStatus_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 13 2014
*Function name: ToolManager_FirstSettingConfig_Set
*Descrtiption : set field first setting config in g_strtToolManager structure
                this field is used to check as if first time power up tool
                so all tool setting is invalid
*Input        : enumbool blValue - logic value need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_FirstSettingConfig_Set(enumbool blValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolManager_FirstSettingConfig_Get
*Descrtiption : Get blIsFirstSettingConfig field in g_strtToolManager
                this field is used to check as if first time power up tool

*Input        : none
*Output       : enumbool - status of SDCard setting
*-----------------------------------------------------------------------------*/
enumbool ToolManager_FirstSettingConfig_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 13 2014
*Function name: ToolManager_CableID_Set
*Descrtiption : set field eCableID in g_strtToolManager

*Input        : enumbool blValue - logic value need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_CableID_Set(enumCableId eCableID);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolManager_CableID_Get
*Descrtiption : get field eCableID in g_strtToolManager

*Input        : none
*Output       : enumbool - status of SDCard setting
*-----------------------------------------------------------------------------*/
enumCableId ToolManager_CableID_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1515
*Function name: ToolManager_VehicleDataValid_Set
*Descrtiption : set field blVehicleDataValid in g_strtToolManager

*Input        : enumbool eStatus - valid status for vehicle data, UI based on this field
                                to consider whether vehicle data is valid or not
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolManager_VehicleDataValid_Set(enumbool eStatus);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1515
*Function name: ToolManager_VehicleDataValid_Get
*Descrtiption : Get blVehicleDataValid field in g_strtToolManager
                this field is used to determine as if current vehicle data on RAM is valid

*Input        : none
*Output       : enumbool - status of valid
*-----------------------------------------------------------------------------*/
enumbool ToolManager_VehicleDataValid_Get(void) ;






/*==============================================================================
                        TOOL MANAGER SETTING INFORMATION
        ACTIVE GROUP SYSTEM DTCs
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_ActiveGroupSystem_MemoryClear
*Descrtiption : reset active group system for all UI process
                 - clear memory of variable handle this
                - 
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_ActiveGroupSystem_MemoryClear(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_ActiveGroupSystem_Set
*Descrtiption : set active group system for all UI process
                - check current active to set to new active group system
                - 
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_ActiveGroupSystem_SetChange(enumMFRGroupSystem eGroupSystem);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: ToolManager_ActiveGroupSystem_Get
*Descrtiption : get active group system for all UI process
                
*Input        : None
*Output       : enumMFRGroupSystem - current actived group system 
*-----------------------------------------------------------------------------*/
enumMFRGroupSystem ToolManager_ActiveGroupSystem_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_ProcessData
*Descrtiption : set active group system for OBD2 group system
                - check all system handler to get valid system 
                    --> process and copy dtc and other info to active group handler buff
                    --> sort dtc in active group handler buff follow dtc type for all valid systems
                - set valid status if any system in group valid
                - check to see whether FF is exist
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_ActiveGroupSystem_OBD2_ProcessData(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_NumberDTC_Get
*Descrtiption : Get number of OBD2 DTC

*Input        : None
*Output       : uint8 - no. of DTC
*-----------------------------------------------------------------------------*/
uint8   ToolManager_ActiveGroupSystem_OBD2_NumberDTC_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 21 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_FFExist_Get
*Descrtiption : Get status of FF DTC

*Input        : None
*Output       : enumbool - status of FF DTC
                    eTRUE - eixst
                    eFALSE - not exist
*-----------------------------------------------------------------------------*/
enumbool    ToolManager_ActiveGroupSystem_OBD2_FFExist_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 21 2014
*Function name: ToolManager_ActiveGroupSystem_OBD2_FFData_Get
*Descrtiption : Get FF data details

*Input        : None
*Output       : uint16 - number item supported

*-----------------------------------------------------------------------------*/
uint16    ToolManager_ActiveGroupSystem_OBD2_FFData_Get(const void ** p_strNameList,
                                                        const void ** p_strValueList);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 16 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_LDItemList_Get
*Descrtiption : Get LD item supported and name, value, for first displaying

*Input        : None
*Output       : uint16 - number item supported

*-----------------------------------------------------------------------------*/
uint16    ToolManager_ActiveGroupSystem_OBD2_LDItemList_Get(const void ** p_strNameList,
                                                            const void ** p_strValueList);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 16 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_LDItemList_Get
*Descrtiption : Get LD item supported and name, value, for first displaying

*Input        : None
*Output       : uint16 - number item supported

*-----------------------------------------------------------------------------*/
enumbool    ToolManager_ActiveGroupSystem_OBD2_LD_LiveDataValue_Get(uint16    sStartItemIdx,
                                                                    uint16    sNoReadItem);
                
                                                            
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 16 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_LDFF_NoSupItem_Get
*Descrtiption : Get LD FF number supported items
                This function should be called after get LD/FF data details \
                        by function ToolManager_ActiveGroupSystem_OBD2_FFData_Get
                         or ToolManager_ActiveGroupSystem_OBD2_LDItemList_Get
            currently, using just one variable to handle LD and FF is p_strtLDFFSuppoted
            may seperate this in the future if got problem when running (may need LD and FF at the same time)
*Input        : None
*Output       : uin16 - number item supported

*-----------------------------------------------------------------------------*/
uint16    ToolManager_ActiveGroupSystem_OBD2_LDFF_NoSupItem_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 10 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_FF_ItemNameFullTerm_Get
*Descrtiption : Get FF item name full term
                This function should be called just after get FF data details \
                        by function ToolManager_ActiveGroupSystem_OBD2_FFData_Get  
                            or ToolManager_ActiveGroupSystem_OBD2_LDItemList_Get
*Input        : None
*Output       : enumbool - status of getting FF item full term 

*-----------------------------------------------------------------------------*/
enumbool    ToolManager_ActiveGroupSystem_OBD2_FF_ItemNameFullTerm_Get(uint16 Lap DangemIdx,
                                                                       uint8 * p_bItemFullTerm);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 16 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_LD_ItemNameFullTerm_Get
*Descrtiption : Get LD item name full term
                This function should be called just after get LD data details \
                        by function ToolManager_ActiveGroupSystem_OBD2_FFData_Get  
                            or ToolManager_ActiveGroupSystem_OBD2_LDItemList_Get
*Input        : None
*Output       : enumbool - status of getting LD item full term 

*-----------------------------------------------------------------------------*/
enumbool    ToolManager_ActiveGroupSystem_OBD2_LD_ItemNameFullTerm_Get(uint16 Lap DangemIdx,
                                                                       uint8 * p_bItemFullTerm);



/*------------------------------------------------------------------------------
*Engineer     : December
*Historical   : 1. January 03 2015
*Function name: ToolManager_ActiveGroupSystem_OBD2_EngineSpeed_Get
*Descrtiption : Get Engine Speed
                 
*Input        : None
*Output       : uint32 - engine speed

*-----------------------------------------------------------------------------*/
uint32    ToolManager_ActiveGroupSystem_OBD2_EngineSpeed_Get(void);








/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 29 2015
*Function name: ToolManager_ActiveGroupSystem_GroupOEMSystem_ProcessData
*Descrtiption : set active group system for OEM group system
                - check all system handler to get valid system 
                    --> process and copy dtc and other info to active group handler buff
                    --> sort dtc in active group handler buff follow dtc type for all valid systems
                - set valid status if any system in group valid
                //- check to see whether FF is exist
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void ToolManager_ActiveGroupSystem_GroupOEMSystem_ProcessData(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 29 2015
*Function name: ToolManager_ActiveGroupSystem_OEMSystem_Linking
*Descrtiption : 
            - Link to OEM system in the current active group system to get data
            - Then process data for system handler if link success
*Input        : None
*Output       : enumbool - status of linking
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_GroupOEMSystem_Linking(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 30 2015
*Function name: ToolManager_ActiveGroupSystem_GroupOEMSystem_ErasingDTC
*Descrtiption : Erase DTCs of the current active group system
*Input        : None
*Output       : enumbool - status of erasing
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_GroupOEMSystem_ErasingDTC(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 29 2015
*Function name: ToolManager_ActiveGroupSystem_GroupOEMSystem_IsValid
*Descrtiption : check to see whether current active group system data is valid
*Input        : None
*Output       : enumbool - status of current active group system (eTRUE - Valid; eFALSE - invalid)
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_GroupOEMSystem_IsValid(void);














/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: ToolManager_ActiveGroupSystem_ValidStatus_Get
*Descrtiption : - check status of the current active group system whether 
                    it is valid
                - 
*Input        : None
*Output       : enumbool - valid status of active group system
*-----------------------------------------------------------------------------*/
enumbool ToolManager_ActiveGroupSystem_ValidStatus_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 25 2014
*Function name: ToolManager_ActiveGroupSystem_NumberDTC_Get
*Descrtiption : - get number DTC of active group system
                    
                - 
*Input        : None
*Output       : uint8 - index of current DTC
*-----------------------------------------------------------------------------*/ 
uint8 ToolManager_ActiveGroupSystem_NumberDTC_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 25 2014
*Function name: ToolManager_ActiveGroupSystem_CurrentDTC_Index_Increase
*Descrtiption : - increase current DTC index of active group system
                    
                - 
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/ 
void ToolManager_ActiveGroupSystem_CurrentDTC_Index_Increase(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 25 2014
*Function name: ToolManager_ActiveGroupSystem_CurrentDTC_Index_Decrease
*Descrtiption : - decrease current DTC index of active group system
                    
                - 
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/ 
void ToolManager_ActiveGroupSystem_CurrentDTC_Index_Decrease(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 25 2014
*Function name: ToolManager_ActiveGroupSystem_CurrentDTC_Index_Reset
*Descrtiption : - reset current DTC index of active group system to start index
                    
                - 
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/ 
void ToolManager_ActiveGroupSystem_CurrentDTC_Index_Reset(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 25 2014
*Function name: ToolManager_ActiveGroupSystem_CurrentDTC_Index_Get
*Descrtiption : - get current DTC index of active group system
                    
                - 
*Input        : None
*Output       : uint8 - index of current DTC
*-----------------------------------------------------------------------------*/ 
uint8 ToolManager_ActiveGroupSystem_CurrentDTC_Index_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 02 2015
*Function name: ToolManager_ActiveGroupSystem_CurrentDTC_IsFirstIndex
*Descrtiption : - check to see whether the current dtc is the first dtc
                    
*Input        : None
*Output       : enumbool - status of current dtc index
                eTRUE - current dtc is first dtc
                eFALSE - current dtc is not the first dtc
*-----------------------------------------------------------------------------*/ 
enumbool ToolManager_ActiveGroupSystem_CurrentDTC_IsFirstIndex(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 25 2014
*Function name: ToolManager_ActiveGroupSystem_CurrentDTC_Info_Get
*Descrtiption : - get current DTC information to display on UI
                    
                - 
*Input        : None
*Output       : structDTCInfo* - pointer to current dtc info structure data

* NOTE:     This function get info and store some data on common ram buffer bCommonRamBuff
*-----------------------------------------------------------------------------*/ 
typedef enum __enumDTCContent
{
    eDTCCONTENT_UNKNOWN     = 0,
    
    eDTCCONTENT_FIX_ASSIST  = 1,
    eDTCCONTENT_DEFINITION  = 2,
    
    eDTCCONTENT_MAX         = 0xFF
}enumDTCContent;

structDTCInfo* ToolManager_ActiveGroupSystem_DTC_Info_Get(enumDTCContent eDTCContent);

#define ToolManager_ActiveGroupSystem_CurrentDTC_Info_Get()   (ToolManager_ActiveGroupSystem_DTC_Info_Get(eDTCCONTENT_DEFINITION))

#define ToolManager_ActiveGroupSystem_FixDTC_Info_Get()   (ToolManager_ActiveGroupSystem_DTC_Info_Get(eDTCCONTENT_FIX_ASSIST))


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January2415
*Function name: ToolManager_DTC_Info_WithJustMakeSystem_Get
*Descrtiption : - get dtc info - definition in case just just have make and system
                    
                - 
*Input        : structDTCInfo   *p_strtDTCInfo --> pointer to struct to store dtc info
                                                     enumMake   eMake - make to get def
                                                     enumSystem eSystem - system to get def
*Output       : enumbool - status of getting dtc info

* NOTE:     This function get info and store some data on common ram buffer bCommonRamBuff
*-----------------------------------------------------------------------------*/
enumbool ToolManager_DTC_Info_WithJustMakeSystem_Get(structDTCInfo   *p_strtDTCInfo,
                                                     enumMake   eMake,
                                                     enumSystem eSystem);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 19 2014
*Function name: ToolManager_ActiveGroupSystem_LinkFailedCount_Increase
*Descrtiption : - increase number link failed time of current active group system by 1
                    
                - 
*Input        : None
*Output       : uint8 - number time linked fail
*-----------------------------------------------------------------------------*/
void ToolManager_ActiveGroupSystem_LinkFailedCount_Increase(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 19 2014
*Function name: ToolManager_ActiveGroupSystem_LinkFailedCount_Get
*Descrtiption : - get number link failed time of current active group system
                    
                - 
*Input        : None
*Output       : uint8 - number time linked fail
*-----------------------------------------------------------------------------*/ 
uint8   ToolManager_ActiveGroupSystem_LinkFailedCount_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_ActiveGroupSystem_LinkFailedCount_Reset
*Descrtiption : - reset number link failed time of current active group system
                    
                - 
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/ 
void ToolManager_ActiveGroupSystem_LinkFailedCount_Reset(void);
















/*==============================================================================
                        TOOL MANAGER 
        OTHER FUNCTIONs - need for handle UI
==============================================================================*/

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_YMMEProfile_IsValid
*Descrtiption : get status of YMME profile

*Input        : none
*Output       : enumbool - status of YMME profile (eTRUE - valid; eFALSE - invalid)
*-----------------------------------------------------------------------------*/
enumbool ToolManager_YMMEProfile_IsValid(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 20 2014
*Function name: ToolManager_YMMEProfile_IsValid
*Descrtiption : get status of YMME profile

*Input        : none
*Output       : enumbool - status of YMME profile VIN string
                eTRUE - valid VIN string
                eFALSE - invalid VIN string
*-----------------------------------------------------------------------------*/
enumbool ToolManager_YMMEProfile_VINString_Get(uint8* p_bVINStr);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2315
*Function name: ToolManager_YMMEProfile_Make_Get
*Descrtiption : get make of YMME profile

*Input        : none
*Output       : enumMake - make of YMME profile

*-----------------------------------------------------------------------------*/
enumMake ToolManager_YMMEProfile_Make_Get(void);


#endif

