/*******************************************************************************
================================================================================
                              Lap Dang Dev
 * Filename: NWSCAN_Setup_define.h
 * Description:
 * Layer:
 * Accessibility:
 * Created on: Oct 9, 2015
 *      Author: Lap Dang
================================================================================
*******************************************************************************/

#ifndef NWSCAN_SETUP_DEFINE_H_
#define NWSCAN_SETUP_DEFINE_H_

#define YMME_NWSCAN_PROFILE_MAP(Vehicle,MAKE,BYEAR,SMAKE,SMODEL,SENGINE,STRIM,STRAMISSION,SOPTION1,SOPTION2,SOPTION3)  \
    {\
.pMwLib=__PVAR_MW_LIB_VEHICLE__(Vehicle),\
.sMake = MAKE,\
.use_bYear=BYEAR,\
.use_sMake=SMAKE,\
.use_sModel=SMODEL,\
.use_sEngine=SENGINE,\
.use_sTrim=STRIM,\
.use_sTrasmission=STRAMISSION,\
.use_sOption1=SOPTION1,\
.use_sOption2=SOPTION2,\
.use_sOption3=SOPTION3}
#define __EXPORT_MW_LIB_VEHICLE__(a)    extern const structVehNWScanSupported strtVehNWScanSupported_##a

#define __PVAR_MW_LIB_VEHICLE__(a)   &strtVehNWScanSupported_##a




#if ENABLE_NWSCAN_FORD
__EXPORT_MW_LIB_VEHICLE__(Ford);
#endif
#if ENABLE_NWSCAN_TOYOTA
__EXPORT_MW_LIB_VEHICLE__(Toyota);
#endif
#if ENABLE_NWSCAN_GM
__EXPORT_MW_LIB_VEHICLE__(GM);
#endif
#if ENABLE_NWSCAN_MERCEDES
__EXPORT_MW_LIB_VEHICLE__(Mercedes);
#endif
#if ENABLE_NWSCAN_CHRYSLER
__EXPORT_MW_LIB_VEHICLE__(Chrysler);
#endif
#if ENABLE_NWSCAN_HONDA
__EXPORT_MW_LIB_VEHICLE__(Honda);
#endif
#if ENABLE_NWSCAN_VAG
__EXPORT_MW_LIB_VEHICLE__(VAG);
#endif
#if ENABLE_NWSCAN_BMW
__EXPORT_MW_LIB_VEHICLE__(Bmw);
#endif
#if ENABLE_NWSCAN_HYUNDAI
__EXPORT_MW_LIB_VEHICLE__(Hyundai);
#endif
#if ENABLE_NWSCAN_NISSAN
__EXPORT_MW_LIB_VEHICLE__(Nissan);
#endif
#if ENABLE_NWSCAN_VOLVO
__EXPORT_MW_LIB_VEHICLE__(Volvo);
#endif


#if ENABLE_NWSCAN_FAW
__EXPORT_MW_LIB_VEHICLE__(Faw);
#endif
#if ENABLE_NWSCAN_FIAT
__EXPORT_MW_LIB_VEHICLE__(Fiat);
#endif
#if ENABLE_NWSCAN_OPEL
__EXPORT_MW_LIB_VEHICLE__(Opel);
#endif
#if ENABLE_NWSCAN_DAEWOO
__EXPORT_MW_LIB_VEHICLE__(Daewoo);
#endif


#if ENABLE_NWSCAN_JAGUAR_LANDROVER
__EXPORT_MW_LIB_VEHICLE__(JaguarLandrover);
#endif

#if ENABLE_NWSCAN_MG
__EXPORT_MW_LIB_VEHICLE__(MG);
#endif

#if ENABLE_NWSCAN_PORSCHE
__EXPORT_MW_LIB_VEHICLE__(Porsche);
#endif

#if ENABLE_NWSCAN_SSANGYONG
__EXPORT_MW_LIB_VEHICLE__(Ssangyong);
#endif

#if ENABLE_NWSCAN_SUZUKI
__EXPORT_MW_LIB_VEHICLE__(Suzuki);
#endif

#if ENABLE_NWSCAN_PEUGEOT
__EXPORT_MW_LIB_VEHICLE__(Peugeot);
#endif

#if ENABLE_NWSCAN_MITSUBISHI
__EXPORT_MW_LIB_VEHICLE__(Mitsubishi);
#endif

#if ENABLE_NWSCAN_RENAULT
__EXPORT_MW_LIB_VEHICLE__(Renault);
#endif

#if ENABLE_NWSCAN_SUBARU
__EXPORT_MW_LIB_VEHICLE__(Subaru);
#endif

#endif /* NWSCAN_SETUP_DEFINE_H_ */
