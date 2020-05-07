/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 9/29/2015
********************************************************************************************************************/

#ifndef __ENUMS_MG_H__
#define __ENUMS_MG_H__



    
    typedef enum _enumCommand_MG{
        ecommand_UNKNOWN_MG   = 0,
        ecommand_01_MG  = 1,
        ecommand_82_MG  = 2,
        ecommand_81_MG  = 3,
        ecommand_14_____00_____00_MG  = 4,
        ecommand_18_____00_____00_____00_MG  = 5,
        ecommand_14_____80_____00_MG  = 6,
        ecommand_18_____00_____80_____00_MG  = 7,
        ecommand_18_____01_____80_____00_MG  = 8,
        ecommand_14_____FF_____00_MG  = 9,
        ecommand_18_____00_____FF_____00_MG  = 10,
        ecommand_18_____F0_____00_____00_MG  = 11,
        ecommand_02_____10_____03_____00_____00_____00_____00_____00_MG  = 12,
        ecommand_04_____14_____FF_____FF_____FF_____00_____00_____00_MG  = 13,
        ecommand_03_____19_____02_____0C_____00_____00_____00_____00_MG  = 14,
    
    }enumCommand_MG;
    
    
    typedef enum _enumReaddtccommandlist_MG{
        ereaddtccommandlist_UNKNOWN_MG   = 0,
        ereaddtccommandlist_18_____00_____00_____00_CURRENT___1_MG  = 1,
        ereaddtccommandlist_18_____00_____80_____00_CURRENT___18_____01_____80_____00_CURRENT___2_MG  = 2,
        ereaddtccommandlist_18_____00_____FF_____00___3_MG  = 3,
        ereaddtccommandlist_18_____00_____00_____00_CURRENT___18_____F0_____00_____00_CURRENT___4_MG  = 4,
        ereaddtccommandlist_18_____00_____FF_____00_CURRENT___5_MG  = 5,
        ereaddtccommandlist_03_____19_____02_____0C_____00_____00_____00_____00_CURRENT___6_MG  = 6,
        ereaddtccommandlist_18_____F0_____00_____00_CURRENT___7_MG  = 7,
    
    }enumReaddtccommandlist_MG;
    
    
    typedef enum _enumCommandlist_MG{
        ecommandlist_UNKNOWN_MG   = 0,
        ecommandlist_81_MG  = 1,
        ecommandlist_14_____00_____00_MG  = 2,
        ecommandlist_14_____80_____00_MG  = 3,
        ecommandlist_14_____FF_____00_MG  = 4,
        ecommandlist_02_____10_____03_____00_____00_____00_____00_____00_MG  = 5,
        ecommandlist_04_____14_____FF_____FF_____FF_____00_____00_____00_MG  = 6,
    
    }enumCommandlist_MG;
    
    
    typedef enum _enumEcuinfotype_MG{
        eecuinfotype_UNKNOWN_MG   = 0,
    
    }enumEcuinfotype_MG;
    
    
    typedef enum _enumDtcreadtype_MG{
        edtcreadtype_UNKNOWN_MG   = 0,
    
    }enumDtcreadtype_MG;
    
    
    typedef enum _enumLookuptable_MG{
        elookuptable_UNKNOWN_MG   = 0,
        elookuptable_STRTDTCTABLEPROFILE3_18_MG  = 1,
        elookuptable_STRTDTCTABLEPROFILE3_28_MG  = 2,
        elookuptable_STRTDTCTABLEPROFILE3_3_MG  = 3,
        elookuptable_STRTDTCTABLEPROFILE51_MG  = 4,
        elookuptable_STRTDTCTABLEPROFILE51_B_MG  = 5,
        elookuptable_STRTDTCTABLEPROFILE3_27_MG  = 6,
        elookuptable_STRTDTCTABLEPROFILE1_11_MG  = 7,
        elookuptable_STRTDTCTABLEPROFILE3_31_MG  = 8,
        elookuptable_STRTDTCTABLEPROFILE3_16_MG  = 9,
        elookuptable_STRTDTCTABLEPROFILE6_5_MG  = 10,
        elookuptable_STRTDTCTABLEPROFILE3_26_MG  = 11,
    
    }enumLookuptable_MG;
    
    
    typedef enum _enumMessageid_MG{
        emessageid_UNKNOWN_MG   = 0,
        emessageid_ECM_001_MG  = 1,
        emessageid_SRS_002_MG  = 2,
        emessageid_ABS_003_MG  = 3,
        emessageid_ECM_005_MG  = 4,
        emessageid_ABS_006_MG  = 5,
        emessageid_TCM_007_MG  = 6,
        emessageid_ECM_008_MG  = 7,
        emessageid_ECM_009_MG  = 8,
    
    }enumMessageid_MG;
    
    
    typedef enum _enumSystem_MG{
        esystem_UNKNOWN_MG   = 0,
    
    }enumSystem_MG;
    
    
    typedef enum _enumSubsystem_MG{
        esubsystem_UNKNOWN_MG   = 0,
    
    }enumSubsystem_MG;
    
    
    typedef enum _enumTiming_MG{
        etiming_UNKNOWN_MG   = 0,
        etiming_KW1281DEFAULT_MG  = 1,
        etiming_TIMINGP_CHRYSLER_CAN_MG  = 2,
        etiming_TIMINGP_CHRYSLER_CAN_C_UDS_MG  = 3,
        etiming_TIMINGP_CHRYSLER_CAN_I_UDS_MG  = 4,
        etiming_TIMINGP_CHRYSLER_CCD_MG  = 5,
        etiming_TIMINGP_CHRYSLER_CCD2_MG  = 6,
        etiming_TIMINGP_CHRYSLER_KW2000_MG  = 7,
        etiming_TIMINGP_CHRYSLER_KWFB_MG  = 8,
        etiming_TIMINGP_CHRYSLER_MB_ISO_MG  = 9,
        etiming_TIMINGP_CHRYSLER_MUT_MG  = 10,
        etiming_TIMINGP_CHRYSLER_SCI_MG  = 11,
        etiming_TIMINGP_CHRYSLER_VPW_MG  = 12,
        etiming_TIMINGP_FORD_CAN_MG  = 13,
        etiming_TIMINGP_FORD_CAN_UDS_MG  = 14,
        etiming_TIMINGP_FORD_ISO9141_MG  = 15,
        etiming_TIMINGP_FORD_MCAN_MG  = 16,
        etiming_TIMINGP_FORD_MCAN_____UDS_MG  = 17,
        etiming_TIMINGP_FORD_PWM_MG  = 18,
        etiming_TIMINGP_FORD_UBP_MG  = 19,
        etiming_TIMINGP_GM_ALDL_MG  = 20,
        etiming_TIMINGP_GM_CAN_MG  = 21,
        etiming_TIMINGP_GM_GMLAN_MG  = 22,
        etiming_TIMINGP_GM_KW_MG  = 23,
        etiming_TIMINGP_GM_SDL_MG  = 24,
        etiming_TIMINGP_GM_SWCAN_MG  = 25,
        etiming_TIMINGP_GM_VPW_MG  = 26,
        etiming_TIMINGP_HONDA_92HM_MG  = 27,
        etiming_TIMINGP_HONDA_95HM_MG  = 28,
        etiming_TIMINGP_HONDA_BOSCH_MG  = 29,
        etiming_TIMINGP_HONDA_CAN_MG  = 30,
        etiming_TIMINGP_HONDA_H99B_MG  = 31,
        etiming_TIMINGP_HONDA_KW2000_MG  = 32,
        etiming_TIMINGP_TOYOTA_CAN_MG  = 33,
        etiming_TIMINGP_TOYOTA_ISO9141_MG  = 34,
        etiming_TIMINGP_TOYOTA_KW2000_MG  = 35,
        etiming_TIMINGP_TOYOTA_VPW_MG  = 36,
        etiming_TIMINGW_CHRYSLER_MB_ISO_MG  = 37,
        etiming_TIMINGW_CHRYSLER_MUT_MG  = 38,
        etiming_TIMINGW_FORD_ISO9141_MG  = 39,
        etiming_TIMINGW_GM_KW_MG  = 40,
        etiming_TIMINGW_HONDA_BOSCH_MG  = 41,
        etiming_TIMINGW_TOYOTA_ISO9141_MG  = 42,
        etiming_TWUP_CHRYSLER_KW2000_MG  = 43,
        etiming_TWUP_CHRYSLER_KWFB_MG  = 44,
        etiming_TWUP_FORD_UBP_MG  = 45,
        etiming_TWUP_GM_KW_MG  = 46,
        etiming_TWUP_HONDA_92HM_MG  = 47,
        etiming_TWUP_HONDA_95HM_MG  = 48,
        etiming_TWUP_HONDA_H99B_MG  = 49,
        etiming_TWUP_HONDA_KW2000_MG  = 50,
        etiming_TWUP_TOYOTA_KW2000_10400_MG  = 51,
        etiming_TWUP_TOYOTA_KW2000_9600_MG  = 52,
        etiming_TWUPHONDA_00_MG  = 53,
        etiming_TIMINGP_NORMAL_MG  = 54,
        etiming_TIMINGP_CANNORMAL_MG  = 55,
        etiming_TIMINGW_NORMAL_MG  = 56,
        etiming_TWUPGENERAL_MG  = 57,
        etiming_TWUP_GM_KW9600_MG  = 58,
        etiming_TIMINGP_VOLVO_D2_MG  = 59,
        etiming_TIMINGP_VOLVO_GGD_MG  = 60,
        etiming_TIMINGP_VOLVO_KW_MG  = 61,
        etiming_TIMINGW_VOLVO_D2_MG  = 62,
        etiming_TWUP_VOLVO_KW_MG  = 63,
        etiming_TWUP_VOLVO_GGD_MG  = 64,
        etiming_TWUP_VOLVO_D2_MG  = 65,
        etiming_TIMINGW_VOLVO_GGD_MG  = 66,
        etiming_TIMINGW_VOLVO_KW_MG  = 67,
        etiming_TIMINGP_BMW_KW2000_MG  = 68,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_MG  = 69,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_UDS_MG  = 70,
        etiming_TIMINGP_NISSAN_DDL1_MG  = 71,
    
    }enumTiming_MG;
    
    
    typedef enum _enumErasetype_MG{
        eerasetype_UNKNOWN_MG   = 0,
        eerasetype_ERASETYPE_NONE_MG  = 1,
    
    }enumErasetype_MG;
    
    
    typedef enum _enumModel_MG{
        emodel_UNKNOWN_MG   = 0,
    
    }enumModel_MG;
    
    
    typedef enum _enumEngine_MG{
        eengine_UNKNOWN_MG   = 0,
    
    }enumEngine_MG;
    

#endif