/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#define __SYS_PROCESS_C__
#include <stddef.h>
#include <PlatFormType.h>
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
SYS_PROC_MANAGER PROC_Manager;

/*==============================================================================
*                                 FUNCTIONS
==============================================================================*/

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackIsEmpty
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*Output       :
*-----------------------------------------------------------------------------*/
enumbool SysCmdProcStackIsEmpty(SYS_PROC_STACK* p_CmdProcStatck)
{
    enumbool blIsEmpty;
    if (p_CmdProcStatck->iProcCmdStackSize > 0)
    {
        blIsEmpty = eFALSE;
    }
    else
    {
        blIsEmpty = eTRUE;
    }
    return blIsEmpty;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: SysCmdProcStackGetSize
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*Output       :
*-----------------------------------------------------------------------------*/
uint32 SysCmdProcStackGetSize(SYS_PROC_STACK* p_CmdProcStatck)
{
    return p_CmdProcStatck->iProcCmdStackSize;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackRemoveAt
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : uint32 iPos
*Output       :
*-----------------------------------------------------------------------------*/
enumbool SysCmdProcStackRemoveAt(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos)
{
    enumbool blRemoveStatus;
    uint32 iIdx;
    if (iPos < p_CmdProcStatck->iProcCmdStackSize)
    {
        for (iIdx = iPos + 1; iIdx < p_CmdProcStatck->iProcCmdStackSize; iIdx++)
        {
            p_CmdProcStatck->ProcCmdStack[iIdx - 1]= p_CmdProcStatck->ProcCmdStack[iIdx];
        }
        p_CmdProcStatck->iProcCmdStackSize--;
        blRemoveStatus = eTRUE;
    }
    else
    {
        blRemoveStatus = eFALSE;
    }
    return blRemoveStatus;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: SysCmdProcStackRemoveFrom
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : uint32 iPos
*Output       :
*-----------------------------------------------------------------------------*/
enumbool SysCmdProcStackRemoveFrom(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos)
{
    enumbool blRemoveStatus;

    if (iPos < p_CmdProcStatck->iProcCmdStackSize)
    {
        p_CmdProcStatck->iProcCmdStackSize = iPos;
        blRemoveStatus = eTRUE;
    }
    else
    {
        blRemoveStatus = eFALSE;
    }
    return blRemoveStatus;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackPush
*Descrtiption : Add Proc, cmd to top of stack
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_STAT* pCmdProc
*Output       :
*-----------------------------------------------------------------------------*/
void SysCmdProcStackPush(SYS_PROC_STACK* p_CmdProcStatck,
                         SYS_PROC_STAT* pCmdProc)
{
    SysCmdProcStackRemove(p_CmdProcStatck, pCmdProc);
    p_CmdProcStatck->ProcCmdStack[p_CmdProcStatck->iProcCmdStackSize] = *pCmdProc;
    p_CmdProcStatck->iProcCmdStackSize++;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackPush
*Descrtiption : Add Proc, cmd to top of stack
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_STAT* pCmdProc
*Output       :
*-----------------------------------------------------------------------------*/
void SysCmdProcStackPop(SYS_PROC_STACK* p_CmdProcStatck)
{
    SYS_PROC_STAT* pCmdProc;

    pCmdProc = SysCmdProcStackGetTopPtr(p_CmdProcStatck);
    SysCmdProcStackRemove(p_CmdProcStatck, pCmdProc);
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackTop
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*Output       :
*-----------------------------------------------------------------------------*/
SYS_PROC_STAT* SysCmdProcStackGetTopPtr(SYS_PROC_STACK* p_CmdProcStatck)
{
    SYS_PROC_STAT* p_TopProc = NULL;
    uint32 iTopIdx;

    if (p_CmdProcStatck->iProcCmdStackSize > 0)
    {
        iTopIdx = p_CmdProcStatck->iProcCmdStackSize - 1;
        p_TopProc = &p_CmdProcStatck->ProcCmdStack[iTopIdx];
    }
    return p_TopProc;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackPush
*Descrtiption : Remove all eProc from stack
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_STAT* pCmdProc
*Output       :
*-----------------------------------------------------------------------------*/
void SysCmdProcStackRemove(SYS_PROC_STACK* p_CmdProcStatck,
                           SYS_PROC_STAT* pCmdProc)
{
    uint32 iIdx = 0;
    while (iIdx < p_CmdProcStatck->iProcCmdStackSize)
    {
        if ((p_CmdProcStatck->ProcCmdStack[iIdx].eProc == pCmdProc->eProc)
            && (p_CmdProcStatck->ProcCmdStack[iIdx].eCmd == pCmdProc->eCmd))
        {
            SysCmdProcStackRemoveFrom(p_CmdProcStatck, iIdx);
            p_CmdProcStatck->iProcCmdStackSize = iIdx;
        }
        else
        {
            iIdx++;
        }
    }
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackPush
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_STAT* pCmdProc
*Output       :
*-----------------------------------------------------------------------------*/
void SysCmdProcStackRemoveProc(SYS_PROC_STACK* p_CmdProcStatck,
                               SYS_PROC_ID eProc)
{
    uint32 iIdx = 0;
    while (iIdx < p_CmdProcStatck->iProcCmdStackSize)
    {
        if (p_CmdProcStatck->ProcCmdStack[iIdx].eProc == eProc)
        {
            SysCmdProcStackRemoveFrom(p_CmdProcStatck, iIdx);
        }
        else
        {
            iIdx++;
        }
    }
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackPushProc
*Descrtiption : Remove all same proc from Stack then add Proc, cmd to top
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_STAT* pCmdProc
*Output       :
*-----------------------------------------------------------------------------*/
void SysCmdProcStackPushProc(SYS_PROC_STACK* p_CmdProcStatck,
                             SYS_PROC_STAT * pCmdProc)
{
    SysCmdProcStackRemoveProc(p_CmdProcStatck, pCmdProc->eProc);
    SysCmdProcStackPush(p_CmdProcStatck, pCmdProc);
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackPushProc
*Descrtiption : Remove all same proc from Stack
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_STAT* pCmdProc
*Output       :
*-----------------------------------------------------------------------------*/
void SysCmdProcStackPopProc(SYS_PROC_STACK* p_CmdProcStatck)
{
    SYS_PROC_STAT* p_TopProc;
    SYS_PROC_ID    eProc;

    if (p_CmdProcStatck->iProcCmdStackSize > 0)
    {
        p_TopProc = SysCmdProcStackGetTopPtr(p_CmdProcStatck);
        eProc = p_TopProc->eProc;
        SysCmdProcStackRemoveProc(p_CmdProcStatck, eProc);
    }
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: SysCmdProcStackGetProcIdx
*Descrtiption : Seacrh Proc by Proc name from Top to bottom
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_ID eProc
*Output       :
*-----------------------------------------------------------------------------*/
sint32 SysCmdProcStackGetProcIdx(SYS_PROC_STACK* p_CmdProcStatck,
                                 SYS_PROC_ID eProc)
{
    sint32 iIdx;

    iIdx = p_CmdProcStatck->iProcCmdStackSize - 1;
    while (iIdx >= 0)
    {
        if (p_CmdProcStatck->ProcCmdStack[iIdx].eProc == eProc)
        {
            break;
        }
        else
        {
            iIdx--;
        }
    }
    return iIdx;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: SysCmdProcStackGetCmdIdx
*Descrtiption :
*Input        : SYS_PROC_STACK* p_CmdProcStatck
*             : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
sint32 SysCmdProcStackGetCmdIdx(SYS_PROC_STACK* p_CmdProcStatck,
                                SYS_PROC_ID eProc, SYS_CMD_ID eCmd)
{
    sint32 iIdx;

    iIdx = p_CmdProcStatck->iProcCmdStackSize - 1;
    while (iIdx >= 0)
    {
        if ((p_CmdProcStatck->ProcCmdStack[iIdx].eProc == eProc)
            &&(p_CmdProcStatck->ProcCmdStack[iIdx].eCmd  == eCmd))
        {
            break;
        }
        else
        {
            iIdx--;
        }
    }
    return iIdx;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: SysCmdProcStackGetPrevProcIdx
*Descrtiption : Get previous Proc ID (search from top)
*Input        :
*Output       : -1 There was no prev proc of this proc, i: index of proc in stack
*-----------------------------------------------------------------------------*/
sint32 SysCmdProcStackGetPrevProcIdx(SYS_PROC_STACK* p_CmdProcStatck)
{
    SYS_PROC_STAT* p_TopProc;
    SYS_PROC_ID eProc;
    sint32 iIdx;
    sint32 iReturn = - 1;

    p_TopProc = SysCmdProcStackGetTopPtr(p_CmdProcStatck);
    eProc = p_TopProc->eProc;

    iIdx = p_CmdProcStatck->iProcCmdStackSize - 1;
    for (; iIdx >= 0; iIdx--)
    {
        if (p_CmdProcStatck->ProcCmdStack[iIdx].eProc != eProc)
        {
            iReturn = iIdx;
            break;
        }
    }

    return iReturn;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: SysCmdProcStackGetProcPtrAt
*Descrtiption :
*Input        : uint32 iPos
*Output       : Pointer to Process at index iPos
*-----------------------------------------------------------------------------*/
SYS_PROC_STAT* SysCmdProcStackGetProcPtrAt(SYS_PROC_STACK* p_CmdProcStatck, uint32 iPos)
{
    SYS_PROC_STAT* p_Proc;
    if (iPos < p_CmdProcStatck->iProcCmdStackSize)
    {
        p_Proc = &(p_CmdProcStatck->ProcCmdStack[iPos]);
    }
    else
    {
        p_Proc = NULL;
    }
    return p_Proc;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 26, 2011
*Function name: Proc_StackClean
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_StackClean(void)
{
    PROC_Manager.strtProcStack.iProcCmdStackSize = 0;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_GetCurProcPtr
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
SYS_PROC_STAT* Proc_GetCurProcPtr(void)
{
    SYS_PROC_STAT* p_Proc;

    p_Proc = SysCmdProcStackGetTopPtr(&PROC_Manager.strtProcStack);

    return p_Proc;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_GetCurProcID
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
SYS_PROC_ID Proc_GetCurProcID(void)
{
    SYS_PROC_STAT* p_Proc;
    SYS_PROC_ID    eProc;

    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        eProc = p_Proc->eProc;
    }
    else
    {
        p_Proc = PROC_NONE;
    }
    return eProc;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_GetCurCmdID
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
SYS_CMD_ID Proc_GetCurCmdID(void)
{
    SYS_PROC_STAT* p_Proc;
    SYS_CMD_ID     eCmd;

    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        eCmd = p_Proc->eCmd;
    }
    else
    {
        eCmd = CMD_NONE;
    }
    return eCmd;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: Proc_GetPrevProcess
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*Output       :
*-----------------------------------------------------------------------------*/
SYS_PROC_STAT* Proc_GetPrevProcPtr(void)
{
    sint32 iPrevProcIdx;
    SYS_PROC_STAT* p_Proc;
    SYS_PROC_STACK* p_CmdProcStatck;

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    iPrevProcIdx = SysCmdProcStackGetPrevProcIdx(p_CmdProcStatck);
    if (iPrevProcIdx >= 0)
    {
        p_Proc= SysCmdProcStackGetProcPtrAt(p_CmdProcStatck, iPrevProcIdx);
    }
    else
    {
        p_Proc = NULL;
    }
    return p_Proc;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 16, 2011
*Function name: Proc_GetPrevProcess
*Descrtiption : Get previous Process ID
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
SYS_PROC_ID Proc_GetPrevProcID(void)
{
    SYS_PROC_STAT* p_Proc;
    SYS_PROC_ID eProc;


    p_Proc = Proc_GetPrevProcPtr();
    if (p_Proc != NULL)
    {
        eProc = p_Proc->eProc;
    }
    else
    {
        eProc = PROC_NONE;
    }
    return eProc;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_GetPrevCmdID
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
SYS_CMD_ID Proc_GetPrevCmdID(void)
{
    SYS_PROC_STAT*  p_CurProcCmd;
    SYS_PROC_STAT*  p_PrevProcCmd;
    SYS_PROC_STACK* p_CmdProcStatck;
    uint32          iStackSize;
    SYS_CMD_ID      eCmd = CMD_NONE;

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);
    p_CurProcCmd    = Proc_GetCurProcPtr();

    if (p_CurProcCmd != NULL)
    {
        iStackSize = SysCmdProcStackGetSize(p_CmdProcStatck);
        if (iStackSize > 1) /*At least 2 prc cmd in stack*/
        {
            p_PrevProcCmd = SysCmdProcStackGetProcPtrAt(p_CmdProcStatck, iStackSize - 2);
            if (p_PrevProcCmd->eProc == p_CurProcCmd->eProc)
            {
                eCmd = p_PrevProcCmd->eCmd;
            }
        }
    }
    return eCmd;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_GetSelectionItem
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
sint32 Proc_GetSelectionItem(void)
{
    sint32 iSelected;

    SYS_PROC_STAT* p_Proc;
    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        iSelected = p_Proc->iSelectedItem;
    }
    else
    {
        iSelected = 0;
    }
    return iSelected;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_SetSelectionItem
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_SetSelectionItem(sint32 iSelectedIdx)
{
    SYS_PROC_STAT* p_Proc;
    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        p_Proc->iSelectedItem = iSelectedIdx;
    }
}

/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Mar 08, 2013
*Function name: Proc_GetDispType
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
SCR_DISP_TYPE Proc_GetDispType(void)
{
    SCR_DISP_TYPE eDispType;

    SYS_PROC_STAT* p_Proc;
    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        eDispType = p_Proc->eSrcDispType;
    }
    else
    {
        eDispType = SCR_DISP_FULL;
    }
    return eDispType;
}

/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Mar 08, 2013
*Function name: Proc_SetDispType
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_SetDispType(SCR_DISP_TYPE eDispType)
{
    SYS_PROC_STAT* p_Proc;
    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        p_Proc->eSrcDispType = eDispType;
    }
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 18, 2011
*Function name: Proc_GetParam
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void const* Proc_GetParam(void)
{
    void const* p_Param = NULL;
    SYS_PROC_STAT* p_Proc;
    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        p_Param = p_Proc->p_Param;
    }
    return p_Param;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 18, 2011
*Function name: Proc_GetParam
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_SetParam(void const* p_Param)
{
    SYS_PROC_STAT* p_Proc;
    p_Proc = Proc_GetCurProcPtr();
    if (p_Proc != NULL)
    {
        p_Proc->p_Param = p_Param;
    }
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_EnterProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_EnterProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_STAT  strtCmdProc =
    {
        .eCmd          = eCmd,
        .eProc         = eProc,
        .iSelectedItem = 0,
        .eSrcDispType  = SCR_DISP_FULL,
        .p_Param       = NULL
    };

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);
    //SysCmdProcStackRemoveProc(p_CmdProcStatck, eProc);
    SysCmdProcStackPushProc(p_CmdProcStatck, &strtCmdProc);

    PROC_Manager.blIsProcChange = eTRUE;
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ChangeProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_ChangeProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_STAT  strtCmdProc =
    {
        .eCmd          = eCmd,
        .eProc         = eProc,
        .iSelectedItem = 0,
        .eSrcDispType  = SCR_DISP_FULL,
        .p_Param       = NULL
    };

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    SysCmdProcStackPopProc(p_CmdProcStatck); /*remove current Proc*/
    SysCmdProcStackPushProc(p_CmdProcStatck, &strtCmdProc);
    PROC_Manager.blIsProcChange = eTRUE;
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_JumpToProc
*Descrtiption : Jump to a exist Proc in stack
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_JumpToProc(SYS_PROC_ID eProc, SYS_CMD_ID eCmd)
{
    sint32 iProcIdx;
    SYS_PROC_STACK* p_CmdProcStatck;

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);
    iProcIdx = SysCmdProcStackGetCmdIdx(p_CmdProcStatck, eProc, eCmd);

    if (iProcIdx < 0) /*eProc doesnt exist in our stack*/
    {
        Proc_EnterProc(eProc, eCmd);
    }
    else
    {
        SysCmdProcStackRemoveFrom(p_CmdProcStatck, iProcIdx + 1);
    }
    Proc_SetDispType(SCR_DISP_FULL);
    PROC_Manager.blIsProcChange = eTRUE;
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ChangeProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_LeaveProc(void)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    SysCmdProcStackPopProc(p_CmdProcStatck);
    Proc_SetDispType(SCR_DISP_FULL);
    PROC_Manager.blIsProcChange = eTRUE;
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_EnterProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_EnterCmd(SYS_CMD_ID eCmd, sint32 iSelectIdx, const void* p_Param)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_STAT  strtCmdProc =
    {
        .eCmd          = eCmd,
        .eProc         = Proc_GetCurProcID(),
        .iSelectedItem = iSelectIdx,
        .eSrcDispType  = SCR_DISP_FULL,
        .p_Param       = p_Param
    };

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    //SysCmdProcStackRemove(p_CmdProcStatck, &strtCmdProc);
    SysCmdProcStackPush(p_CmdProcStatck, &strtCmdProc);

    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ChangeProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_ChangeCmd(SYS_CMD_ID eCmd, sint32 iSelectIdx, const void* p_Param)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_STAT  strtCmdProc =
    {
        .eCmd          = eCmd,
        .eProc         = Proc_GetCurProcID(),
        .iSelectedItem = iSelectIdx,
        .eSrcDispType  = SCR_DISP_FULL,
        .p_Param       = p_Param
    };

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    SysCmdProcStackPop(p_CmdProcStatck);
    SysCmdProcStackPush(p_CmdProcStatck, &strtCmdProc);
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ChangeProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_JumpToCmd(SYS_CMD_ID eCmd)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_ID eProc;
    sint32 iIdx;

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    eProc = Proc_GetCurProcID();
    iIdx = SysCmdProcStackGetCmdIdx(p_CmdProcStatck, eProc, eCmd);
    if (iIdx >= 0)
    {
        SysCmdProcStackRemoveFrom(p_CmdProcStatck, iIdx + 1);
    }
    else
    {
        Proc_EnterCmd(eCmd, 0, NULL);
    }
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Mar 08, 2013
*Function name: Proc_EnterCmdNew
*Descrtiption :
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_EnterCmdNew(SYS_CMD_ID eCmd, sint32 iSelectIdx, SCR_DISP_TYPE eDispType, 
                      const void* p_Param)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_STAT  strtCmdProc =
    {
        .eCmd          = eCmd,
        .eProc         = Proc_GetCurProcID(),
        .iSelectedItem = iSelectIdx,
        .eSrcDispType  = eDispType,
        .p_Param       = p_Param
    };

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    SysCmdProcStackPush(p_CmdProcStatck, &strtCmdProc);

    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ChangeCmdNew
*Descrtiption :
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_ChangeCmdNew(SYS_CMD_ID eCmd, sint32 iSelectIdx, SCR_DISP_TYPE eDispType,
                       const void* p_Param)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    SYS_PROC_STAT  strtCmdProc =
    {
        .eCmd          = eCmd,
        .eProc         = Proc_GetCurProcID(),
        .iSelectedItem = iSelectIdx,
        .eSrcDispType  = eDispType,
        .p_Param       = p_Param
    };

    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    SysCmdProcStackPop(p_CmdProcStatck);
    SysCmdProcStackPush(p_CmdProcStatck, &strtCmdProc);
    PROC_Manager.blIsCmdChange  = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ChangeProc
*Descrtiption :
*Input        : SYS_PROC_ID eProc
*             : SYS_CMD_ID eCmd
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_LeaveCmd(void)
{
    SYS_PROC_STACK* p_CmdProcStatck;
    p_CmdProcStatck = &(PROC_Manager.strtProcStack);

    SysCmdProcStackPop(p_CmdProcStatck);
    /*May 13, 2013: Hoang Nguyen add to update all screen when leave cmd*/
    Proc_SetDispType(SCR_DISP_FULL);
    PROC_Manager.blIsCmdChange = eTRUE;
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_IsProcCmdChange
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
enumbool Proc_ProcCmdIsChanged(void)
{

    enumbool blIsChanged;
    if ((PROC_Manager.blIsProcChange )|| (PROC_Manager.blIsCmdChange))
    {
        blIsChanged = eTRUE;
    }
    else
    {
        blIsChanged = eFALSE;
    }
    return blIsChanged;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ProcCmdClearChanged
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_ProcCmdClearChanged(void)
{

    PROC_Manager.blIsProcChange = eFALSE;
    PROC_Manager.blIsCmdChange = eFALSE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ProcCmdClearChanged
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_ProcCmdSetChanged(void)
{

    PROC_Manager.blIsProcChange = eTRUE;
    PROC_Manager.blIsCmdChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_DataIsChanged
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
enumbool Proc_DataIsChanged(void)
{
    return PROC_Manager.blIsDataChange;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_DataSetChanged
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_DataSetChanged(void)
{
    PROC_Manager.blIsDataChange = eTRUE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_DataClearChanged
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_DataClearChanged(void)
{
    PROC_Manager.blIsDataChange = eFALSE;
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 08, 2011
*Function name: Proc_RemoveFrom
*Descrtiption : Remove all from Proc index in stack
*Input        : uint32 iPos
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_RemoveFrom(uint32 iPos)
{
    SysCmdProcStackRemoveFrom(&(PROC_Manager.strtProcStack), iPos);
}

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 17, 2011
*Function name: Proc_ManagerInit
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_ManagerInit(void)
{
    PROC_Manager.strtProcStack.iProcCmdStackSize = 0;
}