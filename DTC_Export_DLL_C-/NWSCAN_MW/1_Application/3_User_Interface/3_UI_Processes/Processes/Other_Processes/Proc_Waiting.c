/*******************************************************************************
*Engineer    : Lap Dangruong
*Date        : October 16 2014
*File        : Proc_Wating.c
*Description : Displaying waiting screen, wait use press S key for testing their
                process 
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

#include "StorageMemoryInterface.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define     CMD_TESTING                           (SYS_CMD_ID)(1001)
/*==============================================================================
*                                 GLOBAL VARIABLEs
*=============================================================================*/
//these declare just for testing
const void* const MLWaitingScreen[NUM_LANG_SUPPORT] =
DefineMLText
(
   "WAITING SCREEN",
   "WAITING SCREEN",
   "WAITING SCREEN"
);
const void* const MLPressSForYourProcess[NUM_LANG_SUPPORT] =
DefineMLText
(
   "Press "SYSTEM_BUTTON_IMAGE" for your process",
   "Press "SYSTEM_BUTTON_IMAGE" for your process",
   "Press "SYSTEM_BUTTON_IMAGE" for your process"
);
const void* const MLWaitingScrDescription[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Please follow these steps to test your process:"
    "\n1. Add your PROC ID and CMD ID declare to SysProcess.h"
        "\n2. Extern your process function prototype and add it to g_strtPhocHandlerList in Processes.h"
            "\n3. Add command to enter your process in function JumpToSystemMenu in CommonKeyHandler.c"
                "\n4. In your process, declare System key handler as (JumpToSystemMenu) "
                    "so the tool will run into the process called in function(JumpToSystemMenu)"
                        "\nOne more thing: access g_strtMFRVehicleProfile to get YMME profile",
    "Please follow these steps to test your process:"
    "\n1. Add your PROC ID and CMD ID declare to SysProcess.h"
        "\n2. Extern your process function prototype and add it to g_strtPhocHandlerList in Processes.h"
            "\n3. Add command to enter your process in function JumpToSystemMenu in CommonKeyHandler.c"
                "\n4. In your process, declare System key handler as (JumpToSystemMenu) "
                    "so the tool will run into the process called in function(JumpToSystemMenu)"
                        "\nOne more thing: access g_strtMFRVehicleProfile to get YMME profile",
    "Please follow these steps to test your process:"
    "\n1. Add your PROC ID and CMD ID declare to SysProcess.h"
        "\n2. Extern your process function prototype and add it to g_strtPhocHandlerList in Processes.h"
            "\n3. Add command to enter your process in function JumpToSystemMenu in CommonKeyHandler.c"
                "\n4. In your process, declare System key handler as (JumpToSystemMenu) "
                    "so the tool will run into the process called in function(JumpToSystemMenu)"
                        "\nOne more thing: access g_strtMFRVehicleProfile to get YMME profile"
);


#define     MLProcYMMEWaitingTitle      (MLWaitingScreen)
#define     MLProcYMMEWaitingInstr      (MLPressSForYourProcess)
#define     MLProcYMMEWaitingBody       (MLWaitingScrDescription)
#define     MLProcYMMEWaitingFooter     (MLPressMenuForMainMenu)                                 



/*==============================================================================
                        PROCESS KEYS FOR 31x0E TOOLs
        
==============================================================================*/

#define OBD31x0e_Proc_Waiting_PressedSystem    (JumpToSystemMenu)
#define OBD31x0e_Proc_Waiting_PressedMenu      (JumpToMainMenu)
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 24 2014 Lap Dang initialized
*Function name: OBD31x0e_Proc_Waiting_KeyInit
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void OBD31x0e_Proc_Waiting_KeyInit(void)
{
    GUI_KeyHandlerReset();
    switch (Proc_GetCurCmdID())
    {
    case CMD_WAITING:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_TextOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_TextOnDown);
        
        GUI_KeyRegister(GUI_KEY_MENU  , OBD31x0e_Proc_Waiting_PressedMenu);
        GUI_KeyRegister(GUI_KEY_SYSTEM, OBD31x0e_Proc_Waiting_PressedSystem);
        break;
        
    default:
        break;
    }
    HwKeyEnable();
}

/*==============================================================================
                                MACRO 
    Define Macro key function handler corresponding to different tools 
    and number of keys 

==============================================================================*/

                            
#define     Proc_Waiting_KeyInit     (OBD31x0e_Proc_Waiting_KeyInit)


/*==============================================================================
                                MAIN PROCESS 

==============================================================================*/
void Proc_Waiting(void);
void Proc_Waiting(void)
{
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();
    
    if (blIsCmdChanged)
    {
        IMMonLedSetStatus(eFALSE);
        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
        
        Proc_Waiting_KeyInit();
        Proc_ProcCmdClearChanged();
    }
    
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        Proc_ChangeCmd(CMD_WAITING,0,0);
//        Proc_ChangeCmd(CMD_TESTING,0,0);
        
        break;

    case CMD_WAITING:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                GUI_TextInit(MLProcYMMEWaitingTitle,
                             MLProcYMMEWaitingInstr,
                             MLProcYMMEWaitingBody,
                             MLProcYMMEWaitingFooter);
            }

            GUI_TextDisplay();
            Proc_DataClearChanged();
        }
        break;
    
    case CMD_TESTING:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                void* const MLSmallTextBuffer_1[NUM_LANG_SUPPORT] =
                    DefineMLText
                        (
                         GUI_Manager.p_strTextBufferNext,
                         GUI_Manager.p_strTextBufferNext,
                         GUI_Manager.p_strTextBufferNext
                             );
                 void* const MLSmallTextBuffer_2[NUM_LANG_SUPPORT] =
                    DefineMLText
                        (
                         &GUI_Manager.p_strTextBufferNext[255],
                         &GUI_Manager.p_strTextBufferNext[255],
                         &GUI_Manager.p_strTextBufferNext[255]
                             );
                sprintf(MLSmallTextBuffer_1[0],
                        "DTC Type\nMake");
                sprintf(MLTextBuffer[0],
                        "This is dtc definition...");
                sprintf(MLSmallTextBuffer_2[0],
                        "DTC Def. Scrn footer");
                GUI_DTCInit(SRSDTC,
                            1,
                            5,
                            "P0123-01",
                            MLSmallTextBuffer_1,
                            MLTextBuffer,
                            MLSmallTextBuffer_2);
            }

            GUI_DTCDisplay();
            Proc_DataClearChanged();
        }
        break;
        
    default:
        break;
    }

}

