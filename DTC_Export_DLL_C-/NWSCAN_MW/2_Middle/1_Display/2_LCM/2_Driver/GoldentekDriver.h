#ifndef __GOLDENTEKDRIVER_H__
#define __GOLDENTEKDRIVER_H__
#include "UC1611Driver.h"

#define swap(a, b) { uint16 t = a; a = b; b = t; }

#if (!IS_ROW_COL_EX)
#define ROW_COL_EX_ILI9141          (0x00)
#else
#define ROW_COL_EX_ILI9141          (1<<5)
#endif

#define COL_INV_ILI9141             (1<<6)
#define ROW_INV_ILI9141             (1<<7)
#ifdef __GOLDENTEKDRIVER_C__
/*Defined for Goldentek LCD*/

void Goldentek_LCD_Fill_Src(uint16 color);
void Goldentek_LCD_Reset(void);
void Goldentek_LCD_Test(void);
void Goldentek_LCD_FillRect(uint16 sc, uint16 ec, uint16 sp, uint16 ep, uint16 color);
void Goldentek_LCD_DrawPixel(uint16 x, uint16 y, uint16 RGB_Code);
void Goldentek_LCD_DispChar(GUI_WINDOW* p_strtWnd, uint16 c, uint16 color);
void Goldentek_LCD_DispCharAt(GUI_WINDOW* p_strtWnd, uint16 c, uint16 x, uint16 y, uint16 color);

/*Low level*/
void Goldentek_LCD_Init(void);
void Goldentek_LCD_Config(void);
void Goldentek_LCD_AddSet(uint16 sc, uint16 ec, uint16 sp, uint16 ep);
void Goldentek_LCD_WriteRAM(uint16 RGB_Code);
void Goldentek_LCD_WriteRAMInv(uint16 RGB_Code);
void Goldentek_LCD_EnDisp(void);
void Goldentek_LCD_DisDisp(void);
void Goldentek_LCD_SetPixel(uint16 x, uint16 y);
void Goldentek_LCD_WriteRAM(uint16 RGB_Code);
void Goldentek_LCD_CmdData(uint16 cmd, uint16 data);
#else
extern void Goldentek_LCD_Init(void);
extern void Goldentek_LCD_Fill_Src(uint16 color);
extern void Goldentek_LCD_DrawPixel(uint16 x, uint16 y, uint16 RGB_Code);
extern void Goldentek_LCD_FillRect(uint16 sc, uint16 ec, uint16 sp, uint16 ep, uint16 color);
extern void Goldentek_LCD_AddSet(uint16 sc, uint16 ec, uint16 sp, uint16 ep);
extern void Goldentek_LCD_WriteRAM(uint16 RGB_Code);
extern void Goldentek_LCD_CmdData(uint16 cmd, uint16 data);
extern void Goldentek_LCD_WriteRAMInv(uint16 RGB_Code);
extern void Goldentek_LCD_EnDisp(void);
extern void Goldentek_LCD_DisDisp(void);
#endif


/**/
enumbool CheckGoldentekLcdValid(void);
#endif