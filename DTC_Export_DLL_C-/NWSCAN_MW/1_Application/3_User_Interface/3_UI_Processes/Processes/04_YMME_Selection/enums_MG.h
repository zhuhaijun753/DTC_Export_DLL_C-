/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 10/14/2015
* Version   : V01.00.01
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
    ereaddtccommandlist_18_____00_____00_____00_Current___1_MG  = 1,
    ereaddtccommandlist_18_____00_____80_____00_Current___18_____01_____80_____00_Current___2_MG  = 2,
    ereaddtccommandlist_18_____00_____FF_____00___3_MG  = 3,
    ereaddtccommandlist_18_____00_____00_____00_Current___18_____F0_____00_____00_Current___4_MG  = 4,
    ereaddtccommandlist_18_____00_____FF_____00_Current___5_MG  = 5,
    ereaddtccommandlist_03_____19_____02_____0C_____00_____00_____00_____00_Current___6_MG  = 6,
    ereaddtccommandlist_18_____F0_____00_____00_Current___7_MG  = 7,
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
    elookuptable_strtDTCTableProfile3_18_MG  = 1,
    elookuptable_strtDTCTableProfile3_28_MG  = 2,
    elookuptable_strtDTCTableProfile3_3_MG  = 3,
    elookuptable_strtDTCTableProfile51_MG  = 4,
    elookuptable_strtDTCTableProfile51_B_MG  = 5,
    elookuptable_strtDTCTableProfile3_27_MG  = 6,
    elookuptable_strtDTCTableProfile1_11_MG  = 7,
    elookuptable_strtDTCTableProfile3_31_MG  = 8,
    elookuptable_strtDTCTableProfile3_16_MG  = 9,
    elookuptable_strtDTCTableProfile6_5_MG  = 10,
    elookuptable_strtDTCTableProfile3_26_MG  = 11,
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
    etiming_Kw1281Default_MG  = 1,
    etiming_TimingP_Chrysler_CAN_MG  = 2,
    etiming_TimingP_Chrysler_CAN_C_UDS_MG  = 3,
    etiming_TimingP_Chrysler_CAN_I_UDS_MG  = 4,
    etiming_TimingP_Chrysler_CCD_MG  = 5,
    etiming_TimingP_Chrysler_CCD2_MG  = 6,
    etiming_TimingP_Chrysler_KW2000_MG  = 7,
    etiming_TimingP_Chrysler_KWFB_MG  = 8,
    etiming_TimingP_Chrysler_MB_ISO_MG  = 9,
    etiming_TimingP_Chrysler_MUT_MG  = 10,
    etiming_TimingP_Chrysler_SCI_MG  = 11,
    etiming_TimingP_Chrysler_VPW_MG  = 12,
    etiming_TimingP_Ford_CAN_MG  = 13,
    etiming_TimingP_Ford_CAN_UDS_MG  = 14,
    etiming_TimingP_Ford_ISO9141_MG  = 15,
    etiming_TimingP_Ford_MCAN_MG  = 16,
    etiming_TimingP_Ford_MCAN_____UDS_MG  = 17,
    etiming_TimingP_Ford_PWM_MG  = 18,
    etiming_TimingP_Ford_UBP_MG  = 19,
    etiming_TimingP_GM_ALDL_MG  = 20,
    etiming_TimingP_GM_CAN_MG  = 21,
    etiming_TimingP_GM_GMLAN_MG  = 22,
    etiming_TimingP_GM_KW_MG  = 23,
    etiming_TimingP_GM_SDL_MG  = 24,
    etiming_TimingP_GM_SWCAN_MG  = 25,
    etiming_TimingP_GM_VPW_MG  = 26,
    etiming_TimingP_Honda_92HM_MG  = 27,
    etiming_TimingP_Honda_95HM_MG  = 28,
    etiming_TimingP_Honda_BOSCH_MG  = 29,
    etiming_TimingP_Honda_CAN_MG  = 30,
    etiming_TimingP_Honda_H99B_MG  = 31,
    etiming_TimingP_Honda_KW2000_MG  = 32,
    etiming_TimingP_Toyota_CAN_MG  = 33,
    etiming_TimingP_Toyota_ISO9141_MG  = 34,
    etiming_TimingP_Toyota_KW2000_MG  = 35,
    etiming_TimingP_Toyota_VPW_MG  = 36,
    etiming_TimingW_Chrysler_MB_ISO_MG  = 37,
    etiming_TimingW_Chrysler_MUT_MG  = 38,
    etiming_TimingW_Ford_ISO9141_MG  = 39,
    etiming_TimingW_GM_KW_MG  = 40,
    etiming_TimingW_Honda_BOSCH_MG  = 41,
    etiming_TimingW_Toyota_ISO9141_MG  = 42,
    etiming_Twup_Chrysler_KW2000_MG  = 43,
    etiming_Twup_Chrysler_KWFB_MG  = 44,
    etiming_Twup_Ford_UBP_MG  = 45,
    etiming_Twup_GM_KW_MG  = 46,
    etiming_Twup_Honda_92HM_MG  = 47,
    etiming_Twup_Honda_95HM_MG  = 48,
    etiming_Twup_Honda_H99B_MG  = 49,
    etiming_Twup_Honda_KW2000_MG  = 50,
    etiming_Twup_Toyota_KW2000_10400_MG  = 51,
    etiming_Twup_Toyota_KW2000_9600_MG  = 52,
    etiming_TwupHonda_00_MG  = 53,
    etiming_TimingP_Normal_MG  = 54,
    etiming_TimingP_CANNormal_MG  = 55,
    etiming_TimingW_Normal_MG  = 56,
    etiming_TwupGeneral_MG  = 57,
    etiming_Twup_GM_KW9600_MG  = 58,
    etiming_TimingP_Volvo_D2_MG  = 59,
    etiming_TimingP_Volvo_GGD_MG  = 60,
    etiming_TimingP_Volvo_KW_MG  = 61,
    etiming_TimingW_Volvo_D2_MG  = 62,
    etiming_Twup_Volvo_KW_MG  = 63,
    etiming_Twup_Volvo_GGD_MG  = 64,
    etiming_Twup_Volvo_D2_MG  = 65,
    etiming_TimingW_Volvo_GGD_MG  = 66,
    etiming_TimingW_Volvo_KW_MG  = 67,
    etiming_TimingP_BMW_KW2000_MG  = 68,
    etiming_TimingP_Mercedes_Benz_CAN_MG  = 69,
    etiming_TimingP_Mercedes_Benz_CAN_UDS_MG  = 70,
    etiming_TimingP_Nissan_DDL1_MG  = 71,
}enumTiming_MG;


typedef enum _enumErasetype_MG{
    eerasetype_UNKNOWN_MG   = 0,
    eerasetype_EraseType_None_MG  = 1,
}enumErasetype_MG;


typedef enum _enumModel_MG{
    emodel_UNKNOWN_MG   = 0,
    emodel_MG_____7_MG  = 1,
    emodel_MG_____750__MG  = 2,
    emodel_MG_____6_MG  = 3,
    emodel_MG_____3_MG  = 4,
}enumModel_MG;


typedef enum _enumEngine_MG{
    eengine_UNKNOWN_MG   = 0,
}enumEngine_MG;


#endif