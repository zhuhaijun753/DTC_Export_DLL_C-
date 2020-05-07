/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: Processes.h
Description: declare all processes in UI
Layer: Application
Accessibility: Each UI process need declare a function prototye and process index here in this file
================================================================================
*******************************************************************************/

#ifndef __PROCESSES_H__
#define __PROCESSES_H__

#include <string.h>

#include "SysProcess.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
typedef void (*fpProcHandler)(void);

typedef struct
{
    SYS_PROC_ID     eProc;
    fpProcHandler   fpProc;
} structProcHandler;

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

//#if _ENABLE_ATE_FUNCTION_
//void ATE_Process(void);
//#endif

//extern process function to use in g_strtPhocHandlerList declare
extern void Proc_ToolInit(void);
extern void Proc_SDCardWarning(void);
extern void Proc_SelectLanguage(void);
extern void Proc_Usb(void);
extern void Proc_SelectUnit(void);
extern void Proc_MainMenu(void);
extern void Proc_FirmwareVersion(void);
extern void Proc_SetupMenu(void);
extern void Proc_AdjustBrightness(void);
extern void Proc_AudibleTone(void);
extern void Proc_FooterSetting(void);
extern void Proc_HotkeyLegends(void);
extern void Proc_OBD1_GM(void);

//YMME selection
extern void Proc_YMMESelection(void);

//Make selection
extern void Proc_Make_Selection(void);

//Waiting
extern void Proc_Waiting(void);

//Tool Library
extern void Proc_ToolLibrary(void);
extern void Proc_LedMeaning(void);
extern void Proc_MonitorIcon(void);
extern void Proc_DTC_Libary(void);

//Low Battery
extern void Proc_BatteryLow(void);

//Power Off the tool
extern void Proc_PowerOff(void);

//DLC Locator
extern void Proc_DLC_Locator(void);


//Battery Alternator health check
extern void Proc_Vehicle_Batery_Health_Check(void);


//Link OBD2 processes
void Proc_OBD2_AutoLink(void);
//Display OBD2 DTC
void Proc_OBD2_DisplayData(void);
//erase OBD2 DTC
void Proc_OBD2_EraseDTC(void);

//obd2 live data view
void Proc_OBD2_LiveData_View(void);

//Vehicle information
void Proc_Vehicle_Info(void);


//Battery Reset
void Proc_Battery_Reset(void);


//Oil Reset
void Proc_Oil_Reset(void);


//system menu
void Proc_SystemMenu(void);

//Network Scan
void Proc_Network_Scan_Link(void);
void Proc_Network_Scan_Erase(void);
void Proc_Network_Scan_DisplayData(void);
void Proc_Network_Scan_OEM_LD(void);

/*
 * Hung Vo , start section added 24 Jan 2015 for testing UI nwscan
 * */
void Proc_NwS_Link(void);
void Proc_NwS_Display(void);
void Proc_NwS_Erase(void);
void Proc_UI_SystemMenu(void);
void Proc_YMMESelection(void);
void Proc_YMME_InFo(void);
void Proc_NWScan_FordEnh(void);
void Proc_NWScan_HondaBodySpecial(void);

void Proc_ViewVehicleID(void);
void Proc_ViewAvailModules(void);
void Proc_VehicleInfo(void);
/*
 * Hung Vo , End section 24 Jan 2015 for testing UI nwscan
 * */
#ifdef __PROCESSES_C__
const structProcHandler g_strtPhocHandlerList[] =
{
    /*==========================================
                PROCESS TOOL INIT
    ===========================================*/
    {
        .eProc  = PROC_TOOL_INIT,
        .fpProc = Proc_ToolInit
    },
    /*==========================================
                PROCESS SD CARD WARNING
    ===========================================*/
    /*Warning SD Card not detect or not valid*/
    {
        .eProc  = PROC_SDCARD_WARNING,
        .fpProc = Proc_SDCardWarning
    },
    /*==========================================
                PROCESS SELECT LANGUAGE
    ===========================================*/
    /*Select Language*/
    {
        .eProc  = PROC_SELECT_LANGUAGE,
        .fpProc = Proc_SelectLanguage
    },
    /*==========================================
                PROCESS SELECT UNIT
    ===========================================*/
    /*Select Unit*/
    {
        .eProc  = PROC_SELECT_UINT,
        .fpProc = Proc_SelectUnit
    },
    /*==========================================
                PROCESS DISPLAY TOOL VERSIONs
    ===========================================*/
    {
        .eProc  = PROC_FIRMWARE_VERSION,
        .fpProc = Proc_FirmwareVersion
    },
    /*==========================================
                MAIN MENU
    ===========================================*/
//    {
//        .eProc  = PROC_MAIN_MENU,
//        .fpProc = Proc_MainMenu
//    },
    /*==========================================
                PROCESS SET UP MENU
          display menu for tool settings option
    ===========================================*/
    {
        .eProc  = PROC_SETUP_MENU,
        .fpProc = Proc_SetupMenu
    },
    {
        .eProc  = PROC_ADJUST_BRIGHTNESS,
        .fpProc = Proc_AdjustBrightness
    },
    {
        .eProc  = PROC_AUDIBLE_TONE,
        .fpProc = Proc_AudibleTone
    },
    {
        .eProc  = PROC_FOOTER_SETTING,
        .fpProc = Proc_FooterSetting
    },
    {
        .eProc  = PROC_HOTKEY_LEGENDS,
        .fpProc = Proc_HotkeyLegends
    },
    
    /*==========================================
                PROCESS YMME SELECTION
    ===========================================*/
    {
        .eProc  = PROC_YMME_SELECTION,
        .fpProc = Proc_YMMESelection
    },
    /*==========================================
                PROCESS MAKE SELECTION
    ===========================================*/
    {
        .eProc  = PROC_MAKE_SELECTION,
        .fpProc = Proc_Make_Selection
    },
    /*==========================================
                PROCESS WAITING
    ===========================================*/
    {
        .eProc  = PROC_WAITING,
        .fpProc = Proc_Waiting
    },
    
    /*==========================================
                PROCESS TOOL LIBRARY
    ===========================================*/
    {
        .eProc  = PROC_TOOL_LIBRARY,
        .fpProc = Proc_ToolLibrary
    },
    {
        .eProc  = PROC_MONITOR_ICON,
        .fpProc = Proc_MonitorIcon
    },
    {
        .eProc  = PROC_LED_MEANING,
        .fpProc = Proc_LedMeaning
    },
    {
        .eProc  = PROC_DTC_LIBRARY,
        .fpProc = Proc_DTC_Libary
    },
    /*==========================================
                PROCESS LOW BATTERY
    ===========================================*/
    {
        .eProc  = PROC_BATTERY_LOW,
        .fpProc = Proc_BatteryLow
    },
    /*==========================================
                PROCESS POWER OFF
    ===========================================*/
    {
        .eProc  = PROC_POWER_OFF,
        .fpProc = Proc_PowerOff
    },
    
    /*==========================================
           PROCESS BATTERY ALTERNATOR HEALTH CHECK
    ===========================================*/
    {
        .eProc  = PROC_DLC_LOCATOR,
        .fpProc = Proc_DLC_Locator
    },
    
    /*==========================================
           PROCESS BATTERY ALTERNATOR HEALTH CHECK
    ===========================================*/
    {
        .eProc  = PROC_BATTERY_HEALTH_CHECK,
        .fpProc = Proc_Vehicle_Batery_Health_Check
    },
    
    
    
    /*==========================================
                PROCESS USB
    ===========================================*/
    {
        .eProc  = PROC_USB,
        .fpProc = Proc_Usb
    },
    /*==========================================================================
                    INSERT YOUR PROCESSes HERE, PLEASE!!!
    ==========================================================================*/
    /*==========================================
          PROCESSes INVOLVING TO OBD2
    ===========================================*/
    {
        .eProc  = PROC_OBD2_AUTO_LINK,
        .fpProc = Proc_OBD2_AutoLink
    },
    {
        .eProc  = PROC_OBD2_PROCESS_DATA,
//        .fpProc = Proc_OBD2_AutoLink
    },
    {
        .eProc  = PROC_OBD2_DISPLAY_DATA,
        .fpProc = Proc_OBD2_DisplayData
    },
    {
        .eProc  = PROC_OBD2_ERASE_DTC,
        .fpProc = Proc_OBD2_EraseDTC
    },
    {
        .eProc  = PROC_OBD2_LIVE_DATA_VIEW,
        .fpProc = Proc_OBD2_LiveData_View
    },
    //OBD2 special test
    {
        .eProc  = PROC_SPECIAL_TEST,
        .fpProc = Proc_OBD2_LiveData_View
    },
    //Vehicle information
    {
        .eProc  = PROC_VEHICLE_INFO,
        .fpProc = Proc_Vehicle_Info
    },
    
    
    
    //Jan2315 Lap Dang added for sytem menu
    //{
    //    .eProc  = PROC_SYSTEM_MENU,
    //    .fpProc = Proc_UI_SystemMenu
    //},

    
    
    //Battery Reset
    {
        .eProc  = PROC_OEM_BAT_RESET,
        .fpProc = Proc_Battery_Reset
    },
    
    //Oil Reset
    {
        .eProc  = PROC_OIL_RESET,
        .fpProc = Proc_Oil_Reset
    },
    
    //NETWORK SCAN
//    {
//       .eProc  = PROC_NETWORK_SCAN_LINK,
//        .fpProc = Proc_Network_Scan_Link
//    },
 //   {
//        .eProc  = PROC_NETWORK_SCAN_ERASE,
//        .fpProc = Proc_Network_Scan_Erase
//    },
//    {
//        .eProc  = PROC_NETWORK_SCAN_DISPLAY_DATA,
//        .fpProc = Proc_Network_Scan_DisplayData
//    },
//    {
//        .eProc  = PROC_NETWORK_SCAN_OEM_LD,
//        .fpProc = Proc_Network_Scan_OEM_LD
//    },
    
    
    /*
         * 24 Jan 2015
         * NWSCAN Testing UI
         * */
        {
            .eProc = PROC_NWSCAN_FORD_ENH,
            .fpProc = Proc_NWScan_FordEnh,
        },
        {
            .eProc = PROC_NWSCAN_HONDA_BODY_SPECIAL,
            .fpProc = Proc_NWScan_HondaBodySpecial,
        },
//
//        {
//            .eProc = PROC_MAIN_MENU,
//            .fpProc = Proc_MainMenu,
//        },

        {
            .eProc = PROC_NWSCAN_NWS_DISPLAY,
            .fpProc = Proc_NwS_Display
        },

//		{
//		            .eProc = PROC_SYSTEM_MENU,
//		            .fpProc = Proc_NwS_Link
//		},
//        {
//            .eProc = PROC_NETWORK_SCAN_LINK,
//            .fpProc = Proc_NwS_Link
//        },
        {
            .eProc = PROC_NWSCAN_NWS_LINK,
            .fpProc = Proc_NwS_Link
        },
        {
            .eProc = PROC_NWSCAN_ERASE,
            .fpProc = Proc_NwS_Erase
        },
        {
            .eProc = PROC_SYSTEM_MENU,
            .fpProc = Proc_UI_SystemMenu
        },
//        {
//            .eProc = PROC_NWSCAN_YMME_INFO,
//            .fpProc = Proc_YMME_InFo
//        },

        /*
         * Ending NWSCAN Testing UI
         * */
        {
            .eProc = PROC_GM_OBD1,
            .fpProc = Proc_OBD1_GM
        },

    //==================================================//
    {
        .eProc  = PROC_NONE,
        .fpProc = NULL
    }
};
#else

#endif


//--------- extern prototype for using outside ----------------------------
extern void OnRestoreAndLeaveProc(void);
extern void OnRestoreAndLeaveCmd(void);
extern void OnBackUpAndEnterProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd);

extern void Proc_Process(void);



#endif

