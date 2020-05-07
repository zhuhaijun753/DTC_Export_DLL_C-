/*
*  m69aLLD.h
*  File description:  This file includes the LLD functions to connect the FTL user for high level apllication interfaces.
*  
*  Copyright Micron Technology 2011 *
*/

#include "2_Middle\3_Storage\2_Driver\3_Nand_Flash\2_Driver\fsmc_nand.h"

/* external global variables */
extern unsigned int gFTL_StartBlk;
extern unsigned int gFTL_DataBlk;
extern unsigned int gFTL_OOB_size;
extern unsigned int gNand_Bytes_per_Page_main;
extern unsigned int gNand_Sector_Size;
extern unsigned int gNand_Bytes_per_Page_spare;
extern unsigned int gNand_Page_per_Blk;
extern unsigned int gNand_Page_Shift_Bits;
extern unsigned int gNand_Page_Mask_Bits;
extern unsigned int gNand_Managed_Pages;

#define M_SHIFT_8BIT           	8
#define M_PASS  1
#define M_FAIL  0
#define M_NAND_READY      0xe0
#define M_NAND_STATUS_WARN      0xe8
#define M_NAND_BUSY       0x01
#define M_NAND_TIMEOUT_ERROR  0x01
#define M_NAND_STATUS_ERROR   0x01
#define M_FTL_SYSTEM_OOB0_4BYTE	      0x804
#define M_FTL_SYSTEM_OOB1_4BYTE	      0x814

#define mU32    unsigned int
#define mU16    unsigned short
#define mU8     unsigned char

#define NAND_CMD *(__IO mU8 *)(Bank_NAND_ADDR | CMD_AREA)
#define NAND_ADR *(__IO mU8 *)(Bank_NAND_ADDR | ADDR_AREA)
#define NAND_DAT *(__IO mU8 *)(Bank_NAND_ADDR | DATA_AREA)
    
typedef struct {
	mU32    number;
	mU32    startBlock;
	mU32    sizeInBlocks;
	mU32    numOfPageInBlock;
	
} m_partitionInfo;

/* APIs */
mU8 MFTL_FormatPartition(mU8 partition);
mU8 MFTL_Initialize(mU8 partitionsNumber,m_partitionInfo * partitionInfos);
mU8 MFTL_WriteSector(unsigned char partitionNum, unsigned int LBA_PageNum, unsigned char *pBuffer);
mU8 MFTL_ReadSector(unsigned char partitionNum, unsigned int LBA_PageNum, unsigned char *pBuffer);
mU8 MFTL_DeleteSector(unsigned char partitionNum, unsigned int LBA_PageNum);


/* utility LLD functions */
unsigned char m_ftl_initVars(void);
void MICRON_NAND_Init(void);
void MICRON_NAND_unlock(unsigned int bLow, unsigned int bHigh);
unsigned char MICRON_NAND_Reset(void);
void MICRON_NAND_ECC_ON(void);
void MICRON_NAND_ECC_OFF(void);
void MICRON_NAND_ReadID(unsigned char *idBytes);


/* external functions */
extern void M_NAND_Close(void);
extern void M_NAND_Open(void);
extern unsigned short M_NAND_DataOutput(void);
extern void M_NAND_DataInput(unsigned short ubData);
extern void M_NAND_CommandInput(unsigned char ubCommand);
extern void M_NAND_AddressInput(unsigned char ubAddress);

extern void NAND_Board_cntlr_Init(void);
extern unsigned char Nand_cntlr_Reset(unsigned char *cmd);
extern void NAND_cntlr_unlock(unsigned char *cmd);
extern void NAND_cntlr_ECC_ON(unsigned char *cmd);
extern void NAND_cntlr_ECC_OFF(unsigned char *cmd);
extern unsigned char NAND_cntlr_Page_Read(unsigned char *cmd, unsigned char *pBuffer, unsigned short Buffer_Len);
extern unsigned char NAND_cntlr_Page_Write(unsigned char *cmd, unsigned char *pBuffer, unsigned short Buffer_Len);
extern void NAND_cntlr_ReadID(unsigned char *cmd, unsigned char *idBytes);
extern unsigned char m_reFormat(void);
extern unsigned char m_ftl_init(void);
extern unsigned char m_mftl_Get_Number_Of_Logical_Block( unsigned short *pMax_Number_Of_Blocks );
extern unsigned char m_read_mftl_page(unsigned int pageLBA, unsigned char *pBuffer, unsigned short Page_Offset, unsigned short Buffer_Len);
extern unsigned char m_write_mftl_page(unsigned int addrLBA, unsigned char *buf, unsigned short pOffset, unsigned short pLen);
extern unsigned char m_read_full_page(unsigned int pageLBA, unsigned char *pBuffer, unsigned short Page_Offset, unsigned short Buffer_Len);
extern unsigned char m_write_full_page(unsigned int addrLBA, unsigned char *buf, unsigned short pOffset, unsigned short pLen);
extern unsigned char m_delete_full_page(unsigned int addrLBA);


extern unsigned char m_ftl_version_number(unsigned int *verNum);
extern unsigned char ucFTL_INIT_initialized;

unsigned char M_NAND_Init(void);
unsigned char M_NAND_ftl_version_number(unsigned int *verNum);
unsigned char m_x16_word_aligned(unsigned char *buf);
void m_delay_loop(int val);
unsigned char M_NAND_Page_Write(unsigned short Block_idx, unsigned char Page_idx, unsigned short Page_Offset, unsigned char *pBuffer, unsigned short Buffer_Len);
unsigned char M_NAND_Page_Read(unsigned short Block_idx, unsigned char Page_idx, unsigned short Page_Offset, unsigned char *pBuffer, unsigned short Buffer_Len);
unsigned char M_FTL_NAND_erase(unsigned int blk);
unsigned int NAND_cntlr_GetStatus(void);
unsigned int NAND_cntlr_ReadStatus(void);
unsigned char M_NAND_Format(void);
unsigned char M_NAND_Get_Number_Of_Logical_Block(unsigned short *pMax_Number_Of_Blocks);
void m_eraseAll_Managed_Blks(void);
mU8 m_internal_PA_Write(mU32 addr, mU16 Offset, mU8 *pBuf, mU16 pLen, mU8 *oobBuf);
mU8 m_internal_PA_Write_Byte(mU32 addr, mU16 ppOffset, mU8 *pBuf, mU16 pLen, mU8 *oobBuf);
mU8 m_internal_PA_Read(mU32 addr, mU16 pOffset, mU8 *pBuf, mU16 pLen, mU8 *oobBuf);

/******END OF FILE****/
