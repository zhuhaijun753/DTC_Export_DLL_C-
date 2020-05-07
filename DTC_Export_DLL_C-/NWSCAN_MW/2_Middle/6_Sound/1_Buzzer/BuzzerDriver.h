/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/


#ifndef _BUZZERDRIVER_H
#define _BUZZERDRIVER_H

typedef enum _enumTone
{
  TONE_KEY      =   1,
  TONE_POWER    =   2,
  TONE_DONE     =   4,
  TONE_ERASE    =   4,
  TONE_ERROR    =   8,
} enumTone;

#ifdef _BUZZER_DRIVER_

//=========================== Define =========================================//

#define BuzzerOn()  __Set_Gpio_Pin(BUZZER_PORT, BUZZER_PIN)
#define BuzzerOff() __Clear_Gpio_Pin(BUZZER_PORT, BUZZER_PIN)

#define     BEEP_FREQ       5000 // Lap Dang modified BEEP speak for 1 second with frequency = 5KHz
#define     BEEP_TIME       800
#define     TONE_T_ON       (1000000 / BEEP_FREQ) /2
#define     TONE_T_OFF      ((1000000 / BEEP_FREQ)  - (TONE_T_ON))

#define     BEEP_DELAY      60      // Delay time between two beeps, unit is mili second
//============================================================================//

//=========================== Prototype Function =============================//

#else

#endif

void BuzzerInit(void);
void BuzzerControl(enumTone eToneType);
void BuzzerDisable(void);
void BuzzerEnable(void);

#endif // End define BuzzerDriver.h
