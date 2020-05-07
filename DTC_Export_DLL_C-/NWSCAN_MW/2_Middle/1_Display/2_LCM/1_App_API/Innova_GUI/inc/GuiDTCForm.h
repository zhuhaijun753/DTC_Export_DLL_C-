/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIDTCFORM_H__
#define __GUIDTCFORM_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIDTCFORM_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_DTCFormInit(GUI_DTC_FORM* p_strtDTCFrm,
                     const uint8* strDTCCode,
                     const void* strDTCInfo,
                     const void* strDTCDefinition,
                     const void* strFooter);
void GUI_DTCLibFormInit(GUI_DTC_FORM* p_strtDTCFrm,
                     const uint8* strDTCCode,
                     const void* strDTCInfo,
                     const void* strDTCDefinition,
                     const void* strDTCOEMInfo,
                     const void* strDTCOEMDefinition,
                     const void* strFooter);
void GUI_FixFormInit(GUI_DTC_FORM* p_strtDTCFrm,
                     const void* strFixTitle,
                     const uint8* strDTCCode,
                     const void* strDTCInfo,
                     const void* strDTCDefinition,
                     const void* strFooter);
void GUI_DTCFormDisplay(GUI_DTC_FORM* p_strtDTCFrm);
void GUI_DTCLibFormDisplay(GUI_DTC_FORM* p_strtDTCFrm);
enumbool GUI_DTCScrollDown(GUI_DTC_FORM* p_strtDTCFrm);
enumbool GUI_DTCScrollUp(GUI_DTC_FORM* p_strtDTCFrm);
void GUI_DTCLibFormBackGndDisplay(GUI_DTC_FORM* p_strtDTCFrm);
#endif
