/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIMENUFORM_NEW_H__
#define __GUIMENUFORM_NEW_H__
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIMENUFORM_NEW_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_MenuForm_New_StringInit(GUI_MENU_FORM* p_strtMenuFrm,
                                 const void* strTitle,
                                 const void* strNextPage,
                                 const void* strPrevPage,
                                 const void* strDescription,
                                 const void* strInstruction,
                                 const void* strFooter,
                                 const void* const* p_strItemList,
                                 GUI_TEXT_MODE ItemTextMode);

void GUI_MenuForm_New_DispInit(GUI_MENU_FORM* p_strtMenuFrm,
                               uint8 bNumberItem,
                               uint8 bNumDispCol,
                               uint8 bFirstDispItem,
                               sint32 iSelectedItem,
                               GUI_SCROLL_DISP_MODE DispScrollMode,
                               GUI_SELECTION_MODE SelectionMode);


void GUI_MenuForm_New_Display(GUI_MENU_FORM* p_strtMenuFrm, SCR_DISP_TYPE eDispType);
//
//void GUI_MenuScrollUp(GUI_MENU_FORM* p_strtMenuFrm);
//void GUI_MenuScrollDown(GUI_MENU_FORM* p_strtMenuFrm);
//void GUI_MenuSrollNextPage(GUI_MENU_FORM* p_strtMenuFrm);
//sint32 GUI_MenuGetCurrentItemIdx(GUI_MENU_FORM* p_strtMenuFrm);
//uint8 GUI_MenuGetFirstDispItem(GUI_MENU_FORM* p_strtMenuFrm);
#endif
