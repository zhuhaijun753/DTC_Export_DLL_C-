/******************************************************************************
Filename: PossibleCause
Date: Oct 25 2013
Engineer: Hung Phan
Description: To get fix description for DTC of  specific vehilce YMME.
Input: YMME + ... ( vehicle profile) + DTC
Output: Fix description
******************************************************************************/
/*=====================pc.bin file structure==================================*/
/*
// start file
4bytes (TOTAL_YMMETT_INDEX_SIZE) Total YMMETT in search list + 6 bytes (EACH_YMMETT_SIZE) YMMETT_1 data + 4 bytes jump address for YMMETT_1
+ 6 bytes (EACH_YMMETT_SIZE)YMMETT_2 data + 4 bytes (INDEX_ADDRESS_SIZE) jump address for YMMETT_2 
+ 6 bytes (EACH_YMMETT_SIZE)YMMETT_3 data + 4 bytes (INDEX_ADDRESS_SIZE) jump address for YMMETT_3 
+ ... 
+6 bytes YMMETT_n data + 4 bytes jump address for YMMETT_n // end of YMMETT list
// start DTC list for one YMMETT
+ 2bytes total DTC in one YMMETT_x + 2 bytes DTC_x1 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_x1
+ 2 bytes DTC_x2 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_x2
+ 2 bytes DTC_x3 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_x3
+...
+ 2 bytes DTC_xn code + 4 bytes jump address for DTC_xn // end YMMETTx
+ 2bytes total DTC in one YMMETT_y + 2 bytes DTC_y1 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_y1
+ 2 bytes DTC_y2 code + 4 bytes (INDEX_ADDRESS_SIZE) jump address for DTC_y2
+ 2 bytes DTC_y3 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_y3
+...
+ 2 bytes DTC_yn code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_yn
+...
+ 2bytes total DTC in one YMMETT_z + 2 bytes DTC_z1 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_z1
+ 2 bytes DTC_z2 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_z2
+ 2 bytes DTC_z3 code + 4 bytes (INDEX_ADDRESS_SIZE)jump address for DTC_z3
+...
+ 2 bytes DTC_zn code + 4 bytes(INDEX_ADDRESS_SIZE) jump address for DTC_zn // End DTC list for all YMMETT
// start fix description
+ 2 bytes DTC_1 code + 1 byte DTC type + 4 bytes (DTC_PCD_OFFSET_SIZE) fix description jump address + 2 byte len of description
+ 2 bytes DTC_2 code + 1 byte DTC type + 4 bytes (DTC_PCD_OFFSET_SIZE) fix description jump address + 2 byte len of description
+ 2 bytes DTC_3 code + 1 byte DTC type + 4 bytes (DTC_PCD_OFFSET_SIZE) fix description jump address + 2 byte len of description
+ 2 bytes DTC_4 code + 1 byte DTC type + 4 bytes (DTC_PCD_OFFSET_SIZE) fix description jump address + 2 byte len of description
+...
+ 2 bytes DTC_n code + 1 byte DTC type + 4 bytes (DTC_PCD_OFFSET_SIZE) fix description jump address + 2 byte len of description
*/

/*=====================pcd.bin file structure==================================*/
//each string has len that len %16=0
/*
Fix1 description string + Fix 2 description string + Fix 3 description string +
Fix 4 description string +Fix 5 description string +Fix 6 description string +
...
Fix n-2 description string +Fix n-1 description string +Fix n description string 
*/

/******************************************************************************

====================HISTORY====================================================
Date        Version     Note
Oct2913     V01.00.00   1st release
                        structure: typedef struct _structFixID
                                    {
                                        unsigned short sDTCCode;
                                        unsigned char eDTCType;
                                        unsigned char bFixIDString[FIX_ID_STRING_LENGTH];
                                    }structFixID;
            -------------------------------------------------------
Nov0513     V01.00.01   2nd release, update new structure
                        typedef struct _structFixID
                        {
                            unsigned short sDTCCode;
                            unsigned int iOffset;
                            unsigned short sLength;
                        }structFixID;            
            -------------------------------------------------------
Nov0513     V01.00.02 3rd release, update new parameter for this function    
                        unsigned short GetFixDescription(...unsigned short sFixDescrptLimit)
                       by adding sFixDescrptLimit for length limitation of buffer 
            -------------------------------------------------------
Nov 2613    V01.00.03    add Trim for BMW
            -------------------------------------------------------
Dec 0513    V01.00.04   Change to one PC file structure
            -------------------------------------------------------
Feb 282014  V01.00.05   Fix bug on matching DTC with total DTC =1
            -------------------------------------------------------
Sep 192014  V01.00.06   Clean up magic number
            -------------------------------------------------------
Jan 282015  V01.00.07   Change YMMETT struct from Year Make Model Engine Trim Transmission
                            to Year Make Model Trim Engine Transmission.
                        This version is not backward compatible. It work with database from V02.00.xx
Feb 022015  V01.00.08   Change DTC byte order in database. Don't need to reverse byte order anymore. 
******************************************************************************/
//#include "Include\PossibleCause.h"		
#include <YMMESelection.h>
#include "PossibleCause.h"
#define POSSIBLECAUSE_PATH "/Fix/pc.bin"
#define PCDESCRIPTION_PATH "/Fix/pcd.bin"

/*============================================================================*/
#define EACH_YMMETT_SIZE    6
#define TOTAL_YMMETT_INDEX_SIZE     4
#define INDEX_ADDRESS_SIZE      4
#define TOTAL_DTCs_INDEX_SIZE		2
#define DTC_CODE_SIZE		2
#define DTC_PCD_OFFSET_SIZE     4
/*============================================================================*/
typedef enum _ComparedResult
{
    EQUAL =0,
    OVER =1,
    LOWER =2,
    UNKNOW = 0xFF
}ComparedResult;

extern int aes_decrypt( unsigned char* input, unsigned char* output, int length );
static void YMMEConvert2Array ( structMFRVinProfile *pVehicleProfile, unsigned char* Array)
{
#if 0 // for possible cause database version V01.00.xx and older
    // Transmission
    *Array = (unsigned char)pVehicleProfile->eTransmission;
    Array++;
    
    // Engine
    *Array = (unsigned char)pVehicleProfile->eEngine;
    Array++;
    
    // Trim
    if(pVehicleProfile->eMake == eMake_BMW_4)
    {
        *Array = (unsigned char)pVehicleProfile->eTrim;
        Array++;
    }
    else
    {
        *Array = 0;
        Array++;
    }   
    
    
    // Model
    *Array = (unsigned char)pVehicleProfile->eModel;
    Array++;
    
    // Make    
    *Array = (unsigned char)pVehicleProfile->eMake;        
    Array++;
    
    // Year
    *Array = (unsigned char)pVehicleProfile->eYear;
#else
    unsigned long long tempvalue=0;
    
    
/*
self.Year << (5*8)) + (self.Make << (4*8)) + \
                     (self.Model << (3*8)) + (self.Trim << (2*8)) + \
                     (self.Engine << (1*8)) + self.Transmission   
*/
    tempvalue += ((unsigned long long)pVehicleProfile->eYear) << (5*8) ;
    tempvalue += ((unsigned long long)pVehicleProfile->eMake) << (4*8) ;
    tempvalue += ((unsigned long long)pVehicleProfile->eModel)   << (3*8) ;
    tempvalue += ((unsigned long long)pVehicleProfile->eEngine) << (1*8) ;
    tempvalue += (unsigned long long)pVehicleProfile->eTransmission;
    
    if(pVehicleProfile->eMake == eMake_BMW_4)
    {
        tempvalue = tempvalue + ((unsigned long long)pVehicleProfile->eTrim) <<(8*2);        
    }    
    memcpy(Array,&tempvalue,EACH_YMMETT_SIZE);
                     
#endif
}
static unsigned long long ConvertToLongLong ( unsigned char* Source, unsigned char size)
{
    unsigned long long TempBuf=0;
    memcpy(&TempBuf, Source, size);
    
    return TempBuf; 
}
static ComparedResult CompareArray(unsigned char* Target, unsigned char * Sample, unsigned char size)
{
    ComparedResult Status = UNKNOW;
    unsigned long long Temp1;
    unsigned long long Temp2;
    
    Temp1 = ConvertToLongLong(Target,size);
    Temp2 = ConvertToLongLong(Sample,size);
    
    if( Temp1 == Temp2)
    {
        Status = EQUAL;
    }
    else if ( Temp1 > Temp2)
    {
        Status = OVER;
    }
    else // ( Temp1 < Temp2)
    {
        Status = LOWER;
    }
    return Status;    
}
static unsigned int GetDTCOffset ( structMFRVinProfile *pVehicleProfile)
{
    FRESULT res;
    FIL fhandle;
    unsigned int iRead =0;
    unsigned int Min =0;
    unsigned int Max =0;
    unsigned int Mid =0;
    unsigned char YMMETTSample[EACH_YMMETT_SIZE];
    unsigned char YMMETTTarget[EACH_YMMETT_SIZE];
    ComparedResult Status = UNKNOW;
    unsigned int SeekPoLap Dangion =0;
    unsigned int oldMid =0;
    
    YMMEConvert2Array (pVehicleProfile, YMMETTTarget);
    //open pc.bin file
    res = f_open(&fhandle, POSSIBLECAUSE_PATH, FA_OPEN_EXISTING| FA_READ); 
    if ( res == FR_OK)
    {
        f_read(&fhandle, &Max, TOTAL_YMMETT_INDEX_SIZE/*total YMMETT*/,&iRead);        
        do
        {
            Mid = (Max -Min)/2 + Min;
            
            SeekPoLap Dangion = TOTAL_YMMETT_INDEX_SIZE + Mid*( EACH_YMMETT_SIZE + INDEX_ADDRESS_SIZE); /* First 4 bytes = Total YMMETT; 
                                        10 bytes= 6 bytes YMMETT + 4 bytes offset*/
            f_lseek(&fhandle, SeekPoLap Dangion); 
            f_read(&fhandle, YMMETTSample, EACH_YMMETT_SIZE,&iRead); 
            Status = CompareArray(YMMETTTarget, YMMETTSample, EACH_YMMETT_SIZE);
            if (Status == EQUAL)
            {
                f_close(&fhandle);
                return SeekPoLap Dangion + EACH_YMMETT_SIZE;
            }
            else if (Status == OVER)
            {
                Min = Mid;
            }
            else // (Status == LOWER)                
            {
                Max = Mid;
            }
            if(oldMid == Mid)
            {
                break;
            }
            else
            {
                oldMid = Mid;
            }
        }while (Min != Max);
    }
    return 0;
}
static unsigned short ConvertDTCtoNumber (unsigned short DTCcode)
{
#if 1 // for possible cause database version 1,2 and later
    return ((DTCcode & 0x00FF) << 8) | ((DTCcode & 0xFF00)>>8);
#else // plain
    return DTCcode;
#endif
}
static unsigned int GetDTCDescriptionOffset(unsigned int StartPoint,unsigned short DTCcode  )
{
    FRESULT res;
    FIL fhandle;
    unsigned int iRead =0;
    unsigned int Min =0;
    unsigned int Max =0;
    unsigned int Mid =0;
    unsigned int Temp =0;
    unsigned short DTCSample;  
    unsigned int SeekPoLap Dangion =0;    
    unsigned int oldMid =0;
    
    DTCcode = ConvertDTCtoNumber(DTCcode);
    //open pc.bin file
    res = f_open(&fhandle, POSSIBLECAUSE_PATH, FA_OPEN_EXISTING| FA_READ); 
    if ( res == FR_OK)
    {
        f_lseek(&fhandle, StartPoint); 
        f_read(&fhandle, &Temp, INDEX_ADDRESS_SIZE/*DTCOffset*/,&iRead);   
        f_lseek(&fhandle, Temp); 
        f_read(&fhandle, &Max, TOTAL_DTCs_INDEX_SIZE/*total DTC*/,&iRead);        
        do
        {
            Mid = (Max -Min)/2 + Min;            
            
            SeekPoLap Dangion = Temp + TOTAL_DTCs_INDEX_SIZE + Mid*(DTC_CODE_SIZE + INDEX_ADDRESS_SIZE); /* First 2 bytes = Total DTC; 
                                        6 bytes= 2 DTC code + 4 bytes offset*/
            f_lseek(&fhandle, SeekPoLap Dangion); 
            f_read(&fhandle, &DTCSample, DTC_CODE_SIZE/*DTC*/,&iRead);     
            //DTCSample= ConvertDTCtoNumber(DTCSample);
            if (DTCcode == DTCSample)
            {
                f_close(&fhandle);
                return SeekPoLap Dangion + DTC_CODE_SIZE;
            }
            else if (DTCcode > DTCSample)
            {
                Min = Mid;
            }
            else // (Status == LOWER)                
            {
                Max = Mid;
            }
            if(oldMid == Mid)
            {
                break;
            }
            else
            {
                oldMid = Mid;
            }
        }while (Min != Max);
    }
    return 0;
}
static enumbool GetFixInfo(structMFRVinProfile *VehicleProfile, unsigned int* DTCPCDOffset,
                    unsigned short DTCcode,enumDTCType DTCtype)
{   
    enumbool eStatus = eFALSE;   
    unsigned int DTCOffset =0;
    
    if (DTCtype == DTC_SAE)
    {
        DTCOffset= GetDTCOffset (VehicleProfile);
        if(DTCOffset !=0)
        {
            *DTCPCDOffset = GetDTCDescriptionOffset (DTCOffset,DTCcode);
            if(*DTCPCDOffset != 0)
            {
                eStatus = eTRUE;
            }            
        }
    }    
    return eStatus; 
}
                    
/******************************************************************************
Function: GetFixDescription
Date: Oct 25 2013
Version: V01.00.01 
        V01.00.02   Nov0513 update new structure created Nov0513     V01.00.01
                    support description length is over 512 bytes
                    read out 512 characters/time
        V01.00.03   Nov 1113 add sFixDescrptLimit for length of description buffer
Engieer: Hung Phan
Description: get fix description for DTC of specific vehicle
Input: VehicleProfile, DTCcode and DTC type, FisDescription address, FixDescOffset,
        sFixDescrptLimit
Output: FixDescription in pointer format and Fix descprition length
Precondition: DTC type is SAE only
            FixDescOffset is smaller than length of full description
            sFixDescrptLimit must be a multiple of 16
******************************************************************************/
unsigned short GetFixDescription( structMFRVinProfile *VehicleProfile, unsigned short DTCcode, 
                  enumDTCType DTCtype, char* FixDescription, unsigned int FixDescOffset,
                  unsigned short sFixDescrptLimit)
{
    FRESULT res;
    FIL fhandle;
    unsigned int iRead =0;
    unsigned short sLength = 0;
    unsigned int DTCPCDOffset =0;
    structFixID strtFixIDTemp;   
    enumbool blFixIDGetStatus = eFALSE;

    
    if (DTCtype == DTC_SAE)
    {         
     
        /*Get Fix description offset*/
        blFixIDGetStatus= GetFixInfo (VehicleProfile,&DTCPCDOffset, 
                     DTCcode, DTCtype);
        
        /*If get FixID success, try to get definition*/
        if(blFixIDGetStatus)
        {    
            //open file
            res = f_open(&fhandle, POSSIBLECAUSE_PATH, FA_OPEN_EXISTING| FA_READ);
            if ( res == FR_OK)
            {        
                f_lseek(&fhandle, DTCPCDOffset);
                f_read(&fhandle, &DTCPCDOffset, DTC_PCD_OFFSET_SIZE,&iRead); 
                f_lseek(&fhandle, DTCPCDOffset);
                f_read(&fhandle, &strtFixIDTemp, sizeof(structFixID),&iRead);           
                f_close(&fhandle);
            }
            // Get Fix Description 
            res = f_open(&fhandle, PCDESCRIPTION_PATH, FA_OPEN_EXISTING| FA_READ);
            if (( res == FR_OK) && (FixDescOffset < strtFixIDTemp.sLength))
            {
                /* Get read point */
                f_lseek(&fhandle,strtFixIDTemp.iOffset + FixDescOffset );
                    
                f_read(&fhandle, FixDescription, 
                       sFixDescrptLimit > strtFixIDTemp.sLength ? strtFixIDTemp.sLength:sFixDescrptLimit ,&iRead);
                aes_decrypt((unsigned char *)FixDescription, (unsigned char *)FixDescription, iRead);
                
                sLength =  strtFixIDTemp.sLength;
                f_close(&fhandle);
            }   
        }      
    }
    
    return sLength;
}

