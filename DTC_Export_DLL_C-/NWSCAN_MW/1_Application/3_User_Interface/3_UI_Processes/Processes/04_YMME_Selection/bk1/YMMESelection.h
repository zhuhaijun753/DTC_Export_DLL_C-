#ifndef _YMME_SEL_API_H
#define _YMME_SEL_API_H

#include <2_Middle\2_Vehicle_Interface\1_OBD_API\NWSCAN_APP\LIB\VBI_Utility.h>
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include "enums.h"
#include "YMME_Structure.h"

#define YMME_SELECTION_LIB_VERSION      "YMME Selection LIB V01.01.01"

#define USING_SEPERATED_MAKE_DATABASE

#define YMME_MAX_NUMBER_OF_ENTRY    6
#define MFR_SELECT_ITEM_MAX_AMOUNT  100

typedef     enumMemoryLanguage  enumOBDLanguage;
typedef     enumProtocol       enumYMMEProtocol;

extern unsigned char ymme_years[114];
extern unsigned char years_entry[152];
extern unsigned char make[2048];
extern unsigned char make_string_english[];
//extern unsigned char make_string_spanish[];
//extern unsigned char make_string_french[];
//extern unsigned char make_string_japanese[];
//extern unsigned char make_string_chinese[];
//extern unsigned char make_string_vietnamese[];
extern unsigned char protocol[2528];
extern unsigned char protocol_string_english[];
extern unsigned char fieldheader[];

//extern unsigned char buffername[1312];
//extern unsigned char buffername_string_english[];
//extern unsigned char buffername_string_french[];
//extern unsigned char buffername_string_spanish[];

#pragma pack(1)
typedef struct _structEntry
{
    uint32  iOffset;
    uint16  sQuantity;
} structEntry;
#pragma pack()

typedef struct _structYMMEEntryStack
{
    uint8           bStackSize;
    structEntry     eStackList[YMME_MAX_NUMBER_OF_ENTRY];
}structYMMEEntryStack;

typedef struct _structYMMEFieldStack
{
    uint8           bStackSize;
    enumMFRField    eStackList[YMME_MAX_NUMBER_OF_ENTRY];
}structYMMEFieldStack;

typedef struct _structYMMEIndexStack
{
    uint8           bStackSize;
    sint32          eStackList[YMME_MAX_NUMBER_OF_ENTRY];
}structYMMEIndexStack;

typedef enum __enumSearchStatus
{
	eSEARCH_NOTFOUND	    =	0,
	eSEARCH_FOUND		    =	1,
	
	eSEARCH_DATA_READ_ERROR	=	0xFF,
}enumSearchStatus;

#pragma pack(1)
typedef struct  _structMFRYMMESelectProfile{
    enumMFRField     eField; // 1 byte
    uint16           Lap DangemAmount; // 2 bytes
    uint16   		 eList[MFR_SELECT_ITEM_MAX_AMOUNT]; // 200 bytes
    structEntry 	 strtKeptEntry;  // 6 bytes
    //structYMMEIndexStack strtIndexStack;
}structMFRYMMESelectProfile;
#pragma pack()

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: MFRYMMEGetUserSelectList
*Descrtiption : get EnumList from Previous Selection
*Input        : p_strtMFRVehSelectProfile
*Output       : p_strtMFRVehSelectProfile
------------------------------------------------------------------------------*/
void MFRYMMEGetUserSelectList(structMFRVinProfile* p_strtMFRVinProfile, 
                              structMFRYMMESelectProfile* p_strtMFRVehSelectProfile,
                              structYMMEFieldStack* p_strtYMMEFieldStack,
                              structYMMEEntryStack* p_strtYMMEEntryStack);

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: getVehicleStringProfile
*Descrtiption : get String of All Vehicle Profile Field
*Input        : eLanguage, strtMFRVinProfile
*Output       : p_ProfileString
------------------------------------------------------------------------------*/
void getVehicleStringProfile(structMFRVinProfile* strtMFRVinProfile,
                             uint8* p_ProfileString, enumMemoryLanguage eLanguage);

#ifndef USING_SEPERATED_MAKE_DATABASE
/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: getYMMEFieldString
*Descrtiption : get String of specific Field by enum Value
*Input        : eLanguage, eFieldEnumValue, eField
*Output       : pOutputString
------------------------------------------------------------------------------*/
enumSearchStatus getYMMEFieldString(enumMFRField eField,
                                    uint16 eFieldEnumValue,
                                    uint8* pOutputString);

enumSearchStatus getYMMEFieldString_ML(enumMFRField eField,
                                       uint16 eFieldEnumValue,
                                       uint8* pOutputString,
                                       enumOBDLanguage eLanguage);

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: getYMMEFieldStringList_ML
*Descrtiption : get List String of enumList
*Input        : p_eFieldEnumValue, Lap DangemAmount, eField
*Output       : pOutputString, pGuiStr
------------------------------------------------------------------------------*/
void getYMMEFieldStringList_ML(enumMFRField eField, 
                               uint16 Lap DangemAmount, 
                               uint16* p_eFieldEnumValue,
                               const void* pGuiStr[],
                               uint8* pOutputString, 
                               enumOBDLanguage eLanguage);
#else
enumSearchStatus getYMMEFieldString(structMFRVinProfile* p_strtMFRVehicleProfile,
                                    enumMFRField eField,
                                    uint16 eFieldEnumValue,
                                    uint8* pOutputString);

enumSearchStatus getYMMEFieldString_ML(structMFRVinProfile* p_strtMFRVehicleProfile,
                                       enumMFRField eField,
                                       uint16 eFieldEnumValue,
                                       uint8* pOutputString,
                                       enumOBDLanguage eLanguage);

void getYMMEFieldStringList_ML(structMFRVinProfile* p_strtMFRVehicleProfile,
                               enumMFRField eField, 
                               uint16 Lap DangemAmount, 
                               uint16* p_eFieldEnumValue,
                               const void* pGuiStr[],
                               uint8* pOutputString, 
                               enumOBDLanguage eLanguage);

#endif

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: pressFieldItemHandle
*Descrtiption : handle Data when an item is chosen
*Input        : eField, iSelectedIdx
*Output       : p_strtMFRVehicleProfile, p_strtMFRVehSelectProfile
------------------------------------------------------------------------------*/
void pressFieldItemHandle(enumMFRField eField, sint32 iSelectedIdx,
                          structMFRVinProfile* p_strtMFRVehicleProfile, 
                          structMFRYMMESelectProfile* p_strtMFRVehSelectProfile,
                          structYMMEEntryStack* p_strtYMMEEntryStack,
                          structYMMEFieldStack* p_strtYMMEFieldStack);

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: backDataHandle
*Descrtiption : handle Data when pressing Back Button
*Input        : ePrevField, p_strtYMMEFieldStack
*Output       : p_strtMFRVehicleProfile, p_strtMFRVehSelectProfile
------------------------------------------------------------------------------*/
//void backDataHandle(enumMFRField ePrevField, structYMMEEntryStack* p_strtYMMEEntryStack,
//                    structMFRVinProfile* p_strtMFRVehicleProfile, 
//                    structMFRYMMESelectProfile* p_strtMFRVehSelectProfile);
void backDataHandle(enumMFRField ePrevField, structYMMEEntryStack* p_strtYMMEEntryStack,
                    structYMMEFieldStack* p_strtYMMEFieldStack,
                    structMFRVinProfile* p_strtMFRVehicleProfile, 
                    structMFRYMMESelectProfile* p_strtMFRVehSelectProfile);
 
/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: getMakeGroupFromMake
*Descrtiption : get MakeGroup for Input Make
*Input        : eMake
*Output       : 
------------------------------------------------------------------------------*/
enumMakeGroup getMakeGroupFromMake(enumMake eMake);

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: checkYMMEEnumMakeForNextField
*Descrtiption : check if selected Make has another field to choose
*Input        : eExMake, p_sIndexInList
*Output       : 
------------------------------------------------------------------------------*/
enumbool checkYMMEEnumMakeForNextField(structMFRYMMESelectProfile* strtMFRVehSelectProfile,
                                       enumMake eExMake,
                                       sint32* p_sIndexInList);
                
/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: checkMakeListInMarket
*Descrtiption : check if each Item in inputList belongs to MarketList
                NOTE: call this function before calling checkYMMEEnumMakeForNextField
*Input        : makeListProtocol, numberOfProtocolMakes
*Output       : makeListMarket
------------------------------------------------------------------------------*/             
uint16 checkMakeListInMarket(uint16 const* makeListProtocol, uint16 numberOfProtocolMakes, uint16* makeListMarket);

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: getManufacturerFromMake
*Descrtiption : get enumValue of correlative Manufacturer for Input Make
*Input        : eMake
*Output       : enumManufacturer
------------------------------------------------------------------------------*/
enumManufacturer getManufacturerFromMake(enumMake eMake);

#endif