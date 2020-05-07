#ifndef __MEMORYINTERFACE_INTERNAL_FLASH_H__
#define __MEMORYINTERFACE_INTERNAL_FLASH_H__

#include    "ToolSetting_Interface_Enum.h"

//#define NUMBER_SAVED_VEHICLE    3
//#define INTFLASH_VALID  0xAA5555AA

//typedef enum __enumSectorOrder
//{
//    eSECTOR_ODER_None   =   0,
//    
//    eSECTOR_ODER_1      =   1,
//    eSECTOR_ODER_2      =   2,
//    eSECTOR_ODER_3      =   3,
//    
//    eSECTOR_ODER_MAX    = 0xFF
//}enumSectorOrder;

//typedef struct __structFeeBuffHandler        
//{
//    enumbool    blVinProfileSaved;
//    enumbool    blPcmBuffSaved;
//    enumbool    blEcmBuffSaved;
//    enumbool    blTcmBuffSaved;
//    enumbool    blEnhBuffSaved;
//    enumbool    blAbsBuffSaved;
//    enumbool    blSrsBuffSaved;
//    enumbool    blOBD1BuffSaved;
//    enumbool    blSpecTestBuffSaved;
//    enumbool    blLiveDataBuffSaved;
//    /*add new buff to save here*/
//    
//    enumbool    blVehBlockValidSaved;
//}structFeeBuffHandler;

/*==============================================================================
                        SYSTEM SETTING
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer       : KhaVo
*Date           : 30 -Aug 2010
                2. Oct0614 Lap Dang modified, get current system setting from memory before erasing
                                to back up and write back after write tool setting
*Function name  : SaveToolSetting
*Description    : Write curent SystemSetting, ToolSetting to internal flash
*Note           : For LM MCU, because of internal flash writing limitation,
*                 so always writing SystemSetting and ToolSetting together.
*Input          : None
*Output         : None
------------------------------------------------------------------------------*/
extern void IntFlashSaveToolSetting(structToolSetting* p_strtToolSetting);
/*------------------------------------------------------------------------------
*Engineer:      KhaVo
*Historical:    1. 10/13/2010
                2. Oct0614 Lap Dang modified, just read setting from flash memory
*Function name: IntFlashLoadToolSetting
*Descrtiption:  Load tool setting from memory, if it is invalid, reset all to default
*Input:         None
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashLoadToolSetting(structToolSetting* p_strtToolSetting);
/*------------------------------------------------------------------------------
*Engineer:      KhaVo
*Historical:    1. 10/13/2010
                2. 10/10/2014 Lap Dang rename function to IntFlashClearToolSetting
*Function name: IntFlashClearToolSetting
*Descrtiption:  Load SystemSetting from internal flash, if flash value is invalid
*               clear all data to default value.
*Input:         p_strtSystemSetting: Ram systemsetting structure
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashClearToolSetting(structToolSetting* p_strtToolSetting);


/*==============================================================================
                        SYSTEM SETTING
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer:      KhaVo
*Historical:    1. 10/13/2010
*Function name: IntFlashSaveSystemSetting
*Descrtiption:  Load SystemSetting from internal flash, if flash value is invalid
*               clear all data to default value.
*Input:         p_strtSystemSetting: Ram systemsetting structure
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashSaveSystemSetting(structSystemSetting *p_strtSystemSetting);
/*------------------------------------------------------------------------------
*Engineer:      KhaVo
*Historical:    1. 10/13/2010
                2. 10/10/2014 Lap Dang rename function to IntFlashLoadSystemSetting
*Function name: IntFlashLoadSystemSetting
*Descrtiption:  Load SystemSetting from internal flash, if flash value is invalid
*               clear all data to default value.
*Input:         p_strtSystemSetting: Ram systemsetting structure
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashLoadSystemSetting(structSystemSetting *p_strtSystemSetting);
/*------------------------------------------------------------------------------
*Engineer:      KhaVo
*Historical:    1. 10/13/2010
*Function name: IntFlashClearSystemSetting
*Descrtiption:  Load SystemSetting from internal flash, if flash value is invalid
*               clear all data to default value.
*Input:         p_strtSystemSetting: Ram systemsetting structure
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashClearSystemSetting(structSystemSetting *p_strtSystemSetting);


//Oct072014 Lap Dang added more functions
/*------------------------------------------------------------------------------
*Engineer:      Lap Dangruong
*Historical:    1. 10/11/14
*Function name: IntFlashReadFirmwareVersion
*Descrtiption:  Read firmware version and write to dest buff
*               
*Input:         uint8* p_strFirmVer: pointer to dest buff to write firmware
                   version to
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashReadFirmwareVersion(uint8* p_strFirmVer);
/*------------------------------------------------------------------------------
*Engineer:      Lap Dangruong
*Historical:    1. 10/11/14
*Function name: IntFlashReadBootLoaderVersion
*Descrtiption:  Read boot loader version and write to dest buff
*               
*Input:         uint8* p_strFirmVer: pointer to dest buff to write firmware
                   version to
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashReadBootLoaderVersion(uint8* p_strBootVer);
/*------------------------------------------------------------------------------
*Engineer:      Lap Dangruong
*Historical:    1. 10/11/14
*Function name: IntFlashReadBufferFormat
*Descrtiption:  Read buffer format and write to dest buff
*               
*Input:         uint8* p_strFirmVer: pointer to dest buff to write firmware
                   version to
*Output:        None
------------------------------------------------------------------------------*/
extern void IntFlashReadBufferFormat(uint8* p_strBuffFormat);
#endif