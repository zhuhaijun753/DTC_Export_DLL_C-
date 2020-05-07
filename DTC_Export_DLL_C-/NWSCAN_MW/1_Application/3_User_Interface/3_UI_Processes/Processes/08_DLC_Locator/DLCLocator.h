#ifndef ___DLC_LOCATOR_H__
#define ___DLC_LOCATOR_H__

#include <PlatFormType.h>
#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include <string.h>
#include "DLCLocatorEnumeration.h"

#pragma pack(1)

#ifdef ___DLC_LOCATOR_C__
enumbool DLCLocatorInfo_Get(structMFRVinProfile *p_strtMFRVehicleProfile, enumOBDLanguage bLanguage, structMFRDLCLocatorInfo *p_strtDLCLocatorInfo);
#else
extern enumbool DLCLocatorInfo_Get(structMFRVinProfile *p_strtMFRVehicleProfile, enumOBDLanguage bLanguage, structMFRDLCLocatorInfo *p_strtDLCLocatorInfo);
#endif


#endif
