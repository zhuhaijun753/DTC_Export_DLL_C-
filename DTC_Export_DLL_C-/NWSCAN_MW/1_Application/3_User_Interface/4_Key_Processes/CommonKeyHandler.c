/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#define __COMMON_KEY_HANDLER_C__
#include <PlatFormType.h>
#include <GUIManager.h>
#include <GuiKey.h>

#include "TimerApp.h"
//#include "KeyBoardApp.h"
#include    "Processes.h"
#include "OBDToolManager.h"
#include    "PowerDriver.h"

#include "CommonKeyHandler.h"


/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/




/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/





/*==============================================================================
*                                 FUNCTIONs
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 16 2015
*Function name: KeyPressedBreakChecking
*Descrtiption : check key pressed during linking process and break
                
*Input        : None
*Output       : status of break
*-----------------------------------------------------------------------------*/
enumSystemStatus KeyPressedBreakChecking(void)
{
    enumSystemStatus eSysStatus;
    GUI_KEY_CODE eCurrentKey;
    eCurrentKey = GUI_KeyGet();

    if (eCurrentKey & GUI_KEY_ALL)
    {
        eSysStatus = USER_BREAK;
    }
    else if (!HasVECU())
    {
        eSysStatus = ERROR_VECU;
    }
    else
    {
        eSysStatus = SYSTEM_NORMAL;
    }
    return eSysStatus;
}


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 19 2015
*Function name: BreakCheckingNone
*Descrtiption : do not check break when linking
                
*Input        : None
*Output       : status of break
*-----------------------------------------------------------------------------*/
enumSystemStatus BreakCheckingNone(void)
{
    return SYSTEM_NORMAL;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 03 2015
*Function name: KeyHandler_KeyPreProcessFunction
*Descrtiption : function for pre-processing each time any key pressed
                After registered, this function will be called before the key handler
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void KeyHandler_KeyPreProcessFunction(void)
{
    iTurnOffTimeOut = jiffies + AUTO_TURN_OFF_PERIOD;
    iHiddenLink_Counter = jiffies + HIDDEN_LINK_PERIOD;
    //set auto re-link status to false
    ToolManager_AutoRelink_Set(eFALSE);
//    //set hidden re-link status to false
//    ToolManager_HiddenRelink_Set(eFALSE);
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 14 2014
*Function name: JumpToMainMenu
*Descrtiption : jump to main menu from any processes 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void JumpToMainMenu(void)
{
    if (ToolManager_SystemState_Get() != SYSTEM_STATE_REVIEW_OBD1_MODE)
    {
        if(SysCmdProcStackGetProcIdx(&PROC_Manager.strtProcStack, PROC_MAIN_MENU) >= 0)
        {
            Proc_JumpToProc(PROC_MAIN_MENU, CMD_DISP);
        }
        else
        {
//            if (SysCmdProcStackGetCmdIdx(&PROC_Manager.strtProcStack,  PROC_SYSTEM_MENU, CMD_DISP) < 0)
//            {
//                Proc_EnterProc(PROC_SYSTEM_MENU, CMD_INIT_PROC);
//            }
            Proc_JumpToProc(PROC_MAIN_MENU, CMD_INIT_PROC);
        }
    }
    else
    {
//        Proc_ChangeProc(PROC_OBDI_REVIEW_MENU,CMD_INIT_PROC);
    }
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 14 2014
*Function name: JumpToSystemMenu
*Descrtiption : jump to system menu from any processes 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void JumpToSystemMenu(void)
{
    Proc_EnterProc(PROC_SYSTEM_MENU, CMD_INIT_PROC);
}


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyLINK
*Descrtiption : common handler for key LINK 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyLINK(void)
{
    if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
    {
        //if active system is OBD2
        if(ToolManager_ActiveGroupSystem_Get() == eMFRGroupSystem_OBD2)
        {
            Proc_EnterProc(PROC_OBD2_AUTO_LINK, CMD_INIT_PROC);
        }
        else//oem group system
        {
            Proc_EnterProc(PROC_NETWORK_SCAN_LINK, CMD_INIT_PROC);
        }
    }
    else//turn off tool if not VECU
    {
        if(!HasVECU())
        {
            Proc_EnterProc(PROC_POWER_OFF,
                           CMD_INIT_PROC);
        }
    }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyERASE
*Descrtiption : common handler for key ERASE 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyERASE(void)
{
    if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
    {
        //check active group system to jump to corresponding process
        //if active system is OBD2
        if(ToolManager_ActiveGroupSystem_Get() == eMFRGroupSystem_OBD2)
        {
            Proc_EnterProc(PROC_OBD2_ERASE_DTC, CMD_INIT_PROC);
        }
        else//oem group system
        {
            Proc_EnterProc(PROC_NETWORK_SCAN_ERASE, CMD_INIT_PROC);
        }
        
    }
    else
    {
        
    }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeySYSTEM
*Descrtiption : common handler for key SYSTEM 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeySYSTEM(void)
{
//    if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
//    {
        //run to system menu here
        JumpToSystemMenu();
        
//    }
//    else
//    {
//        
//    }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyDTC
*Descrtiption : common handler for key DTC 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyDTC(void)
{
    if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
    {
        //if active system is OBD2
        if(ToolManager_ActiveGroupSystem_Get() == eMFRGroupSystem_OBD2)
        {
            Proc_EnterProc(PROC_OBD2_DISPLAY_DATA, CMD_INIT_PROC);
        }
        else//oem group system
        {
            Proc_EnterProc(PROC_NETWORK_SCAN_DISPLAY_DATA, CMD_INIT_PROC);
        }
    }
    else
    {
        
    }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyLD
*Descrtiption : common handler for key LD 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyLD(void)
{
    if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
    {
        //check active group system to jump to corresponding process
        //if active system is OBD2
        if(ToolManager_ActiveGroupSystem_Get() == eMFRGroupSystem_OBD2)
        {
            Proc_EnterProc(PROC_OBD2_LIVE_DATA_VIEW,
                           CMD_INIT_PROC);
        }
        else//oem group system
        {
            Proc_EnterProc(PROC_NETWORK_SCAN_OEM_LD,
                           CMD_INIT_PROC);
        }
    }
    else
    {
        
    }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyMENU
*Descrtiption : common handler for key MENU 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyMENU(void)
{
    JumpToMainMenu();
//    if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
//    {
//        JumpToMainMenu();
//    }
//    else
//    {
//        
//    }
}






/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyMENU
*Descrtiption : common handler for key MENU 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotKeyHandlerCommonProcess_Register(GUI_KEY_CODE eEnabledKeys)
{
    //key POWER
    if(eEnabledKeys & GUI_KEY_POWER_LINK)
    {
        GUI_KeyRegister(GUI_KEY_POWER_LINK  , HotkeyHandlerFunction_KeyLINK);
    }
    //key MENU
    if(eEnabledKeys & GUI_KEY_MENU)
    {
        GUI_KeyRegister(GUI_KEY_MENU  , HotkeyHandlerFunction_KeyMENU);
    }
    //key LD
    if(eEnabledKeys & GUI_KEY_LD)
    {
        GUI_KeyRegister(GUI_KEY_LD  , HotkeyHandlerFunction_KeyLD);
    }
    //key DTC
    if(eEnabledKeys & GUI_KEY_DTC)
    {
        GUI_KeyRegister(GUI_KEY_DTC  , HotkeyHandlerFunction_KeyDTC);
    }
    //key SYSTEM
    if(eEnabledKeys & GUI_KEY_SYSTEM)
    {
        GUI_KeyRegister(GUI_KEY_SYSTEM  , HotkeyHandlerFunction_KeySYSTEM);
    }
    //key ERASE
    if(eEnabledKeys & GUI_KEY_ERASE)
    {
        GUI_KeyRegister(GUI_KEY_ERASE  , HotkeyHandlerFunction_KeyERASE);
    }
    
}


















