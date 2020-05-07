/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUILCDDRIVER_H__
#define __GUILCDDRIVER_H__

#include    "GUIApp_Driver_Interface_Macro.h"
#include    "GUIApp_Driver_Interface.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
extern int LcdGetXSize(void);
extern int LcdGetYSize(void);


extern void LcdIconLoadAll(void);
extern void LcdIconClearAll(void);


extern void LcdLoadBuffer(void);
extern void LcdClearBuffer(void);

extern void LcdIconClearAll(void);
extern void LcdIconLoadAll(void);

extern void LcdIconSet(enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);
extern void LcdDigit(enumGUI_DIGIT_ICON eNumberDigit, uint8 bValueDigit);
extern void LcdCacheSetPixel(uint16 x, uint16 y, uint16 c, uint16 color);
extern void LcdCacheXorPixel(int x, int y, uint16 color);
extern uint16 LcdCacheGetPointColor(uint16 x, uint16 y);
extern uint16 LcdCacheGetPixel(uint16 x, uint16 y);


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
int LCD_GetXSize(void);
int LCD_GetYSize(void);
void LCD_SetPixelIndex(GUI_RECT* p_strtClientRect, int x, int y, int ColorIndex);
void Lcd_TextCacheRefresh(void);
void Lcd_TextCacheClear(void);
void GUI_IconRefresh(void);
void GUI_IconRefreshNew(enumICON_DISP_TYPE eIconDispType, GUI_IM_MONITOR_ICON* p_strtGuiMonitors);
void LCD_DrawPixel(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                   int x, int y,  uint8 c, uint16 color);
void LCD_DrawPixelToBuffer(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                   int x, int y,  uint8 c, uint16 color);
void LCD_DrawVLine(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                   int x, int y0,  int y1, uint16 color);
void LCD_DrawVLineToBuffer(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                   int x, int y0,  int y1, uint16 color);
void LCD_DrawHLine(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                   int x0, int y,  int x1, uint16 color);
void LCD_DrawHLineToBuffer(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                   int x0, int y,  int x1, uint16 color);
void LCD_DrawLine(GUI_RECT* p_strtClientRect, GUI_DRAW_MODE DrawMode,
                  int x0, int y0, int x1, int y1, uint16 color);
//void Lcd_FillBackGnd(GUI_RECT rect, uint16 RGB_Code);
void Lcd_DisDisp(void);
void Lcd_EnDisp(void);
void GUI_UpdateLcdFromBuffer(GUI_RECT* p_rect, uint16 BackGndColor, uint16 TextColor);

//Oct0314 Lap Dang moved this function to GuiLcdDriver.h
void LcdInitialize(void);



void LcdIconSet(enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);
void LcdDigit(enumGUI_DIGIT_ICON eNumberDigit, uint8 bValueDigit);



void LcdBackLightInit(void);

//might move to another file
extern uint16 LcdCacheGetPointColor(uint16 x, uint16 y);
extern void LcdDrawPixel(uint16 x, uint16 y, uint16 RGB_Code);
extern GUI_POINT LcdDrawBmpImage(uint16 x, uint16 y, uint16* image);
extern void LcdIconDisp(uint16 x, uint16 y, enumGUI_ICON_STATUS eMode, uint16* imageOn,
                 uint16* imageOff, enumbool blIsRemoveEndByte);
extern void LcdIconLoad(enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);
extern void LcdIconHorizonLoad(enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);
extern void LcdFillBmpImageRect(uint16 x, uint16 y, uint16* image, uint16 RGB_code);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : Jan0215 Lap Dang rewrite new function
*Function name: LcdIconHorizonRightLoad
*Descrtiption : display icon from the right of lcd
*Input        : enumImageFile eImageFile - image file need to be displayed
*             : GUI_POINT sInputXY - top right point to display the image
*Output       :
*-----------------------------------------------------------------------------*/
extern GUI_POINT LcdIconHorizonRightLoad(enumImageFile eImageFile, GUI_POINT sInputXY);

//extern void LcdIconHorizonRightClear(uint8 bIdx);
extern void LcdIconHorizonRightClearAll(void);
extern void LcdIconHorizonLeftClearAll(void);
extern void LcdIconHorizonClearAll(void);
extern void LcdIconLoadAllNew(enumICON_DISP_TYPE eIconDispType, GUI_IM_MONITOR_ICON* p_strtGuiMonitors);
extern void LCD_Color_IconLoadAll(void);
extern void LCD_Color_LcdLoadBuffer(void);
extern void LCD_Color_LcdBrightness(uint8 bStep);

#endif
