/******************************************************************************
===============================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/

#ifndef __GUIIMAGE_H__
#define __GUIIMAGE_H__

#define IMAGE_IN_INTERFLASH     0
#define IMAGE_IN_FS             1
#define IMAGE_LOCATION          (IMAGE_IN_FS)

#define IMAGE_PATH_MAX_LEN      (63)
#define ICON_HOR_WIDTH          (25)
#define NUMBER_ICON_HOR         (3)

#define FF_ICON_WIDTH   (88)

#pragma pack(1)
typedef struct _structImageFilePath
{
    enumImageFile eImageFile;
    uint8 bPath[IMAGE_PATH_MAX_LEN];
}structImageFilePath;
#pragma pack()
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __GUIIMAGE_C__
const structImageFilePath strtButtonImageFilePath[]=
{
    {eIMAGE_INNOVA_DTC_BUTTON, "/Image/Mis/dtc.bmp"},
    {eIMAGE_INNOVA_ENTER_BUTTON, "/Image/Mis/enter.bmp"},
    {eIMAGE_INNOVA_ERASE_BUTTON, "/Image/Mis/erase.bmp"},
    {eIMAGE_INNOVA_LD_BUTTON, "/Image/Mis/LD.bmp"},
    {eIMAGE_INNOVA_LINK_BUTTON, "/Image/Mis/link.bmp"},
    {eIMAGE_INNOVA_MENU_BUTTON, "/Image/Mis/M.bmp"},
    {eIMAGE_INNOVA_POWER_BUTTON, "/Image/Mis/power.bmp"},
    {eIMAGE_INNOVA_SYSTEM_BUTTON, "/Image/Mis/systems.bmp"},
    
};
#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
GUI_POINT GUI_DrawBmpImage(uint16 x, uint16 y, uint16* image);
uint16 GUI_GetImageXPixel(uint16* image);
uint16 GUI_GetImageYPixel(uint16* image);
enumbool GUI_GetImageFilePath(enumImageFile eImageFile, uint8 *p_bPath);
enumbool GUI_CheckValidImageFile(enumImageFile eImageFile);
uint16 GUI_GetImageXPixelFromFS(enumImageFile eImageFile);
uint16 GUI_GetImageYPixelFromFS(enumImageFile eImageFile);
GUI_POINT GUI_DrawBmpImageFromFS(uint16 x, uint16 y, enumImageFile eImageFile);
void GUI_FillBmpImageRect(uint16 x, uint16 y, enumImageFile eImageFile, uint16 sColor);
void GUI_IconDisp(uint16 x, uint16 y, enumGUI_ICON_STATUS eMode, enumImageFile eImageFile);
#endif