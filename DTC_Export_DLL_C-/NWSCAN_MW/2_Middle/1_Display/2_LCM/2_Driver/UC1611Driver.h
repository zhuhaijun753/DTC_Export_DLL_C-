#ifndef __UC1611DRIVER_H__
#define __UC1611DRIVER_H__

#define LcdEnable()    __Clear_Gpio_Pin(LCDCS_PORT        , LCDCS_PIN);
#define LcdDisable()   __Set_Gpio_Pin  (LCDCS_PORT        , LCDCS_PIN);
#define LcdCmdSet()    __Clear_Gpio_Pin(LCDA0_PORT        , LCDA0_PIN);
#define LcdDataSet()   __Set_Gpio_Pin(LCDA0_PORT          , LCDA0_PIN);
#define LcdWRSet()     __Set_Gpio_Pin(LCDWR_PORT          , LCDWR_PIN);
#define LcdWRClear()   __Clear_Gpio_Pin(LCDWR_PORT        , LCDWR_PIN);
#define LcdRDSet()     __Set_Gpio_Pin(LCDRD_PORT          , LCDRD_PIN);
#define LcdRDClear()   __Clear_Gpio_Pin(LCDRD_PORT        , LCDRD_PIN);
#define LcdReset()     __Clear_Gpio_Pin(LCDRES_PORT       , LCDRES_PIN);
#define LcdRelease()   __Set_Gpio_Pin(LCDRES_PORT         , LCDRES_PIN);
#define LcdLightOn()   __Set_Gpio_Pin(LCD_BACKLIGHT_PORT  , LCD_BACKLIGHT_PIN);
#define LcdLightOff()  __Clear_Gpio_Pin(LCD_BACKLIGHT_PORT, LCD_BACKLIGHT_PIN);

/****************************** Define Parameter ******************************/

/******************************************************************************/
//#ifdef __UC1611DRIVER_C__

typedef enum _enumInstruction
{
    SET_PAGE,
    SET_COLUMN,
    PANEL_LOADING,
    TEMP_COMPENTSATION,
    LCD_MAPPING_CONTROL,
    RAM_ADDRESS_CONTROL,
    LINE_RATE,
    BIAS_RATIO,
    POTENTIOMETER,
    DISPLAY_PATTERN,
    DISPLAY_ON_OFF,
    NOP,

} enumInstruction;

typedef struct _structLcdIcon
{
    enumGUI_ICON eIcon;
    const uint8 Seg; /* column consist icon */
    const uint8 ComMask; /* Line consist icon */
} structLcdIcon, *p_structLcdIcon;

//static void LcdSndIns(uint8 bIns);
//static void LcdSndCmd(uint8 bTypeCmd, uint8 bData);
//static void LcdSetPage(uint8 bPage);
//static void LcdSetColumn(uint8 bColumn);
//static void LcdSetCurSEG(uint8 bData);
//static void LcdSndData(uint8 bData);
//
//#else
//
//#endif

extern const structLcdIcon  g_strtLcdIconList[];
extern const uint8 DigitCode[];


void LCD_UC1611_Initialize(void);
void LCD_UC1611_IconLoadAll(void);
void LCD_UC1611_BackLightInit(void);
void LCD_UC1611_LcdBrightness(uint8 bStep);
void LCD_UC1611_LcdLoadBuffer(void);
//void LCD_UC1611_LcdDigit(enumGUI_DIGIT_ICON eNumberDigit, uint8 bValueDigit);
//void LCD_UC1611_LcdIconSet(enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);

void LcdSetBackLight(enumLogicState eStatus);

#endif // end define _DRIVERLCD_H

