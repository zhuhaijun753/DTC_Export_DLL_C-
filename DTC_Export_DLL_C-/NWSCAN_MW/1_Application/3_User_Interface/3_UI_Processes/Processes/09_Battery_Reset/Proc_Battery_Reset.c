/*******************************************************************************
*Engineer    : Lap Dangruong
*Date        : February 05 2015
*File        : Proc_Battery_Reset.c
*Description : Processing Battery Reset (text procedure and service)
                Based on vehicle selection
                --> check for support reset by service --> reset by service
                --> if reset fail by service or not support --> show text procedure

*******************************************************************************/
/*############################################################################*/
/*
================================================================================
INCLUDED FILES
================================================================================
*/
#include <PlatFormType.h>

#include <GUIManager.h>

#include    "TimerApp.h"
#include    "KeyBoardApp.h"
#include    "Processes.h"
#include    "OBDToolManager.h"

#include    "Common_Text_Database.h"
#include    "CommonKeyHandler.h"

#include <YMMESelection.h>

//#include    <1_Application\3_User_Interface\3_UI_Processes\Processes\09_Battery_Reset\BatteryReset_Enumeration.h>
//#include    <1_Application\3_User_Interface\3_UI_Processes\Processes\09_Battery_Reset\BatteryReset.h>
//
//
//
//
//
//#include    "BatteryReset.h"



























/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 
*Function name: Proc_Battery_Reset
*Descrtiption : Process for Battery Reset Procedure
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_Battery_Reset(void);
void Proc_Battery_Reset(void)
{
//    enumbool blIsProcChanged;
//    blIsProcChanged = Proc_ProcCmdIsChanged();
//    enumOilResetStatus  eOilResetStatus = eOIL_RESET_NONE;
//    
//    if (blIsProcChanged)
//    {
//        Proc_OilReset_KeyInit();
//        Proc_ProcCmdClearChanged();
//    }
//    switch(Proc_GetCurCmdID())
//    {
//    case CMD_INIT_PROC:
//        if((g_strtMFRVehicleProfile.ValidStatus != eMFR_VALID))
//        {
//            Proc_ChangeCmd(CMD_BATTERY_RESET_SELECT_VEHECLE, 0, 0);
//        }
//        else
//        {
//            Proc_ChangeCmd(CMD_GET_NAVIGATION_SYSTEM, 0, 0);
//        }
//        break;
//        
//        
//    case CMD_BATTERY_RESET_SELECT_VEHECLE:
//        
//        break;
//        
//        
//    case CMD_BATTERY_RESET_AFTER_SELECT_VEHECLE:
//        //if make temp valid, 
//        if(ToolManager_YMMMProfile_IsValid())
//        {
//            //get make to manufacturer adapter
//            strtDTCLibProfileTemp.eMake = Make_Selection_Make_Temp_Get();
//            //change to select system
//            Proc_ChangeCmd(CMD_BATTERY_RESET_CHECK_SUPPORT,0,0);
//        }
//        else//change to display dtc library
//        {
//            Proc_ChangeCmd(PROC_DLC_LIBRARY_MENU_DISPLAY,Proc_GetSelectionItem(),0);
//        }
//        break;
//        
//    case CMD_BATTERY_RESET_CHECK_SUPPORT:
//        
//        break;
//        
//    default:
//        break;
//        
//    }
}