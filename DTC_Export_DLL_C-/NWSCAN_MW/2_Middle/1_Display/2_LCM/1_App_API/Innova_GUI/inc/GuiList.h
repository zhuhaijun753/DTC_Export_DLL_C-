/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUILIST_H__
#define __GUILIST_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUILIST_C__

typedef enum __enumItemPoLap Dangion
{
    eITEMPOS_NONE   =   0,
    
    eITEMPOS_BACK   =   1,
    eITEMPOS_NEXT   =   2,
    eITEMPOS_NORMAL =   3,
    
    eITEMPOS_MAX    =   0xFF,
}enumItemPoLap Dangion;

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
int GUI_ListWithNextBackGetNumberScreenPage(GUI_LIST* p_strtGuiList, 
                                            const void* p_strNext, 
                                            const void* p_strBack);
uint16 GUI_ListItemLayout_New(GUI_LIST* p_strtGuiList, 
                              GUI_SCROLL_DISP_MODE* p_eDispMode,
                              const void* p_strNext, 
                              const void* p_strBack);
void GUI_ListDisplay_New(GUI_LIST* p_strtGuiList,
                         const void* p_strNext, 
                         const void* p_strBack);
                         
int GUI_ListGetNumberScreenPage(GUI_LIST* p_strtGuiList);
#if 1
void GUI_ListDisplay(GUI_LIST* p_strtGuiList, GUI_POINT* p_strtNextDispPoint);
void GUI_ListDisplay_CheckHighlight(GUI_LIST* p_strtGuiList, GUI_POINT* p_strtNextDispPoint, enumbool eHighlight);
void GUI_ListScrollUp(GUI_LIST* p_strtGuiList, GUI_SCROLL_DISP_MODE DispScrollMode);
void GUI_ListScrollUp_New(GUI_LIST* p_strtGuiList, GUI_SCROLL_DISP_MODE DispScrollMode);
void GUI_ListScrollDown(GUI_LIST* p_strtGuiList, GUI_SCROLL_DISP_MODE DispScrollMode);
void GUI_ListScrollDown_New(GUI_LIST* p_strtGuiList, GUI_SCROLL_DISP_MODE DispScrollMode);
void GUI_ListScrollNextPage(GUI_LIST* p_strtGuiList);
uint8 GUI_ListItemLayout(GUI_LIST* p_strtGuiList, GUI_SCROLL_DISP_MODE* p_eDispMode);
enumbool GUI_ListCkeckItemInLastRow(GUI_LIST* p_strtGuiList, uint8 bItem);
#else
void GUI_ListDisplay(GUI_LIST* p_strtGuiList);
uint8 GUI_ListItemLayout(GUI_LIST* p_strtGuiList);
#endif
#endif
