/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __BYTE_STRING_UTILITIES_H__
#define __BYTE_STRING_UTILITIES_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/
#define GUID_STRING_SIZE    36

typedef struct _structGUID
{
    uint32 Data1;
    uint16 Data2;
    uint16 Data3;
    uint8  Data4[8];
} structGUID;
/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __BYTE_STRING_UTILITIES_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
int LiBytesToInt(const uint8* p_byteArray, uint8 bNumberByte);
int BiBytesToInt(const uint8* p_byteArray, uint8 bNumberByte);
void GUID2String(uint8* p_Guid, uint8* p_strGUI);
uint16 DecToBCD(uint8 bDec);
float ZeroTrunc(float fValue, float epsilon);
void FloatToString(float fValue, uint8 bPrecision,
                   enumbool blIsWChar, void* p_strBuffer);
uint8 GetNextElement(uint8 bKey, sint32 iOffset,
                     const uint8 p_bDigitList[],
                     uint32 iListSize);

float   FloatNumberMakeRound(float f_InputFloat,
                             uint8  bNoDigit);
#endif


