/*******************************************************************************
*Engineer    : Tran Luu
*Date        : January 28 2015
*File        : Proc_OilReset.c
*Description : Process function Oil Reset
*******************************************************************************/

/*******************************************************************************
================================================================================
INCLUDED FILES
================================================================================
*******************************************************************************/
#define _PROC_OILRESET_C_
#include <PlatFormType.h>

#include <GUIManager.h>
#include <timerdriver.h>
#include    "KeyBoardApp.h"

#include "Processes.h"
#include    "SysProcess.h"
#include "OBDToolManager.h"
#include "Common_Text_Database.h"
#include "CommonKeyHandler.h"
#include "OilResetEnumeration.h"
#include "OilReset.h"


/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
// Define used command in this process here, these values should not be in (SYS_CMD_ID)
// declared in SysProcess.h
#define     CMD_GET_NAVIGATION_SYSTEM           (SYS_CMD_ID)(1001)
#define     CMD_CONFIRM                (SYS_CMD_ID)(1002)
#define     CMD_TEST_FAULT                 (SYS_CMD_ID)(1003)
#define     CMD_LINKING                (SYS_CMD_ID)(1004)
#define     CMD_LINK_FAIL             (SYS_CMD_ID)(1005)
#define     CMD_LINK_OK                 (SYS_CMD_ID)(1006)
#define     CMD_WAIT_FOR_SELECTION            (SYS_CMD_ID)(1007)
#define     UI_COMMAND_8        (SYS_CMD_ID)(1008)
#define     UI_COMMAND_9        (SYS_CMD_ID)(1009)
#define     UI_COMMAND_10       (SYS_CMD_ID)(1010)
#define     UI_COMMAND_11       (SYS_CMD_ID)(1011)
#define     UI_COMMAND_12       (SYS_CMD_ID)(1012)
#define     UI_COMMAND_13       (SYS_CMD_ID)(1013)
#define     UI_COMMAND_14       (SYS_CMD_ID)(1014)




#define MAX_BYTE_PROCEDURE_TEXT 5*1024

extern void* const MLCommonRamBuff[NUM_LANG_SUPPORT];
extern const void* const MLPressMenuForMainMenu[NUM_LANG_SUPPORT];

//extern structMFRVinProfile       g_strtMFRVehicleProfile;
#define g_strtMFRVehicleProfile     (g_strtVehicleDataBuffer.strtVehData_YMMEProfile)

extern structVehicleProfile      g_strtNWScanVehicleProfile;

uint8  bOilResetRamBuff[MAX_BYTE_PROCEDURE_TEXT];
void* const MLOilResetBuffer[NUM_LANG_SUPPORT] =
DefineMLText
(
bOilResetRamBuff,
bOilResetRamBuff,
bOilResetRamBuff
);

const void* const MLServiceReset[NUM_LANG_SUPPORT] =
DefineMLText
(
"Oil Reset",
"Reseteo del aceite",
"R�initialisation d'huile"
);

const void* const MLOilResetOBDIIServiceConfirmInstruction[NUM_LANG_SUPPORT] =
DefineMLText
(
"Reset oil maintenance?\n\nSelect and press "ENTER_BUTTON_IMAGE,
"�Resetear el mantenimiento del aceite?\n\nSeleccione y Presione "ENTER_BUTTON_IMAGE,
"R�initialiser l'entretien d'huile?\n\nS�lect et appuyer "ENTER_BUTTON_IMAGE
);
const void* const MLOilResetOBDIIServiceSuccess[NUM_LANG_SUPPORT] =
DefineMLText
(
"Oil maintenance reset was successful.",
"El reseteo del mantenimiento del aceite se ha realizado correctamente.",
"R�initialisation d'entretien d'huile r�ussie."
);
const void* const MLOilResetOBDIIServiceNotSuccess[NUM_LANG_SUPPORT] =
DefineMLText
(
"Oil maintenance reset was not successful.",
"Solicitud enviada del reseteo del mantenimiento del aceite",
"Demande de r�initialisation d'entretien d'huile envoy�e."
);

const void* const MLOilResetOBDIIServiceNotSuccessNew[NUM_LANG_SUPPORT] =
DefineMLText
(
"Oil maintenance reset was not successful.\nDo you want to reset by procedure?\nSelect and press "ENTER_BUTTON_IMAGE,
"Oil maintenance reset was not successful.\nDo you want to reset by procedure?\nSeleccione y Presione "ENTER_BUTTON_IMAGE,
"Oil maintenance reset was not successful.\nDo you want to reset by procedure?\nS�lect et appuyer "ENTER_BUTTON_IMAGE
);

const void* const ML_OilResetIsInProgress[NUM_LANG_SUPPORT] =
DefineMLText
(
"Oil reset is in progress...",
"El reseteo del aceite est� en progreso...",
"R�initialisation d'huile en cours..."
);

const void* const MLOilResetInstruction[NUM_LANG_SUPPORT] =
DefineMLText
(
"Is the vehicle equipped with navigation system?\nSelect and press "ENTER_BUTTON_IMAGE,
"�El veh�culo est� equipado con sistema de navegaci�n?\nSeleccione y  Presione "ENTER_BUTTON_IMAGE,
"Ce v�hicule poss�de-t-il un syst�me de navigation?\nS�lect et appuyer "ENTER_BUTTON_IMAGE
);

//const void* const MLYes[NUM_LANG_SUPPORT] =
//DefineMLText
//(
//"Yes",
//"S�",
//"OUI"
//);
//const void* const MLNo[NUM_LANG_SUPPORT] =
//DefineMLText
//(
//"No",
//"No",
//"NON"
//);
//const structMenuItem p_strtConfirmYesNo[] =
//{
//    {PROC_CURRENT, CMD_CURRENT, MLYes     , eTRUE},
//    {PROC_PREVIOUS, CMD_EXIT, MLNo      , eTRUE},
//    {PROC_NONE               , CMD_NONE, NULL      , eFALSE},
//    
//};
//
//structMenu g_strtConfirmYesNo =
//{
//    
//    .MLTitle        = MLTextBuffer,
//    .MLInstruction  = MLNull,
//    .MLFooter       = MLNull,//MLPressMenuForMainMenu,
//    .p_strtMenuItemList = p_strtConfirmYesNo,
//};
 extern structMenu g_strtConfirmYesNo;
const void* const MLOilResetNotSup[NUM_LANG_SUPPORT] =
DefineMLText
(
"Not Equipped",
"No est� instalado.",
"Non �quip�"
);
enumNavigationStatus eNavigationStatusTemp = eNAVIGATION_NONE;


static void DisplayOilResetOneMomentPlease(void)
{
    GUI_TextInit(MLServiceReset,
                 MLNull,
                 ML_OneMomentPlease,
                 MLNull);
    GUI_TextDisplay();
}

static void DisplayOilResetIsInProgress(void)
{
    GUI_TextInit(MLServiceReset,
                 MLNull,
                 ML_OilResetIsInProgress,
                 MLNull);
    GUI_TextDisplay();
    
}

/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Sep 26, 2013
2. TranLuu rewrite for new flatform structure
*Function name: Proc_OilReset_OnEnterPressed
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void Proc_OilReset_OnEnterPressed(void)
{
    uint8 bRealIdx ;
    enumOilResetStatus eOilResetStatus = eOIL_RESET_NONE;
    GUI_LANGUAGE_ID eGuiLanguage = GUI_GetLanguage();
    switch(Proc_GetCurCmdID())
    {
    case CMD_GET_NAVIGATION_SYSTEM:
        bRealIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
        
        /*based on Vin profile to get the Oil Reset procedure text to buffer
        change to display the procedure
        */
        if(bRealIdx == 0)
        {
            eNavigationStatusTemp = eNAVIGATION_YES;
        }
        else
        {
            eNavigationStatusTemp = eNAVIGATION_NO;
        }
        DisplayOilResetOneMomentPlease();
        
        ToolManager_EnterSystemMode();
        eOilResetStatus = IsOilResetServiceSupportted(&g_strtMFRVehicleProfile,
                                                      &g_strtNWScanVehicleProfile);
        /*if support Oil Reset OBDII service*/
        if(eOilResetStatus == eOIL_RESET_NORMAL)
        {
            Proc_ChangeCmd(CMD_CONFIRM, 0, 0);
        }
        else
        {
            memset(bOilResetRamBuff, null, sizeof(bOilResetRamBuff));
            eOilResetStatus = OilReset_Get(&g_strtMFRVehicleProfile,
                                           eNavigationStatusTemp,
                                           (uint8*)MLOilResetBuffer[eGuiLanguage],
                                           MAX_BYTE_PROCEDURE_TEXT,
                                           (enumOBDLanguage)(eGuiLanguage + 1)
                                               );
            if(eOilResetStatus == eOIL_RESET_NORMAL)
            {
                Proc_ChangeCmd(CMD_DISP, 0, 0);
            }
            else
            {
                Proc_ChangeCmd(CMD_TEST_FAULT, 0, 0);
            }
        }
        ToolManager_LeaveSystemMode();
        FreeTimerStart();
        
        break;
        
        /*confirm to implement Oil Reset OBDII service*/
    case CMD_CONFIRM:
        bRealIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
        
        if(bRealIdx == 0)
        {
            Proc_ChangeCmd(CMD_LINKING, 0, 0);
        }
        else
        {
            JumpToMainMenu();
        }
        break;
        //ask for view procedure in case fail service
    case CMD_LINK_FAIL:
        bRealIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
        
        if(bRealIdx == 0)
        {
            DisplayOilResetOneMomentPlease();
            ToolManager_EnterSystemMode();      
            memset(bOilResetRamBuff, null, sizeof(bOilResetRamBuff));
            eOilResetStatus = OilReset_Get(&g_strtMFRVehicleProfile,
                                           eNavigationStatusTemp,
                                           (uint8*)MLOilResetBuffer[eGuiLanguage],
                                           MAX_BYTE_PROCEDURE_TEXT,
                                           (enumOBDLanguage)(eGuiLanguage + 1)
                                               );     
            
            if(eOilResetStatus == eOIL_RESET_NORMAL)
            {
                Proc_ChangeCmd(CMD_DISP, 0, 0);
            }
            else
            {
                Proc_ChangeCmd(CMD_TEST_FAULT, 0, 0);
            }
            ToolManager_LeaveSystemMode();
            FreeTimerStart();
        }
        else
        {
            JumpToMainMenu();
        }
        break;
        
    default:
        break;
    }
}

/*------------------------------------------------------------------------------
*Engineer     : Si Truong
*Historical   : 1. June 10 2013
*Function name: Proc_OilReset_KeyInit
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void Proc_OilReset_KeyInit(void)
{
    GUI_KeyHandlerReset();
    //hot keys
    HotKeyHandlerCommonProcess_Register(GUI_KEY_POWER_LINK|GUI_KEY_MENU|GUI_KEY_LD|GUI_KEY_DTC|GUI_KEY_SYSTEM|GUI_KEY_ERASE);
    
    switch (Proc_GetCurCmdID())
    {
    case CMD_GET_NAVIGATION_SYSTEM:
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_OilReset_OnEnterPressed);
        GUI_KeyRegister(GUI_KEY_UP   , GUI_MenuOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuOnDown);
        //        GUI_KeyRegister(GUI_KEY_MENU  , JumpToMainMenu);
        //        GUI_KeyRegister(GUI_KEY_SYSTEM   , JumpToSystemMenu);
        break;
        //ask for view procedure in case fail service
    case CMD_LINK_FAIL:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_MenuOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuOnDown);
        //        GUI_KeyRegister(GUI_KEY_MENU  , JumpToMainMenu);
        //        GUI_KeyRegister(GUI_KEY_SYSTEM   , JumpToSystemMenu);
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_OilReset_OnEnterPressed);
        break;
        
    case CMD_DISP:
    case CMD_TEST_FAULT:
    case CMD_LINK_OK:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_TextOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_TextOnDown);
        //        GUI_KeyRegister(GUI_KEY_MENU  , JumpToMainMenu);
        //        GUI_KeyRegister(GUI_KEY_SYSTEM   , JumpToSystemMenu);
        break;
        
    case CMD_CONFIRM:
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_OilReset_OnEnterPressed);
        GUI_KeyRegister(GUI_KEY_UP   , GUI_MenuOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuOnDown);
        //        GUI_KeyRegister(GUI_KEY_MENU  , JumpToMainMenu);
        //        GUI_KeyRegister(GUI_KEY_SYSTEM   , JumpToSystemMenu);
        break;
        
    default:
        break;
    }
    
    HwKeyEnable();
}

void Proc_Oil_Reset(void);
void Proc_Oil_Reset(void)
{
    enumbool blIsProcChanged;
    blIsProcChanged = Proc_ProcCmdIsChanged();
    enumOilResetStatus  eOilResetStatus = eOIL_RESET_NONE;
    
    if (blIsProcChanged)
    {
        Proc_OilReset_KeyInit();
        Proc_ProcCmdClearChanged();
    }
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        if((g_strtMFRVehicleProfile.ValidStatus != eMFR_VALID))
        {
            Proc_ChangeCmd(CMD_WAIT_FOR_SELECTION, 0, 0);
            //      Proc_EnterProc(PROC_CHOOSE_VEHICLE, CMD_INIT_PROC);
        }
        else
        {
            Proc_ChangeCmd(CMD_GET_NAVIGATION_SYSTEM, 0, 0);
        }
        break;
    case CMD_GET_NAVIGATION_SYSTEM:
        if (Proc_DataIsChanged())
        {
            if (blIsProcChanged)
            {
                IMMonLedSetStatus(eFALSE);
                GUI_Clear(LCD_AREA_ICONS_EXCEPT_CONNECTION);
                
                g_strtConfirmYesNo.MLTitle = MLServiceReset;
                g_strtConfirmYesNo.MLInstruction = MLOilResetInstruction;
                g_strtConfirmYesNo.MLFooter = MLPressMenuForMainMenu;
                GUI_MenuInit(&g_strtConfirmYesNo,
                             1,//NumDispCol
                             (uint32)(Proc_GetParam()),
                             Proc_GetSelectionItem(),
                             UI_SCROLL_MODE);
            }
            GUI_MenuDisplay();
            Proc_DataClearChanged();
        }
        break;
    case CMD_DISP:/*display Oil Reset procedure text*/
        if (Proc_DataIsChanged())
        {
            if (blIsProcChanged)
            {
                GUI_TextInit(MLServiceReset,
                             MLNull,
                             MLOilResetBuffer,
                             MLPressMenuForMainMenu);
            }
            GUI_TextDisplay();
            Proc_DataClearChanged();
        }
        break;
        
        /*Confirm implementing Oil Reset OBDII service*/
    case CMD_CONFIRM:
        if (Proc_DataIsChanged())
        {
            if (blIsProcChanged)
            {
                g_strtConfirmYesNo.MLTitle = MLServiceReset;
                g_strtConfirmYesNo.MLInstruction = MLOilResetOBDIIServiceConfirmInstruction;
                g_strtConfirmYesNo.MLFooter = MLPressMenuForMainMenu;
                GUI_MenuInit(&g_strtConfirmYesNo,
                             1,//NumDispCol
                             (uint32)(Proc_GetParam()),
                             Proc_GetSelectionItem(),
                             UI_SCROLL_MODE);
                
            }
            GUI_MenuDisplay();
            Proc_DataClearChanged();
        }
        break;
        
        /*implementing oil reset obdii service*/
    case CMD_LINKING:
        DisplayOilResetIsInProgress();
        //    FreeTimerDisableWithBackup();
        /*
        eOilResetStatus = ImplementOilResetService(&g_strtMFRVehicleProfile,
        &g_strtNWScanVehicleProfile);
        */
        //    FreeTimerRestoreBackup();
        /*Lap Dang Start Free Timer*/
        FreeTimerStart();
        
        if(eOilResetStatus == eOIL_RESET_NORMAL)
        {
            Proc_ChangeCmd(CMD_LINK_OK, 0, 0);
        }
        else
        {
            Proc_ChangeCmd(CMD_LINK_FAIL, 0, 0);
        }
        break;
        
        /*oil reset obdii service success*/
    case CMD_LINK_OK:
        if (Proc_DataIsChanged())
        {
            if (blIsProcChanged)
            {
                GUI_TextInit(MLServiceReset,
                             MLNull,
                             MLOilResetOBDIIServiceSuccess,
                             MLPressMenuForMainMenu
                                 );
            }
            GUI_TextDisplay();
            Proc_DataClearChanged();
        }
        break;
        
        /*oil reset obdii service failed*/
    case CMD_LINK_FAIL:
        if (Proc_DataIsChanged())
        {
            if (blIsProcChanged)
            {
                g_strtConfirmYesNo.MLTitle = MLServiceReset;
                g_strtConfirmYesNo.MLInstruction = MLOilResetOBDIIServiceNotSuccessNew;
                g_strtConfirmYesNo.MLFooter = MLPressMenuForMainMenu;
                GUI_MenuInit(&g_strtConfirmYesNo,
                             1, //NumDispCol
                             (uint32)(Proc_GetParam()),
                             Proc_GetSelectionItem(),
                             UI_SCROLL_MODE);
            }
            GUI_MenuDisplay();
            Proc_DataClearChanged();
        }
        break;
        
    case CMD_TEST_FAULT:
        if (Proc_DataIsChanged())
        {
            if (blIsProcChanged)
            {
                GUI_TextInit(MLServiceReset,
                             MLNull,
                             MLOilResetNotSup,
                             MLPressMenuForMainMenu
                                 );
            }
            GUI_TextDisplay();
            Proc_DataClearChanged();
        }
        break;
    case CMD_WAIT_FOR_SELECTION:
        /*After enter select vehicle, if user select back => leave current PRC else 
        enter to link*/
        if (g_strtMFRVehicleProfile.ValidStatus != eMFR_VALID)
        {
            Proc_LeaveProc();
        }
        else
        {
            Proc_ChangeCmd(CMD_INIT_PROC, 0, 0);
        }
        break;
    default:
        break;
    }
    
    return;    
}