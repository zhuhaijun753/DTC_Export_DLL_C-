/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __GUIDIGITSELECTIONFORM_H__
#define __GUIDIGITSELECTIONFORM_H__
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIDIGITSELECTIONFORM_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_DigitSelectionFormInit(GUI_DIGIT_SELECTION_FORM* p_strtDigitScreenFrm,
                                const void*  strTitle,
                                uint8*       strDigits,
                                const void*  strFooter,
                                uint8        bCurrentDigitIdx,
                                uint8        bNumberDigit);

void GUI_DigitSelectionFormInit_New(GUI_DIGIT_SELECTION_FORM* p_strtDigitScreenFrm,
                                    const void*  strTitle,
                                    uint8*       strDigits,
                                    const void*  strInstruction,
                                    const void*  strFooter,
                                    uint8        bCurrentDigitIdx,
                                    uint8        bNumberDigit);

void GUI_DigitScreenFormDisplay(GUI_DIGIT_SELECTION_FORM* p_strtDigitScreenFrm, 
                                SCR_DISP_TYPE eDispType);

void GUI_DigitScreenFormDisplay_New(GUI_DIGIT_SELECTION_FORM* p_strtDigitScreenFrm, 
                                    SCR_DISP_TYPE eDispType);
#endif


