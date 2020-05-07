/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#define __PROCESSES_C__
#include <string.h>

#include <PlatFormType.h>

//#include <GUIManager.h>
//#include <OBDToolManager.h>


#include "SysProcess.h"
#include "Processes.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 27, 2011
*Function name: OnRestoreAndLeaveProc
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void OnRestoreAndLeaveProc(void)
{
//    EnvironmentRestore();
    Proc_LeaveProc();
    Proc_SetDispType(SCR_DISP_FULL);
//    if((Proc_GetCurProcID() == PROC_VIEW_LIVE_GRAPH)
//       || ((Proc_GetCurProcID() == PROC_PLAYBACK_LIVE_DATA) 
//           && ((Proc_GetCurCmdID() == CMD_DISP_GRAPH_MERGE)
//               || (Proc_GetCurCmdID() == CMD_DISP_GRAPH)
//                   || (Proc_GetCurCmdID() == CMD_DISP_GRAPH_MULTI))))
//    {
//        GUI_IconDispTypeChange(ICON_DISP_NONE);
//    }
//    else
//    {
//        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
//    }
}
/*------------------------------------------------------------------------------
*Engineer     : GiangDo
*Historical   : June 8 -2012
*Function name: OnRestoreAndLeaveCmd
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void OnRestoreAndLeaveCmd(void)
{
//    EnvironmentRestore();
    Proc_LeaveCmd();
}
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 27, 2011
*Function name: OnBackUpAndEnterProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void OnBackUpAndEnterProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd)
{
//    EnvironmentBackup();
    Proc_EnterProc(eProc, eCmd);
}

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
void Proc_Process(void)
{
    uint8 bIdx;
    SYS_PROC_ID eCurProc;

    eCurProc = Proc_GetCurProcID();
    bIdx = 0;
    while (g_strtPhocHandlerList[bIdx].eProc != PROC_NONE)
    {
        if (eCurProc == g_strtPhocHandlerList[bIdx].eProc)
        {
            if (g_strtPhocHandlerList[bIdx].eProc != NULL)
            {
                g_strtPhocHandlerList[bIdx].fpProc();
            }
            
           break;
        }
        else
        {
            bIdx++;
        }
    }
}
