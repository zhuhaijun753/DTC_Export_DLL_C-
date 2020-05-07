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

#ifndef __GUIFLASHSCRNFORM_H__
#define __GUIFLASHSCRNFORM_H__

#define IMAGE_DASH_FROM_TOP     (5)
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

//#ifdef __GUIFLASHSCRNFORM_C__
//
//#else
//
//#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
//#if 1
void GUI_FlashScreenFormInit(GUI_FLASH_SCREEN_FORM* p_strtFlashScreenFrm,
                             const uint8* strBigTitle,
                             const void*  strBody,
                             const void*  strFooter,
                             enumImageFile eImageFile);
//#else
//void GUI_FlashScreenFormInit(GUI_FLASH_SCREEN_FORM* p_strtFlashScreenFrm,
//                             const uint8* strBigTitle,
//                             const void*  strBody,
//                             const void*  strFooter,
//                             uint16 *image);
//void GUI_FlashScreenFormInit(GUI_FLASH_SCREEN_FORM* p_strtFlashScreenFrm,
//                             const uint8* strTitle,
//                             const void*  strBody,
//                             const void*  strFooter);
//#endif
void GUI_FlashScreenFormDisplay(GUI_FLASH_SCREEN_FORM* p_strtFlashScreenFrm);
#endif
