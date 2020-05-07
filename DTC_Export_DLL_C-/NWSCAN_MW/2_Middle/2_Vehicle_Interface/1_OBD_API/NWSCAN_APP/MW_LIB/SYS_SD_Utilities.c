/*
 * SYS_SD_Utilities.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Lap Dang
 */
#include "NWSCAN_APP\LIB\PlatFormType.h"
#include <NWSCAN_APP\LIB\SYS_Utility.h>
//#include <NWSCAN_APP\Adapter\Common\NwS_Config.h>
//#include "NWSCAN_APP\Common\SystemData.h"
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include "SYS_SD_Utilities.h"

__FileResult gf_SYS_Util_ReadFile(structFileBinHandle *pstrtFileBinHandle,
		uint32 iAddr, uint8 *pData, uint32 iSize)
{
	uint32 iRead;
	if (FILE_BIN_Seek(pstrtFileBinHandle->fp, (iAddr+OFFSET_VERSION_PATERN)) != fresult_OK)
	{
		return FR_DISK_ERR;
	}

	if (FILE_BIN_Read(pstrtFileBinHandle->fp, pData, iSize,
			&iRead) != fresult_OK)
	{
		return FR_DISK_ERR;
	}
	return fresult_OK;
}

uint32 gf_SYS_GetFirstKey(uint32 iRootAddress, uint32 iNumberLine,

uint8 * pKey, uint8 bSizeKey,

uint8 * pRam, /*Size must be = iBase*3*/
uint32 iBase, structFileBinHandle *pstrtFileBinHandle)
{
	//uint32 iTemp;
	sint32 iSearch;
	uint32 lowBound, highBound;
	lowBound = 0;
	if (iNumberLine == 0)
		return _BST_NOT_FOUND_KEY_;
	highBound = iNumberLine - 1;
	int mid;
	while (lowBound <= highBound)
	{

		mid = (lowBound + highBound) / 2;

		if (gf_SYS_Util_ReadFile(pstrtFileBinHandle,
				(mid * iBase) + iRootAddress, pRam, bSizeKey) != fresult_OK)
		{
			return _BST_NOT_FOUND_KEY_;
		}

		iSearch = memcmp(pKey, pRam, bSizeKey);
		if (iSearch > 0) //the element we search is located to the right from the mid point
		{
			lowBound = mid + 1;
			continue;
		}
		else if (iSearch < 0) //the element we search is located to the left from the mid point
		{
			if (mid == 0)
				break;
			highBound = mid - 1;
			continue;
		}
		//at this point low and high bound are equal and we have found the element or
		//arr[mid] is just equal to the value => we have found the searched element
		else
		{
			//find first key
			if (mid > 0)
			{
				while (eTRUE)
				{
					if (gf_SYS_Util_ReadFile(pstrtFileBinHandle,
							(mid * iBase) + iRootAddress, pRam,
							bSizeKey)!=fresult_OK)
						break;
					if (memcmp(pKey, pRam, bSizeKey) != 0)
					{
						mid++;
						break;
					}
					if (mid == 0)
						break;
					mid--;
				}
			}
			return (mid * iBase) + iRootAddress;
		}

	}
	return _BST_NOT_FOUND_KEY_;        //value not found
}

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_SYS_CatchBinaryFile
 *Input        :
 uint32 iRootAddress, uint32 iNumberLine,
 uint8 * pKey, uint8 bSizeKey,
 uint8 * pRam, //Size must be = iBase*3
 uint32 iBaseSize, //Key size  + Value Size
 structFileBinHandle *pstrtFileBinHandle
 {
 void *  path;//absolute path file
 uint8   mode;//FA_OPEN_EXISTING| FA_READ
 void    *fp;//assign FIL fhandle

 pf_FileBinOpen      pf_Open;//assign FRESULT f_open (

 pf_FileBinSeek      pf_Seek;//assign FRESULT f_lseek (
 pf_FileBinRead      pf_Read;//assign FRESULT f_read(
 pf_FileBinClose     pf_Close;//assign FRESULT f_close(
 }
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Sep 9, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint8* gf_SYS_CatchBinaryFile(uint32 iRootAddress, uint32 iNumberLine,
		uint8 * pKey, uint8 bSizeKey, uint8 * pRam, /*Size must be = iBase*3*/
		uint32 iBaseSize, //Key size  + Value Size
		structFileBinHandle *pstrtFileBinHandle)
{
	uint8 *pValue = null;
	uint32 iAddr= _BST_NOT_FOUND_KEY_;

#ifndef  _MSC_VER
	//check error
	if (pstrtFileBinHandle == null)
		return null;
	if (FILE_BIN_Open == null)
		return null;
	if (FILE_BIN_Close == null)
		return null;
	if (pstrtFileBinHandle->pf_Seek == null)
		return null;
	if (pstrtFileBinHandle->pf_Read == null)
		return null;
	if (pstrtFileBinHandle->fp == null)
		return null;
#endif
	//end error checking
	if (FILE_BIN_Open(pstrtFileBinHandle->fp,
			pstrtFileBinHandle->path, pstrtFileBinHandle->mode) != fresult_OK)
		return null;

	iAddr = gf_SYS_GetFirstKey(iRootAddress, iNumberLine, pKey, bSizeKey, pRam,
			iBaseSize, pstrtFileBinHandle);

	if (iAddr != _BST_NOT_FOUND_KEY_)
	{
		if (gf_SYS_Util_ReadFile(pstrtFileBinHandle, (iAddr + bSizeKey), pRam,
				iBaseSize - bSizeKey) == fresult_OK)
		{
			pValue = pRam;
		}
	}

	FILE_BIN_Close(pstrtFileBinHandle->fp);

	return pValue;
}

