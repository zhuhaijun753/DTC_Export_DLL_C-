/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __INNGUIINPUTTEXTFORM_H__
#define __INNGUIINPUTTEXTFORM_H__
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
typedef enum
{
  GUI_BUTTON_0YZ = 9,
  GUI_BUTTON_SPACE = 10,
  GUI_BUTTON_CLEAR = 11,
  GUI_BUTTON_ALL = (0xFFFF)
}INN_GUI_BUTON;

typedef enum
{
  GUI_FIELD_NONE = 0,
  GUI_FIELD_KEYBOARD = 1,
  GUI_FIELD_OPTION = 2,  
  GUI_FIELD_ALL = (0xFFFF)
}
INN_GUI_FIELD;
/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void INN_GUI_InputTextFormInit(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm,
                               GUI_SCROLL_DISP_MODE DispScrollMode,
                               GUI_SELECTION_MODE SelectionMode,
                               const void* strTitle,
                               const void* strDescription1,
                               const void* strInstruction,
                               void* strInput,
                               const void* strDescription2,
                               const void* strFooter,
                               const char ** pp_ListOption,
                               uint8 bNumberOption);
void INN_GUI_InputTextFormDisp(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm,
                               GUI_SCROLL_DISP_MODE DispScrollMode);
void INN_GUI_InputTextFormScrollDown(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
void INN_GUI_InputTextFormScrollUp(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
void INN_GUI_InputTextFormEnter(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
sint32 GUI_InpTxtFrmGetCurrentItemIdx(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
uint8 INN_GUI_InpTxtFrmGetFirstDispItem(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
sint32 INN_GUI_InputTextFormGetSelected(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
INN_GUI_FIELD INN_GUI_InputTextFormGetEnableField(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
void const* INN_GUI_InputTextFormGetInputText(INN_GUI_INPUT_TEXT_FORM* p_strtInpTxtFrm);
#endif
