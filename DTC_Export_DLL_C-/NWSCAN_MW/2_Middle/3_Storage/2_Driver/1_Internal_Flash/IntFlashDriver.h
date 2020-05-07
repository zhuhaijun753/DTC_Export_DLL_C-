/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __INTFLASH_DRIVER_H__
#define __INTFLASH_DRIVER_H__

#ifdef STM32F2XX
#include "STM32F2xxIntFlashDriver.h"

#elif defined(STM32F4XX)
#include "STM32F4xxIntFlashDriver.h"

#else
#error Need Porting
#endif

#endif


