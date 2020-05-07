/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __INN_GUI_INFOVALUEFORM_H__
#define __INN_GUI_INFOVALUEFORM_H__
#include "PlatformType.h"
#define NULL_SIZE 4						// "NULL"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/

typedef enum _enumChecking
{
    NONE_CHECKING = 0,
    UNCHECK,
    CHECK
} enumChecking;

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/

void INNv1_GUI_InfoValueFormStringInit(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
									 const void* strTitle,
									 const void* strInstruction,
									 const void* strFooter,
									 const void* p_strItemList[],
									 const void* p_strValueList[],
									 const void* strCmd1,
									 const void* strCmd2,
									 const void* strCmd3,
									 GUI_TEXT_MODE ItemTextMode,
									 GUI_TEXT_MODE ValueTextMode);

void INNv1_GUI_InfoValueFormDispInit(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
									 uint8 bNumberItem,
									 uint8 bFirstDispItem,
									 sint32 iSelectedItem,
									 uint32 iInfoMaxXSize,
									 GUI_SCROLL_DISP_MODE DispScrollMode,
									 GUI_SELECTION_MODE SelectionMode);

void INNv1_GUI_InfoValueFormDisplay(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
                                 SCR_DISP_TYPE eDispType);



static uint8 INNv1_GUI_InfoValueListGetNumberScreenPage(INN_GUI_INFO_VALUE_LIST* p_strtGuiInfoValueList);								 
static uint8 INNv1_GUI_InfoValueItemLines(INN_GUI_INFO_VALUE_LIST* p_strtGuiInfoValueList,
											uint32 iItemIndex,
											uint32* p_iInfoMaxXPixel);	
static uint8 INNv1_GUI_InfoValueItemLinesWithCmd(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
										  uint32 iItemIndex,
										  uint32* p_iInfoMaxXPixel);                                   

void INNv1_GUI_InfoValueListLayout(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
static void INNv1_GUI_InfoValueListDisplay(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);


void INNv1_GUI_InfoValueScrollUp(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm, INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
void INNv1_GUI_InfoValueScrollDown(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm, INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);


sint16 INNv1_GUI_InfoValueGetCurrentItemIdx(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
uint8  INNv1_GUI_InfoValueGetFirstDispItem(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);
uint16 INNv1_GUI_InfoValueGetNumberItem(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);

// End list with NULL
uint16 INNv1_GUI_InfoValueGetNumItemOfList(const void* p_strItemList[]);

uint16 INNv1_GUI_InfoValueGetNumItemNoCmd(const void* p_strItemList[], const void* p_strValueList[], const void* strCmd1);

enumbool INNv1_GUI_InfoValueCheckCmdInList(INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm, uint16 Index);




// =============================================================================
// 							USE - WITH - GENERAL - TEXT
// =============================================================================

//    Notes     :       Put MLNull to Command String for not displaying command
//              :       Put Null is not correct
void INNv2_GUI_InfoValueFormStringInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
									   INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
									   const void* strTitle,
									   const void* strDescription1,
									   const void* strInstruction,
                                       const void* strSubBody,
									   const void* strDescription2,
									   const void* strFooter,
									   const void* p_strItemList[],
									   const void* p_strValueList[],
									   const void* strCmd1,
									   const void* strCmd2,
									   const void* strCmd3,
									   GUI_TEXT_MODE ItemTextMode,
									   GUI_TEXT_MODE ValueTextMode);

void INNv2_GUI_InfoValueFormDispInit(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
									 INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm,
									 uint8 bNumberItem,
									 uint8 bFirstDispItem,
									 sint32 iSelectedItem,
									 uint32 iInfoMaxXSize,
                                     enumbool IsCheckListOnTheLeft,
									 GUI_SCROLL_DISP_MODE DispScrollMode,
									 GUI_SELECTION_MODE SelectionMode);

void INNv2_GUI_InfoValueFormDisplay(INN_GUI_GENERAL_TEXT_FORM* p_strtInnTxtFrm,
									INN_GUI_INFO_VALUE_FORM* p_strtInfoValueFrm);


// =============================================================================
// 							  USE - WITH - CUSTOM
// =============================================================================

void INNv1_GUI_GetString_OnCheckList(uint8 bNumberItem,
                            uint8* p_CustomCheckList,
                            const void* p_strPtrList[]);
                            
void INNv1_GUI_CheckString_Toggle(const void* p_strPtrList[], sint16 sIndex);
void INNv1_GUI_CheckList_ToggleTick(uint8* p_CustomCheckList, sint16 sIndex); 

enumChecking INNv1_GUI_CheckList_GetStatus(uint8* p_CustomCheckList, sint16 sIndex);
void INNv1_GUI_CheckList_SetStatus(uint8* p_CustomCheckList, sint16 sIndex, enumChecking eStatus);



#endif


