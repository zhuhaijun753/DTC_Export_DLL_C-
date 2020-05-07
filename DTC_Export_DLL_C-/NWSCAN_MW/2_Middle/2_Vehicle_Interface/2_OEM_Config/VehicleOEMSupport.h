/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : VehicleOEMSupport.h
Description     :
layer           : Middle Layer
Accessibility   : use in application layer
Creation        : Lap Dang - 06 Sept 2011
Modify/Updated  :
Version         : V01.00.00
===============================================================================
******************************************************************************/
#ifndef VEHICLE_OEM_SUPPORT_H
#define VEHICLE_OEM_SUPPORT_H
#ifdef __USE_OEM_MODULE
typedef struct _structOEMModule
{
    enumController  eCtrlType;
    Init_X_Profile  Init_X_OEM_Profile;
} structOEMModule;
typedef struct _structVehicleOEMModule
{
    enumVehicle                eVehicle;
    const structOEMModule*     p_strtOEMModule;
} structVehicleOEMModule;
#ifdef __OEM_SETUP_C
const structOEMModule p_strNoneOEMModule[] =
{
    {ALL_CONTROLLER     ,null                              },
};

const structOEMModule p_strToyotaOEMModule[] =
{
    {HV                 ,InitToyotaHvProfile                },
    {BATTERY            ,InitToyotaBatteryProfile           },
    {SEAT_SNSR          ,InitToyotaSeat_SnsrProfile         },
    {ACC                ,InitToyotaAccProfile               },
    {CHECK_VER          ,InitToyotaCheck_VerProfile         },
    {POWER              ,InitToyotaPowerProfile             },
    {CLR_SONAR          ,InitToyotaClr_SonarProfile         },
    {P_CONTR            ,InitToyotaP_ContrProfile           },
    {EPS                ,InitToyotaEpsProfile               },
    {IMM                ,InitToyotaImmProfile               },
    {TPMS               ,InitToyotaTpmsProfile              },
    {SECURITY           ,InitToyotaSecurityProfile          },
    {BODY               ,InitToyotaBodyProfile              },
    {BODY_4             ,InitToyotaBody_4Profile            },
    {D_SEAT_DOOR        ,InitToyotaD_Seat_DoorProfile       },
    {P_SEAT_DOOR        ,InitToyotaP_Seat_DoorProfile       },
    {RR_DOOR            ,InitToyotaRr_DoorProfile           },
    {RL_DOOR            ,InitToyotaRl_DoorProfile           },
    {RETR_TOP           ,InitToyotaRetr_TopProfile          },
    {TILT_TELESCOPIC    ,InitToyotaTilt_TelescopicProfile   },
    {AFS                ,InitToyotaAfsProfile               },
    {ARS                ,InitToyotaArsProfile               },
    {AIR_SUS            ,InitToyotaAir_SusProfile           },
    {GATEWAY            ,InitToyotaGatewayProfile           },
    {D_SEAT_JB          ,InitToyotaD_Seat_JbProfile         },
    {P_SEAT_JB          ,InitToyotaP_Seat_JbProfile         },
    {VGRS               ,InitToyotaVgrsProfile              },
    {ECD                ,InitToyotaEcdProfile               },
    {ALL_CONTROLLER     ,null                               },
};

const structOEMModule p_strMazdaOEMModule[] =
{
    {METER              ,InitMazdaMeterProfile              },
    {BCM                ,InitMazdaBcmProfile                },
    {EPS                ,InitMazdaEpsProfile                },
    {ESP                ,InitMazdaEspProfile                },
    {DSC                ,InitMazdaDscProfile                },
    {ALL_CONTROLLER     ,null                               },
};

const structOEMModule p_strSubaruOEMModule[] =
{
    {ITU                ,InitSubaruItuProfile              },
    {EPS                ,InitSubaruEpsProfile              },
    {ALL_CONTROLLER     ,null                              },
};

const structOEMModule p_strHondaOEMModule[] =
{
    {BCM                ,InitHondaBcmProfile              },
    {EPS                ,InitHondaEpsProfile              },
    {HYDRO_BOOSTER      ,InitHondaHydro_BoosterProfile    },
    {IMA                ,InitHondaImaProfile              },
    {ALL_CONTROLLER     ,null                             },
};

const structOEMModule p_strIsuzuOEMModule[] =
{
    {BCM                ,InitIsuzuBcmProfile              },
    {IMM                ,InitIsuzuImmProfile              },
    {ALL_CONTROLLER     ,null                             },
};

const structOEMModule p_strSuzukiOEMModule[] =
{
    {AT_4WD             ,InitSuzuki4WdProfile              },
    {AC                 ,InitSuzukiAcProfile               },
    {BCM                ,InitSuzukiBcmProfile              },
    {EMCD               ,InitSuzukiEmcdProfile             },
    {EPS                ,InitSuzukiEpsProfile              },
    {EV                 ,InitSuzukiEvProfile               },
    {IMM                ,InitSuzukiImmProfile              },
    {ALL_CONTROLLER     ,null                              },
};

const structOEMModule p_strNissanOEMModule[] =
{
    {AUTO_RISER         ,InitNissanAuto_RiserProfile        },
    {BCM                ,InitNissanBcmProfile               },
    {E_4WD              ,InitNissanE_4WdProfile             },
    {E_SUS              ,InitNissanE_SusProfile             },
    {DIU                ,InitNissanDiuProfile               },
    {AT_4WAS            ,InitNissan4WasProfile              },
    {AT_4WAS_RAS_HICAS  ,InitNissan4Was_Ras_HicasProfile    },
    {AFS                ,InitNissanAfsProfile               },        
    {DR_POLap DangION        ,InitNissanDr_PoLap DangionProfile       },
    {EPS                ,InitNissanEpsProfile               },
    {HVAC               ,InitNissanHvacProfile              },
    {MULTI_AV           ,InitNissanMulti_AvProfile          },
    {PCSB               ,InitNissanPcsbProfile              },
    {TPMS               ,InitNissanTpmsProfile              },
    {IPDM_ER            ,InitNissanIpdm_ErProfile           },
    {AVCS_ADAS          ,InitNissanAvcs_AdasProfile         },
    {LASER              ,InitNissanLaserProfile             },
    {SM_KEY             ,InitNissanSm_KeyProfile            },
    {AUTO_SD            ,InitNissanAuto_SdProfile           },
    {AT_4WD             ,InitNissan4WdProfile               },
    {SONAR              ,InitNissanSonarProfile             },
    {EHS                ,InitNissanEhsProfile               },
    {METER              ,InitNissanMeterProfile             },
    {AC                 ,InitNissanAcProfile                },
    {ALL_CONTROLLER     ,null                               },
};

const structOEMModule p_strMitsubishiOEMModule[] =
{
    {AT_4WD             ,InitMitsubishi4WdProfile               },
    {AC                 ,InitMitsubishiAcProfile                },
    {AYC_ACD            ,InitMitsubishiAyc_AcdProfile           },
    {CR_CONTR           ,InitMitsubishiCr_ContrProfile          },
    {DISPLAY            ,InitMitsubishiDisplayProfile           },
    {EPS                ,InitMitsubishiEpsProfile               },
    {ETACS              ,InitMitsubishiEtacsProfile             },
    {HBB                ,InitMitsubishiHbbProfile               },
    {IMM                ,InitMitsubishiImmProfile               },
    {KEYLESS            ,InitMitsubishiKeylessProfile           },
    {METER              ,InitMitsubishiMeterProfile             },
    {SS4_II             ,InitMitsubishiSs4_IiProfile            },
    {SUS                ,InitMitsubishiSusProfile               },
    {SWS                ,InitMitsubishiSwsProfile               },
    {TCS                ,InitMitsubishiTcsProfile               },
    {TPMS               ,InitMitsubishiTpmsProfile              },
    {ALL_CONTROLLER     ,null                                   },
};
const structOEMModule p_strDaihatsuOEMModule[] =
{
    {IMM                ,InitDaihatsuImmProfile             },
    {AT_4WD             ,InitDaihatsu4WdProfile             },
    {FR_KEY             ,InitDaihatsuFr_KeyProfile          },
    {ITC                ,InitDaihatsuItcProfile             },
    {ACC                ,InitDaihatsuAccProfile             },
    {E_ROOF_RAT         ,InitDaihatsuE_Roof_RatProfile      },
    {ESP                ,InitDaihatsuEspProfile             },
    {ALL_CONTROLLER     ,null                               },
};

const structOEMModule p_strMercedesOEMModule[] =
{
    {ASSYST                ,InitMercedesAssystProfile             },
    {INSTR                ,InitMercedesInstrProfile             },
    {SBC                ,InitMercedesSbcProfile             },

    {ALL_CONTROLLER     ,null                               },
};

const structOEMModule p_strVWOEMModule[] =
{
    {METER                ,InitVolkswagenMeterProfile             },
    {L_LIGHT_CONTR                ,InitVolkswagenL_Light_ContrProfile             },

    {ALL_CONTROLLER     ,null                               },
};

const structVehicleOEMModule strtVehicleOEMModule[] =
{
    //{TOYOTA     ,p_strToyotaOEMModule   },
    //{MAZDA      ,p_strMazdaOEMModule    },
    //{SUBARU     ,p_strSubaruOEMModule   },
    //{HONDA      ,p_strHondaOEMModule    },
    //{ISUZU      ,p_strIsuzuOEMModule    },
    //{SUZUKI     ,p_strSuzukiOEMModule   },
    //{NISSAN     ,p_strNissanOEMModule   },
    //{MITSUBISHI ,p_strMitsubishiOEMModule   },
   // {DAIHATSU   ,p_strDaihatsuOEMModule   },
    {MERCEDES   ,p_strMercedesOEMModule   },
    //{VOLKSWAGEN   ,p_strVWOEMModule   },
    
    //Add more manufacturer at hare
    {GENERIC    ,p_strNoneOEMModule     },
};
#else
enumbool gf_Init_OEM_Profile(structVehicleProfile * p_strtVeh);
enumbool gf_Search_Index_OEM_Module(enumVehicle eVehicle,enumController eOEMModule,uint8 *bIdx);
extern const structVehicleOEMModule strtVehicleOEMModule[];
#endif
#endif
#endif
