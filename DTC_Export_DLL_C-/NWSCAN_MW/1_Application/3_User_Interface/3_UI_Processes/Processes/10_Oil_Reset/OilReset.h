#ifndef ___OIL_RESET_H__
#define ___OIL_RESET_H__

#include <PlatFormType.h>
#include <string.h>
#include "OilResetEnumeration.h"

#ifdef _OIL_RESET_C_
enumOilResetStatus OilReset_Get(structMFRVinProfile * p_strtMFRVinProfile, enumNavigationStatus eNavigateStatus, uint8 * p_TextBuffer, uint16 sBuffLen, enumOBDLanguage eLanguage);
enumOilResetStatus IsOilResetSupportted(structMFRVinProfile * p_strtMFRVinProfile, enumNavigationStatus eNavigateStatus, enumOBDLanguage eLanguage);
enumOilResetStatus IsOilResetServiceSupportted(structMFRVinProfile * p_strtMFRVinProfile, structVehicleProfile * p_strtVehicleProfile);
enumOilResetStatus ImplementOilResetService(structMFRVinProfile * p_strtMFRVinProfile, structVehicleProfile * p_strtVehicleProfile);
#else
extern enumOilResetStatus OilReset_Get(structMFRVinProfile * p_strtMFRVinProfile, enumNavigationStatus eNavigateStatus, uint8 * p_TextBuffer, uint16 sBuffLen, enumOBDLanguage eLanguage);
extern enumOilResetStatus IsOilResetSupportted(structMFRVinProfile * p_strtMFRVinProfile, enumNavigationStatus eNavigateStatus, enumOBDLanguage eLanguage);
extern enumOilResetStatus IsOilResetServiceSupportted(structMFRVinProfile * p_strtMFRVinProfile, structVehicleProfile * p_strtVehicleProfile);
extern enumOilResetStatus ImplementOilResetService(structMFRVinProfile * p_strtMFRVinProfile, structVehicleProfile * p_strtVehicleProfile);
#endif
#endif
