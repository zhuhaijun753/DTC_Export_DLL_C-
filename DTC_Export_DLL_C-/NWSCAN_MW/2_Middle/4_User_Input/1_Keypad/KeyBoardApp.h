/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __KEYBOARDAPP_H__
#define __KEYBOARDAPP_H__

#include "buttondriver.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
typedef struct
{
    uint32          iIOPin;
    GUI_KEY_CODE    eKey;
} structtIO2KeyMap;

typedef struct
{
    GUI_KEY_CODE        eKey;
    enumKeyInterrupt    eIntSource;
} structKey2IntSourceMap;

#ifdef __KEYBOARDAPP_C__
GUI_KEY_CODE g_eButtonSpecial;


structtIO2KeyMap strtIO2KeyList[GUI_KEY_NUMBER_OF_KEY] =
{
    {MENU_KEY_PIN,      GUI_KEY_MENU},
    {ENTER_KEY_PIN,     GUI_KEY_ENTER},
    {ERASE_KEY_PIN,     GUI_KEY_ERASE},
    {DTC_KEY_PIN,       GUI_KEY_DTC},
    {DOWN_KEY_PIN,      GUI_KEY_DOWN},
    {UP_KEY_PIN,        GUI_KEY_UP},
    {LINK_KEY_PIN,      GUI_KEY_POWER_LINK},
    {LD_KEY_PIN,        GUI_KEY_LD},
    {FF_KEY_PIN,        GUI_KEY_SYSTEM},
};

structKey2IntSourceMap strtKey2IntList[GUI_KEY_NUMBER_OF_KEY] =
{
    {GUI_KEY_MENU,        KEY_LDM_INT},
    {GUI_KEY_ENTER,      KEY_ENTER_INT},
    {GUI_KEY_ERASE,      KEY_ERASE_INT},
    {GUI_KEY_DTC,        KEY_DTC_INT},
    {GUI_KEY_DOWN,       KEY_DOWN_INT},
    {GUI_KEY_UP,         KEY_UP_INT},
    {GUI_KEY_POWER_LINK, KEY_POWER_LINK_INT},
    {GUI_KEY_LD,         KEY_LD_INT},
    {GUI_KEY_SYSTEM,     KEY_FF_INT},
};

#else
extern GUI_KEY_CODE g_eButtonSpecial;
extern GUI_KEY_CODE g_kCurentKey;
#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
GUI_KEY_CODE IO2GuiKey(uint32 iIOPinStat);
enumKeyInterrupt Key2IntSource(GUI_KEY_CODE eKey);
GUI_KEY_CODE GetCurrentKey(void);

void KeyPressIsr(void);
void SetHoldingKeyMask(GUI_KEY_CODE kKeys);
void ClearHoldingKeyMask(GUI_KEY_CODE kKeys);

GUI_KEY_CODE GetHeldKey(void);
void ClearHeldKey(void);
void KeyBoardTimerISR(void);

//Oct072014 Lap Dang moved these function to here
void HwKeyEnable(void);
void ButtonDisableInterupt(void);

#endif
