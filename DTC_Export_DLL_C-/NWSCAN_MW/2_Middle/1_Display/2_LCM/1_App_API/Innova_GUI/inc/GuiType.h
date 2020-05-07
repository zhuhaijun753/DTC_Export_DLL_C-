/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUITYPE_H__
#define __GUITYPE_H__
#include    "PlatformType.h"
#include "..\..\Font\Font.h"
/*==============================================================================
*                                 GUI Config
*=============================================================================*/
#define US_BUILD 1

#ifdef CN_BUILD
#define EN_EN   1
#define SP_EN   0
#define FR_EN   0
#define JP_EN   0
#define CN_EN   1
#define VN_EN   0

#elif defined(JP_BUILD)
#define EN_EN   1
#define SP_EN   0
#define FR_EN   0
#define JP_EN   1
#define CN_EN   0
#define VN_EN   0

#elif defined(MX_BUILD)
#define EN_EN   1
#define SP_EN   1
#define FR_EN   0
#define JP_EN   0
#define CN_EN   0
#define VN_EN   0

#elif defined(US_BUILD)
#define EN_EN   1
#define SP_EN   1
#define FR_EN   1
#define JP_EN   0
#define CN_EN   0
#define VN_EN   0

#elif defined(VN_BUILD)
#define EN_EN   0
#define SP_EN   0
#define FR_EN   0
#define JP_EN   0
#define CN_EN   0
#define VN_EN   1

#endif


#if (JP_EN || CN_EN)
#define SUPPORT_UNICODE     1
#else
#define SUPPORT_UNICODE     0
#endif

#define    NUM_LANG_SUPPORT (EN_EN + SP_EN + FR_EN + JP_EN + CN_EN)

#if (NUM_LANG_SUPPORT == 0)
 #error "Not Any language is defined?"
#elif (NUM_LANG_SUPPORT == 1)
    #define DefineMLText(LangT) { LangT }
#elif (NUM_LANG_SUPPORT == 2)
    #define DefineMLText(EnglishT , ForeignT) {EnglishT, ForeignT}
#elif (NUM_LANG_SUPPORT == 3)
    #define DefineMLText(Lang1T, Lang2T, Lang3T) { Lang1T ,\
                                                    Lang2T ,\
                                                    Lang3T \
                                                  }
#else
#error "Define too many language: English + SP + FR or English + Other Language"
#endif

#define IMSTATUSICONS_HEGHT         56
#define LINKICONS_HEGHT             24

#define ADD_SPACE_BEFOE_OPTION_OF_MENU  0/*need to modify GUI driver if want to use this*/
#define SPACE_MENU_OPTION   4

#define PROGRESS_BAR_HEIGHT 30
#define SPACE_FROM_BOTTOM   5

//Dec1514 TranL added as TungNguyen resource
#define MAX_NUMBER_LIST_ITEM	250

/*==============================================================================
*                                 Simple types
*=============================================================================*/
typedef enum
{
    GUI_TA_LEFT           = (1<<0),
    GUI_TA_RIGHT          = (1<<1),
    GUI_TA_HCENTER        = (1<<2),

    /* Text alignment flags, vertical */

    GUI_TA_TOP            = (1<<3),
    GUI_TA_BOTTOM         = (1<<4),
    GUI_TA_BASELINE       = (1<<5),
    GUI_TA_VCENTER        = (1<<6),

    GUI_TA_HVCENTER       = (GUI_TA_HCENTER | GUI_TA_VCENTER)
} GUI_TEXT_ALIGN_MODE;

#define GUI_TA_HORIZONTAL_MASK (GUI_TA_LEFT | GUI_TA_RIGHT | GUI_TA_HCENTER)
#define GUI_TA_VERTICAL_MASK   (GUI_TA_TOP | GUI_TA_BOTTOM | GUI_TA_BASELINE | GUI_TA_VCENTER)

typedef enum
{
    LCD_DRAWMODE_NORMAL     = (0),
    LCD_DRAWMODE_XOR        = (1<<0),
    LCD_DRAWMODE_TRANS      = (1<<1),
    LCD_DRAWMODE_REV        = (1<<2),
#if SUPPORT_UNICODE
    LCD_TEXTMODE_UNICODE    = (1<<3),
#endif
} GUI_DRAW_MODE;

typedef enum
{
    GUI_TEXTMODE_NORMAL    = LCD_DRAWMODE_NORMAL,
    GUI_TEXTMODE_XOR       = LCD_DRAWMODE_XOR,
    GUI_TEXTMODE_TRANS     = LCD_DRAWMODE_TRANS,
    GUI_TEXTMODE_REVERSE   = LCD_DRAWMODE_REV,
#if SUPPORT_UNICODE
    GUI_TEXTMODE_UNICODE   = LCD_TEXTMODE_UNICODE
#endif
} GUI_TEXT_MODE;

typedef enum
{
    GUI_SCROLL_DISP_NONE            = (0),
    GUI_SCROLL_DISP_ICON_UP         = (1<<0),
    GUI_SCROLL_DISP_ICON_DOWN       = (1<<1),
    GUI_SCROLL_DISP_INDEX           = (1<<2),
    GUI_SCROLL_DISP_NEXTPAGE        = (1<<3),
    GUI_SCROLL_DISP_PREVPAGE        = (1<<4),
    GUI_SCROLL_DISP_CUSTOM_INDEX    = (1<<5),
    GUI_SCROLL_DISP_TOP_INDEX       = (1<<6),
    GUI_SCROLL_DISP_FORCE           = (1<<7), /*alway display flag*/
        
    GUI_SCROLL_DISP_FORCE_INDEX     = (1<<8),
    GUI_SCROLL_DISP_FORCE_NEXTPAGE  = (1<<9),
    GUI_SCROLL_DISP_FORCE_PREVPAGE  = (1<<10),
} GUI_SCROLL_DISP_MODE;

#if 0
#define GUI_SCROLL_DISP_FORCE_INDEX  ((GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_INDEX | GUI_SCROLL_DISP_FORCE))
#define GUI_SCROLL_DISP_FORCE_NEXTPAGE  ((GUI_SCROLL_DISP_MODE)(GUI_SCROLL_DISP_NEXTPAGE | GUI_SCROLL_DISP_FORCE))
#endif

typedef enum
{
    GUI_SELECT_NONE            = (0),
    GUI_SELECT_ONE             = (1),
    GUI_SELECT_MULTIPLE        = (2), /*Reserved*/
} GUI_SELECTION_MODE;

typedef enum
{
    GUI_LAYOUT_NONE            = (0),
    GUI_LAYOUT_FIRST           = (1),
    GUI_LAYOUT_LAST            = (2),

}GUI_LAYOUT_MODE; 

#define GUI_SELECTING_NEXTPAGE_IDX  (-1)
#define GUI_SELECTING_PREVPAGE_IDX  (-2)

#define ITEM_INDEX_STR_MAX_LEN    12

#define UI_SCROLL_MODE         (GUI_SCROLL_DISP_INDEX )


typedef enum
{
    #if (EN_EN)
    GUI_LANG_ENGLISH,
    #endif

    #if (SP_EN)
    GUI_LANG_SPANISH,
    #endif

    #if (FR_EN)
    GUI_LANG_FRENCH,
    #endif

    #if (JP_EN)
    GUI_LANG_JAPANESE,
    #endif

    #if (CN_EN)
    GUI_LANG_CHINESE,
    #endif
    
    #if (VN_EN)
    GUI_LANG_VIETNAMESE,
    #endif
    
} GUI_LANGUAGE_ID;

typedef enum
{
    PERMANENTDTC    =(1<<0),
    PENDINGDTC      =(1<<1),
    STOREDTC        =(1<<2),
    FREEZEFRAMEDTC  =(1<<3),
    ABSDTC          =(1<<4),
    SRSDTC          =(1<<5),
    LIBRARYDTC      =(1<<6),
    ENHANCEDTC      =(1<<7),
}GUI_DTC_TYPE;


typedef enum _enumImageFile
{
    eIMAGE_UNKNOWN                  = 0,
    eIMAGE_INNOVA_LOGO              = 1,
    eIMAGE_INNOVA_LOADING           = 2,
    eIMAGE_INNOVA_HOR_VEHICLE       = 3,
    eIMAGE_INNOVA_HOR_LINK          = 4,
    eIMAGE_INNOVA_HOR_COMPUTER      = 5,
    eIMAGE_INNOVA_HOR_BATTERY       = 6,
    eIMAGE_INNOVA_VEHICLE           = 7,
    eIMAGE_INNOVA_LINK              = 8,
    eIMAGE_INNOVA_COMPUTER          = 9,
    eIMAGE_INNOVA_BATTERY           = 10,
    
    eIMAGE_INNOVA_MIS               = 11,
    eIMAGE_INNOVA_FUE               = 12,
    eIMAGE_INNOVA_CCM               = 13,
    eIMAGE_INNOVA_CAT               = 14,
    eIMAGE_INNOVA_HCA               = 15,
    eIMAGE_INNOVA_EVA               = 16,
    eIMAGE_INNOVA_HCC               = 17,
    eIMAGE_INNOVA_NOx               = 18,
    eIMAGE_INNOVA_AIR               = 19,
    eIMAGE_INNOVA_O2S               = 20,
    eIMAGE_INNOVA_HTR               = 21,
    eIMAGE_INNOVA_EGR               = 22,
    eIMAGE_INNOVA_BPS               = 23,
    eIMAGE_INNOVA_EGS               = 24,
    eIMAGE_INNOVA_DPF               = 25,
    
    eIMAGE_INNOVA_MIL               = 26,
    eIMAGE_INNOVA_FF                = 27,
    eIMAGE_INNOVA_IM                = 28,
    eIMAGE_INNOVA_ABS               = 29,
    eIMAGE_INNOVA_SRS               = 30,
    eIMAGE_INNOVA_BTCONNECTED       = 31,
    eIMAGE_INNOVA_BTNOTCONNECT      = 32,
    eIMAGE_INNOVA_HOR_MIL           = 33,
    eIMAGE_INNOVA_CHECK_ICON        = 34,
    eIMAGE_INNOVA_LED_RED           = 35,
    eIMAGE_INNOVA_LED_YELLOW        = 36,
    eIMAGE_INNOVA_LED_GREEN         = 37,
    /*Feb2514*/
    eIMAGE_INNOVA_MIS_RED = 38,
    eIMAGE_INNOVA_FUE_RED = 39,
    eIMAGE_INNOVA_CCM_RED = 40,
    eIMAGE_INNOVA_CAT_RED = 41,
    eIMAGE_INNOVA_HCA_RED = 42,
    eIMAGE_INNOVA_EVA_RED = 43,
    eIMAGE_INNOVA_HCC_RED = 44,
    eIMAGE_INNOVA_NOx_RED = 45,
    eIMAGE_INNOVA_AIR_RED = 46,
    eIMAGE_INNOVA_O2S_RED = 47,
    eIMAGE_INNOVA_HTR_RED = 48,
    eIMAGE_INNOVA_EGR_RED = 49,
    eIMAGE_INNOVA_BPS_RED = 50,
    eIMAGE_INNOVA_EGS_RED = 51,
    eIMAGE_INNOVA_DPF_RED = 52,
    
    /*Lap Dang added for Buttons image*/
    eIMAGE_INNOVA_DTC_BUTTON         ,
    eIMAGE_INNOVA_ENTER_BUTTON         ,
    eIMAGE_INNOVA_ERASE_BUTTON         ,
    eIMAGE_INNOVA_LD_BUTTON         ,
    eIMAGE_INNOVA_LINK_BUTTON         ,
    eIMAGE_INNOVA_MENU_BUTTON         ,
    eIMAGE_INNOVA_POWER_BUTTON         ,
//    eIMAGE_INNOVA_DOWN_BUTTON         ,
//    eIMAGE_INNOVA_UP_BUTTON         ,
    eIMAGE_INNOVA_SYSTEM_BUTTON         ,
	
	/*TranL added for DLC poLap Dangion image*/
    eIMAGE_INNOVA_DLC_POS_INIT,
    eIMAGE_INNOVA_DLC_POS_01,
    eIMAGE_INNOVA_DLC_POS_01_ATV,
    eIMAGE_INNOVA_DLC_POS_02,
    eIMAGE_INNOVA_DLC_POS_02_ATV,
    eIMAGE_INNOVA_DLC_POS_03,
    eIMAGE_INNOVA_DLC_POS_03_ATV,
    eIMAGE_INNOVA_DLC_POS_04,
    eIMAGE_INNOVA_DLC_POS_04_ATV,
    eIMAGE_INNOVA_DLC_POS_05,
    eIMAGE_INNOVA_DLC_POS_05_ATV,
    eIMAGE_INNOVA_DLC_POS_06,
    eIMAGE_INNOVA_DLC_POS_06_ATV,
    eIMAGE_INNOVA_DLC_POS_07,
    eIMAGE_INNOVA_DLC_POS_07_ATV,
    eIMAGE_INNOVA_DLC_POS_08,
    eIMAGE_INNOVA_DLC_POS_08_ATV,
    eIMAGE_INNOVA_DLC_POS_09,
    eIMAGE_INNOVA_DLC_POS_09_ATV,        
    
}enumImageFile;

#define FIST_BUTTON_IMAGE_ENUM  eIMAGE_INNOVA_DTC_BUTTON
#define LAST_BUTTON_IMAGE_ENUM  eIMAGE_INNOVA_SYSTEM_BUTTON


/*==============================================================================
*                                 Structures
==============================================================================*/
typedef struct
{
    sint16 x,y;
} GUI_POINT;

typedef struct
{
    union
    {
        struct
        {
            sint16 x0,y0,x1,y1;
        };
        struct
        {
            GUI_POINT TopLeft;
            GUI_POINT BottomRight;
        };
    };
} GUI_RECT;

typedef struct
{
    uint8 x, y;
} GUI_U8_POINT;

typedef enum
{
    DISP_FULL_MODE,
    DISP_PART_MODE,
}GUI_DISP_MODE;

//Oct0314 Lap Dang moved this struct to Font.h
//typedef struct _structFont
//{
//    char *  name;       /* font name*/
//    int     minwidth;   /* min width in pixels*/
//    int     maxwidth;   /* max width in pixels*/
//    int     height;     /* height in pixels*/
//    int     ascent;     /* ascent (baseline) height*/
//    int     firstchar;  /* first character in bitmap*/
//    int     lastchar;
//    int     charsize;       /* font size in glyphs*/
//    const uint16*   bits;       /* 16-bit right-padded bitmap data*/
//    const uint16*   offset;     /* offsets into bitmap data*/
//    const uint8 *   width;      /* character widths or NULL if fixed*/
//} structFont, *p_structFont;

typedef struct
{
    const structFont*   p_strtFont;
    GUI_RECT            ClipRect;
    sint16              DispPosX, DispPosY;
    GUI_TEXT_MODE       TextMode;
    GUI_TEXT_ALIGN_MODE TextAlignMode;
    /*Hoang Nguyen added*/
    uint16              BackGndColor;
    uint16              TextColor;
} GUI_WINDOW;

typedef struct
{
    const structFont* p_strtBigFont;
    const structFont* p_strtNormalFont;
    const structFont* p_strtSmallFont;

    GUI_RECT ClientRect;
    
    //Titile
    GUI_TEXT_ALIGN_MODE TitleAlignMode;
    GUI_TEXT_MODE TitleTextMode;
    uint16 TitleBackGndColor;
    uint16 TitleTextColor;
    
    //Description
    /*March0414 Lap Dang added*/
    GUI_TEXT_ALIGN_MODE DescriptionAlign;
    GUI_TEXT_MODE DescriptionTextMode;
    uint16 DescriptionBackGndColor;
    uint16 DescriptionTextColor;
    
    //Description 1  
    /*Dec1514 TranL added as TungNguyen resource*/
    GUI_TEXT_ALIGN_MODE Description1Align;
    GUI_TEXT_MODE Description1TextMode;
    uint16 Description1BackGndColor;
    uint16 Description1TextColor;
	
    //Description 2  
    /*Dec1514 TranL added as TungNguyen resource*/
    GUI_TEXT_ALIGN_MODE Description2Align;
    GUI_TEXT_MODE Description2TextMode;
    uint16 Description2BackGndColor;
    uint16 Description2TextColor;
    
    //Instruction
    GUI_TEXT_ALIGN_MODE InstructionAlign;
    GUI_TEXT_MODE InstructionTextMode;
    uint16 InstructionBackGndColor;
    uint16 InstructionTextColor;

    //Ratio
    GUI_TEXT_ALIGN_MODE RatioAlignMode;
    GUI_TEXT_MODE RatioTextMode;
    uint16 RatioBackGndColor;
    uint16 RatioTextColor;

    //Body
    GUI_TEXT_ALIGN_MODE BodyAlignMode;
    GUI_TEXT_MODE BodyTextMode;
    uint16 BodyBackGndColor;
    uint16 BodyTextColor;

    //Footer
    GUI_TEXT_ALIGN_MODE FooterAlignMode;
    GUI_TEXT_MODE FooterTextMode;
    uint16 FooterBackGndColor;
    uint16 FooterTextColor;
    //Oct0414 Lap Dang added for ON/OFF footer
    enumbool    blFooterOnOff;

    //DTC Info
    GUI_TEXT_ALIGN_MODE DTCInfoAlignMode;
    GUI_TEXT_MODE DTCInfoTextMode;
    uint16 DTCInfoBackGndColor;
    uint16 DTCInfoTextColor;

    GUI_SCROLL_DISP_MODE TextScrollMode;
    GUI_SCROLL_DISP_MODE MenuScrollMode;

    GUI_TEXT_ALIGN_MODE ListItemAlignMode;
    GUI_SELECTION_MODE  ListSelectionMode;
    GUI_LANGUAGE_ID  LanguageID;
    GUI_LAYOUT_MODE  LayoutMode; //Long To add
    
    uint16      FirstGraphColor;
    uint16      SecondGraphColor;
    
    
} GUI_CONTEXT;

typedef struct
{
    int       bCurentBodyLine;
    int       bNumBodyLines;
    int       bAvailBodyLines;
    int       iCurrentSelectedLine;
    int       iNumberSelectableLine;
    GUI_RECT    ClientRect;

    const void* strTitle;
    const void* strInstruction;
    const void* strBody;
    const void* strFooter;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndBody;
    GUI_WINDOW  WndFooter;
} GUI_TEXT_FORM;

typedef struct
{
    uint8       bCurrentDTCIdx;
    uint8       bTotalDTC;
    GUI_DTC_TYPE eDTCType;

    uint8       bCurentBodyLine;
    uint8       bNumBodyLines;
    uint8       bAvailBodyLines;
    GUI_RECT    ClientRect;

    const uint8* strDTCCode;
    const void*  strDTCInfo;
    const void*  strDTCDefinition;
    const void*  strDTCOEMInfo;
    const void*  strDTCOEMDefinition;
    const void*  strFooter;
    
    /*Sep 25, 2013: Hoang Nguyen added WndFixTitle to show Fix Title*/
    const void*  strFixTitle;
    GUI_WINDOW  WndFixTitle;
    
    GUI_WINDOW  WndDTCCode;
    GUI_WINDOW  WndDTCInfo;
    GUI_WINDOW  WndDTCDefinition;
    GUI_WINDOW  WndDTCIndex;
    GUI_WINDOW  WndFooter;
} GUI_DTC_FORM;

typedef struct
{
    GUI_RECT    ClientRect;

    const uint8* strTitle;
    const void*  strBody;
    const void*  strFooter;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndBody;
    GUI_WINDOW  WndFooter;
} GUI_FLASH_SCREEN_FORM;

typedef struct
{
    uint8       bCurrentDigitIdx;
    uint8       bTotalDigit;

    GUI_RECT    ClientRect;

    const uint8* strTitle;
    uint8        strDigits[15];
    const void*  strFooter;
    
    /*Jan2114 Lap Dang added instruction field*/
    const void*     strInstruction;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndBody;
    /*Jan2114 Lap Dang added instruction field*/
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndFooter;
    GUI_WINDOW  WndBoldDigit;
} GUI_DIGIT_SELECTION_FORM;

/*
    Define max number Item could display on screen (not all item)
*/

typedef struct
{
    GUI_RECT    ItemContainerRect;

    const structFont* p_strtItemFont;

    uint8   bNumberItem; /* number item in the list */
    uint8   bNumDispCol; /* number column are displayed items */
    const uint16* p_wWidthList;
    GUI_TEXT_ALIGN_MODE eItemAlignMode;
    GUI_SELECTION_MODE SelectionMode;
    GUI_SCROLL_DISP_MODE DispScrollMode;
    
    uint8   bFirstDispItem;   /*First item/Total Item*/
    uint8   bLastDispItem;
    uint8   bPrevFirstItem;
    sint32  iSelectedItem;    /*Selected item/Total Item*/
    GUI_TEXT_MODE  ItemTextMode;
    GUI_LAYOUT_MODE  LayoutMode;
    const void* const* p_strItemList;
    
	//TungMN added
	enumbool blArrayCmd[MAX_NUMBER_LIST_ITEM];
    
    //LongTo Add
    sint32   iCurrentIndex;
    sint32   iNumberIndex;
} GUI_LIST;

/*2Column (Info - Value) list*/
typedef struct
{
    GUI_RECT    ItemContainerRect;
    sint32      iInfoMaxXPixel;
    sint32      iValueMaxXPixel;

    const structFont* p_strtItemFont;

    uint8   bNumberItem; /* number item in the list */
    uint8   bNumberActiveItem;
    GUI_TEXT_ALIGN_MODE eItemAlignMode;
    GUI_SELECTION_MODE  SelectionMode;

    uint8   bFirstDispItem;   /*First item/Total Item*/
    uint8   bLastDispItem;
    uint8   bPrevFirstItem;
    sint32  iSelectedItem;    /*Selected item/Total Item*/

    //LongTo Add
    sint32   iCurrentIndex;
    sint32   iNumberIndex;

    GUI_TEXT_MODE  ItemTextMode;
    GUI_TEXT_MODE  ValueTextMode;

    const void* const* p_strItemList;
    const void* const* p_strValueList;
} GUI_INFO_VALUE_LIST;

typedef struct
{
    GUI_LIST    strtGuiList;
    GUI_RECT    ClientRect;

    GUI_SCROLL_DISP_MODE DispScrollMode;

    const void* strTitle;
    const void* strNextPage;
    const void* strPrevPage;
    const void* strDescription;/*March0414 Lap Dang added*/
    const void* strInstruction;
    const void* strFooter;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndNextPage;
    GUI_WINDOW  WndPrevPage;
    GUI_WINDOW  WndDescription;/*March0414 Lap Dang added*/
    GUI_WINDOW  WndItemIndex;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndFooter;

} GUI_MENU_FORM;

typedef struct
{
    GUI_INFO_VALUE_LIST    strtGuiInfoValueList;
    GUI_RECT    ClientRect;

    GUI_SCROLL_DISP_MODE      DispScrollMode;

    const void* strTitle;
    const void* strInstruction;
    const void* strFooter;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndItemIndex;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndFooter;

} GUI_INFO_VALUE_FORM;

typedef struct
{
    uint8 bNumberItem;
    uint16 sImageMaxXPixel;
    
    uint8 bCurImageItem;
    uint8 bAvailImageItem;
    
    GUI_RECT    ClientRect;
    GUI_RECT    ImageItemRect;
    
    const structFont* p_strtItemFont;
    
    const void* strTitle;
    const void* strInstruction;
    const void* strFooter;
    
    const void* const* p_strItemList;
    enumImageFile* p_ImageList;
        
    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndFooter;

} GUI_INFO_IMAGE_FORM;

typedef struct
{
    float        fyValue;
    GUI_POINT    strtPoint;
} GRAPH_POINT;
typedef struct
{
    GUI_RECT   ClientRect;
    GUI_RECT   GraphRect;

    uint16      xAxis; /*origin (0,0) at (xPixel, y)*/
    uint8      yAxis;

    GRAPH_POINT PointList[150];

    uint8      bNumberPoint;
    uint8      bStartPointIndex;
    int        iEndPointIndex;
    uint8      bMarkerIndex;
    sint32      bRefX;
    uint8      bPrecision;
    float      fGlobalMinValue;
    float      fGlobalMaxValue;
    float      fCurrentMin; /*Min value disp at base line*/
    float      fCurrentMax;
    const void* strTitle;
    const void* strInstruction;
    const void* strFooter;
    const void* strFrameTitle;
    const void* strXUnit;
    uint16 strMinValue[10];
    uint16 strMaxValue[10];
    uint16 strValue[10];

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndValue;
    GUI_WINDOW  WndFrameTitle;

    GUI_WINDOW  WndMax;
    GUI_WINDOW  WndMin;
    GUI_WINDOW  WndXUnit;
    uint8       bDefaultXIndent;
} GUI_GRAPH_FORM;

typedef struct
{
    GUI_RECT    ProgBarRect;
    uint8       bPercent;
    GUI_WINDOW  WndText;
    const void* strText;
}GUI_PROGBAR_FORM;

typedef enum
{
    GUI_ICON_OFF   = 0,
    GUI_ICON_ON    = 1,
    GUI_ICON_FLASH = (1<<7)
} enumGUI_ICON_STATUS;

typedef enum
{
    ICON_NONE,
    CAR_ICON,
    RIGHT_ICON,
    COMPUTER_ICON,
    BATTERY_ICON,
    LEFT_ICON,
    IM_ICON,
    M_ICON,
    AA_ICON,
    F_ICON,
    O_ICON,
    CC_ICON,
    MONITOR_ICON,
    OH_ICON,
    C_ICON,
    E_ICON,
    HC_ICON,
    STATUS_ICON,
    BP_ICON,
    EV_ICON,
    EG_ICON,
    NM_ICON,
    P_ICON,
    MILON_ICON,
    N_ICON,
    PENDING_ICON,
    PERMANENT_ICON,
    FREEZEFRAME_ICON,
    SLASH_ICON,
    IMMONITORSTATUS_ICON,
    LINK_ICON,
    ABS_ICON,
    SRS_ICON,
    ANTENNA_ICON,
    //smal MIL ON icon
    MILON_SMALL_ICON,
} enumGUI_ICON;

typedef enum
{
    DIGIT1,
    DIGIT2,
    DIGIT3,
    DIGIT4,
} enumGUI_DIGIT_ICON;

typedef struct
{
    enumGUI_ICON            eIcon;
    enumGUI_ICON_STATUS     eStatus;
    enumbool                eIsChange;
} structGUI_ICON;

typedef enum
{
    GUI_DISPLAY_OFF   = 0,
    GUI_DISPLAY_ON    = 1,
    GUI_DISPLAY_FLASH = (1<<7)
} enumGUI_DISPLAY_STATUS;

typedef enum
{
    LCD_AREA_NONE                     = (0),
    LCD_AREA_CONNECTION_ICONS         = (1<<0),
    LCD_AREA_DTC_INFO_ICONS           = (1<<1),
    LCD_AREA_IM_MONITOR_STATUS_ICONS  = (1<<2),
    LCD_AREA_DTC_INDEX_ICONS          = (1<<3),
    LCD_AREA_TEXT                     = (1<<4),
    LCD_AREA_ICONS_EXCEPT_CONNECTION  = (LCD_AREA_DTC_INFO_ICONS | \
                                         LCD_AREA_IM_MONITOR_STATUS_ICONS | \
                                         LCD_AREA_DTC_INDEX_ICONS),
    LCD_AREA_ALL                      = (0xFF),
} enumGUI_LCD_AREA;

#define LCD_AREA_ALLICONS_MASK           (LCD_AREA_CONNECTION_ICONS | \
                                          LCD_AREA_DTC_INFO_ICONS | \
                                          LCD_AREA_IM_MONITOR_STATUS_ICONS | \
                                          LCD_AREA_DTC_INDEX_ICONS)

#define GUI_NUMBER_ICON             40
#define GUI_NUMBER_CONNECTION_ICON  4 /*LinkR, LinkL, Battery, USB*/
#define GUI_NUMBER_IM_MON_ICON      16
#define GUI_NUMBER_DTC_INFO_ICON    6//Jan0215 Lap Dang increase from 5 to 6 to add small MIL icon

/*Note: Change any field in this structure without using built-in function is
not recommended*/
typedef struct
{
    structGUI_ICON ConnectionIcons[GUI_NUMBER_CONNECTION_ICON + 1];
    structGUI_ICON IMMonIcons[GUI_NUMBER_IM_MON_ICON + 1];
    structGUI_ICON DTCInfoIcons[GUI_NUMBER_DTC_INFO_ICON + 1];
    structGUI_ICON IMMonStatusIcon;
    structGUI_ICON DTCIndexIcon;
    uint8 bDigits[4];
    enumbool blIMMonEnable;
} GUI_IM_MONITOR_ICON;

/*Hoang Nguyen added*/
typedef enum
{
    LD_GRAPH_DEACTIVE = 0,
    LD_GRAPH_ACTIVE,
    LD_GRAPH_FREEZE
}enumLD_GRAPH_STATUS;

typedef struct
{
    enumLD_GRAPH_STATUS eLDGraphStat;
    uint16               bLDItemIndex;
}structLDGraphItem;

typedef struct
{
    sint8               bsOffset;
    structLDGraphItem   arrListLdGraph[2];
}structLDGraph;

typedef enum 
{
    ICON_DISP_NONE = 0,
    ICON_DISP_IMMON = 1,
    ICON_DISP_MINIMIZE = 2
}enumICON_DISP_TYPE;


#define LCD_COLOR_WHITE          0xFFFF
#define LCD_COLOR_BLACK          0x0000
#define LCD_COLOR_GREY           0xF7DE
#define LCD_COLOR_BLUE           0x001F
#define LCD_COLOR_BLUE2          0x051F
#define LCD_COLOR_RED            0xF800
#define LCD_COLOR_MAGENTA        0xF81F
#define LCD_COLOR_GREEN          0x07E0
#define LCD_COLOR_CYAN           0x7FFF
#define LCD_COLOR_YELLOW         0xFFE0


//Nov1414 Lap Dang added as TranLuu resource
typedef struct
{
    uint8       bCurentBodyLine;
    uint8       bNumBodyLines;
    uint8       bAvailBodyLines;
  
    uint8       bCurentTitleLine;
    uint8       bNumTitleLines;
    uint8       bAvailTitleLines;
    
    uint8       bCurentDescription1Line;
    uint8       bNumDescription1Lines;
    uint8       bAvailDescription1Lines;
    
    uint8       bCurentInstructionLine;
    uint8       bNumInstructionLines;
    uint8       bAvailInstructionLines;

    uint8       bCurentDescription2Line;
    uint8       bNumDescription2Lines;
    uint8       bAvailDescription2Lines;
    
    uint8       bCurentFooterLine;
    uint8       bNumFooterLines;
    uint8       bAvailFooterLines;
    
    uint8       iCurrentSelectedLine;
    uint8       iNumberSelectableLine;
    
    GUI_RECT    ClientRect;

    const void* strTitle;
    const void* strDescription1;
    const void* strInstruction;
    const void* strBody;
    const void* strDescription2;
    const void* strFooter;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndDescription1;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndBody;
    GUI_WINDOW  WndDescription2;
    GUI_WINDOW  WndFooter;
} 
INN_GUI_TEXT_FORM;

typedef struct
{
    uint8       bCurentBodyLine;
    uint8       bNumBodyLines;
    uint8       bAvailBodyLines;
  
    uint8       bCurentTitleLine;
    uint8       bNumTitleLines;
    uint8       bAvailTitleLines;
    
    uint8       bCurentDescription1Line;
    uint8       bNumDescription1Lines;
    uint8       bAvailDescription1Lines;
    
    uint8       bCurentInstructionLine;
    uint8       bNumInstructionLines;
    uint8       bAvailInstructionLines;

    uint8       bCurentDescription2Line;
    uint8       bNumDescription2Lines;
    uint8       bAvailDescription2Lines;
    
    uint8       bCurentFooterLine;
    uint8       bNumFooterLines;
    uint8       bAvailFooterLines;
    
    uint8       iCurrentSelectedLine;
    uint8       iNumberSelectableLine;
    
    GUI_RECT    ClientRect;

    const void* strTitle;
    const void* strDescription1;
    const void* strInstruction;
    const void* strCommand;
    const void* strValue;
    const void* strOption;
    const void* strDescription2;
    const void* strFooter;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndDescription1;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndCommand;
    GUI_WINDOW  WndValue;
    GUI_WINDOW  WndDescription2;
    GUI_WINDOW  WndFooter;
} 
INN_GUI_TEXT_RESULT;
//Dec0814 TranL added 
typedef struct
{  
    uint8       bCurentTitleLine;
    uint8       bNumTitleLines;
    uint8       bAvailTitleLines;
    
    uint8       bCurentDescription1Line;
    uint8       bNumDescription1Lines;
    uint8       bAvailDescription1Lines;
    
    uint8       bCurentInstructionLine;
    uint8       bNumInstructionLines;
    uint8       bAvailInstructionLines;

    uint8       bCurentDescription2Line;
    uint8       bNumDescription2Lines;
    uint8       bAvailDescription2Lines;
    
    uint8       bCurentFooterLine;
    uint8       bNumFooterLines;
    uint8       bAvailFooterLines;
    
    uint8       bCurrentSelectedLine;
    uint8       bNumberSelectableLine;
    uint8       bAvailSelectableLines;
    
    GUI_LIST    strtGuiList;
    GUI_RECT    ClientRect;
    
    uint8       eField;
    
    uint8       bCharInButton_IDX;
    enumbool    blBtn_Changed;
    uint8       bCharPos;
    enumbool    blOptionMode;

    GUI_SCROLL_DISP_MODE DispScrollMode;

    const void* strTitle;
    const void* strDescription1;
    const void* strInstruction;
    const void* strInputText;
    const void* strOption;
    const void* strDescription2;
    const void* strFooter;
    const void* strNextPage;
    const void* strPrevPage;

    GUI_WINDOW  WndTitle;
    GUI_WINDOW  WndDescription1;
    GUI_WINDOW  WndInstruction;
    GUI_WINDOW  WndInputText;
    GUI_WINDOW  WndItemIndex;
    GUI_WINDOW  WndOption;
    GUI_WINDOW  WndDescription2;
    GUI_WINDOW  WndFooter;
} 
INN_GUI_INPUT_TEXT_FORM;
typedef struct
{
  GUI_RECT    ClientRect;
  GUI_RECT    InitDLCPos_rect;
  enumbool    blActive;
  
  const void*  strTitle;
  const void*  strAccess;
  const void*  strCommand;
  const void*  strFooter;
  
  uint8 bCurentCommandLine;
  uint8 bNumCommandLines;
  uint8 bAvailCommandLines;
  
  GUI_WINDOW  WndTitle;
  GUI_WINDOW  WndAccess;
  GUI_WINDOW  WndCommand;
  GUI_WINDOW  WndFooter;
} INN_GUI_DLC_LOCATOR_FORM;

/*Dec1514 TranL added as TungNguyen resource*/
typedef struct
{
  uint8       bCurrentTitleLine;
  uint8       bNumTitleLines;
  uint8       bAvailTitleLines;	
  enumbool    blTitleUpdateEnable;
  
  uint8       bCurrentDscrp1Line;
  uint8       bNumDscrp1Lines;
  uint8       bAvailDscrp1Lines;	
  enumbool    blDscrp1UpdateEnable;
  
  uint8       bCurrentInstrLine;
  uint8       bNumInstrLines;
  uint8       bAvailInstrLines;	
  enumbool    blInstrUpdateEnable;
  
  uint8       bCurrentDscrp2Line;
  uint8       bNumDscrp2Lines;
  uint8       bAvailDscrp2Lines;
  enumbool    blDscrp2UpdateEnable;
  
  uint8       bCurrentFooterLine;
  uint8       bNumFooterLines;
  uint8       bAvailFooterLines;	
  enumbool    blFooterUpdateEnable;
  
  uint8       bCurrentBodyLine;
  uint8       bNumBodyLines;
  uint8       bAvailBodyLines;
  enumbool    blBodyUpdateEnable;
  
  uint8       bTotalAvailLines;
  uint8       bTotalNumberLines;
  
  int       	iCurrentSelectedLine;
  int       	iNumberSelectableLine;
  GUI_RECT    ClientRect;
  
  const void* strTitle;
  const void* strDescription1;
  const void* strInstruction;
  const void* strBody;
  const void* strDescription2;
  const void* strFooter;
  
  GUI_WINDOW  WndTitle;
  GUI_WINDOW	WndDescription1;
  GUI_WINDOW  WndInstruction;
  GUI_WINDOW  WndBody;
  GUI_WINDOW	WndDescription2;
  GUI_WINDOW  WndFooter;
  
  enumbool blScrollEnable;
  
} INN_GUI_GENERAL_TEXT_FORM;


/*2 Column (Info - Value) list*/            //  Item --- Value
typedef struct
{
  GUI_RECT    ItemContainerRect;
  uint32      iInfoMaxXPixel;
  uint32      iValueMaxXPixel;
  
  const structFont* p_strtItemFont;
  
  uint8   bNumberItem; 		    // number of Items in the list 
  uint8   bNumberActiveItem;
  uint16 	bNumberItemNoCmd;	    // number of Items do not include Commands 
  
  GUI_TEXT_ALIGN_MODE eItemAlignMode;
  GUI_SELECTION_MODE  SelectionMode;
  
  uint8   bFirstDispItem;   	    // First display Item in screen. 
  uint8   bLastDispItem;		    // Last display Item in screen. 
  sint32  iSelectedItem;    	
  
  sint32   iCurrentIndex;
  sint32   iNumberIndex;
  
  GUI_TEXT_MODE  ItemTextMode;
  GUI_TEXT_MODE  ValueTextMode;
  
  const void* const* p_strItemList;
  const void* const* p_strValueList;
  
  enumbool IsCheckListOnTheLeft;  // use for Custom Form
  // if no use ---> eTRUE or eFALSE is OK
} INN_GUI_INFO_VALUE_LIST;

typedef struct
{
  INN_GUI_INFO_VALUE_LIST    strtGuiInfoValueList;
  GUI_RECT    ClientRect;
  
  GUI_SCROLL_DISP_MODE      DispScrollMode;
  
  const void* strTitle;
  const void* strDescription1;
  const void* strInstruction;
  const void* strSubBody;
  const void* strDescription2;
  const void* strFooter;
  
  uint8       bCurrentSubBodyLine;
  uint8       bNumSubBodyLines;
  uint8       bAvailSubBodyLines;
  enumbool    blSubBodyUpdateEnable;
  
  const void* strCmd1;		// return Idx = -1
  const void* strCmd2;		// return Idx = -2
  const void* strCmd3;		// return Idx = -3
  
  GUI_WINDOW  WndTitle;
  GUI_WINDOW  WndDescription1;
  GUI_WINDOW  WndInstruction;
  GUI_WINDOW  WndSubBody;
  GUI_WINDOW  WndDescription2;
  GUI_WINDOW  WndFooter;
  GUI_WINDOW  WndItemIndex;
  
} INN_GUI_INFO_VALUE_FORM;


typedef struct
{
  GUI_LIST    strtGuiList;
  GUI_RECT    ClientRect;
  
  const void* strNextPage;
  const void* strPrevPage;
  
  GUI_WINDOW  WndNextPage;
  GUI_WINDOW  WndPrevPage;
  GUI_WINDOW  WndItemIndex;
  
  GUI_SCROLL_DISP_MODE 	DispScrollMode;
  
} INN_GUI_MENU_FORM;
#endif
