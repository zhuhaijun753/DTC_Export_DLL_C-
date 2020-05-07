#ifndef ___BATTERY_RESET_H__
#define ___BATTERY_RESET_H__

#include <PlatFormType.h>
#include "YMME_Structure.h"
#include <string.h>
#include "BatteryReset_Enumeration.h"
#include "BatteryReset_Structure.h"

extern enumBATResetStatus BatteryResetProcedure_CheckSupport(enumYear           eYear,
                                                             enumMake 		    eMake,
                                                             enumModel			eModel,
                                                             enumTrim           eTrim,
                                                             enumEngine			eEngine,
                                                             enumOBDLanguage 	eMemLanguage);

extern enumBATResetStatus BatteryResetProcedure_GetInfo(enumYear		       eYear,
                                                        enumMake			   eMake,
                                                        enumModel			   eModel,
                                                        enumTrim               eTrim,
                                                        enumEngine		       eEngine,
                                                        enumBRP_GetInfoUnit    eBRP_GetInfoUnit,
                                                        enumOBDLanguage 	   eMemLanguage,														
                                                        uint8 				   * p_TextProcedureBuff, 
                                                        uint16 			  	   sMaxLengthText);

#endif