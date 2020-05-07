/******************************************************************************
 ===============================================================================
                         Lap Dang Dev
 * Filename : Makes_Adapter_App.h
 * Description:
 
 *  Created on: Lap Dang  Feb 5, 2015
 *
 *  Version         : V01.00.00
===============================================================================
******************************************************************************/

#ifndef _MAKES_UTILITIES_MAKES_ADAPTER_APP_H_
#define _MAKES_UTILITIES_MAKES_ADAPTER_APP_H_

#ifndef VERSION_NWSCAN_LIB_
#define VERSION_NWSCAN_LIB_ "V01.00.00"
#endif

#ifndef NWS_NUMBER_CMD_BYTE
#define NWS_NUMBER_CMD_BYTE 50
#endif
/*
 * Port old message id to new
 * */

#define NWS_NUMBER_LIST_ENHANCE 8
typedef enum _enumFordEnhDTCType
{
    eFORD_ENH_DTC_NA            = 0,
    
    eFORD_ENH_DTC_CM            = 1,
    eFORD_ENH_DTC_KOEO          = 2,
    eFORD_ENH_DTC_KOER          = 3,
    eFORD_ENH_DTC_KOEO_INJECTOR = 4,
    eFORD_ENH_DTC_KOER_GLOWPLUG = 5,
    eFORD_ENH_DTC_ODO           = 6,
    
    
    eFORD_ENH_OBD1_DTC_WIG=7,
    eFORD_ENH_OBD1_DTC_TIM=8,
    eFORD_ENH_OBD1_DTC_OUTPUT_STATE=9,
    eFORD_ENH_OBD1_DTC_KOER=10,
    eFORD_ENH_OBD1_DTC_KOEO=11,
    eFORD_ENH_OBD1_DTC_CYL=12,

    eFORD_ENH_DTC_MAX       = 0xFF
}enumFordEnhDTCType;
typedef struct _structGetListEnhance
{
    enumFordEnhDTCType  eFordDTCTypeList[NWS_NUMBER_LIST_ENHANCE];
    uint8  bNoItem;
}structGetListEnhance;

typedef enum    __enumFordEnhanceStatus
{
    eFORD_ENHANCE_STATUS_None                   = 0,
    
    eFORD_ENHANCE_STATUS_ENGINE_RUNNING         = 1,
    eFORD_ENHANCE_STATUS_ENGINE_NOT_RUNNING     = 2,
    
    eFORD_ENHANCE_STATUS_NORMAL                 = 3,
    //more other status here
    eFORD_ENHANCE_LINK_SUCCESS                  = 4,  // Link Enhance success
    eFORD_ENHANCE_LINK_FAIL                     = 5,  // Link Enhance fail
    eFORD_ENHANCE_ERASE_SUCCESS                 = 6,  // Erase Enhance success
    eFORD_ENHANCE_ERASE_FAIL                    = 7,  // Erase Enhance fail
    
    eFORD_ENHANCE_OVER_SRPM                     = 8,  
    eFORD_ENHANCE_UNDER_SRPM                    = 9,  
    
    eFORD_ENHANCE_STATUS_MAX                    = 0xFF
}enumFordEnhanceStatus;


#pragma pack(1)
typedef struct  __structDTCList
{
    uint8   bNoDTC;
    uint8*  bDTCIdxList;
}structDTCList;
#pragma pack()

structGetListEnhance* gf_VDM_Ford_GetListEnhance(structGetListEnhance* p_strtGetListEnhance);

typedef enum _enumNwscanLinkStatus
{
    eLink_NA=0,/**/
    eLink_NotSupport=1, /*Nwscan not support this ymme profile*/
    eLink_Success=2,/*Link successful*/
    eLink_Fail=3,/*Link Fail*/
    eLink_Special_FordTest=4,/*Need switch to special testing Ford enhance */
    eLink_Special_HondaTest=5,/*Need switch to special testing Honda enhance */
    eLink_Fail_InputData,/*Input invalid parameter */
	eLink_Fail_UserEvent,/*Error VECU / Key Pressed ....*/
	eLink_Fail_NeedRetry_OEM_Cable,/*Link Fail with present OBDII connector ,
	 	 	 	 	 	 	 	 	 But Detected 1 OE Cable in Database , could be retry with this cable*/
    eLink_Max=255
}enumNwscanLinkStatus;

typedef enum _enumNWSCANType
{
    eNWSCAN_TYPE_NORMAL,
    eNWSCAN_TYPE_FORD_ENH,
    eNWSCAN_TYPE_HONDA_ENH
}enumNWSCANType;
typedef enum _enumFordEnhType
{
    FORD_ENH_NA=0,
    FORD_ENH_OD_1,/*KOEO, KOER*/
    FORD_ENH_OD_2,/*KOEO, KOER, KOEO Injector Code,KOER Glow Plug Code*/
    FORD_ENH_CM,
    FORD_ENH_OBD1
}enumFordEnhType;


#pragma pack(1)

typedef struct _structBodyInfoResult
{
        uint8            bAddrSubBody;
        enumECUTypes     eECUType;
        uint8 eResult;//enumHondaOptions
}structBodyInfoResult;

#define MAX_LIST_SYS_VALUE              255
typedef struct _structNwSSystemUI
{
    uint16 ListItem[MAX_LIST_SYS_VALUE];
    uint8  bNoItem;
}structNwSSystemUI;
#define SYSTEM_NA   0xFFFF
# define LIST_DTC_TYPE 8
# define BYE_RESERVE   5
#pragma pack(1)
typedef struct _structListDTCType
{
#ifdef _MSC_VER
	uint8   eMFRField;
#else
  enumMFRField      eMFRField;
#endif
  uint8             bDTCString[20];
  uint8             bNoItem;
  uint16            sDTCTypeList[LIST_DTC_TYPE];
  uint8             bDTCIndex;
  uint8             bSeverity;
  uint8             bReseve[BYE_RESERVE];
}structListDTCType;
#pragma pack()
typedef struct _structECUInfo
{
  structVehDB * p_strtECUInfoDB;
  enumMFRField    eMFRField;
  uint32          iECUInfo;
  //uint8*          ECUWorkShop;

  uint8           *pStrEcuInfo;

  enumValidCode   eStatus;
}structECUInfo;
typedef struct _structECUIDString
{
  enumMFRField    eMFRField;
  uint8           bStrEcuID[30];
  enumValidCode   eStatus;
}structECUIDString;
#pragma pack()
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_GetNWScanLoadDB
*Input        : void
*Output       : eTRUE : Support this YMME , eFALSE : Not supported
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Oct 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_GetNWScanLoadDB(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_InitVehicleProfile
*Input        : void
*Output       :
*Description  :
*Init vehicle profile with g_strtNWScanVehicleProfile.strtNwSYmme.sSubSystem,sSystem
*@ note  : do not effect on previous oem profile
*
*Historical   :
*     1. Creation Lap Dang Nov 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_InitVehicleProfile(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_ResetAllVehicleProfile
*Input        : void
*Output       :
*Description  :
*Clear status initialize to gf_VDM_InitVehicleProfile will reset all previous oem profile
*
*
*Historical   :
*     1. Creation Lap Dang Nov 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VDM_ResetAllVehicleProfile(void);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_GetListSystem
 *Input        : structNwSSystemUI *p_strtSystemUI,
 structMFRVinProfile* p_strtMFRVinProfile
 enumInnovaGroups eInnovaGroup = INNOVA_GROUP_UNKNOW : will get ignore this field
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 7, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_NWSCAN_GetListSystem(structNwSSystemUI *p_strtSystemUI,
        structMFRVinProfile* p_strtMFRVinProfile,enumInnovaGroups eInnovaGroup);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_GetListSubSystem
 *Input        : structNwSSystemUI *p_strtSystemUI,
 structMFRVinProfile* p_strtMFRVinProfile
 enumInnovaGroups eInnovaGroup = INNOVA_GROUP_UNKNOW : will get ignore this field
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 7, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_NWSCAN_GetListSubSystem(structNwSSystemUI *p_strtSystemUI,
        structMFRVinProfile* p_strtMFRVinProfile,enumInnovaGroups eInnovaGroup);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_SetSystem
 *Input        : enumSystem eSystem
 *Output       :
 *Description  :
 *set system to nwscan ymme profile
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 7, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_SetSystem(enumSystem eSystem);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_SetSubSystem
 *Input        : enumSubSystem eSubSystem
 *Output       :
 *Description  :
 *set subsystem to nwscan ymme profile
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 7, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_SetSubSystem(enumSubSystem eSubSystem);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_SetGroup
 *Input        : enumInnovaGroups eGroup
 *Output       :
 *Description  :
 *set group to nwscan ymme profile
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 7, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_SetGroup(enumInnovaGroups eGroup);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_NWSCAN_GetType
*Input        : structVehicleProfile *pstrtVehicleProfile
*Output       :  enumNWSCANType
       eNWSCAN_TYPE_NORMAL    : Normal type nwscan link
       eNWSCAN_TYPE_FORD_ENH  : special for Ford Enh
       eNWSCAN_TYPE_HONDA_ENH : special for honda process
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Feb 6, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
enumNWSCANType gf_VDM_NWSCAN_GetType(structVehicleProfile *pstrtVehicleProfile);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name:gf_VDM_DtcOEMBuff_GetState
 *Input        :structVehicleProfile *pstrtVehicleProfile
 *Output       : enumOemDtcBuffStatus
 OEM_DTC_INVALID=0,
 OEM_DTC_NOTSUPPORT_DB,//Can not implement since missing database or some problem from ECU : Ex Honda Srs
 OEM_DTC_VALID=0xAA,
 *Description  :
 *get status buffer dtc of active profile
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 6, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumOemDtcBuffStatus gf_VDM_DtcOEMBuff_GetState(structVehicleProfile *pstrtVehicleProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_ReadDtc_Group
 *Input        :structVehicleProfile *pstrtVehicleProfile
 *Input        structMFRVinProfile * pstrtMFRVinProfile
 *Input        enumInnovaGroups eInnGroup : Group is linked to
 *Input        uint8 bNumMaxProfile : maximum profile will be saved data to
 *Output       :number linked module of input group
 *Description  :
 *should set screen display info query
 gf_UI_SYS_DisplayQueryRegister(p_strtNWScanLinkProfile,__UI_OEMScanAll_DisplayInfo)
 If do not set , maybe it will use previous function display query info
 *
 *gf_UI_SYS_FlashLinkIconRegister(p_strtNWScanLinkProfile,
 gf_UI_OBD2_FlashLinkIcon)
 *@After link it will reset function display info
 *Historical   :
 *     1. Creation Lap Dang Feb 5, 2015
 *
 *@Auto query to each module in group
 *
 *
 -------------------------------------------------------------------------------*/
uint8 gf_VDM_NWSCAN_ReadDtc_Group(structVehicleProfile *pstrtVehicleProfile,
        structMFRVinProfile * pstrtMFRVinProfile, enumInnovaGroups eInnGroup,
        uint8 bNumMaxProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_Query_System
 *Input        : structVehicleProfile *pstrtVehicleProfile
 *Input        structMFRVinProfile * pstrtMFRVinProfile,
 *Input        enumSystem eSystem
 *Input        enumSubSystem eSubSystem
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 5, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumNwscanLinkStatus gf_VDM_NWSCAN_Query_System(
        structVehicleProfile *pstrtVehicleProfile,
        structMFRVinProfile * pstrtMFRVinProfile, enumSystem eSystem,
        enumSubSystem eSubSystem);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_ReadDtc_System
 *Input        : structVehicleProfile *pstrtVehicleProfile
 *Input        structMFRVinProfile * pstrtMFRVinProfile,
 *Input        enumSystem eSystem
 *Input        enumSubSystem eSubSystem
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 5, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumNwscanLinkStatus gf_VDM_NWSCAN_ReadDtc_System(
        structVehicleProfile *pstrtVehicleProfile,
        structMFRVinProfile * pstrtMFRVinProfile,
        enumSystem eSystem,
        enumSubSystem eSubSystem);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_KeepAlive_ActiveSystem
 *Input        : structVehicleProfile *pstrtVehicleProfile
 *Output       :
 *Description  :
 *send keepalive service for active system
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 5, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_KeepAlive_ActiveSystem(structVehicleProfile *pstrtVehicleProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VDM_NWSCAN_Erase_ActiveSystem
 *Input        : structVehicleProfile *pstrtVehicleProfile
 *Output       :eTRUE : erase ok , eFALSE : erase fail
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Feb 5, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_NWSCAN_Erase_ActiveSystem(structVehicleProfile *pstrtVehicleProfile);



/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name:structResponseBuffer *gf_VDM_NWSCAN_Link(enumSystem eSystem,
 enumSubSystem eSubSystem,
 enumCommands eCmd,uint8*pCmdData,
 enumbool IsAutoReinit)
 *Input        :
 *Input        enumSystem eSystem,
 enumSubSystem eSubSystem,
 enumCommands eCmd,
 uint8*pCmdData : = Null if use command as enumcommands
                  != Null if use custom command with format : [1byte len][Command data]
 enumbool IsAutoReinit = eTRUE : auto reinit in case fail
 *Output       : structResponseBuffer* = Null if fail
 *Output       Other is successful
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 10, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer *gf_VDM_NWSCAN_Link(enumSystem eSystem,
                                        enumSubSystem eSubSystem, enumCommands eCmd, uint8*pCmdData,
                                         enumbool IsAutoReinit);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_IsHondaBodySpecial
*Input        : enumManufacturer eManufacture,structOemProfile *p_strtOemProfiles
*Output       : eTRUE : special honda body kw
*Description  :
*strtVehDB->EcuInfoParserType == eecuinfotype_ECUType_ID0036 &sSystem ==eSYSTEM_HONDA_SPECIAL
*
*
*Historical   :
*     1. Creation Lap Dang Nov 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_IsHondaBodySpecial(enumManufacturer eManufacture,structOemProfile *p_strtOemProfiles);


/*-----------------------------------------------------------------------------
*Engineer: Hung Vo
*Historical:
*Function name: enumbool gf_VDM_IsHondaSubBodySystem(enumManufacturer eManufacture,structOemProfile *p_strtOemProfiles)
*Descrtiption:
*Input: enumManufacturer eManufacture
*Input: structOemProfile *p_strtOemProfiles
*Output: eTRUE : this module is sub honda module
*Output: eFALSE : this module is not sub honda module
-----------------------------------------------------------------------------*/
enumbool gf_VDM_IsHondaSubBodySystem(enumManufacturer eManufacture,structOemProfile *p_strtOemProfiles);


//////////
enumFordEnhanceStatus   gf_VDM_FordEnhanced_Linking(enumFordEnhDTCType eFordEnhDTCType, uint16 sRPMCondition);
enumFordEnhanceStatus   gf_VDM_FordEnhanced_Erase(enumFordEnhDTCType eFordEnhDTCType);

//return eFALSE if p_strtOemProfileBuff is not Ford Enhance Buffer or can't get dtc list
//return eTRUE and the p_strtDTCList store number dtc and list of dtc index in the p_strtOemProfileBuff
enumbool    gf_VDM_FordEnhanced_DTCList_Get(structDTCList * p_strtDTCList,
                                            uint8  bNoDTCMax,
                                            enumFordEnhDTCType eFordEnhDTCType,
                                            structOemProfile *p_strtOemProfileBuff);

//enumbool gf_VDM_Dtc_GetDTCInfo(structOemProfile *pstrtOemProfile,
//                                        uint8 bIdxDtc,
//                                             structListDTCType *pstrtListDTCType);  

enumbool gf_VDM_FordOBD1_CheckIgnition(uint16 TOff_Ms,void (*pfProgressBar)(uint16 sPercent));

enumbool gf_VDM_FordOBD1_IsIgnitionTurnOn(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_ECUInfo_Get
*Input        :
*Output       :
*Description  :
*
*Historical   :
*     1. Creation Lap Dang Mar 24, 2015
-------------------------------------------------------------------------------*/
void gf_VDM_ECUInfo_Get(enumSystem eSystem,
                          enumSubSystem eSubSystem,
                          structECUInfo * p_strtECUInfo );

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: uint8* gf_VDM_NWSCAN_eCMDToData(enumCommands eCmd,uint8 pRamCmd[NWS_NUMBER_CMD_BYTE])
*Function
*Input        : enumCommands eCmd : ID Need to get corresponse data
*Input        uint8 pRamCmd[NWS_NUMBER_CMD_BYTE] : ram buffer content data
*Output       : null if not found , other : found
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Apr 1, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
uint8* gf_VDM_NWSCAN_eCMDToData(enumCommands eCmd,uint8 pRamCmd[NWS_NUMBER_CMD_BYTE]);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_LinkProfile_Kw_SetHdrType
*Input        : structLinkProfile  *p_strtLinkProfile,enumFormatHeader Init,enumFormatHeader Link
*Output       :
*Description  :
*set init type for keyword
*
*
*Historical   :
*     1. Creation Lap Dang Nov 3, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VBI_LinkProfile_Kw_SetHdrType(structLinkProfile  *p_strtLinkProfile,enumFormatHeader Init,enumFormatHeader Link);


void gf_VDM_ECUID_String(structECUIDString *pstrtECUIDString);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void gf_VDM_NWSCAN_OBD1_Init(enumManufacturer eManufacture,enumMessageIds eMesgID)
*Input        : enumManufacturer eManufacture,enumMessageIds eMesgID
*Output       : eTRUE if supported , eFALSE : Not support
*Description  :
*support 5 Main manufacture obd1 : Ford , GM , Chrysler , Honda , Toyota
*bInnovaGroup=GROUP_OBDI
*
*Historical   :
*     1. Creation Lap Dang Apr 23, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_NWSCAN_OBD1_Init(enumManufacturer eManufacture,enumMessageIds eMesgID);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void *gf_VDM_NWSCAN_Link_SetTiming(uint16 sTimingP2Ms)
*Input        :
*Output       :
*Description  :
*set timing P2 to custom value to handle some special function
*as livedata or special function  that need timing faster or slower when call gf_VDM_NWSCAN_Link
*p2 Max with KW and P2Min with CAN
*Historical   :
*     1. Creation Lap Dang May 4, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_Link_SetTimingP2(uint16 sTimingP2Ms);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_NWSCAN_Exit_ActiveSystem(
        structVehicleProfile *pstrtVehicleProfile)
 *Input        :
 *Output       :
 *Description  :
 *close connection with active system
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:04:12 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_Exit_ActiveSystem(
        structVehicleProfile *pstrtVehicleProfile);



/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumbool gf_VDM_FordOBD1_CheckIgnition(uint16 TOff_Ms,void (*pfProgressBar)(uint16 sPercent))
 *Input        :
 *Output       :
 *Description  :
 *Wait Ignition Off in Toff_Ms and auto reset progress bar if ignition ON detected
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:42:39 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_FordOBD1_CheckIgnition(uint16 TOff_Ms,void (*pfProgressBar)(uint16 sPercent));

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumbool gf_VDM_FordOBD1_IsIgnitionTurnOn(void)
 *Input        :
 *Output       :
 *Description  :
 * Check Ignition is On
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:42:20 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_FordOBD1_IsIgnitionTurnOn(void);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_FordOBD1_Enter_Wiggle_Mode(void)
 *Input        :
 *Output       :
 *Description  :
 *Enter to procedure wiggle test
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:41:55 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_FordOBD1_Enter_Wiggle_Mode(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name:enumBusStatus gf_VDM_FordOBD1_ReadKlineStatus(void)
 *Input        :
 *Output       :
 *Description  :
 *get Kline status level
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:41:08 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumBusStatus gf_VDM_FordOBD1_ReadKlineStatus(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_FordOBD1_KOER_Init(void)
 *Input        :
 *Output       :
 *Description  :
 *Init KOER
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:40:44 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_FordOBD1_KOER_Init(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_FordOBD1_Wait_KLine_High(uint8 Second)
 *Input        :
 *Output       :
 *Description  :
 *wait Kline with high level in n Second
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:40:05 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_FordOBD1_Wait_KLine_High(uint8 Second);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_FordOBD1_Wait_End_Slow_code(void)
 *Input        :
 *Output       :
 *Description  :
 *wait end of slow code ford obd1 signal
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:39:35 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_FordOBD1_Wait_End_Slow_code(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: sint8 gf_VDM_FordOBD1_GetNumberCyclinder(void)
 *Input        :
 *Output       : >=0 if valid , <0 if failure
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:38:50 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
sint8 gf_VDM_FordOBD1_GetNumberCyclinder(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: sint8 gf_VDM_FordOBD1_GetGooseCode(void)
 *Input        :
 *Output       :  >=0 if valid , <0 if failure
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:39:18 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
sint8 gf_VDM_FordOBD1_GetGooseCode(void);



/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: uint16 gf_VDM_NWSCAN_EraseDtc_Group(structVehicleProfile *pstrtVehicleProfile,
		structMFRVinProfile * pstrtMFRVinProfile, enumInnovaGroups eInnGroup,
		uint16 *psNumValidOemProfile)
 *Input        :
 *Output       : number of successful erase controller module
 *Output       psNumValidOemProfile : is number of valid oem profile belong to eInnGroup
 *Description  :
 *erase all existed oemprofile belong to input group
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  9:17:43 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint16 gf_VDM_NWSCAN_EraseDtc_Group(structVehicleProfile *pstrtVehicleProfile,
		structMFRVinProfile * pstrtMFRVinProfile, enumInnovaGroups eInnGroup,
		uint16 *psNumValidOemProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structOemProfile *gf_VDM_IsExistHondaBCMCAN(structVehicleProfile * p_VehicleProfile)
 *Input        : structVehicleProfile * p_VehicleProfile
 *Output       :
 *Description  :
 *check status of special oem module bcm can
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  4:58:35 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structOemProfile *gf_VDM_IsExistHondaBCMCAN(structVehicleProfile * p_VehicleProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name:uint16 gf_VDM_NWSCAN_GetNumberProfileDB(
									structVehicleProfile *pstrtVehicleProfile,
									structMFRVinProfile * pstrtMFRVinProfile,
									enumSystem eSystem,
									enumSubSystem eSubSystem)
 *Input        :
 *Output       :
 *Description  :
 *
 *just get number profile data of this module
 *
 *Historical   :
 *     1. Creation Lap Dang  10:39:41 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint16 gf_VDM_NWSCAN_GetNumberProfileDB(
									structVehicleProfile *pstrtVehicleProfile,
									structMFRVinProfile * pstrtMFRVinProfile,
									enumSystem eSystem,
									enumSubSystem eSubSystem);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_NWSCAN_ReLinkDtcGroup_Set(void)
 *Input        :
 *Output       :
 *Description  :
 * this function will active feature , just relink the valid module
 * auto reset to default feature that call all module exist in DB
 *
 *Historical   :
 *     1. Creation Lap Dang  11:28:28 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWSCAN_ReLinkDtcGroup_Set(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_NWSCAN_ResetConnectorAddition(structVehicleProfile *pstrtVehicleProfile)
 *Input        : structVehicleProfile *pstrtVehicleProfile
 *Output       :
 *Description  :
 *Reset addition connetor
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  3:33:12 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_NWSCAN_ResetConnectorAddition(structVehicleProfile *pstrtVehicleProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumConnectors gf_NWSCAN_GetConnectorAddition(structVehicleProfile *pstrtVehicleProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  3:36:18 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumConnectors gf_NWSCAN_GetConnectorAddition(structVehicleProfile *pstrtVehicleProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_CheckDupplicateSystem
 *Input        :
 *Output       :
 *Description  :
 *
 *Historical   :
 *     1.
 *
 -------------------------------------------------------------------------------*/
enumbool gf_CheckDupplicateSystem(uint16 Lap Dangem, structNwSSystemUI *p_strtSystemUI);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: uint8 gf_VDM_GlobalTruckQuery(structVehicleProfile * p_VehicleProfile,
		structMFRVinProfile * pstrtMFRVinProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  4:43:16 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint8 gf_VDM_GlobalTruckQuery(structVehicleProfile * p_VehicleProfile,
		structMFRVinProfile * pstrtMFRVinProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: uint8 gf_VDM_NWSCAN_Truck_ReadDtc_Group(structVehicleProfile *pstrtVehicleProfile,
		structMFRVinProfile * pstrtMFRVinProfile, enumInnovaGroups eInnGroup,
		uint8 bNumMaxProfile)
 *Description  :
 *should set screen display info query
 gf_UI_SYS_DisplayQueryRegister(p_strtNWScanLinkProfile,__UI_OEMScanAll_DisplayInfo)
 If do not set , maybe it will use previous function display query info
 *
 *gf_UI_SYS_FlashLinkIconRegister(p_strtNWScanLinkProfile,
 gf_UI_OBD2_FlashLinkIcon)
 *@After link it will reset function display info
 *Historical   :
 *     1. Creation Lap Dang Feb 5, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint8 gf_VDM_NWSCAN_Truck_ReadDtc_Group(structVehicleProfile *pstrtVehicleProfile,
		structMFRVinProfile * pstrtMFRVinProfile, enumInnovaGroups eInnGroup,
		uint8 bNumMaxProfile);

#endif /* 2_MIDDLE_2_VEHICLE_INTERFACE_1_OBD_API_NWSCAN_APP_ADAPTER_MAKES_UTILITIES_MAKES_ADAPTER_APP_H_ */

