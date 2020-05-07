/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 10/14/2015
* Version   : V01.00.01
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
    edtcreadtype_ReadDTCType_None_Mitsubishi  = 1,
    edtcreadtype_ReadDTCType_ID0000_Mitsubishi  = 2,
}enumDtcreadtype_Mitsubishi;


typedef enum _enumLookuptable_Mitsubishi{
    elookuptable_UNKNOWN_Mitsubishi   = 0,
    elookuptable_DTC_MUT_Mitsubishi  = 1,
}enumLookuptable_Mitsubishi;


typedef enum _enumMessageid_Mitsubishi{
    emessageid_UNKNOWN_Mitsubishi   = 0,
    emessageid_Mitsubishi_ECM_CAN_500_7E0_7E8_Mitsubishi  = 1,
    emessageid_Mitsubishi_ECM_ISO9141_10400_Mitsubishi  = 2,
    emessageid_Mitsubishi_ECM_MUT_15600_Mitsubishi  = 3,
    emessageid_Mitsubishi_TCM_CAN_500_7E1_7E9_Mitsubishi  = 4,
    emessageid_Mitsubishi_TCM_MUT_15600_Mitsubishi  = 5,
    emessageid_Mitsubishi_ABS_CAN_500_784_785_Mitsubishi  = 6,
    emessageid_Mitsubishi_ABS_CAN_500_78A_78B_Mitsubishi  = 7,
    emessageid_Mitsubishi_ABS_MUT_15600_Mitsubishi  = 8,
    emessageid_Mitsubishi_SRS_CAN_500_6E0_51C_Mitsubishi  = 9,
    emessageid_Mitsubishi_SRS_CAN_500_78C_78D_Mitsubishi  = 10,
    emessageid_Mitsubishi_SRS_KW2000_10400_Mitsubishi  = 11,
    emessageid_Mitsubishi_SRS_MUT_15600_Mitsubishi  = 12,
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
    etiming_TimingP_Toyota_CAN_Mitsubishi  = 1,
    etiming_Twup_Toyota_ISO9141_Mitsubishi  = 2,
    etiming_TimingP_Toyota_ISO9141_Mitsubishi  = 3,
    etiming_TimingW_Toyota_ISO9141_Mitsubishi  = 4,
    etiming_Twup_Chrysler_MUT_Mitsubishi  = 5,
    etiming_TimingP_Chrysler_MUT_Mitsubishi  = 6,
    etiming_TimingW_Chrysler_MUT_Mitsubishi  = 7,
    etiming_Twup_Toyota_KW2000_10400_Mitsubishi  = 8,
    etiming_TimingP_Toyota_KW2000_Mitsubishi  = 9,
    etiming_TimingW_Toyota_KW2000_Mitsubishi  = 10,
    etiming_Kw1281Default_Mitsubishi  = 11,
    etiming_TimingP_Chrysler_CAN_Mitsubishi  = 12,
    etiming_TimingP_Chrysler_CAN_C_UDS_Mitsubishi  = 13,
    etiming_TimingP_Chrysler_CAN_I_UDS_Mitsubishi  = 14,
    etiming_TimingP_Chrysler_CCD_Mitsubishi  = 15,
    etiming_TimingP_Chrysler_CCD2_Mitsubishi  = 16,
    etiming_TimingP_Chrysler_KW2000_Mitsubishi  = 17,
    etiming_TimingP_Chrysler_KWFB_Mitsubishi  = 18,
    etiming_TimingP_Chrysler_MB_ISO_Mitsubishi  = 19,
    etiming_TimingP_Chrysler_SCI_Mitsubishi  = 20,
    etiming_TimingP_Chrysler_VPW_Mitsubishi  = 21,
    etiming_TimingP_Ford_CAN_Mitsubishi  = 22,
    etiming_TimingP_Ford_CAN_UDS_Mitsubishi  = 23,
    etiming_TimingP_Ford_ISO9141_Mitsubishi  = 24,
    etiming_TimingP_Ford_MCAN_Mitsubishi  = 25,
    etiming_TimingP_Ford_MCAN_____UDS_Mitsubishi  = 26,
    etiming_TimingP_Ford_PWM_Mitsubishi  = 27,
    etiming_TimingP_Ford_UBP_Mitsubishi  = 28,
    etiming_TimingP_GM_ALDL_Mitsubishi  = 29,
    etiming_TimingP_GM_CAN_Mitsubishi  = 30,
    etiming_TimingP_GM_GMLAN_Mitsubishi  = 31,
    etiming_TimingP_GM_KW_Mitsubishi  = 32,
    etiming_TimingP_GM_SDL_Mitsubishi  = 33,
    etiming_TimingP_GM_SWCAN_Mitsubishi  = 34,
    etiming_TimingP_GM_VPW_Mitsubishi  = 35,
    etiming_TimingP_Honda_92HM_Mitsubishi  = 36,
    etiming_TimingP_Honda_95HM_Mitsubishi  = 37,
    etiming_TimingP_Honda_BOSCH_Mitsubishi  = 38,
    etiming_TimingP_Honda_CAN_Mitsubishi  = 39,
    etiming_TimingP_Honda_H99B_Mitsubishi  = 40,
    etiming_TimingP_Honda_KW2000_Mitsubishi  = 41,
    etiming_TimingP_Toyota_VPW_Mitsubishi  = 42,
    etiming_TimingW_Chrysler_MB_ISO_Mitsubishi  = 43,
    etiming_TimingW_Ford_ISO9141_Mitsubishi  = 44,
    etiming_TimingW_GM_KW_Mitsubishi  = 45,
    etiming_TimingW_Honda_BOSCH_Mitsubishi  = 46,
    etiming_Twup_Chrysler_KW2000_Mitsubishi  = 47,
    etiming_Twup_Chrysler_KWFB_Mitsubishi  = 48,
    etiming_Twup_Ford_UBP_Mitsubishi  = 49,
    etiming_Twup_GM_KW_Mitsubishi  = 50,
    etiming_Twup_Honda_92HM_Mitsubishi  = 51,
    etiming_Twup_Honda_95HM_Mitsubishi  = 52,
    etiming_Twup_Honda_H99B_Mitsubishi  = 53,
    etiming_Twup_Honda_KW2000_Mitsubishi  = 54,
    etiming_Twup_Toyota_KW2000_9600_Mitsubishi  = 55,
    etiming_TwupHonda_00_Mitsubishi  = 56,
    etiming_TimingP_Normal_Mitsubishi  = 57,
    etiming_TimingP_CANNormal_Mitsubishi  = 58,
    etiming_TimingW_Normal_Mitsubishi  = 59,
    etiming_TwupGeneral_Mitsubishi  = 60,
    etiming_Twup_GM_KW9600_Mitsubishi  = 61,
    etiming_TimingP_Volvo_D2_Mitsubishi  = 62,
    etiming_TimingP_Volvo_GGD_Mitsubishi  = 63,
    etiming_TimingP_Volvo_KW_Mitsubishi  = 64,
    etiming_TimingW_Volvo_D2_Mitsubishi  = 65,
    etiming_Twup_Volvo_KW_Mitsubishi  = 66,
    etiming_Twup_Volvo_GGD_Mitsubishi  = 67,
    etiming_Twup_Volvo_D2_Mitsubishi  = 68,
    etiming_TimingW_Volvo_GGD_Mitsubishi  = 69,
    etiming_TimingW_Volvo_KW_Mitsubishi  = 70,
    etiming_TimingP_BMW_KW2000_Mitsubishi  = 71,
    etiming_TimingP_Mercedes_Benz_CAN_Mitsubishi  = 72,
    etiming_TimingP_Mercedes_Benz_CAN_UDS_Mitsubishi  = 73,
    etiming_TimingP_Nissan_DDL1_Mitsubishi  = 74,
    etiming_TimingP_Mitsubishi_MUT_Mitsubishi  = 75,
    etiming_TimingW_Mitsubishi_ISO9141_Mitsubishi  = 76,
}enumTiming_Mitsubishi;


typedef enum _enumErasetype_Mitsubishi{
    eerasetype_UNKNOWN_Mitsubishi   = 0,
    eerasetype_EraseType_None_Mitsubishi  = 1,
}enumErasetype_Mitsubishi;


typedef enum _enumModel_Mitsubishi{
    emodel_UNKNOWN_Mitsubishi   = 0,
    emodel_3000GT_Mitsubishi  = 1,
    emodel_Diamante_Mitsubishi  = 2,
    emodel_Eclipse_Mitsubishi  = 3,
    emodel_Galant_Mitsubishi  = 4,
    emodel_Mighty_____Max_Mitsubishi  = 5,
    emodel_Mirage_Mitsubishi  = 6,
    emodel_Montero_Mitsubishi  = 7,
    emodel_Montero_____Sport_Mitsubishi  = 8,
    emodel_Eclipse_____Spyder_Mitsubishi  = 9,
    emodel_Lancer_Mitsubishi  = 10,
    emodel_Lancer_____Evolution_Mitsubishi  = 11,
    emodel_Outlander_Mitsubishi  = 12,
    emodel_Endeavor_Mitsubishi  = 13,
    emodel_Lancer_____Sportback_Mitsubishi  = 14,
    emodel_Raider_Mitsubishi  = 15,
    emodel_Outlander_____Sport_Mitsubishi  = 16,
    emodel_RVR_Mitsubishi  = 17,
    emodel_i_MiEV_Mitsubishi  = 18,
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
    eengine_Electric_____Motor_Mitsubishi  = 9,
    eengine_L3_____1_2L_Mitsubishi  = 10,
    eengine_V6_____3_5L_Mitsubishi  = 11,
    eengine_L4_____1_6L_Mitsubishi  = 12,
}enumEngine_Mitsubishi;


#endif