/******************************************************************************
 ===============================================================================
 Lap Dang Dev
 * Filename : NwS_Config.h
 * Description:
 
 *  Created on: Lap Dang  Oct 10, 2014
 *
 *  Version         : V01.00.00
 ===============================================================================
 ******************************************************************************/

#ifndef NWS_CONFIG_H_
#define NWS_CONFIG_H_
#ifndef OBD2_ECM
#define OBD2_ECM        2
#endif
#ifndef OBD2_TCM
#define OBD2_TCM        3
#endif

#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\enums.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMMESelection.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMME_Structure.h>
#include <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Structure.h>
#include "NWSCAN_APP\MW_LIB\SYS_SD_Utilities.h"
#include "NWSCAN_APP\MW_LIB\Makes_EcuInfo.h"

char* gf_VDM_DTCPathGet(uint8*pFunction,uint8* pFile,uint8 isUsedYear);
uint8 gf_VDM_DTCPathGetListVersion(char*RootFolder);
void gf_VDM_DTCPathSetIdx(uint8 bIdx);

extern structMFRVinProfile * VehicleData_YMMEProfile_Get(void);

#define PATH_DTC_ROOT 							        "Dtc"
#define PATH_NWS_DTC_ROOT 							"NwsDtc"
#define PATH_NWSCAN_ROOT         						"NetworkScan"

#define VDM_DTC_GET_LIST_VERSION()                       gf_VDM_DTCPathGetListVersion(PATH_DTC_ROOT)
#define VDM_NWDTC_GET_LIST_VERSION()                     gf_VDM_DTCPathGetListVersion(PATH_NWS_DTC_ROOT)
#define VDM_ECU_VOLVO_GET_LIST_VERSION()                 gf_VDM_DTCPathGetListVersion(PATH_NWSCAN_ROOT)

#define __MAKE_DTC_PATH(a)				 gf_VDM_DTCPathGet(PATH_DTC_ROOT,FILE_##a,0)
#define __MAKE_NWDTC_PATH(a)			         gf_VDM_DTCPathGet(PATH_NWS_DTC_ROOT,FILE_##a,0)

#define FILE_VOLVO_ECUID_DEFAULT                	"volvo_ecuid_default.bin"
#define FILE_OBDII_MAINDTC_BIN                   	"%s/maindtc.bin"
#define FILE_OBDII_M_DTC                         	"%s/m%01d.bin"
#define FILE_M_DTC                   			"%s/m%01d.bin"
#define FILE_S_DTC                   			"%s/s%01d.bin"
#define FILE_MAINDTC_BIN            			"%s/maindtc.bin"
#define FILE_SUBDTC_BIN                          	"%s/subdtc.bin"
#define FILE_SEVERITY_BIN                               "%s/severity.bin"
/*
 * NWSCAN PATH
 * */


/*
 * DTC Paths
 * */
#define PATH_OBDII_MAINDTC_BIN                   			 __MAKE_DTC_PATH(OBDII_MAINDTC_BIN)
#define PATH_OBDII_M_DTC                         			 __MAKE_DTC_PATH(OBDII_M_DTC)
#define PATH_M_DTC                   					 __MAKE_DTC_PATH(M_DTC)
#define PATH_S_DTC                   				         __MAKE_DTC_PATH(S_DTC)
#define PATH_MAINDTC_BIN            				         __MAKE_DTC_PATH(MAINDTC_BIN)
#define PATH_SUBDTC_BIN                          			 __MAKE_DTC_PATH(SUBDTC_BIN)
#define PATH_SEVERITY_DTC                                                __MAKE_DTC_PATH(SEVERITY_BIN)

#define PATH_ALL_M_DTC                   				 __MAKE_NWDTC_PATH(M_DTC)
#define PATH_ALL_S_DTC                   				 __MAKE_NWDTC_PATH(S_DTC)
#define PATH_ALL_MAINDTC_BIN            				 __MAKE_NWDTC_PATH(MAINDTC_BIN)
#define PATH_ALL_SUBDTC_BIN                          			 __MAKE_NWDTC_PATH(SUBDTC_BIN)
                                              


#define __NWSCAN_PATH(a)				                gf_VDM_DTCPathGet(PATH_NWSCAN_ROOT,FILE_##a,1)
#define PATH_OK_VOLVO_ECUID_DEFAULT                                     __NWSCAN_PATH(VOLVO_ECUID_DEFAULT)
/*END OF VCI config regions*/
#endif /* NWS_CONFIG_H_ */
