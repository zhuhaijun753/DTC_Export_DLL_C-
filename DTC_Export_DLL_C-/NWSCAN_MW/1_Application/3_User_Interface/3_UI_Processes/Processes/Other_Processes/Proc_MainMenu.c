
/*******************************************************************************
*Engineer    : Lap Dangruong
*Date        : Oct1514 Lap Dang initialize
*File        : Proc_MainMenu.c
*Description : process display main menu 
*******************************************************************************/
/*############################################################################*/
/*
================================================================================
INCLUDED FILES
================================================================================
*/
#include <PlatFormType.h>
#include <GUIManager.h>

#include "KeyBoardApp.h"
#include    "Processes.h"
#include "OBDToolManager.h"

#include    "Common_Text_Database.h"
#include    "CommonKeyHandler.h"


//extern const structMenuItem* gp_strtCurrSys;
/*******************************************************************************
================================================================================
                            GLOBAL VARIABLES
================================================================================
*******************************************************************************/

const void* const MLMainMenu[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Main Menu",
    "Men� principal",
    "Menu Principal"
);
const void* const MLMainMenuMemory[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Main Menu Memory",
    "Memoria Men� principal",
    "Menu principal M�moire"
);

#define     MLMainMenuTitle             (MLMainMenu)
#define     MLMainMenuMemoryTitle       (MLMainMenuMemory)

#define     MLMainMenuScrnTitle         (MLTextBuffer)
#define     MLMainMenuScrnInstr         (MLMenuInstruction)
#define     MLMainMenuScrnFooter        (MLPressAnyHotKeys)


const void* const MLDLCLocator[NUM_LANG_SUPPORT] =
DefineMLText
(
    "DLC Locator",
    "Ubicaciones del conector de diagn�stico",
    "Localisateur de connecteur de diagnostic"
);

const void* const MLBatteryAlternatorMenuOption[NUM_LANG_SUPPORT] =
DefineMLText
(
   "Battery/Alternator Monitor",
   "Monitor de bater�a/alternador",
    "Moniteur de batterie/alternateur"
);

const void* const MLFirmwareVersion[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Firmware Version",
    "Versi�n de firmware",
    "Version de micrologiciel"
);
const void* const MLToolLibrary[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Tool Library",
    "Colecci�n de herramientas",
	"Biblioth�que d'outils"
);
const void* const MLToolSettingMenu[NUM_LANG_SUPPORT] =
DefineMLText
(
	"Tool Setting",
    "Ajustes de la herramienta",
    "Param�tres d'outil"
);
const void* const MLSpecialTestMenu[NUM_LANG_SUPPORT] =
DefineMLText
(
    "System tests",
	"Pruebas de sistema",
	"Tests de syst�me"
);
const void* const MLVehicleInfoMenu[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Vehicle Information",
    "Informaci�n del veh�culo",
	"Infos sur v�hicule"
);
const void* const MLOilReset[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Oil Reset",
    "Reseteo del aceite",
	"R�initialisation d'huile"
);
const void* const MLBatteryResetMenuOption[NUM_LANG_SUPPORT] =
DefineMLText
(
   "Battery Reset",
   "Restablecimiento de la bater�a",
   "R�initialisation de batterie"
);



structMenuItem p_strtMainMenuList[] =
{
//    {PROC_SPECIAL_TEST    , CMD_INIT_PROC, MLSpecialTestMenu   , eTRUE},
    {PROC_VEHICLE_INFO    , CMD_INIT_PROC, MLVehicleInfoMenu   , eTRUE},
    {PROC_OIL_RESET         , CMD_INIT_PROC            , MLOilReset          , eFALSE} ,
    {PROC_DLC_LOCATOR     , CMD_INIT_PROC, MLDLCLocator      , eTRUE},
//    {PROC_OEM_BAT_RESET         , CMD_INIT_PROC            , MLBatteryResetMenuOption          , eFALSE} ,

    {PROC_BATTERY_HEALTH_CHECK         , CMD_INIT_PROC            , MLBatteryAlternatorMenuOption          , eFALSE} ,
   
    {PROC_FIRMWARE_VERSION    , CMD_INIT_PROC, MLFirmwareVersion   , eTRUE},
    {PROC_TOOL_LIBRARY     , CMD_INIT_PROC, MLToolLibrary      , eTRUE},
    {PROC_SETUP_MENU      , CMD_INIT_PROC, MLToolSettingMenu     , eTRUE},

    {PROC_NONE            , CMD_NONE     , NULL                , eFALSE},
};

const structMenu strtMainMenu =
{
    .MLTitle        = MLMainMenuScrnTitle,
    .MLInstruction  = MLMainMenuScrnInstr,
    .MLFooter       = MLMainMenuScrnFooter,
    .p_strtMenuItemList = p_strtMainMenuList,
};

/*==============================================================================
                        FUCNTIONs SUPPORT FOR DISPLAYING
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Oct1514 Lap Dang initialize
*Function name: MainMenuConfig
*Descrtiption : check to set valid for processes should be displayed in main menu

*Input        : structMenuItem p_strtMenuList[]
*             : structToolSetting* p_strtToolSetting
*Output       :
*-----------------------------------------------------------------------------*/
static void MainMenuConfig(structMenuItem p_strtMenuList[],
                           structToolSetting* p_strtToolSetting)
{
    uint8   bIdx, bSpecialTest;
    uint8   bNoMenu = countof(p_strtMainMenuList);
    for(bIdx = 0; bIdx<bNoMenu; bIdx++)
    {
        if(p_strtMenuList[bIdx].eProc == PROC_SPECIAL_TEST)
        {
            if((ToolSettingOBD2SpecialTest_IsValid())
               &&(ToolManager_ActiveGroupSystem_Get() == eMFRGroupSystem_OBD2)
                   )
            {
                p_strtMenuList[bIdx].blEnable = eTRUE;
                //check if review mode, just display incase special test valid
            }
        }
//        {
//            if ((p_strtToolSetting->SpecialTestSetup != INVALID_CODE)
//                && (gp_strtCurrSys->eProc == PROC_PCM_LINK)
//                    &&(IsVehicleDataValid())
//                        &&(PcmIsBufferValid())/*March1114 Lap Dang added*/
//                        )
//            {
//                p_strtMenuList[bIdx].blEnable = eTRUE;
//                if(IsSystemReviewOBD2Mode())
//                {
//                    if(!IsSpecialTestDataValid())
//                    {
//                        p_strtMenuList[bIdx].blEnable = eFALSE;
//                    }
//                }
//            }
//            else
//            {
//                p_strtMenuList[bIdx].blEnable = eFALSE;
//            }
//        }

        
        //if link mode
        if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
        {
            if(p_strtMenuList[bIdx].eProc == PROC_OIL_RESET)
            {
                //if tool setting is support oil reset for selected make
                if(ToolSettingOilResetFeature_IsValid(ToolManager_YMMEProfile_Make_Get()))
                {
                    //TODO: need to check dynamic oil reset by call function check support in oil reset database
                    p_strtMenuList[bIdx].blEnable = eTRUE;
                }
            }
            
            if(p_strtMenuList[bIdx].eProc == PROC_OEM_BAT_RESET)
            {
                //if tool setting is support oil reset for selected make
                if(ToolSettingBatteryResetFeature_IsValid(ToolManager_YMMEProfile_Make_Get()))
                {
                    //TODO: need to check dynamic oil reset by call function check support in oil reset database
                    p_strtMenuList[bIdx].blEnable = eTRUE;
                }
                
            }
            
            if(p_strtMenuList[bIdx].eProc == PROC_BATTERY_HEALTH_CHECK)
            {
                if(ToolManager_ActiveGroupSystem_Get() == eMFRGroupSystem_OBD2)
                {
                    p_strtMenuList[bIdx].blEnable = eTRUE;
                }
            } 
        }
        
        /*Dec2713 Lap Dang added for Vehicle Information*/
        if(p_strtMenuList[bIdx].eProc == PROC_VEHICLE_INFO)
        {
            //if vehicle data valid
            if(ToolManager_VehicleDataValid_Get())
            {
                p_strtMenuList[bIdx].blEnable = eTRUE;
            }
            else
            {
                p_strtMenuList[bIdx].blEnable = eFALSE;
            }
        }
        
    }
}



static void SetMainMenuTitle(void)
{
    mlsprintf(MLTextBuffer,MLMainMenuTitle);
//    if(IsSystemLinkOBD2Mode())
//    {
//        switch(gp_strtCurrSys->eProc)
//        {
//        case PROC_PCM_LINK:
//            mlsprintf(MLTextBuffer,MLGlobalMainMenuTitle);
//            break;
//            
//        case PROC_ECM:
//        case PROC_TCM:
//        case PROC_OEM_DTC:
//            mlsprintf(MLTextBuffer,MLEnhanceMainMenuTitle);
//            break;
//            
//        case PROC_ABS:
//            mlsprintf(MLTextBuffer,MLABSMainMenuTitle);
//            break;
//            
//        case PROC_SRS:
//            mlsprintf(MLTextBuffer,MLSRSMainMenuTitle);
//            break;
            
//        default:
//            mlsprintf(MLTextBuffer,MLMainMenuTitle);
//            break;
//        }
//    }
//    else if(IsSystemReviewOBD2Mode())
//    {
//       switch(gp_strtCurrSys->eProc)
//        {
//        case PROC_PCM_LINK:
//            mlsprintf(MLTextBuffer,MLGlobalMainMenuMemory);
//            break;
//            
//        case PROC_ECM:
//        case PROC_TCM:
//        case PROC_OEM_DTC:
//            mlsprintf(MLTextBuffer,MLEnhancedMainMenuMemory);
//            break;
//            
//        case PROC_ABS:
//            mlsprintf(MLTextBuffer,MLABSMainMenuMemory);
//            break;
//            
//        case PROC_SRS:
//            mlsprintf(MLTextBuffer,MLSRSMainMenuMemory);
//            break;
            
//        default:
//            mlsprintf(MLTextBuffer,MLMainMenuMemoryTitle);
//            break;
//        }
//    }
//    else/*review mode*/
//    {
//        mlsprintf(MLTextBuffer,MLMainMenuTitle);
//    }
    
    return;
}


/*==============================================================================
                        PROCESS KEYS FOR 31x0E TOOLs
        
==============================================================================*/

//#define OBD31x0e_Proc_MainMenu_PressedMenu          (HotkeyHandlerFunction_KeyMENU)
#define OBD31x0e_Proc_MainMenu_PressedSystem        (HotkeyHandlerFunction_KeySYSTEM)
#define OBD31x0e_Proc_MainMenu_PressedLink          (HotkeyHandlerFunction_KeyLINK)
#define OBD31x0e_Proc_MainMenu_PressedErase         (HotkeyHandlerFunction_KeyERASE)
#define OBD31x0e_Proc_MainMenu_PressedLD            (HotkeyHandlerFunction_KeyLD)


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 07, 2011
*Function name: Proc_MainMenuKeyInit
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void OBD31x0e_Proc_MainMenuKeyInit(void)
{
    GUI_KeyHandlerReset();
    
    if (Proc_GetCurCmdID() == CMD_DISP)
    {
        HotKeyHandlerCommonProcess_Register(GUI_KEY_POWER_LINK|GUI_KEY_LD|GUI_KEY_DTC|GUI_KEY_SYSTEM|GUI_KEY_ERASE);
////        GUI_KeyRegister(GUI_KEY_MENU  , OBD31x0e_Proc_MainMenu_PressedMenu);
//        GUI_KeyRegister(GUI_KEY_SYSTEM, OBD31x0e_Proc_MainMenu_PressedSystem);
//        GUI_KeyRegister(GUI_KEY_POWER_LINK, OBD31x0e_Proc_MainMenu_PressedLink);
//        GUI_KeyRegister(GUI_KEY_ERASE, OBD31x0e_Proc_MainMenu_PressedErase);
//        GUI_KeyRegister(GUI_KEY_LD, OBD31x0e_Proc_MainMenu_PressedLD);
        
        GUI_KeyRegister(GUI_KEY_ENTER, GUI_MenuOnEnter);
        GUI_KeyRegister(GUI_KEY_UP   , GUI_MenuOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuOnDown);

//        GUI_KeyRegister(GUI_KEY_MENU  , Proc_MainMenu_PressedMenu);
//        GUI_KeyRegister(GUI_KEY_SYSTEM, Proc_MainMenu_PressedSystem);
        
    }
    
    HwKeyEnable();
}




/*==============================================================================
                                MACRO 
    Define Macro key function handler corresponding to different tools 
    and number of keys 

==============================================================================*/


#define Proc_MainMenuKeyInit    (OBD31x0e_Proc_MainMenuKeyInit)


/*==============================================================================
                                MAIN PROCESS 

==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 15 2014 Lap Dang rewrite
*Function name: Proc_MainMenu
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_MainMenu(void);
void Proc_MainMenu(void)
{
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();

    if (blIsCmdChanged)
    {
        //set led and monitor false
        IMMonLedSetStatus(eFALSE);
        //set display icon type as minimize
        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
        
        Proc_MainMenuKeyInit();
        Proc_ProcCmdClearChanged();
    }
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        Proc_ChangeCmd(CMD_DISP, 0, 0);
        break;
    case CMD_DISP:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                MainMenuConfig(p_strtMainMenuList, 
                               &g_strtToolSetting);
                SetMainMenuTitle();
                
                GUI_Clear(LCD_AREA_ICONS_EXCEPT_CONNECTION);
                GUI_MenuInit(&strtMainMenu,
                             1,
                             (uint32)(Proc_GetParam()),
                             Proc_GetSelectionItem(),
                             UI_SCROLL_MODE);

            }
            GUI_MenuDisplay();
            Proc_DataClearChanged();
        }
        break;
    default:
        break;
    }
}
