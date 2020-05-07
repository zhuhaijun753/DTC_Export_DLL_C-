/******************************************************************************************************************
*Engineer    : TienTN
*Date        : 
*File        : Proc_YMMESelection.c
*Description : Process YMME Selection
********************************************************************************************************************/
/*#################################################################################*/
/*
================================================================================
INCLUDED FILES
================================================================================
*/
#include <PlatFormType.h>

#include <GUIManager.h>

#include "KeyBoardApp.h"
#include    "Processes.h"
#include "OBDToolManager.h"

#include    "Common_Text_Database.h"
#include    "CommonKeyHandler.h"

#include "StorageMemoryInterface.h"
#include    <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Manager.h>

#include <YMMESelection.h>
#include    <1_Application\3_User_Interface\3_UI_Processes\Processes\05_VIN_Decode\VinDecode.h>


/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
// Define used command in this process here, these value should not be in (SYS_CMD_ID)
// declared in SysProcess.h
#define     PROC_SELECT_YMME_DISPLAY_CONFIRM        (SYS_CMD_ID)(1001)
#define     CMD_PROC_YMME_VIN_DECODE        (SYS_CMD_ID)(1002)
#define     UI_COMMAND_3        (SYS_CMD_ID)(1003)
#define     UI_COMMAND_4        (SYS_CMD_ID)(1004)
#define     UI_COMMAND_5        (SYS_CMD_ID)(1005)
#define     UI_COMMAND_6        (SYS_CMD_ID)(1006)
#define     UI_COMMAND_7        (SYS_CMD_ID)(1007)
#define     UI_COMMAND_8        (SYS_CMD_ID)(1008)
#define     UI_COMMAND_9        (SYS_CMD_ID)(1009)
#define     UI_COMMAND_10       (SYS_CMD_ID)(1010)
#define     UI_COMMAND_11       (SYS_CMD_ID)(1011)
#define     UI_COMMAND_12       (SYS_CMD_ID)(1012)
#define     UI_COMMAND_13       (SYS_CMD_ID)(1013)
#define     UI_COMMAND_14       (SYS_CMD_ID)(1014)



/*******************************************************************************
================================================================================
                            GLOBAL VARIABLES
================================================================================
*******************************************************************************/

#define     eOBD2Protocol       (ToolManager_SystemHandler_OBD2_Protocol_Get())

#define     ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL     (1)

//this variable used to handle make list follow protocol, just use for selecting Make
const uint16 * p_ProtocolMakeList = null;

const uint16 eMakeVPWList[] =
{
    emake_BUICK,
    emake_CADILLAC,
    emake_CHEVROLET,
    emake_CHRYSLER,
    emake_DAEWOO,
    emake_DODGE,
    emake_EAGLE,
    emake_RAM,
    emake_SRT,
    emake_GEO,
    emake_GMC,
    emake_HUMMER,
    emake_AM_____GENERAL,
    emake_ISUZU,
    emake_JEEP,
    emake_OLDSMOBILE,
    emake_PLYMOUTH,
    emake_PONTIAC,
    emake_SATURN,
    
    emake_ACURA,
    emake_AUDI,
    emake_BMW,
    emake_FIAT,
    emake_FORD,
    emake_HONDA,
    emake_HYUNDAI,
    emake_INFINITI,
    emake_JAGUAR,
    emake_KIA,
    emake_LAND_____ROVER,
    emake_LEXUS,
    emake_LINCOLN,
    emake_MAZDA,
    emake_MERCEDES_BENZ,
    emake_MERCURY,
    emake_MINI,
    emake_MITSUBISHI,
    emake_NISSAN,
    emake_PORSCHE,
    emake_SAAB,
    emake_SCION,
    emake_SMART,
    emake_SUBARU,
    emake_SUZUKI,
    emake_TOYOTA,
    emake_VOLKSWAGEN,
    emake_VOLVO,
    
    emake_BYD,
    emake_CHERY,
    
    emake_DAIHATSU,
    emake_SSANGYONG,
    emake_MG,
    emake_PEUGEOT,
    emake_SEAT,
    emake_BENTLEY,
    emake_ALFA_____ROMEO,
    emake_CITRO_N,
    emake_LIFAN,
    
    emake_OTHERS,
    
    emake_MAX,
};

const uint16 eMakePWMList[] =
{
    emake_FORD,
    emake_LINCOLN,
    emake_MAZDA,
    emake_MERCURY,
    
    emake_ACURA,
    emake_AUDI,
    emake_BMW,
    emake_BUICK,
    emake_CADILLAC,
    emake_CHEVROLET,
    emake_CHRYSLER,
    emake_DAEWOO,
    emake_DODGE,
    emake_EAGLE,
    emake_FIAT,
    emake_GEO,
    emake_GMC,
    emake_RAM,
    emake_SRT,
    emake_HONDA,
    emake_HUMMER,
    emake_HYUNDAI,
    emake_INFINITI,
    emake_ISUZU,
    emake_JAGUAR,
    emake_JEEP,
    emake_KIA,
    emake_LAND_____ROVER,
    emake_LEXUS,
    emake_MERCEDES_BENZ,
    emake_MINI,
    emake_MITSUBISHI,
    emake_NISSAN,
    emake_OLDSMOBILE,
    emake_PLYMOUTH,
    emake_PONTIAC,
    emake_PORSCHE,
    emake_SAAB,
    emake_SATURN,
    emake_SCION,
    emake_SMART,
    emake_SUBARU,
    emake_SUZUKI,
    emake_TOYOTA,
    emake_VOLKSWAGEN,
    emake_VOLVO,
    
    emake_BYD,
    emake_CHERY,
    
    emake_DAIHATSU,
    emake_SSANGYONG,
    emake_MG,
    emake_PEUGEOT,
    emake_SEAT,
    emake_BENTLEY,
    emake_ALFA_____ROMEO,
    emake_CITRO_N,
    emake_LIFAN,
    
    emake_OTHERS,
    
    emake_MAX,
};

const uint16 eMakeCANList[] =
{
    emake_ACURA,
    emake_AUDI,
    emake_BMW,
    emake_BUICK,
    emake_CADILLAC,
    emake_CHEVROLET,
    emake_CHRYSLER,
    emake_DAEWOO,
    emake_DODGE,
    emake_EAGLE,
    emake_FIAT,
    emake_FORD,
    emake_GEO,
    emake_GMC,

    emake_HONDA,
    emake_HUMMER,
    emake_HYUNDAI,
    emake_INFINITI,
    emake_ISUZU,
    emake_JAGUAR,
    emake_JEEP,
    emake_KIA,
    emake_LAND_____ROVER,
    emake_LEXUS,
    emake_LINCOLN,
    emake_MAZDA,
    emake_MERCEDES_BENZ,
    emake_MERCURY,
    emake_MINI,
    emake_MITSUBISHI,
    emake_NISSAN,
    emake_OLDSMOBILE,
    emake_PLYMOUTH,
    emake_PONTIAC,
    emake_PORSCHE,
    emake_RAM,
    emake_SAAB,
    emake_SATURN,
    emake_SCION,
    emake_SMART,
    emake_SRT,
    emake_SUBARU,
    emake_SUZUKI,
    emake_TOYOTA,
    emake_VOLKSWAGEN,
    emake_VOLVO,
    
    emake_OTHERS,
    
    emake_MAX,
};

const uint16 eMakeKW2000List[] =
{
    emake_ACURA,
    emake_AUDI,
    emake_BMW,
    emake_BUICK,
    emake_CADILLAC,
    emake_CHEVROLET,
    emake_DAEWOO,
    emake_GEO,
    emake_GMC,
    emake_HUMMER,
    emake_AM_____GENERAL,
    emake_HYUNDAI,
    emake_KIA,
    emake_MINI,
    emake_OLDSMOBILE,
    emake_PONTIAC,
    emake_PORSCHE,
    emake_SAAB,
    emake_SATURN,
    emake_SUBARU,
    emake_SUZUKI,
    emake_VOLKSWAGEN,
    
    emake_CHRYSLER,
    emake_DODGE,
    emake_EAGLE,
    emake_FIAT,
    emake_RAM,
    emake_SRT,
    emake_FORD,
    emake_HONDA,
    emake_INFINITI,
    emake_ISUZU,
    emake_JAGUAR,
    emake_JEEP,
    emake_LAND_____ROVER,
    emake_LEXUS,
    emake_LINCOLN,
    emake_MAZDA,
    emake_MERCEDES_BENZ,
    emake_MERCURY,
    emake_MITSUBISHI,
    emake_NISSAN,
    emake_PLYMOUTH,
    emake_SCION,
    emake_SMART,
    emake_TOYOTA,
    emake_VOLVO,
    
    emake_OTHERS,
    
    emake_MAX,
};

const uint16 eMakeISO9141List[] =
{
    emake_ACURA,
    emake_AUDI,
    emake_BMW,
    emake_BUICK,
    emake_CADILLAC,
    emake_CHEVROLET,
    emake_CHRYSLER,
    emake_DAEWOO,
    emake_DODGE,
    emake_EAGLE,
    emake_FIAT,
    emake_GEO,
    emake_GMC,
    emake_RAM,
    emake_SRT,
    emake_HONDA,
    emake_HUMMER,
    emake_HYUNDAI,
    emake_INFINITI,
    emake_JAGUAR,
    emake_JEEP,
    emake_KIA,
    emake_LAND_____ROVER,
    emake_LEXUS,
    emake_MAZDA,
    emake_MERCEDES_BENZ,
    emake_MINI,
    emake_MITSUBISHI,
    emake_NISSAN,
    emake_OLDSMOBILE,
    emake_PLYMOUTH,
    emake_PONTIAC,
    emake_PORSCHE,
    emake_SAAB,
    emake_SATURN,
    emake_SCION,
    emake_SUBARU,
    emake_SUZUKI,
    emake_TOYOTA,
    emake_VOLKSWAGEN,
    emake_VOLVO,
    emake_FORD,
    emake_ISUZU,
    emake_LINCOLN,
    emake_MERCURY,
    emake_SMART,
    
    emake_OTHERS,
    
    emake_MAX,
};

const uint16 eMakeDefaultList[] =
{
    emake_ACURA,
    emake_AM_____GENERAL,
    emake_AUDI,
    emake_BMW,
    emake_BUICK,
    emake_CADILLAC,
    emake_CHEVROLET,
    emake_CHRYSLER,
    emake_DAEWOO,
    emake_DODGE,
    emake_EAGLE,
    emake_FIAT,
    emake_FORD,
    emake_GEO,
    emake_GMC,
    emake_HONDA,
    emake_HUMMER,
    emake_HYUNDAI,
    emake_INFINITI,
    emake_ISUZU,
    emake_JAGUAR,
    emake_JEEP,
    emake_KIA,
    emake_LAND_____ROVER,
    emake_LEXUS,
    emake_LINCOLN,
    emake_MAZDA,
    emake_MERCEDES_BENZ,
    emake_MERCURY,
    emake_MINI,
    emake_MITSUBISHI,
    emake_NISSAN,
    emake_OLDSMOBILE,
    emake_PLYMOUTH,
    emake_PONTIAC,
    emake_PORSCHE,
    emake_RAM,
    emake_SAAB,
    emake_SATURN,
    emake_SCION,
    emake_SMART,
    emake_SRT,
    emake_SUBARU,
    emake_SUZUKI,
    emake_TOYOTA,
    emake_VOLKSWAGEN,
    emake_VOLVO,
    
    emake_OTHERS,
    
    emake_MAX,
};

const void* const MLSelectVehicle[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Vehicle Selection",
    "Selecci�n del veh�culo",
    "S�lectionner v�hicule"
);
const void* const MLSureSelectByEnterYesNo[NUM_LANG_SUPPORT] =
DefineMLText
(
   " Is this your vehicle?\n\n Select and press " ENTER_BUTTON_IMAGE "\n Yes\n No",
   " �Es este su veh�culo?\n Seleccione y Presione " ENTER_BUTTON_IMAGE "\n S�\n NO",
   " S'agit-il de votre v�hicule??\n S�lect et appuyer "ENTER_BUTTON_IMAGE "\n OUI\n NON"
);
const void* const MLVehicleInfo_Title[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Vehicle Confirm",
    "Informaci�n del veh�culo",
    "Confirmer le v�hicule"
);


#define MAX_CHAR_VEHICLE_INFO   100

structYMMEEntryStack strtYMMEEntryStack = 
{
    .bStackSize = 0
};

structYMMEFieldStack strtYMMEFieldStack =
{
    .bStackSize = 0
};

uint8 VehicleInfoText[MAX_CHAR_VEHICLE_INFO];

structMFRYMMESelectProfile    g_strtMFRYMMESelectProfile;
structMFRVinProfile g_strtMFRVehicleProfileTemp;//this just temp buff for selection


#define p_strtMFRVehicleProfileTemp     (&g_strtMFRVehicleProfileTemp)

//after selection, must save info to this buff
#define     p_strtMFRVehicleProfile     (&g_strtVehicleDataBuffer.strtVehData_YMMEProfile)






/*==============================================================================
FUCNTIONs SUPPORT FOR PROCESSING DATA

==============================================================================*/
static void YMMESel_ProfileReset(void)
{
    memset(VehicleInfoText, Null, MAX_CHAR_VEHICLE_INFO);
    memset(&g_strtMFRVehicleProfileTemp, Null, sizeof(structMFRVinProfile));
    memset(&g_strtMFRYMMESelectProfile, Null, sizeof(g_strtMFRYMMESelectProfile));
    memset(&strtYMMEEntryStack, Null, sizeof(structYMMEEntryStack));
    memset(&strtYMMEFieldStack, Null, sizeof(structYMMEFieldStack));
    g_strtMFRYMMESelectProfile.eField = eMFR_FIELD_NONE;
}

static void OBD2_VIN_Decode_Processing(void)
{
    uint32 sManuMakeList[10];
    
    memset(sManuMakeList,
           eMFR_MAKE_UNKNOWN,
           sizeof(sManuMakeList));
    //copy VIN string from vehicle ymme profile to temp buff
    if(ToolManager_YMMEProfile_VINString_Get(p_strtMFRVehicleProfileTemp->bVinString))
    {        
        decodeVINtoVehicleInfo(sManuMakeList,
                               p_strtMFRVehicleProfileTemp);
        
        if(p_strtMFRVehicleProfileTemp->ValidStatus == eMFR_VALID)
        {
            //Feb0215 Lap Dang modified, need to select transmission manual
            p_strtMFRVehicleProfileTemp->ValidStatus = eMFR_INVALID;
            g_strtMFRYMMESelectProfile.eField = eMFR_FIELD_TRANSMISSION;
            Proc_ChangeCmd(CMD_PROCESSING_DATA,0,0);
            
//            Proc_ChangeCmd(PROC_SELECT_YMME_DISPLAY_CONFIRM,0,0);
        }
        else
        {
            //reset temp buffer if decode not valid
            memset(p_strtMFRVehicleProfileTemp, Null, sizeof(structMFRVinProfile));
            Proc_ChangeCmd(CMD_PROCESSING_DATA,0,0);
            
        }
    }
    return;
}


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 
*Function name: MakeListFollowProtocol_Enum_Get
*Descrtiption : Get the Make List based on Protocol
*Input        : 
*Output       : uint16* - pointer to make list (in internal flash)
------------------------------------------------------------------------------*/
const uint16* MakeListFollowProtocol_Enum_Get(enumProtocol eProtocol);
/*static */const uint16* MakeListFollowProtocol_Enum_Get(enumProtocol eProtocol)
{
    const uint16 * p_MakeList = null;
    
    switch(eProtocol)
    {
    case PROTOCOL_VPW:
        p_MakeList = eMakeVPWList;
        break;
        
    case PROTOCOL_PWM:
        p_MakeList = eMakePWMList;
        break;
        
    case PROTOCOL_ISO9141:
        p_MakeList = eMakeISO9141List;
        break;
                
    case PROTOCOL_KW2000:
        p_MakeList = eMakeKW2000List;
        break;
        
    case PROTOCOL_CAN500KBAUD:
    case PROTOCOL_XCAN500KBAUD:
    case PROTOCOL_CAN250KBAUD:
    case PROTOCOL_XCAN250KBAUD:
        p_MakeList = eMakeCANList;
        break;
        
    default://not linked successful OBD2 before
        p_MakeList = eMakeDefaultList;
        break;
    }
    
    return p_MakeList;
}

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: 
*Descrtiption : 
*Input        : 
*Output       : 
------------------------------------------------------------------------------*/
static uint16 GetQuantity_MakeListFollowProtocol(const uint16* p_MakeListEnum)
{
    uint16 sIdx = 0;
    
    while((*p_MakeListEnum) != eMFR_MAKE_MAX)
    {
        sIdx++;
        p_MakeListEnum++;
    }
    
    return sIdx;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 
*Function name: ProcessMakeListFollowProtocol_String
*Descrtiption : Get Make string and set to GUI buffer to display
*Input        : 
                uint16* p_MakeListEnum - pointer to make list enum, end with eMFR_MAKE_MAX
                uint8 * p_bStrBuffer - raw buffer to store make list strings
*Output       : uint16 - number of item
------------------------------------------------------------------------------*/
uint16 ProcessMakeListFollowProtocol_String(const uint16* p_MakeListEnum,
                                            uint8 * p_strBuffer);
/*static*/ uint16 ProcessMakeListFollowProtocol_String(const uint16* p_MakeListEnum,
                                                   uint8 * p_strBuffer)
{
    uint16 sIdx = 0;
    enumSearchStatus eStatus = eSEARCH_NOTFOUND;
    
    while((*p_MakeListEnum) != eMFR_MAKE_MAX)
    {
        eStatus = getYMMEFieldString_ML(p_strtMFRVehicleProfile,
                                        eMFR_FIELD_MAKE, 
                                        (*p_MakeListEnum), 
                                        p_strBuffer, 
                                        (uint8) (CURRENT_LANGUAGE_ID + 1));
        if (eStatus != eSEARCH_FOUND)//if make string couldn't be get from database
        {
            //this is just for testing, release version must alway search found
            sprintf(p_strBuffer, "Make %d", (*p_MakeListEnum));
        }
        //set pointer for UI display
        GUI_Manager.p_strNameList[sIdx++]= p_strBuffer;
        //increase pointer for raw buff stores Make string
        p_strBuffer = GetStrOffset(p_strBuffer, 
                                   GetstrLenBuff(p_strBuffer) + 1);
        //increase pointer to make list
        p_MakeListEnum++;
    }
    
    return sIdx;
}

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: 
*Descrtiption : 
*Input        : 
*Output       : 
------------------------------------------------------------------------------*/
//warning - this function should be in YMME API?
void YMMEFieldStackPop(enumMFRField* p_eField);
/*static*/ void YMMEFieldStackPop(enumMFRField* p_eField)
{
    uint8 bIdx = 0;
    
    if(strtYMMEFieldStack.bStackSize > 0)
    {
        strtYMMEFieldStack.bStackSize--;
        bIdx = strtYMMEFieldStack.bStackSize;
                
        *p_eField = strtYMMEFieldStack.eStackList[bIdx];
    }
}

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: 
*Descrtiption : 
*Input        : 
*Output       : 
------------------------------------------------------------------------------*/
static void getListString(enumMFRField eField, structMFRYMMESelectProfile* p_strtMFRVehSelectProfile, uint8 *p_strBuffer)
{
    uint16 sIdx = 0;
    uint16 sIdx_GUI = 0;
    enumSearchStatus eStatus = eSEARCH_NOTFOUND;
    
    for(sIdx = 0; sIdx < p_strtMFRVehSelectProfile->Lap DangemAmount; sIdx++)
    {
        eStatus = getYMMEFieldString_ML(p_strtMFRVehicleProfile, eField, p_strtMFRVehSelectProfile->eList[sIdx], p_strBuffer, (uint8) (CURRENT_LANGUAGE_ID + 1));
        if (eStatus == eSEARCH_FOUND)
        {
            GUI_Manager.p_strNameList[sIdx_GUI]= p_strBuffer;
            p_strBuffer = GetStrOffset(p_strBuffer, GetstrLenBuff(p_strBuffer) + 1);
            sIdx_GUI++;
        }
    }
}

/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: 
*Descrtiption : 
*Input        : 
*Output       : 
------------------------------------------------------------------------------*/
void MFRYMMECreateSelectList(structMFRYMMESelectProfile* p_strtMFRVehSelectProfile,
                         structMFRVinProfile * p_strtMFRVinProfile);
void MFRYMMECreateSelectList(structMFRYMMESelectProfile* p_strtMFRVehSelectProfile,
                             structMFRVinProfile * p_strtMFRVinProfile)
{
    uint8 bColum;
    uint8 *p_strBuffer =(uint8 *)GUI_Manager.p_strTextBuffer;
#if     (ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL)
    uint16   sNoItemBackup = p_strtMFRVehSelectProfile->Lap DangemAmount;
#endif
    
    memset(p_strBuffer, Null, 512);
    
    switch(p_strtMFRVehSelectProfile->eField)
    {
    case eMFR_FIELD_YEAR:
        bColum = 3;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_YEAR, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_LANGUAGE_ID + 1));
        break;
        
    case eMFR_FIELD_MAKE:
        bColum = 2;
#if     (ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL)
        if(p_ProtocolMakeList != null)
        {            
            p_strtMFRVehSelectProfile->Lap DangemAmount = GetQuantity_MakeListFollowProtocol(p_ProtocolMakeList);
            getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                      eMFR_FIELD_MAKE, 
                                      p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                      (uint16*)p_ProtocolMakeList, 
                                      GUI_Manager.p_strNameList,
                                      p_strBuffer,
                                      (uint8) (CURRENT_LANGUAGE_ID + 1));
        }
#else
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_MAKE, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_LANGUAGE_ID + 1));
#endif
        break;
        
    case eMFR_FIELD_MODEL:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  p_strtMFRVehSelectProfile->eField, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_LANGUAGE_ID + 1));
        break;
        
    case eMFR_FIELD_TRIM:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_TRIM, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_LANGUAGE_ID + 1));
        break;
        
    case eMFR_FIELD_BODY:
        bColum = 2;
        if(p_strtMFRVinProfile->eMake == emake_MERCEDES_BENZ)
        {
            getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                      eMFR_FIELD_BM, 
                                      p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                      p_strtMFRVehSelectProfile->eList, 
                                      GUI_Manager.p_strNameList,
                                      p_strBuffer,
                                      (uint8) (CURRENT_LANGUAGE_ID + 1));
        }
        else
        {
            getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                      eMFR_FIELD_BODY, 
                                      p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                      p_strtMFRVehSelectProfile->eList, 
                                      GUI_Manager.p_strNameList,
                                      p_strBuffer,
                                      (uint8) (CURRENT_LANGUAGE_ID + 1));
        }
        break;
        
    case eMFR_FIELD_ENGINE:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_ENGINE, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_LANGUAGE_ID + 1));
        break;
        
    case eMFR_FIELD_TRANSMISSION:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_TRANSMISSION, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_LANGUAGE_ID + 1));
        break;
        
    default:
        bColum = 2;
        break;
    }
    
    memset(VehicleInfoText, Null, MAX_CHAR_VEHICLE_INFO);
    getVehicleStringProfile(p_strtMFRVinProfile, 
                            VehicleInfoText, 
                            CURRENT_MEMORY_LANGUAGE);
    
    GUI_MenuForm_New_StringInit(GUI_Manager.p_strtGuiMnuFrm,
                                MLSelectVehicle[CURRENT_LANGUAGE_ID],
                                MLNext[CURRENT_LANGUAGE_ID],
                                MLBack[CURRENT_LANGUAGE_ID],
                                VehicleInfoText,
                                MLMenuInstruction[CURRENT_LANGUAGE_ID],
                                MLNull[CURRENT_LANGUAGE_ID],
                                GUI_Manager.p_strNameList,
                                GUI_TEXTMODE_NORMAL);
    
    GUI_MenuForm_New_DispInit(GUI_Manager.p_strtGuiMnuFrm,
                              p_strtMFRVehSelectProfile->Lap DangemAmount,
                              bColum,
                              (uint32)(Proc_GetParam()),
                              Proc_GetSelectionItem(),
                              (GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_NEXTPAGE | GUI_SCROLL_DISP_FORCE_PREVPAGE),
                              GUI_SELECT_ONE);
    GUI_WndSetTextAlign(&GUI_Manager.p_strtGuiMnuFrm->WndDescription,
                            GUI_TA_HCENTER);

#if     (ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL)
    p_strtMFRVehSelectProfile->Lap DangemAmount = sNoItemBackup;
#endif
    
    return;
}                     

/*------------------------------------------------------------------------------
*Engineer     : TienTN
*Historical   : 
*Function name: Proc_YMMESelection_BackHandler
*Descrtiption : Hanlde when user select back
*Input        : void
*Output       : void
*-----------------------------------------------------------------------------*/
static void Proc_YMMESelection_BackHandler(void)
{
    enumMFRField ePrevField = eMFR_FIELD_NONE;
    YMMEFieldStackPop(&ePrevField);
    
    backDataHandle(ePrevField, 
                   &strtYMMEEntryStack,
                   &strtYMMEFieldStack,
                   p_strtMFRVehicleProfileTemp, 
                   &g_strtMFRYMMESelectProfile);
    
    /*change to process data to get next step*/
    Proc_ChangeCmd(CMD_PROCESSING_DATA, 0, 0);
    
    return;
}


/*------------------------------------------------------------------------------
*Engineer     : Lap Danguong
*Historical   : November 20 2014
*Function name: DispConfirmVehicle
*Descrtiption : confirm vehicle information after user selection
*Input        : void
*Output       : structMFRVinProfile* p_strtCurrentProfile - pointer to selected YMME profile
*-----------------------------------------------------------------------------*/
static void DispConfirmVehicle(structMFRVinProfile* p_strtCurrentProfile)
{
    uint8* p_str = MLTextBuffer[CURRENT_LANGUAGE_ID];
//    uint8* p_strVehicleInfo = (uint8*)strSmallTextBuff;
    
    //get vehicle info as string
    memset(VehicleInfoText,
           null,
           sizeof(VehicleInfoText));
    getVehicleStringProfile(p_strtCurrentProfile, 
                            VehicleInfoText,
                            CURRENT_MEMORY_LANGUAGE);

    sprintf((char*)p_str, 
            "%s",
            (char*)MLSureSelectByEnterYesNo[CURRENT_LANGUAGE_ID]);
    /*display vehicle infor as center*/
    GUI_HighlightTextFormInit(GUI_Manager.p_strtGuiTxtFrm,
                              MLVehicleInfo_Title[CURRENT_LANGUAGE_ID], 
                              VehicleInfoText, 
                              MLTextBuffer[CURRENT_LANGUAGE_ID], 
                              MLNull[CURRENT_LANGUAGE_ID],
                              2, /*Yes or No*/
                              0); /*Select first item*/ 
    GUI_WndSetTextAlign(&GUI_Manager.p_strtGuiTxtFrm->WndInstruction,
                        GUI_TA_HVCENTER);
}




/*==============================================================================
                        PROCESS KEYS FOR 31x0E TOOLs
        
==============================================================================*/

/*------------------------------------------------------------------------------
*Engineer     : TienTN
*Historical   : 
*Function name: 
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void Proc_YMMESelection_OnEnterPressed(void)
{
    sint32 iSelectedIdx;
    enumbool eSelNextField = eTRUE;
    enumMFRMake eExMake = eMFR_MAKE_UNKNOWN;
    
    iSelectedIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
    if (iSelectedIdx == GUI_SELECTING_NEXTPAGE_IDX)
    {
        GUI_MenuSrollNextPage_New(GUI_Manager.p_strtGuiMnuFrm);
        GUI_Menu_New_Display();
    }
    else if (iSelectedIdx == GUI_SELECTING_PREVPAGE_IDX)
    {
        if (g_strtMFRYMMESelectProfile.eField == eMFR_FIELD_YEAR)
        {
            Proc_LeaveProc();
        }
        else
        {
            Proc_YMMESelection_BackHandler();
        }
    }
    else
    {
#if     (ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL)
        if (g_strtMFRYMMESelectProfile.eField == eMFR_FIELD_MAKE)
        {
            eExMake = *(p_ProtocolMakeList+iSelectedIdx);
            //check to see this make is valid in database, then jump to select next field
            eSelNextField = checkYMMEEnumMakeForNextField(&g_strtMFRYMMESelectProfile, 
                                                          eExMake, 
                                                          &iSelectedIdx);
        }
        //if need select next field
        if(eSelNextField == eTRUE)
        {
            pressFieldItemHandle(g_strtMFRYMMESelectProfile.eField, 
                                 iSelectedIdx,
                                 p_strtMFRVehicleProfileTemp, 
                                 &g_strtMFRYMMESelectProfile,
                                 &strtYMMEEntryStack,
                                 &strtYMMEFieldStack);
        }
        else
        {
            p_strtMFRVehicleProfileTemp->eMake = eExMake;
            p_strtMFRVehicleProfileTemp->ValidStatus = eMFR_VALID;
        }
#else        
        pressFieldItemHandle(g_strtMFRYMMESelectProfile.eField, iSelectedIdx,
                             p_strtMFRVehicleProfileTemp, &g_strtMFRYMMESelectProfile,
                             &strtYMMEEntryStack,
                             &strtYMMEFieldStack);
#endif
        
        /*change to process data to get next step*/
        Proc_ChangeCmd(CMD_PROCESSING_DATA, 0, 0);
        
    }
}

static void OBD31x0e_YMME_VehConfirm_PressedEnter(void)
{
    sint32 iSelectedIdx;
    iSelectedIdx = GUI_HighlightTextGetSelected();
    if(iSelectedIdx < 0)
    {
        iSelectedIdx = 0;
    }
    if(iSelectedIdx == 0)
    {
        //vehicle info is confirmed, set info into main vehicle YMME profile
        ToolManager_YMMEProfile_Set(p_strtMFRVehicleProfileTemp);
        //set Oil Reset set up
        ToolManager_OilResetSup_Set();
        //set battery reset set up
        ToolManager_BatteryResetSup_Set();
        
        //init vehicle profile for linking
//        ToolManager_VehicleProfile_Init();
        //then just leave process to come back to previous process
        Proc_LeaveProc();
    }
    else//vehicle is not confirmed
    {
        //reset temp buffer and select all again from beggining
        YMMESel_ProfileReset();
        //change to command  process data to select manual to select again
        Proc_ChangeCmd(CMD_PROCESSING_DATA, 0, 0);
        
    }
}
        
#define OBD31x0e_Proc_YMME_PressedSystem    (JumpToSystemMenu)
#define OBD31x0e_Proc_YMME_PressedMenu      (JumpToMainMenu)
/*------------------------------------------------------------------------------
*Engineer     : TienTN
*Historical   : 
*Function name: Proc_YMMESelKeyInit
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void OBD31x0e_Proc_YMMESelKeyInit(void)
{
    GUI_KeyHandlerReset();
    
    //hot keys
    HotKeyHandlerCommonProcess_Register(GUI_KEY_POWER_LINK|GUI_KEY_MENU|GUI_KEY_LD|GUI_KEY_DTC|GUI_KEY_SYSTEM|GUI_KEY_ERASE);
    
    switch (Proc_GetCurCmdID())
    {
    case CMD_DISP_MENU:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_Menu_New_OnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuNew_OnDown);
        
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_YMMESelection_OnEnterPressed);
//        GUI_KeyRegister(GUI_KEY_SYSTEM    , OBD31x0e_Proc_YMME_PressedSystem);
//        GUI_KeyRegister(GUI_KEY_MENU      , OBD31x0e_Proc_YMME_PressedMenu);
////        GUI_KeyRegister(GUI_KEY_DTC       , DTCHotKeyHandler);
////        GUI_KeyRegister(GUI_KEY_LD        , LDFFHotKeyHandler);
//
////        GUI_KeyRegister(GUI_KEY_ERASE     , EraseHotKeyHandler);
////        GUI_KeyRegister(GUI_KEY_POWER_LINK,LinkHotKeyHandler);
        break;
        //display vehicle confirm
    case PROC_SELECT_YMME_DISPLAY_CONFIRM:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_HighlightTextOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_HighlightTextOnDown);
        GUI_KeyRegister(GUI_KEY_ENTER, OBD31x0e_YMME_VehConfirm_PressedEnter);
//        GUI_KeyRegister(GUI_KEY_MENU      , OnMainMenuEnter);
//        GUI_KeyRegister(GUI_KEY_DTC       , DTCHotKeyHandler);
//        GUI_KeyRegister(GUI_KEY_LD        , LDFFHotKeyHandler);
//        GUI_KeyRegister(GUI_KEY_SYSTEM    , OnSystemMenuEnter);
//        GUI_KeyRegister(GUI_KEY_ERASE     , EraseHotKeyHandler);
//        GUI_KeyRegister(GUI_KEY_POWER_LINK,LinkHotKeyHandler);
        break;
                
    case CMD_DISPLAY_INVALID:
//        GUI_KeyRegister(GUI_KEY_MENU      , OnMainMenuEnter);
//        GUI_KeyRegister(GUI_KEY_DTC       , DTCHotKeyHandler);
//        GUI_KeyRegister(GUI_KEY_LD        , LDFFHotKeyHandler);
//        GUI_KeyRegister(GUI_KEY_SYSTEM    , OnSystemMenuEnter);
//        GUI_KeyRegister(GUI_KEY_ERASE     , EraseHotKeyHandler);
//        GUI_KeyRegister(GUI_KEY_POWER_LINK, LinkHotKeyHandler);
        break;
        
    default:
        GUI_KeyHandlerReset();
        break;
    }
    HwKeyEnable();
}

                             


/*==============================================================================
                                MACRO 
    Define Macro key function handler corresponding to different tools 
    and number of keys 

==============================================================================*/

                            
#define     Proc_YMMESelKeyInit     (OBD31x0e_Proc_YMMESelKeyInit)

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 
*Function name: Proc_YMMESelection
*Descrtiption : Display YMME selection for vehicle
                    
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_YMMESelection(void);
void Proc_YMMESelection(void)
{
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();
    
    if (blIsCmdChanged)
    {
        IMMonLedSetStatus(eFALSE);
        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
        
        Proc_YMMESelKeyInit();
        Proc_ProcCmdClearChanged();
    }
    
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        //reset temp buffer and select all again from beggining
        YMMESel_ProfileReset();
        //get current vehicle ymme profile
        if(ToolManager_YMMEProfile_VINString_Get(p_strtMFRVehicleProfileTemp->bVinString))
        {
            //call for VIN Decode if have VIN string
            Proc_ChangeCmd(CMD_PROC_YMME_VIN_DECODE,0,0);
        }
        else
        {
            Proc_ChangeCmd(CMD_PROCESSING_DATA,0,0);
        }
        break;
        //Decode VIN
    case CMD_PROC_YMME_VIN_DECODE:
        OBD2_VIN_Decode_Processing();
        break;
        
    case CMD_PROCESSING_DATA:
        MFRYMMEGetUserSelectList(p_strtMFRVehicleProfileTemp, 
                                 &g_strtMFRYMMESelectProfile,
                                 &strtYMMEFieldStack, 
                                 &strtYMMEEntryStack);
#if     (ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL)
        //in this case, above get user make list will get valid list from database
        //after user select Make, will validate the selected make with valid list
        //then go ahead to select next field or just stop after make
        p_ProtocolMakeList = MakeListFollowProtocol_Enum_Get(eOBD2Protocol);
#endif
        if (p_strtMFRVehicleProfileTemp->ValidStatus == eMFR_VALID)
        {
            Proc_ChangeCmd(PROC_SELECT_YMME_DISPLAY_CONFIRM, 0, 0);
        }
        else if (p_strtMFRVehicleProfileTemp->ValidStatus == eMFR_DATACELL_ERROR)
        {
            Proc_ChangeCmd(PROC_SELECT_YMME_DISPLAY_CONFIRM, 0, 0);
        }
        else
        {
            Proc_ChangeCmd(CMD_DISP_MENU, 0, 0);
        }
        break;
    case CMD_DISP_MENU:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                MFRYMMECreateSelectList(&g_strtMFRYMMESelectProfile,
                                        p_strtMFRVehicleProfileTemp);
            }
            GUI_Menu_New_Display();
            Proc_DataClearChanged();
        }
        break;
        
        //display confirm information
    case PROC_SELECT_YMME_DISPLAY_CONFIRM:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                DispConfirmVehicle(p_strtMFRVehicleProfileTemp);
            }
            GUI_HighlightTextDisplay();
            Proc_DataClearChanged();
        }
        break;
            
    case CMD_DISPLAY_INVALID:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                
            }
            GUI_TextDisplay();
            Proc_DataClearChanged();
        }
        break;
    default:
        break;
    }
}