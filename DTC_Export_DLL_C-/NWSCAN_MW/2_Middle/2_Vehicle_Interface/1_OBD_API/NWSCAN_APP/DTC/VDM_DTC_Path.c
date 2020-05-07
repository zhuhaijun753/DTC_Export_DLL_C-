/*
* VDM_NWScan_Path.c
*
*  Created on: Jul 31, 2015
*      Author: Lap Dang
*/

#include "NWSCAN_APP\LIB\PlatFormType.h"
#include "NWSCAN_APP\DTC\DTC_Config.h"
#include "NWSCAN_APP\LIB\SYS_Utility.h"
#include "NWSCAN_APP\LIB\VDM_Adapter.h"
#include "NWSCAN_APP\MW_LIB\Makes_Adapter_App.h"
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#ifdef _MSC_VER
#include <Windows.h>
#include <io.h>
#endif
#define MAX_NUM_VERSION_FOLDER	20
#define MAX_LEN_OF_VERSION      50
#define MAX_LEN_PATH_TEMP_RAM	255

static uint8 listPath[MAX_NUM_VERSION_FOLDER][MAX_LEN_OF_VERSION];
static uint8 bIdxPathVersion = 0;

void gf_VDM_DTCPathSetIdx(uint8 bIdx)
{
  bIdxPathVersion = bIdx;
}

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: char* gf_VDM_NwscanPathGet(uint8*pFunction,uint8* pFile,uint16 sYear)
*Input        : if sYear = 0 , skip level folder year
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang  8:59:16 AM
*
*
*
*
-------------------------------------------------------------------------------*/
char* gf_VDM_DTCPathGet(uint8*pFunction, uint8* pFile, uint8 isUsedYear)
{
  static char strTempRAM[MAX_LEN_PATH_TEMP_RAM];
  
  structMFRVinProfile *pstrtMFRVinProfile = VehicleData_YMMEProfile_Get();
  /*/Lap modify for test
  FILE *Edit_File;
  structMFRVinProfile *pstrtMFRVinProfile;
  structMFRVinProfile strtMFRVinProfile;
  pstrtMFRVinProfile = &strtMFRVinProfile;
  Edit_File = fopen("dataYMME.bin", "r");
  if (Edit_File == NULL)
  {
  pstrtMFRVinProfile = null;
}
	else
  {
  fread((char*)&strtMFRVinProfile, sizeof(structMFRVinProfile), 1, Edit_File);
}
  fclose(Edit_File);
  /*/
  if (pstrtMFRVinProfile == null)
    return null;
  if (pstrtMFRVinProfile->ValidStatus != VALID_CODE)
    return null;
  char*pVersionFolder=null;
  if(bIdxPathVersion<MAX_NUM_VERSION_FOLDER)
    pVersionFolder = listPath[bIdxPathVersion];
  /*
  * struct folder path
  * [MAKE]
  *        Function
  *        			Year
  * */
  if ((isUsedYear != 0) && (pstrtMFRVinProfile->eYear < eyear_Others))
  {
    sprintf(strTempRAM, "%s/%s/%d/%d/%s", pFunction, pVersionFolder,
            pstrtMFRVinProfile->eManufacturer, pstrtMFRVinProfile->eYear,
            pFile);
  }
  else
  {
    if ((pstrtMFRVinProfile->eManufacturer==emanufacturer_Opel)||
        (pstrtMFRVinProfile->eManufacturer==emanufacturer_Daewoo))
    {
      sprintf(strTempRAM, "%s/%s/%d/%s", pFunction, pVersionFolder,   //Opel use database of GM
              emanufacturer_GM, pFile);
    }
    else
    {
      sprintf(strTempRAM, "%s/%s/%d/%s", pFunction, pVersionFolder,
              pstrtMFRVinProfile->eManufacturer, pFile);
    }
  }
  
  return strTempRAM;
}

uint8 gf_VDM_DTCPathGetListVersion(char*RootFolder)
{
#ifdef _MSC_VER
  struct _finddata_t ListFolder;
  char originalDirectory[_MAX_PATH];
  _getcwd(originalDirectory, _MAX_PATH);
  _chdir(RootFolder);
  uint8 bIdxPath = 0;
  char *pNWSCANRoot = RootFolder;
  if (pNWSCANRoot == null)
    return 0;
  intptr_t handle = _findfirst("*", &ListFolder);
  if (handle == -1)  // No files or directories found
  {
    perror("Error searching for file");
    exit(1);
  }
  do
  {
    if (strcmp(ListFolder.name, ".") == 0 || strcmp(ListFolder.name, "..") == 0)
      continue;
    if (ListFolder.attrib & _A_SUBDIR) // Use bitmask to see if this is a directory
    {
      sprintf(listPath[bIdxPath], "%s", ListFolder.name);
      bIdxPath++;
      if (bIdxPath > MAX_NUM_VERSION_FOLDER)
        break;
    }
  } while (_findnext(handle, &ListFolder) == 0);
  
  _findclose(handle); // Close the stream
  _chdir(originalDirectory);
  //TODO SCAN FOLDER
  return bIdxPath;
  
#else
  FRESULT res;
  FILINFO fno;
  DIR dir;
  uint8 bIdxPath = 0;
  //uint8*pListVersion[10];
  char lfn[_MAX_LFN + 1];
  fno.lfname = lfn;
  fno.lfsize = sizeof(lfn);
  char *fn; /* This function assumes non-Unicode configuration */
  char *pNWSCANRoot = RootFolder;
  if (pNWSCANRoot == null)
    return 0;
  res = f_opendir(&dir, pNWSCANRoot); /* Open the directory */
  if (res == FR_OK)
  {
    //int i = strlen(pNWSCANRoot);
    for (;;)
    {
      res = f_readdir(&dir, &fno); /* Read a directory item */
      if (res != FR_OK || fno.fname[0] == 0)
        break; /* Break on error or end of dir */
      if (fno.fname[0] == '.')
        continue; /* Ignore dot entry */
#if _USE_LFN
      fn = *fno.lfname ? fno.lfname : fno.fname;
#else
      fn = fno.fname;
#endif
      if (fno.fattrib & AM_DIR)
      { /* It is a directory */
        if (strlen(fn) > MAX_LEN_OF_VERSION)
          break;
        sprintf(listPath[bIdxPath], "%s", fn);
        bIdxPath++;
        if (bIdxPath >= MAX_NUM_VERSION_FOLDER)
          break;
      }
    }
    
  }
  return bIdxPath;
#endif
}
static enumManufacturer ListVehicleSkipYear[] = { emanufacturer_HONDA,emanufacturer_MERCEDES_BENZ,emanufacturer_UNKNOWN };
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
/*enumbool gf_VDM_IsVehicleDependOnYear(void)
{
structMFRVinProfile *pstrtMFRVinProfile = VehicleData_YMMEProfile_Get();
uint16 sVehIdx = 0;
while (ListVehicleSkipYear[sVehIdx] != emanufacturer_UNKNOWN)
{
if (ListVehicleSkipYear[sVehIdx] == pstrtMFRVinProfile->eManufacturer)
return eFALSE;
sVehIdx++;
	}
return eTRUE;
}*/

