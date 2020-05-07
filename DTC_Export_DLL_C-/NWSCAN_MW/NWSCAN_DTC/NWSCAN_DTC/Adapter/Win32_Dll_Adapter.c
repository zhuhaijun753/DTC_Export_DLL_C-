#include "NWSCAN_APP\LIB\PlatFormType.h"
//#include <NWSCAN_APP\Adapter\Common\NwS_Config.h>
#include <NWSCAN_APP\MW_LIB\SYS_SD_Utilities.h>
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\enums.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMMESelection.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMME_Structure.h>
#include <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Structure.h>
#include "NWSCAN_APP\LIB\SYS_Utility.h"
#include <2_Middle\0_Middle_Utilities\AES\aes256.h>
structMFRVinProfile * VehicleData_YMMEProfile(uint16 sYear, uint16 sManufacture);
structMFRVinProfile * VehicleData_YMMEProfile_Get(void);
static FILE * g_fhandle;
structVehicleDataBuffer  strtVehicleDataBuffer;
structFileBinHandle strtFileBinHandle =
{
#ifdef _MSC_VER
	.path = null,
	.mode = "r",
	.fp = &g_fhandle,
	//TODO : initialize for this struct utility read file
#else
.path = null,
.mode = FA_OPEN_EXISTING | FA_READ,
.fp = &g_fhandle,
.pf_Open = (pf_FileBinOpen)f_open,
.pf_Seek = (pf_FileBinSeek)f_lseek,
.pf_Read = (pf_FileBinRead)f_read,
.pf_Close = (pf_FileBinClose)f_close
#endif
};

structMFRVinProfile * VehicleData_YMMEProfile(uint16 sYear, uint16 sManufacture)
{
	strtVehicleDataBuffer.strtVehData_YMMEProfile.eYear = sYear;
	strtVehicleDataBuffer.strtVehData_YMMEProfile.eManufacturer = sManufacture;
	strtVehicleDataBuffer.strtVehData_YMMEProfile.ValidStatus = VALID_CODE;
	//TODO : need to implement this function
	return &strtVehicleDataBuffer.strtVehData_YMMEProfile;
}
structMFRVinProfile * VehicleData_YMMEProfile_Get()
{
	if (strtVehicleDataBuffer.strtVehData_YMMEProfile.ValidStatus == VALID_CODE)
		return &strtVehicleDataBuffer.strtVehData_YMMEProfile;
	else
		return null;
}


void gf_Util_ShiftLeftBuff(uint8 *p_bDataBuff, uint16 bSize, uint8 bNumOffSet)
{
	uint16 bIdx = 0;
	if (bNumOffSet>0)
	{
		for (bIdx = 0; bIdx<(bSize - bNumOffSet); bIdx++)
		{
			p_bDataBuff[bIdx] = p_bDataBuff[bIdx + bNumOffSet];
		}
	}
}

__FileResult WinFileClose(void *fp     /* Pointer to the file object to be closed */)
{
	fclose(fp);
	return fresult_OK;
}
__FileResult WinFileOpen(void *fp,            /* Pointer to the blank file object */
	const TCHAR *path,						  /* Pointer to the file name */
	char* mode								 /* Access mode and file open mode flags */)
{
	structFileBinHandle *pstrtFileBinHandle = &strtFileBinHandle;
	fp = fopen(path,mode);
	if (fp == NULL)
		return fresult_Error;
	pstrtFileBinHandle->fp = fp;
	return fresult_OK;
}
__FileResult WinFileSeek(void *fp,        /* Pointer to the file object */
	                     uint32 ofs		  /* File pointer from top of file */)
{
	uint8 eSeek;
	eSeek = fseek(fp, ofs, 0);
	if (eSeek!=0)
		return fresult_Error;
	return fresult_OK;
}
__FileResult WinFileRead(void *fp,        /* Pointer to the file object */
	void *buff,     /* Pointer to data buffer */
	uint32 btr,       /* Number of bytes to read */
	uint32 *br        /* Pointer to number of bytes read */)
{
	uint8 bCheck = 0;
	bCheck = fread(buff, btr, 1, fp);
	if (bCheck==0)
		return fresult_Error;
	return fresult_OK;
}
/*int VDS_aes_decrypt(enumKeyType eKeyType, unsigned char* input, unsigned char* output, int length)
{
	return 0;
}*/

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:
*Input        :structOemProfile * p_strtOemProfile,
enumBufferName * pBuffName,
uint8 bDtcNo,
structDtcParser * p_strtDtcParser
*Output       :
string of display dtc
pBuffName buffer name of dtc

*Description  :
*
*
*Historical   :
*     1. Creation Lap Dang Sep 13, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void *gf_VDM_DTC_GetDtcStringFromOemProfile(structOemProfile * p_strtOemProfile,
	enumBufferName * pBuffName, uint8 bDtcNo,
	structDtcParser * p_strtDtcParser)
{
	if (p_strtDtcParser == null)
		return null;
	if (bDtcNo < p_strtOemProfile->strtOEMDTCBuffer.NumberDTC)
	{
		p_strtDtcParser->bFrameDtc =
			p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc;
		p_strtDtcParser->eDTCType =
			p_strtOemProfile->strtOEMDTCBuffer.DtcDispType;
		p_strtDtcParser->pDtc = p_strtOemProfile->strtOEMDTCBuffer.DTC;
		p_strtDtcParser->pDtc += bDtcNo
			* (p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc + 1);
		ParserDtc(p_strtDtcParser);
		if (pBuffName != Null)
		{
			*pBuffName =
				(enumBufferName)p_strtDtcParser->pDtc[p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc];
		}
		return p_strtDtcParser->arrDtcOutPut;
	}
	return Null;
}
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_GetRawFromOemProfile
*Input        : structOemProfile * p_strtOemProfile
*Output       : out put frame dtc pFmtDtc
*Description  :
*get status dtc by data of index (*pFmtDtc)+1
*
*
*Historical   :
*     1. Creation Lap Dang Sep 13, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void* gf_VDM_DTC_GetRawFromOemProfile(structOemProfile * p_strtOemProfile,
	uint8 * pFmtDtc, uint8 bDtcNo)
{
	uint8 * pTempDtc = Null;
	if (pFmtDtc != Null)
	{
		*pFmtDtc = 0;
	}
	if (bDtcNo < p_strtOemProfile->strtOEMDTCBuffer.NumberDTC)
	{
		pTempDtc = p_strtOemProfile->strtOEMDTCBuffer.DTC;
		pTempDtc += bDtcNo
			* (p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc + 1);
		if (pFmtDtc != Null)
		{
			*pFmtDtc = p_strtOemProfile->strtOEMDTCBuffer.bFormatDtc;
		}
		return pTempDtc;
	}
	return Null;
}