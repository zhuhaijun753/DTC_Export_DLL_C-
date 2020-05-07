/******************************************************************************************************************
*Engineer: Duc Tran
*Date: 12/06/2010
*File: intflash_driver.h
*Description
********************************************************************************************************************/
/*#################################################################################*/
#ifndef __STM32F2XXINTFLASHDRIVER_H__
#define __STM32F2XXINTFLASHDRIVER_H__

/*
================================================================================
CONSTANTS
================================================================================
*/
//
/* Exported macro ------------------------------------------------------------*/

/*
================================================================================
PROTOTYPES
================================================================================
*/
typedef enum
{
  BOOTLOADER = 0x0,
  FIRMWARE   = 0x1,
}
enumFlashArea;


/* Private function prototypes -----------------------------------------------*/
uint16_t FLASH_If_Init(void);
uint16_t FLASH_If_Erase (uint32_t Add);
uint16_t FLASH_If_Write(uint32_t pDestAddr, uint32_t Len, uint32_t pSrcAddr);
void FLASH_If_Read (uint32_t Add, uint32_t Len, uint8_t* p_bTgtBuff);
uint16_t FLASH_If_DeInit(void);
void ResetUpgradeArea(enumFlashArea eFlashArea);
enumbool FLASH_If_GetSecure(void);
void FLASH_If_SetSecure(void);
#endif
