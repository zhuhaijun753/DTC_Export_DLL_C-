/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#define __PROC_TOOL_INIT_C__
#include <PlatFormType.h>
#include <GUIManager.h>
#include    "TimerApp.h"
#include    "SDCardApp.h"

#include "OBDToolSetting.h"
#include "OBDToolManager.h"
#include "Common_LCD_Screen.h"
#include "PowerDriver.h"

#include    "Processes.h"

extern GUI_KEY_CODE GetCurrentKey(void);
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

void Proc_ToolInit(void);
void Proc_ToolInit(void)
{
    static enumbool IsSkipAutoLink=eFALSE;
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();
    if (blIsCmdChanged)
    {
        GUI_KeyHandlerReset();
        Proc_ProcCmdClearChanged();
    }
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        Proc_ChangeCmd(CMD_TOOL_INIT_CHECK_SYS_SETTING, 0, 0);
        break;
        
    case CMD_TOOL_INIT_CHECK_SYS_SETTING:
        if(SystemSetting_IsValid())
        {
            ToolManager_FirstSettingConfig_Set(eFALSE);
#if _SD_CARD
            Proc_EnterCmd(CMD_TOOL_INIT_CHECK_SD_CARD, 0, 0);
#else
            Proc_ChangeCmd(CMD_END_PROC, 0, 0);
#endif
            
        }
        else
        {
          //DispFlashScreen();
            ToolManager_FirstSettingConfig_Set(eTRUE);
            Proc_EnterProc(PROC_SELECT_LANGUAGE,CMD_INIT_PROC);
        }
        break;
        
#if _SD_CARD
    case CMD_TOOL_INIT_CHECK_SD_CARD:
        Proc_ChangeCmd(CMD_END_PROC, 0, 0);
        
        if ((SD_Detect()==SD_PRESENT)
            &&(FeatureSetting_Security_Get() == eTRUE))
        {
        }
        else if (SD_Detect()==SD_PRESENT)
        {
            OnBackUpAndEnterProc(PROC_SDCARD_WARNING,CMD_SD_NOT_VALID);
        }
        else
        {
            FeatureSetting_SDCard_Set(eFALSE);
            OnBackUpAndEnterProc(PROC_SDCARD_WARNING,CMD_SD_NOT_DETECT);
        }
        break;
#endif
        
    case CMD_END_PROC:
        /*Aug 21, 2013: Hoang Nguyen modified to disable Flash Screen when in USB mode*/
        if(!HasVBUS())
        {
            DispFlashScreen();
            DelayMsNop(2000);
        }
        
        ToolManager_FirstSettingConfig_Set(eFALSE);
        Proc_StackClean();
     
#if 1//Just for testing
        Proc_EnterProc(PROC_SYSTEM_MENU, CMD_INIT_PROC);
        //Proc_EnterProc(PROC_YMME_SELECTION, CMD_INIT_PROC);
#else
        if(GetCurrentKey()==GUI_KEY_ENTER)
        {
//          IsSkipAutoLink = eTRUE;
//        }
//        if(IsSkipAutoLink==eTRUE)
//        {
          Proc_EnterProc(PROC_SYSTEM_MENU, CMD_INIT_PROC);
        }
        else
        {
          if ((ToolManager_CableID_Get() == CABLE_GENERIC) 
              && (HasVECU()))
          {
              ToolManager_SystemState_EnterLinkOBD2Mode();
          }
          else if ((ToolManager_CableID_Get() != CABLE_GENERIC)
                   &&(ToolManager_CableID_Get() != CABLE_UNKNOWN))
          {
  //            SystemEnterLinkOBD1Mode();
          }
          else if(!HasVBUS())
          {
  //            SystemEnterReviewMode();
              if (!HasVECU())
              {
                  iTurnOffTimeOut = jiffies + AUTO_TURN_OFF_PERIOD;
              }
          }
        }
#endif
        break;
    default:
        break;
    }
}



