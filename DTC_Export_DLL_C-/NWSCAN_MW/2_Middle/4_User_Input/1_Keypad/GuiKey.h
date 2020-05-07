/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __GUI_KEY_H__
#define __GUI_KEY_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define GUI_KEY_NUMBER_OF_KEY       16

/*This define must match to GPIO PIN, bit field*/
typedef enum
{
    GUI_KEY_NONE        = 0,
    GUI_KEY_ERASE       = (1<<0),
    GUI_KEY_ENTER       = (1<<1),
    GUI_KEY_UP          = (1<<2),
    GUI_KEY_DOWN        = (1<<3),
    GUI_KEY_POWER_LINK  = (1<<4),
    GUI_KEY_DTC         = (1<<5),
    GUI_KEY_MENU         = (1<<6),
    GUI_KEY_FF          = (1<<7),
    GUI_KEY_LD          = (1<<8),
    GUI_KEY_SYSTEM      = (1<<9),
    GUI_KEY_RESERVED_10 = (1<<10),
    GUI_KEY_RESERVED_11 = (1<<11),
    GUI_KEY_RESERVED_12 = (1<<12),
    GUI_KEY_RESERVED_13 = (1<<13),
    GUI_KEY_RESERVED_14 = (1<<14),
    GUI_KEY_RESERVED_15 = (1<<15),

    GUI_KEY_ALL         = (0xFFFF)
}GUI_KEY_CODE;


typedef void (*fpKeyHandler)(void);
typedef void (*fpPreKeyProcHook)(void);
typedef void (*fpPostKeyProcHook)(void);

typedef struct
{
    GUI_KEY_CODE eKey;
    fpKeyHandler fHandler;

} structKeyHandler;


typedef struct
{
    GUI_KEY_CODE        eKeyPressed;
    fpPreKeyProcHook    fpPreKeyProc;
    fpPostKeyProcHook   fpPostKeyProc;
    structKeyHandler    KeyHandlerList[GUI_KEY_NUMBER_OF_KEY + 1];
    /*Feb 27, 2013: Hoang Nguyen added*/
    fpKeyHandler        fKeyUpEndHandler;
    fpKeyHandler        fKeyDownEndHandler;
} GUI_KEY_MANAGER;

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

extern GUI_KEY_MANAGER GUI_KeyManager;


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_KeyHandleNone(void);
void GUI_KeyHookNone(void);

void GUI_KeyHandlerReset(void);
enumbool GUI_KeyRegister(GUI_KEY_CODE eKeyCode, fpKeyHandler fHander);
void GUI_KeyUpEndRegister(fpKeyHandler fHander);
void GUI_KeyDownEndRegister(fpKeyHandler fHander);
void GUI_KeyPreProcessRegister(fpPreKeyProcHook fPreKey);
void GUI_KeyPostProcessRegister(fpPreKeyProcHook fPostKey);

void GUI_KeySet(GUI_KEY_CODE eKeyCode);
GUI_KEY_CODE GUI_KeyGet(void);

void GUI_KeyInit(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1015
*Function name: GUI_KeyHolding_Enable
*Descrtiption : Set holding keys
*Input        : GUI_KEY_CODE eKeyCode - holding keys need to set
*             : 
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_KeyHolding_Enable(GUI_KEY_CODE eKeyCode);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1015
*Function name: GUI_KeyHolding_Get
*Descrtiption : get holding keys
*Input        : None
*             : 
*Output       : GUI_KEY_CODE - key is been holding
*-----------------------------------------------------------------------------*/
GUI_KEY_CODE GUI_KeyHolding_Get(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1015
*Function name: GUI_KeyHolding_Disable
*Descrtiption : Disable holding keys
*Input        : GUI_KEY_CODE eKeyCode - holding keys need to clear
*             : 
*Output       :
*-----------------------------------------------------------------------------*/
void GUI_KeyHolding_Disable(GUI_KEY_CODE eKeyCode);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1015
*Function name: GUI_KeyHolding_Clear
*Descrtiption : Clear holding keys
*Input        : none
*             : 
*Output       : none
*-----------------------------------------------------------------------------*/
void GUI_KeyHolding_Clear(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan1215
*Function name: GUI_KeyCurrent_Get
*Descrtiption : get current keys
*Input        : None
*             : 
*Output       : GUI_KEY_CODE - key is been pressing
*-----------------------------------------------------------------------------*/
GUI_KEY_CODE GUI_KeyCurrent_Get(void);





enumbool GUI_KeyProcess(void);




#endif


