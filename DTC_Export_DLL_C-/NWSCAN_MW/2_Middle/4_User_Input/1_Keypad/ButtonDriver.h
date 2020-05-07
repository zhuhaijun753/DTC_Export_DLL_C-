/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef _BUTTONDRIVER_H
#define _BUTTONDRIVER_H
#include "coremcu.h"

#define ERASE_FIRMWARE_KEY_COMBINE  (ERASE_KEY_PIN)
#define ERASE_NAND_KEY_COMBINE      (DTC_KEY_PIN)

typedef enum _enumKeyInterrupt
{
    KEY_NO_INT         = 0,
    KEY_LDM_INT        = MenuButton_EXTI_Line,
    KEY_ENTER_INT      = EnterButton_EXTI_Line,
    KEY_ERASE_INT      = EraseButton_EXTI_Line,
    KEY_DTC_INT        = ScrollDTCButton_EXTI_Line,
    KEY_DOWN_INT       = DownArrowButton_EXTI_Line,
    KEY_UP_INT         = UpArrowButton_EXTI_Line,
    KEY_POWER_LINK_INT = LinkButton_EXTI_Line,
    KEY_FF_INT         = FFButton_EXTI_Line,
    KEY_LD_INT         = LDButton_EXTI_Line,
    KEY_ALL_INT        = (KEY_LDM_INT | KEY_ENTER_INT | KEY_ERASE_INT | \
                          KEY_DTC_INT | KEY_DOWN_INT | KEY_UP_INT  | KEY_POWER_LINK_INT | \
                          KEY_FF_INT |KEY_LD_INT),
    KEY_INT_MAX        = 0xFFFFFFFF
}enumKeyInterrupt;


#define KEY_HOLDING_TIMEOUT         1000
#define KEY_PRESS_TIMEOUT           50
#define KEY_PRESS_DEBOUND_DELAY     10
#define KEY_REPEAT_INTERVAL         250 /*300ms Repeat post press*/

#ifdef _BUTTON_DRIVER_

#else

#endif

uint32 GetCurrentKeyIO(void);
uint32 GetCurrentKeyIOPortG(void);
uint32 GetCurrentKeyIOPortD(void);
void ButtonInit(void);
void ButtonDisable(enumKeyInterrupt eKeyInts);
void ButtonEnable(enumKeyInterrupt eKeyInts);
enumKeyInterrupt ButtonGetIntStatus(void);
#endif
