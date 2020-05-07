/*******************************************************************************
 ================================================================================
 Lap Dang Dev
 * Filename: NWSCAN_Setup.c
 * Description:
 * Layer:
 * Accessibility:
 * Created on: Oct 9, 2015
 *      Author: Lap Dang
 ================================================================================
 *******************************************************************************/

#define NWSCAN_SETUP_C_
#include "PlatFormType.h"
#include "SYS_Utility.h"
#include "VDM_Adapter.h"
#include "NWSCAN_Setup_US_12Makes.h"
#include "NWSCAN_Setup_define.h"
#include "enums.h"

const structNWScanYmmeUsing strtNWScanYmmeUsing[] =
		{
#if ENABLE_NWSCAN_FORD
						YMME_NWSCAN_PROFILE_MAP(Ford,emake_Ford ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Ford,emake_Lincoln ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Ford,emake_Mercury ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Ford,emake_Mazda ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_TOYOTA
						YMME_NWSCAN_PROFILE_MAP(Toyota,emake_Lexus ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Toyota,emake_Scion ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Toyota,emake_Toyota ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_GM
						YMME_NWSCAN_PROFILE_MAP(GM,emake_AM_____General ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Buick ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Cadillac ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Chevrolet ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
				// YMME_NWSCAN_PROFILE_MAP(GM,emake_Daewoo ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Geo ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_GMC,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Hummer ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Oldsmobile ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Pontiac ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Saab ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(GM,emake_Saturn ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_MERCEDES
						YMME_NWSCAN_PROFILE_MAP(Mercedes,emake_Mercedes_Benz,eFALSE , eTRUE, eFALSE , eFALSE , eFALSE , eFALSE, eFALSE, eFALSE, eTRUE),
#endif
#if ENABLE_NWSCAN_CHRYSLER
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_Chrysler ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_Dodge ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_Eagle ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_Jeep ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_Plymouth ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_Ram ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Chrysler,emake_SRT ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_HONDA
						YMME_NWSCAN_PROFILE_MAP(Honda,emake_Honda ,eFALSE, eTRUE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Honda,emake_Acura ,eFALSE, eTRUE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_VAG
						YMME_NWSCAN_PROFILE_MAP(VAG,emake_Volkswagen ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(VAG,emake_Audi ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_BMW
						YMME_NWSCAN_PROFILE_MAP(Bmw,emake_BMW ,eTRUE , eTRUE, eFALSE, eFALSE, eFALSE, eFALSE , eTRUE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Bmw,emake_Mini ,eTRUE , eTRUE, eFALSE, eFALSE, eFALSE, eFALSE , eTRUE , eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_HYUNDAI
						YMME_NWSCAN_PROFILE_MAP(Hyundai,emake_Hyundai ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Hyundai,emake_Kia ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_NISSAN
						YMME_NWSCAN_PROFILE_MAP(Nissan,emake_Nissan ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Nissan,emake_Infiniti ,eTRUE , eTRUE, eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_VOLVO
						YMME_NWSCAN_PROFILE_MAP(Volvo,emake_Volvo ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_JAGUAR_LANDROVER
						YMME_NWSCAN_PROFILE_MAP(JaguarLandrover,emake_Jaguar ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(JaguarLandrover,emake_Land_____Rover ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_FIAT
						YMME_NWSCAN_PROFILE_MAP(Fiat,emake_Fiat ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
						YMME_NWSCAN_PROFILE_MAP(Fiat,emake_Alfa_____Romeo ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_DAEWOO
						YMME_NWSCAN_PROFILE_MAP(Daewoo,emake_Daewoo ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_FAW
						YMME_NWSCAN_PROFILE_MAP(Faw,emake_Faw ,eFALSE , eTRUE, eFALSE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_OPEL
						YMME_NWSCAN_PROFILE_MAP(Opel,emake_Opel ,eTRUE , eTRUE, eTRUE , eTRUE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif
#if ENABLE_NWSCAN_MG 
						YMME_NWSCAN_PROFILE_MAP(MG,emake_MG ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_PORSCHE
						YMME_NWSCAN_PROFILE_MAP(Porsche,emake_Porsche ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_SSANGYONG
						YMME_NWSCAN_PROFILE_MAP(Ssangyong,emake_Ssangyong ,eFALSE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_SUZUKI
						YMME_NWSCAN_PROFILE_MAP(Suzuki,emake_Suzuki ,eFALSE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_PEUGEOT
						YMME_NWSCAN_PROFILE_MAP(Peugeot,emake_Peugeot ,eFALSE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_MITSUBISHI
						YMME_NWSCAN_PROFILE_MAP(Mitsubishi,emake_Mitsubishi ,eTRUE , eTRUE, eFALSE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

#if ENABLE_NWSCAN_RENAULT
						YMME_NWSCAN_PROFILE_MAP(Renault,emake_Renault ,eTRUE , eTRUE, eTRUE , eFALSE , eFALSE, eFALSE, eFALSE, eFALSE, eFALSE),
#endif

				/*
				 * Register Make library here
				 * */
				{ .sMake = emake_UNKNOWN, .use_bYear = eFALSE, .use_sMake =
						eFALSE, .use_sModel = eFALSE, .use_sEngine = eFALSE,
						.use_sTrim = eFALSE, .use_sTrasmission = eFALSE,

				}, };
