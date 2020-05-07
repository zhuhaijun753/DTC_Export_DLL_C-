/******************************************************************************
===============================================================================
Lap Dang Dev
Filename: OBDConf.h
Description: OBD tool feature/Hardware configurations
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __MD75_85_CONFIG_H__
#define __MD75_85_CONFIG_H__

#include    "GuiType.h"
#include    "GUIManager.h"

/*Note: Configuration below set to make sure features are not enable by write
        setting bytes and sometimes they do not reduce firmware size*/
/*==========================CPU Setting===================================*/
#define CPU_PLATFORM_STM32F427  1

#define CPU_PLATFORM_STM32F205  0

#if CPU_PLATFORM_STM32F427
#define STM32F4XX
#elif CPU_PLATFORM_STM32F205
#define STM32F2XX
#else
#error need to choose platform
#endif
/*==========================End CPU Setting===============================*/

/*==========================Feature Setting===================================*/

#define _ENABLE_ATE_FUNCTION_   1            
            
#define _ENABLE_3170E_3180E_    0

#define _OBD1_ENABLE            1
#define _ENHANCED_ENABLE        1
#define _ABS_ENABLE             1
#define _SRS_ENABLE             1
#define _LIVE_DATA_ENABLE       1
#define _SPECIAL_TEST_ENABLE    1
#define _FIX_ASSIST_ENABLE      1

#define ENABLE_BLUETOOTH_FUNCTION 0

/*==========================End Feature Setting===============================*/

/*=============================USB Setting====================================*/
#define INNOVA_VID              0x1720
#define MATCO_PRODUCT_ID_BASE         0x0400
#define _USB_AUTOLAUNCH         1

/*===========================End USB Setting==================================*/

/*===========================Default language & Brightness====================*/
/*============================================================================*/
#define _USE_ENGLISH            0
#define DEFAULT_LANGUAGE        GUI_LANG_ENGLISH
#define DEFAULT_BRIGHTNESS      BRIGHTNESS_LEVEL3
#define DEFAULT_UNIT            UNIT_USA
/*==========================Hardware profile==================================*/


//#warning may need modify this define with the API for hardware MD75, MD85
#define __INNOVA_31X0D_HW__

////#define LCD_ST7528          (0)
//#define LCD_UC1611_OLD      (1)
//#define LCD_UC1611_NEW      (2)
//#define LCD_GOLDENTEK       (3)
//#define LCD_KAIEE           (4)
//#define LCD_3_5_INCH_ILITEK_ILI9488     (5)
//
//
//
//#ifdef OBD3130E_KAIEE_LCD
//#define LCD_TYPE            (LCD_KAIEE)
//
//#else 
//#ifdef  (USING_LCD_3_5_INCH_ILITEK_ILI9488)
//#define LCD_TYPE            (LCD_3_5_INCH_ILITEK_ILI9488)
//
//#else 
//#ifdef OBD3130E_GOLDENTEK_LCD
//#define LCD_TYPE            (LCD_GOLDENTEK)
//#endif
//
//#endif
//#endif


#define USE_STDPERIPH_DRIVER
#define USE_USB_OTG_HS
#define USE_EMBEDDED_PHY

/*==========================Hardware Setting==================================*/

#define USING_SOFT_TOOLID       1
#define USING_HW_TOOLID         0
#if (!(USING_SOFT_TOOLID ^ USING_HW_TOOLID))
    #error Please choose Tool ID type
#endif


#define OBD_MD75_TOOL_ID         0x1A
#define OBD_MD85_TOOL_ID         0x1B

#define TOOL_ID_DEFAULT         OBD_MD75_TOOL_ID

#define TOOL_ID_MIN             OBD_MD75_TOOL_ID//need modify if add more tool out of range
#define TOOL_ID_MAX             OBD_MD85_TOOL_ID//need modify if add more tool out of range


#define NUMBER_TOOL_IN_SERIRIES 2


#define _EXTERNAL_FLASH         0
#define _EEPRROM                0
#define _FILE_SYSTEM            1

#define ENABLE_VEHICLE_FEATURE  1

#ifdef USING_NAND_FLASH
#define _NAND_FLASH             1
#define _SD_CARD                0
#else
#ifdef USING_SD_CARD
#define _NAND_FLASH             0
#define _SD_CARD                1
// June 24, 2014 - CuongHL added macro for security check
#define _SD_CARD_SECUTIRY_CHECK 0
#endif
#endif


#if ((!_EXTERNAL_FLASH) && (!_FILE_SYSTEM))
    #error Must be choose at least FS or External Flash
#endif
#if (_SD_CARD)
#define CD_ISO_IMAGE_PATH       "\\PC\\Data_31303.bin"
#endif

#define ISO_LOCATION            USING_MEMORY_NONE
#define DTC_LIST_LOCATION       USING_FILE_SYSTEM
#define USE_FF_HOT_KEY          0
/*==========================End Hardware Setting==============================*/
#endif
