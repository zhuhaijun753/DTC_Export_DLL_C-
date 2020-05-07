/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUICORE_H__
#define __GUICORE_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define   CURRENT_LANGUAGE_ID (GUI_Context.LanguageID)


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
#define ICON_WIDTH                                  5
#define DEFAULT_BACKGROUND_COLOR                    0xFFFF
#define DEFAULT_TEXT_COLOR                          0x0000
#if 1
#define TITLE_DEFAULT_BACKGROUND_COLOR              0xFFFF
#define TITLE_DEFAULT_TEXT_COLOR                    0x0000

#define DESCRIPTION_DEFAULT_BACKGROUND_COLOR        0xFFFF
#define DESCRIPTION_DEFAULT_TEXT_COLOR              0x0000

/*Dec1514 TranL added as TungNguyen resource*/
#define DESCRIPTION_1_DEFAULT_BACKGROUND_COLOR        0xFFFF
#define DESCRIPTION_1_DEFAULT_TEXT_COLOR              0x0000
#define DESCRIPTION_2_DEFAULT_BACKGROUND_COLOR        0xFFFF
#define DESCRIPTION_2_DEFAULT_TEXT_COLOR              0x0000


#define INSTRUCTION_DEFAULT_BACKGROUND_COLOR        0xFFFF
#define INSTRUCTION_DEFAULT_TEXT_COLOR              0x0000
#define FOOTER_DEFAULT_BACKGROUND_COLOR             0xFFFF
#define FOOTER_DEFAULT_TEXT_COLOR                   0x849F
#else
#define TITLE_DEFAULT_BACKGROUND_COLOR              0x001F
#define TITLE_DEFAULT_TEXT_COLOR                    0xFFFF
#define INSTRUCTION_DEFAULT_BACKGROUND_COLOR        0x001F
#define INSTRUCTION_DEFAULT_TEXT_COLOR              0xFFFF
#define FOOTER_DEFAULT_BACKGROUND_COLOR             0x001F
#define FOOTER_DEFAULT_TEXT_COLOR                   0xFFFF
#endif
#define BODY_DEFAULT_BACKGROUND_COLOR               0xFFFF
#define BODY_DEFAULT_TEXT_COLOR                     0x0000
#define DTCCODE_DEFAULT_BACKGROUND_COLOR            0xFFFF
#define DTCCODE_DEFAULT_TEXT_COLOR                  0xF800
#define DTCINFO_DEFAULT_BACKGROUND_COLOR            0xFFFF
#define DTCINFO_DEFAULT_TEXT_COLOR                  0xF800
#define DTCDEF_DEFAULT_BACKGROUND_COLOR             0xFFFF
#define DTCDEF_DEFAULT_TEXT_COLOR                   0x0000
#define DIGIT_DEFAULT_BACKGROUND_COLOR              0xFFFF
#define DIGIT_DEFAULT_TEXT_COLOR                    0x0000
#define FLASH_DEFAULT_BACKGROUND_COLOR              0xFFFF
#define FLASH_DEFAULT_TEXT_COLOR                    0x0000
#define VALUE_DEFAULT_BACKGROUND_COLOR              0xFFFF
#define VALUE_DEFAULT_TEXT_COLOR                    0x0000
#define XUNIT_DEFAULT_BACKGROUND_COLOR              0xFFFF
#define XUNIT_DEFAULT_TEXT_COLOR                    0x0000
#define RATIO_DEFAULT_BACKGROUND_COLOR              0xFFFF
#define RATIO_DEFAULT_TEXT_COLOR                    0x0000

//#ifdef __GUICORE_C__
//dafd
//#ifdef MX_BUILD
//#define LIST_ITEM_ALIGN_MODE     GUI_TA_BASELINE
//#else
//#define LIST_ITEM_ALIGN_MODE     GUI_TA_TOP
//#endif

//GUI_CONTEXT GUI_Context = {\
//    .p_strtBigFont       = &g_strtDTCBigFont,  \
//    .p_strtNormalFont    = &g_strtNormalFont,  \
//    .p_strtSmallFont     = &g_strtSmallFont,  \
//     \
//    .TitleAlignMode      = GUI_TA_HVCENTER,  \
//    .TitleTextMode       = GUI_TEXTMODE_NORMAL,  \
//    .TitleBackGndColor   = TITLE_DEFAULT_BACKGROUND_COLOR,\
//    .TitleTextColor      = TITLE_DEFAULT_TEXT_COLOR,\
//    \
//    .DescriptionAlign    = GUI_TA_LEFT,  \
//    .DescriptionTextMode = GUI_TEXTMODE_NORMAL,  \
//    .DescriptionBackGndColor = DESCRIPTION_DEFAULT_BACKGROUND_COLOR,    \
//    .DescriptionTextColor = DESCRIPTION_DEFAULT_TEXT_COLOR, \
//    \
//    .InstructionAlign    = GUI_TA_LEFT,  \
//    .InstructionTextMode = GUI_TEXTMODE_NORMAL,  \
//    .InstructionBackGndColor = INSTRUCTION_DEFAULT_BACKGROUND_COLOR,    \
//    .InstructionTextColor = INSTRUCTION_DEFAULT_TEXT_COLOR, \
//    \
//    .RatioAlignMode      = GUI_TA_RIGHT,  \
//    .RatioTextMode       = GUI_TEXTMODE_NORMAL,  \
//    .RatioBackGndColor   = RATIO_DEFAULT_BACKGROUND_COLOR,  \
//    .RatioTextColor      = RATIO_DEFAULT_TEXT_COLOR,    \
//    \
//    .BodyAlignMode       = (GUI_TEXT_ALIGN_MODE)(GUI_TA_LEFT | GUI_TA_TOP),  \
//    .BodyTextMode        = GUI_TEXTMODE_NORMAL,  \
//    .BodyBackGndColor    = BODY_DEFAULT_BACKGROUND_COLOR,   \
//    .BodyTextColor       = BODY_DEFAULT_TEXT_COLOR, \
//    \
//    .FooterAlignMode     = GUI_TA_HVCENTER,  \
//    .FooterTextMode      = GUI_TEXTMODE_NORMAL,  \
//    .FooterBackGndColor  = FOOTER_DEFAULT_BACKGROUND_COLOR, \
//    .FooterTextColor     = FOOTER_DEFAULT_TEXT_COLOR,   \
//    \
//    .DTCInfoAlignMode    = (GUI_TA_LEFT | GUI_TA_VCENTER),  \
//    .DTCInfoTextMode     = GUI_TEXTMODE_NORMAL,  \
//    .DTCInfoBackGndColor = DTCINFO_DEFAULT_BACKGROUND_COLOR,    \
//    .DTCInfoTextColor    = DTCINFO_DEFAULT_TEXT_COLOR,  \
//    \
//    .TextScrollMode      = (GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_ICON_UP | GUI_SCROLL_DISP_ICON_DOWN),  \
//    .MenuScrollMode      = (GUI_SCROLL_DISP_INDEX),  \
//    .ListItemAlignMode   = LIST_ITEM_ALIGN_MODE,  \
//    .LanguageID          = GUI_LANG_ENGLISH,\
//    .LayoutMode          = GUI_LAYOUT_NONE,\
//    .FirstGraphColor     = 0x0000,\
//    .SecondGraphColor    = 0xF800,\
//};//GUI_DEFAUT_CONTEXT;
//GUI_IM_MONITOR_ICON     GUI_Monitors;
//GUI_TEXT_FORM           GUI_TxtFrm;
//GUI_DTC_FORM            GUI_DtcFrm;
//GUI_MENU_FORM           GUI_MnuFrm;
//GUI_INFO_VALUE_FORM     GUI_InfValFrm;
//GUI_DIGIT_SELECTION_FORM GUI_DigitFrm;
//GUI_GRAPH_FORM           GUI_GraphFrm;
//GUI_GRAPH_FORM           GUI_GraphNextFrm;
//GUI_PROGBAR_FORM         GUI_ProgBarFrm;
//GUI_INFO_IMAGE_FORM     GUI_InfImgFrm;
//structLDGraph g_strtLDGraph;
//#else
extern GUI_CONTEXT             GUI_Context;
extern GUI_IM_MONITOR_ICON     GUI_Monitors;
extern GUI_TEXT_FORM           GUI_TxtFrm;
extern GUI_DTC_FORM            GUI_DtcFrm;
extern GUI_MENU_FORM           GUI_MnuFrm;
extern GUI_INFO_VALUE_FORM     GUI_InfValFrm;
extern GUI_DIGIT_SELECTION_FORM GUI_DigitFrm;
extern GUI_GRAPH_FORM           GUI_GraphFrm;
extern GUI_GRAPH_FORM           GUI_GraphNextFrm;
extern GUI_PROGBAR_FORM         GUI_ProgBarFrm;
extern GUI_INFO_IMAGE_FORM     GUI_InfImgFrm;

extern INN_GUI_TEXT_FORM        INN_GUI_TxtFrm;
extern INN_GUI_INPUT_TEXT_FORM  INN_GUI_InpTxtFrm;
extern INN_GUI_TEXT_RESULT        INN_GUI_TxtRslt;
extern INN_GUI_INPUT_TEXT_FORM    INN_GUI_InpTxtFrm;
extern INN_GUI_DLC_LOCATOR_FORM   INN_GUI_DLCLocatorFrm;
extern structLDGraph g_strtLDGraph;
//#endif


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_Init(void);
void GUI_ContextSetTextMode(GUI_TEXT_MODE TextMode);
void GUI_GetClientRect(GUI_RECT* pRect);
void GUI_GetProgBarRect(GUI_RECT* pRect);
void GUI_SetProgBarRect(GUI_RECT* pRect, int x0, int y0, int x1, int y1);
GUI_WINDOW* GUI_ClientWndGet(void);
enumbool GUI_SetLanguage(GUI_LANGUAGE_ID LanguageID);
GUI_LANGUAGE_ID GUI_GetLanguage(void);
enumbool GUI_IsUnicodeLang(GUI_LANGUAGE_ID LanguageID);



/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 15 2014
*Function name: GUI_Footer_Set
*Descrtiption : set footer setting in GUI_Context for displaying 
*Input        : enumbool eFooter - Footer value On/Off
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_Footer_Set(enumbool eFooter);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 15 2014
*Function name: GUI_Footer_Get
*Descrtiption : get footer setting in GUI_Context for displaying 
*Input        : 
*Output       : enumbool - Footer value On/Off
*-----------------------------------------------------------------------------*/
enumbool GUI_Footer_Get(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 13 2014
*Function name: GUI_LCD_UnsuedArea_Background_Update
*Descrtiption : fill unsued area on right side of lcd with input color
*Input        : uint16 sColor - color to fill to the unsued area
*Output       : none
*-----------------------------------------------------------------------------*/
//November 13 2014 Lap Dang added
void GUI_LCD_UnsuedArea_Background_Update(uint16 sColor);

#endif
