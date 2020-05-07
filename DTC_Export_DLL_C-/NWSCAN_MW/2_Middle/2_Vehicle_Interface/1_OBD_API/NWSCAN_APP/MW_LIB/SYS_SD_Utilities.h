/*
 * SYS_SD_Utilities.h
 *
 *  Created on: Sep 19, 2015
 *      Author: Lap Dang
 */

#ifndef SYS_SD_UTILITIES_H_
#define SYS_SD_UTILITIES_H_

typedef enum _enumNWSFileID
{
	eFILE_NWSCAN_MSGID_BIN=1,
	eFILE_NWSCAN_PCMD_BIN,
	eFILE_NWSCAN_PPCMD_BIN,
	eFILE_NWSCAN_PPREADDTC_BIN,
	eFILE_NWSCAN_PROFILE_BIN,
	eFILE_TIMING,
	eFILE_DTC_STATUS,

	eFILE_BMW_DB_VAR,
	eFILE_BMW_DTC_VAR,
	eFILE_BMW_MSG_MAPPING,
	eFILE_BMW_PROTOCOL_VAR,
	eFILE_FORD_PARTNUMBER,
	eFILE_FORD_SECURITY_DB,
	eFILE_HONDAECUIDPARSER,
	eFILE_HONDAECUMAPPiNG,
	eFILE_HONDAECUPARTNUMBER,
	eFILE_HONDAKWDTCMAPPING,
	eFILE_HONDAKWSYSTEMMAPPING,
	eFILE_HONDAOTHERSECUID,
	eFILE_HONDAPCMPARSERDTC,
	eFILE_MERCEDES_BM_MAPPING,
	eFILE_MERCEDES_ME97_SECURITY,
	eFILE_MERCEDES_VAR,
	eFILE_NISSAN_PARTNUMBER,
	eFILE_VAG_DEFAULT_PARTNUMBER,
	eFILE_VAG_GW_MAPPING,
	eFILE_VAG_PARTNUMBER,
	eFILE_VOLVO_ECUID,
	eFILE_NWSCAN_LOOKUPTABLE_BIN,
}enumNWSFileID;


#pragma pack(1)

#if (USE_DB_INTERNAL_FLASH == 1)
#define OFFSET_VERSION_PATERN	16
#else
#define OFFSET_VERSION_PATERN	16
#endif

#define _BST_NOT_FOUND_KEY_ 0xFFFFFFFF

#ifdef _MSC_VER
#define fresult_OK		0
#define fresult_Error		1
#define __FileResult	uint8

typedef struct _structFileBinHandle
{
	void * path; //absolute path file
	char* mode;//FA_OPEN_EXISTING| FA_READ
	void* fp;//assign FIL fhandle
	//pf_FileBinOpen      pf_Open;
	//pf_FileBinSeek      pf_Seek;

}structFileBinHandle;
#define FILE_BIN_Close(a)				WinFileClose(a)
#define FILE_BIN_Open(fp,path,mode)		WinFileOpen(fp,path,mode)

#define FILE_BIN_Seek(fp,ofs)				WinFileSeek(fp,ofs)
#define FILE_BIN_Read(fp,buff,btr,br)		WinFileRead(fp,buff,btr,br)

#else
#ifndef fresult_OK
#define fresult_OK  FR_OK
#endif
typedef FRESULT __FileResult;

#ifndef __USE_SD_ROM_CODE
#define __USE_SD_ROM_CODE 0
#endif
typedef __FileResult (*pf_FileBinOpen)(void *fp, /* Pointer to the blank file object */
const TCHAR *path, /* Pointer to the file name */
uint8 mode /* Access mode and file open mode flags */
);
typedef __FileResult (*pf_FileBinSeek)(

void *fp, /* Pointer to the file object */
uint32 ofs /* File pointer from top of file */
);

typedef __FileResult (*pf_FileBinRead)(void *fp, /* Pointer to the file object */
void *buff, /* Pointer to data buffer */
uint32 btr, /* Number of bytes to read */
uint32 *br /* Pointer to number of bytes read */
);
typedef __FileResult (*pf_FileBinClose)(void *fp /* Pointer to the file object to be closed */
);

//((FRESULT (*) (structFFSManager *p_strtFFSManager, FIL*, const TCHAR*, BYTE))

typedef struct _structFileBinHandle
{
	void * path;	//absolute path file
	uint8 mode;	//FA_OPEN_EXISTING| FA_READ
	void *fp;	//assign FIL fhandle
	pf_FileBinOpen pf_Open;
	pf_FileBinSeek pf_Seek;
	pf_FileBinRead pf_Read;
	pf_FileBinClose pf_Close;
} structFileBinHandle;
#pragma pack()
#endif

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
		uint8 * pKey, uint8 bSizeKey, uint8 * pRam, /*Size must be = iBaseSize*/
		uint32 iBaseSize, //Key size  + Value Size
		structFileBinHandle *pstrtFileBinHandle);

__FileResult gf_SYS_Util_ReadFile(structFileBinHandle *pstrtFileBinHandle,
		uint32 iAddr, uint8 *pData, uint32 iSize);

uint32 gf_SYS_GetFirstKey(uint32 iRootAddress, uint32 iNumberLine,

uint8 * pKey, uint8 bSizeKey,

uint8 * pRam, /*Size must be = iBase*3*/
uint32 iBase, structFileBinHandle *pstrtFileBinHandle);
//#define OFFSET_VERSION_PATERN	16

#pragma pack(1)
typedef struct _structNwSHeader
{
	uint32 iNumberLine;
	uint8 bBaseSize;
	uint8 bKeySize;
#ifdef  _MSC_VER
	uint8 eEnEncrypt;
#else
	enumbool eEnEncrypt;
#endif
	uint8 bReserve[9];
} structNwSHeader;
#pragma pack()

#ifndef SYS_FILE_UTILITIES_C_
extern structFileBinHandle strtFileBinHandle;
#endif
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_NWScanPathFileSetSize(void*bPath,uint32 iSizeFile)
 *Input        :
 *Output       :
 *Description  :
 *set size of file correspond with present path
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  2:40:59 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NWScanPathFileSetSize(void*bPath,uint32 iSizeFile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumbool gf_VDM_IsVehicleDependOnYear(void)
 *Input        :
 *Output       :
 *Description  :
 *Check vehicle is depend on year or not
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  10:36:32 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_IsVehicleDependOnYear(void);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_NwscanSetData(enumNWSFileID pFile,uint8*pData);
 *Input        :
 *Output       :
 *Description  :
 *Check vehicle is depend on year or not
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  10:36:32 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_NwscanSetData(enumNWSFileID pFile,uint8*pData,uint32 iSize);


#endif /* SYS_SD_UTILITIES_H_ */
