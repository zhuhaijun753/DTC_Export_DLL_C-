 /*******************************************************************************
*Engineer:      TranLuu
*Date:          Aug 18 2014
*Filename:      DLCLocator.c
*Description:
*******************************************************************************/

/*############################################################################*/
#define ___DLC_LOCATOR_C__
/*
================================================================================
INCLUDED FILES
================================================================================
*/
#include "DLCLocator.h"
#include "DLCLocatorEnumeration.h"
/*
================================================================================
GLOBAL VARIABLES
================================================================================
*/
//extern int aes_decrypt_double_wKey(unsigned char* key, unsigned char* input, unsigned char* output, int length );
/*
================================================================================
CONSTANTS
================================================================================
*/
#define YEAR_ENUM_LENGTH                2
#define MAKE_ENUM_LENGTH                2
#define MODEL_ENUM_LENGTH               2
#define ENGINE_ENUM_LENGTH              2
#define YEAR_STRING_LENGTH              5

#define DLC_LOCATOR_PATH                "/DLCLocator/dlclocatorymme.bin"

#define HEADER_ACCESS_ENG_PATH          "/DLCLocator/dataaccessheader_eng.bin"
#define HEADER_ACCESS_FRE_PATH          "/DLCLocator/dataaccessheader_fre.bin"
#define HEADER_ACCESS_SPA_PATH          "/DLCLocator/dataaccessheader_spa.bin"
#define HEADER_ACCESS_CHI_PATH          "/DLCLocator/dataaccessheader_chi.bin"
#define HEADER_ACCESS_JAP_PATH          "/DLCLocator/dataaccessheader_jap.bin"
#define HEADER_ACCESS_VIE_PATH          "/DLCLocator/dataaccessheader_vie.bin"

#define LIST_ACCESS_ENG_PATH            "/DLCLocator/dataaccess_eng.bin"
#define LIST_ACCESS_FRE_PATH            "/DLCLocator/dataaccess_fre.bin"
#define LIST_ACCESS_SPA_PATH            "/DLCLocator/dataaccess_spa.bin"
#define LIST_ACCESS_CHI_PATH            "/DLCLocator/dataaccess_chi.bin"
#define LIST_ACCESS_JAP_PATH            "/DLCLocator/dataaccess_jap.bin"
#define LIST_ACCESS_VIE_PATH            "/DLCLocator/dataaccess_vie.bin"

#define HEADER_COMMENT_ENG_PATH         "/DLCLocator/datacommentheader_eng.bin"
#define HEADER_COMMENT_FRE_PATH         "/DLCLocator/datacommentheader_fre.bin"
#define HEADER_COMMENT_SPA_PATH         "/DLCLocator/datacommentheader_spa.bin"
#define HEADER_COMMENT_CHI_PATH         "/DLCLocator/datacommentheader_chi.bin"
#define HEADER_COMMENT_JAP_PATH         "/DLCLocator/datacommentheader_jap.bin"
#define HEADER_COMMENT_VIE_PATH         "/DLCLocator/datacommentheader_vie.bin"

#define LIST_COMMENT_ENG_PATH           "/DLCLocator/datacomment_eng.bin"
#define LIST_COMMENT_FRE_PATH           "/DLCLocator/datacomment_fre.bin"
#define LIST_COMMENT_SPA_PATH           "/DLCLocator/datacomment_spa.bin"
#define LIST_COMMENT_CHI_PATH           "/DLCLocator/datacomment_chi.bin"
#define LIST_COMMENT_JAP_PATH           "/DLCLocator/datacomment_jap.bin"
#define LIST_COMMENT_VIE_PATH           "/DLCLocator/datacomment_vie.bin"

#define HEADER_ACCESS_STRING_SIZE       7
#define HEADER_COMMENT_STRING_SIZE      8
#define ACCESS_ID_SIZE                  1
#define COMMENT_ID_SIZE                  2

#define NUMBER_OF_LANG			7
#define SIZE_OF_ADDRESS_TABLE_SIZE	2
#define HEADER_FILE_SIZE                16// 4 byte numbers Item and 12 byte reserved


/*
================================================================================
PROTOTYPES
================================================================================
*/

/*
================================================================================
FUNCTION BODY
================================================================================
*/
/*------------------------------------------------------------------------------
*Engineer:    TranLuu      
*Historical:    1.Jan 09 2014
		2.
*Function name:     CompareFunction
*Description:       
*Input:             
*Output:            
------------------------------------------------------------------------------*/
static sint8 CompareFunction(uint8* p_Key, uint8* p_FoundItem, uint8* p_Idx_array, uint8 bCompare_size)
{
  sint8 bResult = 0;/*p_Item1 = p_Item2*/
  uint32 iIdx = 0;
  
  for (iIdx = 0; iIdx < bCompare_size; iIdx++)
  {
    if(p_Key[p_Idx_array[iIdx]] > p_FoundItem[p_Idx_array[iIdx]])
    {
      return bResult = 1;
    }
    else if(p_Key[p_Idx_array[iIdx]] < p_FoundItem[p_Idx_array[iIdx]])
    {
      return bResult = -1;
    }      
  }
  return bResult;
}
/*------------------------------------------------------------------------------
*Engineer:    TranLuu      
*Historical:    1.Aug 18 2014
		2.
*Function name:     BinarySearch
*Description:       
*Input:             
*Output:            
------------------------------------------------------------------------------*/
static enumbool BinarySearch(FIL*                         fhandle, 
                             void*                        p_Key, 
                             void*                        p_FoundItem,
                             uint16                       sFoundItemSize,
                             uint16                       sKeySize,
                             uint32                       StartAddr,     //Start Address of Item in List
                             uint16                       NumItem)
{
  uint8 Idx_array[] = {1, 0, 2, 4, 3, 6, 5, 8, 7, 10, 9}; 
  enumbool ebResult = eFALSE;
  sint32 iCmpbResult = 0;
  uint32 iRead = 0;
  sint16 sMid = 0;
  sint16 sLow = 0;
  sint16 sHigh = 0;
  
  sLow = 0; 
  sHigh = NumItem -1; /*low begin with 1*/
 
  while(sLow <= sHigh)
  {
     sMid = (sLow + sHigh)/2;
     f_lseek(fhandle, sMid*sFoundItemSize + StartAddr); 
     f_read(fhandle, p_FoundItem, sFoundItemSize, &iRead);     
     iCmpbResult = CompareFunction(p_Key, p_FoundItem, Idx_array, sKeySize);
     if(iCmpbResult == 0)
     {
       ebResult = eTRUE;
       break;
     }
     else if(iCmpbResult > 0) /* p_Key > p_FoundItem */
     {
       sLow = sMid + 1;
     }
     else if(iCmpbResult < 0) /*  p_Key < p_FoundItem */
     {
       sHigh = sMid - 1;
     }
        
  }
return ebResult;     
}


/*------------------------------------------------------------------------------
*Engineer:          TranLuu
*Historical:        1.Aug 18 2014
2.
*Function name:     SearchYMME
*Description:       SearchYMME
*Input:
*Output:
------------------------------------------------------------------------------*/
static enumbool SearchYMME(structDLCLocator* p_strtDLCLocator,
                           structYMME_DLCLocator* p_strtYMME)
{
    FRESULT res;
    FIL fhandle;
    uint32 iRead = 0;
    enumbool ebResult = eFALSE;
    uint32 iNumItem = 0;
    
    memset(p_strtDLCLocator, 0, sizeof(structDLCLocator));
           
    res = f_open(&fhandle, DLC_LOCATOR_PATH, FA_OPEN_EXISTING| FA_READ);
    
    if(res == FR_OK)
    {
      f_read(&fhandle, &iNumItem, sizeof(iNumItem), &iRead);
      ebResult = BinarySearch(&fhandle, 
                             p_strtYMME, 
                             p_strtDLCLocator,
                             sizeof(*p_strtDLCLocator),
                             sizeof(structYMME_DLCLocator),
                             HEADER_FILE_SIZE, //Start address of record
                             iNumItem);           
    }
    f_close(&fhandle);
    return ebResult;
}
  
/*------------------------------------------------------------------------------
*Engineer:          TranLuu
*Historical:        1.Aug 18 2014
2.
*Function name:     DLCLocatorGetString
*Description:       DLCLocatorGetString
*Input:
*Output:
------------------------------------------------------------------------------*/
static enumbool DLCLocatorGetString(enumbool blGetAccesstring, enumOBDLanguage bLanguage, uint16 index, uint8* buffer)
{
    FRESULT res;
    FIL fhandle;
    uint32 iRead = 0;
    
    char* HEADER_ACCESS_PATH[NUMBER_OF_LANG] 	= {null, HEADER_ACCESS_ENG_PATH, HEADER_ACCESS_SPA_PATH, HEADER_ACCESS_FRE_PATH, null, null, null};
    char* HEADER_COMMENT_PATH[NUMBER_OF_LANG] 	= {null, HEADER_COMMENT_ENG_PATH, HEADER_COMMENT_SPA_PATH, HEADER_COMMENT_FRE_PATH, HEADER_COMMENT_JAP_PATH, HEADER_COMMENT_CHI_PATH, HEADER_COMMENT_VIE_PATH};
    
    char* LIST_ACCESS_PATH[NUMBER_OF_LANG] 	= {null, LIST_ACCESS_ENG_PATH, LIST_ACCESS_SPA_PATH, LIST_ACCESS_FRE_PATH, null, null, null};
    char* LIST_COMMENTS_PATH [NUMBER_OF_LANG]	= {null, LIST_COMMENT_ENG_PATH, LIST_COMMENT_SPA_PATH, LIST_COMMENT_FRE_PATH, LIST_COMMENT_CHI_PATH, LIST_COMMENT_JAP_PATH, LIST_COMMENT_VIE_PATH};
    char* HeaderPath;
    char* DataPath;
    	
    enumbool ebResult = eFALSE;
    
    uint16 bCommentID = 0;
    uint16 sString_ID = 0;

    uint8  bStringID_Size = 0;
    uint8  bRead_Byte = 0;
    
    uint16 sLength = 0;
    uint32 iStartAddr = 0;
    
    uint8 Key[32] = { 0xeb, 0x36, 0x70, 0xf9, 0x34, 0x9b, 0x5b, 0x72, 
                      0x3d, 0x9a, 0x0e, 0x5d, 0xce, 0x4f, 0xdc, 0x91,
                      0x80, 0x8e, 0xbe, 0x5f, 0xab, 0x16, 0x24, 0x5d,
                      0x25, 0xb1, 0x0b, 0xcd, 0x30, 0x71, 0x24, 0x06 };//key decrypt
    if(blGetAccesstring)
    {
      HeaderPath = HEADER_ACCESS_PATH[bLanguage];
      DataPath = LIST_ACCESS_PATH[bLanguage];
      bStringID_Size = ACCESS_ID_SIZE;
      bRead_Byte = HEADER_ACCESS_STRING_SIZE;
    }
    else
    {
      HeaderPath = HEADER_COMMENT_PATH[bLanguage];
      DataPath = LIST_COMMENTS_PATH[bLanguage];
      bStringID_Size = COMMENT_ID_SIZE;
      bRead_Byte = HEADER_COMMENT_STRING_SIZE;
    }
    res = f_open(&fhandle, HeaderPath, FA_OPEN_EXISTING| FA_READ);/*open Header file*/
    if(res == FR_OK)
    {
      f_lseek(&fhandle,(index - 1)*bRead_Byte + HEADER_FILE_SIZE);
      f_read(&fhandle, &sString_ID, bStringID_Size, &iRead);      
      if(sString_ID == index)
	  {
            f_read(&fhandle, &iStartAddr, sizeof(iStartAddr), &iRead);
            f_read(&fhandle, &sLength, sizeof(sLength), &iRead);
            f_close(&fhandle); /*Close header file*/
            res = f_open(&fhandle, DataPath, FA_OPEN_EXISTING| FA_READ);/*open data file*/
            if(res == FR_OK)
            {
              f_lseek(&fhandle, iStartAddr);
              memset(buffer, 0, sLength);
              f_read(&fhandle, buffer, sLength, &iRead);
              //aes_decrypt_double_wKey(Key, (uint8*)buffer, (uint8*)buffer, strtStringInfo.sLength);
              ebResult = eTRUE;
            }
            f_close(&fhandle);/*Close data file*/
	  }      
    }
    else
    {
      f_close(&fhandle);
    }
    return ebResult;
}
/*------------------------------------------------------------------------------
*Engineer:          TranLuu
*Historical:        1.Aug 18 2014
2.
*Function name:     DLCLocatorInfo_Get
*Description:       DLCLocatorInfo Get
*Input:             
*Output:            
------------------------------------------------------------------------------*/
enumbool DLCLocatorInfo_Get(structMFRVinProfile *p_strtMFRVehicleProfile,
                            enumOBDLanguage              bLanguage,
                            structMFRDLCLocatorInfo      *p_strtDLCLocatorInfo)
{
  
  enumbool ebResult = eFALSE;
  structDLCLocator strtDLCLocator;
  structYMME_DLCLocator strtYMME;
  enumbool blGetAccesstring = 0; 
  
  strtYMME.eMake = p_strtMFRVehicleProfile->eMake;
  strtYMME.eYear = (uint8)p_strtMFRVehicleProfile->eYear;
  strtYMME.eModel = p_strtMFRVehicleProfile->eModel;
  strtYMME.eTrim = p_strtMFRVehicleProfile->eTrim;
  strtYMME.eEngine = p_strtMFRVehicleProfile->eEngine;
//  strtYMME.eBM = p_strtMFRVehicleProfile->eBodyCode;
  
  ebResult = SearchYMME(&strtDLCLocator, &strtYMME);
  memset(p_strtDLCLocatorInfo->strAccess, 0, sizeof(p_strtDLCLocatorInfo->strAccess));
  memset(p_strtDLCLocatorInfo->strComment, 0, sizeof(p_strtDLCLocatorInfo->strComment));
  p_strtDLCLocatorInfo->eMFRDLCPos = eMFR_DLC_POS_UNDEFINED;
  if(ebResult == eTRUE)
  {
    p_strtDLCLocatorInfo->eMFRDLCPos = strtDLCLocator.ePoLap Dangion;
    /*blGetAccesstring = 0 => get comment string*/
    ebResult = DLCLocatorGetString(blGetAccesstring,
                                  bLanguage,
                                  (uint16)strtDLCLocator.sComment,
                                  p_strtDLCLocatorInfo->strComment);
    blGetAccesstring = 1;
    /*blGetAccesstring = 1 => get Access string*/
    ebResult = DLCLocatorGetString(blGetAccesstring,
                                  bLanguage,
                                  (uint16)strtDLCLocator.bAccess,
                                  p_strtDLCLocatorInfo->strAccess);

  }
  return ebResult;
}
