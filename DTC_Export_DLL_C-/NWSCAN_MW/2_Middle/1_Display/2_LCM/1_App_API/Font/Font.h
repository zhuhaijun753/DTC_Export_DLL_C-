/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __FONT_H__
#define __FONT_H__
#define   LINK_ICON_CHAR        0x10
#define   LinkIconStr          "\x10"
#define   UniLinkIconStr       L"\x10"

#define   EraseIconStr         "\x11"
#define   UniEraseIconStr      L"\x11"
#define   ERASE_ICON_CHAR         0x11

#define   EnterIconStr         "\x12"
#define   UniEnterIconStr       L"\x12"
#define   ENTER_ICON_CHAR         0x12

#define   UpArrowIconStr       "\x13"
#define   UPARROW_ICON_CHAR       0x13

#define   DownArrowIconStr     "\x14"
#define   DOWNARROW_ICON_CHAR     0x14

#define   UpDownArrowIconStr   "\x15"
#define   UPDOWNARROW_ICON_CHAR   0x15

#define   UnCheckIconStr       "\x16"
#define   UNCHECK_ICON_CHAR       0x16

#define   CheckIconStr         "\x17"
#define   CHECK_ICON_CHAR         0x17

#define   Reserved1IconStr          "\x18"
#define   Reserved2IconStr          "\x19"
#define   CheckIconColorStr         "\x1A"
#define   LedRedIconStr             "\x1B"
#define   LedYellowIconStr          "\x1C"
#define   LedGreenIconStr           "\x1D"

/*Lap Dang added to define other buttons image*/
#define FIST_BUTTON_IMAGE               0x01

#define FIST_BUTTON_IMAGE_STR               "\x01"
#define SECOND_BUTTON_IMAGE_STR             "\x02"
#define THIRD_BUTTON_IMAGE_STR              "\x03"
#define FOURTH_BUTTON_IMAGE_STR             "\x04"
#define FIVETH_BUTTON_IMAGE_STR             "\x05"
#define SIXTH_BUTTON_IMAGE_STR              "\x06"
#define SEVENTH_BUTTON_IMAGE_STR            "\x07"
#define EIGHTH_BUTTON_IMAGE_STR             "\x08"

#define DTC_BUTTON_IMAGE            FIST_BUTTON_IMAGE_STR
#define ENTER_BUTTON_IMAGE          SECOND_BUTTON_IMAGE_STR
#define ERASE_BUTTON_IMAGE          THIRD_BUTTON_IMAGE_STR
#define LD_BUTTON_IMAGE             FOURTH_BUTTON_IMAGE_STR
#define LINK_BUTTON_IMAGE           FIVETH_BUTTON_IMAGE_STR
#define MENU_BUTTON_IMAGE           SIXTH_BUTTON_IMAGE_STR
#define POWER_BUTTON_IMAGE          SEVENTH_BUTTON_IMAGE_STR
#define SYSTEM_BUTTON_IMAGE         EIGHTH_BUTTON_IMAGE_STR


#define LAST_BUTTON_IMAGE           0x08

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
//Oct0314 Lap Dang moved this struct to Font.h
typedef struct _structFont
{
    char *  name;       /* font name*/
    int     minwidth;   /* min width in pixels*/
    int     maxwidth;   /* max width in pixels*/
    int     height;     /* height in pixels*/
    int     ascent;     /* ascent (baseline) height*/
    int     firstchar;  /* first character in bitmap*/
    int     lastchar;
    int     charsize;       /* font size in glyphs*/
    const unsigned short*   bits;       /* 16-bit right-padded bitmap data*/
    const unsigned short*   offset;     /* offsets into bitmap data*/
    const unsigned char *   width;      /* character widths or NULL if fixed*/
} structFont, *p_structFont;



/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __FONT_C__

#else
extern const structFont g_strtSmallFont;
extern const structFont g_strtNormalFont ;
extern const structFont g_strtDTCBigFont;
#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

#endif
