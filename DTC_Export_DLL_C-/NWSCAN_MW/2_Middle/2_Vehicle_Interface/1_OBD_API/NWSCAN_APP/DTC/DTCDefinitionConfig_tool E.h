/*
* DTCDefinitionConfig.h
*
*  Created on: Jul 29, 2015
*      Author: Lap Dang
*/

#ifndef DTCDEFINITIONCONFIG_H_
#define DTCDEFINITIONCONFIG_H_

#define SUPPORTED_TOOL_3100J    1

#define DEF_VALID(a)    (a==0xffff?0:1)

#define _SUPPORTED_DTC_DEF_BMW    1
#define _SUPPORTED_DTC_DEF_VOLKSWAGEN    1
#define _SUPPORTED_DTC_DEF_CHRYSLER    1
#define _SUPPORTED_DTC_DEF_FORD    1
#define _SUPPORTED_DTC_DEF_GM    1
#define _SUPPORTED_DTC_DEF_HONDA    1
#define _SUPPORTED_DTC_DEF_HYUNDAI    1
#define _SUPPORTED_DTC_DEF_MAZDA    1
#define _SUPPORTED_DTC_DEF_MERCEDES_BENZ    1
#define _SUPPORTED_DTC_DEF_NISSAN    1
#define _SUPPORTED_DTC_DEF_TOYOTA    1
#define _SUPPORTED_DTC_DEF_VOLVO    1
#define _SUPPORTED_DTC_DEF_SUBARU    0
#define _SUPPORTED_DTC_DEF_SUZUKI    1
#define _SUPPORTED_DTC_DEF_PORSCHE    0
#define _SUPPORTED_DTC_DEF_ISUZU    0
#define _SUPPORTED_DTC_DEF_JAGUAR    0
#define _SUPPORTED_DTC_DEF_JAGUAR_LAND_ROVER    1
#define _SUPPORTED_DTC_DEF_MITSUBISHI    1
#define _SUPPORTED_DTC_DEF_DAEWOO    0
#define _SUPPORTED_DTC_DEF_FAW    0
#define _SUPPORTED_DTC_DEF_FIAT    1
#define _SUPPORTED_DTC_DEF_MG    0
#define _SUPPORTED_DTC_DEF_PEUGEOT    0
#define _SUPPORTED_DTC_DEF_SSANGYONG    0
#define _SUPPORTED_DTC_DEF_RENAULT    1
#define _SUPPORTED_DTC_DEF_TRUCK    1

#define _USED_LIB_MAKE(x)	uint32 gf_##x##_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,\
                                                                   structOemProfile *p_strtOemProfile,\
                                                                   enumOBDLanguage eMemLanguage,\
                                                                   structListDTCType *pstrtListDTCType,\
                                                                   void *pDef,\
                                                                   uint32 iDefSize,\
                                                                   structListAddressDTC* pstrtListAddrDTC);

#if _SUPPORTED_DTC_DEF_BMW
_USED_LIB_MAKE(BMW)
#endif
#if _SUPPORTED_DTC_DEF_VOLKSWAGEN
_USED_LIB_MAKE(VOLKSWAGEN)
#endif
#if _SUPPORTED_DTC_DEF_CHRYSLER
_USED_LIB_MAKE(CHRYSLER)
#endif
#if _SUPPORTED_DTC_DEF_FORD
_USED_LIB_MAKE(FORD)
#endif
#if _SUPPORTED_DTC_DEF_GM
_USED_LIB_MAKE(GM)
#endif
#if _SUPPORTED_DTC_DEF_HONDA
_USED_LIB_MAKE(HONDA)
#endif
#if _SUPPORTED_DTC_DEF_HYUNDAI
_USED_LIB_MAKE(HYUNDAI)
#endif
#if _SUPPORTED_DTC_DEF_KIA
_USED_LIB_MAKE(KIA)
#endif
#if _SUPPORTED_DTC_DEF_MAZDA
_USED_LIB_MAKE(MAZDA)
#endif
#if _SUPPORTED_DTC_DEF_MERCEDES_BENZ
_USED_LIB_MAKE(MERCEDES_BENZ)
#endif
#if _SUPPORTED_DTC_DEF_NISSAN
_USED_LIB_MAKE(NISSAN)
#endif
#if _SUPPORTED_DTC_DEF_TOYOTA
_USED_LIB_MAKE(TOYOTA)
#endif
#if _SUPPORTED_DTC_DEF_VOLVO
_USED_LIB_MAKE(VOLVO)
#endif
#if _SUPPORTED_DTC_DEF_SUBARU
_USED_LIB_MAKE(SUBARU)
#endif
#if _SUPPORTED_DTC_DEF_SUZUKI
_USED_LIB_MAKE(SUZUKI)
#endif
#if _SUPPORTED_DTC_DEF_PORSCHE
_USED_LIB_MAKE(PORSCHE)
#endif
#if _SUPPORTED_DTC_DEF_ISUZU
_USED_LIB_MAKE(ISUZU)
#endif
#if _SUPPORTED_DTC_DEF_JAGUAR
_USED_LIB_MAKE(JAGUAR)
#endif
#if _SUPPORTED_DTC_DEF_JAGUAR_LAND_ROVER
_USED_LIB_MAKE(JAGUAR_LAND_ROVER)
#endif
#if _SUPPORTED_DTC_DEF_MITSUBISHI
_USED_LIB_MAKE(MITSUBISHI)
#endif
#if _SUPPORTED_DTC_DEF_DAEWOO
_USED_LIB_MAKE(DAEWOO)
#endif
#if _SUPPORTED_DTC_DEF_FAW
_USED_LIB_MAKE(FAW)
#endif
#if _SUPPORTED_DTC_DEF_FIAT
_USED_LIB_MAKE(FIAT)
#endif
#if _SUPPORTED_DTC_DEF_MG
_USED_LIB_MAKE(MG)
#endif
#if _SUPPORTED_DTC_DEF_PEUGEOT
_USED_LIB_MAKE(PEUGEOT)
#endif
#if _SUPPORTED_DTC_DEF_SSANGYONG
_USED_LIB_MAKE(SSANGYONG)
#endif
#if _SUPPORTED_DTC_DEF_RENAULT
_USED_LIB_MAKE(RENAULT)
#endif
#if _SUPPORTED_DTC_DEF_TRUCK
_USED_LIB_MAKE(GLOBAL_TRUCK)
#endif


uint32 gf_Default_Adapter_DTC_GetDef(structMFRVinProfile * p_strtMFRVinProfile,
                                     structOemProfile *p_strtOemProfile,
                                     enumOBDLanguage eMemLanguage,
                                     structListDTCType *pstrtListDTCType,
                                     void *pDef,
                                     uint32 iDefSize,
                                     structListAddressDTC* pstrtListAddrDTC);
#define BASESIZE_MAIN_DTC 45

#define FORD_use_sManufacturer                1
#define FORD_use_sModel                0
#define FORD_use_sSystem                1
#define FORD_use_sSubSystem                0
#define FORD_use_sProtocol                1

#define GM_use_sManufacturer                1
#define GM_use_sModel                1
#define GM_use_sSystem                0
#define GM_use_sSubSystem                0
#define GM_use_sProtocol                1

#define CHRYSLER_use_sManufacturer                1
#define CHRYSLER_use_sModel                0
#define CHRYSLER_use_sSystem                1
#define CHRYSLER_use_sSubSystem                1
#define CHRYSLER_use_sProtocol                1

#define HONDA_use_sManufacturer                1
#define HONDA_use_sModel                1
#define HONDA_use_sSystem                1
#define HONDA_use_sSubSystem                1
#define HONDA_use_sProtocol                1

#define TOYOTA_use_sManufacturer                1
#define TOYOTA_use_sModel                0
#define TOYOTA_use_sSystem                0
#define TOYOTA_use_sSubSystem                0
#define TOYOTA_use_sProtocol                0

#define HYUNDAI_use_sManufacturer                1
#define HYUNDAI_use_sModel                0
#define HYUNDAI_use_sSystem                0
#define HYUNDAI_use_sSubSystem                1
#define HYUNDAI_use_sProtocol                0

#define NISSAN_use_sManufacturer                1
#define NISSAN_use_sModel                0
#define NISSAN_use_sSystem                0
#define NISSAN_use_sSubSystem                1
#define NISSAN_use_sProtocol                1

#define MAZDA_use_sManufacturer                1
#define MAZDA_use_sModel                0
#define MAZDA_use_sSystem                0
#define MAZDA_use_sSubSystem                0
#define MAZDA_use_sProtocol                0

#define MERCEDES_use_sManufacturer                1
#define MERCEDES_use_sModel                0
#define MERCEDES_use_sSystem                0
#define MERCEDES_use_sSubSystem                0
#define MERCEDES_use_sProtocol                0
#define MERCEDES_eOption2                eMFR_FIELD_BodyCode

#define VOLVO_use_sManufacturer                1
#define VOLVO_use_sModel                1
#define VOLVO_use_sSystem                1
#define VOLVO_use_sSubSystem                0
#define VOLVO_use_sProtocol                1
#define VOLVO_eOption1                eMFR_FIELD_Engine

#define BMW_use_sManufacturer                1
#define BMW_use_sModel                       0
#define BMW_use_sSystem                      0
#define BMW_use_sSubSystem                   0
#define BMW_use_sProtocol                    0

#define VOLKSWAGEN_use_sManufacturer         1
#define VOLKSWAGEN_use_sModel                1
#define VOLKSWAGEN_use_sSystem               1
#define VOLKSWAGEN_use_sSubSystem            1
#define VOLKSWAGEN_use_sProtocol             0

#define FIAT_use_sManufacturer                1
#define FIAT_use_sModel                       0
#define FIAT_use_sSystem                      1
#define FIAT_use_sSubSystem                   1
#define FIAT_use_sProtocol                    0

#define JAGUAR_LAND_ROVER_use_bYear                        1
#define JAGUAR_LAND_ROVER_use_sManufacturer                1
#define JAGUAR_LAND_ROVER_use_sModel                       1
#define JAGUAR_LAND_ROVER_use_sSystem                      1
#define JAGUAR_LAND_ROVER_use_sSubSystem                   0
#define JAGUAR_LAND_ROVER_use_sProtocol                    0

#define MITSUBISHI_use_bYear                        0
#define MITSUBISHI_use_sManufacturer                1
#define MITSUBISHI_use_sModel                       0
#define MITSUBISHI_use_sSystem                      0
#define MITSUBISHI_use_sSubSystem                   0
#define MITSUBISHI_use_sProtocol                    0

#define TRUCK_use_bYear                        0
#define TRUCK_use_sManufacturer                1
#define TRUCK_use_sModel                       0
#define TRUCK_use_sSystem                      1
#define TRUCK_use_sSubSystem                   0
#define TRUCK_use_sProtocol                    1

#define SUZUKI_use_bYear                        0
#define SUZUKI_use_sManufacturer                1
#define SUZUKI_use_sModel                       0
#define SUZUKI_use_sSystem                      0
#define SUZUKI_use_sSubSystem                   0
#define SUZUKI_use_sProtocol                    1

#define RENAULT_use_bYear                       0
#define RENAULT_use_sManufacturer               1
#define RENAULT_use_sModel                      0
#define RENAULT_use_sSystem                     0
#define RENAULT_use_sSubSystem                  1
#define RENAULT_use_sProtocol                   0

#ifdef _DTC_DEF_DEFAULT_CONFIG_C_




#define __ADAPTER_DTC(MAKE,make,NameLib)	{ .sID=emanufacturer_##MAKE,\
                                                  .pString=#make,\
                                                  .gf_Vehicle_Adapter_DTC_GetDef=gf_##NameLib##_Adapter_DTC_GetDef,\
                                                  .IsUseGenericExt=eTRUE\
                                                }

#define __ADAPTER_DTC_Custom(MAKE,make,NameLib,IsUseGeneric)	{.sID=emanufacturer_##MAKE,\
                                                                 .pString=#make,\
                                                                 .gf_Vehicle_Adapter_DTC_GetDef=gf_##NameLib##_Adapter_DTC_GetDef,\
                                                                 .IsUseGenericExt=IsUseGeneric\
                                                                 }

const structDtcInfoPath ROM_dtcinfo_Manuf_map[] = {
__ADAPTER_DTC(BMW,bmw,BMW),
__ADAPTER_DTC(Volkswagen,audi&vw,VOLKSWAGEN),
__ADAPTER_DTC_Custom(Chrysler,chrysler,CHRYSLER,eFALSE),
__ADAPTER_DTC(Ford,ford,FORD),
__ADAPTER_DTC(GM,gm,GM),
__ADAPTER_DTC(Honda,honda,HONDA),
__ADAPTER_DTC(Hyundai,hyundai-kia,HYUNDAI),
__ADAPTER_DTC(Mazda,mazda,MAZDA),
__ADAPTER_DTC_Custom(Mercedes_Benz,mercedes,MERCEDES_BENZ,eFALSE),
//__ADAPTER_DTC(Nissan,nissan&infiniti,NISSAN),
__ADAPTER_DTC_Custom(Nissan,nissan&infiniti,NISSAN,eFALSE),
__ADAPTER_DTC_Custom(Toyota,toyota,TOYOTA,eFALSE),
__ADAPTER_DTC(Volvo,volvo,VOLVO),
__ADAPTER_DTC(Subaru,subaru,Default),
__ADAPTER_DTC(Suzuki,suzuki,SUZUKI),
__ADAPTER_DTC(Porsche,porsche,Default),
__ADAPTER_DTC(Isuzu,isuzu,Default),
__ADAPTER_DTC(Mitsubishi,mitsubishi,MITSUBISHI),
__ADAPTER_DTC(Faw,faw,Default),
__ADAPTER_DTC(Fiat,fiat,FIAT),
__ADAPTER_DTC(Jaguar_____Land_____Rover,jaguar_land_rover,JAGUAR_LAND_ROVER),
__ADAPTER_DTC(Daewoo,daewoo,Default),
__ADAPTER_DTC(Renault,renault,RENAULT),
__ADAPTER_DTC(Peugeot,peugeot,Default),
__ADAPTER_DTC(MG,mg,Default),
__ADAPTER_DTC(Ssangyong,ssangyong,Default),
__ADAPTER_DTC(GlobalTruck,globaltruck,GLOBAL_TRUCK),
  {
    emanufacturer_MAX, "generic"
  }, 
  {
    emanufacturer_UNKNOWN, 0
  }
};

const structDTCYmmeUsing strtDTCYmmeUsing[] =
{
  {
    .sVehicle = emanufacturer_Peugeot,
    .use_sManufacturer = eTRUE,
    .use_sModel = eFALSE,
    .use_sSystem = eFALSE,
    .use_sSubSystem = eFALSE,
    .use_sProtocol = eFALSE,
  },
  {
    .sVehicle = emanufacturer_Ssangyong,
    .use_sManufacturer = eTRUE,
    .use_sModel = eFALSE,
    .use_sSystem = eFALSE,
    .use_sSubSystem = eFALSE,
    .use_sProtocol = eFALSE,
  },
  {
    .sVehicle = emanufacturer_MG,
    .use_sManufacturer = eTRUE,
    .use_sModel = eFALSE,
    .use_sSystem = eFALSE,
    .use_sSubSystem = eFALSE,
    .use_sProtocol = eFALSE,
  },
//  {
//    .sVehicle = emanufacturer_MAZDA,
//    .use_sManufacturer = eTRUE,
//    .use_sModel = eFALSE,
//    .use_sSystem = eFALSE,
//    .use_sSubSystem = eFALSE,
//    .use_sProtocol = eFALSE,
//  },
//  {
//    .sVehicle = emanufacturer_MERCEDES_BENZ,
//    .use_sManufacturer = eTRUE,
//    .use_sModel = eFALSE,
//    .use_sSystem = eFALSE,
//    .use_sSubSystem = eFALSE,
//    .use_sProtocol = eFALSE,
//    .eOption2 = eMFR_FIELD_BodyCode,
//  },
//  {
//    .sVehicle = emanufacturer_VOLVO,
//    .use_sManufacturer = eTRUE,
//    .use_sModel = eTRUE,
//    .use_sSystem = eTRUE,
//    .use_sSubSystem = eFALSE,
//    .use_sProtocol = eTRUE,
//    .eOption1 = eMFR_FIELD_Engine,
//  },
//  {
//    .sVehicle = emanufacturer_BMW,
//    .use_sManufacturer = eTRUE,
//    .use_sModel =eFALSE,
//    .use_sSystem = eFALSE,
//    .use_sSubSystem = eFALSE,
//    .use_sProtocol = eFALSE,
//  },
//  {
//    .sVehicle = emanufacturer_VOLKSWAGEN,
//    .use_sManufacturer = eTRUE,
//    .use_sModel = eTRUE,
//    .use_sSystem = eTRUE,
//    .use_sSubSystem = eTRUE,
//    .use_sProtocol = eFALSE,
//  },
  {
    .sVehicle = emanufacturer_UNKNOWN, 
    .use_sManufacturer = eFALSE, 
    .use_sModel = eFALSE, 
    .use_sSystem = eFALSE, 
    .use_sSubSystem = eFALSE, 
    .use_sProtocol = eFALSE, 
  },
};
#else
//extern const structDTCYmmeUsing strtDTCYmmeUsing[];
extern const structDtcInfoPath ROM_dtcinfo_inngrp_map[];
extern const structDtcInfoPath ROM_dtcinfo_Manuf_map[];
#endif



#endif /* DTCDEFINITIONCONFIG_H_ */
