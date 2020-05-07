/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __GUI_GRAPH_H__
#define __GUI_GRAPH_H__
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUI_GRAPH_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
sint32 GUI_GraphConvertXToLcdAddr(GUI_GRAPH_FORM* p_strtGraphFrm, sint32 bGraphX);
sint32 GUI_MultiGraphConvertXToLcdAddr(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                       uint16 xAxis,
                                       sint32 bGraphX);
sint32 GUI_GraphConvertYToLcdAddr(GUI_GRAPH_FORM* p_strtGraphFrm, sint32 bGraphY);

sint32 GUI_GraphValueToY(GUI_GRAPH_FORM* p_strtGraphFrm, float fValue);
sint32 GUI_GraphTimeToX(GUI_GRAPH_FORM* p_strtGraphFrm, float fTime);

void GUI_LiveGraphFormInit(GUI_GRAPH_FORM* p_strtGraphFrm,
                           const void* strTitle,
                           uint8 bPrecision,
                           float fGlobalMin, float fGlobalMax, GUI_RECT mainRect);
void GUI_LiveMultiGraphFormInit(GUI_GRAPH_FORM* p_strtGraphFrm,
                           const void* strTitle,
                           uint8 bPrecision,
                           float fGlobalMin, float fGlobalMax,
                           GUI_GRAPH_FORM* p_strtGraphFrmNext,
                           const void* strTitleNext,
                           uint8 bPrecisionNext,
                           float fGlobalMinNext, float fGlobalMaxNext, GUI_RECT mainRect);
void GUI_PlaybackGraphFormInit(GUI_GRAPH_FORM* p_strtGraphFrm,
                               const void* strTitle,
                               const void* strFrameTitle,
                               const void* strSecond, uint8 bPrecision,
                               float fGlobalMin, float fGlobalMax, GUI_RECT rect);
void GUI_PlaybackMultiGraphFormInit(GUI_GRAPH_FORM* p_strtGraphFrm,
                               const void* strTitle,
                               const void* strFrameTitle,
                               const void* strSecond, uint8 bPrecision,
                               float fGlobalMin, float fGlobalMax,
                               GUI_GRAPH_FORM* p_strtGraphNextFrm,
                               const void* strTitleNext,
                               uint8 bPrecisionNext,
                               float fGlobalMinNext, float fGlobalMaxNext,
                               GUI_RECT mainRect);
void GUI_GraphFormDrawTimeLine(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphInitBaseMarker(GUI_GRAPH_FORM* p_strtGraphFrm);

void GUI_GraphUpdateRange(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphUpdateLcdY(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphUpdateXRange(GUI_GRAPH_FORM* p_strtGraphFrm);

void GUI_GraphInitBaseMarker(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphMarkerShiftLeft(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphMarkerShiftRight(GUI_GRAPH_FORM* p_strtGraphFrm);

void GUI_LiveGraphFormDisplay(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_LiveGraphFormDisplayNew(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                 enumLD_GRAPH_STATUS eLdGraphStat,
                                 SCR_DISP_TYPE eDispType);
void GUI_LiveMultiGraphFormDisplay(GUI_GRAPH_FORM* p_strtGraphFrm,
                                   GUI_GRAPH_FORM* p_strtGraphNextFrm,
                                   SCR_DISP_TYPE eDispType);
#if 1
void GUI_PlaybackGraphFormDisplay(GUI_GRAPH_FORM* p_strtGraphFrm, uint16 colorRect);
void GUI_PlaybackMultiGraphFormDisplay(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                       GUI_GRAPH_FORM* p_strtGraphNextFrm,
                                       SCR_DISP_TYPE eDispType);
void GUI_PlaybackGraphFormDisplayNew(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                     enumLD_GRAPH_STATUS eLdGraphStat,
                                     SCR_DISP_TYPE eDispType);
void GUI_GraphFormDrawSkeleton(GUI_GRAPH_FORM* p_strtGraphFrm, uint16 color);

#if 1//July1014 Lap Dang modified
void GUI_MultiGraphFormDrawSkeleton(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                    GUI_GRAPH_FORM* p_strtGraphNextFrm,
                                    uint16 sFirstGraphColor,
                                    uint16 sSecondGraphColor);
#else
void GUI_MultiGraphFormDrawSkeleton(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                    GUI_GRAPH_FORM* p_strtGraphNextFrm,
                                    uint16 color);
#endif
void GUI_GraphFormDrawMarker(GUI_GRAPH_FORM* p_strtGraphFrm, uint16 colorRect);
void GUI_MultiGraphFormDrawMarker(GUI_GRAPH_FORM* p_strtGraphFrm, 
                                  uint16 xAxis,
                                  uint16 colorRect);
#else
void GUI_PlaybackGraphFormDisplay(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphFormDrawSkeleton(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_GraphFormDrawMarker(GUI_GRAPH_FORM* p_strtGraphFrm);
void GUI_LiveGraphFormInit(GUI_GRAPH_FORM* p_strtGraphFrm,
                           const void* strTitle, uint8 bPrecision,
                           float fGlobalMin, float fGlobalMax);
#endif
void GUI_LiveGraphFormAddValue(GUI_GRAPH_FORM* p_strtGraphFrm, float fNewValue, uint16 xAxis);
void GUI_LiveMultiGraphFormAddValue(GUI_GRAPH_FORM* p_strtGraphFrm, float fNewValue,
                                    GUI_GRAPH_FORM* p_strtGraphNextFrm, float fNewValueNext);
void GUI_PlaybackGraphFormAddValue(GUI_GRAPH_FORM* p_strtGraphFrm,
                                   float fValue, float fTime);
void GUI_LiveGraphNotify(GUI_GRAPH_FORM* p_strtGraphFrm, 
                         enumLD_GRAPH_STATUS eLdGraphStat);
#endif


