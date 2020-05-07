/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIDRAW_H__
#define __GUIDRAW_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIDRAW_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_DrawImage(GUI_WINDOW* p_strtWnd, int x0, int y0, int xSize, int ySize,
                   const uint8* p_wCharImage, uint8 bTransparentColor);
#if 1
void GUI_DrawPixel(GUI_WINDOW* p_strtWnd, int x0, int y0, int c, uint16 color);
void GUI_DrawPixelToBuffer(GUI_WINDOW* p_strtWnd, int x0, int y0, int c, uint16 color);
void GUI_DrawVLine(GUI_WINDOW* p_strtWnd, int x0, int y0, int y1, uint16 color);
void GUI_DrawVLineToBuffer(GUI_WINDOW* p_strtWnd, int x0, int y0, int y1, uint16 color);
void GUI_DrawHLine(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, uint16 color);
void GUI_DrawHLineToBuffer(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, uint16 color);
void GUI_DrawLine(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, int y1, uint16 color);
void GUI_DrawRect(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, int y1, uint16 color);
void GUI_DrawRectToBuffer(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, int y1, uint16 color);
void GUI_DrawTriangle(GUI_WINDOW* p_strtWnd, int x1, int y1, int x2, int y2, int x3, int y3, uint16 color);
#else
void GUI_DrawPixel(GUI_WINDOW* p_strtWnd, int x0, int y0, int c);
void GUI_DrawVLine(GUI_WINDOW* p_strtWnd, int x0, int y0, int y1);
void GUI_DrawHLine(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1);
void GUI_DrawLine(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, int y1);
void GUI_DrawRect(GUI_WINDOW* p_strtWnd, int x0, int y0, int x1, int y1);
void GUI_DrawTriangle(GUI_WINDOW* p_strtWnd, int x1, int y1, int x2, int y2, int x3, int y3);
#endif
#endif
