/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUITEXTFORM_H__
#define __GUITEXTFORM_H__
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"
#include "..\inc\GuiImage.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUITEXTFORM_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_TextFormInit(GUI_TEXT_FORM* p_strtTxtFrm,
                      const void* sTitle,
                      const void* sInstruction,
                      const void* sBody,
                      const void* sFooter);
void GUI_TextFormDisplay(GUI_TEXT_FORM* p_strtTxtFrm);
void GUI_TextScrollDown(GUI_TEXT_FORM* p_strtTxtFrm);
void GUI_TextScrollUp(GUI_TEXT_FORM* p_strtTxtFrm);
void GUI_TextFormDisplayNew(GUI_TEXT_FORM* p_strtTxtFrm, SCR_DISP_TYPE eDispType);
#if 0
void GUI_TextImageFormInit(GUI_TEXT_FORM* p_strtTxtFrm,
                      const void* strTitle,
                      const void* strInstruction,
                      const void* strBody,
                      const void* strFooter,
                      uint16 * image,
                      const void* strPercent);
#else
void GUI_TextImageFormInit(GUI_TEXT_FORM* p_strtTxtFrm,
                      const void* strTitle,
                      const void* strInstruction,
                      const void* strBody,
                      const void* strFooter,
                      enumImageFile eImageFile);
#endif


void GUI_Text_ProgressBar_FormInit(GUI_TEXT_FORM* p_strtTxtFrm,
                                   const void* strTitle,
                                   const void* strInstruction,
                                   const void* strBody,
                                   const void* strFooter,
                                   GUI_PROGBAR_FORM* p_strtProgressBarFrm,
                                   const void* strProgBarText,
                                   enumbool eProgBarEn);
void GUI_Text_ProgressBar_Form_Display(GUI_TEXT_FORM* p_strtTxtFrm, 
                                       SCR_DISP_TYPE eDispType,
                                       GUI_PROGBAR_FORM* p_strtProgressBarFrm);
#endif
