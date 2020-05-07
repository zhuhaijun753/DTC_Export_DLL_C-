/*******************************************************************************
*Engineer    : Lap Dangruong
*Date        : January 17 2015
*File        : Proc_DLC_Locator.c
*Description : Processing DLC Locator
                Let user seelct YMME to see the poLap Dangion of the DLC on the vehicle                

*******************************************************************************/
/*############################################################################*/
/*
================================================================================
INCLUDED FILES
================================================================================
*/
#include <PlatFormType.h>

#include <GUIManager.h>

#include    "TimerApp.h"
#include    "KeyBoardApp.h"
#include    "Processes.h"
#include    "OBDToolManager.h"

#include    "Common_Text_Database.h"
#include    "CommonKeyHandler.h"

//#include "StorageMemoryInterface.h"
//#include    <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Manager.h>

#include <YMMESelection.h>
//#include    <1_Application\3_User_Interface\3_UI_Processes\Processes\05_VIN_Decode\VinDecode.h>

#include    <1_Application\3_User_Interface\3_UI_Processes\Processes\08_DLC_Locator\DLCLocator.h>



extern const uint16 * p_ProtocolMakeList;
extern structYMMEEntryStack strtYMMEEntryStack;
extern structYMMEFieldStack strtYMMEFieldStack;

//extern uint8 VehicleInfoText[MAX_CHAR_VEHICLE_INFO];

extern structMFRYMMESelectProfile    g_strtMFRYMMESelectProfile;
extern structMFRVinProfile g_strtMFRVehicleProfileTemp;//this just temp buff for selection
#define     p_strtVehProfileTemp    (&g_strtMFRVehicleProfileTemp)
#define     strtVehProfileTemp      (g_strtMFRVehicleProfileTemp)

#define     p_strtSelectProfile     (&g_strtMFRYMMESelectProfile)
#define     strtSelectProfile       (g_strtMFRYMMESelectProfile)

extern const uint16* MakeListFollowProtocol_Enum_Get(enumProtocol eProtocol);
extern void MFRYMMECreateSelectList(structMFRYMMESelectProfile* p_strtMFRVehSelectProfile,
                                    structMFRVinProfile * p_strtMFRVinProfile);

extern void YMMEFieldStackPop(enumMFRField* p_eField);


/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
// Define used command in this process here, these value should not be in (SYS_CMD_ID)
// declared in SysProcess.h
#define     PROC_DLC_LOCATOR_DISPLAY_SELECT_LIST        (SYS_CMD_ID)(1001)
#define     PROC_DLC_LOCATOR_DISPLAY_LOCATOR_INFO        (SYS_CMD_ID)(1002)
#define     PROC_DLC_LOCATOR_DISPLAY_NO_LOCATION_INFO        (SYS_CMD_ID)(1003)
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



#define     DLC_LOCATOR_TIME_FLASH_POLap DangION     (1)



typedef struct
{
    uint8   eGroup;
    uint8   eType;
} structGroupTypeMapping;

typedef enum __enumDLCProfileType
{
	eDLC_PROFILE_UNKNOWN	=	0,
	eDLC_PROFILE_1      	=	1,
    eDLC_PROFILE_2      	=	2,
    eDLC_PROFILE_3      	=	3,
    eDLC_PROFILE_4      	=	4,
	
	eDLC_PROFILE_MAX    	=	0xFF,
}enumDLCProfileType;

const structGroupTypeMapping strtGroupTypeMapping[] =
{
    {.eGroup     = eGroup_Audi_VW,      .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Chrysler,     .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Fiat,         .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Ford,         .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Freightliner, .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_GM,           .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Hyundai_Kia,  .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Isuzu,        .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Madza,        .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Mitsubishi,   .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Nissan,       .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Porsche,      .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_RollsRoyce,   .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Subaru,       .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Suzuki,       .eType = eDLC_PROFILE_1},
    {.eGroup     = eGroup_Volvo,        .eType = eDLC_PROFILE_1},
    
    {.eGroup     = eGroup_BMW_Mini,     .eType = eDLC_PROFILE_2},
    
    {.eGroup     = eGroup_Honda,        .eType = eDLC_PROFILE_3},
    {.eGroup     = eGroup_Toyota,       .eType = eDLC_PROFILE_3},
    
    {.eGroup     = eGroup_Mercedes,     .eType = eDLC_PROFILE_4},   
    
    {.eGroup     = eGroup_UNKNOWN,      .eType = eDLC_PROFILE_UNKNOWN},
    {.eGroup     = eGroup_MAX,          .eType = eDLC_PROFILE_MAX},
};


/*******************************************************************************
================================================================================
                            GLOBAL VARIABLES
================================================================================
*******************************************************************************/

structMFRDLCLocatorInfo     strtDLCLocatorInfo;
#define     p_strtDLCLocatorInfo        (&strtDLCLocatorInfo)



const void* const MLStringAccessFmt[NUM_LANG_SUPPORT] =
{
   "Access: %s",
   "Acceso: %s",
   "Acc�s: %s"
};
const void* const MLStringCommentFmt[NUM_LANG_SUPPORT] =
{
   "Comments: %s",
   "Comentarios: %s ",
   "Commentaires: %s "
};

const void* const MLStringAccessCommentFmt[NUM_LANG_SUPPORT] =
{
   "Access: %s\nComments: %s",
   "Acceso: %s\nComentarios: %s ",
   "Acc�s: %s\nCommentaires: %s "
};

#define     ML_DLC_Locator_DisplayInfo_Title            (MLCommonTextBuffer_1)
#define     ML_DLC_Locator_DisplayInfo_Title_Clear()        (MLCommonTextBuffer_1_Clear())
#define     ML_DLC_Locator_DisplayInfo_Access           (MLCommonTextBuffer_2)
#define     ML_DLC_Locator_DisplayInfo_Comment          (MLCommonRamBuff)
#define     ML_DLC_Locator_DisplayInfo_Footer           (MLPressMenuForMainMenu)
                                       

#define     RAW_ACCESS_STRING_SIZE_MAX      (200)
#define     RAW_STRING_ACCESS_COMMENT_ADDR      (MLCommonTextBuff_3_Pointer_Get())

const void* const MLDLCLocatorTitle[NUM_LANG_SUPPORT] =
DefineMLText
(
    "DLC Locator",
    "Ubicaciones del conector de diagn�stico",
    "Localisateur de connecteur de diagnostic"
);
const void* const MLNoDLCInfo[NUM_LANG_SUPPORT] =
DefineMLText
(
    "No DLC information",
    "No hay informaci�n del DLC",
	"Aucune information sur le connecteur de diagnostic"
);

#define     ML_DLC_Locator_DisplayNoInfo_Title          (MLDLCLocatorTitle)
#define     ML_DLC_Locator_DisplayNoInfo_Instr          (MLNull)
#define     ML_DLC_Locator_DisplayNoInfo_Body           (MLNoDLCInfo)
#define     ML_DLC_Locator_DisplayNoInfo_Footer         (MLPressMenuForMainMenu)

/*==============================================================================
                        FUCNTIONs SUPPORT FOR DISPLAYING
        
==============================================================================*/
static void Proc_DLC_Locator_DisplayInfo_Prepare_TextStringForDisplay(void)
{
    //title - vechile info
    ML_DLC_Locator_DisplayInfo_Title_Clear();
    getVehicleStringProfile(&strtVehProfileTemp, 
                            ML_DLC_Locator_DisplayInfo_Title[CURRENT_LANGUAGE_ID]);
#if 1
    //set access to null
    xsprintf(ML_DLC_Locator_DisplayInfo_Access[CURRENT_LANGUAGE_ID],
             MLNull[CURRENT_LANGUAGE_ID]);
    //set comment field to store both access and comment
    xsprintf(ML_DLC_Locator_DisplayInfo_Comment[CURRENT_LANGUAGE_ID],
             MLStringAccessCommentFmt[CURRENT_LANGUAGE_ID],
             p_strtDLCLocatorInfo->strAccess,
             p_strtDLCLocatorInfo->strComment);

#else
    //access string
    xsprintf(ML_DLC_Locator_DisplayInfo_Access[CURRENT_LANGUAGE_ID],
             MLStringAccessFmt[CURRENT_LANGUAGE_ID],
             p_strtDLCLocatorInfo->strAccess);
    //comment string
    xsprintf(ML_DLC_Locator_DisplayInfo_Comment[CURRENT_LANGUAGE_ID],
             MLStringCommentFmt[CURRENT_LANGUAGE_ID],
             p_strtDLCLocatorInfo->strComment);
#endif
}

static void Proc_DLC_Locator_Process_Flash_PoLap Dangion(void)
{
    if (SystemTimer_Timeout_Get())
    {
        INN_GUI_DLCLocator_UpdateImage(p_strtDLCLocatorInfo->eMFRDLCPos);
        //set timing for flashing the poLap Dangion
        SystemTimer_Timeout_Set(DLC_LOCATOR_TIME_FLASH_POLap DangION);
    }
}




/*==============================================================================
                        FUCNTIONs SUPPORT FOR PROCESSING DATA
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Tien Nguyen
*Historical   : 
*Function name: 
*Descrtiption : 
*Input        : 
*Output       : 
------------------------------------------------------------------------------*/
static enumMFRField getLastField_DLC(enumMakeGroup eGroup)
{
    enumMFRField  eField = eMFR_FIELD_NONE;
    enumDLCProfileType eProfileType = eDLC_PROFILE_UNKNOWN;
    uint8 bExIdx = 0;
    
    while(strtGroupTypeMapping[bExIdx].eGroup != eGroup_MAX)
    {
        if (strtGroupTypeMapping[bExIdx].eGroup == eGroup)
        {
            eProfileType = strtGroupTypeMapping[bExIdx].eType;
            break;
        }
        bExIdx++;
    }

    if (eProfileType != eDLC_PROFILE_UNKNOWN)
    {
        switch (eProfileType)
        {
        case eDLC_PROFILE_1:
            eField = eMFR_FIELD_MODEL;
            break;
        case eDLC_PROFILE_2:
            eField = eMFR_FIELD_TRIM;
            break;
        case eDLC_PROFILE_3:
            eField = eMFR_FIELD_ENGINE;
            break;
        case eDLC_PROFILE_4:
            eField = eMFR_FIELD_ENGINE;
            break;
        }
    }
    
    return eField;
}



static void Proc_DLC_Locator_AllTempBuff_Clear(void)
{
    memset(&strtYMMEEntryStack, Null, sizeof(structYMMEEntryStack));
    memset(&strtYMMEFieldStack, Null, sizeof(structYMMEFieldStack));
//    memset(VehicleInfoText, Null, MAX_CHAR_VEHICLE_INFO);
    memset(p_strtVehProfileTemp, Null, sizeof(structMFRVinProfile));
    memset(p_strtSelectProfile, null, sizeof(structMFRYMMESelectProfile));
    //reset locator info
    memset(p_strtDLCLocatorInfo, null, sizeof(strtDLCLocatorInfo));
    p_strtDLCLocatorInfo->strAccess = RAW_STRING_ACCESS_COMMENT_ADDR;
    p_strtDLCLocatorInfo->strComment = RAW_STRING_ACCESS_COMMENT_ADDR+RAW_ACCESS_STRING_SIZE_MAX;
    
}

static void Proc_DLC_Locator_Processing_YMME_Display(void)
{
    enumbool eSelNextField = eTRUE;
    enumMake eExMake = eMake_UNKNOWN;
    enumMakeGroup eGroup = eGroup_UNKNOWN;
    
    //get user select list with current selected field
    MFRYMMEGetUserSelectList(p_strtVehProfileTemp, 
                             p_strtSelectProfile,
                             &strtYMMEFieldStack, 
                             &strtYMMEEntryStack);
    
    //if has been selecting Make
    if (p_strtSelectProfile->eField == eMFR_FIELD_MAKE)
    {
        p_ProtocolMakeList = MakeListFollowProtocol_Enum_Get(PROTOCOL_NO);
    }
    
    if((p_strtSelectProfile->Lap DangemAmount == 1)
       &&(p_strtSelectProfile->eField == eMFR_FIELD_ENGINE)
           )
    {
        p_strtVehProfileTemp->ValidStatus = eMFR_VALID;
        
        //no need to display confirm vehicle, so no need to get text info here
//        memset(VehicleInfoText, Null, MAX_CHAR_VEHICLE_INFO);
//        getVehicleStringProfile(p_strtVehProfileTemp, 
//                                VehicleInfoText);
    }
    //check to see if complete selecting YMME
    if (p_strtVehProfileTemp->ValidStatus == eMFR_VALID)
    {
        //should display screen one moment please... here during getting DLC info
        
        //call function to get DLC Locator Info
        if(DLCLocatorInfo_Get(p_strtVehProfileTemp,
                              CURRENT_MEMORY_LANGUAGE,
                              p_strtDLCLocatorInfo))
        {
            Proc_ChangeCmd(PROC_DLC_LOCATOR_DISPLAY_LOCATOR_INFO, 0, 0);
        }
        else
        {
            Proc_ChangeCmd(PROC_DLC_LOCATOR_DISPLAY_NO_LOCATION_INFO, 0, 0);
        }
        
    }
    else//display ymme selection list
    {
        Proc_ChangeCmd(PROC_DLC_LOCATOR_DISPLAY_SELECT_LIST, 0, 0);
    }
}


static void Proc_DLC_Locator_Select_List_BackHandler(void)
{
    enumMFRField ePrevField = eMFR_FIELD_NONE;
    YMMEFieldStackPop(&ePrevField);
    
    backDataHandle(ePrevField, 
                   &strtYMMEEntryStack,
                   &strtYMMEFieldStack,
                   p_strtVehProfileTemp, 
                   p_strtSelectProfile);
    
    /*change to process data to get next step*/
    Proc_ChangeCmd(PROC_DLC_LOCATOR_DISPLAY_SELECT_LIST, 0, 0);
    
    return;
}
/*==============================================================================
                        PROCESS KEYS FOR 31x0E TOOLs
        
==============================================================================*/
static void Proc_DLC_Locator_Select_List_PressEnter(void)
{
    sint32 iSelectedIdx = GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtGuiMnuFrm);
    enumbool eSelNextField = eTRUE;
    enumMFRMake eExMake = eMFR_MAKE_UNKNOWN;
    static enumMFRField eLastField = eMFR_FIELD_NONE;
    enumMakeGroup eGroup = eGroup_UNKNOWN;
    
    if (iSelectedIdx == GUI_SELECTING_NEXTPAGE_IDX)
    {
        GUI_MenuSrollNextPage_New(GUI_Manager.p_strtGuiMnuFrm);
        GUI_Menu_New_Display();
    }
    else if (iSelectedIdx == GUI_SELECTING_PREVPAGE_IDX)
    {
        if (p_strtSelectProfile->eField == eMFR_FIELD_YEAR)
        {
            Proc_LeaveProc();
        }
        else
        {
            Proc_DLC_Locator_Select_List_BackHandler();
        }
    }
    else
    {
        //if current field is make
        if (p_strtSelectProfile->eField == eMFR_FIELD_MAKE)
        {
            eLastField = eMFR_FIELD_NONE;
            eExMake = *(p_ProtocolMakeList+iSelectedIdx);
            //check to see this make is valid in database, then jump to select next field
            eSelNextField = checkYMMEEnumMakeForNextField(&strtSelectProfile, 
                                                          eExMake, 
                                                          &iSelectedIdx);
            //get last field for chosing YMME in DLC locator
            if(eSelNextField == eTRUE)
            {
                eGroup = getMakeGroupFromMake(eExMake);
                eLastField = getLastField_DLC(eGroup);
            }
        }
        
        if(eSelNextField == eTRUE)
        {
            if (p_strtSelectProfile->eField == eLastField)
            {
                p_strtVehProfileTemp->ValidStatus = eMFR_VALID;
            }
            //set item field value to profile
            pressFieldItemHandle(p_strtSelectProfile->eField, 
                                 iSelectedIdx,
                                 p_strtVehProfileTemp, 
                                 p_strtSelectProfile,
                                 &strtYMMEEntryStack,
                                 &strtYMMEFieldStack);
        }
        else
        {
            p_strtVehProfileTemp->eMake = eExMake;
            p_strtVehProfileTemp->ValidStatus = eMFR_VALID;
        }
        
        //call for processing data and jump to next display (select next field, or display dlc info)
        Proc_DLC_Locator_Processing_YMME_Display();
    }
}

static void OBD31x0e_Proc_DLC_Locator_KeyInit(void)
{
    GUI_KeyHandlerReset();
    //hot keys
    HotKeyHandlerCommonProcess_Register(GUI_KEY_POWER_LINK|GUI_KEY_MENU|GUI_KEY_LD|GUI_KEY_DTC|GUI_KEY_SYSTEM|GUI_KEY_ERASE);
    switch (Proc_GetCurCmdID())
    {
        //display YMME select list
    case PROC_DLC_LOCATOR_DISPLAY_SELECT_LIST:
        GUI_KeyRegister(GUI_KEY_UP   , GUI_Menu_New_OnUp);
        GUI_KeyRegister(GUI_KEY_DOWN , GUI_MenuNew_OnDown);
        
        GUI_KeyRegister(GUI_KEY_ENTER, Proc_DLC_Locator_Select_List_PressEnter);
        break;
        
        //display locator poLap Dangion, access, comment
    case PROC_DLC_LOCATOR_DISPLAY_LOCATOR_INFO:
        GUI_KeyRegister(GUI_KEY_UP   , INN_GUI_DLCLocatorScrollUp);
        GUI_KeyRegister(GUI_KEY_DOWN , INN_GUI_DLCLocatorScrollDown);
        
        break;   
        
    default:
        break;
    }
    //important --> enable keys
    HwKeyEnable();
}

/*==============================================================================
                                MACRO 
    Define Macro key function handler corresponding to different tools 
    and number of keys 

==============================================================================*/

                            
#define     Proc_DLC_Locator_KeyInit     (OBD31x0e_Proc_DLC_Locator_KeyInit)

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 
*Function name: Proc_DLC_Locator
*Descrtiption : Process for select and display DLC poLap Dangion
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void Proc_DLC_Locator(void);
void Proc_DLC_Locator(void)
{
    enumbool blIsCmdChanged;
    blIsCmdChanged = Proc_ProcCmdIsChanged();
    
    if (blIsCmdChanged)
    {
        IMMonLedSetStatus(eFALSE);
        GUI_IconDispTypeChange(ICON_DISP_MINIMIZE);
        
        Proc_DLC_Locator_KeyInit();
        Proc_ProcCmdClearChanged();
    }
    
    switch(Proc_GetCurCmdID())
    {
    case CMD_INIT_PROC:
        Proc_DLC_Locator_AllTempBuff_Clear();        
        //call function to processing data for displaying
        Proc_DLC_Locator_Processing_YMME_Display();
        break;
        
    case PROC_DLC_LOCATOR_DISPLAY_SELECT_LIST:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                MFRYMMECreateSelectList(p_strtSelectProfile,
                                        p_strtVehProfileTemp);
            }
            GUI_Menu_New_Display();
            
            Proc_DataClearChanged();
        }
        break;
        
    case PROC_DLC_LOCATOR_DISPLAY_LOCATOR_INFO:
        if (Proc_DataIsChanged())
        {
            if (blIsCmdChanged)
            {
                GUI_IconDispTypeChange(ICON_DISP_NONE);
                
                Proc_DLC_Locator_DisplayInfo_Prepare_TextStringForDisplay();
                INN_GUI_DLCLocatorInit(ML_DLC_Locator_DisplayInfo_Title,
                                       ML_DLC_Locator_DisplayInfo_Access,
                                       ML_DLC_Locator_DisplayInfo_Comment,
                                       ML_DLC_Locator_DisplayInfo_Footer
                                       );
            }
            INN_GUI_DLCLocatorDisplay();
            //set timing for flashing the poLap Dangion
            SystemTimer_Timeout_Set(DLC_LOCATOR_TIME_FLASH_POLap DangION);
            
            Proc_DataClearChanged();   
        }
        else
        {
            Proc_DLC_Locator_Process_Flash_PoLap Dangion();
        }
        break;
        
    case PROC_DLC_LOCATOR_DISPLAY_NO_LOCATION_INFO:
        if (Proc_DataIsChanged())
        {
            if(blIsCmdChanged)
            {
                GUI_TextInit(ML_DLC_Locator_DisplayNoInfo_Title, 
                             ML_DLC_Locator_DisplayNoInfo_Instr, 
                             ML_DLC_Locator_DisplayNoInfo_Body, 
                             ML_DLC_Locator_DisplayNoInfo_Footer
                                 );
                
            }
            GUI_TextDisplay();

            Proc_DataClearChanged();
        }
        break;
        
    default:
        break;    
    }
  
}
