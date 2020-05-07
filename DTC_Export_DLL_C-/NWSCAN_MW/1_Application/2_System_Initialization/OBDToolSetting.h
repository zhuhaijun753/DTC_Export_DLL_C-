/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __OBD_TOOL_SETTING_H__
#define __OBD_TOOL_SETTING_H__

#include    "ExFlashInterface.h"
#include    "ToolSetting_Interface_Enum.h"
#include    "USBInterface.h"

#include    "enums.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/

typedef enum
{
    ABSSRS_DISABLE = 0xA1,
    ABSSRS_DOMESTIC = 0xA2,
    ABSSRS_ASIAN  = 0xA3,
    ABSSRS_EUROPE = 0xA4,
    ABSSRS_ALL  =0xA5
}eControllerSupport;

//typedef enum
//{
//    LiveData_Disable = 0x00,
//    ViewLiveDataOnly = 0xA1,
//    ViewnGraphingLiveData = 0xA2 ,
//    ViewnGraphingnRecordLiveData = 0xA3
//} e_LiveDataFunctionList;

typedef enum
{
    UNIT_USA,
    UNIT_METRIC
} enumUnit;

//typedef enum _EXFLASH
//{
//  EXFLASH_AT45DB321D,   // 32Mbit
//  EXFLASH_AT45DB161D,   // 16Mbit
//  EXFLASH_AT45DB642D,
//  EXFLASH_M25PX32,      //32 Mbit
//  EXFLASH_M25PX64,      //64 Mbit
//  EXFLASH_SST25VF032B,
//  EXFLASH_SST25VF064C,
//  EXFLASH_W25Q32BV,
//  EXFLASH_W25Q64BV,
//  EXFLASH_S25FL32P,
//  EXFLASH_S25FL64P,
//  EXFLASH_S25FL128S,
//  EXFLASH_SST25VF080B,
//  EXFLASH_NONE = 0xFF
//} enumExFlashType;


//typedef struct _structVehicleFeatureSetting
//{
//    union
//    {
//        uint8 VehSetup[23];
//        struct
//        {
//            enumbool Kia_Setup:1;
//            enumbool Hyundai_Setup:1;
//            enumbool Nissan_Setup:1;
//            enumbool Toyota_Setup:1;
//            enumbool Honda_Setup:1;
//            enumbool Chrysler_Setup:1;
//            enumbool Ford_Setup:1;
//            enumbool GM_Setup:1;
//
//            enumbool Deawoo_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool ChevyAuto_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool BYD_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Mercedes_Setup:1;
//            enumbool Audi_Setup:1;
//            enumbool Volkswagen_Setup:1;
//            enumbool Mini_Setup:1;
//            enumbool BMW_Setup:1;
//
//            enumbool Daihatsu_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Fiat_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Isuzu_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool LandRover_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Lifan_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Mitsubishi_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Porsche_Setup:1;//August1814 Lap Dang added as R&D 85
//            enumbool Ssangyong_Setup:1;//August1814 Lap Dang added as R&D 85
//            
//            //bit 0 --> bit 7
//            enumbool Reserve13_Setup:1;
//            enumbool Reserve14_Setup:1;
//            enumbool Reserve15_Setup:1;
//            enumbool Mazda_Setup:1;//August1814 Lap Dang added Mazda as new
//            enumbool Jaguar_Setup:1;//August1814 Lap Dang added Jaguar as new
//            enumbool Sabb_Setup:1;
//            enumbool Suzuki_Setup:1;
//            enumbool Volvo_Setup:1;
//            
//            enumbool Reserve19_Setup:1;
//            enumbool Reserve20_Setup:1;
//            enumbool Reserve21_Setup:1;
//            enumbool Reserve22_Setup:1;
//            enumbool Reserve23_Setup:1;
//            enumbool Reserve24_Setup:1;
//            enumbool Reserve25_Setup:1;
//            enumbool Reserve26_Setup:1;
//            enumbool Reserve27_Setup:1;
//            enumbool Reserve28_Setup:1;
//            enumbool Reserve29_Setup:1;
//            enumbool Reserve30_Setup:1;
//            enumbool Reserve31_Setup:1;
//            enumbool Reserve32_Setup:1;
//            enumbool Reserve33_Setup:1;
//            enumbool Reserve34_Setup:1;
//            enumbool Reserve35_Setup:1;
//            enumbool Reserve36_Setup:1;
//            enumbool Reserve37_Setup:1;
//            enumbool Reserve38_Setup:1;
//            enumbool Reserve39_Setup:1;
//            enumbool Reserve40_Setup:1;
//            enumbool Reserve41_Setup:1;
//            enumbool Reserve42_Setup:1;
//            enumbool Reserve43_Setup:1;
//            enumbool Reserve44_Setup:1;
//            enumbool Reserve45_Setup:1;
//            enumbool Reserve46_Setup:1;
//            enumbool Reserve47_Setup:1;
//            enumbool Reserve48_Setup:1;
//            enumbool Reserve49_Setup:1;
//            enumbool Reserve50_Setup:1;
//            enumbool Reserve51_Setup:1;
//            enumbool Reserve52_Setup:1;
//            enumbool Reserve53_Setup:1;
//            enumbool Reserve54_Setup:1;
//            enumbool Reserve55_Setup:1;
//            enumbool Reserve56_Setup:1;
//            enumbool Reserve57_Setup:1;
//            enumbool Reserve58_Setup:1;
//            enumbool Reserve59_Setup:1;
//            enumbool Reserve60_Setup:1;
//            enumbool Reserve61_Setup:1;
//            enumbool Reserve62_Setup:1;
//            enumbool Reserve63_Setup:1;
//            enumbool Reserve64_Setup:1;
//            enumbool Reserve65_Setup:1;
//            enumbool Reserve66_Setup:1;
//            enumbool Reserve67_Setup:1;
//            enumbool Reserve68_Setup:1;
//            enumbool Reserve69_Setup:1;
//            enumbool Reserve70_Setup:1;
//            enumbool Reserve71_Setup:1;
//            enumbool Reserve72_Setup:1;
//            enumbool Reserve73_Setup:1;
//            enumbool Reserve74_Setup:1;
//            enumbool Reserve75_Setup:1;
//            enumbool Reserve76_Setup:1;
//            enumbool Reserve77_Setup:1;
//            enumbool Reserve78_Setup:1;
//            enumbool Reserve79_Setup:1;
//            enumbool Reserve80_Setup:1;
//            enumbool Reserve81_Setup:1;
//            enumbool Reserve82_Setup:1;
//            enumbool Reserve83_Setup:1;
//            enumbool Reserve84_Setup:1;
//            enumbool Reserve85_Setup:1;
//            enumbool Reserve86_Setup:1;
//            enumbool Reserve87_Setup:1;
//            enumbool Reserve88_Setup:1;
//            enumbool Reserve89_Setup:1;
//            enumbool Reserve90_Setup:1;
//        };
//    };
//} structVehicleFeatureSetting;
//
//

//
//#define TOOL_SETTING_MAXSIZE    1*1024//currently, we reserved 1KB to save tool setting to internal memory,
//                                      //if want to change this size, need to modified saving ToolSetting and System Setting
//                                        //System Setting is saved following Tool Setting in Internal Flash Memory
//#define TOOL_SETTING_VALID    0xAA
//#define MAX_SIZE_SERIAL_NUMBER  32  //[Len 1Byte][Data 20bytes][status 1byte]
//#pragma pack(1)
//typedef struct _structToolSetting
//{
//    uint8 ToolStatus;
//
//    uint8 Reserverd1;
//    uint8 Reserverd2;
//
//    uint8 CustomerValid;
//    uint8 CustomerID;
//
//    enumUsbStorageMode eStorageMode;/*March1914 V27a Lap Dang declare this for usb mode*/
//    uint8 Reserverd4;
//    uint8 OBD1Setup;
//    e_LiveDataFunctionList LiveDataSetup;
//    uint8 Reserverd5;
//    uint8 SpecialTestSetup;
//    structVehicleFeatureSetting AbsVehSetup;
//    structVehicleFeatureSetting SrsVehSetup;
//    structVehicleFeatureSetting EnhVehSetup;
//    //April1614 V32a Lap Dang added feature functions supported
//    structVehicleFeatureSetting BatteryResetSetup;
//    structVehicleFeatureSetting ABSLiveDataSetup;
//
//    enumbool blFixEnable;//Lap Dang move this field to tool setting for enable from PC
//
//    //_ENABLE_ATE_FUNCTION_//always set this is 1, sync with R&D 86
//    uint8 SerialNumber[MAX_SIZE_SERIAL_NUMBER];
//
//    //September172014 Lap Dang added 1 field for Oil Reset setup
//    structVehicleFeatureSetting OilLightResetDataSetup;
//    
//    //All new parameters must be added from here
//    //Each setting field added need to work with PC via USB command
//    // -->add code in Usb for processing
//    
//    //August2214 Lap Dang added bReserve to set limit tool setting buffer size to 1KB
//    uint8   bReserved[TOOL_SETTING_MAXSIZE - 182];//need modify this if we add more field to the struct
//    
//} structToolSetting;
//#pragma pack()
//
//#define SYSTEM_SETTING_INVALID  0x00
//#define SYSTEM_SETTING_VALID    0xAA
//#define GUID_SIZE               16
//#define PHONE_NUMBER_SIZE       16
//#define VIN_SIZE                17
//#pragma pack(1)
//typedef struct _structSystemSetting
//{
//    uint8 SystemStatus;     // If is not 0xaa, reset all parameters //
//    uint8 LanguageSetting;
//    uint8 BrightnessLevel;
//    uint8 UnitSetting;
//    uint8 BuzzerSetting;    /*Update as R&D 46*/
//    uint8 BacklightSetting; /*Update as R&D 46*/
//    uint8 Guid[GUID_SIZE];  // for carmd and repairsolutions
//    uint8 Vin[VIN_SIZE];
//    uint8 KioskToolId;      // index of string descriptor for kiosk tools
//    uint8 Manufacturer;     // cellematics project
//    union
//    {
//        struct
//        {
//            uint8 PhoneNumber[PHONE_NUMBER_SIZE]; //cellematics project
//        };
//        struct
//        {
//            uint8 FooterSetting;    /*Oct 09, 2013: Hoang Nguyen added*/
//            uint8 BluetoothSetting; /*Oct 09, 2013: Hoang Nguyen added*/
//        };
//    };
//} structSystemSetting;
//#pragma pack()
//
//#pragma pack(1)
///*
//    Feature settings, other settings not in tool setting
//    These things could be set.clear by firmware itseft.
//*/
//typedef struct _structFeatureSetting
//{
//    enumbool blSelectManufFirst;
//    enumbool blSelectManufDTC;
////    enumbool blFixEnable;//Lap Dang move this field to tool setting for enable from PC
//    enumbool blSdCardEnable;
//    enumbool blExFlashEnable;
//    enumbool blSecurityPassed;
//} structFeatureSetting;
//
//typedef struct _structUsbString
//{
//    const uint8* strManufacture;
//    const uint8* strProduct;
//    const uint8* strSerial;
//    const uint8* strConfiguration;
//    const uint8* strInterface1;
//    const uint8* strInterface2;
//    const uint8* p_bMscInquiryData;
//}structUsbString;
//
//typedef struct _structProductSetting
//{
//    uint8   ToolId;
//    uint16  UsbProductId;
//    structToolSetting       strtToolSetting;
//    structFeatureSetting    strtFeatureSetting;
//    structUsbString         strtUsbString;
//} structProductSetting;

//#pragma pack()

#pragma pack(1)
typedef struct _structProductSetting
{
    uint8   ToolId;
    uint16  UsbProductId;
    structToolSetting       strtToolSetting;
    structFeatureSetting    strtFeatureSetting;
    structUsbString         strtUsbString;
} structProductSetting;
#pragma pack()

#define FW_VERSION_SIZE 16
#define BL_VERSION_SIZE 16
#define DB_VERSION_SIZE 16
#define VD_VERSION_SIZE 16
#define FC_VERSION_SIZE 16
#define SD_VERSION_SIZE 16
#define CD_VERRSION_SIZE 16
#define VIN_VERSION_SIZE 16

#pragma pack(1)
typedef struct _structSoftwareInfo
{
    uint8 FirmwareVersion[FW_VERSION_SIZE];
    uint8 BootLoaderVersion[BL_VERSION_SIZE];
    uint8 DTCDefinitionVersion[DB_VERSION_SIZE];//consider this as main version of database
    
    uint8 VehilceDecodeVersion[VD_VERSION_SIZE];
    uint8 FixedCodeVersion [FC_VERSION_SIZE];
    uint8 SDcardVersion [SD_VERSION_SIZE];
    uint8 VINDecodeVersion [VIN_VERSION_SIZE];
    uint32 BufferFormat;
} structSoftwareInfo;
#pragma pack()

#pragma pack(1)
typedef struct _structToolInfo
{
    uint8 ToolId;
    uint8 LedStatus;
    enumExFlashType ExternalFlashType;
} structToolInfo;
#pragma pack()

#pragma pack(1)
typedef struct _structSystemInfo
{
  structSystemSetting strtSystemSetting;
  structSoftwareInfo strtSoftwareInfo;
  structToolInfo  strtToolInfo;
} structSystemInfo;
#pragma pack()

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
extern structToolSetting    g_strtToolSetting;
extern structSystemInfo     g_strtSystemInfo ;
extern structFeatureSetting g_strtFeatureSetting;
extern uint16 g_wProductID;
extern const structProductSetting*   gp_strtProductSetting;
extern uint8 bSDSlotStatus;

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
enumbool IsValidCustomerID(uint8 bCustomID);
const structProductSetting* GetProductSetting(uint8 bToolID);

uint8 GetToolID(void);
enumbool SystemSecurityCheck(void);
void ToolSettingInit(void);
enumbool VehicleFeatureIsEnable(structVehicleFeatureSetting* p_strtFeatureSetup);

//Oct072014 Lap Dang moved these functions to here
void GetSystemInfo(structSystemInfo* p_strtSysInf);



/*==============================================================================
                        TOOL SETTING INFORMATION
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 13 2014
*Function name: IsToolSupportFFHotkey
*Descrtiption : This function is used to check whether tool supports FF hotkey or not

*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
enumbool    IsToolSupportFFHotkey(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SaveToolSetting
*Descrtiption : erase tool setting buffer, load default and save to storage
                currently save into Internal Flash
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void SaveToolSetting(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: ClearToolSetting
*Descrtiption : erase tool setting buffer, load default and save to storage
                currently save into Internal Flash
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ClearToolSetting(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingCustomID_Set
*Descrtiption : set tool ID for tool, then get coressponding setting
                and set valid tool setting buffer
                
*Input        : pointer to data buffer to get value of tool id to write to tool
                    setting buffer
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingCustomID_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingCustomID_Get
*Descrtiption : Get tool ID of tool
                
*Input        : pointer to data buffer to write tool ID value into
*Output       : size of tool ID value
*-----------------------------------------------------------------------------*/
uint32 ToolSettingCustomID_Get(uint8* p_Data);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingUsbMassStorage_Set
*Descrtiption : set mass storage mode of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingUsbMassStorage_Set(uint8 bMassStorageMode);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingUsbMassStorage_Set
*Descrtiption : get mass storage mode of tool
                
*Input        : pointer to data buffer to write mass storage mode of tool into
*Output       : size of mass storage mode value
*-----------------------------------------------------------------------------*/
uint32 ToolSettingUsbMassStorage_Get(uint8* p_Data);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingFixSupport_Set
*Descrtiption : set Fix Assist feature support of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingFixSupport_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingFixSupport_Get
*Descrtiption : set Fix Assist feature support of tool
                
*Input        : pointer to dest data buffer need to get Fix setting and write to
*Output       : size of Fix Assist Value
*-----------------------------------------------------------------------------*/
uint32 ToolSettingFixSupport_Get(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 21 2014
*Function name: ToolSettingFixSupport_IsEnable
*Descrtiption : check to see tool support Fix Assist or not
                
*Input        : None
*Output       : enumbool - status of Fix Assist Support
                    eTRUE - support
                    eFALSE - not support
*-----------------------------------------------------------------------------*/
enumbool ToolSettingFixSupport_IsEnable(void);




/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingLDFeature_Set
*Descrtiption : set Live Data feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingLDFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingLDFeature_Set
*Descrtiption : get Live Data feature of tool
                
*Input        : pointer to data buff to get value of LD feature in tool setting 
            and write to 
*Output       : none
*-----------------------------------------------------------------------------*/
uint32 ToolSettingLDFeature_Get(uint8* p_Data);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOBD2SpecialTest_Set
*Descrtiption : set OBD2 Special Test feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingOBD2SpecialTest_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 27 2015
*Function name: ToolSettingOBD2SpecialTest_IsValid
*Descrtiption : check to see whether OBD2 Special Test is support
                
*Input        : none
*Output       : enumbool - status of obd2 special test
*-----------------------------------------------------------------------------*/
enumbool    ToolSettingOBD2SpecialTest_IsValid(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOBD2SpecialTest_Get
*Descrtiption : get OBD2 Special Test feature of tool
                
*Input        : pointer to data buff need write value of Special Test into
*Output       : none
*-----------------------------------------------------------------------------*/
uint32 ToolSettingOBD2SpecialTest_Get(uint8* p_Data);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingABSFeature_Set
*Descrtiption : set ABS feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingABSFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingABSFeature_Get
*Descrtiption : Get ABS feature of tool
                
*Input        : pointer to data buff need write value of ABS Feature into
*Output       : size of ABS Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingABSFeature_Get(uint8* p_Data);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingSRSFeature_Set
*Descrtiption : set SRS feature of tool
                
*Input        : pointer to data buff need to get value of SRS Feature and write
                    to tool setting
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingSRSFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingSRSFeature_Get
*Descrtiption : Get SRS feature of tool
                
*Input        : pointer to data buff need write value of SRS Feature into
*Output       : size of SRS Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingSRSFeature_Get(uint8* p_Data);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingEnhanceFeature_Set
*Descrtiption : set Enhance feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingEnhanceFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingEnhanceFeature_Get
*Descrtiption : Get Enhance feature of tool
                
*Input        : pointer to data buff need write value of Enhance Feature into
*Output       : size of enhance Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingEnhanceFeature_Get(uint8* p_Data);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingBatteryResetFeature_Set
*Descrtiption : set Battery Reset feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingBatteryResetFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 27 2015
*Function name: ToolSettingBatteryResetFeature_IsValid
*Descrtiption : check to see whether Battery Reset is support
                
*Input        : none
*Output       : enumbool - status of battery reset support in tool setting
*-----------------------------------------------------------------------------*/
enumbool    ToolSettingBatteryResetFeature_IsValid(enumMake eMake);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingBatteryResetFeature_Get
*Descrtiption : Get Battery reset feature of tool
                
*Input        : pointer to data buff need write value of Battery Reset Feature into
*Output       : size of Battery Reset Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingBatteryResetFeature_Get(uint8* p_Data);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingABSLDFeature_Set
*Descrtiption : set ABS LD feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingABSLDFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingABSLDFeature_Get
*Descrtiption : Get ABS LD feature of tool
                
*Input        : pointer to data buff need write value of ABS LD Feature into
*Output       : size of ABS LD Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingABSLDFeature_Get(uint8* p_Data);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOBD1Feature_Set
*Descrtiption : set OBD1 feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingOBD1Feature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOBD1Feature_Get
*Descrtiption : Get OBD1 feature of tool
                
*Input        : pointer to data buff need write value of OBD1 Feature into
*Output       : size of ODB1 Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingOBD1Feature_Get(uint8* p_Data);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOilResetFeature_Set
*Descrtiption : set Oil Reset feature of tool
                
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void ToolSettingOilResetFeature_Set(uint8* p_Data);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 27 2015
*Function name: ToolSettingOilResetFeature_IsValid
*Descrtiption : check to see whether Oil Reset is support
                
*Input        : none
*Output       : enumbool - status of oil reset support in tool setting
*-----------------------------------------------------------------------------*/
enumbool    ToolSettingOilResetFeature_IsValid(enumMake eMake);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOilResetFeature_Get
*Descrtiption : Get Oil Reset feature of tool
                
*Input        : pointer to data buff need write value of Oil Reset Feature into
*Output       : size of Oil Reset Feature
*-----------------------------------------------------------------------------*/
uint32 ToolSettingOilResetFeature_Get(uint8* p_Data);













/*==============================================================================
                        SYSTEM SETTING INFORMATION
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: GetSystemInfo
*Descrtiption : get information of system setting 
                
*Input        : structSystemInfo - structure to write info into
*Output       : none
*-----------------------------------------------------------------------------*/
void GetSystemInfo(structSystemInfo* p_strtSysInf);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_SetDefault
*Descrtiption : set system setting to default 
                - use in case system setting not valid
*Input        : none
*Output       : enumbool - return true/false for valid/invalid
*-----------------------------------------------------------------------------*/
void SystemSetting_SetDefault(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSettingIsValid
*Descrtiption : check to see if system setting is valid
                check the variable g_strtSystemInfo is valid or not
*Input        : none
*Output       : enumbool - return true/false for valid/invalid
*-----------------------------------------------------------------------------*/
enumbool SystemSetting_IsValid(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 15 2014
*Function name: SystemSettingValid_Set
*Descrtiption : set the SystemStatus field in system setting to make this valid/invalid

*Input        : enumbool eValid - true/false value for valid/invalid
                        0xAA - Valid
                        else -  invalid
*Output       : none
*-----------------------------------------------------------------------------*/
void SystemSettingValid_Set(uint8 bValue);


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 06, 2011
                2. Oct1514 Lap Dang modified function name to SystemLanguage_Get
*Function name: SystemLanguage_Get
*Descrtiption : Return current language of system
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
uint8 SystemSetting_Language_Get(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemLanguageSet
*Descrtiption : set language use in system
                The function will set fiel LanguageSetting in g_strtSystemInfo
*Input        : bLanguage - language need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void SystemSetting_Language_Set(uint8 bLanguage);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Unit_Set
*Descrtiption : set unit of system
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void SystemSetting_Unit_Set(uint8 bUnit);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Unit_Get
*Descrtiption : get unit of system
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
uint8 SystemSetting_Unit_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Brightness_Set
*Descrtiption : set brightness level for LCD
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void SystemSetting_Brightness_Set(uint8 bBrightLevel);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Brightness_Get
*Descrtiption : get current brightness of LCD in system setting
*Input        : None
*Output       : uint8 - brightness level
*-----------------------------------------------------------------------------*/
uint8 SystemSetting_Brightness_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Buzzer_Set
*Descrtiption : set buzzer setting
*Input        : uint8 bBuzzValue - buzzer value ON/OFF
*Output       :
*-----------------------------------------------------------------------------*/
void SystemSetting_Buzzer_Set(uint8 bBuzzValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Buzzer_Get
*Descrtiption : get current buzzer setting
*Input        : None
*Output       : uint8 - buzzer setting (on/off)
*-----------------------------------------------------------------------------*/
uint8 SystemSetting_Buzzer_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Footer_Set
*Descrtiption : set Footer setting
*Input        : uint8   bFooterValue - Footer value ON/OFF
*Output       :
*-----------------------------------------------------------------------------*/
void SystemSetting_Footer_Set(uint8 bFooterValue);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Footer_Get
*Descrtiption : get current Footer setting
*Input        : None
*Output       : uint8 - Footer setting (on/off)
*-----------------------------------------------------------------------------*/
uint8 SystemSetting_Footer_Get(void);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Save
*Descrtiption : save system setting to memory
                The function will save g_strtSystemInfo in to memory, 
                currently save into Internal Flash
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void SystemSetting_Save(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: SystemSetting_Clear
*Descrtiption : clear system setting in memory
                The function will clear g_strtSystemSetting and also save to 
                storage, currently save into Internal Flash
*Input        : none
*Output       : none
*-----------------------------------------------------------------------------*/
void SystemSetting_Clear(void);











/*==============================================================================
                        FEATURE SETTING INFORMATION
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 13 2014
*Function name: FeatureSetting_SDCard_Set
*Descrtiption : set SDCard setting
                
*Input        : enumbool blEnDis
*Output       : none
*-----------------------------------------------------------------------------*/
void FeatureSetting_SDCard_Set(enumbool blEnDis);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOBD1Feature_Get
*Descrtiption : Get SDCard setting
                
*Input        : none
*Output       : enumbool - status of SDCard setting
*-----------------------------------------------------------------------------*/
enumbool FeatureSetting_SDCard_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 13 2014
*Function name: FeatureSetting_Security_Set
*Descrtiption : set Security setting
                
*Input        : enumbool blEnDis
*Output       : none
*-----------------------------------------------------------------------------*/
void FeatureSetting_Security_Set(enumbool blEnDis);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014
*Function name: ToolSettingOBD1Feature_Get
*Descrtiption : Get Security setting
                
*Input        : none
*Output       : enumbool - status of SDCard setting
*-----------------------------------------------------------------------------*/
enumbool FeatureSetting_Security_Get(void);






#endif


