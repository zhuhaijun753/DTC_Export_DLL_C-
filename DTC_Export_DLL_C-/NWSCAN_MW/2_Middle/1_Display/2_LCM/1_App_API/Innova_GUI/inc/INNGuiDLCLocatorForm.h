/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/
#include "..\inc\GuiImage.h"

#ifndef __INNGUIDLCLOCATORFORM_H__
#define __INNGUIDLCLOCATORFORM_H__

#define IMAGE_DASH_FROM_TOP     (5)
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void INN_GUI_DLCLocatorForm_UpdateImage(GUI_RECT* InitDLCPos_rect, uint8 bDLC_Pos, enumbool *blActive);
void INN_GUI_DLCLocatorFormInit(INN_GUI_DLC_LOCATOR_FORM* p_strtDLCLocatorFrm,
                                const uint8* strTitle,
                                const void* strAccess,
                                const void* strComment,
                                const void* strFooter);
void INN_GUI_DLCLocatorFormScrollDown(INN_GUI_DLC_LOCATOR_FORM* p_strtDLCLocatorFrm);
void INN_GUI_DLCLocatorFormScrollUp(INN_GUI_DLC_LOCATOR_FORM* p_strtDLCLocatorFrm);
void INN_GUI_DLCLocatorFormDisplay(INN_GUI_DLC_LOCATOR_FORM* p_strtDLCLocatorFrm);

#endif
