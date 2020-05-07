/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIDLOGO_H__
#define __GUIDLOGO_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define  LOGO_WIDTH          40
#define  LOGO_HEIGHT         40
#define  LOGO_PPB            2   /*Pixel per byte*/
#define   BOLD              0x01
#define   NORMAL            0x00


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIDLOGO_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GUI_DispLogo(GUI_WINDOW* p_strtWnd, const uint8* p_wCharImage);
#endif
