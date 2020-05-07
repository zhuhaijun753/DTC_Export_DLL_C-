/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUI_MANAGER_H__
#define __GUI_MANAGER_H__

#include <string.h>
#include <stdio.h>
#include <PlatFormType.h>

#include "GuiType.h"
#include "GuiLcdDriver.h"
#include "Font.h"
#include "GuiWindow.h"
#include "GuiDraw.h"
#include "GuiCore.h"
#include "GuiString.h"
#include "GuiMenuForm.h"
#include "GuiTextForm.h"
#include "GuiHighlightTextForm.h"
#include "GuiFlashScrnForm.h"
#include "GuiDTCForm.h"
#include "GuiMenuForm.h"
#include "GuiInfoValueList.h"
#include "GuiInfoImageForm.h"
#include "GuiIcons.h"
#include "GuiDigitSelectionForm.h"
#include "GuiGraph.h"
#include "GuiProgressBarForm.h"
#include "GuiLogo.h"
//Nov1414 Lap Dang added as TranLuu resource
#include "INNGuiTextForm.h"
#include "INNGuiTextResult.h"
//Dec0814 TranL added
#include "INNGuiInputTextForm.h"
#include "INNGuiDLCLocatorForm.h"
//Dec0814 TranL added as TungNguyen resource
#include "INN_GuiTextForm.h"
#include "INN_GuiInfoValueForm.h"
#include "INN_GuiMenuForm.h"
#include "Common_Text_Database.h"
#include    "InnovaCommonEnum.h"


#include "2_Middle\0_Middle_Utilities\MLStringUtilities.h"
#include "2_Middle\4_User_Input\1_Keypad\GuiKey.h"

#include "SysProcess.h"

#include "GuiMenuForm_New.h"

//#include <Application\UserInterface\UIConfig.h>

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


#define     CURRENT_MEMORY_LANGUAGE     (GUILanguageToMemoryLanguage_Get(CURRENT_LANGUAGE_ID))

//Dec1514 TranL added as TungNguyen resource

#define eWINDOW_TITLE        	 WINDOW_TITLE        
#define eWINDOW_INSTRUCTION      WINDOW_INSTRUCTION  
#define eWINDOW_DESCRIPTION1     WINDOW_DESCRIPTION1 
#define eWINDOW_DESCIPTION2      WINDOW_DESCIPTION2  
#define eWINDOW_BODY             WINDOW_BODY         
#define eWINDOW_FOOTER           WINDOW_FOOTER

#define	eNONE_CHECKING		     NONE_CHECKING
#define	eUNCHECK         	     UNCHECK
#define	eCHECK           	     CHECK

#define MAX_ITEM_STR_LIST 250
#define MAX_ICON                    15

// --------------------------   GENERAL TEXT   ---------------------------------
#define INNv1_GUI_BodyTextAndBackgroundColorReset()  INNv1_GUI_BodyTextAndBackgroundColor_Reset()


// --------------------   INFO-VALUE OR CUSTOM FORM   --------------------------
// return sint16
#define INNv1_GUI_InfoValueForm_GetCurrentItemIdx()   INNv1_GUI_InfoValueGetCurrentItemIdx(GUI_Manager.p_strtInnGuiInfValFrm)
// return uint8
#define INNv1_GUI_InfoValueForm_GetFirstDispItem()    INNv1_GUI_InfoValueGetFirstDispItem(GUI_Manager.p_strtInnGuiInfValFrm)


//---------------------------    MENU FORM   -----------------------------------
//return sint16
#define INNv1_GUI_MenuForm_GetCurrentItemIdx()     INNv1_GUI_MenuGetCurrentItemIdx(GUI_Manager.p_strtInnGuiMenuFrm)
//return uint8
#define INNv1_GUI_MenuForm_GetFirstDispItem()      INNv1_GUI_MenuGetFirstDispItem(GUI_Manager.p_strtInnGuiMenuFrm)

//Oct072014 Lap Dang moved this enum to here
typedef enum _enumBrightness
{
    BRIGHTNESS_LEVEL0 = 0,
    BRIGHTNESS_LEVEL1,
    BRIGHTNESS_LEVEL2,
    BRIGHTNESS_LEVEL3,
    BRIGHTNESS_LEVEL4
} enumBrightness;


typedef struct
{
    SYS_PROC_ID eProc;
    SYS_CMD_ID  eCmd;
    const void* const*  MLItemStr;
    enumbool blEnable;
} structMenuItem;

typedef struct
{
    const void* const*  MLTitle;
    const void* const*  MLInstruction;
    const void* const*  MLFooter;
    const structMenuItem*  p_strtMenuItemList;
}structMenu;
//Dec1514 TranL added as TungNguyen resource
typedef struct
{
  SYS_PROC_ID eProc;
  SYS_CMD_ID  eCmd;
  const void* const*  MLItemStr;
    enumbool blIsCmd;
  enumbool blEnable;   
} INN_structMenuItem;

typedef struct
{
  const void* const*  MLTitle;
  const void* const*  MLDescription1;
  const void* const*  MLInstruction;
  const void* const*  MLDescription2;
  const void* const*  MLFooter;
  
  const INN_structMenuItem*  p_strtInnMenuItemList;   
} INN_structMenu;


typedef struct _INN_structInfoValueText
{
  const void* const*  MLTitle;
  const void* const*  MLDescription1;
  const void* const*  MLInstruction;
  const void* const*  MLSubBody;
  const void* const*  MLDescription2;
  const void* const*  MLFooter;
  
  const void* const*  MLCmd1;
  const void* const*  MLCmd2;
  const void* const*  MLCmd3;
  
  const void* p_strItemList[MAX_ITEM_STR_LIST];
  const void* p_strValueList[MAX_ITEM_STR_LIST];
  
  GUI_TEXT_MODE ItemTextMode;
  GUI_TEXT_MODE ValueTextMode;
  
} INN_structInfoValueText;
typedef struct
{
    GUI_IM_MONITOR_ICON*     p_strtGuiMonitors;
    GUI_CONTEXT*             p_strtGuiContext;
    GUI_TEXT_FORM*           p_strtGuiTxtFrm;
    GUI_DTC_FORM*            p_strtGuiDtcFrm;
    GUI_MENU_FORM*           p_strtGuiMnuFrm;
    GUI_INFO_VALUE_FORM*     p_strtGuiInfValFrm;
    GUI_DIGIT_SELECTION_FORM* p_strtGuiDigitFrm;
    GUI_GRAPH_FORM*          p_strtGuiGraphFrm;
    GUI_GRAPH_FORM*          p_strtGuiGraphNextFrm;
    GUI_PROGBAR_FORM*        p_strtGuiProgBarFrm;
    GUI_INFO_IMAGE_FORM*     p_strtGuiInfImgFrm;
    //Nov1414 Lap Dang added as TranLuu resource
    INN_GUI_TEXT_FORM*       p_strtINNGuiTxtFrm;
    INN_GUI_TEXT_RESULT*     p_strtINNGuiTxtRslt;
    //Dec0814 TranL added
    INN_GUI_INPUT_TEXT_FORM*  p_strtINNGuiInpTxtFrm;
    INN_GUI_DLC_LOCATOR_FORM* p_strtINNGuiDLCLocatorFrm;
    //Dec0814 TranL added as TungNguyen resource
    INN_GUI_GENERAL_TEXT_FORM*	p_strtInnGuiTxtFrm;
    INN_GUI_INFO_VALUE_FORM*    p_strtInnGuiInfValFrm;
    INN_GUI_MENU_FORM*          p_strtInnGuiMenuFrm;
    const INN_structMenuItem*   p_strtInnMenuItemList;

    const void*              p_strNameList[MAX_ITEM_STR_LIST];
    const void*              p_strValueList[MAX_ITEM_STR_LIST];
    enumImageFile            p_ImageList[MAX_ICON];
    uint16                   p_strTextBuffer[512];
    uint16                   p_strTextBufferNext[512];
    const structMenuItem*    p_strtMenuItemList;
    enumbool                 blLcmUpdateFlag;
    enumbool                 blIconUpdateFlag;
    enumICON_DISP_TYPE       eIconDispType;
    enumbool                 blIconValidChangeFlag;
} GUI_MANAGER;



/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


extern GUI_MANAGER GUI_Manager;


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

/*==============================================================================
                        BASIC FUNCTIONs
        
==============================================================================*/
/******************************* DisplaySetBrightness **************************
Engineer : My Nguyen
Date : 30, Dec, 2010
Function: DisplaySetBrightness
Description: Set brightness of LCD
Input: eLevel is one of them :  BRIGHTNESS_LEVEL0, BRIGHTNESS_LEVEL1
BRIGHTNESS_LEVEL2, BRIGHTNESS_LEVEL3, BRIGHTNESS_LEVEL4
Output: none
*******************************************************************************/
void DisplaySetBrightness(enumBrightness eLevel);










/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1015 
*Function name: GUILanguageToMemoryLanguage_Get
*Descrtiption : get memory language from GUI language
*Input        : GUI_LANGUAGE_ID eGUILang - GUI language ID
*Output       : enumMemoryLanguage - memory language
*-----------------------------------------------------------------------------*/

enumMemoryLanguage  GUILanguageToMemoryLanguage_Get(GUI_LANGUAGE_ID eGUILang);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: GUIFormFooterOnOff_Set
*Descrtiption : set the GUI Footer setting ON/OFF
*Input        : enumbool eState - state of footer need to be set
*Output       : none
*-----------------------------------------------------------------------------*/
void GUIFormFooterOnOff_Set(enumbool eState);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 10 2014
*Function name: GUIFormFooterOnOff_Get
*Descrtiption : get the GUI Footer setting
*Input        : none
*Output       : enumbool - state of footer setting in GUI
*-----------------------------------------------------------------------------*/
enumbool GUIFormFooterOnOff_Get(void );

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 14, 2011
*Function name: GUI_Clear
*Descrtiption : clear lcd area: text and icon area
*Input        : enumGUI_LCD_AREA eArea
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_Clear(enumGUI_LCD_AREA eArea);
/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Mar 14, 2013
                2. October 10 2014 Lap Dang optimize source
*Function name: GUI_IconDispTypeChange
*Descrtiption : Set change Icon disp type - set flag to refresh lcd
*Input        : enumICON_DISP_TYPE eIconDispType
*Output       : 
------------------------------------------------------------------------------*/
void GUI_IconDispTypeChange(enumICON_DISP_TYPE eIconDispType);


/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 05, 2011
                2. October 10 2014 Lap Dang optimize source
*Function name: GUI_LcdUpdate
*Descrtiption : update displaying LCD screen
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_LcdUpdate(void);

    





/*==============================================================================
                        GUI TEXT FORM
        
==============================================================================*/

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
                2. October 10, 2014 Lap Dang optimized source
*Function name: GUI_TextInit
*Descrtiption : - Init string for all field 
                - Calculate rect window to display fields

*Input        : const void* const* MLTitle
*             : const void* const* MLInstruction
*             : const void* const* MLBody
*             : const void* const* MLFooter
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_TextInit(const void* const* MLTitle,
                  const void* const* MLInstruction,
                  const void* const* MLBody,
                  const void* const* MLFooter);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
                2. October 10 2014 Lap Dang optimized source
*Function name: GUI_TextDisplay
*Descrtiption : Display the text screen type has initialized before
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_TextDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_TextOnUp
*Descrtiption : scroll up text in body field of text screen type
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_TextOnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_TextOnUp
*Descrtiption : scroll down text in body field of text screen type
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_TextOnDown(void);







/*==============================================================================
                        GUI MENU FORM
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 21, 2011
                2. October 10 2014 Lap Dang optimized source
*Function name: GUI_MenuItemInit
*Descrtiption : Init string and calculate rect window for Menu screen
*Input        : const structMenu* p_strtMenu
*             : uint8 bNumDispCol
*             : uint8 bFirstDispItem
*             : sint32 iSelectedItem
*             : uint16 DispScrollMode
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_MenuInit(const structMenu* p_strtMenu,
                  uint8 bNumDispCol,
                  uint8 bFirstDispItem,
                  sint32 iSelectedItem,
                  GUI_SCROLL_DISP_MODE DispScrollMode);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 21, 2011
*Function name: GUI_MenuDisplay
*Descrtiption : Display Menu screen which initialized before
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_MenuDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 21, 2011
                2. October 10 2014 Lap Dang optimized source
*Function name: GUI_MenuOnUp
*Descrtiption : scroll up body item list
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_MenuOnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 21, 2011
                2. October 10 2014 Lap Dang optimized source
*Function name: GUI_MenuOnDown
*Descrtiption : scroll down body item list
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_MenuOnDown(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2315
*Function name: GUI_Menu_CurrentOptionIndex_Get
*Descrtiption : get index of current option in menu form
*Input        : None
*Output       : sint32 - index of current option (highlight on screen)
*-----------------------------------------------------------------------------*/
sint32 GUI_Menu_CurrentOptionIndex_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 21, 2011
*Function name: GUI_MenuOnEnter
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_MenuOnEnter(void);



/*==============================================================================
                        GUI MENU NEW FORM
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Oct1614 Lap Dang customized source
*Function name: GUI_Menu_New_Display
*Descrtiption : display menu form on lcd with new style
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_Menu_New_Display(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Oct1614 Lap Dang customized source
*Function name: GUI_Menu_New_OnUp
*Descrtiption : scroll up menu items - new style
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_Menu_New_OnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Oct1614 Lap Dang customized source
*Function name: GUI_MenuNew_OnDown
*Descrtiption : scroll down menu items - new style
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_MenuNew_OnDown(void);


/*==============================================================================
                        GUI TEXT HIGHLIGHT FORM
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_HighlightTextInit
*Description  :
*Input        : const void* const* MLTitle
*             : const void* const* MLInstruction
*             : const void* const* MLBody
*             : const void* const* MLFooter
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_HighlightTextInit(const void* const* MLTitle,
                           const void* const* MLInstruction,
                           const void* const* MLBody,
                           const void* const* MLFooter,
                           sint32 iNumberSelectableLine,
                           sint32 iCurrentSelectedLine);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_HighlightTextDisplay
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_HighlightTextDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_HighlightTextOnUp
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_HighlightTextOnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_HighlightTextOnUp
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_HighlightTextOnDown(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_HighlightTextGetSelected
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
sint32 GUI_HighlightTextGetSelected(void);



/*==============================================================================
                        GUI IMAGE - INFO form
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Apr 08, 2013
                2. July012014 Lap Dang modified, 
                    consider images in internal flash as files
*Function name: GUI_InfoImageInit

*Descrtiption :
*Input        : const void* const* MLTitle
*             : const void* const* MLInstruction
*             : const void* const* MLBody
*             : const void* const* MLFooter
*Output       :

*-----------------------------------------------------------------------------*/\
void GUI_InfoImageInit(const void* const* MLTitle,

                       const void* const* MLInstruction,


                       const void* const* MLFooter,


                       uint8 bNumberItem,
                       const void* const* p_strItemList,
                       enumImageFile* p_ImageList);
/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Apr 08, 2013
*Function name: GUI_InfoImageDisplay

*Descrtiption : Display form image - info
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_InfoImageDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Apr 10, 2013
*Function name: GUI_InfoImageOnUp

*Descrtiption : scroll up in Image - Info form
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_InfoImageOnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Apr 10, 2013
*Function name: GUI_InfoImageOnDown

*Descrtiption : scroll down in Image - Info form
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_InfoImageOnDown(void);





/*==============================================================================
                        GUI IM MONITOR
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_IMMonInit
*Descrtiption :
*Input        : uint8* p_bPid01
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_IMMonInit(const uint8* p_bPid01);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_IMMonToggle

*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/


void GUI_IMMonToggle(void);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 22 2014
*Function name: GUI_IconUpdateFlag_Set












*Descrtiption : set flag to update Icon
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/










void GUI_IconUpdateFlag_Set(enumbool eFlagStat);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 22 2014
*Function name: GUI_IconUpdateFlag_Get

*Descrtiption : get flag of update Icon
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/

enumbool GUI_IconUpdateFlag_Get(void);







/*==============================================================================
                        GUI DTC SCREEN FORM
        
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_DTCInit

*Descrtiption :
*Input        : GUI_DTC_TYPE eDTCType
*             : uint8 bCurrentDTCIdx : Index of current DTC [0, bTotalDTC -1]
*             : uint8 bTotalDTC
*             : const uint8* strDTCCode
*             : const void* const* MLDTCInfo
*             : const void* const* MLDTCDefinition
*             : const void* const* MLFooter
*Output       :
*-----------------------------------------------------------------------------*/


void GUI_DTCInit(GUI_DTC_TYPE eDTCType,
                 uint8 bCurrentDTCIdx,
                 uint8 bTotalDTC,
                 const uint8* strDTCCode,
                 const void* const* MLDTCInfo,
                 const void* const* MLDTCDefinition,
                 const void* const* MLFooter);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_DTCDisplay

*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_DTCDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011
*Function name: GUI_DTCOnUp

*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/


void GUI_DTCOnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. November 22, 2011

*Function name: GUI_DTCOnDown
*Descrtiption :




*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/

void GUI_DTCOnDown(void);

/*------------------------------------------------------------------------------
*Engineer     : Hoang Nguyen
*Historical   : 1. Sep 25, 2013
*Function name: GUI_FIXInit
*Descrtiption :
*Input        : GUI_DTC_TYPE eDTCType
*             : uint8 bCurrentDTCIdx : Index of current DTC [0, bTotalDTC -1]
*             : uint8 bTotalDTC
*             : const uint8* strDTCCode
*             : const void* const* MLDTCInfo
*             : const void* const* MLDTCDefinition
*             : const void* const* MLFooter
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_FIXInit(GUI_DTC_TYPE eDTCType,
                 uint8 bCurrentDTCIdx,
                 uint8 bTotalDTC,
                 const void* const* MLFixTitle,
                 const uint8* strDTCCode,
                 const void* const* MLDTCInfo,
                 const void* const* MLDTCDefinition,
                 const void* const* MLFooter);




/*==============================================================================
                        GUI INFO - VALUE SCREEN FORM
            using for live data
==============================================================================*/








/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1.
*Historical   : 2. March 12, 2012, KhaV add description
*Function name: GUI_InfoValueonUp
*Descrtiption : On Info menu UP pressed













*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/










void GUI_InfoValueonUp(void);
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. March 12, 2012
*Function name: GUI_InfoValueonDown
*Descrtiption : On Info menu DOWN pressed
*Input        : None


*Output       :
*-----------------------------------------------------------------------------*/



void GUI_InfoValueonDown(void);


void GUI_DigitScreenInit(const void* const* MLTitle,
                            uint8* pstrDigits,
                            const void* const* MLFooter,
                            uint8        bCurrentDigitIdx,
                            uint8        bNumberDigit);

void GUI_DigitScreenInit_New(const void* const* MLTitle,
                             uint8* pstrDigits,
                             const void* const* MLInstruction,
                             const void* const* MLFooter,
                             uint8        bCurrentDigitIdx,
                             uint8        bNumberDigit);

void GUI_DigitScreenDisplay(void);

void GUI_DigitScreenDisplay_New(void);

void GUI_DigitScreenSelectNextDigit(void);
void GUI_DigitScreenSelectPrevDigit(void);
uint8 GUI_DigitScreenGetDigit(void);
void GUI_DigitScreenSetDigit(uint8 bDigit);
void GUI_DigitScreenSetDigitStr(uint8* p_strDigit);
uint8* GUI_DigitScreenGetDigitStrPtr(void);
uint8 GUI_DigitScreenGetDigitIdx(void);








/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 15 2014
*Function name: GUI_LCD_SIZE_WIDTH_Get
*Descrtiption : get available size of LCD in width
*Input        : None
*Output       : available display area in width direction
*-----------------------------------------------------------------------------*/
uint16  GUI_LCD_SIZE_WIDTH_Get(void);











































//Nov1414 Lap Dang added as TranLuu resource
/*==============================================================================
                        GUI TEXT FORM SCREEN FORM
            
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 25, 2014
*Function name: INN_GUI_TextInit
*Description  :
*Input        : const void* const* MLTitle
*             : const void* const* MLInstruction
*             : const void* const* MLBody
*             : const void* const* MLFooter
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_TextInit(const void* const* MLHeader,
                      const void* const* MLDescription1,
                      const void* const* MLInstruction,
                      const void* const* MLBody,
                      const void* const* MLDescription2,
                      const void* const* MLFooter,
                      const void** ListOption,
                      uint8  bNumberOption);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 25, 2014
*Function name: INN_GUI_TextDisplay
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_TextDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 25, 2014
*Function name: INN_GUI_TextOnUp
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_HighlightTextOnUp(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 25, 2014
*Function name: INN_GUI_TextOnUp
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_HighlightTextOnDown(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 25, 2014
*Function name: INN_GUI_TextGetSelected
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
sint32 INN_GUI_TextGetSelected(void);





/*==============================================================================
                        GUI TEXT RESULT SCREEN FORM
            
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 29, 2014
*Function name: INN_GUI_TextResultFormInit
*Description  :
*Input        : const void* const* MLHeader,
                const void* const* MLDescription1,
                const void* const* MLInstruction,
                const void* const* MLCommand,
                const void* const* MLValue,
                const void* const* MLDescription2,
                const void* const* MLFooter,
                const void** ListOption,
                uint8  bNumberOption,
                sint32 iNumberSelectableLine,
                sint32 iCurrentSelectedLine
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_TextResultFormInit(const void* const* MLHeader,
                                const void* const* MLDescription1,
                                const void* const* MLInstruction,
                                const void* const* MLCommand,
                                const void* const* MLValue,
                                const void* const* MLDescription2,
                                const void* const* MLFooter,
                                const void** ListOption,
                                uint8  bNumberOption);

/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 29, 2014
*Function name: INN_GUI_TextResultFormDisplay
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_TextResultFormDisplay(void);

/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 29, 2014
*Function name: INN_GUI_TextResultOnUp
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_TextResultOnUp(void);

/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 29, 2014
*Function name: INN_GUI_TextResultOnDown
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_TextResultOnDown(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 25, 2014
*Function name: INN_GUI_TextResultFormGetSelected
*Description  :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
sint32 INN_GUI_TextResultFormGetSelected(void);

/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 29, 2014
*Function name: INN_GUI_TextResultFormSetWndValueXSize
*Descrtiption :
*Input        : (I/0) INN_GUI_TEXT_RESULT* p_strtTxtRslt

*Note: 
*Output       : Index of selected Item
*-----------------------------------------------------------------------------*/
void INN_GUI_TextResultFormSetWndValueXSize(sint32 iWndValueXSize);





/*==============================================================================
                        GUI TEXT PROGRESS BAR SCREEN FORM
            
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 30, 2014
*Function name: INN_GUI_Text_ProgressBar_Init
*Descrtiption :
*Input        : INN_GUI_TEXT_FORM* p_strtTxtFrm,
                const void* strTitle,
                const void* strDescription1,
                const void* strInstruction,
                const void* strBody,
                const void* strDescription2,
                const void* strFooter,
                GUI_PROGBAR_FORM* p_strtProgressBarFrm,
                const void* strProgBarText,
                enumbool eProgBarEn
                const char ** pp_ListOption,
                uint8 bNumberOption
*Note: text mode and text aligment is define with GUI_Context
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_Text_ProgressBar_Init(const void* const* MLHeader,
                                   const void* const* MLDescription1,
                                   const void* const* MLInstruction,
                                   const void* const* MLBody,
                                   const void* const* MLDescription2,
                                   const void* const* MLFooter,
                                   const void* const* strProgBarText,
                                   enumbool eProgBarEn,
                                   const void** ListOption,
                                   uint8  bNumberOption);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. October 30, 2014
*Function name: INN_GUI_Text_ProgressBar_Disp
*Descrtiption :
*Input        : 

*Note: text mode and text aligment is define with GUI_Context
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_Text_ProgressBar_Disp(void);		
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 30, 2014
*Function name: INN_GUI_ProgressBar_Update
*Descrtiption :
*Input        : 

*Note: 
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_ProgressBar_Update(const void* strProgBarText,
                                uint8 bPercent);
  
  



/*==============================================================================
                        GUI INPUT TEXT SCREEN FORM
            
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 15, 2014
*Function name: INN_GUI_InputTextInit
*Descrtiption :
*Input        : (I/0) GUI_SCROLL_DISP_MODE DispScrollMode,
                      GUI_SELECTION_MODE SelectionMode,
                      const void* const* MLHeader,
                      const void* const* MLDescription1,
                      const void* const* MLInstruction,
                      char* strInput,
                      const void* const* MLDescription2,
                      const void* const* MLFooter,
                      const void** ListOption,
                      uint8  bNumberOption
*Note: text mode and text aligment is define with GUI_Context
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_InputTextInit(GUI_SCROLL_DISP_MODE DispScrollMode,
                           const void* const* MLHeader,
                           const void* const* MLDescription1,
                           const void* const* MLInstruction,
                           void* strInput,
                           const void* const* MLDescription2,
                           const void* const* MLFooter,
                           const void** ListOption,
                           uint8  bNumberOption);



/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 15, 2014
*Function name: INN_GUI_InputTextDisp
*Descrtiption :
*Input        : (I/0)                  
*Note: text mode and text aligment is define with GUI_Context
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_InputTextDisp(void);

/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 14, 2014
*Function name: INN_GUI_InputTextScrollDown
*Description  :
*Input        : INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_InputTextScrollDown(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 14, 2014
*Function name: INN_GUI_InputTextScrollUp
*Description  :
*Input        : INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_InputTextScrollUp(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 18, 2014
*Function name: INN_GUI_InputTextKeyBoardOnEnter
*Description  :
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_InputTextKeyBoardOnEnter(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 19, 2014
*Function name: INN_GUI_InputTextGetSelected
*Descrtiption :
*Input        : (I/0) 

*Note: 
*Output       : Index of selected Item
*-----------------------------------------------------------------------------*/
sint32 INN_GUI_InputTextGetSelected(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 19, 2014
*Function name: INN_GUI_InputTextGetEnableField
*Descrtiption :
*Input        : (I/0) 

*Note: 
*Output       : Index of selected Item
*-----------------------------------------------------------------------------*/
INN_GUI_FIELD INN_GUI_InputTextGetEnableField(void);
/*------------------------------------------------------------------------------
*Engineer     : TranLuu
*Historical   : 1. November 21, 2014
*Function name: INN_GUI_InputTextGetInputText
*Descrtiption :
*Input        : (I/0) INN_GUI_TEXT_FORM* p_strtInpTxtFrm

*Note: 
*Output       : Input string
*-----------------------------------------------------------------------------*/
void const* INN_GUI_InputTextGetInputText(void);






/*==============================================================================
                        GUI DLC LOCATOR SCREEN FORM
            
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Tran Luu
*Historical   : 1. December 1, 2014
*Function name: INN_GUI_DLCLocatorInit
*Descrtiption : Initialize DLC Locator screen
*Input        :
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_DLCLocatorInit(const void* const* MLHeader,
                            const void* const* MLAccess,
                            const void* const* MLCommand,
                            const void* const* MLFooter);
/*------------------------------------------------------------------------------
*Engineer     : Tran Luu
*Historical   : 1. Novemver 28, 2014
*Function name: INN_GUI_DLCLocatorDisplay
*Descrtiption : Display flash screen
*Input        : INN_GUI_DLC_LOCATOR_FORM* p_strtDLCLocatorFrm
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_DLCLocatorDisplay(void);
/*------------------------------------------------------------------------------
*Engineer     : Tran Luu
*Historical   : 1. December 1, 2014
*Function name: INN_GUI_DLCLocatorScrollUp
*Descrtiption : 
*Input        :
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_DLCLocatorScrollUp(void);
/*------------------------------------------------------------------------------
*Engineer     : Tran Luu
*Historical   : 1. December 1, 2014
*Function name: INN_GUI_DLCLocatorScrollDown
*Descrtiption : 
*Input        :
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_DLCLocatorScrollDown(void);
/*------------------------------------------------------------------------------
*Engineer     : Tran Luu
*Historical   : 1. December 1, 2014
*Function name: INN_GUI_DLCLocator_UpdateImage
*Descrtiption : 
*Input        :
*Output       :
*-----------------------------------------------------------------------------*/
void INN_GUI_DLCLocator_UpdateImage(uint8 bDLC_Pos);






//Dec0814 TranL added as Tung Nguyen resource
/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 12, 2014

*Function name: INNv1_GUI_TextAndBackgroundColorChange
*Description  :	Change Text Color and Background Color

*Input        : enumWindow eWindow
*             : uint16 iTextColor
*             : uint16 iBackgroundColor
*Output       :

*Notes        : 1. Should call only before Display function.
*             : 2. The color of Body Window should be changed before Init Form for correction.
*             :    Set the default color of Body Window by calling INNv1_GUI_BodyTextAndBackgroundColorReset()
*             :    before Displaying.
*-----------------------------------------------------------------------------*/
void INNv1_GUI_TextAndBackgroundColorChange(enumWindow eWindow, uint16 iTextColor, uint16 iBackgroundColor);


// =============================================================================
// 			INFO VALUE FORM
// =============================================================================

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 09, 2014

*Function name: INNv1_GUI_InfoValueForm_Init
*Description  : Initialize Info-Value Form

*Input        : INN_structInfoValueText *p_strtInnInfoValueText
*             : uint8 bNumberItem 
*             : uint8 bFirstDispItem 
*             : sint32 iSelectedItem 
*             : uint32 iInfoMaxXSize
*             : enumbool IsCheckListOnTheLeft
*             : GUI_SCROLL_DISP_MODE DispScrollMode
*             : GUI_SELECTION_MODE SelectionMode
*Output       :
*
*Notes        : remember list end with NULL
*             : INN_structInfoValueText need to be initialized full (with MLNull)
*             : bNumberItem includes Commands
*
*-----------------------------------------------------------------------------*/
void INNv1_GUI_InfoValueForm_Init(INN_structInfoValueText *p_strtInnInfoValueText,
                                  uint8 bNumberItem,
                                  uint8 bFirstDispItem,
                                  sint32 iSelectedItem,
                                  uint32 iInfoMaxXSize,
                                  enumbool IsCheckListOnTheLeft,
                                  GUI_SCROLL_DISP_MODE DispScrollMode,
                                  GUI_SELECTION_MODE SelectionMode);

                
/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 09, 2014
*Function name: INNv1_GUI_InfoValueForm_Display
*Description  : Display Info-Value Form
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_InfoValueForm_Display(void);


/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 12, 2014
*Function name: INNv1_GUI_InfoValueOnUp
*Description  : Scroll Up InfoValue Form
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_InfoValueOnUp(void);

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 12, 2014
*Function name: INNv1_GUI_InfoValueOnDown
*Description  : Scroll Down InfoValue Form
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_InfoValueOnDown(void);


// =============================================================================
//	 			MENU FORM
// =============================================================================

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 12, 2014
*Function name: INNv1_GUI_MenuInit
*Description  : Init Menu Form
*Input        : const INN_structMenu* p_strtMenu
*			  : uint8 bNumDispCol
*			  : uint8 bFirstDispItem
*			  : sint32 iSelectedItem
*			  : GUI_SCROLL_DISP_MODE DispScrollMode
*Output       :
* 
*Note         : NextPage, PrevPage not supported yet.
*-----------------------------------------------------------------------------*/
void INNv1_GUI_MenuInit(const INN_structMenu* p_strtMenu,
                        uint8 bNumDispCol,
                        uint8 bFirstDispItem,
                        sint32 iSelectedItem,
                        GUI_SCROLL_DISP_MODE DispScrollMode);

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 12, 2014
*Function name: INNv1_GUI_Menu_Display
*Description  : Display Menu Form
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/						  
void INNv1_GUI_Menu_Display(void);

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 12, 2014
*Function name: INNv1_GUI_MenuOnUp
*Description  : Scroll Up Menu Form
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_MenuOnUp(void);

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 12, 2014
*Function name: INNv1_GUI_MenuOnDown
*Description  : Scroll Down Menu Form
*Input        : 
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_MenuOnDown(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 05 2015
*Function name: INNv1_GUI_Menu_CurrentItemIdx_Get
*Descrtiption : get current item index of new MENU GUI Form
*Input        : None
*Output       : sint32 - signed integer item index,
                index>0 - current item is at infor-value list
                index<0 - current item is at command list
*-----------------------------------------------------------------------------*/
sint32 INNv1_GUI_Menu_CurrentItemIdx_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 05 2015
*Function name: INNv1_GUI_MenuOnEnter
*Descrtiption : process ENTER with new form MENU
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_MenuOnEnter(void);


// =============================================================================
// 				CUSTOM FORM
// =============================================================================

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. November 25, 2014
*Function name: INNv1_GUI_CustomForm_CheckList_OnEnter
*Description  : Custom Form On Enter Pressed for Toogling CheckTick
*Input        : uint8* p_CustomCheckList
*             : sint16 sIndex
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_CustomForm_CheckList_OnEnter(uint8* p_CustomCheckList, sint16 sIndex);


/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 12, 2014
*Function name: INNv1_GUI_GetStringOnCheckList
*Description  :	Get String List from CheckList
*Input        : uint8 bNumberItem
*             : uint8* p_CustomCheckList
*             : const void* p_strPtrList[]
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_GetStringOnCheckList(uint8 bNumberItem,
                            uint8* p_CustomCheckList,
                            const void* p_strPtrList[]);

							
/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 12, 2014
*Function name: INNv1_GUI_CheckString__Toggle
*Description  :	Toggle CheckString of StringList for displaying
*Input        : sint16 sIndex
*             : enumbool blIsCheckListOnTheLeft
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_CheckString__Toggle(sint16 sIndex, enumbool blIsCheckListOnTheLeft);

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 12, 2014
*Function name: INNv1_GUI_CheckList__ToggleTick
*Description  :	Toggle CheckTick in CheckList
*Input        : uint8* p_CustomCheckList
*             : int16 sIndex
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_CheckList__ToggleTick(uint8* p_CustomCheckList, sint16 sIndex); 


/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 12, 2014
*Function name: INNv1_GUI_CheckList__GetStatus
*Description  :	Get status of an element in Checklist
*Input        : uint8* p_CustomCheckList
*             : sint16 sIndex
*Output       : enumChecking status
*-----------------------------------------------------------------------------*/
enumChecking INNv1_GUI_CheckList__GetStatus(uint8* p_CustomCheckList, sint16 sIndex);

/*------------------------------------------------------------------------------
*Engineer     : TungMN
*Historical   : 1. December 12, 2014
*Function name: INNv1_GUI_CheckList__SetStatus
*Description  :	Set status of and element in Checklist
*Input        : uint8* p_CustomCheckList
*             : sint16 sIndex
*             : enumChecking eStatus
*Output       :
*-----------------------------------------------------------------------------*/
void INNv1_GUI_CheckList__SetStatus(uint8* p_CustomCheckList, sint16 sIndex, enumChecking eStatus);



#endif