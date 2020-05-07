/*******************************************************************************
*Engineer    : Lap Dangruong
*Date        : October 27 2014
*File        : Proc_Template.c
*Description : Just a template for UI process coding

*******************************************************************************/
/*############################################################################*/
/*
================================================================================
INCLUDED FILES
================================================================================
*/
#include    <PlatFormType.h>
#include    "GuiType.h"
#include    <GUIManager.h>

#include    "KeyBoardApp.h"
#include    "Processes.h"
#include    "OBDToolManager.h"

#include    "Common_Text_Database.h"
#include    "CommonKeyHandler.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
// Define used command in this process here, these value should not be in (SYS_CMD_ID)
// declared in SysProcess.h
#define     UI_COMMAND_1        (SYS_CMD_ID)(1001)
#define     UI_COMMAND_2        (SYS_CMD_ID)(1002)
#define     UI_COMMAND_3        (SYS_CMD_ID)(1003)
#define     UI_COMMAND_4        (SYS_CMD_ID)(1004)
#define     UI_COMMAND_5        (SYS_CMD_ID)(1005)
#define     UI_COMMAND_6        (SYS_CMD_ID)(1006)
#define     UI_COMMAND_7        (SYS_CMD_ID)(1007)
#define     UI_COMMAND_8        (SYS_CMD_ID)(1008)
#define     UI_COMMAND_9        (SYS_CMD_ID)(1009)
#define     UI_COMMAND_10       (SYS_CMD_ID)(1010)
#define     UI_COMMAND_11       (SYS_CMD_ID)(1011)
#define     UI_COMMAND_12       (SYS_CMD_ID)(1012)
#define     UI_COMMAND_13       (SYS_CMD_ID)(1013)
#define     UI_COMMAND_14       (SYS_CMD_ID)(1014)






/*==============================================================================
*                                 GLOBAL VARIABLEs
*=============================================================================*/
const void* const MLTemplateScrTitle[NUM_LANG_SUPPORT] =
DefineMLText
(
   "TEMPLATE SCREEN",
   "TEMPLATE SCREEN",
   "TEMPLATE SCREEN"
);

const void* const MLTemplateScrDescription[NUM_LANG_SUPPORT] =
DefineMLText
(
    "",
    "",
    ""
);
                                 
#define     MLProcTemplateTitle      (MLTemplateScrTitle)
#define     MLProcTemplateInstr      (MLNull)
#define     MLProcTemplateBody       (MLTemplateScrDescription)
#define     MLProcTemplateFooter     (MLPressMenuForMainMenu)                                 





/*==============================================================================
                        FUCNTIONs SUPPORT FOR DISPLAYING
        
==============================================================================*/


/*==============================================================================
                        FUCNTIONs SUPPORT FOR PROCESSING DATA
        
==============================================================================*/



/*==============================================================================
                        PROCESS KEYS FOR 31x0E TOOLs
        
==============================================================================*/

#define OBD31x0e_Proc_Template_PressedSystem    (JumpToSystemMenu)
#define OBD31x0e_Proc_Template_PressedMenu      (JumpToMainMenu)
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014 Lap Dang initialized
*Function name: OBD31x0e_Proc_Template_KeyInit
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void OBD31x0e_Proc_Template_KeyInit(void)
{
    GUI_KeyHandlerReset();
    
    switch (Proc_GetCurCmdID())
    {
    case CMD_WAITING:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_TextOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_TextOnDown);
        
        GUI_KeyRegister(GUI_KEY_MENU  , OBD31x0e_Proc_Template_PressedMenu);
        GUI_KeyRegister(GUI_KEY_SYSTEM, OBD31x0e_Proc_Template_PressedSystem);
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

#define     Proc_Template_KeyInit     (OBD31x0e_Proc_Template_KeyInit)


/*==============================================================================
                                MAIN PROCESS 

==============================================================================*/
void Proc_Template(void);
void Proc_Template(void)
{
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();
    
    if (blIsCmdChanged)
    {
        IMMonLedSetStatus(eFALSE);
        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
        
        Proc_Template_KeyInit();
        Proc_ProcCmdClearChanged();
    }
    
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        Proc_ChangeCmd(CMD_WAITING,0,0);
        break;

    case CMD_WAITING:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                GUI_TextInit(MLProcTemplateTitle,
                             MLProcTemplateInstr,
                             MLProcTemplateBody,
                             MLProcTemplateFooter);
            }

            GUI_TextDisplay();
            Proc_DataClearChanged();
        }
        break;

    default:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                
            }
            
            Proc_DataClearChanged();
        }
        break;
    }   
    
}


