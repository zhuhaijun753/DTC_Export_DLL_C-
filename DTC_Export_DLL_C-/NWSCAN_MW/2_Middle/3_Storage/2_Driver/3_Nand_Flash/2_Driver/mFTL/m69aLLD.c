/*
*  m69aLLD.c
*  File description:  This file includes the LLD functions to connect the FTL user for high level apllication interfaces.
*  
*  Copyright Micron Technology 2011 *
*/

#include "m69aLLD.h"


/*******************************************************************************
* Function Name  : M_NAND_Init
* Description    : Initialize FTL
* Input          : None
* Output         : None
* Return         : M_PASS or M_FAIL
*******************************************************************************/
unsigned char M_NAND_Init(void)
{
 
  m_partitionInfo pInfo;
  
  pInfo.number = 0;
  pInfo.startBlock = 0;
  pInfo.sizeInBlocks = 1984;
  pInfo.numOfPageInBlock = 64;
  
  return MFTL_Initialize(0, &pInfo);

}

unsigned char MFTL_Initialize(unsigned char partitionsNumber,m_partitionInfo * partitionInfos)
{

	if (partitionsNumber != 0)
	{
		return M_FAIL;
    }
	
	MICRON_NAND_Reset();
	MICRON_NAND_ECC_ON();	
	gFTL_StartBlk = partitionInfos->startBlock;
	gFTL_DataBlk  = partitionInfos->sizeInBlocks;
	
	gNand_Page_per_Blk = partitionInfos->numOfPageInBlock;
	gNand_Managed_Pages = gFTL_DataBlk *  gNand_Page_per_Blk;
	gNand_Sector_Size = 512;
	gNand_Bytes_per_Page_main = 2048;
	gNand_Bytes_per_Page_spare = 64;	
	gNand_Page_Shift_Bits = 6;
	gNand_Page_Mask_Bits  = 0x3f;	
	//Init FTL variables
	if (m_ftl_initVars() != M_PASS)
	{
		return M_FAIL;	
    }
/* erase data + spare */	
//	if (MFTL_FormatPartition(0) != M_PASS)
//		return M_FAIL;
//        while(1);

  return m_ftl_init();

}


/******************************************************************************
* Function Name  : M_NAND_ftl_version_number
* Description    : To get three 4-byte unsigned integer numbers to represent MAJOR,MINOR,EVAL
* Input          : a point to the three unsigned integers
* Return         : if pass a NULL point, return fail, otherwise return pass
*******************************************************************************/
unsigned char M_NAND_ftl_version_number(unsigned int *verNum)
{
   return m_ftl_version_number(verNum);
}

/******************************************************************************
* Function Name  : MICRON_NAND_Reset
* Description    : This routine reset the NAND FLASH
* Input          : None
* Output         : None
* Return         : pass or fail
*******************************************************************************/
unsigned char MICRON_NAND_Reset(void)
{
  unsigned char cmd[1];

  cmd[0] = 0xff;
  return Nand_cntlr_Reset(cmd);
}

/* unlock blocks */
void MICRON_NAND_unlock(unsigned int bLow, unsigned int bHigh)
{
  unsigned int blkLow,blkHigh;
  unsigned char cmd[8];
  blkLow = bLow << gNand_Page_Shift_Bits;
  blkHigh = bHigh << gNand_Page_Shift_Bits;
  cmd[0] = 0x23;
  cmd[1] = (unsigned char)(blkLow & 0xff);
  cmd[2] = (unsigned char)((blkLow) >> 8);
  cmd[3] = (unsigned char)((blkLow) >> 16);
  cmd[4] = 0x24;
  cmd[5] = (unsigned char)(blkHigh & 0xff);
  cmd[6] = (unsigned char)((blkHigh) >> 8);
  cmd[7] = (unsigned char)((blkHigh) >> 16);
  NAND_cntlr_unlock(cmd);

  return ;
}

void MICRON_NAND_ECC_ON(void)
{

  unsigned char cmd[4];
  cmd[0] = 0xee;
  cmd[1] = 0x90;
  cmd[2] = 0xef;
  cmd[3] = 0x90;

  NAND_cntlr_ECC_ON(cmd);

  return ;  

}

void MICRON_NAND_ECC_OFF(void)
{

  unsigned char cmd[4];
  cmd[0] = 0xee;
  cmd[1] = 0x90;
  cmd[2] = 0xef;
  cmd[3] = 0x90;

  NAND_cntlr_ECC_OFF(cmd);

  return ;  
}

/*
 * Check for byte alignment
 */
unsigned char m_x16_word_aligned(unsigned char *buf)
{
	unsigned int u32Var1;
	
	u32Var1 = (unsigned int)buf;
	if ( u32Var1 & 0x01 )
	{
		return M_FAIL;
    }
	else
	{
		return M_PASS;
}
}


/******************************************************************************
* Function Name  : MICRON_NAND_Write
* Description    : This routine is for writing one or several 512 Bytes Page size.
* Input          : - pBuffer: pointer on the Buffer containing data to be written   
*                  - Address: First page address
*                  - NumPageToWrite: Number of page to write  
* Output         : None
* Return         : PASS = 1  --  FAIL = 0;

*******************************************************************************/
unsigned char M_NAND_Page_Write(unsigned short Block_idx, unsigned char Page_idx, unsigned short Page_Offset, unsigned char *pBuffer, unsigned short Buffer_Len)
{
    unsigned int pageLBA;
	if ( Buffer_Len == 0 )
	{
		return M_FAIL;
    }
	if (Page_idx >= gNand_Page_per_Blk)
	{
		return M_FAIL;
    }
	if ((Buffer_Len+Page_Offset) > gNand_Bytes_per_Page_main)
	{
		return M_FAIL;
    }
	
	pageLBA = (unsigned int)Block_idx;
	pageLBA = pageLBA << gNand_Page_Shift_Bits;
	pageLBA = pageLBA | Page_idx;
	
	if ( Buffer_Len == gNand_Bytes_per_Page_main )
	{
		return m_write_full_page(pageLBA, pBuffer, Page_Offset, Buffer_Len);
    }
  else
  {
    return m_write_mftl_page(pageLBA, pBuffer, Page_Offset, Buffer_Len);
  }


}



/******************************************************************************
* Function Name  : MICRON_NAND_Read
* Description    : This routine is for sequential read from one or several 
*                  512 Bytes Page size.
* Input          : - pBuffer: pointer on the Buffer to fill  
*                  - Address: First page address
*                  - NumPageToRead: Number of page to read
* Output         : None
* Return         : Pass = 1  -- Fail = 0
*******************************************************************************/
unsigned char M_NAND_Page_Read(unsigned short Block_idx, unsigned char Page_idx, unsigned short Page_Offset, unsigned char *pBuffer, unsigned short Buffer_Len)
{
	
  unsigned int pageLBA;
	
	if ( Buffer_Len == 0 )
	{
		return M_FAIL;
    }

	if (Page_idx >= gNand_Page_per_Blk)
	{
		return M_FAIL;
    }
	if ((Buffer_Len+Page_Offset) > gNand_Bytes_per_Page_main)
	{
		return M_FAIL;
    }
	
	pageLBA = (unsigned int)Block_idx;
	pageLBA = pageLBA << gNand_Page_Shift_Bits;
	pageLBA = pageLBA | Page_idx;
	
	if ( Buffer_Len == gNand_Bytes_per_Page_main )
	{
		return m_read_full_page(pageLBA, pBuffer, Page_Offset, Buffer_Len);
    }
  else
  {
    return m_read_mftl_page(pageLBA, pBuffer, Page_Offset, Buffer_Len);
  }

}


/******************************************************************************
* Function Name  : M_NAND_Format
* Description    : This routine is to reformat the device everything being erased
*                  
* Input          : None
* Output         : None
* Return         : Pass = 1  -- Fail = 0
*******************************************************************************/
unsigned char M_NAND_Format(void)
{
    	
	return m_reFormat(); 

}


unsigned char M_NAND_Get_Number_Of_Logical_Block(unsigned short *pMax_Number_Of_Blocks)
{
	return m_mftl_Get_Number_Of_Logical_Block( pMax_Number_Of_Blocks );
}


/*
    Micron Read 4 ID bytes
*/
void MICRON_NAND_ReadID(unsigned char *idBytes)
{

	unsigned char cmd[2];

	cmd[0] = 0x90;
	cmd[1] = 0x00;

	NAND_cntlr_ReadID(cmd, idBytes);

	return;

}

unsigned char MFTL_FormatPartition(unsigned char partition)
{
	int rtn;
	
	if (partition != 0)
	{
		rtn = M_FAIL;
    }
	else
	{
		rtn = m_reFormat();
    }
		
	return rtn;

}



unsigned char MFTL_WriteSector(unsigned char partitionNum, unsigned int LBA_PageNum, unsigned char *pBuffer)
{
    unsigned int pageLBA,pageIdx;
	if (partitionNum != 0)
	{
		return M_FAIL;
    }
	if (LBA_PageNum > gNand_Managed_Pages)
	{
		return M_FAIL;			
    }
	if (pBuffer == 0)
	{
		return M_FAIL;
    }
	
	pageLBA = LBA_PageNum/gNand_Page_per_Blk;
	pageLBA = pageLBA << gNand_Page_Shift_Bits;
	pageIdx = LBA_PageNum % gNand_Page_per_Blk;
	pageLBA = pageLBA | pageIdx;
	
	return m_write_full_page(pageLBA, pBuffer, 0, gNand_Bytes_per_Page_main);

}

unsigned char MFTL_ReadSector(unsigned char partitionNum, unsigned int LBA_PageNum, unsigned char *pBuffer)
{
    unsigned int pageLBA,pageIdx;
    
	if (partitionNum != 0)
	{
		return M_FAIL;
    }
	if (LBA_PageNum > gNand_Managed_Pages)
	{
		return M_FAIL;			
    }
	if (pBuffer == 0)
	{
		return M_FAIL;
    }
	
	pageLBA = LBA_PageNum/gNand_Page_per_Blk;
	pageLBA = pageLBA << gNand_Page_Shift_Bits;
	pageIdx = LBA_PageNum % gNand_Page_per_Blk;
	pageLBA = pageLBA | pageIdx;
	
	return m_read_full_page(pageLBA, pBuffer, 0, gNand_Bytes_per_Page_main);

}


unsigned char MFTL_DeleteSector(unsigned char partitionNum, unsigned int LBA_PageNum)
{
    unsigned int pageLBA,pageIdx;
	if (partitionNum != 0)
	{
		return M_FAIL;
    }
	if (LBA_PageNum > gNand_Managed_Pages)
	{
		return M_FAIL;
    }
			
	pageLBA = LBA_PageNum/gNand_Page_per_Blk;
	pageLBA = pageLBA << gNand_Page_Shift_Bits;
	pageIdx = LBA_PageNum % gNand_Page_per_Blk;
	pageLBA = pageLBA | pageIdx;
	
	return m_delete_full_page(pageLBA);

}


/* unlock blocks */
void NAND_cntlr_unlock(unsigned char *cmd)
{
	
  NAND_CMD = cmd[0];
  NAND_ADR = cmd[1];
  NAND_ADR = cmd[2];
  NAND_ADR = cmd[3];
  NAND_CMD = cmd[4];
  NAND_ADR = cmd[5];
  NAND_ADR = cmd[6];
  NAND_ADR = cmd[7];
  

  return ;
}

void NAND_cntlr_ECC_ON(unsigned char *cmd)
{

  unsigned char d0,d1,d2,d3;
  /* get feature  */
  
  NAND_CMD = cmd[0];
  NAND_ADR = cmd[1];
  d0 = d1 = d2 = d3 = 0;
  d0 = NAND_DAT;
  d1 = NAND_DAT;
  d2 = NAND_DAT;
  d3 = NAND_DAT;

  /* set feature */
  NAND_CMD = cmd[2];
  NAND_ADR = cmd[3];

  d0 = d0 | 0x08;
  NAND_DAT = d0; 
  NAND_DAT = d1; 
  NAND_DAT = d2;
  NAND_DAT = d3;
  
  return;
}

void NAND_cntlr_ECC_OFF(unsigned char *cmd)
{
   unsigned char d0,d1,d2,d3;
  /* get feature  */

  
  NAND_CMD = cmd[0];
  NAND_ADR = cmd[1];
  d0 = d1 = d2 = d3 = 0;
  d0 = NAND_DAT;
  d1 = NAND_DAT;
  d2 = NAND_DAT;
  d3 = NAND_DAT;

  /* set feature */
  NAND_CMD  = cmd[2];
  NAND_ADR = cmd[3];
   d0 = d0 & 0xf7;
  NAND_DAT = d0; 
  NAND_DAT = d1; 
  NAND_DAT = d2;
  NAND_DAT = d3;
 
	return;
}


void m_delay_loop(int val)
{
	int i;
	i= val;
	while(i--)
    {
        ;
    }
}

/******************************************************************************
* Function Name  : NAND_cntlr_ReadStatus
* Description    : Reads the NAND memory status using the Read status command 
* Input          : None
* Output         : None
* Return         : The status of the NAND memory. This parameter can be:
*                   - NAND_BUSY: when memory is busy
*                   - NAND_READY: when memory is ready for the next operation    
*                   - NAND_ERROR: when the previous operation gererates error   
*******************************************************************************/
unsigned int NAND_cntlr_ReadStatus(void)
{
  unsigned char status;

  /* Read status operation ------------------------------------ */
  
  NAND_CMD = (unsigned char)0x70;
  status = M_NAND_BUSY;
  m_delay_loop(0x1);
  status = NAND_DAT;
  status = status | 0x20;  // to be sure the read case always return 0xe0 for status.
  return (status & 0xe1);
}


/******************************************************************************
* Function Name  : NAND_cntlr_GetStatus
* Description    : Get the NAND operation status
* Input          : None
* Output         : None
* Return         : New status of the NAND operation. This parameter can be:
*                   - NAND_TIMEOUT_ERROR: when the previous operation generate 
*                     a Timeout error
*                   - NAND_READY: when memory is ready for the next operation    
*******************************************************************************/
unsigned int NAND_cntlr_GetStatus(void)
{
  unsigned int timeout = 0x3, status = M_NAND_READY;

  status = NAND_cntlr_ReadStatus(); 

  while ((status != M_NAND_READY) && ( timeout != 0x00))
  {
	  timeout --;
	  status = NAND_cntlr_ReadStatus();
  }

  if (status == M_NAND_READY)  
  {
  	 return M_NAND_READY;
  }

  status = NAND_cntlr_ReadStatus();
  timeout = 0x2000;
  while (((status & 0x40) == 0) && ( timeout != 0x00))
  {
	  timeout --;
	  status = NAND_cntlr_ReadStatus();
  }			


  if (status == M_NAND_READY)
  {
	  return M_NAND_READY;
  }
  else
  {
  	  if (status == M_NAND_STATUS_WARN)
  	  {
  	  	return M_NAND_STATUS_WARN;
      }
  	  return M_NAND_STATUS_ERROR;   
  }
	   
}

/******************************************************************************
* Function Name  : Nand_cntlr_Reset
* Description    : This routine reset the NAND FLASH
* Input          : None
* Output         : None
* Return         : NAND_READY
*******************************************************************************/
unsigned char Nand_cntlr_Reset(unsigned char *cmd)
{
   unsigned char ubStatus;
   /* Issue the Reset Command*/
   NAND_CMD = (unsigned char)0xFF;

   /* Wait for ready */
   ubStatus=NAND_cntlr_GetStatus();
   return ubStatus;
}

unsigned char M_FTL_NAND_erase(unsigned int blk)
{
		  mU32 addr,rtn;
	      
		  
		  addr = blk & (~gNand_Page_Mask_Bits);

		  NAND_CMD = (unsigned char)0x60;
		
		  NAND_ADR = (mU8)addr;
		  addr = addr >> M_SHIFT_8BIT;
		
		  NAND_ADR = (mU8)addr;
		  addr = addr >> M_SHIFT_8BIT;
		
		  NAND_ADR = (mU8)addr;
		
		  NAND_CMD = (unsigned char)0xD0;
		  
		  rtn = NAND_cntlr_GetStatus();
		  
		  
		  if (rtn & 0x01)
		  {
		      return M_FAIL;
          }
		  else
	      {
			  return M_PASS;
          }

}

// Read Nand page with physical address
mU8 m_internal_PA_Read(mU32 addr, mU16 pOffset, mU8 *pBuf, mU16 pLen, mU8 *oobBuf)
{
	mU32 i;
	unsigned char status,col0,col1;

	/* Page Read command and page address */
	NAND_CMD = (unsigned char)0x00;
	
	col1 = (unsigned char)(pOffset>>8);
	col0 = (unsigned char)pOffset;	
	
	NAND_ADR = col0;
	NAND_ADR = col1;
	
	NAND_ADR = ADDR_1st_CYCLE(addr);
	NAND_ADR = ADDR_2nd_CYCLE(addr);
	NAND_ADR = ADDR_3rd_CYCLE(addr);

	NAND_CMD = (unsigned char)0x30;

	/* Check status for successful operation */
	status = NAND_cntlr_GetStatus();
	
	
	/* turn it to read mode */
	NAND_CMD = (unsigned char)0x0;

	/* Read data */
	if (pBuf != 0)
	{		
		for(i=0; i < pLen; i++)
		{
			pBuf[i]= NAND_DAT;
		}
	}	
	
	if (oobBuf != 0)
	{
		
		col0 =	(unsigned char)M_FTL_SYSTEM_OOB0_4BYTE;
		col1 = 	(unsigned char)(M_FTL_SYSTEM_OOB0_4BYTE>>8);
		
		NAND_CMD = (unsigned char)0x05;
		NAND_ADR = col0;
		NAND_ADR = col1;
		NAND_CMD = (unsigned char)0xe0;
		
		/* Read data */		
		for (i=0; i<gFTL_OOB_size/2; i++)
		{
			oobBuf[i] = NAND_DAT;
		}
		
		col0 =	(unsigned char)M_FTL_SYSTEM_OOB1_4BYTE;
		col1 = 	(unsigned char)(M_FTL_SYSTEM_OOB1_4BYTE>>8);
		
		NAND_CMD = (unsigned char)0x05;
		NAND_ADR = col0;
		NAND_ADR = col1;
		NAND_CMD = (unsigned char)0xe0;
		
		/* Read data */
		for (i=gFTL_OOB_size/2; i<gFTL_OOB_size; i++)
		{
			oobBuf[i] = NAND_DAT;
		}
		
	}	
	
    if(status == M_NAND_STATUS_WARN)
	{
        return M_NAND_STATUS_WARN;
    }
    if(status == M_NAND_READY)
	{
        return M_PASS;
    }
    else
	{
        return M_FAIL;
    }
}




mU8 m_internal_PA_Write(mU32 addr, mU16 Offset, mU8 *pBuf, mU16 pLen, mU8 *oobBuf)
{
    mU32 i;
	mU8 col0, col1, status = M_NAND_READY;

	col1 = (unsigned char)(Offset>>8);
	col0 = (unsigned char)Offset;

    /* Page Write command and page address */
	
	NAND_CMD = (unsigned char)0x80;
	NAND_ADR = (mU8)col0;
	NAND_ADR = (mU8)col1;
	    
    NAND_ADR = (ADDR_1st_CYCLE(addr));  
    NAND_ADR = (ADDR_2nd_CYCLE(addr));    
    NAND_ADR = (ADDR_3rd_CYCLE(addr));
	

	if (pBuf != 0)
	{

			for(i=0; i < pLen; i++)
			{				
			  	NAND_DAT =  pBuf[i]; 
			  	  		
			}

	}


    if ( oobBuf != 0 )
    {
		
			col0 =	(unsigned char)M_FTL_SYSTEM_OOB0_4BYTE;
			col1 = 	(unsigned char)(M_FTL_SYSTEM_OOB0_4BYTE>>8);
			
			NAND_CMD = (unsigned char)0x85;
			NAND_ADR = col0;
			NAND_ADR = col1;
				
			for (i=0; i<gFTL_OOB_size/2; i++)
			{
					
				NAND_DAT = oobBuf[i];
				
			}
			
			col0 =	(unsigned char)M_FTL_SYSTEM_OOB1_4BYTE;
			col1 = 	(unsigned char)(M_FTL_SYSTEM_OOB1_4BYTE>>8);
			
			NAND_CMD = (unsigned char)0x85;
			NAND_ADR = col0;
			NAND_ADR = col1;
			
			for (i=gFTL_OOB_size/2; i<gFTL_OOB_size; i++)
			{
				
				NAND_DAT = oobBuf[i];
				
			}
			
			
    }
 

	NAND_CMD = (unsigned char)0x10;
	    /* Check status for successful operation */
    status = NAND_cntlr_GetStatus();

    if(status == M_NAND_READY)
  		{
        return M_PASS;
    }
	else
	{
        return M_FAIL;
    }
}



mU8 m_internal_PA_Write_Byte(mU32 addr, mU16 ppOffset, mU8 *pBuf, mU16 pLen, mU8 *oobBuf)
{
    mU32 index;
    mU8 col0, col1;
    
	MICRON_NAND_ECC_OFF();
	col1 = (unsigned char)(ppOffset>>8);
	col0 = (unsigned char)ppOffset;

    /* Page Write command and page address */
	NAND_CMD = (unsigned char)0x80;
	
	NAND_ADR = (unsigned char)col0;	
	NAND_ADR = (unsigned char)col1;
	   
    NAND_ADR = ((ADDR_1st_CYCLE(addr)));    
    NAND_ADR = ((ADDR_2nd_CYCLE(addr)));    
    NAND_ADR = ((ADDR_3rd_CYCLE(addr)));
  

	if ( pBuf != 0 )
	{

			for(index=0; index < pLen; index++)
		
			{
			  	
			  	NAND_DAT = pBuf[index];
			
			}

	}

	NAND_CMD = (unsigned char)0x10;

	    /* Check status for successful operation */
    NAND_cntlr_GetStatus();
	MICRON_NAND_ECC_ON();
  	return M_PASS;

}


/* utility functions for speed access */

 /*
     Read ID command
*/
void NAND_cntlr_ReadID(unsigned char *cmd, unsigned char *idBytes)
{
	

  /* Send Command to the command area */
  NAND_CMD = cmd[0];
  NAND_ADR = cmd[1];

   /* Sequence to read ID from NAND flash */

   idBytes[0]   = NAND_DAT;
   idBytes[1]   = NAND_DAT;
   
   idBytes[2]   = NAND_DAT;
   idBytes[3]   = NAND_DAT;
   

}

/******END OF FILE****/
