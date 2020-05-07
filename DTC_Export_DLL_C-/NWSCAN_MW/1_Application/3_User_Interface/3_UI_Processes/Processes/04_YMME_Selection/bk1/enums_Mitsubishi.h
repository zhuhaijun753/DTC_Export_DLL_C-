/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 9/29/2015
********************************************************************************************************************/

#ifndef __ENUMS_Mitsubishi_H__
#define __ENUMS_Mitsubishi_H__



    
    typedef enum _enumCommand_Mitsubishi{
        ecommand_UNKNOWN_Mitsubishi   = 0,
        ecommand_04_____18_____00_____FF_____00_____00_____00_____00_Mitsubishi  = 1,
        ecommand_01_____00_Mitsubishi  = 2,
        ecommand_FD_Mitsubishi  = 3,
        ecommand_02_____10_____92_____00_____00_____00_____00_____00_Mitsubishi  = 4,
        ecommand_02_____1A_____87_____00_____00_____00_____00_____00_Mitsubishi  = 5,
        ecommand_03_____14_____FF_____00_____00_____00_____00_____00_Mitsubishi  = 6,
        ecommand_14_Mitsubishi  = 7,
        ecommand_04_Mitsubishi  = 8,
        ecommand_13_____FF_Mitsubishi  = 9,
        ecommand_03_Mitsubishi  = 10,
        ecommand_FE_Mitsubishi  = 11,
        ecommand_FF_Mitsubishi  = 12,
        ecommand_FC_Mitsubishi  = 13,
        ecommand_45_Mitsubishi  = 14,
        ecommand_46_Mitsubishi  = 15,
        ecommand_47_Mitsubishi  = 16,
        ecommand_20_Mitsubishi  = 17,
        ecommand_21_Mitsubishi  = 18,
        ecommand_22_Mitsubishi  = 19,
        ecommand_23_Mitsubishi  = 20,
        ecommand_24_Mitsubishi  = 21,
        ecommand_25_Mitsubishi  = 22,
        ecommand_26_Mitsubishi  = 23,
        ecommand_27_Mitsubishi  = 24,
        ecommand_02_Mitsubishi  = 25,
        ecommand_05_Mitsubishi  = 26,
        ecommand_81_Mitsubishi  = 27,
        ecommand_14_____FF_____00_Mitsubishi  = 28,
        ecommand_18_____00_____FF_____00_Mitsubishi  = 29,
        ecommand_B0_Mitsubishi  = 30,
        ecommand_B1_Mitsubishi  = 31,
    
    }enumCommand_Mitsubishi;
    
    
    typedef enum _enumReaddtccommandlist_Mitsubishi{
        ereaddtccommandlist_UNKNOWN_Mitsubishi   = 0,
        ereaddtccommandlist_04_____18_____00_____FF_____00_____00_____00_____00___1_Mitsubishi  = 1,
        ereaddtccommandlist_13_____FF___03___2_Mitsubishi  = 2,
        ereaddtccommandlist_45___46___47___3_Mitsubishi  = 3,
        ereaddtccommandlist_20___21___22___23___24___25___26___27___4_Mitsubishi  = 4,
        ereaddtccommandlist_02___03___04___05___5_Mitsubishi  = 5,
        ereaddtccommandlist_18_____00_____FF_____00___6_Mitsubishi  = 6,
        ereaddtccommandlist_B0___B1___7_Mitsubishi  = 7,
    
    }enumReaddtccommandlist_Mitsubishi;
    
    
    typedef enum _enumCommandlist_Mitsubishi{
        ecommandlist_UNKNOWN_Mitsubishi   = 0,
        ecommandlist_02_____10_____92_____00_____00_____00_____00_____00___02_____1A_____87_____00_____00_____00_____00_____00_Mitsubishi  = 1,
        ecommandlist_03_____14_____FF_____00_____00_____00_____00_____00_Mitsubishi  = 2,
        ecommandlist_01_____00_Mitsubishi  = 3,
        ecommandlist_14___04_Mitsubishi  = 4,
        ecommandlist_FE___FF_Mitsubishi  = 5,
        ecommandlist_FC_Mitsubishi  = 6,
        ecommandlist_81_Mitsubishi  = 7,
        ecommandlist_14_____FF_____00_Mitsubishi  = 8,
    
    }enumCommandlist_Mitsubishi;
    
    
    typedef enum _enumEcuinfotype_Mitsubishi{
        eecuinfotype_UNKNOWN_Mitsubishi   = 0,
    
    }enumEcuinfotype_Mitsubishi;
    
    
    typedef enum _enumDtcreadtype_Mitsubishi{
        edtcreadtype_UNKNOWN_Mitsubishi   = 0,
        edtcreadtype_READDTCTYPE_NONE_Mitsubishi  = 1,
        edtcreadtype_READDTCTYPE_ID0000_Mitsubishi  = 2,
    
    }enumDtcreadtype_Mitsubishi;
    
    
    typedef enum _enumLookuptable_Mitsubishi{
        elookuptable_UNKNOWN_Mitsubishi   = 0,
        elookuptable_DTC_MUT_Mitsubishi  = 1,
    
    }enumLookuptable_Mitsubishi;
    
    
    typedef enum _enumMessageid_Mitsubishi{
        emessageid_UNKNOWN_Mitsubishi   = 0,
        emessageid_MITSUBISHI_ECM_CAN_500_7E0_7E8_Mitsubishi  = 1,
        emessageid_MITSUBISHI_ECM_ISO9141_10400_Mitsubishi  = 2,
        emessageid_MITSUBISHI_ECM_MUT_15600_Mitsubishi  = 3,
        emessageid_MITSUBISHI_TCM_CAN_500_7E1_7E9_Mitsubishi  = 4,
        emessageid_MITSUBISHI_TCM_MUT_15600_Mitsubishi  = 5,
        emessageid_MITSUBISHI_ABS_CAN_500_784_785_Mitsubishi  = 6,
        emessageid_MITSUBISHI_ABS_CAN_500_78A_78B_Mitsubishi  = 7,
        emessageid_MITSUBISHI_ABS_MUT_15600_Mitsubishi  = 8,
        emessageid_MITSUBISHI_SRS_CAN_500_6E0_51C_Mitsubishi  = 9,
        emessageid_MITSUBISHI_SRS_CAN_500_78C_78D_Mitsubishi  = 10,
        emessageid_MITSUBISHI_SRS_KW2000_10400_Mitsubishi  = 11,
        emessageid_MITSUBISHI_SRS_MUT_15600_Mitsubishi  = 12,
        emessageid_ECUID_01_Mitsubishi  = 13,
        emessageid_ECUID_02_Mitsubishi  = 14,
        emessageid_ECUID_03_Mitsubishi  = 15,
        emessageid_ECUID_04_Mitsubishi  = 16,
        emessageid_ECUID_05_Mitsubishi  = 17,
        emessageid_ECUID_06_Mitsubishi  = 18,
        emessageid_ECUID_08_Mitsubishi  = 19,
        emessageid_ECUID_09_Mitsubishi  = 20,
        emessageid_ECUID_10_Mitsubishi  = 21,
        emessageid_ECUID_11_Mitsubishi  = 22,
        emessageid_ECUID_12_Mitsubishi  = 23,
        emessageid_ECUID_14_Mitsubishi  = 24,
        emessageid_ECUID_15_Mitsubishi  = 25,
        emessageid_ECUID_16_Mitsubishi  = 26,
        emessageid_ECUID_17_Mitsubishi  = 27,
        emessageid_ECUID_18_Mitsubishi  = 28,
        emessageid_ECUID_19_Mitsubishi  = 29,
        emessageid_ECUID_20_Mitsubishi  = 30,
        emessageid_ECUID_21_Mitsubishi  = 31,
        emessageid_ECUID_22_Mitsubishi  = 32,
        emessageid_ECUID_23_Mitsubishi  = 33,
        emessageid_ECUID_24_Mitsubishi  = 34,
        emessageid_ECUID_26_Mitsubishi  = 35,
        emessageid_ECUID_27_Mitsubishi  = 36,
    
    }enumMessageid_Mitsubishi;
    
    
    typedef enum _enumSystem_Mitsubishi{
        esystem_UNKNOWN_Mitsubishi   = 0,
    
    }enumSystem_Mitsubishi;
    
    
    typedef enum _enumSubsystem_Mitsubishi{
        esubsystem_UNKNOWN_Mitsubishi   = 0,
    
    }enumSubsystem_Mitsubishi;
    
    
    typedef enum _enumTiming_Mitsubishi{
        etiming_UNKNOWN_Mitsubishi   = 0,
        etiming_TIMINGP_TOYOTA_CAN_Mitsubishi  = 1,
        etiming_TWUP_TOYOTA_ISO9141_Mitsubishi  = 2,
        etiming_TIMINGP_TOYOTA_ISO9141_Mitsubishi  = 3,
        etiming_TIMINGW_TOYOTA_ISO9141_Mitsubishi  = 4,
        etiming_TWUP_CHRYSLER_MUT_Mitsubishi  = 5,
        etiming_TIMINGP_CHRYSLER_MUT_Mitsubishi  = 6,
        etiming_TIMINGW_CHRYSLER_MUT_Mitsubishi  = 7,
        etiming_TWUP_TOYOTA_KW2000_10400_Mitsubishi  = 8,
        etiming_TIMINGP_TOYOTA_KW2000_Mitsubishi  = 9,
        etiming_TIMINGW_TOYOTA_KW2000_Mitsubishi  = 10,
        etiming_KW1281DEFAULT_Mitsubishi  = 11,
        etiming_TIMINGP_CHRYSLER_CAN_Mitsubishi  = 12,
        etiming_TIMINGP_CHRYSLER_CAN_C_UDS_Mitsubishi  = 13,
        etiming_TIMINGP_CHRYSLER_CAN_I_UDS_Mitsubishi  = 14,
        etiming_TIMINGP_CHRYSLER_CCD_Mitsubishi  = 15,
        etiming_TIMINGP_CHRYSLER_CCD2_Mitsubishi  = 16,
        etiming_TIMINGP_CHRYSLER_KW2000_Mitsubishi  = 17,
        etiming_TIMINGP_CHRYSLER_KWFB_Mitsubishi  = 18,
        etiming_TIMINGP_CHRYSLER_MB_ISO_Mitsubishi  = 19,
        etiming_TIMINGP_CHRYSLER_SCI_Mitsubishi  = 20,
        etiming_TIMINGP_CHRYSLER_VPW_Mitsubishi  = 21,
        etiming_TIMINGP_FORD_CAN_Mitsubishi  = 22,
        etiming_TIMINGP_FORD_CAN_UDS_Mitsubishi  = 23,
        etiming_TIMINGP_FORD_ISO9141_Mitsubishi  = 24,
        etiming_TIMINGP_FORD_MCAN_Mitsubishi  = 25,
        etiming_TIMINGP_FORD_MCAN_____UDS_Mitsubishi  = 26,
        etiming_TIMINGP_FORD_PWM_Mitsubishi  = 27,
        etiming_TIMINGP_FORD_UBP_Mitsubishi  = 28,
        etiming_TIMINGP_GM_ALDL_Mitsubishi  = 29,
        etiming_TIMINGP_GM_CAN_Mitsubishi  = 30,
        etiming_TIMINGP_GM_GMLAN_Mitsubishi  = 31,
        etiming_TIMINGP_GM_KW_Mitsubishi  = 32,
        etiming_TIMINGP_GM_SDL_Mitsubishi  = 33,
        etiming_TIMINGP_GM_SWCAN_Mitsubishi  = 34,
        etiming_TIMINGP_GM_VPW_Mitsubishi  = 35,
        etiming_TIMINGP_HONDA_92HM_Mitsubishi  = 36,
        etiming_TIMINGP_HONDA_95HM_Mitsubishi  = 37,
        etiming_TIMINGP_HONDA_BOSCH_Mitsubishi  = 38,
        etiming_TIMINGP_HONDA_CAN_Mitsubishi  = 39,
        etiming_TIMINGP_HONDA_H99B_Mitsubishi  = 40,
        etiming_TIMINGP_HONDA_KW2000_Mitsubishi  = 41,
        etiming_TIMINGP_TOYOTA_VPW_Mitsubishi  = 42,
        etiming_TIMINGW_CHRYSLER_MB_ISO_Mitsubishi  = 43,
        etiming_TIMINGW_FORD_ISO9141_Mitsubishi  = 44,
        etiming_TIMINGW_GM_KW_Mitsubishi  = 45,
        etiming_TIMINGW_HONDA_BOSCH_Mitsubishi  = 46,
        etiming_TWUP_CHRYSLER_KW2000_Mitsubishi  = 47,
        etiming_TWUP_CHRYSLER_KWFB_Mitsubishi  = 48,
        etiming_TWUP_FORD_UBP_Mitsubishi  = 49,
        etiming_TWUP_GM_KW_Mitsubishi  = 50,
        etiming_TWUP_HONDA_92HM_Mitsubishi  = 51,
        etiming_TWUP_HONDA_95HM_Mitsubishi  = 52,
        etiming_TWUP_HONDA_H99B_Mitsubishi  = 53,
        etiming_TWUP_HONDA_KW2000_Mitsubishi  = 54,
        etiming_TWUP_TOYOTA_KW2000_9600_Mitsubishi  = 55,
        etiming_TWUPHONDA_00_Mitsubishi  = 56,
        etiming_TIMINGP_NORMAL_Mitsubishi  = 57,
        etiming_TIMINGP_CANNORMAL_Mitsubishi  = 58,
        etiming_TIMINGW_NORMAL_Mitsubishi  = 59,
        etiming_TWUPGENERAL_Mitsubishi  = 60,
        etiming_TWUP_GM_KW9600_Mitsubishi  = 61,
        etiming_TIMINGP_VOLVO_D2_Mitsubishi  = 62,
        etiming_TIMINGP_VOLVO_GGD_Mitsubishi  = 63,
        etiming_TIMINGP_VOLVO_KW_Mitsubishi  = 64,
        etiming_TIMINGW_VOLVO_D2_Mitsubishi  = 65,
        etiming_TWUP_VOLVO_KW_Mitsubishi  = 66,
        etiming_TWUP_VOLVO_GGD_Mitsubishi  = 67,
        etiming_TWUP_VOLVO_D2_Mitsubishi  = 68,
        etiming_TIMINGW_VOLVO_GGD_Mitsubishi  = 69,
        etiming_TIMINGW_VOLVO_KW_Mitsubishi  = 70,
        etiming_TIMINGP_BMW_KW2000_Mitsubishi  = 71,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_Mitsubishi  = 72,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_UDS_Mitsubishi  = 73,
        etiming_TIMINGP_NISSAN_DDL1_Mitsubishi  = 74,
        etiming_TIMINGP_MITSUBISHI_MUT_Mitsubishi  = 75,
        etiming_TIMINGW_MITSUBISHI_ISO9141_Mitsubishi  = 76,
    
    }enumTiming_Mitsubishi;
    
    
    typedef enum _enumErasetype_Mitsubishi{
        eerasetype_UNKNOWN_Mitsubishi   = 0,
        eerasetype_ERASETYPE_NONE_Mitsubishi  = 1,
    
    }enumErasetype_Mitsubishi;
    
    
    typedef enum _enumModel_Mitsubishi{
        emodel_UNKNOWN_Mitsubishi   = 0,
        emodel_3000GT_Mitsubishi  = 1,
        emodel_DIAMANTE_Mitsubishi  = 2,
        emodel_ECLIPSE_Mitsubishi  = 3,
        emodel_GALANT_Mitsubishi  = 4,
        emodel_MIGHTY_____MAX_Mitsubishi  = 5,
        emodel_MIRAGE_Mitsubishi  = 6,
        emodel_MONTERO_Mitsubishi  = 7,
        emodel_MONTERO_____SPORT_Mitsubishi  = 8,
        emodel_ECLIPSE_____SPYDER_Mitsubishi  = 9,
        emodel_LANCER_Mitsubishi  = 10,
        emodel_LANCER_____EVOLUTION_Mitsubishi  = 11,
        emodel_OUTLANDER_Mitsubishi  = 12,
        emodel_ENDEAVOR_Mitsubishi  = 13,
        emodel_LANCER_____SPORTBACK_Mitsubishi  = 14,
        emodel_RAIDER_Mitsubishi  = 15,
        emodel_OUTLANDER_____SPORT_Mitsubishi  = 16,
        emodel_RVR_Mitsubishi  = 17,
        emodel_I_MIEV_Mitsubishi  = 18,
    
    }enumModel_Mitsubishi;
    
    
    typedef enum _enumEngine_Mitsubishi{
        eengine_UNKNOWN_Mitsubishi   = 0,
        eengine_V6_____3_0L_Mitsubishi  = 1,
        eengine_L4_____1_5L_Mitsubishi  = 2,
        eengine_L4_____2_4L_Mitsubishi  = 3,
        eengine_L4_____2_0L_Mitsubishi  = 4,
        eengine_L4_____1_8L_Mitsubishi  = 5,
        eengine_V6_____3_8L_Mitsubishi  = 6,
        eengine_V6_____3_7L_Mitsubishi  = 7,
        eengine_V8_____4_7L_Mitsubishi  = 8,
        eengine_ELECTRIC_____MOTOR_Mitsubishi  = 9,
        eengine_L3_____1_2L_Mitsubishi  = 10,
        eengine_V6_____3_5L_Mitsubishi  = 11,
        eengine_L4_____1_6L_Mitsubishi  = 12,
    
    }enumEngine_Mitsubishi;
    

#endif