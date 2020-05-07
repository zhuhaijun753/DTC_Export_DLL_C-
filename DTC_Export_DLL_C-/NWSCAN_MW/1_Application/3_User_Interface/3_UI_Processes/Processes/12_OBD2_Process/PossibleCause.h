/******************************************************************************
Function: GetFixDescription
Date: Oct 25 2013
Version: V01.00.01 
        V01.00.02   Nov0513 update new structure created Nov0513     V01.00.01
                    support description length is over 512 bytes
                    read out 512 characters/time
        V01.00.03   Nov 1113 add sFixDescrptLimit for length of description buffer
		V01.00.03   Nov 2613 add Trim for BMW
Engieer: Hung Phan
Description: get fix description for DTC of specific vehicle
Input: VehicleProfile, DTCcode and DTC type, FisDescription address, FixDescOffset,
        sFixDescrptLimit
Output: FixDescription in pointer format and Fix descprition length
Precondition: DTC type is SAE only
            FixDescOffset is smaller than length of full description
            sFixDescrptLimit must be a multiple of 16
******************************************************************************/
#ifndef __POSSIBLECAUSE_H__
#define __POSSIBLECAUSE_H__
#include <string.h>
#include <stdio.h>
#include "PlatformType.h"
//#include "InnovaLib.h"
//#include "ProtocolUtility.h"
//#include <AppDriver\FatFs\inc\ff.h>
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
//#include <libs\vindecode\Manufacturer_VinDecode.h>

#define MAX_POSSIBLE_CAUSE_FNAME    50
#define FIX_ID_STRING_LENGTH        6
#define FIX_ID_STRUCT_SIZE          9
#define DTC_CODE_SIZE               2
#define MAX_POSSIBLE_CAUSE_DESCRIPTION 512

#pragma pack(1)
typedef struct _structFixID
{
    unsigned short sDTCCode;
    unsigned char DTCtype;
    unsigned int iOffset;
    unsigned short sLength;
}structFixID;
#pragma pack()

#ifdef __POSSIBLECAUSE_C__

#if 0
unsigned short GetFixDescription( structMFRVinProfile *VehicleProfile, unsigned short DTCcode, 
                  enumDTCType DTCtype, char* FixDescription, unsigned int FixDescOffset);
#endif
#else
#if 1
extern unsigned short GetFixDescription( structMFRVinProfile *VehicleProfile, unsigned short DTCcode, 
                                        enumDTCType DTCtype, char* FixDescription, unsigned int FixDescOffset,
                                        unsigned short sFixDescrptLimit);
#else
extern unsigned short GetFixDescription( structMFRVinProfile *VehicleProfile, unsigned short DTCcode, 
                  enumDTCType DTCtype, char* FixDescription, unsigned int FixDescOffset);
#endif
#endif
#endif