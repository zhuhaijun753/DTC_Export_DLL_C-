/*******************************************************************************
*Engineer    : Lap Dangruong
*Date        : January 27 2015
*File        : Proc_Make_Selection.c
*Description : Process select Make, just select make and save into a temporary variable
*******************************************************************************/

/*******************************************************************************
================================================================================
INCLUDED FILES
================================================================================
*******************************************************************************/

#include <PlatFormType.h>
#include <GUIManager.h>

#include "KeyBoardApp.h"
#include    "Processes.h"
#include "OBDToolManager.h"


#include    "enums.h"
#include    "enums_CompDefine.h"

#include    "Common_Text_Database.h"
#include    "CommonKeyHandler.h"


/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
// Define used command in this process here, these value should not be in (SYS_CMD_ID)
// declared in SysProcess.h
#define     PROC_MAKE_SELECTION_DISPLAY_MAKE_LIST        (SYS_CMD_ID)(1001)
#define     UI_COMMAND_2        (SYS_CMD_ID)(1002)
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



#define     MAKE_SELECTION_LIST_COLUMN      (2)
/*==============================================================================
*                                 GLOBAL VARIABLEs
*=============================================================================*/
extern const uint16 * p_ProtocolMakeList;
extern const uint16* MakeListFollowProtocol_Enum_Get(enumProtocol eProtocol);
extern uint16 ProcessMakeListFollowProtocol_String(const uint16* p_MakeListEnum,
                                                   uint8 * p_strBuffer);


enumMake    eMakeTemp = eMake_UNKNOWN;


typedef  struct   __structMakeToManufacturerMapping
{
    enumMake            eMake;
    enumManufacturer    eManuf;
}structMakeToManufacturerMapping;

const structMakeToManufacturerMapping   strtMakeToManufacturerMapping[]=
{
    {eMake_AUDI_3,     eManufacturer_VOLKSWAGEN_14},
    {eMake_VOLKSWAGEN_39,     eManufacturer_VOLKSWAGEN_14},
    {eMake_VOLKSWAGEN_39,     eManufacturer_CHRYSLER_2},
    
    {eMake_BMW_4,     eManufacturer_BMW_1},
    {eMake_MINI_28,     eManufacturer_BMW_1},
    
    {eMake_CHRYSLER_8,     eManufacturer_CHRYSLER_2},
    {eMake_DODGE_10,     eManufacturer_CHRYSLER_2},
    {eMake_JEEP_20,     eManufacturer_CHRYSLER_2},
    {eMake_RAM_33,     eManufacturer_CHRYSLER_2},
    {eMake_SRT_37,     eManufacturer_CHRYSLER_2},
    {eMake_PLYMOUTH_31,     eManufacturer_CHRYSLER_2},
    {eMake_EAGLE_11,     eManufacturer_CHRYSLER_2},
    {eMake_FIAT_41,     eManufacturer_CHRYSLER_2},//TODO: miss make Fiat

    {eMake_FORD_12,     eManufacturer_FORD_3},
    {eMake_LINCOLN_24,     eManufacturer_FORD_3},
    {eMake_MERCURY_27,     eManufacturer_FORD_3},
    
    {eMake_AM_GENERAL_2,     eManufacturer_GM_4},
    {eMake_BUICK_5,     eManufacturer_GM_4},
    {eMake_CADILLAC_6,     eManufacturer_GM_4},
    {eMake_CHEVROLET_7,     eManufacturer_GM_4},
    {eMake_GEO_13,     eManufacturer_GM_4},
    {eMake_GMC_14,     eManufacturer_GM_4},
    {eMake_OLDSMOBILE_30,     eManufacturer_GM_4},
    {eMake_PONTIAC_32,     eManufacturer_GM_4},
    {eMake_SAAB_34,     eManufacturer_GM_4},
    {eMake_SATURN_35,     eManufacturer_GM_4},
    {eMake_DAEWOO_9,     eManufacturer_GM_4},
    {eMake_HUMMER_16,     eManufacturer_GM_4},
    
    {eMake_ACURA_1,     eManufacturer_HONDA_5},
    {eMake_HONDA_15,     eManufacturer_HONDA_5},
    
    {eMake_HYUNDAI_17,     eManufacturer_HYUNDAI_6},
    
    {eMake_KIA_21,     eManufacturer_KIA_8},
    
    {eMake_ISUZU_42,     eManufacturer_ISUZU_16},
    {eMake_ISUZU_42,     eManufacturer_GM_4},
    {eMake_ISUZU_42,     eManufacturer_HONDA_5},
    
    {eMake_JAGUAR_19,     eManufacturer_JAGUAR_7},
    {eMake_LAND_ROVER_22,     eManufacturer_LAND_ROVER_9},
    {eMake_MAZDA_25,     eManufacturer_MAZDA_10},
    
    {eMake_MERCEDES_BENZ_26,     eManufacturer_MERCEDES_BENZ_11},
//    {eMake_MERCEDES_26,     eManufacturer_MERCEDES_BENZ_11},
    
    {eMake_MITSUBISHI_43,     eManufacturer_MITSUBISHI_17},
//    {eMake_MITSUBISHI_45,     eManufacturer_CHRYSLER_2},
    
    {eMake_NISSAN_29,     eManufacturer_NISSAN_12},
    {eMake_INFINITI_18,     eManufacturer_NISSAN_12},
    
    {eMake_PORSCHE_44,     eManufacturer_PORSCHE_20},
    {eMake_SMART_45,     eManufacturer_MERCEDES_BENZ_11},
    
    {eMake_SUBARU_46,     eManufacturer_SUBARU_18},
    {eMake_SUZUKI_47,     eManufacturer_SUZUKI_19},
    
    {eMake_LEXUS_23,     eManufacturer_TOYOTA_13},
    {eMake_TOYOTA_38,     eManufacturer_TOYOTA_13},
    {eMake_SCION_36,     eManufacturer_TOYOTA_13},
    
    {eMake_VOLVO_40,     eManufacturer_VOLVO_15},    
    
//    {eMake_UNKNOWN,     eManufacturer_UNKNOWN},
};





const void* const MLSelectMake[NUM_LANG_SUPPORT] =
DefineMLText
(
    "Select Make",
    "Seleccionar Marca",
    "Choisir Marque"
);


#define     MLMakeSelction_DisplayMakeList_Title            (MLSelectMake)
#define     MLMakeSelction_DisplayMakeList_Des              (MLNull)
#define     MLMakeSelction_DisplayMakeList_Instr            (MLMenuInstruction)
#define     MLMakeSelction_DisplayMakeList_Footer           (MLNull)


/*==============================================================================
                        FUCNTIONs SUPPORT FOR DISPLAYING
        
==============================================================================*/
static void Proc_Make_Selection_CreateMakeList(void)
{
    uint8 *p_strBuffer =(uint8 *)GUI_Manager.p_strTextBuffer;
    uint16  sNoItem;
    
    p_ProtocolMakeList = MakeListFollowProtocol_Enum_Get(PROTOCOL_NO);
    sNoItem = ProcessMakeListFollowProtocol_String(p_ProtocolMakeList,
                                                                                  p_strBuffer);
    
    GUI_MenuForm_New_StringInit(GUI_Manager.p_strtGuiMnuFrm,
                                MLMakeSelction_DisplayMakeList_Title[CURRENT_LANGUAGE_ID],
                                MLNext[CURRENT_LANGUAGE_ID],
                                MLBack[CURRENT_LANGUAGE_ID],
                                MLMakeSelction_DisplayMakeList_Des[CURRENT_LANGUAGE_ID],
                                MLMakeSelction_DisplayMakeList_Instr[CURRENT_LANGUAGE_ID],
                                MLMakeSelction_DisplayMakeList_Footer[CURRENT_LANGUAGE_ID],
                                GUI_Manager.p_strNameList,
                                GUI_TEXTMODE_NORMAL);
    
    GUI_MenuForm_New_DispInit(GUI_Manager.p_strtGuiMnuFrm,
                              sNoItem,
                              MAKE_SELECTION_LIST_COLUMN,
                              (uint32)(Proc_GetParam()),
                              Proc_GetSelectionItem(),
                              (GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_NEXTPAGE | GUI_SCROLL_DISP_FORCE_PREVPAGE),
                              GUI_SELECT_ONE);
    GUI_WndSetTextAlign(&GUI_Manager.p_strtGuiMnuFrm->WndDescription,
                            GUI_TA_HCENTER);
}

/*==============================================================================
                        FUCNTIONs SUPPORT FOR PROCESSING DATA
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2715
*Function name: Make_Selection_Make_Temp_Clear
*Descrtiption : clear variable to store make
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
uint8   YMME_Selection_Make_To_Manufacturer_List(enumManufacturer *p_ManuList,
                                                 enumMake   eMake);
uint8   YMME_Selection_Make_To_Manufacturer_List(enumManufacturer *p_ManuList,
                                                 enumMake   eMake)
{
    uint8   bNoManuf = 0, bLoop;
    for(bLoop = 0; bLoop<countof(strtMakeToManufacturerMapping); bLoop++)
    {
        if(strtMakeToManufacturerMapping[bLoop].eMake == eMake)
        {
            *p_ManuList = strtMakeToManufacturerMapping[bLoop].eManuf;
            p_ManuList++;
            bNoManuf++;
        }
    }
    return bNoManuf;
}


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2715
*Function name: Make_Selection_Make_Temp_Clear
*Descrtiption : clear variable to store make
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void Make_Selection_Make_Temp_Clear(void)
{
    eMakeTemp = eMake_UNKNOWN;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2715
*Function name: Make_Selection_Make_Temp_IsValid
*Descrtiption : check to see whether make temp is valid (has been selected)
*Input        : None
*Output       : enumbool - status of make temp
*-----------------------------------------------------------------------------*/
enumbool    Make_Selection_Make_Temp_IsValid(void);
enumbool    Make_Selection_Make_Temp_IsValid(void)
{
    if((eMakeTemp != eMFR_MAKE_UNKNOWN)
       &&(eMakeTemp != eMFR_MAKE_OTHERS)
           &&(eMakeTemp != eMFR_MAKE_MAX)
               )
    {
        return eTRUE;
    }
    else
    {
        return eFALSE;
    }
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2715
*Function name: Make_Selection_Make_Temp_Get
*Descrtiption : return make has been selected
*Input        : None
*Output       : enumMake - Make has been selected
*-----------------------------------------------------------------------------*/
enumMake    Make_Selection_Make_Temp_Get(void);
enumMake    Make_Selection_Make_Temp_Get(void)
{
    return eMakeTemp;
}


/*==============================================================================
                        PROCESS KEYS FOR 31x0E TOOLs
        
==============================================================================*/
static void Proc_Make_Selection_DisplayMakeList_PressedEnter(void)
{
    sint32 iSelectedIdx;
    
    iSelectedIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
    if (iSelectedIdx == GUI_SELECTING_NEXTPAGE_IDX)
    {
        GUI_MenuSrollNextPage_New(GUI_Manager.p_strtGuiMnuFrm);
        GUI_Menu_New_Display();
    }
    else if (iSelectedIdx == GUI_SELECTING_PREVPAGE_IDX)
    {
        Make_Selection_Make_Temp_Clear();
        Proc_LeaveProc();
    }
    else
    {
        eMakeTemp = *(p_ProtocolMakeList+iSelectedIdx);
        if(Make_Selection_Make_Temp_IsValid())
        {
            Proc_LeaveProc();
        }
        else//should not match this case
        {
            Proc_ChangeCmd(CMD_INIT_PROC,0,0);
        }
    }
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 
*Function name: OBD31x0e_Proc_Make_Selection_KeyInit
*Descrtiption : process key for Make selection
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
static void OBD31x0e_Proc_Make_Selection_KeyInit(void)
{
    GUI_KeyHandlerReset();
    
    //hot keys
    HotKeyHandlerCommonProcess_Register(GUI_KEY_POWER_LINK|GUI_KEY_MENU|GUI_KEY_LD|GUI_KEY_DTC|GUI_KEY_SYSTEM|GUI_KEY_ERASE);
    
    switch (Proc_GetCurCmdID())
    {
    case PROC_MAKE_SELECTION_DISPLAY_MAKE_LIST:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_Menu_New_OnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuNew_OnDown);
        
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_Make_Selection_DisplayMakeList_PressedEnter);
        break;
      
    default:
        break;
    }
    
    HwKeyEnable();
}

/*==============================================================================
                                MACRO 
    Define Macro key function handler corresponding to different tools 
    and number of keys 

==============================================================================*/

#define     Proc_Make_Selection_KeyInit     (OBD31x0e_Proc_Make_Selection_KeyInit)


/*==============================================================================
                                MAIN PROCESS 

==============================================================================*/
void Proc_Make_Selection(void);
void Proc_Make_Selection(void)
{
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();
    
    if (blIsCmdChanged)
    {
        IMMonLedSetStatus(eFALSE);
        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
        
        Proc_Make_Selection_KeyInit();
        Proc_ProcCmdClearChanged();
    }
    
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        Make_Selection_Make_Temp_Clear();
        Proc_ChangeCmd(PROC_MAKE_SELECTION_DISPLAY_MAKE_LIST,0,0);
        break;
        
    case PROC_MAKE_SELECTION_DISPLAY_MAKE_LIST:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                Proc_Make_Selection_CreateMakeList();
            }
            GUI_Menu_New_Display();
            
            Proc_DataClearChanged();
        }
        break;
        
    default:
        break;
    }
}

