/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __INNGUITEXTFORM_H__
#define __INNGUITEXTFORM_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __INNGUITEXTFORM_C__

#else

#endif
/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void INN_GUI_TextFormInit(INN_GUI_TEXT_FORM* p_strtTxtFrm, const void* strHeader, const void* strDescription1,
                          const void* strInstruction, const void* strBody, const void* strDescription2, 
                          const void* strFooter, const char ** pp_ListOption, uint8 bNumberOption);
void INN_GUI_Text_ProgressBar_FormInit(INN_GUI_TEXT_FORM* p_strtTxtFrm, const void* strTitle, const void* strDescription1,
                                       const void* strInstruction, const void* strBody, const void* strDescription2,
                                       const void* strFooter, GUI_PROGBAR_FORM* p_strtProgressBarFrm, const void* strProgBarText,
                                       enumbool eProgBarEn, const char ** pp_ListOption, uint8 bNumberOption);
void INN_GUI_TextFormScrollDown(INN_GUI_TEXT_FORM* p_strtTxtFrm);
void INN_GUI_TextFormScrollUp(INN_GUI_TEXT_FORM* p_strtTxtFrm);
void INN_GUI_TextFormDisp(INN_GUI_TEXT_FORM* p_strtTxtFrm);
void INN_GUI_Text_ProgressBar_FormDisp(INN_GUI_TEXT_FORM* p_strtTxtFrm,
                                       GUI_PROGBAR_FORM* p_strtProgressBarFrm);
sint32 INN_GUI_TextFormGetSelected(INN_GUI_TEXT_FORM* p_strtTxtFrm);
void INN_GUI_ProgBar_Update_Value(GUI_PROGBAR_FORM* p_strtProgressBarFrm,
                                  const void* strProgBarText,
                                  uint8 bPercent);
#endif
