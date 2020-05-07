/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __COMMON_KEY_HANDLER_H__
#define __COMMON_KEY_HANDLER_H__

#include    <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Manager.h>

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 16 2015
*Function name: KeyPressedBreakChecking
*Descrtiption : check key pressed during linking process and break
                
*Input        : None
*Output       : status of break
*-----------------------------------------------------------------------------*/
enumSystemStatus KeyPressedBreakChecking(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 19 2015
*Function name: BreakCheckingNone
*Descrtiption : do not check break when linking
                
*Input        : None
*Output       : status of break
*-----------------------------------------------------------------------------*/
enumSystemStatus BreakCheckingNone(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 03 2015
*Function name: KeyHandler_KeyPreProcessFunction
*Descrtiption : function for pre-processing each time any key pressed
                After registered, this function will be called before the key handler
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void KeyHandler_KeyPreProcessFunction(void);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 14 2014
*Function name: JumpToMainMenu
*Descrtiption : jump to main menu from any processes 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void JumpToMainMenu(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 14 2014
*Function name: JumpToSystemMenu
*Descrtiption : jump to system menu from any processes 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void JumpToSystemMenu(void);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyLINK
*Descrtiption : common handler for key LINK 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyLINK(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyERASE
*Descrtiption : common handler for key ERASE 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyERASE(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeySYSTEM
*Descrtiption : common handler for key SYSTEM 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeySYSTEM(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyDTC
*Descrtiption : common handler for key DTC 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyDTC(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyLD
*Descrtiption : common handler for key LD 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyLD(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyMENU
*Descrtiption : common handler for key MENU 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotkeyHandlerFunction_KeyMENU(void);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. December 30 2014
*Function name: HotkeyHandlerFunction_KeyMENU
*Descrtiption : common handler for key MENU 
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void HotKeyHandlerCommonProcess_Register(GUI_KEY_CODE eEnabledKeys);

#endif


