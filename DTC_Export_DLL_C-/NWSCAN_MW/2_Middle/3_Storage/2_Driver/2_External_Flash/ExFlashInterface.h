/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __EXFLASH_INTERFACE_H__
#define __EXFLASH_INTERFACE_H__

#include    "ExFlashDriver.h"

typedef enum _enumEraseFlash
{
    ERASE_NONE   = 0x00,
    ERASE_DB     = 1,
    ERASE_IMG    = 2,
    ERASE_ALL    = 3,
} enumEraseFlash;
//Oct0314 Lap Dang moved this enum to here
typedef enum _EXFLASH
{
  EXFLASH_AT45DB321D,   // 32Mbit
  EXFLASH_AT45DB161D,   // 16Mbit
  EXFLASH_AT45DB642D,
  EXFLASH_M25PX32,      //32 Mbit
  EXFLASH_M25PX64,      //64 Mbit
  EXFLASH_SST25VF032B,
  EXFLASH_SST25VF064C,
  EXFLASH_W25Q32BV,
  EXFLASH_W25Q64BV,
  EXFLASH_S25FL32P,
  EXFLASH_S25FL64P,
  EXFLASH_S25FL128S,
  EXFLASH_SST25VF080B,
  EXFLASH_NONE = 0xFF
} enumExFlashType;
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define FLASH_BUSY_TIMEOUT       10000

#define FLASH_PAGE_SIZE          256
#define FLASH_512B_SIZE          0X200
#define FLASH_4KB_SIZE           0x1000
#define FLASH_64K_BLOCK_SIZE     0x10000
#define FLASH_512KB_SIZE         0X80000
#define FLASH_1MB_SIZE           0x100000


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __EXFLASH_INTERFACE_C__
static uint32 M25FlashWritePage( uint8 *p_bSrc, uint32 iAddress, uint32 iLength);
static uint32 M25FlashRead(uint8 *p_bDst,
                           uint32 iAddress,
                           uint32 iLength);
static void M25FlashWrite(uint32 iWriteAddr,
                          uint32 iNumByteToWrite,
                          uint8 *p_bBuffer);
void SST25FlashWriteByte(unsigned char bData,
                         unsigned int iAddr);
void SST25FlashWriteWord(unsigned char *bData,
                         unsigned int iAddr,
                         unsigned int    iNumberByte);
void SST25VF032FlashWrite(unsigned int iAddress, unsigned int iNumberBytes,unsigned char* bDataBuffer);
typedef void (*fpExFlashWrite)(uint32 iAddress, uint32 iNumberBytes,uint8 *bDataBuffer);
fpExFlashWrite fExFlashWrite;
#else
typedef void (*fpExFlashWrite)(uint32 iAddress, uint32 iNumberBytes,uint8 *bDataBuffer);
extern fpExFlashWrite fExFlashWrite;
#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void GpioInit_FlashCS(void);

enumbool ExFlashInit(void);

void ExFlashRead(uint32 iAddress, uint32 iNumberBytes,uint8 *bDataBuffer);

void ExFlashWrite(uint8 *bDataBuffer, uint32 iAddress, uint32 iNumberBytes);

enumbool ExFlashChipErase(void);

enumbool ExFlashBlockErase (uint32 iAddress, uint32 iLength);

enumbool ExFlash4kbErase (uint32 iAddress, uint32 iNumberBlock);

enumbool ExFlashCheckBusy(uint32 iTimeOut);



#if 1
void FlashTest(void);
#endif


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 11 2014

*Function name: ExternalFlashType_Get
*Descrtiption : this function is used to get the current extenal flash type 
                on board
*Input        : None
*Output       : enumExFlashType - type of external flash
*-----------------------------------------------------------------------------*/
enumExFlashType ExternalFlashType_Get(void);

#endif


