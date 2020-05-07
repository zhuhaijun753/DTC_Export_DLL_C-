#ifndef __DLC_LOCATOR_ENUMERATION_H__
#define __DLC_LOCATOR_ENUMERATION_H__

#include <PlatFormType.h>
#include <ymme_enumeration.h>
#include <YMME_Structure.h>
#include <enums.h>

#define     DLC_LOCATOR_INFO_MAX_SIZE               256
#define     DLC_LOCATOR_ACCESS_STRING_MAX_SIZE      20
#define     DLC_LOCATOR_COMMENT_STRING_MAX_SIZE     100

typedef enum _enumMFRDLCPoLap Dangion {
  eMFR_DLC_POS_UNDEFINED    = 0,
  eMFR_DLC_POS_1            = 1,
  eMFR_DLC_POS_2            = 2,
  eMFR_DLC_POS_3            = 3,
  eMFR_DLC_POS_4            = 4,
  eMFR_DLC_POS_5            = 5,
  eMFR_DLC_POS_6            = 6,
  eMFR_DLC_POS_7            = 7,
  eMFR_DLC_POS_8            = 8,
  eMFR_DLC_POS_9            = 9,
  eMFR_DLC_POS_MAX          = 0xFF
    
}enumMFRDLCPoLap Dangion;

#pragma pack(1)
typedef struct __structMFRDLCLocatorInfo
{
    enumMFRDLCPoLap Dangion  eMFRDLCPos; /*1 byte DLC PoLap Dangion*/
    uint8*              strAccess;
    uint8*              strComment;
}structMFRDLCLocatorInfo;
#pragma pack()

#pragma pack(1)
typedef struct _structDLCLocator
{
    enumMFRMake         eMake;
    uint8               eYear;
    enumMFRModel        eModel;
    enumMFRTrim		eTrim;
    enumMFREngine       eEngine;
//    enumBM              eBM;
    enumMFRDLCPoLap Dangion  ePoLap Dangion;
    uint8               bAccess;
    uint16              sComment;
} structDLCLocator;


typedef struct _structYMME_DLCLocator
{
  enumMFRMake         eMake;
  uint8               eYear;
  enumMFRModel        eModel;
  enumMFRTrim         eTrim;
  enumMFREngine       eEngine;
//  enumBM              eBM;
} structYMME_DLCLocator;
#pragma pack()

//PROCESS
#pragma pack(1)
typedef struct _structDLCProperties
{
    enumMFRDLCPoLap Dangion     eLocation;
    uint16              sDispPosX;
    uint16              sDispPosY;
    uint16              sHeight;
    uint16              sWidth;
    const uint8*        p_ImageOn;
    const uint8*        p_ImageOff;
}structDLCProperties;
#pragma pack()
#endif
