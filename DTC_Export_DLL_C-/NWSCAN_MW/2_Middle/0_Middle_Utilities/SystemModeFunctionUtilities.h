/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/
#ifndef __SYSTEM_MODE_FUNCTION_UTILITIES_H__
#define __SYSTEM_MODE_FUNCTION_UTILITIES_H__




/*==============================================================================
                        FUCNTIONs 
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 13, 2012
                2. November 26 2014 Lap Dang added blCalledEnterSystem 
                   to prevent multi-time user calls this function
*Function name: EnterSystemMode
*Descrtiption : Disable all user interupt (free timer, button)
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void EnterSystemMode(void);

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 13, 2012
                2. November 26 2014 Lap Dang modified, added flag blCalledEnterSystem
*Function name: LeaveSystemMode
*Descrtiption : Enable user interupt
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void LeaveSystemMode(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2015 
*Function name: SystemMode_FreeTimer_Stop
*Descrtiption : Disable free timer interupt
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void SystemMode_FreeTimer_Stop(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2015 
*Function name: SystemMode_FreeTimer_Restore
*Descrtiption : restore free timer interupt status
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void SystemMode_FreeTimer_Restore(void);








#endif