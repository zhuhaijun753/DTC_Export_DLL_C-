/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: SysProcess.h
Description: Declare enumerations and fucntions prototype use for system process
Layer: Application
Accessibility: All UI processes may use this
================================================================================
*******************************************************************************/

#ifndef __SYS_PROCESS_H__
#define __SYS_PROCESS_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define SYS_PROC_CMD_DEEPTH          30
typedef enum
{
    /*==========================================================================
                    FIXED AREA DECLARE - DO NOT CHANGE
    ==========================================================================*/
    PROC_NONE                    = 0,
    
    PROC_CURRENT                 = 1,
    PROC_PREVIOUS                = 2,
    
    PROC_TOOL_INIT               = 3,
    
    /*==========================================================================
                    USER UI PROCESSES - ADD MORE FROM HERE
    ==========================================================================*/
    PROC_WAITING                    ,
    PROC_BATTERY_LOW                ,
    PROC_POWER_OFF                  ,
    PROC_SDCARD_WARNING             ,
    PROC_USB                        ,
    PROC_MAIN_MENU                  ,
    
    PROC_FIRMWARE_VERSION           ,
    
    PROC_TOOL_LIBRARY               ,
    PROC_GLOSSARY                   ,
    PROC_MONITOR_ICON               ,
    PROC_DTC_LIBRARY                ,
    PROC_LED_MEANING                ,
    
    
    PROC_SETUP_MENU                 ,
    PROC_ADJUST_BRIGHTNESS          ,
    PROC_AUDIBLE_TONE               ,
    PROC_FOOTER_SETTING             ,
    PROC_HOTKEY_LEGENDS             ,
    PROC_SELECT_LANGUAGE            ,
    PROC_SELECT_UINT                ,
    
    
    PROC_YMME_SELECTION             ,
    //Jan2715 Lap Dang added for select Make
    PROC_MAKE_SELECTION             ,
    
    PROC_DLC_LOCATOR                ,
    PROC_BATTERY_HEALTH_CHECK       ,
    
    /*-------- OBD2 ----------*/
    PROC_OBD2_AUTO_LINK             ,
    PROC_OBD2_PROCESS_DATA          ,
    PROC_OBD2_DISPLAY_DATA          ,
    PROC_OBD2_ERASE_DTC             ,
    PROC_OBD2_LIVE_DATA_VIEW        ,
    PROC_OBD2_LIVE_DATA_MENU        ,
    PROC_SPECIAL_TEST               ,
    PROC_VEHICLE_INFO               ,
    /*-------- SYSTEM MENU -----------*/
    PROC_SYSTEM_MENU                ,
    
    PROC_OIL_RESET                  ,
    PROC_OEM_BAT_RESET              ,
    
    /*-------- NETWORK SCAN -----------*/
    PROC_NETWORK_SCAN_LINK          ,
    PROC_NETWORK_SCAN_DISPLAY_DATA  ,
    PROC_NETWORK_SCAN_ERASE         ,
    PROC_NETWORK_SCAN_OEM_LD        ,
    
    PROC_NWSCAN_HONDA_BODY_SPECIAL,
    PROC_NWSCAN_NWS_DISPLAY,
    PROC_NWSCAN_FORD_ENH,
    PROC_NWSCAN_ERASE,
    PROC_NWSCAN_NWS_LINK,


    /*OBD1 for testing only*/

    PROC_OBDIFORDWIG=300,//Avoid effect on other existed process from lib ui
    PROC_OBDIFORDTIM,
    PROC_OBDIFORDOUT,
    PROC_OBDIFORDMAINMENU,
    PROC_OBDIFORDKOER,
    PROC_OBDIFORDKOEO,
    PROC_OBDIFORDERASE,
    PROC_OBDIFORDCYL,
    PROC_GM_OBD1,
    /*==========================================================================
            END OF USER UI PROCESSes
    ==========================================================================*/
    PROC_ID_MAX =   0xFFFF
        
} SYS_PROC_ID;

typedef enum
{
    /*==========================================================================
                    FIXED AREA DECLARE - DO NOT CHANGE
    ==========================================================================*/
    CMD_NONE                                    = 0,
    /*------- BASIC COMMANDs -------------*/
    CMD_CURRENT                                 = 1,
    CMD_PREVIOUS                                = 2,
    CMD_INIT_PROC                               = 3,
    CMD_END_PROC                                = 4,
    CMD_EXIT                                    = 5,
    CMD_DISP                                    = 6,
    CMD_WAITING                                 = 7,
    
    /*==========================================================================
                USER UI COMMANDs - ADD MORE FROM HERE
    ==========================================================================*/
    CMD_PROCESSING_DATA                         ,
    CMD_DISPLAY_INVALID                         ,
    CMD_DISP_MENU                               ,
    
    
    /*-------- TOOL INIT ----------------*/
    CMD_TOOL_INIT_CHECK_SYS_SETTING             ,
    CMD_TOOL_INIT_CHECK_SD_CARD                 ,
    
    /*--------- SD CARD WARNING ------*/
    CMD_SD_NOT_DETECT                           ,
    CMD_SD_NOT_VALID                            ,
    
    
    /*-------- TOOL SETTING -------------*/
    
    
    /*-------- TOOL LIBRARY -------------*/
    CMD_DISP_NON_CONT_MON_ICON                  ,
    CMD_DISP_OTHERS_ICON                        ,
    
    
    /*-------- TOOL VERSION INFO -------*/
    CMD_HONDA_BODY_INFORM_RESULT,
    CMD_HONDA_BODY_ERROR,
    
    CMD_HONDA_OPTION_1,//Special command for Honda
    CMD_HONDA_OPTION_255=CMD_HONDA_OPTION_1+255,//Special command for Honda
    
    CMD_REFRESH_DISPLAY_DTC_BODY_KW_AS_ACTIVE_OPTION,
    
    CMD_FORD_ON_DEMAND_DISPLAY,
    CMD_FORD_ON_DEMAND_READ_CM,
    CMD_FORD_ON_DEMAND_READ_KOEO,
    CMD_FORD_ON_DEMAND_READ_KOER,
    CMD_FORD_ON_DEMAND_READ_KOEO_INJECTOR,
    CMD_FORD_ON_DEMAND_READ_KOER_GLOWPLUG,
    CMD_FORD_ON_DEMAIN_READ_OD,
    CMD_FORD_ON_DEMAND_LINK_FAIL,
    CMD_FORD_ON_DEMAND_LINK_SUCCESS,
    CMD_NWS_DTC_PROCDTC,
    CMD_NWS_DTC_NO_DTC,
    CMD_NWS_PARSER,
    CMD_NWS_DTC_KEEPALIVE,
    CMD_NWS_DTC_LINK_FAIL,
    CMD_SYSTEM_ERASE,
    CMD_OEM_ERASE_YES,
    CMD_OEM_ERASE_NO,
    CMD_OEM_ERASE_CONFIRM,
    CMD_OEM_ERASE_OK,
    CMD_OEM_ERASE_FAIL,
    CMD_OEM_ERASE_END,
    CMD_RELINK_DTC_BODY_KW_OPTION_X,
    CMD_NWS_QUERY,
    CMD_NWS_LINK,
    CMD_SYSMENU_SCANALL_MODULE,
    CMD_NWS_INIT_FASTBAUDS,
    CMD_NWS_INIT_FB,
    CMD_SYSMENU_SEL_SUBSYSTEM,
    CMD_SYSMENU_SEL_SYSTEM,
    CMD_SYSMENU_DISPLAY_MENU,
    CMD_SYSMENU_DISPLAY,
    CMD_SYSMENU_SET_DB_NWSCAN,
    CMD_SYSMENU_END,
    CMD_SYSMENU_AVAIL_MODULES_DISP,
    CMD_SYSMENU_SAVE_SYSTEM,
    CMD_SYSMENU_SAVE_SUBSYSTEM,
    CMD_SYSMENU_SCANALL_MODULEX_LINK,
    CMD_SYSMENU_OBD2,
    CMD_SYSMENU_NWSCAN_MANUAL,
    CMD_SYSMENU_NWSCAN_AUTO,
    CMD_SYSMENU_SELECT_INN_GROUP,
    CMD_SYSMENU_SAVE_INN_GROUP,
    CMD_SYSMENU_INIT_APP,
    CMD_SYSMENU_NOTSUPPORTED,
    CMD_SYSMENU_SCANALL_SUMMARY,
    CMD_NWSCAN_LINK_TO_GROUP,
    CMD_NWSCAN_LINK_TO_SYSTEM,
    

    CMD_FORD_OBD1_WIG,
    CMD_FORD_OBD1_TIM,
    CMD_FORD_OBD1_OUTPUT_STATE,
    CMD_FORD_OBD1_KOER,
    CMD_FORD_OBD1_KOEO,
    CMD_FORD_OBD1_CYL,
    
    CMD_FORD_ENH_MAIN,
    CMD_FORD_LINKING,
	CMD_SYSMENU_FORDOBD1,
    CMD_SYSMENU_GMOBD1,
	CMD_SYSMENU_CHRYSLEROBD1_89_94,
	CMD_SYSMENU_CHRYSLEROBD1_94_95,
	CMD_SYSMENU_HONDAOBD1,
	CMD_SYSMENU_TOYOTAOBD1,

	CMD_SYSMENU_FORD_SPECIAL_FUNCTION,
	CMD_SYSMENU_FORD_LOGIN,
	CMD_SYSMENU_LOGIN_OK,
	CMD_SYSMENU_LOGIN_FAIL,
	CMD_SYSMENU_USER_TEST,
    /*==========================================================================
                END OF USER UI COMMANDs
    ==========================================================================*/
    CMD_ID_MAX  =   0xFFFF
        
}SYS_CMD_ID;

/*==============================================================================
*                     ENUMERATIONs - STRUCTUREs
==============================================================================*/

typedef enum
{
    SCR_DISP_FULL = 0,  //update all again the screen
    SCR_DISP_PART = 1,  //update just part of screen, such as body of info value LD
    SCR_DISP_NONE = 2,  //no update screen
    SCR_DISP_VALUE = 3  //just update value, such as in screen info value LD
}SCR_DISP_TYPE;

typedef struct
{
    SYS_PROC_ID eProc;
    SYS_CMD_ID  eCmd;
    sint32      iSelectedItem;
    SCR_DISP_TYPE eSrcDispType;
    void const* p_Param;
} SYS_PROC_STAT;

typedef struct
{
    uint32 iProcCmdStackSize;
    SYS_PROC_STAT ProcCmdStack[SYS_PROC_CMD_DEEPTH];
} SYS_PROC_STACK;


typedef struct
{
    SYS_PROC_STACK  strtProcStack;
    enumbool        blIsProcChange;
    enumbool        blIsCmdChange;
    enumbool        blIsDataChange;
} SYS_PROC_MANAGER;

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
extern SYS_PROC_MANAGER PROC_Manager;



/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

enumbool SysCmdProcStackIsEmpty(SYS_PROC_STACK* p_CmdProcStatck);
uint32 SysCmdProcStackGetSize(SYS_PROC_STACK* p_CmdProcStatck);

SYS_PROC_STAT* SysCmdProcStackGetTopPtr(SYS_PROC_STACK* p_CmdProcStatck);
SYS_PROC_STAT* SysCmdProcStackGetProcPtrAt(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos);

enumbool SysCmdProcStackRemoveAt(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos);
enumbool SysCmdProcStackRemoveFrom(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos);

void SysCmdProcStackRemove(SYS_PROC_STACK* p_CmdProcStatck,
                           SYS_PROC_STAT* pCmdProc);
void SysCmdProcStackRemoveProc(SYS_PROC_STACK* p_CmdProcStatck,
                               SYS_PROC_ID eProc);

void SysCmdProcStackPush(SYS_PROC_STACK* p_CmdProcStatck,
                         SYS_PROC_STAT* pCmdProc);
void SysCmdProcStackPushProc(SYS_PROC_STACK* p_CmdProcStatck,
                             SYS_PROC_STAT * pCmdProc);

void SysCmdProcStackPop(SYS_PROC_STACK* p_CmdProcStatck);
void SysCmdProcStackPopProc(SYS_PROC_STACK* p_CmdProcStatck);

sint32 SysCmdProcStackGetProcIdx(SYS_PROC_STACK* p_CmdProcStatck,
                                 SYS_PROC_ID eProc);
sint32 SysCmdProcStackGetPrevProcIdx(SYS_PROC_STACK* p_CmdProcStatck);

SYS_PROC_STAT* SysCmdProcStackGetProcPtrAt(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos);

sint32 SysCmdProcStackGetCmdIdx(SYS_PROC_STACK* p_CmdProcStatck,
                                SYS_PROC_ID eProc, SYS_CMD_ID eCmd);

void Proc_StackClean(void);

SYS_PROC_STAT* Proc_GetCurProcPtr(void);
SYS_PROC_ID Proc_GetCurProcID(void);
SYS_CMD_ID Proc_GetCurCmdID(void);

SYS_PROC_STAT* Proc_GetPrevProcPtr(void);
SYS_PROC_ID Proc_GetPrevProcID(void);
SYS_CMD_ID Proc_GetPrevCmdID(void);

void Proc_SetSelectionItem(sint32 iSelectedIdx);
sint32 Proc_GetSelectionItem(void);

SCR_DISP_TYPE Proc_GetDispType(void);
void Proc_SetDispType(SCR_DISP_TYPE eDispType);

void const* Proc_GetParam(void);
void  Proc_SetParam(void const* p_Param);

void Proc_EnterProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd);
void Proc_ChangeProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd);
void Proc_JumpToProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd);
void Proc_LeaveProc(void);


void Proc_EnterCmdNew(SYS_CMD_ID eCmd, sint32 iSelectIdx, SCR_DISP_TYPE eDispType, 
                      const void* p_Param);
void Proc_ChangeCmdNew(SYS_CMD_ID eCmd, sint32 iSelectIdx, SCR_DISP_TYPE eDispType,
                       const void* p_Param);
void Proc_EnterCmd(SYS_CMD_ID eCmd, sint32 iSelectIdx, const void* p_Param);
void Proc_ChangeCmd(SYS_CMD_ID eCmd, sint32 iSelectIdx, const void* p_Param);
void Proc_JumpToCmd(SYS_CMD_ID eCmd);
void Proc_LeaveCmd(void);

enumbool Proc_ProcCmdIsChanged(void);
void Proc_ProcCmdSetChanged(void);
void Proc_ProcCmdClearChanged(void);

enumbool Proc_DataIsChanged(void);
void Proc_DataSetChanged(void);
void Proc_DataClearChanged(void);

void Proc_RemoveFrom(uint32 iPos);
sint32 Proc_GetCmdIdx(SYS_PROC_ID eProc, SYS_CMD_ID eCmd);
void Proc_ManagerInit(void);

sint32 SysCmdProcStackGetProcIdx(SYS_PROC_STACK* p_CmdProcStatck,
                                 SYS_PROC_ID eProc);
SYS_PROC_STAT* SysCmdProcStackGetProcPtrAt(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos);
#endif

