#ifndef __GUI_APP_DRIVER_INTERFACE_MACRO_H__
#define __GUI_APP_DRIVER_INTERFACE_MACRO_H__

#include    "UC1611Driver.h"
#include "HX8347Driver.h"
#include "GoldentekDriver.h"

//Lap Dang moved those define to here
#define LCD_UC1611_OLD      (1)
#define LCD_UC1611_NEW      (2)
#define LCD_GOLDENTEK       (3)
#define LCD_KAIEE           (4)

#define OBD3130E_KAIEE_LCD  1

#if OBD3130E_KAIEE_LCD
#define LCD_TYPE            (LCD_KAIEE)
#elif OBD3130E_GOLDENTEK_LCD
#define LCD_TYPE            (LCD_GOLDENTEK)
#elif USING_LCD_UC1611
#define LCD_TYPE            (LCD_UC1611_NEW)
#else
//#warning ned to declare LCD Type
#endif


//void (*fp_LCD_DrawPixel)(uint16 x, uint16 y, uint16 RGB_Code);

//----------------------- LCD UC1611 -------------------------------------------
#if ((LCD_TYPE == LCD_UC1611_NEW) || (LCD_TYPE == LCD_UC1611_OLD))

#define LcdIconLoadAll      LCD_UC1611_IconLoadAll
#define LcdLoadBuffer       LCD_UC1611_LcdLoadBuffer
#define LcdBrightness(a)       LCD_UC1611_LcdBrightness(a)
//#define LcdDigit(a,b)       LCD_UC1611_LcdDigit(a,b)
//#define LcdIconSet(a,b)     LCD_UC1611_LcdIconSet(a,b)


#else //---------------- Color LCD ---------------------------------------------

#define LcdIconLoadAll      LCD_Color_IconLoadAll
#define LcdLoadBuffer       LCD_Color_LcdLoadBuffer
#define LcdBrightness(a)       LCD_Color_LcdBrightness(a)

#define fp_LCD_DrawPixel(a,b,c) HX8347_LCD_DrawPixel(a,b,c)


#endif //END OF PREPROCESSOR




#endif