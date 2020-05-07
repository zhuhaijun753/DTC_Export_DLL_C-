/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __TIMERAPP_H__
#define __TIMERAPP_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
/*time_after(a,b) returns true if the time a is after time b.*/
#define time_after(a,b)         (((int)(b) - (int)(a)) < 0)
#define time_before(a,b)        time_after(b,a)
#define time_after_eq(a,b)      (((int)(a) - (int)(b)) >= 0)
#define time_before_eq(a,b)     time_after_eq(b,a)

/*time_elapsed(a,b) returns elapsed time from a to b*/
#define time_elapsed(a,b)       (((unsigned int) b) + (0xFFFFFFFF - ((unsigned int) a) + 1))

#define SECOND_TO_TICK(x)             (10*x)

#if TEST_INTERNAL_BATTERY_LIFE
#define AUTO_TURN_OFF_PERIOD          SECOND_TO_TICK(4000000000)   /*never turn off*/
#else
#define AUTO_TURN_OFF_PERIOD          SECOND_TO_TICK(120)   /* 120 second*/
#endif

#define HIDDEN_LINK_PERIOD            SECOND_TO_TICK(30)    /* 30 second - As Release doc */
#if 1 /*Dec1813 Lap Dang modified to increase frequence of monitor icon flashing*/
#define FLASH_ICON_PERIOD             SECOND_TO_TICK(0.5)     /* 0.5 second*/
#else
#define FLASH_ICON_PERIOD             SECOND_TO_TICK(1)     /* 1 second*/
#endif

#define TIME_GET_LIVE_DATA            SECOND_TO_TICK(5/10)  /* 0.5 second*/

#define TIME_GET_LIVE_IMMON           SECOND_TO_TICK(2)     /* 2 second*/
#define TIME_GET_LIVE_DATA_KW_1281    SECOND_TO_TICK(1)     /* 1 second*/
#define TIME_GET_GRAPH_DATA           SECOND_TO_TICK(1/10)  /* 0.2 second*/
#define LOW_BAT_WARNING_PERIOD        SECOND_TO_TICK(25/10) /* 2.5 second*/
#define TIME_AUTO_RELINK              SECOND_TO_TICK(3)     /* 3   second*/
#define TIME_AUTO_RELINK_AFTER_FAIL   SECOND_TO_TICK(30)    /* 30   second*/
//#define TIME_CHECK_CABLE_CHANGE       SECOND_TO_TICK(2/10)  /* 0.2 second*/
#define TIME_GET_BATERY_VOLTAGE       SECOND_TO_TICK(5/10)  /* 0.2 second*/

/*when user unplug and plug again within 10s, do not link, just display confirm last linked vehicle*/
#define TIME_RESET_SELECTED_VEHICLE_FLAG    SECOND_TO_TICK(10)

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __TIMERAPP_C__
uint32 jiffies = 0; /*0.1Second each tick*/
uint32 iTurnOffTimeOut = 0;
uint32 iFlashIconTimeOut = 0;
uint32 iHiddenLink_Counter = 0;
uint32 iTimeOutAfterJiffies;


#else
extern uint32 jiffies;
extern uint32 iTurnOffTimeOut;
extern uint32 iFlashIconTimeOut;
extern uint32 iHiddenLink_Counter;
extern uint32 iTimeOutAfterJiffies;

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

void FreeTimerISR(void);
void DelayUsNop(uint32 iusTimeOut);
void DelayMsNop(uint32 imsTimeOut);


/*==============================================================================
                    MORE FUNCTIONs SUPPORTED

==============================================================================*/ 
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: SystemTimer_Timeout_Set
*Descrtiption : set time out to do an event
*Input        : uint32 iTimeoutSecond
*Output       :
*-----------------------------------------------------------------------------*/
void SystemTimer_Timeout_Set(uint32   iTimeoutSecond);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 27 2014
*Function name: SystemTimer_Timeout_Set
*Descrtiption : get time out status with timing set before by function SystemTimer_Timeout_Set
*Input        :  
*Output       : enumbool - status of time out (true/false)
*-----------------------------------------------------------------------------*/
enumbool SystemTimer_Timeout_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1615
*Function name: SystemTimer_Timeout_DeciSecond_Set
*Descrtiption : set time out (in decisecond) to do an event
*Input        : uint32 iTimeoutMiliSecond
*Output       :
*-----------------------------------------------------------------------------*/
void SystemTimer_Timeout_DeciSecond_Set(uint32   iTimeoutDeciSecond);



#endif
