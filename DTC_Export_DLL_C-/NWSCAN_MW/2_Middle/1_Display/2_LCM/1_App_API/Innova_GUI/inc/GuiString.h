/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUISTRING_H__
#define __GUISTRING_H__

#pragma pack(1)
typedef struct _structColorIconDispInfo
{
    uint16 x;
    uint16 y;
    enumImageFile eImageFile;
}structColorIconDispInfo;
#pragma pack()

/*Jan0214 Lap Dang modified*/
#define MAX_ICON_DISP_INFO_LIST 8
#pragma pack(1)
typedef struct _structColorIconBuffer
{
    uint8 bNoIcon;
#if 1/**/
    structColorIconDispInfo strtInfoList[MAX_ICON_DISP_INFO_LIST];
#else
    structColorIconDispInfo strtInfoList[4];
#endif
    
}structColorIconBuffer;
#pragma pack()

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

//#ifdef __GUISTRING_C__
//structColorIconBuffer g_strtColorIconBuffer;
//#else
extern structColorIconBuffer g_strtColorIconBuffer;
//#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
uint8 GUI_GetCharWidth(const structFont* p_strtFont, uint16 wChar);
int GUI_GetStringLines(const void* s, const structFont* p_strtFont,
                       GUI_TEXT_MODE TextMode, int iMaxXPixel);
void GUI_DispNextLine(GUI_WINDOW* p_strtWnd);
int GUI_GetStringDistX(const void** s, const structFont* p_strtFont,
                       GUI_TEXT_MODE TextMode, int iMaxXPixel, int* iLineLen);
int GUI_GetStringLines(const void* s, const structFont* p_strtFont,
                       GUI_TEXT_MODE TextMode, int iMaxXPixel);
const void* GUI_GetStringLineOffset(const void* s, const structFont* p_strtFont,
                                    GUI_TEXT_MODE TextMode, int iMaxXPixel,
                                    int nLines);
void GUI_GetMultiStringLineOffset(const void* p_arrStr[], uint8* bNoStr,
                                         const structFont* p_strtFont,
                                         GUI_TEXT_MODE TextMode, int iMaxXPixel,
                                         int nLines);
int GUI_GetTextScroll(uint8 bCurrentItem, uint8 bTotalItem,
                      uint8 bAvailDispItem, sint32 ScrollMode);
#if 1
int GUI_GetWordMaxDistX(const void* s, const structFont* p_strtFont,
                        GUI_TEXT_MODE TextMode);
const void* GUI_DispString(GUI_WINDOW* p_strtWnd, const void* s, uint16 color);
const void* GUI_DispStringToBuffer(GUI_WINDOW* p_strtWnd, const void* s, uint16 color);
void GUI_DispCharAt(GUI_WINDOW* p_strtWnd, uint16 c, sint16 x, sint16 y, uint16 color, enumbool blDispToLcd);
void GUI_DispChar(GUI_WINDOW* p_strtWnd, uint16 c, uint16 color);
void GUI_DispCharToBuffer(GUI_WINDOW* p_strtWnd, uint16 c, uint16 color);
void GUI_DispStringLen(GUI_WINDOW* p_strtWnd, const void* s, sint32 iLen, uint16 color);
void GUI_DispStringLenToBuffer(GUI_WINDOW* p_strtWnd, const void* s, sint32 iLen, uint16 color);
const void* GUI_DispMultiString(GUI_WINDOW* p_strtWnd, const void* p_arrStr[], 
                                uint8 bNoStr, uint16 color);
const void* GUI_DispHighlightString(GUI_WINDOW* p_strtWnd, const void* s, int iHighlightLine);
#else
const void* GUI_DispString(GUI_WINDOW* p_strtWnd, const void* s);
void GUI_DispCharAt(GUI_WINDOW* p_strtWnd, uint16 c, sint16 x, sint16 y);
void GUI_DispChar(GUI_WINDOW* p_strtWnd, uint16 c);
void GUI_DispStringLen(GUI_WINDOW* p_strtWnd, const void* s, sint32 iLen);
#endif

void UpdateColorIconInfoToBuffer(uint16 x, uint16 y, enumImageFile eImageFile);
void GUI_ClearColorIconBuffer(void);
void GUI_DispColorIconFromBuffer(void);
#endif
