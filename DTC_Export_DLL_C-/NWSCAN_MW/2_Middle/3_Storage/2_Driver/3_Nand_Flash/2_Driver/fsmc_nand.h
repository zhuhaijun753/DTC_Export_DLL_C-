/******************** (C) COPYRIGHT 2009 STMicroelectronics ********************
* File Name          : fsmc_nand.h
* Author             : MCD Application Team
* Version            : V2.0.0
* Date               : 04/27/2009
* Description        : Header for fsmc_nand.c file.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FSMC_NAND_H
#define __FSMC_NAND_H

/* Includes ------------------------------------------------------------------*/
#include "coremcu.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
    uint8_t Maker_ID;
    uint8_t Device_ID;
    uint8_t Third_ID;
    uint8_t Fourth_ID;
    uint8_t Fifth_ID;
}NAND_IDTypeDef;

typedef struct
{
    uint16_t Zone;
    uint16_t Block;
    uint16_t Page;
} NAND_ADDRESS;

#define BUFFER_SIZE         0x1000 //0x1000          		//0x400
#define NUM_2KBYTE          0X800
#define NAND_MT_MakerID     0x2C
#define NAND_MT_DeviceID    0xDA
#define Bank2_NAND_ADDR    ((uint32_t)0x70000000)

//#define FSMC_Bank_NAND     FSMC_Bank2_NAND

#define Bank_NAND_ADDR     Bank2_NAND_ADDR
#define ROW_ADDRESS (Address.Page + (Address.Block + (Address.Zone * NAND_ZONE_SIZE)) * NAND_BLOCK_SIZE)
typedef struct _strctPicInNand
{
    NAND_ADDRESS    StartAddr;
    uint32_t        bByteLength;
}strtPicInNand;


/* Exported constants --------------------------------------------------------*/
/* NAND Area definition  for STM3210E-EVAL Board RevD */
#define CMD_AREA                   (uint32_t)(1<<16)  /* A16 = CLE  high */
#define ADDR_AREA                  (uint32_t)(1<<17)  /* A17 = ALE high */

#define DATA_AREA                  ((uint32_t)0x00000000)

/* FSMC NAND memory command */
#define	NAND_CMD_AREA_A            ((uint8_t)0x00)
#define	NAND_CMD_AREA_B            ((uint8_t)0x01)
#define NAND_CMD_AREA_C            ((uint8_t)0x50)
#define NAND_CMD_AREA_TRUE1        ((uint8_t)0x30)

#define NAND_CMD_WRITE0            ((uint8_t)0x80)
#define NAND_CMD_WRITE_TRUE1       ((uint8_t)0x10)

#define NAND_CMD_ERASE0            ((uint8_t)0x60)
#define NAND_CMD_ERASE1            ((uint8_t)0xD0)

#define NAND_CMD_READID            ((uint8_t)0x90)
#define NAND_CMD_STATUS            ((uint8_t)0x70)
#define NAND_CMD_LOCK_STATUS       ((uint8_t)0x7A)
#define NAND_CMD_RESET             ((uint8_t)0xFF)

/* NAND memory status */
#define NAND_VALID_ADDRESS         ((uint32_t)0x00000100)
#define NAND_INVALID_ADDRESS       ((uint32_t)0x00000200)
#define NAND_TIMEOUT_ERROR         ((uint32_t)0x00000400)
#define NAND_BUSY                  ((uint32_t)0x00000000)
#define NAND_ERROR                 ((uint32_t)0x00000001)
#define NAND_READY                 ((uint32_t)0x00000040)

/* FSMC NAND memory parameters */
#if 0 //change to 1 if we want to use NAND FLASH of STM32Eval Board
#define NAND_PAGE_SIZE             ((uint16_t)0x0200) /* 512 bytes per page w/o Spare Area */
#define NAND_BLOCK_SIZE            ((uint16_t)0x0020) /* 32x512 bytes pages per block */
#define NAND_ZONE_SIZE             ((uint16_t)0x0400) /* 1024 Block per zone */
#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x0010) /* last 16 bytes as spare area */
#define NAND_MAX_ZONE              ((uint16_t)0x0004) /* 4 zones of 1024 block */
#else
#define NAND_PAGE_SIZE             ((uint16_t)0x0800)		// 2048
#define NAND_BLOCK_SIZE            ((uint16_t)0x0040)		// 64
#define NAND_ZONE_SIZE             ((uint16_t)0x0800)		// 2048
#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x0040)		// 64
#define NAND_MAX_ZONE              ((uint16_t)0x0002)		// 2
#endif

/* FSMC NAND memory address computation */
#define ADDR_1st_CYCLE(ADDR)       (uint8_t)((ADDR)& 0xFF)               /* 1st addressing cycle */
#define ADDR_2nd_CYCLE(ADDR)       (uint8_t)(((ADDR)& 0xFF00) >> 8)      /* 2nd addressing cycle */
#define ADDR_3rd_CYCLE(ADDR)       (uint8_t)(((ADDR)& 0xFF0000) >> 16)   /* 3rd addressing cycle */
#define ADDR_4th_CYCLE(ADDR)       (uint8_t)(((ADDR)& 0xFF000000) >> 24) /* 4th addressing cycle */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void FSMC_NAND_Init(void);
uint32_t FSMC_NAND_Reset(void);
void FSMC_NAND_ReadID(NAND_IDTypeDef* NAND_ID);
void NAND_FSMC_IntEnable(void);
void ButtonInit(void);
#ifdef _FSMC_NAND_C_
uint8_t TxBufferTest[BUFFER_SIZE];
uint8_t RxBufferTest[BUFFER_SIZE];
uint8_t Buffer2Kbyte[NUM_2KBYTE];
NAND_IDTypeDef NAND_ID;
GPIO_InitTypeDef GPIO_InitStructure;

__IO uint32_t PageNumber = 2, WriteReadStatus = 0, status = 0;
#else
extern uint8_t TxBufferTest[BUFFER_SIZE];
extern uint8_t RxBufferTest[BUFFER_SIZE];
extern NAND_IDTypeDef NAND_ID;
extern  GPIO_InitTypeDef GPIO_InitStructure;
extern __IO uint32_t PageNumber,WriteReadStatus,status;
extern uint8_t Buffer2Kbyte[NUM_2KBYTE];
#endif

#endif /* __FSMC_NAND_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
