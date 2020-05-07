/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __SYSTEM_DRIVER_H__
#define __SYSTEM_DRIVER_H__
#include "coremcu.h"
//#include <hwdrivers\power\powerdriver.h>
//#include <hwdrivers\timer\timerdriver.h>
//#include <hwdrivers\led\leddriver.h>
//#include <hwdrivers\lcd\lcddriver.h>
//#include <hwdrivers\button\buttondriver.h>
//#include <hwdrivers\buzzer\buzzerdriver.h>
//#include <hwdrivers\eeprom\eeprominterface.h>
//#include <hwdrivers\exflash\exflashinterface.h>
//#include <hwdrivers\intflash\intflashdriver.h>
//#include <hwdrivers\sdcard\sdcard.h>
//#include <hwdrivers\NandFlash\fsmc_nand.h>
//#include <hwdrivers\bluetooth\BTDriver.h>
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __SYSTEM_DRIVER_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void SystemDriverInit(void);
//void JumpToBootloader(void);
//void SystemReset(void);
void TestNandFlash(void);
//uint8_t SD_Detect(void);
#endif


