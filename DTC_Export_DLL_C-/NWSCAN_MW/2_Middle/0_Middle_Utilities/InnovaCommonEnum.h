/******************************************************************************
===============================================================================
Lap Dang Dev
Filename: InnovaCommonEnum.h
Description: Declare all enumeration should be used on many group of middle and
                application
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __INNOVA_COMMON_ENUM_H__
#define __INNOVA_COMMON_ENUM_H__
typedef enum __enumUsbStorageMode
{
    eUSBMODE_NONE   = 0,
    
    eUSBMODE_STORAGE_ENABLE = 1,
    eUSBMODE_STORAGE_DISABLE = 2,
    
    eUSBMODE_STORAGE_MAX = 0xFF,
    
}enumUsbStorageMode;

/*this enum is declared to use for data stored in memory (sd card, nand flash, eMMC...)*/
typedef enum __enumMemoryLanguage
{
    eMEM_LANGUAGE_UNDEFINE      = 0,
    
    eMEM_LANGUAGE_ENGLISH       = 1,
    eMEM_LANGUAGE_SPANISH       = 2,
    eMEM_LANGUAGE_FRENCH        = 3,
    eMEM_LANGUAGE_JAPANESE      = 4,
    eMEM_LANGUAGE_CHINESE       = 5,
    eMEM_LANGUAGE_VIETNAMESE    = 6,
    
    eMEM_LANGUAGE_MAX           = 0xFF
}enumMemoryLanguage;


#endif
