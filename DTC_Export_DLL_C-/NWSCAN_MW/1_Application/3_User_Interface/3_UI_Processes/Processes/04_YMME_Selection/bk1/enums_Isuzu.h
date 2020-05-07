/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 9/29/2015
********************************************************************************************************************/

#ifndef __ENUMS_Isuzu_H__
#define __ENUMS_Isuzu_H__



    
    typedef enum _enumCommand_Isuzu{
        ecommand_UNKNOWN_Isuzu   = 0,
        ecommand_3E_Isuzu  = 1,
        ecommand_20_Isuzu  = 2,
        ecommand_B1_____01_Isuzu  = 3,
        ecommand_01_____3E_Isuzu  = 4,
        ecommand_14_____00_____00_Isuzu  = 5,
        ecommand_14_____40_____00_Isuzu  = 6,
        ecommand_14_____80_____00_Isuzu  = 7,
        ecommand_14_____FF_____00_Isuzu  = 8,
        ecommand_18_____00_____00_____00_Isuzu  = 9,
        ecommand_18_____00_____40_____00_Isuzu  = 10,
        ecommand_18_____00_____80_____00_Isuzu  = 11,
        ecommand_18_____00_____FF_____00_Isuzu  = 12,
        ecommand_19_____52_____FF_____00_Isuzu  = 13,
        ecommand_19_____12_____FF_____00_Isuzu  = 14,
        ecommand_14_Isuzu  = 15,
        ecommand_13_Isuzu  = 16,
        ecommand_B3_Isuzu  = 17,
        ecommand_81_Isuzu  = 18,
        ecommand_19_____DA_____FF_____00_Isuzu  = 19,
    
    }enumCommand_Isuzu;
    
    
    typedef enum _enumReaddtccommandlist_Isuzu{
        ereaddtccommandlist_UNKNOWN_Isuzu   = 0,
        ereaddtccommandlist_18_____00_____00_____00___18_____00_____40_____00___18_____00_____80_____00___18_____00_____FF_____00___1_Isuzu  = 1,
        ereaddtccommandlist_19_____52_____FF_____00___2_Isuzu  = 2,
        ereaddtccommandlist_19_____12_____FF_____00___3_Isuzu  = 3,
        ereaddtccommandlist_13___B3___4_Isuzu  = 4,
        ereaddtccommandlist_18_____00_____FF_____00___5_Isuzu  = 5,
        ereaddtccommandlist_19_____DA_____FF_____00___6_Isuzu  = 6,
    
    }enumReaddtccommandlist_Isuzu;
    
    
    typedef enum _enumCommandlist_Isuzu{
        ecommandlist_UNKNOWN_Isuzu   = 0,
        ecommandlist_01_____3E_Isuzu  = 1,
        ecommandlist_14_____00_____00___14_____40_____00___14_____80_____00___14_____FF_____00_Isuzu  = 2,
        ecommandlist_20_Isuzu  = 3,
        ecommandlist_B1_____01_Isuzu  = 4,
        ecommandlist_14_Isuzu  = 5,
        ecommandlist_81_Isuzu  = 6,
    
    }enumCommandlist_Isuzu;
    
    
    typedef enum _enumEcuinfotype_Isuzu{
        eecuinfotype_UNKNOWN_Isuzu   = 0,
    
    }enumEcuinfotype_Isuzu;
    
    
    typedef enum _enumDtcreadtype_Isuzu{
        edtcreadtype_UNKNOWN_Isuzu   = 0,
    
    }enumDtcreadtype_Isuzu;
    
    
    typedef enum _enumLookuptable_Isuzu{
        elookuptable_UNKNOWN_Isuzu   = 0,
    
    }enumLookuptable_Isuzu;
    
    
    typedef enum _enumMessageid_Isuzu{
        emessageid_UNKNOWN_Isuzu   = 0,
        emessageid_ISZNWSID_2001_Isuzu  = 1,
        emessageid_ISZNWSID_2002_Isuzu  = 2,
        emessageid_ISZNWSID_2003_Isuzu  = 3,
        emessageid_ISZNWSID_2004_Isuzu  = 4,
        emessageid_ISZNWSID_0001_Isuzu  = 5,
        emessageid_ISZNWSID_0002_Isuzu  = 6,
        emessageid_ISZNWSID_0003_Isuzu  = 7,
        emessageid_ISZNWSID_4101_Isuzu  = 8,
        emessageid_ISZNWSID_4100_Isuzu  = 9,
        emessageid_ISZNWSID_3300_Isuzu  = 10,
    
    }enumMessageid_Isuzu;
    
    
    typedef enum _enumSystem_Isuzu{
        esystem_UNKNOWN_Isuzu   = 0,
    
    }enumSystem_Isuzu;
    
    
    typedef enum _enumSubsystem_Isuzu{
        esubsystem_UNKNOWN_Isuzu   = 0,
    
    }enumSubsystem_Isuzu;
    
    
    typedef enum _enumTiming_Isuzu{
        etiming_UNKNOWN_Isuzu   = 0,
        etiming_TIMINGP_SUZUKI_CAN_Isuzu  = 1,
        etiming_TWUP_GM_VPW_Isuzu  = 2,
        etiming_TIMINGP_GM_VPW_Isuzu  = 3,
        etiming_TIMINGW_GM_VPW_Isuzu  = 4,
        etiming_TWUP_GM_ISO9141_Isuzu  = 5,
        etiming_TIMINGP_GM_ISO9141_Isuzu  = 6,
        etiming_TIMINGW_GM_ISO9141_Isuzu  = 7,
        etiming_TWUP_SUZUKI_KW_Isuzu  = 8,
        etiming_TIMINGP_SUZUKI_KW_Isuzu  = 9,
        etiming_TIMINGW_SUZUKI_KW_Isuzu  = 10,
        etiming_KW1281DEFAULT_Isuzu  = 11,
        etiming_TIMINGP_CHRYSLER_CAN_Isuzu  = 12,
        etiming_TIMINGP_CHRYSLER_CAN_C_UDS_Isuzu  = 13,
        etiming_TIMINGP_CHRYSLER_CAN_I_UDS_Isuzu  = 14,
        etiming_TIMINGP_CHRYSLER_CCD_Isuzu  = 15,
        etiming_TIMINGP_CHRYSLER_CCD2_Isuzu  = 16,
        etiming_TIMINGP_CHRYSLER_KW2000_Isuzu  = 17,
        etiming_TIMINGP_CHRYSLER_KWFB_Isuzu  = 18,
        etiming_TIMINGP_CHRYSLER_MB_ISO_Isuzu  = 19,
        etiming_TIMINGP_CHRYSLER_MUT_Isuzu  = 20,
        etiming_TIMINGP_CHRYSLER_SCI_Isuzu  = 21,
        etiming_TIMINGP_CHRYSLER_VPW_Isuzu  = 22,
        etiming_TIMINGP_FORD_CAN_Isuzu  = 23,
        etiming_TIMINGP_FORD_CAN_UDS_Isuzu  = 24,
        etiming_TIMINGP_FORD_ISO9141_Isuzu  = 25,
        etiming_TIMINGP_FORD_MCAN_Isuzu  = 26,
        etiming_TIMINGP_FORD_MCAN_____UDS_Isuzu  = 27,
        etiming_TIMINGP_FORD_PWM_Isuzu  = 28,
        etiming_TIMINGP_FORD_UBP_Isuzu  = 29,
        etiming_TIMINGP_GM_ALDL_Isuzu  = 30,
        etiming_TIMINGP_GM_CAN_Isuzu  = 31,
        etiming_TIMINGP_GM_GMLAN_Isuzu  = 32,
        etiming_TIMINGP_GM_KW_Isuzu  = 33,
        etiming_TIMINGP_GM_SDL_Isuzu  = 34,
        etiming_TIMINGP_GM_SWCAN_Isuzu  = 35,
        etiming_TIMINGP_HONDA_92HM_Isuzu  = 36,
        etiming_TIMINGP_HONDA_95HM_Isuzu  = 37,
        etiming_TIMINGP_HONDA_BOSCH_Isuzu  = 38,
        etiming_TIMINGP_HONDA_CAN_Isuzu  = 39,
        etiming_TIMINGP_HONDA_H99B_Isuzu  = 40,
        etiming_TIMINGP_HONDA_KW2000_Isuzu  = 41,
        etiming_TIMINGP_TOYOTA_CAN_Isuzu  = 42,
        etiming_TIMINGP_TOYOTA_ISO9141_Isuzu  = 43,
        etiming_TIMINGP_TOYOTA_KW2000_Isuzu  = 44,
        etiming_TIMINGP_TOYOTA_VPW_Isuzu  = 45,
        etiming_TIMINGW_CHRYSLER_MB_ISO_Isuzu  = 46,
        etiming_TIMINGW_CHRYSLER_MUT_Isuzu  = 47,
        etiming_TIMINGW_FORD_ISO9141_Isuzu  = 48,
        etiming_TIMINGW_GM_KW_Isuzu  = 49,
        etiming_TIMINGW_HONDA_BOSCH_Isuzu  = 50,
        etiming_TIMINGW_TOYOTA_ISO9141_Isuzu  = 51,
        etiming_TWUP_CHRYSLER_KW2000_Isuzu  = 52,
        etiming_TWUP_CHRYSLER_KWFB_Isuzu  = 53,
        etiming_TWUP_FORD_UBP_Isuzu  = 54,
        etiming_TWUP_GM_KW_Isuzu  = 55,
        etiming_TWUP_HONDA_92HM_Isuzu  = 56,
        etiming_TWUP_HONDA_95HM_Isuzu  = 57,
        etiming_TWUP_HONDA_H99B_Isuzu  = 58,
        etiming_TWUP_HONDA_KW2000_Isuzu  = 59,
        etiming_TWUP_TOYOTA_KW2000_10400_Isuzu  = 60,
        etiming_TWUP_TOYOTA_KW2000_9600_Isuzu  = 61,
        etiming_TWUPHONDA_00_Isuzu  = 62,
        etiming_TIMINGP_NORMAL_Isuzu  = 63,
        etiming_TIMINGP_CANNORMAL_Isuzu  = 64,
        etiming_TIMINGW_NORMAL_Isuzu  = 65,
        etiming_TWUPGENERAL_Isuzu  = 66,
        etiming_TWUP_GM_KW9600_Isuzu  = 67,
        etiming_TIMINGP_VOLVO_D2_Isuzu  = 68,
        etiming_TIMINGP_VOLVO_GGD_Isuzu  = 69,
        etiming_TIMINGP_VOLVO_KW_Isuzu  = 70,
        etiming_TIMINGW_VOLVO_D2_Isuzu  = 71,
        etiming_TWUP_VOLVO_KW_Isuzu  = 72,
        etiming_TWUP_VOLVO_GGD_Isuzu  = 73,
        etiming_TWUP_VOLVO_D2_Isuzu  = 74,
        etiming_TIMINGW_VOLVO_GGD_Isuzu  = 75,
        etiming_TIMINGW_VOLVO_KW_Isuzu  = 76,
        etiming_TIMINGP_BMW_KW2000_Isuzu  = 77,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_Isuzu  = 78,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_UDS_Isuzu  = 79,
        etiming_TIMINGP_NISSAN_DDL1_Isuzu  = 80,
    
    }enumTiming_Isuzu;
    
    
    typedef enum _enumErasetype_Isuzu{
        eerasetype_UNKNOWN_Isuzu   = 0,
    
    }enumErasetype_Isuzu;
    
    
    typedef enum _enumModel_Isuzu{
        emodel_UNKNOWN_Isuzu   = 0,
        emodel_RODEO_Isuzu  = 1,
        emodel_HOMBRE_Isuzu  = 2,
        emodel_OASIS_Isuzu  = 3,
        emodel_TROOPER_Isuzu  = 4,
        emodel_AMIGO_Isuzu  = 5,
        emodel_VEHICROSS_Isuzu  = 6,
        emodel_RODEO_____SPORT_Isuzu  = 7,
        emodel_AXIOM_Isuzu  = 8,
        emodel_ASCENDER_Isuzu  = 9,
        emodel_I_280_Isuzu  = 10,
        emodel_I_350_Isuzu  = 11,
        emodel_I_290_Isuzu  = 12,
        emodel_I_370_Isuzu  = 13,
        emodel_NQR___________FRR_Isuzu  = 14,
        emodel_NPR___________NPR_HD_Isuzu  = 15,
    
    }enumModel_Isuzu;
    
    
    typedef enum _enumEngine_Isuzu{
        eengine_UNKNOWN_Isuzu   = 0,
        eengine_L4_____2_6L_Isuzu  = 1,
        eengine_V6_____3_2L_Isuzu  = 2,
        eengine_L4_____2_2L_Isuzu  = 3,
        eengine_V6_____4_3L_Isuzu  = 4,
        eengine_L4_____2_3L_Isuzu  = 5,
        eengine_V6_____3_5L_Isuzu  = 6,
        eengine_L4_____1_6L_Isuzu  = 7,
        eengine_L6_____4_2L_Isuzu  = 8,
        eengine_V8_____5_3L_Isuzu  = 9,
        eengine_L4_____2_8L_Isuzu  = 10,
        eengine_L5_____3_5L_Isuzu  = 11,
        eengine_L4_____2_9L_Isuzu  = 12,
        eengine_L5_____3_7L_Isuzu  = 13,
        eengine_V6______3_5L______GASOLINE______VIN8_X__Isuzu  = 14,
        eengine_V6______3_5L______GASOLINE______VIN8_Y__Isuzu  = 15,
        eengine_L4______2_2L______GASOLINE______VIN8_D__Isuzu  = 16,
        eengine_V6______3_2L______GASOLINE______VIN8_W__Isuzu  = 17,
        eengine_L6______4_2L______GASOLINE______VIN8_S__Isuzu  = 18,
        eengine_V8______5_3L______GASOLINE______VIN8_P__Isuzu  = 19,
        eengine_V8______5_3L______GASOLINE______VIN8_M__Isuzu  = 20,
        eengine_L4______2_8L______GASOLINE______VIN8_8__Isuzu  = 21,
        eengine_L5______3_5L______GASOLINE______VIN8_6__Isuzu  = 22,
        eengine_L4______2_9L______GASOLINE______VIN8_9__Isuzu  = 23,
        eengine_L5_____3_7L______GASOLINE______VIN8_E__Isuzu  = 24,
        eengine_L4______2_6L______GASOLINE_Isuzu  = 25,
        eengine_V6______3_2L______GASOLINE_Isuzu  = 26,
        eengine_L4______2_2L______GASOLINE_Isuzu  = 27,
        eengine_V6______4_3L______GASOLINE_Isuzu  = 28,
        eengine_L4______2_3L______GASOLINE_Isuzu  = 29,
        eengine_V6______3_5L______GASOLINE_Isuzu  = 30,
        eengine_L4______1_6L______GASOLINE_Isuzu  = 31,
        eengine_L5______3_7L______GASOLINE______VIN8_E__Isuzu  = 32,
        eengine_V6______3_5L______GASOLINE______VIN_____8TH___________X__Isuzu  = 33,
        eengine_V6______3_5L______GASOLINE______VIN_____8TH___________Y__Isuzu  = 34,
        eengine_L4______2_2L______GASOLINE______VIN_____8TH___________D__Isuzu  = 35,
        eengine_V6______3_2L______GASOLINE______VIN_____8TH___________W__Isuzu  = 36,
        eengine_L6______4_2L______GASOLINE______VIN_____8TH___________S__Isuzu  = 37,
        eengine_V8______5_3L______GASOLINE______VIN_____8TH___________P__Isuzu  = 38,
        eengine_V8______5_3L______GASOLINE______VIN_____8TH___________M__Isuzu  = 39,
        eengine_L4______2_8L______GASOLINE______VIN_____8TH___________8__Isuzu  = 40,
        eengine_L5______3_5L______GASOLINE______VIN_____8TH___________6__Isuzu  = 41,
        eengine_L4______2_9L______GASOLINE______VIN_____8TH___________9__Isuzu  = 42,
        eengine_L5_____3_7L______GASOLINE______VIN_____8TH___________E__Isuzu  = 43,
        eengine_L5______3_7L______GASOLINE______VIN_____8TH___________E__Isuzu  = 44,
    
    }enumEngine_Isuzu;
    

#endif