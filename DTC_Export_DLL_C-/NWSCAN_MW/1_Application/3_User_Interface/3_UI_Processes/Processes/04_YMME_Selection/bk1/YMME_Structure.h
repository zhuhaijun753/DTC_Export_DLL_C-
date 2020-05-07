#ifndef _YMME_STRUCTURE_API_H
#define _YMME_STRUCTURE_API_H

#include "enums.h"
#include "enums_obd1.h"
#include "field_enums.h"
#include "fieldobd1_enums.h"

#define ENUM_OTHER_2_BYTES      0xFFFE
#define ENUM_MAX_2_BYTES        0xFFFF
#define ENUM_UNKNOWN    0x0000

#define     eYear_OTHERS     ENUM_OTHER_2_BYTES
#define     eYear_MAX        ENUM_MAX_2_BYTES

#define     eManufacturer_MAX_65535     ENUM_MAX_2_BYTES    
#define     eYear_UNKNOWN               ENUM_UNKNOWN
#define     eMake_UNKNOWN               ENUM_UNKNOWN
#define     eModel_UNKNOWN              ENUM_UNKNOWN
#define     eTrim_UNKNOWN               ENUM_UNKNOWN
#define     eBodyCode_UNKNOWN           ENUM_UNKNOWN
#define     eEngine_UNKNOWN             ENUM_UNKNOWN
#define     eManufacturer_UNKNOWN       ENUM_UNKNOWN

#define     eSystem_UNKNOWN             ENUM_UNKNOWN
#define     eMFR_MAKE_UNKNOWN           ENUM_UNKNOWN
#define     eMFR_MAKE_OTHERS            ENUM_OTHER_2_BYTES
#define     eMFR_MAKE_MAX               ENUM_MAX_2_BYTES

#define     eMake_OTHERS     ENUM_OTHER_2_BYTES
#define     eMake_MAX        ENUM_MAX_2_BYTES

#define     eModel_OTHERS     ENUM_OTHER_2_BYTES
#define     eModel_MAX        ENUM_MAX_2_BYTES

#define     eTrim_OTHERS    ENUM_OTHER_2_BYTES
#define     eTrim_MAX       ENUM_MAX_2_BYTES

#define     eBodyCode_OTHERS     ENUM_OTHER_2_BYTES
#define     eBodyCode_MAX        ENUM_MAX_2_BYTES

#define     eEngine_OTHERS    ENUM_OTHER_2_BYTES
#define     eEngine_MAX       ENUM_MAX_2_BYTES

#define     eTransmission_MAX       eTransmission_MAX_65535

#define     eMFR_FIELD_MODEL        eMFR_FIELD_Model    
#define     eMFR_FIELD_TRIM         eMFR_FIELD_Trim    
#define     eMFR_FIELD_ENGINE       eMFR_FIELD_Engine
#define     eMFR_FIELD_MAKE         eMFR_FIELD_Make
#define     eMFR_FIELD_BODY         eMFR_FIELD_Bodycode
#define     eMFR_FIELD_BM           eMFR_FIELD_Bm    
#define     eMFR_FIELD_YEAR         eMFR_FIELD_Year
#define     eMFR_FIELD_PROTOCOL     eMFR_FIELD_Protocol
#define     eMFR_FIELD_SYSTEM       eMFR_FIELD_System
#define     eMFR_FIELD_SUBSYSTEM    eMFR_FIELD_Subsystem
#define     eMFR_FIELD_TRANSMISSION eMFR_FIELD_Transmission
#define     eMFR_FIELD_ECUTYPE      eMFR_FIELD_Ecutype
#define     eMFR_FIELD_BUFFER_NAME  eMFR_FIELD_Buffername

typedef     uint16   enumModel;   
typedef     uint16   enumTrim;	
typedef     uint16   enumEngine; 
typedef     uint16   enumBodyCode;

typedef     uint16  enumSystem;
typedef     uint16  enumSubSystem;

typedef     uint16  enumBM;

//Jan1215 Lap Dang modified to compatible with new enumeration file aThang built on Jan09

typedef     enumMemoryLanguage  enumOBDLanguage;
typedef     enumManufacturer    enumMFRManufacturer;
typedef     enumMake  enumMFRMake;
typedef     uint16    enumMFRModel;

typedef     uint16    enumMFREngine;
typedef     uint16    enumMFRTrim;
typedef     uint16    enumMFRTransmission;

typedef     uint16  enumMFRSystem;
typedef     uint16  enumMFRSubSystem;
         
#define		eMFR_SYSTEM_Engine		(82)
#define		eMFR_SYSTEM_TCM		 	(257)
#define		eSystem_BODY_ELECTRICAL_37      (37)
#define		eSystem_PCM_176                 (176)

#define	        eMFR_MAKE_Acura						(eMake_ACURA_1)
#define		eMFR_MAKE_AM__General					(eMake_AM_GENERAL_2)
#define		eMFR_MAKE_Audi						(eMake_AUDI_3)
#define		eMFR_MAKE_BMW							(eMake_BMW_4)
#define		eMFR_MAKE_Buick						(eMake_BUICK_5)
#define		eMFR_MAKE_Cadillac					(eMake_CADILLAC_6)
#define		eMFR_MAKE_Chevrolet					(eMake_CHEVROLET_7)
#define		eMFR_MAKE_Chrysler					(eMake_CHRYSLER_8)
#define		eMFR_MAKE_Daewoo						(eMake_DAEWOO_9)
#define		eMFR_MAKE_Dodge						(eMake_DODGE_10)
#define		eMFR_MAKE_Eagle						(eMake_EAGLE_11)
#define		eMFR_MAKE_Ford					(eMake_FORD_12)
#define		eMFR_MAKE_Geo							(eMake_GEO_13)
#define		eMFR_MAKE_GMC							(eMake_GMC_14)
#define		eMFR_MAKE_Honda						(eMake_HONDA_15)
#define		eMFR_MAKE_Hummer						(eMake_HUMMER_16)
#define		eMFR_MAKE_Hyundai						(eMake_HYUNDAI_17)
#define		eMFR_MAKE_Infiniti					(eMake_INFINITI_18)
#define		eMFR_MAKE_Isuzu						(eMake_ISUZU_44)
#define		eMFR_MAKE_Jaguar						(eMake_JAGUAR_19)
#define		eMFR_MAKE_Jeep						(eMake_JEEP_20)
#define		eMFR_MAKE_Kia							(eMake_KIA_21)
#define		eMFR_MAKE_Land__Rover					(eMake_LAND_ROVER_22)
#define		eMFR_MAKE_Lexus						(eMake_LEXUS_23)
#define		eMFR_MAKE_Lincoln						(eMake_LINCOLN_24)
#define		eMFR_MAKE_Mazda						(eMake_MAZDA_25)
#define		eMFR_MAKE_Mercedes__Benz				(eMake_MERCEDES_26)
#define		eMFR_MAKE_Mercury						(eMake_MERCURY_27)
#define		eMFR_MAKE_Mini						(eMake_MINI_28)
#define		eMFR_MAKE_Mitsubishi					(eMake_MITSUBISHI_45)
#define		eMFR_MAKE_Nissan						(eMake_NISSAN_29)
#define		eMFR_MAKE_Oldsmobile					(eMake_OLDSMOBILE_30)
#define		eMFR_MAKE_Plymouth					(eMake_PLYMOUTH_31)
#define		eMFR_MAKE_Pontiac						(eMake_PONTIAC_32)
#define		eMFR_MAKE_Porsche						(eMake_PORSCHE_41)
#define		eMFR_MAKE_Ram							(eMake_RAM_33)
#define		eMFR_MAKE_Saab						(eMake_SAAB_34)
#define		eMFR_MAKE_Saturn						(eMake_SATURN_35)
#define		eMFR_MAKE_Scion						(eMake_SCION_36)
#define		eMFR_MAKE_Smart						(eMake_SMART_42)
#define		eMFR_MAKE_SRT							(eMake_SRT_37)
#define		eMFR_MAKE_Subaru						(eMake_SUBARU_43)
#define		eMFR_MAKE_Suzuki						(eMake_SUZUKI_46)
#define		eMFR_MAKE_Toyota						(eMake_TOYOTA_38)
#define		eMFR_MAKE_Volkswagen					(eMake_VOLKSWAGEN_39)
#define		eMFR_MAKE_Volvo						(eMake_VOLVO_40)

#define		eMFR_MAKE_MAX						(eMake_MAX)
#define		eMFR_MAKE_UNKNOWN					(eMake_UNKNOWN)
#define		eMFR_MAKE_OTHERS					(eMake_OTHERS)

//typedef enum __enumOBDLanguage
//{
//    eOBDMEM_LANGUAGE_UNDEFINE      = 0,
//#if 0
//    eMEM_LANGUAGE_ENGLISH       = 1,
//    eMEM_LANGUAGE_SPANISH       = 2,
//    eMEM_LANGUAGE_FRENCH        = 3,
//    eMEM_LANGUAGE_JAPANESE      = 4,
//    eMEM_LANGUAGE_CHINESE       = 5,
//    eMEM_LANGUAGE_VIETNAMESE    = 6,
//
//    eMEM_LANGUAGE_MAX           = 0xFF
//#endif
//}enumOBDLanguage;

typedef enum _enumTransmission{
    eTransmission_UNKNOWN   = 0,
    eTransmission_MANUAL_1  = 1,
    eTransmission_AUTOMATIC_2  = 2,
    eTransmission_OTHERS_65534  = 65534,
    eTransmission_MAX_65535  = 65535,
}enumTransmission;

#define     eTransmission_Manual    eTransmission_MANUAL_1
#define     eTransmission_Automatic    eTransmission_AUTOMATIC_2

typedef enum _enumMFRVinDecodeStatus{
    // Decode proccess NOT complete
    eMFR_INVALID                 =   0x00,
    // No SDCard detected
    eMFR_NO_SDCARD               =   0x0C,
    // more than 1 vehicle have same VINs
    eMFR_CONFLICT                =   0x55,
    // Vin Year repeat after 30 years, exapmle VinYear of 1994 & 2024 is 'R', same together
    // if current date time is 2024, all datacell of 1994 need to remove from database
    eMFR_YEAR_VIN_CONFLICT       =   0x66,
    // Decode proccess complete
    eMFR_VALID                   =   0xAA,
    // Information in 1 datacell INCORRECT
    eMFR_DATACELL_ERROR          =   0x88,
    // Lack neccessary information to get user select list
    eMFR_MISSING_INPUT_DATA      =   0x99,
    // Folder structure of database too complex lead file path > 255 chars
    eMFR_FILENAME_ERROR          =   0xBB,
    // Data cell too large, can not parse to strtVinDataCell structure
    eMFR_BUFFER_OVERFLOW_VIN         =   0xCC,
    // Pointer point to NULL address
    eMFR_POINTER_ADDRESS_NULL    =   0xDD,
    // Can not find corresponding datacell in database folder
    eMFR_DATABASE_NOT_EXIST      =   0xEE,
    // API read SD card can not read file completely
    eMFR_DATABASE_READ_ERROR     =   0xFF,
}enumMFRVinDecodeStatus;

//typedef enum _enumMFRField{
//    eMFR_FIELD_NONE		= 0,
//	
//    eMFR_FIELD_YEAR		= 1,
//	eMFR_FIELD_MANUFACTURER	= 2,
//	eMFR_FIELD_MAKE		= 3,
//	eMFR_FIELD_MODEL		= 4,
//	eMFR_FIELD_TRIM		= 5,
//	eMFR_FIELD_BODY		= 6,
//	eMFR_FIELD_ENGINE   = 7,
//    eMFR_FIELD_BM,
//    eMFR_FIELD_TRANSMISSION,
//	eMFR_FIELD_ENGINE_VIN8,
//    eMFR_FIELD_SYSTEM,
//    eMFR_FIELD_SUBSYSTEM,
//    eMFR_FIELD_BUFFER_NAME,
//    eMFR_FIELD_CHECKSUM,
//    eMFR_FIELD_COMMAND,
//    eMFR_FIELD_COMMANDLIST,
//    eMFR_FIELD_CONNECTOR,
//    eMFR_FIELD_DLC_VOLTAGE,
//    eMFR_FIELD_DLC,
//    eMFR_FIELD_DTC_DISPLAYTYPE,
//    eMFR_FIELD_DTC_READTYPE,
//    eMFR_FIELD_DTC_STATUS,
//    eMFR_FIELD_ECUID,
//    eMFR_FIELD_ECUTYPE,
//    eMFR_FIELD_ERASETYPE,
//    eMFR_FIELD_INIT_TYPE,
//    eMFR_FIELD_INNOVAGROUP,
//    eMFR_FIELD_LOOKUP_TABLE,
//    eMFR_FIELD_MESSAGE_ID,
//    eMFR_FIELD_PROGRAM_ID,
//    eMFR_FIELD_PROTOCOL,
//    eMFR_FIELD_READDTC_COMMANDLIST,
//    eMFR_FIELD_RESISTOR,
//    eMFR_FIELD_TIMING,
//    eMFR_FIELD_UART_DATA,
//    eMFR_FIELD_VARIANT,
//    eMFR_FIELD_VEHICLE_TYPE,
//    eMFR_FIELD_VREF,
//    
//    eMFR_FIELD_DISPLAYVISIBLE,
//    eMFR_FIELD_ECUINFOTYPE,
//    eMFR_FIELD_ECUPARTNUMBER,
//    eMFR_FIELD_ECUTYPEID,
//    eMFR_FIELD_HONDAOPTION,
//    eMFR_FIELD_PARSETYPE,
//    eMFR_FIELD_UNITINFO,
//    
//	eMFR_FIELD_OTHERS		= 0xFE,
//    eMFR_FIELD_MAX		= 0xFF
//} enumMFRField;

typedef enum _enumMakeGroup{
    eGroup_UNKNOWN      = 0,
    eGroup_Audi_VW      = 1,
    eGroup_BMW_Mini,
    eGroup_Chrysler,
    eGroup_Ford,
    eGroup_GM,
    eGroup_Honda,
    eGroup_Hyundai_Kia,
    eGroup_Jaguar,
    eGroup_Land_Rover,
    eGroup_Madza,
    eGroup_Mercedes,
    eGroup_Nissan,
    eGroup_Toyota,
    eGroup_Volvo,
    
    eGroup_Fiat,
    eGroup_Freightliner,
    eGroup_Isuzu,
    eGroup_Mitsubishi,
    eGroup_Porsche,
    eGroup_RollsRoyce,
    eGroup_Subaru,
    eGroup_Suzuki,
    
    eGroup_Smart,
    
	eGroup_OTHERS		= 0xFE,
    eGroup_MAX		    = 0xFF
} enumMakeGroup;

/*OBD1*/

#pragma pack(1)
typedef struct  _structYMMEOBD1Profile
{
    enumMFRVinDecodeStatus  ValidStatus;
    uint16                  sProfileID;
    
    enumOBD1year				eYear;			
    enumOBD1vin8				eVin8;			
    enumOBD1truck               eTruck;
    enumOBD1trucktype           eTruckType;
    enumOBD1heavyduty           eHeavyDuty;
    enumOBD1lit                 eLit;
    enumOBD1vin4                eVin4;
    enumOBD1engine              eEngine;
    enumOBD1make                eMake;
    enumOBD1transmission        eTransmission;
    enumOBD1vehspeed            eVehSpeed;
    enumOBD1speeddenLap Dangy        eSpeedDenLap Dangy;
    enumOBD1year84_5            eYear84_5;
    enumOBD1maf                 eMaf;
    enumOBD1federalemission     eFederalEmission;
    enumOBD1varfuelvehicle      eVarFuelVehicle;
    enumOBD1reatta              eReatta;
    enumOBD1vin10_17_val2       eVin10_17_val2;

}structYMMEOBD1Profile;     
#pragma pack()

#define     VINPROFILE_INFO_MAX_SIZE    (512)
#define     YMME_PROFILE_VIN_NUMBER_VALID_CHARS     (17)
#pragma pack(1)
typedef struct  _structMFRVinProfile
{
    //Valid status
    enumMFRVinDecodeStatus  ValidStatus;        //1 byte
    
    uint8                   bVinString[YMME_PROFILE_VIN_NUMBER_VALID_CHARS+1];     //18 bytes
    enumManufacturer     eManufacturer;      //2 bytes
    enumYear             eYear;              //2 bytes
    enumMake             eMake;              //2 bytes
    uint16               eModel;             //2 bytes
    uint16               eTrim;              //2 bytes
    uint16               eBodyCode;          //2 bytes
    uint16               eEngine;            //2 bytes
    uint16               eTransmission;       //2 bytes
    
    enumMakeGroup        eMakeGroup;          //1 byte
    
    union
    {
        uint8                  bReserved[VINPROFILE_INFO_MAX_SIZE - sizeof(bVinString) - 18]; //Note: change Size after modifying this structure
        structYMMEOBD1Profile  strtYMMEOBD1Profile;
    };
}structMFRVinProfile;     
#pragma pack()

#endif