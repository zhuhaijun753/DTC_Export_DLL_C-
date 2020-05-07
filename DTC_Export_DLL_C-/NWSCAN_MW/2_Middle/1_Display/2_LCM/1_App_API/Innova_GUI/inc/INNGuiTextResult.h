/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __INNGUITEXTRESULT_H__
#define __INNGUITEXTRESULT_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __INNGUITEXTRESULT_C__

#else

#endif
/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void INN_GUI_TextResultInit(INN_GUI_TEXT_RESULT* p_strtTxtRslt,
                            const void* strTitle,
                            const void* strDescription1,
                            const void* strInstruction,
                            const void* strCommand,
                            const void* strValue,
                            const void* strDescription2,
                            const void* strFooter,
                            const char ** pp_ListOption,
                            uint8 bNumberOption);
void INN_GUI_TextResultScrollDown(INN_GUI_TEXT_RESULT* p_strtTxtRslt);
void INN_GUI_TextResultScrollUp(INN_GUI_TEXT_RESULT* p_strtTxtRslt);
void INN_GUI_TextResultDisp(INN_GUI_TEXT_RESULT* p_strtTxtRslt);
sint32 INN_GUI_TextResultGetSelected(INN_GUI_TEXT_RESULT* p_strtTxtRslt);
void INN_GUI_TextResultSetWndValueXSize(sint32 iWndValueXSize);
#endif
