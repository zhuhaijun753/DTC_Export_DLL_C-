/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIINFOVALUELIST_H__
#define __GUIINFOVALUELIST_H__
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
/*Space bettwen [Info]_[Value]*/
#define INFO_VALUE_X_DISTANCE     8


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIINFOVALUELIST_C__
static sint32 GUI_InfoValueItemLines(GUI_INFO_VALUE_LIST* p_strtGuiInfoValueList,
                                     uint32 iItemIndex,
                                     sint32* p_iInfoMaxXPixel);
static sint32 GUI_InfoValueListGetNumberScreenPage(GUI_INFO_VALUE_LIST* p_strtGuiInfoValueList);

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_InfoValueFormStringInit(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
                                 const void* strTitle,
                                 const void* strInstruction,
                                 const void* strFooter,
                                 const void* const* p_strItemList,
                                 const void* const* p_strValueList,
                                 GUI_TEXT_MODE ItemTextMode,
                                 GUI_TEXT_MODE ValueTextMode);
void GUI_InfoValueFormDispInit(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
                               uint8 bNumberItem,
                               uint8 bFirstDispItem,
                               sint32 iSelectedItem,
                               sint32 iInfoMaxXSize,
                               GUI_SCROLL_DISP_MODE DispScrollMode,
                               GUI_SELECTION_MODE SelectionMode);
void GUI_InfoValueFormDisplay(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
void GUI_InfoValueFormDisplayNew(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
                                 SCR_DISP_TYPE eDispType);
void GUI_InfoValueScrollUp(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
void GUI_InfoValueScrollDown(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
void GUI_InfoValueSrollNextPage(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
sint32 GUI_InfoValueGetCurrentItemIdx(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
uint8 GUI_InfoValueGetFirstDispItem(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
void GUI_InfoValueListLayout(GUI_INFO_VALUE_LIST* p_strtGuiInfoValueList);
void GUI_InfoValueListBackGndDisplay(GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
#endif
