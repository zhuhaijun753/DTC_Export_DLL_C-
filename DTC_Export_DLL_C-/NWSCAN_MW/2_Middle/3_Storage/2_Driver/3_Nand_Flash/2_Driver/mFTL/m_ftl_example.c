/*
*  m_ftl_example.c
*  File description:  This file includes an example program to use FTL APIs
*  
*  Copyright Micron Technology 2011 *
*/

#include <string.h>
#include <stdio.h>

#define M_PASS 1
#define M_FAIL 0

#define LEN_BUFFER	512
void m_test(void);
extern unsigned char M_NAND_Page_Read(unsigned short Block_idx, unsigned char Page_idx, unsigned short Page_Offset, unsigned char *pBuffer, unsigned short Buffer_Len);
extern unsigned char M_NAND_Page_Write(unsigned short Block_idx, unsigned char Page_idx, unsigned short Page_Offset, unsigned char *pBuffer, unsigned short Buffer_Len);
extern unsigned char M_NAND_Format(void);
extern unsigned char M_NAND_Init(void);

extern char	String_Temp[100];

unsigned char Page_In[LEN_BUFFER], Page_Out[LEN_BUFFER];
unsigned int test_pin[16];



void m_test(void)
{
	unsigned short i;
	unsigned short Index_Block, Index_Page, Offset_Page, Index_Byte;
	unsigned char Out_Read, Out_Write, Out_Mem, Out_Init, Out_Format, Out_Get;
	unsigned short Max_Num_Blocks;
   
	/***************************
		To initialize Nand device 
		--Reset the Nand chip
		--Unlock all blocks
		--Turn on ECC
	****************************/	
	Out_Init = M_NAND_Init();
	if(Out_Init != M_PASS)
	{
		return;
	}
 


	Index_Block = 0;
	Index_Page = 0;
	Offset_Page = 0;
	Max_Num_Blocks = 1920;
	i = 0;
	while(i < 1)
	{
		i++;
		for(Index_Block = 0; Index_Block < Max_Num_Blocks; Index_Block++)
		{
			for(Index_Page = 0; Index_Page < 4; Index_Page++)
			{
				Out_Format = 0;

					for(Offset_Page = 0; Offset_Page < 2040; Offset_Page += LEN_BUFFER)
					{
						Out_Format++;
						for(Index_Byte = 0; Index_Byte < LEN_BUFFER; Index_Byte++)
						{
							Page_In[Index_Byte] = 0xa1;
							Page_Out[Index_Byte] = 0;
						} 
		
					//	Out_Write = M_NAND_Page_Write(Index_Block, Index_Page, Offset_Page, Page_In, LEN_BUFFER);
					//	if(Out_Write != M_PASS)
					//	{
					//		while(1);

					//	}
		
					}
				
					
					Out_Read = M_NAND_Page_Read(Index_Block, Index_Page, 1536, Page_Out, LEN_BUFFER);

					if(Out_Read != M_PASS)
					{
						while(1)
                        {
                            ;
                        }

					}
				
					Out_Mem = memcmp(Page_In, Page_Out, LEN_BUFFER);

					if(Out_Mem == 0)
					{
						
					}else
					{
						while(1)
                        {
                            ;
                        }

					}
                                        
					Out_Read = M_NAND_Page_Read(Index_Block, Index_Page, 0, Page_Out, LEN_BUFFER);

					if(Out_Read != M_PASS)
					{
						while(1)
                        {
                            ;
                        }

					}
				
					Out_Mem = memcmp(Page_In, Page_Out, LEN_BUFFER);

					if(Out_Mem == 0)
					{
						
					}else
					{
						while(1)
                        {
                            ;
                        }

					}
				
			}
		}
	}

        while(1)
        {
            ;
        }
	//return;
}
/****END OF FILE****/
