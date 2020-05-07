/******************************************************************************
===============================================================================
Lap Dang Dev
Filename
Description
Layer
Accessibility
===============================================================================
******************************************************************************/

#ifndef __INN_GUI_TEXTFORM_H__
#define __INN_GUI_TEXTFORM_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/

typedef enum _enumWindow
{
    WINDOW_TITLE        = 0,
    WINDOW_INSTRUCTION  = 1,
    WINDOW_DESCRIPTION1 = 2,
    WINDOW_DESCIPTION2  = 3,
    WINDOW_BODY         = 4,
    WINDOW_FOOTER       = 5,
} enumWindow;

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void INNv1_GUI_TextFormInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
                      const void* strTitle,
					  const void* strDescription1,
                      const void* strInstruction,
                      const void* strBody,
					  const void* strDescription2,
                      const void* strFooter);

void INNv1_GUI_TextFormDisplay(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm, SCR_DISP_TYPE eDispType);

/*----------------------- For MultiString Text Form --------------------*/
void INNv1_GUI_TextFormInitNew(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
                      const void* strTitle,
					  const void* strDescription1,
                      const void* strInstruction,
                      const void* strBody,
					  const void* strDescription2,
                      const void* strFooter);

void INNv1_GUI_TextScrollUp(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_TextScrollDown(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);

void INNv1_GUI_TextScrollUpSequence(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_TextScrollDownSequence(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);

/*----------------------- For General Text Form --------------------*/
void INNv1_GUI_GeneralTextFormInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
                      const void* strTitle,
					  const void* strDescription1,
                      const void* strInstruction,
					  const void* strDescription2,
                      const void* strFooter,
                      uint8 bBodyNumberItem);
					  
void INNv1_GUI_GeneralTextFormDisplay(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);


void INNv1_GUI_GeneralUpperBodyScrollUp(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_GeneralUpperBodyScrollDown(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_GeneralLowerBodyScrollUp(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_GeneralLowerBodyScrollDown(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);


void INNv1_GUI_TextAndBackgroundColor_Change(enumWindow eWindow, uint16 iTextColor, uint16 iBackgroundColor);
void INNv1_GUI_BodyTextAndBackgroundColor_Reset(void);

/*------------------------- For Testing ------------------------------------*/
void INNv2_GUI_TextFormInitNew(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
                      const void* strTitle,
					  const void* strDescription1,
                      const void* strInstruction,
                      const void* strBody,
					  const void* strDescription2,
                      const void* strFooter);
					  
void INNv1_GUI_TextScrollUpSequenceGeneral(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_TextScrollDownSequenceGeneral(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm);
void INNv1_GUI_BodyTextInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm, const void* strBody);

#endif