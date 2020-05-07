#ifndef _VINDECODE_API_H
#define _VINDECODE_API_H

#include "enums.h"
#include "YMME_Structure.h"

enumMFRVinDecodeStatus decodeWMIandYear(uint16* p_sMakeList,
                                        structMFRVinProfile* p_strtMFRVehicleProfile);
enumMFRVinDecodeStatus decodeVINtoVehicleInfo(uint16* p_sMakeList,
                            structMFRVinProfile* p_strtMFRVehicleProfile);
enumbool IsVINValid(uint8 * p_VinNumber);
#endif
