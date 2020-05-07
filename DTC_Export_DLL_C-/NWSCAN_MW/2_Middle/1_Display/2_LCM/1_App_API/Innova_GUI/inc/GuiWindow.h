/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIWINDOW_H__
#define __GUIWINDOW_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

//#ifdef __GUIWINDOW_C__
//GUI_WINDOW GUI_ClientWnd;
//#else
extern GUI_WINDOW GUI_ClientWnd;
//#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
/*inline*/ void         GUI_GetDefaultWnd(GUI_WINDOW** p_strtWnd);
sint32              GUI_RectGetWidth(GUI_RECT *pRect);
sint32              GUI_RectGetHeight(GUI_RECT *pRect);
void                GUI_RectMove(GUI_RECT *pRect, int x, int y);

GUI_WINDOW*         GUI_ClientWndGet(void);
const structFont*   GUI_WndFontSet(GUI_WINDOW* p_strtWnd,
                                const structFont* p_strtFont);
const structFont*   GUI_WndFontGet(GUI_WINDOW* p_strtWnd);
GUI_TEXT_MODE GUI_WndSetTextMode(GUI_WINDOW* p_strtWnd, GUI_TEXT_MODE TextMode);
GUI_TEXT_MODE GUI_WndGetTextMode(GUI_WINDOW* p_strtWnd);
GUI_TEXT_ALIGN_MODE GUI_WndSetTextAlign(GUI_WINDOW* p_strtWnd,
                                        GUI_TEXT_ALIGN_MODE TextAlignMode);
GUI_TEXT_ALIGN_MODE GUI_WndGetTextAlign(GUI_WINDOW* p_strtWnd);
void GUI_RectInvert(GUI_RECT *pRect);
void GUI_RectInvertToBuffer(GUI_RECT *pRect);
void GUI_RectClip(GUI_RECT* pRect, GUI_RECT* pContainerRect);
#if 1
void GUI_RectFill(GUI_RECT *pRect, uint8 bColor, uint16 color);
void GUI_RectFillToBuffer(GUI_RECT *pRect, uint8 bColor, uint16 color);
GUI_SCROLL_DISP_MODE GUI_InPageScrollAdjust(GUI_SCROLL_DISP_MODE eDispMode);
void GUI_WindowInit(GUI_WINDOW* p_strtWnd,
                    GUI_RECT* p_strtRect,
                    const structFont* p_strtFont,
                    GUI_TEXT_MODE TextMode,
                    GUI_TEXT_ALIGN_MODE TextAlign,
                    uint16 BackGndColor,
                    uint16 TextColor,
                    enumbool blIsUpdateText);
#else
void GUI_RectFill(GUI_RECT *pRect, uint8 bColor);
void                GUI_WindowInit(GUI_WINDOW* p_strtWnd,
                                   GUI_RECT* p_strtRect,
                                   const structFont* p_strtFont,
                                   GUI_TEXT_MODE TextMode,
                                   GUI_TEXT_ALIGN_MODE TextAlign);
#endif
#endif
