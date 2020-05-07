/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __STORAGE_INTERFACE_ENUMERATION_H__
#define __STORAGE_INTERFACE_ENUMERATION_H__

#include    "InnovaCommonEnum.h"

typedef enum
{
    LiveData_Disable = 0x00,
    ViewLiveDataOnly = 0xA1,
    ViewnGraphingLiveData = 0xA2 ,
    ViewnGraphingnRecordLiveData = 0xA3
} e_LiveDataFunctionList;


#pragma pack(1)
typedef struct _structVehicleFeatureSetting
{
    union
    {
        uint8 VehSetup[23];
        struct
        {
            enumbool Kia_Setup:1;
            enumbool Hyundai_Setup:1;
            enumbool Nissan_Setup:1;
            enumbool Toyota_Setup:1;
            enumbool Honda_Setup:1;
            enumbool Chrysler_Setup:1;
            enumbool Ford_Setup:1;
            enumbool GM_Setup:1;

            enumbool Deawoo_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool ChevyAuto_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool BYD_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Mercedes_Setup:1;
            enumbool Audi_Setup:1;
            enumbool Volkswagen_Setup:1;
            enumbool Mini_Setup:1;
            enumbool BMW_Setup:1;

            enumbool Daihatsu_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Fiat_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Isuzu_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool LandRover_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Lifan_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Mitsubishi_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Porsche_Setup:1;//August1814 Lap Dang added as R&D 85
            enumbool Ssangyong_Setup:1;//August1814 Lap Dang added as R&D 85
            
            //bit 0 --> bit 7
            enumbool Reserve13_Setup:1;
            enumbool Reserve14_Setup:1;
            enumbool Reserve15_Setup:1;
            enumbool Mazda_Setup:1;//August1814 Lap Dang added Mazda as new
            enumbool Jaguar_Setup:1;//August1814 Lap Dang added Jaguar as new
            enumbool Sabb_Setup:1;
            enumbool Suzuki_Setup:1;
            enumbool Volvo_Setup:1;
            
            enumbool Reserve19_Setup:1;
            enumbool Reserve20_Setup:1;
            enumbool Reserve21_Setup:1;
            enumbool Reserve22_Setup:1;
            enumbool Reserve23_Setup:1;
            enumbool Reserve24_Setup:1;
            enumbool Reserve25_Setup:1;
            enumbool Reserve26_Setup:1;
            enumbool Reserve27_Setup:1;
            enumbool Reserve28_Setup:1;
            enumbool Reserve29_Setup:1;
            enumbool Reserve30_Setup:1;
            enumbool Reserve31_Setup:1;
            enumbool Reserve32_Setup:1;
            enumbool Reserve33_Setup:1;
            enumbool Reserve34_Setup:1;
            enumbool Reserve35_Setup:1;
            enumbool Reserve36_Setup:1;
            enumbool Reserve37_Setup:1;
            enumbool Reserve38_Setup:1;
            enumbool Reserve39_Setup:1;
            enumbool Reserve40_Setup:1;
            enumbool Reserve41_Setup:1;
            enumbool Reserve42_Setup:1;
            enumbool Reserve43_Setup:1;
            enumbool Reserve44_Setup:1;
            enumbool Reserve45_Setup:1;
            enumbool Reserve46_Setup:1;
            enumbool Reserve47_Setup:1;
            enumbool Reserve48_Setup:1;
            enumbool Reserve49_Setup:1;
            enumbool Reserve50_Setup:1;
            enumbool Reserve51_Setup:1;
            enumbool Reserve52_Setup:1;
            enumbool Reserve53_Setup:1;
            enumbool Reserve54_Setup:1;
            enumbool Reserve55_Setup:1;
            enumbool Reserve56_Setup:1;
            enumbool Reserve57_Setup:1;
            enumbool Reserve58_Setup:1;
            enumbool Reserve59_Setup:1;
            enumbool Reserve60_Setup:1;
            enumbool Reserve61_Setup:1;
            enumbool Reserve62_Setup:1;
            enumbool Reserve63_Setup:1;
            enumbool Reserve64_Setup:1;
            enumbool Reserve65_Setup:1;
            enumbool Reserve66_Setup:1;
            enumbool Reserve67_Setup:1;
            enumbool Reserve68_Setup:1;
            enumbool Reserve69_Setup:1;
            enumbool Reserve70_Setup:1;
            enumbool Reserve71_Setup:1;
            enumbool Reserve72_Setup:1;
            enumbool Reserve73_Setup:1;
            enumbool Reserve74_Setup:1;
            enumbool Reserve75_Setup:1;
            enumbool Reserve76_Setup:1;
            enumbool Reserve77_Setup:1;
            enumbool Reserve78_Setup:1;
            enumbool Reserve79_Setup:1;
            enumbool Reserve80_Setup:1;
            enumbool Reserve81_Setup:1;
            enumbool Reserve82_Setup:1;
            enumbool Reserve83_Setup:1;
            enumbool Reserve84_Setup:1;
            enumbool Reserve85_Setup:1;
            enumbool Reserve86_Setup:1;
            enumbool Reserve87_Setup:1;
            enumbool Reserve88_Setup:1;
            enumbool Reserve89_Setup:1;
            enumbool Reserve90_Setup:1;
        };
    };
} structVehicleFeatureSetting;
#pragma pack()

#define TOOL_SETTING_MAXSIZE    1*1024//currently, we reserved 1KB to save tool setting to internal memory,
                                      //if want to change this size, need to modified saving ToolSetting and System Setting
                                        //System Setting is saved following Tool Setting in Internal Flash Memory
#define TOOL_SETTING_VALID    0xAA
#define MAX_SIZE_SERIAL_NUMBER  32  //[Len 1Byte][Data 20bytes][status 1byte]
#pragma pack(1)
typedef struct _structToolSetting
{
    /*valid status*/
    uint8 ToolStatus;

    uint8 Reserverd1;
    uint8 Reserverd2;

    uint8 CustomerValid;
    uint8 CustomerID;

    enumUsbStorageMode eStorageMode;/*March1914 V27a Lap Dang declare this for usb mode*/
    uint8 Reserverd4;
    uint8 OBD1Setup;
    e_LiveDataFunctionList LiveDataSetup;
    uint8 Reserverd5;
    uint8 SpecialTestSetup;
    structVehicleFeatureSetting AbsVehSetup;
    structVehicleFeatureSetting SrsVehSetup;
    structVehicleFeatureSetting EnhVehSetup;
    //April1614 V32a Lap Dang added feature functions supported
    structVehicleFeatureSetting BatteryResetSetup;
    structVehicleFeatureSetting ABSLiveDataSetup;
    
    //Oct1414 Lap Dang change from enumbool to uint8
    uint8 blFixEnable;//Lap Dang move this field to tool setting for enable from PC

    //_ENABLE_ATE_FUNCTION_//always set this is 1, sync with R&D 86
    uint8 SerialNumber[MAX_SIZE_SERIAL_NUMBER];

    //September172014 Lap Dang added 1 field for Oil Reset setup
    structVehicleFeatureSetting OilLightResetDataSetup;
    
    /*Nov1014 Lap Dang added variable to store keys of tool*/
    uint16              sAllKeysOfToolMask;
    //November 21 2014 Lap Dang added for DLC Locator
    uint8       blDLCLocatorEnable;//VALID_CODE for valid, INVALID_CODE for invalid

    //All new parameters must be added from here
    //Each setting field added need to work with PC via USB command
    // -->add code in Usb for processing
    
    
    //August2214 Lap Dang added bReserve to set limit tool setting buffer size to 1KB
    uint8   bReserved[TOOL_SETTING_MAXSIZE - 185];//need modify this if we add more field to the struct
    
} structToolSetting;
#pragma pack()

#define SYSTEM_SETTING_INVALID  0x00
#define SYSTEM_SETTING_VALID    0xAA

#define GUID_SIZE               16
#define PHONE_NUMBER_SIZE       16
#define VIN_SIZE                17

#pragma pack(1)
typedef struct _structSystemSetting
{
    uint8 SystemStatus;     // If is not 0xaa, reset all parameters //
    uint8 LanguageSetting;
    uint8 BrightnessLevel;
    uint8 UnitSetting;
    uint8 BuzzerSetting;    /*Update as R&D 46*/
    uint8 BacklightSetting; /*Update as R&D 46*/
    uint8 Guid[GUID_SIZE];  // for carmd and repairsolutions
    uint8 Vin[VIN_SIZE];
    uint8 KioskToolId;      // index of string descriptor for kiosk tools
    uint8 Manufacturer;     // cellematics project
    union
    {
        struct
        {
            uint8 PhoneNumber[PHONE_NUMBER_SIZE]; //cellematics project
        };
        struct
        {
            uint8 FooterSetting;    /*Oct 09, 2013: Hoang Nguyen added*/
            uint8 BluetoothSetting; /*Oct 09, 2013: Hoang Nguyen added*/
        };
    };
    
    //May add new field here
    
} structSystemSetting;
#pragma pack()

#pragma pack(1)
/*
    Feature settings, other settings not in tool setting
    These things could be set.clear by firmware itseft.
*/
typedef struct _structFeatureSetting
{
    enumbool blSelectManufFirst;
    enumbool blSelectManufDTC;
    enumbool blSdCardEnable;
    enumbool blExFlashEnable;
    enumbool blSecurityPassed;
} structFeatureSetting;

#pragma pack()





#endif