/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: Common_Text_Database.c
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __COMMON_TEXT_DATABASE_H__
#define __COMMON_TEXT_DATABASE_H__

#include    "PlatformType.h"


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
/*common ram buffer to used for process UI
currently this ram buff size is 8KB
*/
extern void* const MLCommonRamBuff[NUM_LANG_SUPPORT];

//common text buffer to process UI, each buff 100 bytes in current
extern void* const MLCommonTextBuffer_1[NUM_LANG_SUPPORT];
extern void* const MLCommonTextBuffer_2[NUM_LANG_SUPPORT];
//currently common text buffer 3 size is 500 byte
extern void* const MLCommonTextBuffer_3[NUM_LANG_SUPPORT];

extern const void* const MLNull[NUM_LANG_SUPPORT];

extern const void* const ML_NA[NUM_LANG_SUPPORT];

extern const void* const MLYes[NUM_LANG_SUPPORT];
extern const void* const MLNo[NUM_LANG_SUPPORT];

extern const void* const MLSelectAndPressEnter[NUM_LANG_SUPPORT];
#define     MLMenuInstruction       (MLSelectAndPressEnter)

extern const void* const MLPressMenuForMainMenu[NUM_LANG_SUPPORT];

extern const void *const MLReleaseEnterToContinue[NUM_LANG_SUPPORT];

extern const void* const MLPressAnyHotKeys[NUM_LANG_SUPPORT];
extern const void *const MLPressLDForLDMenu[NUM_LANG_SUPPORT];

extern const void* const MLOnMenuItem[NUM_LANG_SUPPORT];
extern const void* const MLOffMenuItem[NUM_LANG_SUPPORT];

extern const void* const MLNext[NUM_LANG_SUPPORT];
extern const void* const MLBack[NUM_LANG_SUPPORT];

extern const void *const MLPressEnterToCont[NUM_LANG_SUPPORT];

extern const void* const ML_OneMomentPlease[NUM_LANG_SUPPORT];

extern void const* MLPercentFmt[NUM_LANG_SUPPORT];

extern const void* const MLCommunicationError[NUM_LANG_SUPPORT];
extern const void* const  MLOBD2UnableToEstablish[NUM_LANG_SUPPORT];
extern const void* const  MLContactTechnical[NUM_LANG_SUPPORT];



extern const void* const MLEraseDTC[NUM_LANG_SUPPORT];
extern const void* const MLToEraseWarning[NUM_LANG_SUPPORT];
extern const void* const MLEngineMustNotBeRunningToErase[NUM_LANG_SUPPORT];
extern const void* const MLEraseWasSuccesful[NUM_LANG_SUPPORT];
extern const void* const MLEraseRequestHasBeenSent[NUM_LANG_SUPPORT];
extern const void* const MLErasingClearAllDTCFF[NUM_LANG_SUPPORT];

extern const void* const MLGeneric[NUM_LANG_SUPPORT];

extern const void* const MLDetectProtocolFormat[NUM_LANG_SUPPORT];
extern const void* const MLTechnicalInfo[NUM_LANG_SUPPORT];


extern const void* const MLPowertrain[NUM_LANG_SUPPORT];
extern const void* const MLABS[NUM_LANG_SUPPORT];
extern const void* const MLSRS[NUM_LANG_SUPPORT];
extern const void* const MLEnhanced[NUM_LANG_SUPPORT];

extern const void* const MLLiveData[NUM_LANG_SUPPORT];

extern const void* const MLVehicleInfomation[NUM_LANG_SUPPORT];

extern const void* const  MLNoDefinition[NUM_LANG_SUPPORT];



/*==============================================================================
*                                 FUNCTIONs
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 02 2015
*Function name: MLCommonRamBuff_Clear
*Descrtiption : clear the common ram buffer used in UI
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void MLCommonRamBuff_Clear(void);
uint16 MLCommonRamBuff_Size_Get(void);


void MLCommonTextBuffer_1_Clear(void);
uint16 MLCommonTextBuff_1_Size_Get(void);

void MLCommonTextBuff_2_Clear(void);
uint16 MLCommonTextBuff_2_Size_Get(void);

void MLCommonTextBuffer_3_Clear(void);
uint8* MLCommonTextBuff_3_Pointer_Get(void);
uint16 MLCommonTextBuff_3_Size_Get(void);

#endif