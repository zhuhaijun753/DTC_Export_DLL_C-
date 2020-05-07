/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __INN_GUI_MENUFORM_H__
#define __INN_GUI_MENUFORM_H__

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
void INNv1_GUI_MenuForm_StringInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
								   INN_GUI_MENU_FORM* p_strtInnMenuFrm,
									 const void* strTitle,
									 const void* strNextPage,
									 const void* strPrevPage,
									 const void* strDescription1,
									 const void* strInstruction,
									 const void* strDescription2,
									 const void* strFooter,
									 const void* const* p_strItemList,
                                     uint8 bNumberItems,
									 GUI_TEXT_MODE ItemTextMode);

void INNv1_GUI_MenuForm_DispInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
								 INN_GUI_MENU_FORM* p_strtInnMenuFrm,
								   uint8 bNumberItem,
								   uint8 bNumDispCol,
								   uint8 bFirstDispItem,
								   sint32 iSelectedItem,
								   GUI_SCROLL_DISP_MODE DispScrollMode,
								   GUI_SELECTION_MODE SelectionMode);

void INNv1_GUI_MenuForm_Display(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
								INN_GUI_MENU_FORM* p_strtInnMenuFrm,
								SCR_DISP_TYPE eDispType);


void INNv1_GUI_MenuScrollUp(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm, INN_GUI_MENU_FORM* p_strtInnMenuFrm);
void INNv1_GUI_MenuScrollDown(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm, INN_GUI_MENU_FORM* p_strtInnMenuFrm);

sint16 INNv1_GUI_MenuGetCurrentItemIdx(INN_GUI_MENU_FORM* p_strtInnMenuFrm);
uint8  INNv1_GUI_MenuGetFirstDispItem(INN_GUI_MENU_FORM* p_strtInnMenuFrm);


void INNv1_GUI_ListDisplay(GUI_LIST* p_strtGuiList, GUI_POINT* p_strtNextDispPoint);


#endif