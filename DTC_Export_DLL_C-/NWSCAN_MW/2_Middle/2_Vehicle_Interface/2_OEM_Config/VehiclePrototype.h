#ifndef _VEHICLEPROTOTYPE_H_
#define _VEHICLEPROTOTYPE_H_

#ifdef _ENABLE_ABS_SRS_LIGHT
extern void InitNissanAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitNissanAbsStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitHondaAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitHondaAbsStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitChryslerAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitChryslerAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitGmAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitGmAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitBmwAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitBmwAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitFordAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitFordAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitMercedesAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitMercedesAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitHyundaiAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitHyundaiAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitKiaAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitKiaAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitToyotaAbsStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitVolkswagenAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitVolkswagenAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
extern void InitVolvoAbsStatusProfile(structControllerProfile * p_strtAbsStatusCtrl);
extern void InitVolvoAirbagStatusProfile(structControllerProfile * p_strtAirbagStatusCtrl);
#endif

typedef void (*Init_X_Profile)(structControllerProfile * strtControllerProfile);
#ifdef __OEM_SETUP_C

extern void gf_OBDLiveDataLink(structLinkProfile * p_strtLinkProfile);

extern void InitAlfaromeoEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAlfaromeoTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAlfaromeoAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitAlfaromeoSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitAm_GeneralEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAm_GeneralTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAm_GeneralAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitAm_GeneralSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitAmcEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAmcTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAmcAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitAmcSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitAston_MartinEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAston_MartinTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitAston_MartinAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitAston_MartinSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitBentleyEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBentleyTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBentleyAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitBentleySrsProfile(structControllerProfile * strtControllerProfile);
extern void InitBmwEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBmwTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBmwAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitBmwSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitBrillianceEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBrillianceTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBrillianceAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitBrillianceSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitBugattiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBugattiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBugattiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitBugattiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitBydEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBydTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitBydAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitBydSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitChanaEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChanaTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChanaAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitChanaSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitChangfengEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChangfengTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChangfengAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitChangfengSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitChery_AutoEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChery_AutoTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChery_AutoAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitChery_AutoSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitDaewooEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitDaewooTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitDaewooAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitDaewooSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitDaihatsuEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitDaihatsuTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitDaihatsuAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitDaihatsuSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitDeloreanEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitDeloreanTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitDeloreanAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitDeloreanSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitEagleEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitEagleTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitEagleAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitEagleSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFawEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFawTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFawAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFawSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFaw_VwEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFaw_VwTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFaw_VwAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFaw_VwSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFerrariEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFerrariTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFerrariAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFerrariSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFiatEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFiatTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFiatAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFiatSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFordEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFordTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFordAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFordSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFreightlinerEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFreightlinerTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFreightlinerAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFreightlinerSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitGeelyEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGeelyTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGeelyAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitGeelySrsProfile(structControllerProfile * strtControllerProfile);
extern void InitGmEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGmTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGmAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitGmSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitGreatWallEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGreatWallTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGreatWallAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitGreatWallSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitHafeiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHafeiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHafeiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitHafeiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitHondaEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHondaTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHondaAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitHondaSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitGmEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGmTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitGmAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitGmSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitJacEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitJacTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitJacAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitJacSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitJaguarEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitJaguarTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitJaguarAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitJaguarSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitChryslerSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitHyundaiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitLamborghiniEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLamborghiniTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLamborghiniAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitLamborghiniSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitLandroverEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLandroverTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLandroverAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitLandroverSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitLifanEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLifanTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLifanAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitLifanSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitLotusEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLotusTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitLotusAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitLotusSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitMaseratiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMaseratiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMaseratiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitMaseratiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitMatrixEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMatrixTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMatrixAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitMatrixSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitFordEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFordTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitFordAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitFordSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitMercedesEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMercedesTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMercedesAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitMercedesSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitMerkurEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMerkurTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMerkurAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitMerkurSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitMesacEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMesacTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMesacAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitMesacSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitMitsubishiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMitsubishiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitMitsubishiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitMitsubishiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitNissanEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitNissanTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitNissanAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitNissanSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitOpelEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitOpelTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitOpelAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitOpelSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitPassportEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPassportTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPassportAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitPassportSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitPeugeotSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitPorscheEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPorscheTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitPorscheAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitPorscheSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitRenaultEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitRenaultTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitRenaultAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitRenaultSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitRolls_RoyceEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitRolls_RoyceTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitRolls_RoyceAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitRolls_RoyceSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitSaabEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSaabTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSaabAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitSaabSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitSmartEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSmartTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSmartAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitSmartSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitSouestEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSouestTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSouestAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitSouestSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitSterlingEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSterlingTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSterlingAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitSterlingSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitSubaruEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSubaruTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSubaruAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitSubaruSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitSuzukiEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSuzukiTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitSuzukiAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitSuzukiSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitTeslaEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitTeslaTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitTeslaAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitTeslaSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitThinkEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitThinkTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitThinkAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitThinkSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitTiamaEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitTiamaTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitTiamaAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitTiamaSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitToyotaEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitToyotaTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitToyotaAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitToyotaSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolkswagenSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolvoEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolvoTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitVolvoAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitVolvoSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitWulingEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitWulingTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitWulingAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitWulingSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitYugoEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitYugoTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitYugoAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitYugoSrsProfile(structControllerProfile * strtControllerProfile);
extern void InitCitroenEcmProfile(structControllerProfile * strtControllerProfile);
extern void InitCitroenTcmProfile(structControllerProfile * strtControllerProfile);
extern void InitCitroenAbsProfile(structControllerProfile * strtControllerProfile);
extern void InitCitroenSrsProfile(structControllerProfile * strtControllerProfile);

extern void InitGmEnhanceProfile(structVehicleProfile * pstrtVehicleProfile);
extern void InitFordEnhanceProfile(structVehicleProfile * pstrtVehicleProfile);
extern void InitChryslerEnhanceProfile(structVehicleProfile * pstrtVehicleProfile);
extern void InitToyotaEnhanceProfile(structVehicleProfile * pstrtVehicleProfile);
extern void InitHondaEnhanceProfile(structVehicleProfile * pstrtVehicleProfile);

extern void InitGMOBD1Profile(structControllerProfile * strtControllerProfile);
extern void InitFordOBD1Profile(structControllerProfile * strtControllerProfile);
extern void InitChryslerOBD1Profile(structControllerProfile * strtControllerProfile);
extern void InitToyotaOBD1Profile(structControllerProfile * strtControllerProfile);
extern void InitHondaOBD1Profile(structControllerProfile * strtControllerProfile);

extern void InitNopEcmTcmProfile(structControllerProfile * strtControllerProfile);
/*Creat Group*/
#ifdef _SUPPORT_FORD
#ifndef _SUPPORT_MAZDA
#define _SUPPORT_MAZDA
#endif
#warning group FORD-MAZDA
#endif
#ifdef _SUPPORT_CHRYSLER
#ifndef _SUPPORT_JEEP
#define _SUPPORT_JEEP
#endif
#warning group CHRYSLER-JEEP
#endif
#ifdef _SUPPORT_GM
#ifndef _SUPPORT_ISUZU
#define _SUPPORT_ISUZU
#endif
#warning group GM-ISUZU
#endif
#ifdef _SUPPORT_PEUGEOT
#ifndef _SUPPORT_CITROEN
#define _SUPPORT_CITROEN
#endif
#warning group PEUGEOT-CITROEN
#endif
#ifdef _SUPPORT_HYUNDAI
#ifndef _SUPPORT_KIA
#define _SUPPORT_KIA
#endif
#warning group HYUNDAI-KIA
#endif
#ifdef _SUPPORT_VOLKSWAGEN
#ifndef _SUPPORT_AUDI
#define _SUPPORT_AUDI
#endif
#ifndef _SUPPORT_SEAT
#define _SUPPORT_SEAT
#endif
#warning group VOLKSWAGEN-AUDI-SEAT
#endif
typedef void (*Init_X_Enhanced_Profile)(structVehicleProfile * pstrtVehicleProfile);
typedef struct _structVehicleModule
{
    enumVehicle    eVehicle;
    Init_X_Profile Init_X_Ecm_Profile;
    Init_X_Profile Init_X_Tcm_Profile;
    Init_X_Profile Init_X_Abs_Profile;
    Init_X_Profile Init_X_Srs_Profile;
    p_ROM_Str      pVersion;
} structVehicleModule;

#ifdef _ENABLE_ABS_SRS_LIGHT
typedef struct _structVehicleAbsSrsLight
{
    enumVehicle    eVehicle;
    Init_X_Profile Init_X_Airbagstatus_Profile;
    Init_X_Profile Init_X_Absstatus_Profile;
} structVehicleAbsSrsLight;
#endif

#ifdef __OEM_SETUP_C
#warning pending add every version to file .h
ROM_Str pAlfaromeoVersion[] =     "V01.00.06";
ROM_Str pAm_GeneralVersion[] =     "V01.00.06";
ROM_Str pAmcVersion[] =     "V01.00.06";
ROM_Str pAston_MartinVersion[] =     "V01.00.06";
ROM_Str pAudiVersion[] =     "V01.00.06";
ROM_Str pBentleyVersion[] =     "V01.00.00";
ROM_Str pBmwVersion[] =     "V01.00.07";
ROM_Str pBrillianceVersion[] =     "V01.00.06";
ROM_Str pBugattiVersion[] =     "V01.00.00";
ROM_Str pBydVersion[] =     "V01.00.06";
ROM_Str pChanaVersion[] =     "V01.00.06";
ROM_Str pChangfengVersion[] =     "V01.00.06";
ROM_Str pChery_AutoVersion[] =     "V01.00.06";
ROM_Str pChryslerVersion[] =     "V01.00.06";
ROM_Str pCitroenVersion[] =     "V01.00.06";
ROM_Str pDaewooVersion[] =     "V01.00.00";
ROM_Str pDaihatsuVersion[] =     "V01.00.06";
ROM_Str pDeloreanVersion[] =     "V01.00.00";
ROM_Str pEagleVersion[] =     "V01.00.00";
ROM_Str pFawVersion[] =     "V01.00.06";
ROM_Str pFaw_VwVersion[] =     "V01.00.00";
ROM_Str pFerrariVersion[] =     "V01.00.00";
ROM_Str pFiatVersion[] =     "V01.00.01";
ROM_Str pFordVersion[] =     "V01.00.06";
ROM_Str pFreightlinerVersion[] =     "V01.00.00";
ROM_Str pGeelyVersion[] =     "V01.00.00";
ROM_Str pGmVersion[] =     "V01.00.07";
ROM_Str pGreatwallVersion[] =     "V01.00.00";
ROM_Str pHafeiVersion[] =     "V01.00.00";
ROM_Str pHondaVersion[] =     "V01.00.07";
ROM_Str pHyundaiVersion[] =     "V01.00.07";
ROM_Str pIsuzuVersion[] =     "V01.00.00";
ROM_Str pJacVersion[] =     "V01.00.00";
ROM_Str pJaguarVersion[] =     "V01.00.00";
ROM_Str pJeepVersion[] =     "V01.00.00";
ROM_Str pKiaVersion[] =     "V01.00.00";
ROM_Str pLamborghiniVersion[] =     "V01.00.00";
ROM_Str pLandroverVersion[] =     "V01.00.00";
ROM_Str pLifanVersion[] =     "V01.00.00";
ROM_Str pLotusVersion[] =     "V01.00.00";
ROM_Str pMaseratiVersion[] =     "V01.00.00";
ROM_Str pMatrixVersion[] =     "V01.00.00";
ROM_Str pMazdaVersion[] =     "V01.00.06";
ROM_Str pMercedesVersion[] =     "V01.00.07";
ROM_Str pMerkurVersion[] =     "V01.00.00";
ROM_Str pMesacVersion[] =     "V01.00.00";
ROM_Str pMitsubishiVersion[] =     "V01.00.07";
ROM_Str pNissanVersion[] =     "V01.00.07";
ROM_Str pOpelVersion[] =     "V01.00.06";
ROM_Str pPassportVersion[] =     "V01.00.00";
ROM_Str pPeugeotVersion[] =     "V01.00.06";
ROM_Str pPorscheVersion[] =     "V01.00.00";
ROM_Str pRenaultVersion[] =     "V01.00.06";
ROM_Str pRolls_RoyceVersion[] =     "V01.00.00";
ROM_Str pSaabVersion[] =     "V01.00.00";
ROM_Str pSeatVersion[] =     "V01.00.06";
ROM_Str pSmartVersion[] =     "V01.00.00";
ROM_Str pSouestVersion[] =     "V01.00.00";
ROM_Str pSterlingVersion[] =     "V01.00.00";
ROM_Str pSubaruVersion[] =     "V01.00.01";
ROM_Str pSuzukiVersion[] =     "V01.00.06";
ROM_Str pTeslaVersion[] =     "V01.00.00";
ROM_Str pThinkVersion[] =     "V01.00.00";
ROM_Str pTiamaVersion[] =     "V01.00.00";
ROM_Str pToyotaVersion[] =     "V01.00.07";
ROM_Str pVolkswagenVersion[] =     "V01.00.06";
ROM_Str pVolvoVersion[] =     "V01.00.06";
ROM_Str pWulingVersion[] =     "V01.00.06";
ROM_Str pYugoVersion[] =     "V01.00.00";
#endif
structVehicleModule strtVehicleModule[]=
{
#ifdef _SUPPORT_ALFAROMEO
    {ALFAROMEO    ,InitAlfaromeoEcmProfile    ,InitAlfaromeoTcmProfile    ,InitAlfaromeoAbsProfile    ,InitAlfaromeoSrsProfile    ,pAlfaromeoVersion },
#endif
#ifdef _SUPPORT_AM_GENERAL
    {AM_GENERAL   ,InitAm_GeneralEcmProfile   ,InitAm_GeneralTcmProfile   ,InitAm_GeneralAbsProfile   ,InitAm_GeneralSrsProfile   ,pAm_GeneralVersion },
#endif
#ifdef _SUPPORT_AMC
    {AMC          ,InitAmcEcmProfile          ,InitAmcTcmProfile          ,InitAmcAbsProfile          ,InitAmcSrsProfile          ,pAmcVersion },
#endif
#ifdef _SUPPORT_ASTON_MARTIN
    {ASTON_MARTIN ,InitAston_MartinEcmProfile ,InitAston_MartinTcmProfile ,InitAston_MartinAbsProfile ,InitAston_MartinSrsProfile ,pAston_MartinVersion },
#endif
#ifdef _SUPPORT_AUDI
    {AUDI         ,InitVolkswagenEcmProfile   ,InitVolkswagenTcmProfile   ,InitVolkswagenAbsProfile   ,InitVolkswagenSrsProfile   ,pAudiVersion },
#endif
#ifdef _SUPPORT_BENTLEY
    {BENTLEY      ,InitBentleyEcmProfile      ,InitBentleyTcmProfile      ,InitBentleyAbsProfile      ,InitBentleySrsProfile      ,pBentleyVersion },
#endif
#ifdef _SUPPORT_BMW
    {BMW          ,InitBmwEcmProfile          ,InitBmwTcmProfile          ,InitBmwAbsProfile          ,InitBmwSrsProfile          ,pBmwVersion },
#endif
#ifdef _SUPPORT_BRILLIANCE
    {BRILLIANCE   ,InitBrillianceEcmProfile   ,InitBrillianceTcmProfile   ,InitBrillianceAbsProfile   ,InitBrillianceSrsProfile   ,pBrillianceVersion },
#endif
#ifdef _SUPPORT_BUGATTI
    {BUGATTI      ,InitBugattiEcmProfile      ,InitBugattiTcmProfile      ,InitBugattiAbsProfile      ,InitBugattiSrsProfile      ,pBugattiVersion },
#endif
#ifdef _SUPPORT_BYD
    {BYD          ,InitBydEcmProfile          ,InitBydTcmProfile          ,InitBydAbsProfile          ,InitBydSrsProfile          ,pBydVersion },
#endif
#ifdef _SUPPORT_CHANA
    {CHANA        ,InitChanaEcmProfile        ,InitChanaTcmProfile        ,InitChanaAbsProfile        ,InitChanaSrsProfile        ,pChanaVersion },
#endif
#ifdef _SUPPORT_CHANGFENG
    {CHANGFENG    ,InitChangfengEcmProfile    ,InitChangfengTcmProfile    ,InitChangfengAbsProfile    ,InitChangfengSrsProfile    ,pChangfengVersion },
#endif
#ifdef _SUPPORT_CHERY_AUTO
    {CHERY_AUTO   ,InitChery_AutoEcmProfile   ,InitChery_AutoTcmProfile   ,InitChery_AutoAbsProfile   ,InitChery_AutoSrsProfile   ,pChery_AutoVersion },
#endif
#ifdef _SUPPORT_CHRYSLER
    {CHRYSLER     ,InitChryslerEcmProfile     ,InitChryslerTcmProfile     ,InitChryslerAbsProfile     ,InitChryslerSrsProfile     ,pChryslerVersion },
#endif
#ifdef _SUPPORT_CITROEN
    {CITROEN      ,InitCitroenEcmProfile      ,InitCitroenTcmProfile      ,InitCitroenAbsProfile      ,InitCitroenSrsProfile      ,pCitroenVersion },
#endif
#ifdef _SUPPORT_DAEWOO
    {DAEWOO       ,InitDaewooEcmProfile       ,InitDaewooTcmProfile       ,InitDaewooAbsProfile       ,InitDaewooSrsProfile       ,pDaewooVersion },
#endif
#ifdef _SUPPORT_DAIHATSU
    {DAIHATSU     ,InitDaihatsuEcmProfile     ,InitDaihatsuTcmProfile     ,InitDaihatsuAbsProfile     ,InitDaihatsuSrsProfile     ,pDaihatsuVersion },
#endif
#ifdef _SUPPORT_DELOREAN
    {DELOREAN     ,InitDeloreanEcmProfile     ,InitDeloreanTcmProfile     ,InitDeloreanAbsProfile     ,InitDeloreanSrsProfile     ,pDeloreanVersion },
#endif
#ifdef _SUPPORT_EAGLE
    {EAGLE        ,InitEagleEcmProfile        ,InitEagleTcmProfile        ,InitEagleAbsProfile        ,InitEagleSrsProfile        ,pEagleVersion },
#endif
#ifdef _SUPPORT_FAW
    {FAW          ,InitFawEcmProfile          ,InitFawTcmProfile          ,InitFawAbsProfile          ,InitFawSrsProfile          ,pFawVersion },
#endif
#ifdef _SUPPORT_FAW_VW
    {FAW_VW       ,InitFaw_VwEcmProfile       ,InitFaw_VwTcmProfile       ,InitFaw_VwAbsProfile       ,InitFaw_VwSrsProfile       ,pFaw_VwVersion },
#endif
#ifdef _SUPPORT_FERRARI
    {FERRARI      ,InitFerrariEcmProfile      ,InitFerrariTcmProfile      ,InitFerrariAbsProfile      ,InitFerrariSrsProfile      ,pFerrariVersion },
#endif
#ifdef _SUPPORT_FIAT
    {FIAT         ,InitFiatEcmProfile         ,InitFiatTcmProfile         ,InitFiatAbsProfile         ,InitFiatSrsProfile         ,pFiatVersion },
#endif
#ifdef _SUPPORT_FORD
    {FORD         ,InitFordEcmProfile         ,InitFordTcmProfile         ,InitFordAbsProfile         ,InitFordSrsProfile         ,pFordVersion },
#endif
#ifdef _SUPPORT_FREIGHTLINER
    {FREIGHTLINER ,InitFreightlinerEcmProfile ,InitFreightlinerTcmProfile ,InitFreightlinerAbsProfile ,InitFreightlinerSrsProfile ,pFreightlinerVersion },
#endif
#ifdef _SUPPORT_GEELY
    {GEELY        ,InitGeelyEcmProfile        ,InitGeelyTcmProfile        ,InitGeelyAbsProfile        ,InitGeelySrsProfile        ,pGeelyVersion },
#endif
#ifdef _SUPPORT_GM
    {GM           ,InitGmEcmProfile           ,InitGmTcmProfile           ,InitGmAbsProfile           ,InitGmSrsProfile           ,pGmVersion },
#endif
#ifdef _SUPPORT_GREATWALL
    {GREATWALL    ,InitGreatWallEcmProfile    ,InitGreatWallTcmProfile    ,InitGreatWallAbsProfile    ,InitGreatWallSrsProfile    ,pGreatwallVersion },
#endif
#ifdef _SUPPORT_HAFEI
    {HAFEI        ,InitHafeiEcmProfile        ,InitHafeiTcmProfile        ,InitHafeiAbsProfile        ,InitHafeiSrsProfile        ,pHafeiVersion },
#endif
#ifdef _SUPPORT_HONDA
    {HONDA        ,InitHondaEcmProfile        ,InitHondaTcmProfile        ,InitHondaAbsProfile        ,InitHondaSrsProfile        ,pHondaVersion },
#endif
#ifdef _SUPPORT_HYUNDAI
    {HYUNDAI      ,InitHyundaiEcmProfile      ,InitHyundaiTcmProfile      ,InitHyundaiAbsProfile      ,InitHyundaiSrsProfile      ,pHyundaiVersion },
#endif
#ifdef _SUPPORT_ISUZU
    {ISUZU        ,InitGmEcmProfile           ,InitGmTcmProfile           ,InitGmAbsProfile           ,InitGmSrsProfile           ,pIsuzuVersion },
#endif
#ifdef _SUPPORT_JAC
    {JAC          ,InitJacEcmProfile          ,InitJacTcmProfile          ,InitJacAbsProfile          ,InitJacSrsProfile          ,pJacVersion },
#endif
#ifdef _SUPPORT_JAGUAR
    {JAGUAR       ,InitJaguarEcmProfile       ,InitJaguarTcmProfile       ,InitJaguarAbsProfile       ,InitJaguarSrsProfile       ,pJaguarVersion },
#endif
#ifdef _SUPPORT_JEEP
    {JEEP         ,InitChryslerEcmProfile     ,InitChryslerTcmProfile     ,InitChryslerAbsProfile     ,InitChryslerSrsProfile     ,pJeepVersion },
#endif
#ifdef _SUPPORT_KIA
    {KIA          ,InitHyundaiEcmProfile      ,InitHyundaiTcmProfile      ,InitHyundaiAbsProfile      ,InitHyundaiSrsProfile      ,pKiaVersion },
#endif
#ifdef _SUPPORT_LAMBORGHINI
    {LAMBORGHINI  ,InitLamborghiniEcmProfile  ,InitLamborghiniTcmProfile  ,InitLamborghiniAbsProfile  ,InitLamborghiniSrsProfile  ,pLamborghiniVersion },
#endif
#ifdef _SUPPORT_LANDROVER
    {LANDROVER    ,InitLandroverEcmProfile    ,InitLandroverTcmProfile    ,InitLandroverAbsProfile    ,InitLandroverSrsProfile    ,pLandroverVersion },
#endif
#ifdef _SUPPORT_LIFAN
    {LIFAN        ,InitLifanEcmProfile        ,InitLifanTcmProfile        ,InitLifanAbsProfile        ,InitLifanSrsProfile        ,pLifanVersion },
#endif
#ifdef _SUPPORT_LOTUS
    {LOTUS        ,InitLotusEcmProfile        ,InitLotusTcmProfile        ,InitLotusAbsProfile        ,InitLotusSrsProfile        ,pLotusVersion },
#endif
#ifdef _SUPPORT_MASERATI
    {MASERATI     ,InitMaseratiEcmProfile     ,InitMaseratiTcmProfile     ,InitMaseratiAbsProfile     ,InitMaseratiSrsProfile     ,pMaseratiVersion },
#endif
#ifdef _SUPPORT_MATRIX
    {MATRIX       ,InitMatrixEcmProfile       ,InitMatrixTcmProfile       ,InitMatrixAbsProfile       ,InitMatrixSrsProfile       ,pMatrixVersion },
#endif
#ifdef _SUPPORT_MAZDA
    {MAZDA        ,InitFordEcmProfile         ,InitFordTcmProfile         ,InitFordAbsProfile         ,InitFordSrsProfile         ,pMazdaVersion },
#endif
#ifdef _SUPPORT_MERCEDES
    {MERCEDES     ,InitMercedesEcmProfile     ,InitMercedesTcmProfile     ,InitMercedesAbsProfile     ,InitMercedesSrsProfile     ,pMercedesVersion },
#endif
#ifdef _SUPPORT_MERKUR
    {MERKUR       ,InitMerkurEcmProfile       ,InitMerkurTcmProfile       ,InitMerkurAbsProfile       ,InitMerkurSrsProfile       ,pMerkurVersion },
#endif
#ifdef _SUPPORT_MESAC
    {MESAC        ,InitMesacEcmProfile        ,InitMesacTcmProfile        ,InitMesacAbsProfile        ,InitMesacSrsProfile        ,pMesacVersion },
#endif
#ifdef _SUPPORT_MITSUBISHI
    {MITSUBISHI   ,InitMitsubishiEcmProfile   ,InitMitsubishiTcmProfile   ,InitMitsubishiAbsProfile   ,InitMitsubishiSrsProfile   ,pMitsubishiVersion },
#endif
#ifdef _SUPPORT_NISSAN
    {NISSAN       ,InitNissanEcmProfile       ,InitNissanTcmProfile       ,InitNissanAbsProfile       ,InitNissanSrsProfile       ,pNissanVersion },
#endif
#ifdef _SUPPORT_OPEL
    {OPEL         ,InitOpelEcmProfile         ,InitOpelTcmProfile         ,InitOpelAbsProfile         ,InitOpelSrsProfile         ,pOpelVersion },
#endif
#ifdef _SUPPORT_PASSPORT
    {PASSPORT     ,InitPassportEcmProfile     ,InitPassportTcmProfile     ,InitPassportAbsProfile     ,InitPassportSrsProfile     ,pPassportVersion },
#endif
#ifdef _SUPPORT_PEUGEOT
    {PEUGEOT      ,InitPeugeotEcmProfile      ,InitPeugeotTcmProfile      ,InitPeugeotAbsProfile      ,InitPeugeotSrsProfile      ,pPeugeotVersion },
#endif
#ifdef _SUPPORT_PORSCHE
    {PORSCHE      ,InitPorscheEcmProfile      ,InitPorscheTcmProfile      ,InitPorscheAbsProfile      ,InitPorscheSrsProfile      ,pPorscheVersion },
#endif
#ifdef _SUPPORT_RENAULT
    {RENAULT      ,InitRenaultEcmProfile      ,InitRenaultTcmProfile      ,InitRenaultAbsProfile      ,InitRenaultSrsProfile      ,pRenaultVersion },
#endif
#ifdef _SUPPORT_ROLLS_ROYCE
    {ROLLS_ROYCE  ,InitRolls_RoyceEcmProfile  ,InitRolls_RoyceTcmProfile  ,InitRolls_RoyceAbsProfile  ,InitRolls_RoyceSrsProfile  ,pRolls_RoyceVersion },
#endif
#ifdef _SUPPORT_SAAB
    {SAAB         ,InitSaabEcmProfile         ,InitSaabTcmProfile         ,InitSaabAbsProfile         ,InitSaabSrsProfile         ,pSaabVersion },
#endif
#ifdef _SUPPORT_SEAT
    {SEAT         ,InitVolkswagenEcmProfile   ,InitVolkswagenTcmProfile   ,InitVolkswagenAbsProfile   ,InitVolkswagenSrsProfile   ,pSeatVersion },
#endif
#ifdef _SUPPORT_SMART
    {SMART        ,InitSmartEcmProfile        ,InitSmartTcmProfile        ,InitSmartAbsProfile        ,InitSmartSrsProfile        ,pSmartVersion },
#endif
#ifdef _SUPPORT_SOUEST
    {SOUEST       ,InitSouestEcmProfile       ,InitSouestTcmProfile       ,InitSouestAbsProfile       ,InitSouestSrsProfile       ,pSouestVersion },
#endif
#ifdef _SUPPORT_STERLING
    {STERLING     ,InitSterlingEcmProfile     ,InitSterlingTcmProfile     ,InitSterlingAbsProfile     ,InitSterlingSrsProfile     ,pSterlingVersion },
#endif
#ifdef _SUPPORT_SUBARU
    {SUBARU       ,InitSubaruEcmProfile       ,InitSubaruTcmProfile       ,InitSubaruAbsProfile       ,InitSubaruSrsProfile       ,pSubaruVersion },
#endif
#ifdef _SUPPORT_SUZUKI
    {SUZUKI       ,InitSuzukiEcmProfile       ,InitSuzukiTcmProfile       ,InitSuzukiAbsProfile       ,InitSuzukiSrsProfile       ,pSuzukiVersion },
#endif
#ifdef _SUPPORT_TESLA
    {TESLA        ,InitTeslaEcmProfile        ,InitTeslaTcmProfile        ,InitTeslaAbsProfile        ,InitTeslaSrsProfile        ,pTeslaVersion },
#endif
#ifdef _SUPPORT_THINK
    {THINK        ,InitThinkEcmProfile        ,InitThinkTcmProfile        ,InitThinkAbsProfile        ,InitThinkSrsProfile        ,pThinkVersion },
#endif
#ifdef _SUPPORT_TIAMA
    {TIAMA        ,InitTiamaEcmProfile        ,InitTiamaTcmProfile        ,InitTiamaAbsProfile        ,InitTiamaSrsProfile        ,pTiamaVersion },
#endif
#ifdef _SUPPORT_TOYOTA
    {TOYOTA       ,InitToyotaEcmProfile       ,InitToyotaTcmProfile       ,InitToyotaAbsProfile       ,InitToyotaSrsProfile       ,pToyotaVersion },
#endif
#ifdef _SUPPORT_VOLKSWAGEN
    {VOLKSWAGEN   ,InitVolkswagenEcmProfile   ,InitVolkswagenTcmProfile   ,InitVolkswagenAbsProfile   ,InitVolkswagenSrsProfile   ,pVolkswagenVersion },
#endif
#ifdef _SUPPORT_VOLVO
    {VOLVO        ,InitVolvoEcmProfile        ,InitVolvoTcmProfile        ,InitVolvoAbsProfile        ,InitVolvoSrsProfile        ,pVolvoVersion },
#endif
#ifdef _SUPPORT_WULING
    {WULING       ,InitWulingEcmProfile       ,InitWulingTcmProfile       ,InitWulingAbsProfile       ,InitWulingSrsProfile       ,pWulingVersion },
#endif
#ifdef _SUPPORT_YUGO
    {YUGO         ,InitYugoEcmProfile         ,InitYugoTcmProfile         ,InitYugoAbsProfile         ,InitYugoSrsProfile         ,pYugoVersion },
#endif
    {GENERIC      ,Null                       ,Null                       ,Null                       ,Null                       ,Null},
};

/*May3013 Lap Dang added to test abs srs light*/
#ifdef _ENABLE_ABS_SRS_LIGHT

structVehicleAbsSrsLight strtVehicleAbsSrsLight[]=
{
#if ENABLE_VEHICLE_FEATURE
    
#ifdef _SUPPORT_NISSAN
    {NISSAN    ,InitNissanAirbagStatusProfile,InitNissanAbsStatusProfile},
#endif
#ifdef _SUPPORT_HONDA
    {HONDA    ,InitHondaAirbagStatusProfile,InitHondaAbsStatusProfile},
#endif
#ifdef _SUPPORT_CHRYSLER
    {CHRYSLER    ,InitChryslerAirbagStatusProfile,InitChryslerAbsStatusProfile},
#endif
#ifdef _SUPPORT_GM
    {GM    ,InitGmAirbagStatusProfile,InitGmAbsStatusProfile},
#endif
#ifdef _SUPPORT_BMW
    {BMW    ,InitBmwAirbagStatusProfile,InitBmwAbsStatusProfile},
#endif
#ifdef _SUPPORT_FORD
    {FORD    ,InitFordAirbagStatusProfile, InitFordAbsStatusProfile},
#endif
#ifdef _SUPPORT_MERCEDES
    {MERCEDES    ,InitMercedesAirbagStatusProfile, InitMercedesAbsStatusProfile},
#endif
#ifdef _SUPPORT_HYUNDAI
{HYUNDAI    ,InitHyundaiAirbagStatusProfile,InitHyundaiAbsStatusProfile},
#endif
#ifdef _SUPPORT_KIA
{KIA    ,InitKiaAirbagStatusProfile,InitKiaAbsStatusProfile},
#endif
#ifdef _SUPPORT_TOYOTA
    {TOYOTA    ,null,Null},
#endif
#ifdef _SUPPORT_VOLKSWAGEN
{VOLKSWAGEN    ,InitVolkswagenAirbagStatusProfile,InitVolkswagenAbsStatusProfile},
#endif
#ifdef _SUPPORT_VOLVO
    {VOLVO    ,InitVolvoAirbagStatusProfile,InitVolvoAbsStatusProfile},
#endif

#endif

{GENERIC      ,Null                       ,Null},
};

#endif


#ifdef __USE_OEM_MODULE
Init_X_Profile Init_X_OEM_Profile[NUM_OEM_PROFILE];
#endif
#else
#ifdef __USE_OEM_MODULE
extern Init_X_Profile Init_X_OEM_Profile[NUM_OEM_PROFILE];
#endif
#endif
/***************************************************************
                    Check supported vehicle
***************************************************************/
#ifdef   _SUPPORT_ALFAROMEO
#warning    _SUPPORT_ALFAROMEO
#endif
#ifdef   _SUPPORT_AM_GENERAL
#warning    _SUPPORT_AM_GENERAL
#endif
#ifdef   _SUPPORT_AMC
#warning    _SUPPORT_AMC
#endif
#ifdef   _SUPPORT_ASTON_MARTIN
#warning    _SUPPORT_ASTON_MARTIN
#endif
#ifdef   _SUPPORT_AUDI
#warning    _SUPPORT_AUDI
#endif
#ifdef   _SUPPORT_BENTLEY
#warning    _SUPPORT_BENTLEY
#endif
#ifdef   _SUPPORT_BMW
#warning    _SUPPORT_BMW
#endif
#ifdef   _SUPPORT_BRILLIANCE
#warning    _SUPPORT_BRILLIANCE
#endif
#ifdef   _SUPPORT_BUGATTI
#warning    _SUPPORT_BUGATTI
#endif
#ifdef   _SUPPORT_BYD
#warning    _SUPPORT_BYD
#endif
#ifdef   _SUPPORT_CHANA
#warning    _SUPPORT_CHANA
#endif
#ifdef   _SUPPORT_CHERY_AUTO
#warning    _SUPPORT_CHERY_AUTO
#endif
#ifdef   _SUPPORT_CHRYSLER
#warning    _SUPPORT_CHRYSLER
#endif
#ifdef   _SUPPORT_CITROEN
#warning    _SUPPORT_CITROEN
#endif
#ifdef   _SUPPORT_DAEWOO
#warning    _SUPPORT_DAEWOO
#endif
#ifdef   _SUPPORT_DAIHATSU
#warning    _SUPPORT_DAIHATSU
#endif
#ifdef   _SUPPORT_DELOREAN
#warning    _SUPPORT_DELOREAN
#endif
#ifdef   _SUPPORT_EAGLE
#warning    _SUPPORT_EAGLE
#endif
#ifdef   _SUPPORT_FAW
#warning    _SUPPORT_FAW
#endif
#ifdef   _SUPPORT_FAW_VW
#warning    _SUPPORT_FAW_VW
#endif
#ifdef   _SUPPORT_FERRARI
#warning    _SUPPORT_FERRARI
#endif
#ifdef   _SUPPORT_FIAT
#warning    _SUPPORT_FIAT
#endif
#ifdef   _SUPPORT_FORD
#warning    _SUPPORT_FORD
#endif
#ifdef   _SUPPORT_FREIGHTLINER
#warning    _SUPPORT_FREIGHTLINER
#endif
#ifdef   _SUPPORT_GEELY
#warning    _SUPPORT_GEELY
#endif
#ifdef   _SUPPORT_GM
#warning    _SUPPORT_GM
#endif
#ifdef   _SUPPORT_GREATWALL
#warning    _SUPPORT_GREATWALL
#endif
#ifdef   _SUPPORT_HAFEI
#warning    _SUPPORT_HAFEI
#endif
#ifdef   _SUPPORT_HONDA
#warning    _SUPPORT_HONDA
#endif
#ifdef   _SUPPORT_HYUNDAI
#warning    _SUPPORT_HYUNDAI
#endif
#ifdef   _SUPPORT_ISUZU
#warning    _SUPPORT_ISUZU
#endif
#ifdef   _SUPPORT_JAGUAR
#warning    _SUPPORT_JAGUAR
#endif
#ifdef   _SUPPORT_JEEP
#warning    _SUPPORT_JEEP
#endif
#ifdef   _SUPPORT_KIA
#warning    _SUPPORT_KIA
#endif
#ifdef   _SUPPORT_LAMBORGHINI
#warning    _SUPPORT_LAMBORGHINI
#endif
#ifdef   _SUPPORT_LANDROVER
#warning    _SUPPORT_LANDROVER
#endif
#ifdef   _SUPPORT_LIFAN
#warning    _SUPPORT_LIFAN
#endif
#ifdef   _SUPPORT_LOTUS
#warning    _SUPPORT_LOTUS
#endif
#ifdef   _SUPPORT_MASERATI
#warning    _SUPPORT_MASERATI
#endif
#ifdef   _SUPPORT_MATRIX
#warning    _SUPPORT_MATRIX
#endif
#ifdef   _SUPPORT_MAZDA
#warning    _SUPPORT_MAZDA
#endif
#ifdef   _SUPPORT_MERCEDES
#warning    _SUPPORT_MERCEDES
#endif
#ifdef   _SUPPORT_MERKUR
#warning    _SUPPORT_MERKUR
#endif
#ifdef   _SUPPORT_MESAC
#warning    _SUPPORT_MESAC
#endif
#ifdef   _SUPPORT_MITSUBISHI
#warning    _SUPPORT_MITSUBISHI
#endif
#ifdef   _SUPPORT_NISSAN
#warning    _SUPPORT_NISSAN
#endif
#ifdef   _SUPPORT_OPEL
#warning    _SUPPORT_OPEL
#endif
#ifdef   _SUPPORT_PASSPORT
#warning    _SUPPORT_PASSPORT
#endif
#ifdef   _SUPPORT_PEUGEOT
#warning    _SUPPORT_PEUGEOT
#endif
#ifdef   _SUPPORT_PORSCHE
#warning    _SUPPORT_PORSCHE
#endif
#ifdef   _SUPPORT_RENAULT
#warning    _SUPPORT_RENAULT
#endif
#ifdef   _SUPPORT_ROLLS_ROYCE
#warning    _SUPPORT_ROLLS_ROYCE
#endif
#ifdef   _SUPPORT_SAAB
#warning    _SUPPORT_SAAB
#endif
#ifdef   _SUPPORT_SMART
#warning    _SUPPORT_SMART
#endif
#ifdef   _SUPPORT_SOUEST
#warning    _SUPPORT_SOUEST
#endif
#ifdef   _SUPPORT_STERLING
#warning    _SUPPORT_STERLING
#endif
#ifdef   _SUPPORT_SUBARU
#warning    _SUPPORT_SUBARU
#endif
#ifdef   _SUPPORT_SUZUKI
#warning    _SUPPORT_SUZUKI
#endif
#ifdef   _SUPPORT_TESLA
#warning    _SUPPORT_TESLA
#endif
#ifdef   _SUPPORT_THINK
#warning    _SUPPORT_THINK
#endif
#ifdef   _SUPPORT_TIAMA
#warning    _SUPPORT_TIAMA
#endif
#ifdef   _SUPPORT_TOYOTA
#warning    _SUPPORT_TOYOTA
#endif
#ifdef   _SUPPORT_VOLKSWAGEN
#warning    _SUPPORT_VOLKSWAGEN
#endif
#ifdef   _SUPPORT_VOLVO
#warning    _SUPPORT_VOLVO
#endif
#ifdef   _SUPPORT_WULING
#warning    _SUPPORT_WULING
#endif
#ifdef   _SUPPORT_YUGO
#warning    _SUPPORT_YUGO
#endif
#ifdef   _SUPPORT_JAC
#warning    _SUPPORT_JAC
#endif
#ifdef   _SUPPORT_SEAT
#warning    _SUPPORT_SEAT
#endif
#ifdef   _SUPPORT_CHANGFENG
#warning    _SUPPORT_CHANGFENG
#endif
#ifdef   _SUPPORT_HONDA_OBD1
#warning    _SUPPORT_HONDA_OBD1
#endif
#ifdef   _SUPPORT_CHRYSLER_OBD1
#warning    _SUPPORT_CHRYSLER_OBD1
#endif
#ifdef   _SUPPORT_TOYOTA_OBD1
#warning    _SUPPORT_TOYOTA_OBD1
#endif
#ifdef   _SUPPORT_GM_OBD1
#warning    _SUPPORT_GM_OBD1
#endif
#ifdef   _SUPPORT_FORD_OBD1
#warning    _SUPPORT_FORD_OBD1
#endif

#endif