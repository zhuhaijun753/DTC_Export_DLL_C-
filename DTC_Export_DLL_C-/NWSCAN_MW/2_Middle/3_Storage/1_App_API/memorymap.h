/******************************************************************************
===============================================================================
Lap Dang Dev
Filename: MemoryMap.h
Description: Internal, external flash layout
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __MEMORYMAP_H__
#define __MEMORYMAP_H__

//#include <hwdrivers\exflash\ExFlashInterface.h>

/*Apply for Vehicle Data only*/
#define USING_INTERNAL_FLASH        0
#define USING_EEPROM                1
#define USING_EXTERNAL_FLASH        2
#define USING_OTP_FLASH             3
#define USING_MEMORY_NONE           4
#define USING_FILE_SYSTEM           5
#define USING_AUTO_DETECT           6

#define TOOL_SETTING_LOCATION       USING_INTERNAL_FLASH
#define SYSTEM_SETTING_LOCATION     USING_INTERNAL_FLASH


#if (_EXTERNAL_FLASH)
#define SPECIAL_TEST_LOCATION       USING_EXTERNAL_FLASH
#define LIVE_DATA_LOCATION          USING_EXTERNAL_FLASH
#define VEHICLE_DATA_LOCATION       USING_EXTERNAL_FLASH
#else
#define SPECIAL_TEST_LOCATION       USING_FILE_SYSTEM
#define LIVE_DATA_LOCATION          USING_FILE_SYSTEM
/* May 26, 2014 - CuongHL changed for defining in workspace */
#ifdef _INFLASH_VEHICLE_DATA
	#define VEHICLE_DATA_LOCATION       USING_INTERNAL_FLASH
#else
	#define VEHICLE_DATA_LOCATION       USING_FILE_SYSTEM
#endif
#endif

#define FLASH_BASE_ADDR              (0x08000000)
#define BL_VERSION_FLASH_SIZE        (0x10)
#define BL_START_ADDR                (0x08000000)    //Bootloader Start Address in ROM

#define BL_END_ADDR                  (0x0800BFFF)

#define BL_VERSION_ADDR              (BL_END_ADDR - BL_VERSION_FLASH_SIZE + 1)   //Bootloader Version Address in ROM


#define FW_VERSION_FLASH_SIZE        (0x10)

#define FW_START_ADDR                (0x08010000)


#define FW_VERSION_ADDR              (FW_END_ADDR - FW_VERSION_FLASH_SIZE + 1)   //Bootloader Version Address in ROM

#define DB_VERSION_FLASH_SIZE        8

#define BUFFER_FORMAT_SIZE           4
#define BUFFER_FORMAT_ADDR           (FW_VERSION_ADDR - BUFFER_FORMAT_SIZE)



/************* Vehicle Data region*********************************************/
#if (TOOL_SETTING_LOCATION == USING_EEPROM)
    #define TOOL_SETTING_PAGE            0
    #define TOOL_SETTING_ADDR            (TOOL_SETTING_PAGE * MEMORY_PAGE_SIZE_BYTE)

#elif (TOOL_SETTING_LOCATION == USING_INTERNAL_FLASH)
    #define TOOL_SETTING_SECTOR          (FLASH_Sector_3)
    #define TOOL_SETTING_ADDR            (0x0800C000) /*start at begin of sector 3*/


#elif (TOOL_SETTING_LOCATION == USING_OTP_FLASH)
    #define TOOL_SETTING_ADDR            (0x1FFF7800) /*OTP Block 0*/

#elif (TOOL_SETTING_LOCATION == USING_MEMORY_NONE)
//    #warning Dont save tool setting

#else
    #error Location for tool setting is not valid.
#endif

#if (SYSTEM_SETTING_LOCATION == USING_EEPROM)
    #define SYSTEM_SETTING_PAGE          1
    #define SYSTEM_SETTING_ADDR          (SYSTEM_SETTING_PAGE * MEMORY_PAGE_SIZE_BYTE)

#elif (SYSTEM_SETTING_LOCATION == USING_INTERNAL_FLASH)
#define SYSTEM_SETTING_SECTOR          (FLASH_Sector_3)
#define SYSTEM_SETTING_ADDR            (0x0800C400) /*start at begin of Sector 3 + 1Kb*/



#elif (TOOL_SETTING_LOCATION == USING_OTP_FLASH)
    #define SYSTEM_SETTING_ADDR            (0x1FFF7840) /*OTP Block 2*/

#elif (TOOL_SETTING_LOCATION == USING_MEMORY_NONE)
//    #warning Dont save system setting
#else
    #error Location for system setting is not valid.
#endif


#if (VEHICLE_DATA_LOCATION == USING_EEPROM)
    #define MemoryRead          EEPROM_Read
    #define MemoryWrite         EEPROM_Write
    #define MemoryErasePage     EEPROM_ErasePage

    #define MEMORY_PAGE_SIZE_BYTE        EEPRROM_PAGE_SIZE
    #define MEMORY_SECTOR_SIZE_PAGE      1

    #define VEHICLE_DATA_START_PAGE      2
    #define VEHICLE_DATA_END_PAGE        232
    #define VEHICLE_DATA_NUM_BLOCK       8
    #define VEHICLE_DATA_NUMBER_PAGE     (VEHICLE_DATA_END_PAGE - VEHICLE_DATA_START_PAGE + 1)
    #define VEHICLE_DATA_START_ADDR      (VEHICLE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

    #define SPECIAL_TEST_START_PAGE      233
    #define SPECIAL_TEST_END_PAGE        264
    #define SPECIAL_TEST_START_ADDR      (SPECIAL_TEST_START_PAGE * MEMORY_PAGE_SIZE_BYTE)
    #define SPECIAL_TEST_NUM_BLOCK       4
    #define SPECIAL_TEST_PAGE_PER_BLOCK  (1024 / MEMORY_PAGE_SIZE_BYTE)

    #define LIVE_DATA_START_PAGE            265
    #define LIVE_DATA_END_PAGE              402
    #define LIVE_DATA_START_ADDR            (LIVE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)
    #define LIVE_DATA_NUM_BLOCK             1
    #define LIVE_DATA_PAGE_PER_BLOCK        140
#endif

//Start: define memory areas follow datamemorylayout V.01.00.05
#if (VEHICLE_DATA_LOCATION == USING_EXTERNAL_FLASH)
    #define MemoryRead              ExFlashRead
    #define MemoryWrite             fExFlashWrite
    #define MemoryEraseBlock4kb     ExFlash4kbErase
    #define MemoryEraseBlock64kb    ExFlashBlockErase   //this function use to erase 64kb in external flash

    #define MEMORY_PAGE_SIZE_BYTE        FLASH_PAGE_SIZE
    #define MEMORY_SECTOR_SIZE_PAGE      (0x1000 / MEMORY_PAGE_SIZE_BYTE)   /*number page in a eraseable region*/
    #define SIZE_VEHICLE_DATA_BLOCK      0x1000
    #define SIZE_OF_RESERVED_FOR_OEM_DTC (SIZE_VEHICLE_DATA_BLOCK-sizeof(structDataBuffer)-sizeof(structDataBuffer)-sizeof(structPcmBuffer)-sizeof(structPcmBuffer)-sizeof(structEnhancedBuffer)-sizeof(structEnhancedBuffer)-sizeof(structControllerBuffer)-sizeof(structControllerBuffer)-sizeof(strtVinProfile)-sizeof(structPcmBuffer))
    /* 2xPCM 2x1K,ECM 256, TCM 256, 2xEnh 2x256,ABS 256, SRS 256, , Vehicle Info 64, OBDI 256 */

    #ifdef OBD3130E

        #define VEHICLE_DATA_START_PAGE      0//65280//32512
        #define VEHICLE_DATA_END_PAGE        127//65407//32639
        #define VEHICLE_DATA_NUM_BLOCK       8
        #define VEHICLE_DATA_NUMBER_PAGE     (VEHICLE_DATA_END_PAGE - VEHICLE_DATA_START_PAGE + 1)
        #define VEHICLE_DATA_START_ADDR      (VEHICLE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

        #define SPECIAL_TEST_START_PAGE      128//65408//32640
        #define SPECIAL_TEST_END_PAGE        159//65439//32671
        #define SPECIAL_TEST_START_ADDR      (SPECIAL_TEST_START_PAGE * MEMORY_PAGE_SIZE_BYTE)
        #define SPECIAL_TEST_NUM_BLOCK       2
        #define SPECIAL_TEST_PAGE_PER_BLOCK  (4096 / MEMORY_PAGE_SIZE_BYTE)

        #define LIVE_DATA_START_PAGE         160//65440//32672
        #define LIVE_DATA_END_PAGE           239//65519//32751
        #define LIVE_DATA_START_ADDR         (LIVE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

        #define BLUETOOTH_REGION_START_PAGE         240//65520
        #define BLUETOOTH_REGION_END_PAGE           255//65535
        #define BLUETOOTH_REGION_START_ADDR         (BLUETOOTH_REGION_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

    #else

        #define VEHICLE_DATA_START_PAGE      65280//32512
        #define VEHICLE_DATA_END_PAGE        65407//32639
        #define VEHICLE_DATA_NUM_BLOCK       8
        #define VEHICLE_DATA_NUMBER_PAGE     (VEHICLE_DATA_END_PAGE - VEHICLE_DATA_START_PAGE + 1)
        #define VEHICLE_DATA_START_ADDR      (VEHICLE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

        #define SPECIAL_TEST_START_PAGE      65408//32640
        #define SPECIAL_TEST_END_PAGE        65439//32671
        #define SPECIAL_TEST_START_ADDR      (SPECIAL_TEST_START_PAGE * MEMORY_PAGE_SIZE_BYTE)
        #define SPECIAL_TEST_NUM_BLOCK       2
        #define SPECIAL_TEST_PAGE_PER_BLOCK  (4096 / MEMORY_PAGE_SIZE_BYTE)

        #define LIVE_DATA_START_PAGE         65440//32672
        #define LIVE_DATA_END_PAGE           65519//32751
        #define LIVE_DATA_START_ADDR         (LIVE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

        #define BLUETOOTH_REGION_START_PAGE         65520
        #define BLUETOOTH_REGION_END_PAGE           65535
        #define BLUETOOTH_REGION_START_ADDR         (BLUETOOTH_REGION_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

    #endif

    #define ISO_IMAGE_REGION_SIZE               (8*64*1024) /*512Kb*/
    #define ISO_IMAGE_NUMBER_BLOCK              (ISO_IMAGE_REGION_SIZE / FLASH_64K_BLOCK_SIZE)
    #define ISO_IMAGE_REGION_START_ADDR         (0x760000)
    #define ISO_IMAGE_REGION_END_ADDR           (ISO_IMAGE_REGION_START_ADDR + ISO_IMAGE_REGION_SIZE - 1)
    #define ISO_VERSION_ADDR_PTR_ADDR           ISO_IMAGE_REGION_START_ADDR
    #define ISO_VERION_ADDR_PTR_SIZE            4
    #define ISO_IMAGE_START_ADDR                (ISO_IMAGE_REGION_START_ADDR + ISO_VERION_ADDR_PTR_SIZE)
    #define ISO_IMAGE_VERSION_SIZE              16

#endif

#if (VEHICLE_DATA_LOCATION == USING_FILE_SYSTEM)
    #define VEHICLE_DATA_NUM_BLOCK      10
    #define MAX_VEHICLE_DATA_FNAME  50

    #define VEHICLE_PATH_FMT    "/VehData/Veh%d"
    #define PCM_FILE_FMT        "/VehData/Veh%d/Pcm.bin"
    #define ECM_FILE_FMT        "/VehData/Veh%d/Ecm.bin"
    #define TCM_FILE_FMT        "/VehData/Veh%d/Tcm.bin"
    #define ENH_FILE_FMT        "/VehData/Veh%d/Enh.bin"
    #define ABS_FILE_FMT        "/VehData/Veh%d/Abs.bin"
    #define SRS_FILE_FMT        "/VehData/Veh%d/Srs.bin"
    #define VIN_FILE_FMT        "/VehData/Veh%d/VinProf.bin"
    #define OBD1_FILE_FMT       "/VehData/Veh%d/Obd1.bin"
    #define LD_FILE_FMT         "/VehData/Veh%d/Livedata.bin"
    #define SP_FILE_FMT         "/VehData/Veh%d/Sid6.bin"
    #define VEHICLE_DATA_PATH   "/VehData"

    /*Define for Bluetooth*/
    #define BLUETOOTH_PATH          "/VehData/Bluetooth"
    #define BT_CONFIG_STATUS_PATH   "/VehData/Bluetooth/BTConfigStatus.bin"
    #define BT_DEVICE_DATA_PATH     "/VehData/Bluetooth/BTDeviceData.bin"
#endif


#if (VEHICLE_DATA_LOCATION == USING_INTERNAL_FLASH)
        
    #define VEHICLE_DATA_SECTOR_1_ADDR  ADDR_FLASH_SECTOR_21
    #define VEHICLE_DATA_SECTOR_2_ADDR  ADDR_FLASH_SECTOR_22
    #define VEHICLE_DATA_SECTOR_3_ADDR  ADDR_FLASH_SECTOR_23
    
    #define SIZEOF_1KB 1024
    #define SIZEOF_SECTOR   128*SIZEOF_1KB
    #define VEHICLE_DATA_SIZE   25*SIZEOF_1KB
    #define VEHICLE_DATA_NUM_BLOCK_1_SECTOR     5//SIZEOF_SECTOR/VEHICLE_DATA_SIZE

    #define VEHICLE_DATA_START_PAGE      65280
    #define VEHICLE_DATA_END_PAGE        65407
    #define VEHICLE_DATA_NUM_BLOCK       8
    #define VEHICLE_DATA_NUMBER_PAGE     (VEHICLE_DATA_END_PAGE - VEHICLE_DATA_START_PAGE + 1)
    #define VEHICLE_DATA_START_ADDR      (VEHICLE_DATA_START_PAGE * MEMORY_PAGE_SIZE_BYTE)

    #define FW_END_ADDR                  (0x0819FFFF)//end of sector 20

#endif

/*
================================================================================
CONSTANTS
================================================================================
*/


#endif
