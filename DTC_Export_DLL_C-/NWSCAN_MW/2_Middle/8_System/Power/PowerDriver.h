
/*******************************************************************************
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef _POWERDRIVER_H
#define _POWERDRIVER_H


//Sept1314 Lap Dang added to always enable ADC3 to use with NAND version
//to use ADC interrupt
#if NAND_USE_ADC_3_INTERRUPT
#define ALWAYS_ENABLE_ADC_3     (1)
#define TURN_OFF_LOW_BATTERY    (1)

#else
#define ALWAYS_ENABLE_ADC_3     (0)
#endif


#ifdef _POWER_DRIVER_C_

#define VALUE_DETECT_BATTERY    0x0000  /* Vdetect = 1V */

#define VALUE_LOW_BATTERY   0x0486  /* Vlow = 2.8V - July0914 Lap Dang edit value */
//#define VALUE_LOW_BATTERY   0x04A5  /* Vlow = 2.8V - July0914 Lap Dang edit note */
                                    /* Vref+ = 3.3V | Vref- = 0V */
                                    /* ADC with 12 bits */

#endif

//=========================== Prototype Function =============================//
/******************************* PowerInit *************************************
Engineer : Lap Dangruong
Date :  October 29 2014
        
Function: PowerInit
Description: config and enable Pin, Port for power involving
        - Battery ADC
        - VECU ADC
        - Enable power pin for battery
        - VUSB
Input: none
Output: none
*******************************************************************************/
void PowerInit(void);


enumbool HasVECU(void);
void PowerOffBattery(void);
void PowerOnBattery(void);
enumbool  HasBattery(void);
enumbool IsLowBattery(void);
enumbool HasVBUS(void); /* Thinh Ly added */
float gf_ReadEcuBatteryVoltage(void);


#ifdef TURN_OFF_LOW_BATTERY
enumbool IsLowerBattery(uint32);
void PVD_Init(void);
void VECU_Intc_Init(void);
void InitProtectNand(void);
#endif
void SystemReset(void);

#endif /* end define PowerDriver.h */
