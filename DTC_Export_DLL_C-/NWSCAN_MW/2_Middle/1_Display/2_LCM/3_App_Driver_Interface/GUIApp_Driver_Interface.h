#ifndef __GUI_APP_DRIVER_INTERFACE_H__
#define __GUI_APP_DRIVER_INTERFACE_H__

#include    "GuiType.h"
/*------------------------ COMMON DECLARE ------------------------------------*/

//LCD size
#define IS_ROW_COL_EX           (1)

#if (!IS_ROW_COL_EX)

#if MATCO_TOOLS
#define LCD_XSIZE      (217)   /* X-resolution of LCD, Logical coor. */
#define LCD_YSIZE      (320)    /* Y-resolution of LCD, Logical coor. */
#else
#define LCD_XSIZE      (240)   /* X-resolution of LCD, Logical coor. */
#define LCD_YSIZE      (320)    /* Y-resolution of LCD, Logical coor. */
#endif

#define     LCD_VIRTUAL_PHYSICAL_X_SIZE     (240)
#define     LCD_CACHE_XSIZE_RIGHT_NO_USED       (LCD_VIRTUAL_PHYSICAL_X_SIZE - LCD_XSIZE)

#define     LCD_VIRTUAL_PHYSICAL_Y_SIZE     (LCD_YSIZE)

#else

#if MATCO_TOOLS
//November 12 2014 Lap Dang added to decrease some right columns of the MD HW tools
#define LCD_XSIZE      (307)   /* X-resolution of LCD, Logical coor. */
#define LCD_YSIZE      (240)    /* Y-resolution of LCD, Logical coor. */
#else
#define LCD_XSIZE      (320)   /* X-resolution of LCD, Logical coor. */
#define LCD_YSIZE      (240)    /* Y-resolution of LCD, Logical coor. */
#endif

#define     LCD_VIRTUAL_PHYSICAL_X_SIZE     (320)
#define     LCD_CACHE_XSIZE_RIGHT_NO_USED       (LCD_VIRTUAL_PHYSICAL_X_SIZE - LCD_XSIZE)

#define     LCD_VIRTUAL_PHYSICAL_Y_SIZE     (LCD_YSIZE)

#endif



#define LCD_CACHE_XSIZE         LCD_XSIZE
#define LCD_CACHE_YSIZE         ((LCD_YSIZE + 8 - 1 )/8) /*Ceiling LCD_YSIZE/8*/


/*----------------------- PROTOTYPE ------------------------------------------*/

extern unsigned char LcdTextCache[LCD_CACHE_YSIZE][LCD_CACHE_XSIZE];
extern unsigned char LcdIconBuffer[LCD_CACHE_XSIZE];


extern int LcdGetXSize(void);
extern int LcdGetYSize(void);
extern void LcdClearBuffer(void);
extern void LcdIconClearAll(void);
extern void LcdCacheSetPixel(uint16 x, uint16 y, uint16 c, uint16 color);
extern uint16 LcdCacheGetPixel(uint16 x, uint16 y);
extern void LcdCacheXorPixel(int x, int y, uint16 color);

extern void Lcd_FillBackGnd(GUI_RECT rect, uint16 RGB_Code);

#endif