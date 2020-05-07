/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __LCD_CONFIG_UC1611_H__
#define __LCD_CONFIG_UC1611_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define MAX_PAGE                (18)   //PAGE 0 => PAGE 18 //LongTo
#define MAX_COLUMN              160
#define MAX_LINE                152  //Number of pages * Line per page

#define NORMAL_MODE_LCD         0
#define REVERSE_MODE_LCD        1

#define PAGE_ICONS              19
#define MAX_ICON_COLUMN         9
#define FIRST_ICON_COLUMN       94
#define END_ICON_COLUMN         103

#define CONNECTION_COLUMNE      103
#define MONITOR1_COLUMNE        102
#define MONITOR2_COLUMNE        101
#define DTC_COLUMNE             100
#define DIGIT1_COLUMNE          99
#define DIGIT2_COLUMNE          98
#define DIGIT3_COLUMNE          96
#define DIGIT4_COLUMNE          95
#define SLASH_IM_COLUMNE        97

#define FIRST_DIGIT_INDEX       (99 - 1)
#define SECOND_DIGIT_INDEX      (98 - 1)
#define THIRD_DIGIT_INDEX       (96 - 1)
#define FOURTH_DIGIT_INDEX      (95 - 1)

//========================== LCD COMMANDS ======================================
#define	PANEL_LOADING1		     0  // DATA_COMMAND = 0x2B
#define PANEL_LOADING2		     3

#define TEMP_COMPENSATION1           0  //temperature compensation
#define TEMP_COMPENSATION2           1  //temperature compensation
#define TEMP_COMPENSATION3           2  //temperature compensation
#define TEMP_COMPENSATION4           3  //temperature compensation

#define LINE_RATE0                   0  // Line rate for LCD
#define LINE_RATE1                   1  // Line rate for LCD
#define LINE_RATE2                   2  // Line rate for LCD
#define LINE_RATE3                   3  // Line rate for LCD

#define BIAS_RATIO0		     0  //xxxx xx BR[1:0]
#define BIAS_RATIO1		     1  //xxxx xx BR[1:0]
#define BIAS_RATIO2		     2  //xxxx xx BR[1:0]
#define BIAS_RATIO3		     3  //xxxx xx BR[1:0]

#define POTENTIOMETER_H		     0x81  //1st byte of 2-byte command
#define POTENTIOMETER_L		     101	

#define ONE_BIT_PER_PIXEL	     1    //1 bit per pixel

#define DISPLAY_8_SHADE          7
#define LAST_PAGE                160
#define FIRST_TEXT_PAGE          8
#define ROW_PER_PAGE             2

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __LCD_CONFIG_UC1611_C__

#else

#endif
#endif
