/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIHIGHLIGHTTEXTFORM_H__
#define __GUIHIGHLIGHTTEXTFORM_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIHIGHLIGHTTEXTFORM_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

void GUI_HighlightTextFormInit(GUI_TEXT_FORM* p_strtTxtFrm,
                               const void* strTitle,
                               const void* strInstruction,
                               const void* strBody,
                               const void* strFooter,
                               sint32 iNumberSelectableLine,
                               sint32 iCurrentSelectedLine);
void GUI_HighlightTextScrollDown(GUI_TEXT_FORM* p_strtTxtFrm);
void GUI_HighlightTextScrollUp(GUI_TEXT_FORM* p_strtTxtFrm);
void GUI_HighlightTextFormDisplay(GUI_TEXT_FORM* p_strtTxtFrm);
sint32 GUI_HighlightTextFormGetSelected(GUI_TEXT_FORM* p_strtTxtFrm);
void GUI_HighlightTextFormResetSelected(GUI_TEXT_FORM* p_strtTxtFrm, sint32 siSelectedValue);
#endif
