/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIINFOIMAGEFORM_H__
#define __GUIINFOIMAGEFORM_H__
//#include "..\inc\SysProcess.h"
#include "SysProcess.h"
#include "..\inc\GuiImage.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
/*Space bettwen [Info]_[Value]*/
#define INFO_IMAGE_X_DISTANCE     8


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIINFOIMAGEFORM_C__
static uint8 GUI_ImageItemPixel(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm, uint8 bIdx,
                         sint32* p_iInfoMaxXPixel);
static uint8 GUI_GetAvailImageItem(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm);
#if 1
static uint16 GUI_GetImageMaxXPixel(enumImageFile p_ImageList[], uint8 bNumberItem);
#else
static uint16 GUI_GetImageMaxXPixel(uint16* p_ImageList[], uint8 bNumberItem);
#endif
static void GUI_InfoImageDisp(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm, SCR_DISP_TYPE eDispType);
#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
#if 1
void GUI_InfoImageFormInit(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm,
                                 const void* strTitle,
                                 const void* strInstruction,
                                 const void* strFooter,
                                 uint8 bNumberItem,
                                 const void* const* p_strItemList,
                                 enumImageFile* p_ImageList);
#else
void GUI_InfoImageFormInit(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm,
                                 const void* strTitle,
                                 const void* strInstruction,
                                 const void* strFooter,
                                 uint8 bNumberItem,
                                 const void* const* p_strItemList,
                                 uint16** p_ImageList);
#endif
void GUI_InfoImageFormDisplay(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm, SCR_DISP_TYPE eDispType);
enumbool GUI_InfoImageScrollDown(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm);
enumbool GUI_InfoImageScrollUp(GUI_INFO_IMAGE_FORM* p_strtInfoImageFrm);
#endif