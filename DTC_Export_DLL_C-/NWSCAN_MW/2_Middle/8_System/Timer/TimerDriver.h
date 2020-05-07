/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __TIMERDRIVER_H__
#define __TIMERDRIVER_H__
#include <PlatFormType.h>
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
#ifdef __TIMERDRIVER_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void FreeTimerInit(void);
void FreeTimerStart(void);
void FreeTimerStop(void);
enumbool FreeTimerIsOn(void);
void KeyBoardTimerStart(void);
void KeyBoardTimerStop(void);
void KeyBoardTimerInit(void);
//void DelayTimerInit(void);
//void DelayUs(uint32 iusTimeOut);
//void DelayMs(uint32 imsTimeOut);
//void DelayUsNop(uint32 iusTimeOut);
//void DelayMsNop(uint32 imsTimeOut);
#endif
