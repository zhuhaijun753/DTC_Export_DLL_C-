/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __GUIICONS_H__
#define __GUIICONS_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_IconInit(GUI_IM_MONITOR_ICON* p_strtLcmIcons);
void GUI_IconUpdate(GUI_IM_MONITOR_ICON* p_strtLcmIcons, enumGUI_LCD_AREA eArea);
void GUI_IconAreaToggle(GUI_IM_MONITOR_ICON* p_strtLcmIcons, enumGUI_LCD_AREA eArea);
void GUI_IconBufferSet(GUI_IM_MONITOR_ICON* p_strtLcmIcons,
                       enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);
enumGUI_ICON_STATUS GUI_IconBufferGet(GUI_IM_MONITOR_ICON* p_strtLcmIcons,
                                      enumGUI_ICON eIcon);

void GUI_IconSet(GUI_IM_MONITOR_ICON* p_strtLcmIcons,
                 enumGUI_ICON eIcon, enumGUI_ICON_STATUS eMode);
enumGUI_ICON_STATUS GUI_IconGet(GUI_IM_MONITOR_ICON* p_strtLcmIcons,
                                enumGUI_ICON eIcon);
void GUI_IconToggle(GUI_IM_MONITOR_ICON* p_strtLcmIcons,
                    enumGUI_ICON eIcon);

void GUI_DTCIndexSet(GUI_IM_MONITOR_ICON* p_strtLcmIcons,
                     uint8 bCurrentDTC, uint8 bTotalDTC, enumGUI_ICON_STATUS eMode);
void GUI_DTCTypeSet(GUI_IM_MONITOR_ICON* p_strtLcmIcons, GUI_DTC_TYPE eDTCType,
                    enumGUI_ICON_STATUS eMode);
void GUI_IconClear(GUI_IM_MONITOR_ICON* p_strtLcmIcons, enumGUI_LCD_AREA eArea);
void GUI_IconAreaClear(enumICON_DISP_TYPE eIconDispType);
#endif


