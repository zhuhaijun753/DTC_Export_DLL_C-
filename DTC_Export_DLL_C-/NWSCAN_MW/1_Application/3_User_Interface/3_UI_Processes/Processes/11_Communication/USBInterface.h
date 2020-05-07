/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __USBINTERFACE_H__
#define __USBINTERFACE_H__

#include    "InnovaCommonEnum.h"
#include "2_Middle\5_Communication\1_Usb\2_Core\Libraries\STM32_USB_Device_Library\Class\hid\inc\usbd_hid_core.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define	MASK_BYTE_0	0x000000FF
#define	MASK_BYTE_1	0x0000FF00
#define	MASK_BYTE_2	0x00FF0000
#define	MASK_BYTE_3	0xFF000000

#define SHIFT_1_BYTE    8
#define SHIFT_2_BYTE    16
#define SHIFT_3_BYTE    24

#define MAX_RAW_BUFF_SIZE   4096//2048
#define ONE_LD_FRAME_SIZE   512 /*max is just 1 Kbytes because we use iFlashBuffer in structHidOutData to transfer data*/
#define	ONE_LD_FRAME_DATA_SIZE (ONE_LD_FRAME_SIZE - 2)


//Oct0614 Lap Dang moved this struct declare to here
#pragma pack(1)
typedef struct _structUsbString
{
    const uint8* strManufacture;
    const uint8* strProduct;
    const uint8* strSerial;
    const uint8* strConfiguration;
    const uint8* strInterface1;
    const uint8* strInterface2;
    const uint8* p_bMscInquiryData;
}structUsbString;
#pragma pack()

/*march1713 Lap Dang added*/
/*1 byte enum*/
typedef enum _enumValidBuff
{	
	eBUFF_INVALID		= 0x00,
	eBUFF_VALID			= 0xAA,
	/*insert more here*/

}enumValidBuff;

/*2 byte enum*/
typedef enum _enumTransferStatus
{	
	eSTATUS_NOT_START		= 0x00,
	eSTATUS_TRANSFERING		= 0xBB,
	eSTATUS_COMPLETED		= 0xAA,
	/*insert more here*/

}enumTransferStatus;
/*structure for USB Command*/
typedef enum	__enumReadLDDataType
{
	eTYPE_NONE				=	0x00,
	eTYPE_ITEM_NAME_STRING	=	0x01,
	eTYPE_ITEM_UNIT_STRING	=	0x02,
	eTYPE_ITEM_VALUE_STRING	=	0x03,
	eTYPE_RECORD_TIME_VALUE	=	0x04,
	/*insert more here*/
	
}enumReadLDDataType;

typedef enum	__enumReadLDLanguage
{
	eUSB_LANGUAGE_ENGLISH			=	0x00,
	eUSB_LANGUAGE_SPANISH			=	0x01,
	eUSB_LANGUAGE_FRENCH			=	0x02,
	eUSB_LANGUAGE_CHINESE			=	0x03,
	eUSB_LANGUAGE_JAPANESE			=	0x04,
	eUSB_LANGUAGE_VIETNAM			=	0x05,
	/*insert more here*/
	
}enumReadLDLanguage;
typedef enum	__enumReadLDMeasuretSystem
{
	eUSB_UNIT_METRIC			=	0x00,
	eUSB_UNIT_USA				=	0x01,
	/*insert more here*/
	
}enumReadLDMeasuretSystem;
//typedef enum	_enumRecordTriggerMode
//{
//	eTRIGGER_MODE_NONE		= 0x00,
//	eTRIGGER_MODE_DTC		= 0x01,
//	eTRIGGER_MODE_MANUAL		= 0x02,
//
//	
//}enumRecordTriggerMode;
//typedef enum	_enumRecordTriggerTypeNew
//{
//	eTRIGGER_TYPE_NONE		= 0x00,
//	eTRIGGER_TYPE_BEGINNING	= 0x01,
//	eTRIGGER_TYPE_MIDDLE	= 0x02,
//	eTRIGGER_TYPE_END		= 0x03,
//
//	
//}enumRecordTriggerTypeNew;

//August2214 Lap Dang added
typedef enum _enumReadWrite
{
    eRW_READ    = 0,
    eRW_WRITE   = 1,
}enumReadWrite;

typedef enum __enumFeatureSetupType
{
    eFEATURESETUP_NONE                  = 0,
    
    eFEATURESETUP_FIXASSIST             = 1,
    eFEATURESETUP_OBD1                  = 2,
    
    eFEATURESETUP_OBD2_LD               = 3,
    eFEATURESETUP_OBD2_SPECIAL_TEST     = 4,
    
    eFEATURESETUP_ABS                   = 5,
    eFEATURESETUP_SRS                   = 6,
    eFEATURESETUP_ENHANCE               = 7,
    
    eFEATURESETUP_BATTERY_RESET         = 8,
    eFEATURESETUP_ABS_LIVE_DATA         = 9,
    //August2614 Lap Dang added
    eFEATURESETUP_CUSTOM_ID             = 10,
    eFEATURESETUP_USB_MASS_STORAGE      = 11,
    
    //September1714 Lap Dang added for Oil Light Reset
    eFEATURESETUP_OIL_LIGHT_RESET       = 12,
    
    //INSERT NEW HERE
    
    
    
    
    
    eFEATURESETUP_MAX    = 0xFF,
    
}enumFeatureSetupType;



typedef enum
{
    UsbReadDataBuffer1            = 0 ,  // read ecu1 data (strDataBuffer)
    UsbReadDataBuffer2            = 1 ,  // read ecu2 data (strDataBuffer)
    UsbReadEnhancedBuffer1        = 2 ,  // read ecu1 enhanced data (strEnhanceData)
    UsbReadEnhancedBuffer2        = 3 ,  // read ecu2 enhanced data (strEnhanceData)
    UsbReadSystemInfo             = 4 ,  // read strSystemInfo

    UsbJumpBootloader             = 5 ,  //UsbReset               // clear version bytes->jump to bootloader
    UsbReadMemory                 = 6 ,  // read memory contents
    UsbWriteMemory                = 7 ,   // write memory contents
    UsbReadFlash                  = 8 ,  // read serial flash contents
    UsbWriteFlash                 = 9 ,   // write serial flash contents

    UsbReadGuid                   = 10 ,
    UsbReadVin                    = 11 ,
    UsbReadKioskToolId            = 12 ,
    UsbReadManufacturer           = 13 ,
    UsbReadPhoneNumber            = 14 ,

    UsbWriteGuid                  = 15 ,  // write guid (16 bytes data), only for 5000Tool
    UsbWriteVin                   = 16 ,  // write vin (17 bytes data)
    UsbWriteKioskToolId           = 17 ,   // write index of string descriptor byte (1 byte)
    UsbWriteManufacturer          = 18 ,  // (1 byte)
    UsbWritePhoneNumber           = 19 ,  // (16 bytes)

    UsbWriteMonitors              = 20 ,  // write monitors (4 bytes data), only for 5000Tool
    UsbWriteStoredDtc             = 21 ,  // write stored dtcs (up to 48 bytes data), only for 5000Tool
    UsbWritePendingDtc            = 22 ,  // write pending dtcs (up to 48 bytes data), only for 5000Tool
    UsbWriteFreezeDtc             = 23 ,  // write freezeframe dtc (2 bytes data), only for 5000Tool
    UsbEndTransfer                = 24 ,   // exit usb upgrade loop

    UsbWriteAbsSetup              = 25 ,
    UsbWriteSrsSetup              = 26 ,
    UsbWriteLedStatus             = 27 ,
    UsbReadSystemSetting          = 28 ,
    UsbReadService9Vin            = 29 ,

    UsbSoftReset                  = 30 ,  // reset the tool same as recycling power
    UsbClearService1To9           = 31 ,   // clear data on the tool when checking in, clear Service 1,2,3,7,9 and ABS, SRS
    UsbCheckInComplete            = 32 ,   // Hung Phan Dec 1708 add new command to clear internal flash after checking in Kiosk complete
    UsbReadAbsBuffer              = 33 ,
    UsbReadSrsBuffer              = 34 ,

    UsbReadRecordedLiveData       = 35 ,  // read live data (strLiveDataBuffer)
    UsbReadRecordTime             = 36 ,  //read record time of live data
    UsbReadCommand                = 37 ,  /* only for 5000Tool*/
    UsbWriteCommand               = 38 ,  /* only for 5000Tool*/
    UsbCheckValidCustomer         = 39 ,

    ChangeCustomerID              = 40 ,
    UsbReadSpecialTestData        = 41 ,  // Hung Phan Nov 24 2009 add Command to read Special Test Data
    DataloggerCommand             = 42 ,  //Hungv added 04 Dec 2009
    UsbUpgradeFirmware            = 43 ,   //Khav: used for EST tools only
    UsbUpgradeBootLoader          = 44 ,  /* only for EST Tool*/

    UsbWriteOBD1Setup             = 45 ,  // HungPhan Mar182010, setup OBD1 function from software
    UsbWriteLiveDataSetup         = 46 ,  // HungPhan Mar252010, setup LiveData function from software
    UsbWriteEnhancedDTCSetup      = 47 ,  // HungPhan Mar252010, setup Enhanced function from software
    UsbWriteSpecialTestSetup      = 48 ,  // HungPhan Mar252010, setup SpecialTest function from software
    UsbClearABS                   = 49 ,  // Hung Phan Jun212010, Clear last saved ABS except ABSValidStatus

    UsbClearSRS                   = 50 ,  // Hung Phan Jun212010, Clear last saved SRS data except SRSValidStatus
    UsbClearEnhanced              = 51 ,  // Hung Phan Jun212010, Clear last saved Enhanced data except EnhancedValidStatus
    UsbClearLiveData              = 52 ,  // Hung Phan Jun212010, Clear last saved LIve Data except LiveValidStatus
    UsbClearSpecialTestData       = 53 ,  // Hung Phan Jun212010, Clear last saved Special Test data except SpecialtestValidStatus and Sync byte
    SelfTestWriteVehicleInfo      = 54 ,  // Hung Phan Nov 192010, PC sends Vehicle Information for selftest on definition and fix code

    SeftTestWriteDTC              = 55 ,  // Hung Phan Nov 192010, PC sends PCM,TCM,ABS,SRS,Enhanced DTC for selftest on definition and fix code
    SeftTestReadDef_Fixcode       = 56 ,  // Hung Phan Nov 192010, Tool sends PCM,TCM,ABS,SRS,Enhanced DTC definition and fix code
    UsbClearSystemSetting         = 57 ,  // KhaVo, HungP Dec 14 2010: Clear System setting
    UsbClearToolSetting           = 58 ,  // KhaVo, HungP Dec 14 2010: Clear Tool setting
    UsbClearAllSetting_VehicleData= 59 ,  // KhaVo, HungP Dec 14 2010: Clear all Buffers(DataBufers, ABS, SRS, Enhanced, Livedata, Specialtest)  + Tool setting + System setting

    UsbReadToolSetting            = 60 ,  // Hung Phan Jan 13 2011, command for reading Tool Setting: read ABS setup, SRS setup, Enhanced setup, Live Data setup, OBD1 setup, Special Test setup
    SelfTestGetDef_Fix            = 61 ,  // Hung Phan Mar232011, PC send VehilceInfo (follow struct), 1 DTC code, and type ( Definition or Fix) then tool send definition or fix in 3 languages to PC
    SelfTestDecodeVIN             = 62 ,  // Hung Phan Mar232011, PC sends string has VIN (17 char) then tool sends vehicle info ( follow struct) after decode
    UsbReadEcmBuffer              = 63 ,  //Hung Vo Added 17 May 2011
    UsbReadTcmBuffer              = 64 ,

    UsbSDDeleteFolder             = 65 ,  // SD card upgrade
    UsbSDCreateFolder             = 66 ,  // SD card upgrade
    UsbSDDeleteFile               = 67 ,  // SD card upgrade
    UsbSDCreateFile               = 68 ,  // SD card upgrade
    UsbSDReplaceFolder            = 69 ,  // SD card upgrade
    UsbSDReplaceFile              = 70 ,  // SD card upgrade
    UsbSDReadFile                 = 71 ,  // SD card upgrade  // Hung Phan added Jul182011
    UsbSDResponseStatus           = 72 ,  // SD card upgrade  // Hung Phan added Jul182011
    UsbRead0BD1                   = 73 ,
    UsbUpgradeAutoLaunchImg       = 74 ,  // Upgrade Auto Launch Image into SD card, External Flash or Internal Flash // Update V01.00.41

    UsbReadAutoLaunchVersion      = 75 ,  // Read Auto Launch Version // Update V01.00.41
    UsbReadVehicleInfo            = 76 ,  // Read Vehicle Info in tool // Update V01.00.41
    UsbReadVehicleAPIVersion      = 77 ,  // Read Vehicle Interface API version // Update V01.00.41
    UsbReadUIAPIVersion           = 78 ,  // Read User Interface API Vesrion // Update V01.00.41
    UsbReadDatabaseSec2Version    = 79 ,  // Read Database section 2 ( Live Data Database or something else) // Update V01.00.41

    UsbUpgradeDatabaseSec1        = 80 ,  // Upgrade Database section 2 // Update V01.00.41
    UsbUpgradeDatabaseSec2        = 81 ,  // Upgrade Database section 2 // Update V01.00.41

    //UsbFlashEraseBlock            = 82,
    UsbReadDatabaseSec1Version      = 82,
    UsbUpgradeFontDatabase          = 83,
    UsbReadFontDatabaseVersion      = 84,
                                                
    UsbReadOBD2LDSupItemList	=	85	,			// read OBD2 Custome Live Data support list				
    // Please insert new command here
    UsbReadExtensibleDataController = 86,			// read oem buffer handler					
    UsbReadControllerBuffer         = 87,		// read oem buffer, include with parameter is controller name					
    
    /*April1613 Lap Dang added for new read OEM LD*/
    ReadOEMLiveDataHeader           =   88,    // Please insert new command here

    UsbEraseWholeDatabaseChip	=	89	,// Erase whole external flash chip // V01.00.72				
    
    UsbFlashWholeDatabaseChip	=	90	,// Flash whole database chip // V01.00.72			
    
    UsbReadROMVersion	=	91,		// read ROM version // V01.00.76			
    UsbUpgradeROM	=	92	,	// upgrade ROM section // V01.00.76			
    
    UsbFATFSFormat = 93,/*Dec0213 Lap Dang added as An suggested*/
    UsbVINSelfTest	=	94	,/*HungP*/
    UsbDTCdefinitionSelfTest	=	95	,/*HungP*/

    UsbPrepareVehicleData   =   96,/*Jan0714 Lap Dang added for preparing vehicle data before transfer, 3130e need send 3 latest vehicle data to PC*/
    UsbMassStorageEnDis     = 97,/*March1914 V27a Lap Dang added for Enable/Disable USB Mass Storage Mode*/
    
    UsbATEHID   = 98,//Aug1914 Lap Dang added for ATE as Hung Vo
    
    UsbToolFeatureSetup	=	99	,	// Setup (Read/ Write) ABS, SRS, Enhanced, Battery Reset, ABS Live Data, Fix Assist (replace for command #25,26,33,34, 45,46,47,48 // V01.00.86

    UsbReadTestData               = 0xFF
}eUSBCommand;



/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
//Usb core handler, used in initialization
extern USB_OTG_CORE_HANDLE           USB_OTG_dev;
//Usb mass storage mode - used to set enable/disable mass storage of tool
extern enumUsbStorageMode eUsbMassStorageMode;

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 07, 2011
*Function name: UsbProductInit
*Descrtiption :
*Input        : uint16 wProductID
*             : structUsbString* p_strtUsbString
*Output       :
*-----------------------------------------------------------------------------*/
void UsbProductInit(uint16 wProductID, const structUsbString* p_strtUsbString);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014

*Function name: USBProcessData
*Descrtiption : process all transfering data between tool and host via USB
*Input        : structUSBData *p_strtUSBData
*Output       : none
*-----------------------------------------------------------------------------*/
void USBProcessData(structUSBData *p_strtUSBData);

#endif
