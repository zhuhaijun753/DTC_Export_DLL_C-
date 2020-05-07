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

#include    "enums.h"
#include    "enums_CompDefine.h"


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
#define     CMD_PROC_YMME_LOAD_MEMORY        (SYS_CMD_ID)(1003)
#define     CMD_PROC_YMME_MEMORY_VEHICLE_LIST_MENU        (SYS_CMD_ID)(1004)
#define     CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO        (SYS_CMD_ID)(1005)
#define     UI_COMMAND_6        (SYS_CMD_ID)(1006)
#define     UI_COMMAND_7        (SYS_CMD_ID)(1007)
#define     UI_COMMAND_8        (SYS_CMD_ID)(1008)
#define     UI_COMMAND_9        (SYS_CMD_ID)(1009)
#define     UI_COMMAND_10       (SYS_CMD_ID)(1010)
#define     UI_COMMAND_11       (SYS_CMD_ID)(1011)
#define     UI_COMMAND_12       (SYS_CMD_ID)(1012)
#define     UI_COMMAND_13       (SYS_CMD_ID)(1013)
#define     UI_COMMAND_14       (SYS_CMD_ID)(1014)




extern void Proc_OBD2_AutoRelink_Set(void);

/*******************************************************************************
================================================================================
                            GLOBAL VARIABLES
================================================================================
*******************************************************************************/
extern structMenuItem  strtMenuItemTemp[NUMBER_SYSTEM_LIST_MAX];
extern void* MLTextTemp[NUMBER_SYSTEM_LIST_MAX][NUM_LANG_SUPPORT];
extern structMenu        strtSystemMenuTemp;
#define     p_strtMenuListTemp        (&strtSystemMenuTemp)


#define		NUMBER_VEHICLE_IN_MEMORY_MAX		(3)
static structVehicleProfileIndex	strtVehProfIndex[NUMBER_VEHICLE_IN_MEMORY_MAX];
uint8	bNumValidVeh = 0;



#define     eOBD2Protocol       (ToolManager_SystemHandler_OBD2_Protocol_Get())

#define     ENABLE_MAKE_LIST_FOLLOWING_PROTOCOL     (1)

//this variable used to handle make list follow protocol, just use for selecting Make
const uint16 * p_ProtocolMakeList = null;

const uint16 eMakeVPWList[] =
{
    eMake_BUICK_5,
    eMake_CADILLAC_6,
    eMake_CHEVROLET_7,
    eMake_CHRYSLER_8,
    eMake_DAEWOO_9,
    eMake_DODGE_10,
    eMake_EAGLE_11,
    eMake_RAM_33,
    eMake_SRT_37,
    eMake_GEO_13,
    eMake_GMC_14,
    eMake_HUMMER_16,
    eMake_AM_GENERAL_2,
    eMake_ISUZU_42,
    eMake_JEEP_20,
    eMake_OLDSMOBILE_30,
    eMake_PLYMOUTH_31,
    eMake_PONTIAC_32,
    eMake_SATURN_35,
    
    eMake_ACURA_1,
    eMake_AUDI_3,
    eMake_BMW_4,
    eMake_FIAT_41,
    eMake_FORD_12,
    eMake_HONDA_15,
    eMake_HYUNDAI_17,
    eMake_INFINITI_18,
    eMake_JAGUAR_19,
    eMake_KIA_21,
    eMake_LAND_ROVER_22,
    eMake_LEXUS_23,
    eMake_LINCOLN_24,
    eMake_MAZDA_25,
    eMake_MERCEDES_BENZ_26,
    eMake_MERCURY_27,
    eMake_MINI_28,
    eMake_MITSUBISHI_43,
    eMake_NISSAN_29,
    eMake_PORSCHE_44,
    eMake_SAAB_34,
    eMake_SCION_36,
    eMake_SMART_45,
    eMake_SUBARU_46,
    eMake_SUZUKI_47,
    eMake_TOYOTA_38,
    eMake_VOLKSWAGEN_39,
    eMake_VOLVO_40,
    
    eMake_OTHERS,
    
    eMake_MAX,
};

const uint16 eMakePWMList[] =
{
    eMake_FORD_12,
    eMake_LINCOLN_24,
    eMake_MAZDA_25,
    eMake_MERCURY_27,
    
    eMake_ACURA_1,
    eMake_AUDI_3,
    eMake_BMW_4,
    eMake_BUICK_5,
    eMake_CADILLAC_6,
    eMake_CHEVROLET_7,
    eMake_CHRYSLER_8,
    eMake_DAEWOO_9,
    eMake_DODGE_10,
    eMake_EAGLE_11,
    eMake_FIAT_41,
    eMake_GEO_13,
    eMake_GMC_14,
    eMake_RAM_33,
    eMake_SRT_37,
    eMake_HONDA_15,
    eMake_HUMMER_16,
    eMake_HYUNDAI_17,
    eMake_INFINITI_18,
    eMake_ISUZU_42,
    eMake_JAGUAR_19,
    eMake_JEEP_20,
    eMake_KIA_21,
    eMake_LAND_ROVER_22,
    eMake_LEXUS_23,
    eMake_MERCEDES_BENZ_26,
    eMake_MINI_28,
    eMake_MITSUBISHI_43,
    eMake_NISSAN_29,
    eMake_OLDSMOBILE_30,
    eMake_PLYMOUTH_31,
    eMake_PONTIAC_32,
    eMake_PORSCHE_44,
    eMake_SAAB_34,
    eMake_SATURN_35,
    eMake_SCION_36,
    eMake_SMART_45,
    eMake_SUBARU_46,
    eMake_SUZUKI_47,
    eMake_TOYOTA_38,
    eMake_VOLKSWAGEN_39,
    eMake_VOLVO_40,
    
    eMake_OTHERS,
    
    eMake_MAX,
};

const uint16 eMakeCANList[] =
{
    eMake_ACURA_1,
    eMake_AUDI_3,
    eMake_BMW_4,
    eMake_BUICK_5,
    eMake_CADILLAC_6,
    eMake_CHEVROLET_7,
    eMake_CHRYSLER_8,
    eMake_DAEWOO_9,
    eMake_DODGE_10,
    eMake_EAGLE_11,
    eMake_FIAT_41,
    eMake_FORD_12,
    eMake_GEO_13,
    eMake_GMC_14,

    eMake_HONDA_15,
    eMake_HUMMER_16,
    eMake_HYUNDAI_17,
    eMake_INFINITI_18,
    eMake_ISUZU_42,
    eMake_JAGUAR_19,
    eMake_JEEP_20,
    eMake_KIA_21,
    eMake_LAND_ROVER_22,
    eMake_LEXUS_23,
    eMake_LINCOLN_24,
    eMake_MAZDA_25,
    eMake_MERCEDES_BENZ_26,
    eMake_MERCURY_27,
    eMake_MINI_28,
    eMake_MITSUBISHI_43,
    eMake_NISSAN_29,
    eMake_OLDSMOBILE_30,
    eMake_PLYMOUTH_31,
    eMake_PONTIAC_32,
    eMake_PORSCHE_44,
    eMake_RAM_33,
    eMake_SAAB_34,
    eMake_SATURN_35,
    eMake_SCION_36,
    eMake_SMART_45,
    eMake_SRT_37,
    eMake_SUBARU_46,
    eMake_SUZUKI_47,
    eMake_TOYOTA_38,
    eMake_VOLKSWAGEN_39,
    eMake_VOLVO_40,
    
    eMake_OTHERS,
    
    eMake_MAX,
};

const uint16 eMakeKW2000List[] =
{
    eMake_ACURA_1,
    eMake_AUDI_3,
    eMake_BMW_4,
    eMake_BUICK_5,
    eMake_CADILLAC_6,
    eMake_CHEVROLET_7,
    eMake_DAEWOO_9,
    eMake_GEO_13,
    eMake_GMC_14,
    eMake_HUMMER_16,
    eMake_AM_GENERAL_2,
    eMake_HYUNDAI_17,
    eMake_KIA_21,
    eMake_MINI_28,
    eMake_OLDSMOBILE_30,
    eMake_PONTIAC_32,
    eMake_PORSCHE_44,
    eMake_SAAB_34,
    eMake_SATURN_35,
    eMake_SUBARU_46,
    eMake_SUZUKI_47,
    eMake_VOLKSWAGEN_39,
    
    eMake_CHRYSLER_8,
    eMake_DODGE_10,
    eMake_EAGLE_11,
    eMake_FIAT_41,
    eMake_RAM_33,
    eMake_SRT_37,
    eMake_FORD_12,
    eMake_HONDA_15,
    eMake_INFINITI_18,
    eMake_ISUZU_42,
    eMake_JAGUAR_19,
    eMake_JEEP_20,
    eMake_LAND_ROVER_22,
    eMake_LEXUS_23,
    eMake_LINCOLN_24,
    eMake_MAZDA_25,
    eMake_MERCEDES_BENZ_26,
    eMake_MERCURY_27,
    eMake_MITSUBISHI_43,
    eMake_NISSAN_29,
    eMake_PLYMOUTH_31,
    eMake_SCION_36,
    eMake_SMART_45,
    eMake_TOYOTA_38,
    eMake_VOLVO_40,
    
    eMake_OTHERS,
    
    eMake_MAX,
};

const uint16 eMakeISO9141List[] =
{
    eMake_ACURA_1,
    eMake_AUDI_3,
    eMake_BMW_4,
    eMake_BUICK_5,
    eMake_CADILLAC_6,
    eMake_CHEVROLET_7,
    eMake_CHRYSLER_8,
    eMake_DAEWOO_9,
    eMake_DODGE_10,
    eMake_EAGLE_11,
    eMake_FIAT_41,
    eMake_GEO_13,
    eMake_GMC_14,
    eMake_RAM_33,
    eMake_SRT_37,
    eMake_HONDA_15,
    eMake_HUMMER_16,
    eMake_HYUNDAI_17,
    eMake_INFINITI_18,
    eMake_JAGUAR_19,
    eMake_JEEP_20,
    eMake_KIA_21,
    eMake_LAND_ROVER_22,
    eMake_LEXUS_23,
    eMake_MAZDA_25,
    eMake_MERCEDES_BENZ_26,
    eMake_MINI_28,
    eMake_MITSUBISHI_43,
    eMake_NISSAN_29,
    eMake_OLDSMOBILE_30,
    eMake_PLYMOUTH_31,
    eMake_PONTIAC_32,
    eMake_PORSCHE_44,
    eMake_SAAB_34,
    eMake_SATURN_35,
    eMake_SCION_36,
    eMake_SUBARU_46,
    eMake_SUZUKI_47,
    eMake_TOYOTA_38,
    eMake_VOLKSWAGEN_39,
    eMake_VOLVO_40,
    eMake_FORD_12,
    eMake_ISUZU_42,
    eMake_LINCOLN_24,
    eMake_MERCURY_27,
    eMake_SMART_45,
    
    eMake_OTHERS,
    
    eMake_MAX,
};

const uint16 eMakeDefaultList[] =
{
    eMake_ACURA_1,
    eMake_AM_GENERAL_2,
    eMake_AUDI_3,
    eMake_BMW_4,
    eMake_BUICK_5,
    eMake_CADILLAC_6,
    eMake_CHEVROLET_7,
    eMake_CHRYSLER_8,
    eMake_DAEWOO_9,
    eMake_DODGE_10,
    eMake_EAGLE_11,
    eMake_FIAT_41,
    eMake_FORD_12,
    eMake_GEO_13,
    eMake_GMC_14,
    eMake_HONDA_15,
    eMake_HUMMER_16,
    eMake_HYUNDAI_17,
    eMake_INFINITI_18,
    eMake_ISUZU_42,
    eMake_JAGUAR_19,
    eMake_JEEP_20,
    eMake_KIA_21,
    eMake_LAND_ROVER_22,
    eMake_LEXUS_23,
    eMake_LINCOLN_24,
    eMake_MAZDA_25,
    eMake_MERCEDES_BENZ_26,
    eMake_MERCURY_27,
    eMake_MINI_28,
    eMake_MITSUBISHI_43,
    eMake_NISSAN_29,
    eMake_OLDSMOBILE_30,
    eMake_PLYMOUTH_31,
    eMake_PONTIAC_32,
    eMake_PORSCHE_44,
    eMake_RAM_33,
    eMake_SAAB_34,
    eMake_SATURN_35,
    eMake_SCION_36,
    eMake_SMART_45,
    eMake_SRT_37,
    eMake_SUBARU_46,
    eMake_SUZUKI_47,
    eMake_TOYOTA_38,
    eMake_VOLKSWAGEN_39,
    eMake_VOLVO_40,
    
    eMake_OTHERS,
    
    eMake_MAX,
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

const void* const MLNonameVehicle[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Vehicle %d",
    "Veh�culo %d",
    "V�hicule %d"
);

const void* const MLNewVehicle[NUM_LANG_SUPPORT] =
DefineMLText
(
    "New Vehicle",
    "Veh�culo nuevo",
    "Nouveau v�hicule"
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
uint8	NumberVehicleInMemory_Get(void);
uint8	NumberVehicleInMemory_Get(void)
{
	return	bNumValidVeh;
}



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
    /*copy VIN string from vehicle ymme profile to temp buff*/
    if(ToolManager_YMMEProfile_VINString_Get(p_strtMFRVehicleProfileTemp->bVinString))
    {     
		/*call function to decode VIN*/
        decodeVINtoVehicleInfo(sManuMakeList,
                               p_strtMFRVehicleProfileTemp);
        
        if(p_strtMFRVehicleProfileTemp->ValidStatus == eMFR_VALID)
        {
            /*Feb0215 Lap Dang modified, need to select transmission manual*/
            p_strtMFRVehicleProfileTemp->ValidStatus = eMFR_INVALID;
            g_strtMFRYMMESelectProfile.eField = eMFR_FIELD_TRANSMISSION;
            Proc_ChangeCmd(CMD_PROCESSING_DATA,0,0);
        }
        else
        {
            /*reset temp buffer if decode not valid*/
            memset(p_strtMFRVehicleProfileTemp, Null, sizeof(structMFRVinProfile));
			/*jump to display list vehicle*/
			Proc_JumpToProcCmd(PROC_YMME_SELECTION, CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO);
            
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
        eStatus = getYMMEFieldString_ML(p_strtMFRVehicleProfileTemp,
                                        eMFR_FIELD_MAKE, 
                                        (*p_MakeListEnum), 
                                        p_strBuffer, 
                                        (uint8) (CURRENT_MEMORY_LANGUAGE));
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
        eStatus = getYMMEFieldString_ML(p_strtMFRVehicleProfileTemp,
                                        eField, p_strtMFRVehSelectProfile->eList[sIdx], 
                                        p_strBuffer, 
                                        (uint8) (CURRENT_MEMORY_LANGUAGE));
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
    /*June0415 Lap Dang added to disable interrupt*/
	ToolManager_EnterSystemMode();
	
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
                                  (uint8) (CURRENT_MEMORY_LANGUAGE));
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
                                      (uint8) (CURRENT_MEMORY_LANGUAGE));
        }
#else
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_MAKE, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_MEMORY_LANGUAGE));
#endif
        break;
        
    case eMFR_FIELD_MODEL:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_MODEL, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_MEMORY_LANGUAGE));
        break;
        
    case eMFR_FIELD_TRIM:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_TRIM, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_MEMORY_LANGUAGE));
        break;
        
    case eMFR_FIELD_BODY:
        bColum = 2;
        if(p_strtMFRVinProfile->eMake == eMake_MERCEDES_BENZ_26)
        {
            getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                      eMFR_FIELD_BM, 
                                      p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                      p_strtMFRVehSelectProfile->eList, 
                                      GUI_Manager.p_strNameList,
                                      p_strBuffer,
                                      (uint8) (CURRENT_MEMORY_LANGUAGE));
        }
        else
        {
            getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                      eMFR_FIELD_BODY, 
                                      p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                      p_strtMFRVehSelectProfile->eList, 
                                      GUI_Manager.p_strNameList,
                                      p_strBuffer,
                                      (uint8) (CURRENT_MEMORY_LANGUAGE));
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
                                  (uint8) (CURRENT_MEMORY_LANGUAGE));
        break;
        
    case eMFR_FIELD_TRANSMISSION:
        bColum = 2;
        getYMMEFieldStringList_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_TRANSMISSION, 
                                  p_strtMFRVehSelectProfile->Lap DangemAmount, 
                                  p_strtMFRVehSelectProfile->eList, 
                                  GUI_Manager.p_strNameList,
                                  p_strBuffer,
                                  (uint8) (CURRENT_MEMORY_LANGUAGE));
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
	
	/*call function to leave system mode*/
	ToolManager_LeaveSystemMode();
    
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
		
	/*if user select BACK at year selection, back to previous process*/
	if(ePrevField == eMFR_FIELD_NONE)
	{
		/*jump to display list vehicle*/
		Proc_JumpToProcCmd(PROC_YMME_SELECTION, CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO);
	}
	else
	{
		backDataHandle(ePrevField, 
					   &strtYMMEEntryStack,
					   &strtYMMEFieldStack,
					   p_strtMFRVehicleProfileTemp, 
					   &g_strtMFRYMMESelectProfile);
		
		/*change to process data to get next step*/
		Proc_ChangeCmd(CMD_PROCESSING_DATA, 0, 0);
    }
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

static enumbool Vehicle_YMMEProfile_IsValid(structMFRVinProfile* p_strtMFRVinProfile)
{
    if ((p_strtMFRVinProfile->ValidStatus == eMFR_VALID)
        &&(p_strtMFRVinProfile->eYear != eYear_OTHERS_65534)
            &&(p_strtMFRVinProfile->eMake != eMake_OTHERS_65534)
                   )
    {
        return eTRUE;
    }
    else
    {
        return eFALSE;
    }
}
/*this function print the vehicle info to string*/
static void MFRVinProfileToSimpleString(structMFRVinProfile* p_strtMFRVinProfile, 
										uint8* p_str, 
										uint8 bOtherVehIndx)
{
	uint8 bBuffTemp[VIN_SIZE+1];
    uint8 bBuffTemp1[VIN_SIZE*2];
	/*June0415 Lap Dang added to disable interrupt*/
	ToolManager_EnterSystemMode();
	
	(*p_str) = '\0';
	p_str += strlen((char*)p_str);
    /*March0314 V22g, Lap Dang modified for select year other*/
    if (Vehicle_YMMEProfile_IsValid(p_strtMFRVinProfile))
    {
		if ((p_strtMFRVinProfile->eYear >= eYear_1996_16) 
                && (p_strtMFRVinProfile->eYear <= eYear_2015_35))
        {
            getYMMEFieldString_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_Year,
								  p_strtMFRVinProfile->eYear,
								  p_str,
								  CURRENT_MEMORY_LANGUAGE);
            strcat((char*)p_str, " ");
            p_str += strlen((char*)p_str);
        }
		if ((p_strtMFRVinProfile->eMake != eMake_UNKNOWN) 
			&&(p_strtMFRVinProfile->eMake != eMake_OTHERS_65534)
				&&(p_strtMFRVinProfile->eMake != eMake_MAX_65535)
			)
		{
			getYMMEFieldString_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_Make,
								  p_strtMFRVinProfile->eMake,
								  p_str,
								  CURRENT_MEMORY_LANGUAGE);
            strcat((char*)p_str, " ");
            p_str += strlen((char*)p_str);
		}
		if ((p_strtMFRVinProfile->eModel != eModel_UNKNOWN) 
			&& (p_strtMFRVinProfile->eModel != eModel_OTHERS_65534)
				&& (p_strtMFRVinProfile->eModel != eModel_MAX_65535)
					)
		{
			getYMMEFieldString_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_Model,
								  p_strtMFRVinProfile->eModel,
								  p_str,
								  CURRENT_MEMORY_LANGUAGE);
            strcat((char*)p_str, " ");
            p_str += strlen((char*)p_str);
		}
	}
	else
	{
		if ((p_strtMFRVinProfile->eYear >= eYear_1996_16) 
                && (p_strtMFRVinProfile->eYear <= eYear_2015_35))
        {
            getYMMEFieldString_ML(p_strtMFRVinProfile,
                                  eMFR_FIELD_Year,
								  p_strtMFRVinProfile->eYear,
								  p_str,
								  CURRENT_MEMORY_LANGUAGE);
            strcat((char*)p_str, " ");
            p_str += strlen((char*)p_str);
        }
        xsprintf(p_str,MLNonameVehicle[CURRENT_LANGUAGE_ID],bOtherVehIndx);
	}
	/*if VIN number valid*/
	if(IsVINValid(p_strtMFRVinProfile->bVinString))
    {
        p_str += strlen((char*)p_str);
        memcpy((char*)bBuffTemp, p_strtMFRVinProfile->bVinString, VIN_SIZE);
        bBuffTemp[VIN_SIZE] = 0;
        sprintf((char*)p_str, " (%s)", bBuffTemp);
        p_str += strlen((char*)p_str);
        (*p_str) = null;
    }
	
	/*call function to leave system mode*/
	ToolManager_LeaveSystemMode();
}

static void LinkModeVehicleListMenu_Init(void)
{
	uint8	bLoop, bNoValidIdx=0, bNumberItem = 0;
	uint8 *pString =(uint8*)MLCommonTextBuffer_3[CURRENT_LANGUAGE_ID];
	
	MLCommonTextBuffer_3_Clear();
	
#if 1
	/*set pointer buffer to store string*/
	pString = MLCommonTextBuffer_3[CURRENT_LANGUAGE_ID];

	/*get number valid vehicle in memory*/
	bNumValidVeh = VehicleData_List_Stored_Get(strtVehProfIndex,
											   NUMBER_VEHICLE_IN_MEMORY_MAX);
	/*set item 1 is new vehicle*/
	strtMenuItemTemp[bNumberItem].eProc = PROC_CURRENT;
	strtMenuItemTemp[bNumberItem].eCmd = CMD_CURRENT;
	strtMenuItemTemp[bNumberItem].MLItemStr = MLNewVehicle;
	strtMenuItemTemp[bNumberItem].blEnable = eTRUE;
		
	bNumberItem++;
	for(bLoop=0; bLoop<bNumValidVeh; bLoop++)
	{
		/*get string of ymme profile*/
		if(!Vehicle_YMMEProfile_IsValid(&(strtVehProfIndex[bLoop].strtVehData_YMMEProfile)))
		{
			bNoValidIdx++;
		}
		MFRVinProfileToSimpleString(&(strtVehProfIndex[bLoop].strtVehData_YMMEProfile), 
									  pString, 
									  bNoValidIdx);
		/*assign pointer for string*/
		strtMenuItemTemp[bNumberItem].eProc = PROC_CURRENT;
		strtMenuItemTemp[bNumberItem].eCmd = CMD_CURRENT;
		MLTextTemp[bLoop][CURRENT_LANGUAGE_ID] = pString;
		strtMenuItemTemp[bNumberItem].MLItemStr = MLTextTemp[bLoop];
		strtMenuItemTemp[bNumberItem].blEnable = eTRUE;
		
		bNumberItem++;
		/*increase offset*/
		pString = GetStrOffset(pString, GetstrLenBuff(pString) + 2);
	}
	
	strtMenuItemTemp[bNumberItem].eProc = PROC_NONE;
	strtMenuItemTemp[bNumberItem].blEnable = eFALSE;
	
	//set strings for display
	p_strtMenuListTemp->MLTitle = MLSelectVehicle;
	p_strtMenuListTemp->MLFooter = MLPressMenuForMainMenu;
	
	p_strtMenuListTemp->MLInstruction = MLMenuInstruction;
	p_strtMenuListTemp->p_strtMenuItemList = (structMenuItem const*)strtMenuItemTemp;
	
	/*init menu screen*/
	GUI_MenuInit(p_strtMenuListTemp,
				 1,
				 (uint32)(Proc_GetParam()),
				 Proc_GetSelectionItem(),
				 UI_SCROLL_MODE);
#else
	
//	/*get number valid vehicle in memory*/
//	bNumValidVeh = VehicleData_List_Stored_Get(strtVehProfIndex,
//											   NUMBER_VEHICLE_IN_MEMORY_MAX);
//	/*set item 1 is new vehicle*/
//	GUI_Manager.p_strNameList[bNumberItem]= MLNewVehicle[CURRENT_LANGUAGE_ID];
//	
//	bNumberItem++;
//	for(bLoop=0; bLoop<bNumValidVeh; bLoop++)
//	{
//		/*get string of ymme profile*/
//		if(!Vehicle_YMMEProfile_IsValid(&(strtVehProfIndex[bLoop].strtVehData_YMMEProfile)))
//		{
//			bNoValidIdx++;
//		}
//		MFRVinProfileToSimpleString(&(strtVehProfIndex[bLoop].strtVehData_YMMEProfile), 
//									  pString, 
//									  bNoValidIdx);
//		/*assign pointer for string*/
//		GUI_Manager.p_strNameList[bNumberItem]= pString;
//		bNumberItem++;
//		/*increase offset*/
//		pString = GetStrOffset(pString, GetstrLenBuff(pString) + 2);
//	}
//	/*init string for menu form*/
//	GUI_MenuForm_New_StringInit(GUI_Manager.p_strtGuiMnuFrm,
//                                MLSelectVehicle[CURRENT_LANGUAGE_ID],
//                                MLNull[CURRENT_LANGUAGE_ID],
//                                MLNull[CURRENT_LANGUAGE_ID],
//                                MLNull[CURRENT_LANGUAGE_ID],
//                                MLMenuInstruction[CURRENT_LANGUAGE_ID],
//                                MLPressMenuForMainMenu[CURRENT_LANGUAGE_ID],
//                                GUI_Manager.p_strNameList,
//                                GUI_TEXTMODE_NORMAL);
//    /*init form*/
//    GUI_MenuForm_New_DispInit(GUI_Manager.p_strtGuiMnuFrm,
//                              bNumberItem,
//                              1,
//                              (uint32)(Proc_GetParam()),
//                              Proc_GetSelectionItem(),
//                              (GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_INDEX),
//                              GUI_SELECT_ONE);
#endif
	
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Danguong
*Historical   : November 20 2014
*Function name: DispConfirmVehicle
*Descrtiption : confirm vehicle information after user selection
*Input        : void
*Output       : structMFRVinProfile* p_strtCurrentProfile - pointer to selected YMME profile
*-----------------------------------------------------------------------------*/
static void MemoryVehicleListMenu_Init(void)
{
	uint8	bLoop, bNoValidIdx=0;
	uint8 *pString =(uint8*)MLCommonTextBuffer_3[CURRENT_LANGUAGE_ID];
	
	MLCommonTextBuffer_3_Clear();
	
	for(bLoop=0; bLoop<bNumValidVeh; bLoop++)
	{
		/*get string of ymme profile*/
		if(!Vehicle_YMMEProfile_IsValid(&(strtVehProfIndex[bLoop].strtVehData_YMMEProfile)))
		{
			bNoValidIdx++;
		}
		MFRVinProfileToSimpleString(&(strtVehProfIndex[bLoop].strtVehData_YMMEProfile), 
									  pString, 
									  bNoValidIdx);
		/*assign pointer for string*/
		GUI_Manager.p_strNameList[bLoop]= pString;
		/*increase offset*/
		pString = GetStrOffset(pString, GetstrLenBuff(pString) + 2);
	}
	/*init string for menu form*/
	GUI_MenuForm_New_StringInit(GUI_Manager.p_strtGuiMnuFrm,
                                MLSelectVehicle[CURRENT_LANGUAGE_ID],
                                MLNull[CURRENT_LANGUAGE_ID],
                                MLNull[CURRENT_LANGUAGE_ID],
                                MLNull[CURRENT_LANGUAGE_ID],
                                MLMenuInstruction[CURRENT_LANGUAGE_ID],
                                MLPressMenuForMainMenu[CURRENT_LANGUAGE_ID],
                                GUI_Manager.p_strNameList,
                                GUI_TEXTMODE_NORMAL);
    /*init form*/
    GUI_MenuForm_New_DispInit(GUI_Manager.p_strtGuiMnuFrm,
                              bLoop,
                              1,
                              (uint32)(Proc_GetParam()),
                              Proc_GetSelectionItem(),
                              (GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_INDEX),
                              GUI_SELECT_ONE);
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
//        if (g_strtMFRYMMESelectProfile.eField == eMFR_FIELD_YEAR)
//        {
//			/*jump to display list vehicle*/
//			Proc_JumpToProcCmd(PROC_YMME_SELECTION, CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO);
////            Proc_LeaveProc();
//        }
//        else
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


static void Proc_YMMESelection_LinkModeVehicleList_PressedEnter(void)
{
	/*get the menu index which user select*/
#if 1
	sint32 iSelectedIdx = GUI_Menu_CurrentOptionIndex_Get();
#else
	sint32 iSelectedIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
#endif
	
	if(iSelectedIdx<(bNumValidVeh+1))
	{
		if(bNumValidVeh == 0)
		{
			YMMESel_ProfileReset();
			
		}
		else
		{
			memcpy((char*)p_strtMFRVehicleProfileTemp,
					(char*)&strtVehProfIndex[iSelectedIdx-1].strtVehData_YMMEProfile,
					sizeof(structMFRVinProfile));
		}
		/*change to command  process data to select manual to select again*/
		Proc_EnterCmd(CMD_PROCESSING_DATA, 0, 0);
	}
}

static void JumpToFirstProcessReview(void)
{
	/*if OBD1 vehicle*/
	if(VehicleData_OBD1_IsValid())
	{
		/*change to review OBD1*/
		ToolManager_SystemState_EnterReviewOBD1Mode();
	}
	else
	{
		/*change to display system menu with summary of dtc in memory mode*/
		Proc_EnterProc(PROC_SYSTEM_MENU, CMD_INIT_PROC);
	}
}

static void Proc_YMMESelection_MemoryVehicleList_PressedEnter(void)
{
	/*get the menu index which user select*/
	sint32 iSelectedIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
	
	if(iSelectedIdx<countof(strtVehProfIndex))
	{
		/*call function to get data from memory and copy to vehicle data global buffer*/
		/*load all data of this vehicle from memory to global buffer*/
		VehicleData_Get_Memory(strtVehProfIndex[iSelectedIdx].bOrder);
		if(VehicleData_IsValid())
		{
			ToolManager_VehicleDataValid_Set(eTRUE);
		}
		/*jump to first process displaying in review mode*/
		JumpToFirstProcessReview();
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
        /*vehicle info is confirmed, set info into main vehicle YMME profile*/
        ToolManager_YMMEProfile_Set(p_strtMFRVehicleProfileTemp);
        /*set Oil Reset set up*/
        ToolManager_OilResetSup_Set();
        /*set battery reset set up*/
        ToolManager_BatteryResetSup_Set();
		
		/*save YMME Profile*/
        VehicleData_Save_Memory(eSAVETYPE_VINPROFILE);
		
		/*init vehicle profile for linking*/
		ToolManager_VehicleProfile_Init();
		
        /*then just leave process to come back to previous process*/
        Proc_LeaveProc();

    }
    else/*vehicle is not confirmed*/
    {
        /*reset temp buffer and select all again from beggining*/
        YMMESel_ProfileReset();
		/*jump to display list vehicle*/
		Proc_JumpToProcCmd(PROC_YMME_SELECTION, CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO);
        
    }
}
        
#define OBD31x0e_Proc_YMME_PressedSystem    (JumpToSystemMenu)
#define OBD31x0e_Proc_YMME_PressedMenu      (HotkeyHandlerFunction_KeyMENU)
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
    HotKeyHandlerCommonProcess_Register(GUI_KEY_POWER_LINK|GUI_KEY_MENU);
    
    switch (Proc_GetCurCmdID())
    {
    case CMD_DISP_MENU:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_Menu_New_OnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuNew_OnDown);
        
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_YMMESelection_OnEnterPressed);

        break;
		
	case CMD_PROC_YMME_MEMORY_VEHICLE_LIST_MENU:
		GUI_KeyRegister(GUI_KEY_UP   , GUI_Menu_New_OnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuNew_OnDown);
		
		GUI_KeyRegister(GUI_KEY_ENTER, Proc_YMMESelection_MemoryVehicleList_PressedEnter);
//		/*reset key handler*/
//		GUI_KeyRegister(GUI_KEY_DTC, GUI_KeyHandleNone);
//		GUI_KeyRegister(GUI_KEY_LD, GUI_KeyHandleNone);
//		GUI_KeyRegister(GUI_KEY_ERASE, GUI_KeyHandleNone);
//		GUI_KeyRegister(GUI_KEY_SYSTEM, GUI_KeyHandleNone);
		break;
		
	case CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO:
#if 1
		GUI_KeyRegister(GUI_KEY_UP   , GUI_MenuOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuOnDown);
		
#else
//		GUI_KeyRegister(GUI_KEY_UP   , GUI_Menu_New_OnUp);
//        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuNew_OnDown);
#endif
		
		GUI_KeyRegister(GUI_KEY_ENTER, Proc_YMMESelection_LinkModeVehicleList_PressedEnter);
		break;
		
		
        //display vehicle confirm
    case PROC_SELECT_YMME_DISPLAY_CONFIRM:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_HighlightTextOnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_HighlightTextOnDown);
        GUI_KeyRegister(GUI_KEY_ENTER, OBD31x0e_YMME_VehConfirm_PressedEnter);

        break;
                
    case CMD_DISPLAY_INVALID:

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
		/*check to see memory mode or link mode*/
		if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
		{
			//get current vehicle ymme profile
			if(ToolManager_YMMEProfile_VINString_Get(p_strtMFRVehicleProfileTemp->bVinString))
			{
				//call for VIN Decode if have VIN string
				Proc_ChangeCmd(CMD_PROC_YMME_VIN_DECODE,0,0);
			}
			else
			{
#if 1/*same rule as old tool*/
				/*jump to display list vehicle*/
				Proc_JumpToProcCmd(PROC_YMME_SELECTION, CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO);
#else
				Proc_ChangeCmd(CMD_PROCESSING_DATA,0,0);
#endif
			}
		}
		else/*OBD2 memory mode*/
		{
			/*change to getting vehicle data in memory to display for selection*/
			Proc_ChangeCmd(CMD_PROC_YMME_LOAD_MEMORY,0,0);
		}
        break;
		
		/*load memory then process data for next corresponding step*/
	case CMD_PROC_YMME_LOAD_MEMORY:
		/*get list of vehicle in memory*/
		bNumValidVeh = VehicleData_List_Stored_Get(strtVehProfIndex,
												   NUMBER_VEHICLE_IN_MEMORY_MAX);
		/*if not any valid*/
		if(bNumValidVeh==0)
		{
			/*just change to OBD2 display data process*/
			Proc_EnterProc(PROC_OBD2_DISPLAY_DATA, CMD_DISPLAY_INVALID);
		}
		/*else if just has 1 valid vehicle in memory*/
		else if(bNumValidVeh==1)
		{
			/*load all data of this vehicle from memory to global buffer*/
			VehicleData_Get_Memory(strtVehProfIndex[0].bOrder);
			/*jump to first process displaying in review mode*/
			JumpToFirstProcessReview();
		}
		/*more than 1 vehicle valid*/
		else
		{
			Proc_ChangeCmd(CMD_PROC_YMME_MEMORY_VEHICLE_LIST_MENU,0,0);
		}
		break;
		/*display list of vehicle for selection*/
	case CMD_PROC_YMME_MEMORY_VEHICLE_LIST_MENU:
		if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
				/*re-initialize all vehicle data*/
				VehicleData_Initialization();
				/*set status of vehicle data to invalid*/
				ToolManager_VehicleDataValid_Set(eFALSE);
				
  				/*init screen*/
                MemoryVehicleListMenu_Init();
            }
            GUI_Menu_New_Display();
            Proc_DataClearChanged();
        }
		break;
		
        //Decode VIN
    case CMD_PROC_YMME_VIN_DECODE:
        OBD2_VIN_Decode_Processing();
        break;
     
		/*display vehicle list selection in link mode*/
	case CMD_PROC_YMME_DISP_VEHICLE_LIST_INFO:
		if (ToolManager_SystemState_Get() == SYSTEM_STATE_LINK_OBD2_MODE)
		{
			if (Proc_DataIsChanged())
			{
				if (blIsCmdChanged)
				{
					/*init screen*/
					LinkModeVehicleListMenu_Init();
				}
#if 1
				/*display menu screen*/
				GUI_MenuDisplay();
#else
				//            GUI_Menu_New_Display();
#endif
				Proc_DataClearChanged();
			}
		}
		else
		{
			/*change to getting vehicle data in memory to display for selection*/
			Proc_ChangeCmd(CMD_PROC_YMME_LOAD_MEMORY,0,0);
		}
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
            Proc_EnterCmd(PROC_SELECT_YMME_DISPLAY_CONFIRM, 0, 0);
        }
        else if (p_strtMFRVehicleProfileTemp->ValidStatus == eMFR_DATACELL_ERROR)
        {
            Proc_EnterCmd(PROC_SELECT_YMME_DISPLAY_CONFIRM, 0, 0);
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