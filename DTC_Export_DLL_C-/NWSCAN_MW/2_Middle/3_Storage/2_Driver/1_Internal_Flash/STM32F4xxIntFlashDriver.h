/******************************************************************************************************************
*Engineer: Duc Tran
*Date: 12/06/2010
*File: intflash_driver.h
*Description
********************************************************************************************************************/
/*#################################################################################*/
#ifndef __STM32F4XXINTFLASHDRIVER_H__
#define __STM32F4XXINTFLASHDRIVER_H__

#include    "stdint.h"

/*
================================================================================
CONSTANTS
================================================================================
*/
#define FLASH_NUMBER_SECTOR     24

/* Base address of the Flash sectors */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */
#define ADDR_FLASH_SECTOR_12    ((uint32_t)0x08100000) /* Base @ of Sector 12, 16 Kbytes */
#define ADDR_FLASH_SECTOR_13    ((uint32_t)0x08104000) /* Base @ of Sector 13, 16 Kbytes */
#define ADDR_FLASH_SECTOR_14    ((uint32_t)0x08108000) /* Base @ of Sector 14, 16 Kbytes */
#define ADDR_FLASH_SECTOR_15    ((uint32_t)0x0810C000) /* Base @ of Sector 14, 16 Kbytes */
#define ADDR_FLASH_SECTOR_16    ((uint32_t)0x08110000) /* Base @ of Sector 16, 64 Kbytes */
#define ADDR_FLASH_SECTOR_17    ((uint32_t)0x08120000) /* Base @ of Sector 17, 128 Kbytes */
#define ADDR_FLASH_SECTOR_18    ((uint32_t)0x08140000) /* Base @ of Sector 18, 128 Kbytes */
#define ADDR_FLASH_SECTOR_19    ((uint32_t)0x08160000) /* Base @ of Sector 19, 128 Kbytes */
#define ADDR_FLASH_SECTOR_20    ((uint32_t)0x08180000) /* Base @ of Sector 20, 128 Kbytes */
#define ADDR_FLASH_SECTOR_21    ((uint32_t)0x081A0000) /* Base @ of Sector 21, 128 Kbytes */
#define ADDR_FLASH_SECTOR_22    ((uint32_t)0x081C0000) /* Base @ of Sector 22, 128 Kbytes */
#define ADDR_FLASH_SECTOR_23    ((uint32_t)0x081E0000) /* Base @ of Sector 23, 128 Kbytes */

#define FLASH_BL_START_SECTOR           FLASH_Sector_0   /* Start @ of BL Flash Sector */
#define FLASH_BL_START_SECTOR_INDEX     0



#ifdef STM32F4XX

#if _INFLASH_VEHICLE_DATA//April1014 V31b Lap Dang modified to use Internal Flash to save Vehicle data
#define FIRMWARE_VERSION_SECTOR FLASH_Sector_20
#else
#define FIRMWARE_VERSION_SECTOR FLASH_Sector_23
#endif


#else
#define FIRMWARE_VERSION_SECTOR FLASH_Sector_11
#endif


#define FLASH_FW_START_SECTOR           FLASH_Sector_4   /* Start @ of user Flash area */
#define FLASH_FW_START_SECTOR_INDEX     4

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

typedef struct
{
    uint16_t wSector;
    uint32_t iSectorAddress;
} structFlashSector;

#ifdef __STM32F4XXINTFLASHDRIVER_C__
structFlashSector g_strtWholeFlashSectors[FLASH_NUMBER_SECTOR] =
{
	{FLASH_Sector_0	,	ADDR_FLASH_SECTOR_0	},
	{FLASH_Sector_1	,	ADDR_FLASH_SECTOR_1	},
	{FLASH_Sector_2	,	ADDR_FLASH_SECTOR_2	},
	{FLASH_Sector_3	,	ADDR_FLASH_SECTOR_3	},
	{FLASH_Sector_4	,	ADDR_FLASH_SECTOR_4	},
	{FLASH_Sector_5	,	ADDR_FLASH_SECTOR_5	},
	{FLASH_Sector_6	,	ADDR_FLASH_SECTOR_6	},
	{FLASH_Sector_7	,	ADDR_FLASH_SECTOR_7	},
	{FLASH_Sector_8	,	ADDR_FLASH_SECTOR_8	},
	{FLASH_Sector_9	,	ADDR_FLASH_SECTOR_9	},
	{FLASH_Sector_10	,	ADDR_FLASH_SECTOR_10	},
	{FLASH_Sector_11	,	ADDR_FLASH_SECTOR_11	},
	{FLASH_Sector_12	,	ADDR_FLASH_SECTOR_12	},
	{FLASH_Sector_13	,	ADDR_FLASH_SECTOR_13	},
	{FLASH_Sector_14	,	ADDR_FLASH_SECTOR_14	},
	{FLASH_Sector_15	,	ADDR_FLASH_SECTOR_15	},
	{FLASH_Sector_16	,	ADDR_FLASH_SECTOR_16	},
	{FLASH_Sector_17	,	ADDR_FLASH_SECTOR_17	},
	{FLASH_Sector_18	,	ADDR_FLASH_SECTOR_18	},
	{FLASH_Sector_19	,	ADDR_FLASH_SECTOR_19	},
	{FLASH_Sector_20	,	ADDR_FLASH_SECTOR_20	},
	{FLASH_Sector_21	,	ADDR_FLASH_SECTOR_21	},
	{FLASH_Sector_22	,	ADDR_FLASH_SECTOR_22	},
	{FLASH_Sector_23	,	ADDR_FLASH_SECTOR_23	},
};

#else
extern structFlashSector g_strtWholeFlashSectors[FLASH_NUMBER_SECTOR];
#endif
/* Private function prototypes -----------------------------------------------*/
uint16_t FLASH_If_Init(void);
uint16_t FLASH_If_Erase (uint32_t Add);
uint16_t FLASH_If_Write(uint32_t pDestAddr, uint32_t Len, uint32_t pSrcAddr);
void FLASH_If_Read (uint32_t Add, uint32_t Len, uint8_t* p_bTgtBuff);
uint16_t FLASH_If_DeInit(void);
void ResetUpgradeArea(enumFlashArea eFlashArea);
enumbool FLASH_If_GetSecure(void);
void FLASH_If_SetSecure(void);

void JumpToBootloader(void);
#endif
