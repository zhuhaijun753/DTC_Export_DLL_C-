/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: External flash driver
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __EXFLASH_DRIVER_H__
#define __EXFLASH_DRIVER_H__

//#include "OBDToolSetting.h"
/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define NUMBER_OF_BYTE_ID             4

#define FLASH_SPI_CLK_RATE            (10000000)
#define FLASH_SPI_CLKS_PER_MS         (FLASH_SPI_CLK_RATE / 1000)
#define FLASH_STATUS_READS_PER_MS     (FLASH_SPI_CLKS_PER_MS / 16)



    /* Exported macro ------------------------------------------------------------*/
    /* Select SPI FLASH: Chip Select pin low  */
#define FLASH_CS_LOW()       __Clear_Gpio_Pin(FLASH_SPI_PORT_CS, FLASH_SPI_PIN_CS)
    /* Deselect SPI FLASH: Chip Select pin high */
#define FLASH_CS_HIGH()      __Set_Gpio_Pin(FLASH_SPI_PORT_CS, FLASH_SPI_PIN_CS)

#define FLASH_MAX_BUSY_POLL_IDLE              100
#define FLASH_MAX_BUSY_POLL_PROGRAM_PAGE      (FLASH_STATUS_READS_PER_MS * 5)
#define FLASH_MAX_BUSY_POOL_ERASE_CHIP        (FLASH_STATUS_READS_PER_MS * 200000) /*200Sec: Spec Atmel Typ. 64, Max 112 sec, Test: 57sec*/
#define FLASH_MAX_BUSY_POOL_ERASE_BLOCK       (FLASH_STATUS_READS_PER_MS * 2000) /*2000 ms: Spec Atmel Typ. 400, Max 950 sec, Test: 57Sec 128 block*/


#define FLASH_MAX_BUSY_POLL_ERASE_4KB         800 // 800ms S25FL064P
//#define FLASH_MAX_BUSY_POLL_ERASE_64KB        2000 // 2000ms S25FL064P
#define FLASH_MAX_BUSY_POLL_ERASE_64KB        4000 //3s  M25PX32 
#define FLASH_WRITE_RESGISTER_CYCLE           200 // 200ms S25FL064P
#define FLASH_INSTR_WORD_PROGRAM_CYCLE              20  //20us only SST25VF032B


#define FLASH_MAX_BUSY_POLL_ERASE_4KB         800 // 800ms S25FL064P
#define FLASH_WRITE_RESGISTER_CYCLE           200 // 200ms S25FL064P

    //*****************************************************************************
    //
    // Labels for the instructions supported by the Serial FLASH part.
    //
    //*****************************************************************************
#define FLASH_INSTR_WRITE_ENABLE      0x06
#define FLASH_INSTR_WRITE_DISABLE     0x04
#define FLASH_INSTR_READ_STATUS       0x05
#define FLASH_INSTR_WRITE_STATUS      0x01
#define FLASH_INSTR_READ_DATA         0x03
#define FLASH_INSTR_PAGE_PROGRAM      0x02
#define FLASH_INSTR_64K_BLOCK_ERASE   0xD8    /*Sector/Block Erase*/
#define FLASH_INSTR_BULK_ERASE        0xC7  /* Bulk Erase instruction */

#define FLASH_INSTR_4KB_ERASE         0x20    //4KB erase
#define FLASH_INSTR_ID_READ           0x9F
#define FLASH_CONFIG_READ             0x35      // spansion, need to check other chips



#define FLASH_INSTR_WORD_PROGRAM      0xAD  //only SST25VF032B
#define FLASH_INSTR_BYTE_PROGRAM      0x02  //only SST25VF032B
    //*****************************************************************************
    //
    // Status register bit definitions
    //
    //*****************************************************************************
#define FLASH_STATUS_BUSY                 0x01
#define FLASH_STATUS_WRITE_ENABLE_LATCH   0x02
#define FLASH_STATUS_ERASE_PROGRAM_ERROR  0x20
/* Different flag for each Flash
#define FLASH_STATUS_BLOCK_PROTECT_0      0x04
#define FLASH_STATUS_BLOCK_PROTECT_1      0x08
#define FLASH_STATUS_REGISTER_PROTECT     0x80
*/


#define JEDEC_AT45DB321D_A 0x1F270000 // 32Mbit
#define JEDEC_AT45DB321D_B 0x1F270100 // 32Mbit
#define JEDEC_AT45DB161D 0x1F260000  // 16Mbit
#define JEDEC_AT45DB642D 0x1F280000
#define JEDEC_AT25DF641 0x1F480000    //64Mbit
#define JEDEC_M25PX32 0x10167120 //32 Mbit
#define JEDEC_M25PX64 0x10177120 //64 Mbit
#define JEDEC_SST25VF080B 0xBF258EBF
#define JEDEC_SST25VF032B 0xBF254ABF
#define JEDEC_SST25VF064C 0xBF254BBF
#define JEDEC_W25Q32BV 0xEF401600
#define JEDEC_W25Q64BV 0xEF401700
#define JEDEC_S25FL32P 0x0102154D
#define JEDEC_S25FL64P 0x0102164D
#define JEDEC_S25FL128P 0x0120184D
#define JEDEC_AT25DF641 0x1F480000

////Oct0314 Lap Dang moved this enum to here
//typedef enum _EXFLASH
//{
//  EXFLASH_AT45DB321D,   // 32Mbit
//  EXFLASH_AT45DB161D,   // 16Mbit
//  EXFLASH_AT45DB642D,
//  EXFLASH_M25PX32,      //32 Mbit
//  EXFLASH_M25PX64,      //64 Mbit
//  EXFLASH_SST25VF032B,
//  EXFLASH_SST25VF064C,
//  EXFLASH_W25Q32BV,
//  EXFLASH_W25Q64BV,
//  EXFLASH_S25FL32P,
//  EXFLASH_S25FL64P,
//  EXFLASH_S25FL128S,
//  EXFLASH_SST25VF080B,
//  EXFLASH_NONE = 0xFF
//} enumExFlashType;

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

//#ifdef __EXFLASH_DRIVER_C__
//static enumbool FLASH_IsBusy(void);
//enumExFlashType eExFlashTemp;
//#else
//extern enumExFlashType eExFlashTemp;
//#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void Init_FlashCS(void);
enumbool ExFlash_HwInit(void);
uint8 FLASH_StatusGet(void);
enumbool FLASH_IdleWait(uint32 iMaxRetries);
enumbool FLASH_WriteEnable(void);
void FLASH_InstructionRead(uint8 *bData, uint32 iLen);
void FLASH_InstructionWrite(uint8 bInstruction,
                            uint8 *bData,
                            uint16 usLen);
void FLASH_InstructionDataWrite(uint8 *bData, uint16 usLen);
void FLASH_InstructionEnd(void);

enumbool FLASH_WriteStatus(uint8 bStatus);
enumbool FLASH_CheckBusyWithMsTimeOut(uint16 imsTimeOut);
enumbool FLASH_CheckBusyWithUsTimeOut(uint16 iusTimeOut);
enumbool FLASH_WriteConfigureReLap Danger(uint8 bConfigure);
enumbool FLASH_WriteDisable(void);

enumbool FLASH_WriteStatus(uint8 bStatus);
enumbool FLASH_CheckBusyWithMsTimeOut(uint16 imsTimeOut);



#endif


