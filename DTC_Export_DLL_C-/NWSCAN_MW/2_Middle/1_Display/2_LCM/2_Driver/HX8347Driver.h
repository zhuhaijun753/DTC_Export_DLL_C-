#ifndef __HX8347DRIVER_H__
#define __HX8347DRIVER_H__

#define HX8347_BRIGHTNESS_LEVEL                5
#define HX8347_BRIGHTNESS_PRESET_LEVEL         (HX8347_BRIGHTNESS_LEVEL + 1)
#define HX8347_BRIGHTNESS_STEP_VALUE           13000

/*High layer*/
void HX8347_LCD_FillScr(uint16 color);
void HX8347_LCD_Fill_Rect(uint16 x0, uint16 y0, uint16 x1, uint16 y1, uint16 color);
void HX8347_LCD_Test(void);
void HX8347_LCD_DrawPixel(uint16 x0, uint16 y0, uint16 color);

/*Low layer*/
void HX8347_LCD_Init(void);
void HX8347_LCD_Config(void);
void HX8347_LCD_Add_Set(uint16 x1, uint16 y1, uint16 x2, uint16 y2);
void HX8347_LCD_WriteRAM(uint16 RGB_Code);
void HX8347_LCD_Reset(void);


void HX8347_LCD_BacklightInit(uint8 bStep);
void HX8347_LCD_SetBrightness(uint8 bStep);

/**/
enumbool CheckKaieeLcdValid(void);
#else
extern void HX8347_LCD_FillScr(uint16 color);
extern void HX8347_LCD_Fill_Rect(uint16 x0, uint16 y0, uint16 x1, uint16 y1, uint16 color);
//extern void HX8347_LCD_Test(void);
extern void HX8347_LCD_DrawPixel(uint16 x0, uint16 y0, uint16 color);

/*Low layer*/
extern void HX8347_LCD_Init(void);
extern void HX8347_LCD_Config(void);
extern void HX8347_LCD_Add_Set(uint16 x1, uint16 y1, uint16 x2, uint16 y2);
extern void HX8347_LCD_WriteRAM(uint16 RGB_Code);
extern void HX8347_LCD_Reset(void);

extern void HX8347_LCD_BacklightInit(uint8 bStep);
extern void HX8347_LCD_SetBrightness(uint8 bStep);

#endif