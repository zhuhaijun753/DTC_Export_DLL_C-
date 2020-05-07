/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 10/14/2015
* Version   : V01.00.01
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
    esubsystem_ABS_Isuzu  = 1,
    esubsystem_SRS_Isuzu  = 2,
    esubsystem_ECM_Isuzu  = 3,
    esubsystem_TCM_Isuzu  = 4,
}enumSubsystem_Isuzu;


typedef enum _enumTiming_Isuzu{
    etiming_UNKNOWN_Isuzu   = 0,
    etiming_TimingP_Suzuki_CAN_Isuzu  = 1,
    etiming_Twup_GM_VPW_Isuzu  = 2,
    etiming_TimingP_GM_VPW_Isuzu  = 3,
    etiming_TimingW_GM_VPW_Isuzu  = 4,
    etiming_Twup_GM_ISO9141_Isuzu  = 5,
    etiming_TimingP_GM_ISO9141_Isuzu  = 6,
    etiming_TimingW_GM_ISO9141_Isuzu  = 7,
    etiming_Twup_Suzuki_KW_Isuzu  = 8,
    etiming_TimingP_Suzuki_KW_Isuzu  = 9,
    etiming_TimingW_Suzuki_KW_Isuzu  = 10,
    etiming_Kw1281Default_Isuzu  = 11,
    etiming_TimingP_Chrysler_CAN_Isuzu  = 12,
    etiming_TimingP_Chrysler_CAN_C_UDS_Isuzu  = 13,
    etiming_TimingP_Chrysler_CAN_I_UDS_Isuzu  = 14,
    etiming_TimingP_Chrysler_CCD_Isuzu  = 15,
    etiming_TimingP_Chrysler_CCD2_Isuzu  = 16,
    etiming_TimingP_Chrysler_KW2000_Isuzu  = 17,
    etiming_TimingP_Chrysler_KWFB_Isuzu  = 18,
    etiming_TimingP_Chrysler_MB_ISO_Isuzu  = 19,
    etiming_TimingP_Chrysler_MUT_Isuzu  = 20,
    etiming_TimingP_Chrysler_SCI_Isuzu  = 21,
    etiming_TimingP_Chrysler_VPW_Isuzu  = 22,
    etiming_TimingP_Ford_CAN_Isuzu  = 23,
    etiming_TimingP_Ford_CAN_UDS_Isuzu  = 24,
    etiming_TimingP_Ford_ISO9141_Isuzu  = 25,
    etiming_TimingP_Ford_MCAN_Isuzu  = 26,
    etiming_TimingP_Ford_MCAN_____UDS_Isuzu  = 27,
    etiming_TimingP_Ford_PWM_Isuzu  = 28,
    etiming_TimingP_Ford_UBP_Isuzu  = 29,
    etiming_TimingP_GM_ALDL_Isuzu  = 30,
    etiming_TimingP_GM_CAN_Isuzu  = 31,
    etiming_TimingP_GM_GMLAN_Isuzu  = 32,
    etiming_TimingP_GM_KW_Isuzu  = 33,
    etiming_TimingP_GM_SDL_Isuzu  = 34,
    etiming_TimingP_GM_SWCAN_Isuzu  = 35,
    etiming_TimingP_Honda_92HM_Isuzu  = 36,
    etiming_TimingP_Honda_95HM_Isuzu  = 37,
    etiming_TimingP_Honda_BOSCH_Isuzu  = 38,
    etiming_TimingP_Honda_CAN_Isuzu  = 39,
    etiming_TimingP_Honda_H99B_Isuzu  = 40,
    etiming_TimingP_Honda_KW2000_Isuzu  = 41,
    etiming_TimingP_Toyota_CAN_Isuzu  = 42,
    etiming_TimingP_Toyota_ISO9141_Isuzu  = 43,
    etiming_TimingP_Toyota_KW2000_Isuzu  = 44,
    etiming_TimingP_Toyota_VPW_Isuzu  = 45,
    etiming_TimingW_Chrysler_MB_ISO_Isuzu  = 46,
    etiming_TimingW_Chrysler_MUT_Isuzu  = 47,
    etiming_TimingW_Ford_ISO9141_Isuzu  = 48,
    etiming_TimingW_GM_KW_Isuzu  = 49,
    etiming_TimingW_Honda_BOSCH_Isuzu  = 50,
    etiming_TimingW_Toyota_ISO9141_Isuzu  = 51,
    etiming_Twup_Chrysler_KW2000_Isuzu  = 52,
    etiming_Twup_Chrysler_KWFB_Isuzu  = 53,
    etiming_Twup_Ford_UBP_Isuzu  = 54,
    etiming_Twup_GM_KW_Isuzu  = 55,
    etiming_Twup_Honda_92HM_Isuzu  = 56,
    etiming_Twup_Honda_95HM_Isuzu  = 57,
    etiming_Twup_Honda_H99B_Isuzu  = 58,
    etiming_Twup_Honda_KW2000_Isuzu  = 59,
    etiming_Twup_Toyota_KW2000_10400_Isuzu  = 60,
    etiming_Twup_Toyota_KW2000_9600_Isuzu  = 61,
    etiming_TwupHonda_00_Isuzu  = 62,
    etiming_TimingP_Normal_Isuzu  = 63,
    etiming_TimingP_CANNormal_Isuzu  = 64,
    etiming_TimingW_Normal_Isuzu  = 65,
    etiming_TwupGeneral_Isuzu  = 66,
    etiming_Twup_GM_KW9600_Isuzu  = 67,
    etiming_TimingP_Volvo_D2_Isuzu  = 68,
    etiming_TimingP_Volvo_GGD_Isuzu  = 69,
    etiming_TimingP_Volvo_KW_Isuzu  = 70,
    etiming_TimingW_Volvo_D2_Isuzu  = 71,
    etiming_Twup_Volvo_KW_Isuzu  = 72,
    etiming_Twup_Volvo_GGD_Isuzu  = 73,
    etiming_Twup_Volvo_D2_Isuzu  = 74,
    etiming_TimingW_Volvo_GGD_Isuzu  = 75,
    etiming_TimingW_Volvo_KW_Isuzu  = 76,
    etiming_TimingP_BMW_KW2000_Isuzu  = 77,
    etiming_TimingP_Mercedes_Benz_CAN_Isuzu  = 78,
    etiming_TimingP_Mercedes_Benz_CAN_UDS_Isuzu  = 79,
    etiming_TimingP_Nissan_DDL1_Isuzu  = 80,
}enumTiming_Isuzu;


typedef enum _enumErasetype_Isuzu{
    eerasetype_UNKNOWN_Isuzu   = 0,
}enumErasetype_Isuzu;


typedef enum _enumModel_Isuzu{
    emodel_UNKNOWN_Isuzu   = 0,
    emodel_Rodeo_Isuzu  = 1,
    emodel_Hombre_Isuzu  = 2,
    emodel_Oasis_Isuzu  = 3,
    emodel_Trooper_Isuzu  = 4,
    emodel_Amigo_Isuzu  = 5,
    emodel_VehiCross_Isuzu  = 6,
    emodel_Rodeo_____Sport_Isuzu  = 7,
    emodel_Axiom_Isuzu  = 8,
    emodel_Ascender_Isuzu  = 9,
    emodel_i_280_Isuzu  = 10,
    emodel_i_350_Isuzu  = 11,
    emodel_i_290_Isuzu  = 12,
    emodel_i_370_Isuzu  = 13,
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
    eengine_V6______3_5L______Gasoline______VIN8_X__Isuzu  = 14,
    eengine_V6______3_5L______Gasoline______VIN8_Y__Isuzu  = 15,
    eengine_L4______2_2L______Gasoline______VIN8_D__Isuzu  = 16,
    eengine_V6______3_2L______Gasoline______VIN8_W__Isuzu  = 17,
    eengine_L6______4_2L______Gasoline______VIN8_S__Isuzu  = 18,
    eengine_V8______5_3L______Gasoline______VIN8_P__Isuzu  = 19,
    eengine_V8______5_3L______Gasoline______VIN8_M__Isuzu  = 20,
    eengine_L4______2_8L______Gasoline______VIN8_8__Isuzu  = 21,
    eengine_L5______3_5L______Gasoline______VIN8_6__Isuzu  = 22,
    eengine_L4______2_9L______Gasoline______VIN8_9__Isuzu  = 23,
    eengine_L5_____3_7L______Gasoline______VIN8_E__Isuzu  = 24,
    eengine_L4______2_6L______Gasoline_Isuzu  = 25,
    eengine_V6______3_2L______Gasoline_Isuzu  = 26,
    eengine_L4______2_2L______Gasoline_Isuzu  = 27,
    eengine_V6______4_3L______Gasoline_Isuzu  = 28,
    eengine_L4______2_3L______Gasoline_Isuzu  = 29,
    eengine_V6______3_5L______Gasoline_Isuzu  = 30,
    eengine_L4______1_6L______Gasoline_Isuzu  = 31,
    eengine_L5______3_7L______Gasoline______VIN8_E__Isuzu  = 32,
    eengine_V6______3_5L______Gasoline______VIN_____8th___________X__Isuzu  = 33,
    eengine_V6______3_5L______Gasoline______VIN_____8th___________Y__Isuzu  = 34,
    eengine_L4______2_2L______Gasoline______VIN_____8th___________D__Isuzu  = 35,
    eengine_V6______3_2L______Gasoline______VIN_____8th___________W__Isuzu  = 36,
    eengine_L6______4_2L______Gasoline______VIN_____8th___________S__Isuzu  = 37,
    eengine_V8______5_3L______Gasoline______VIN_____8th___________P__Isuzu  = 38,
    eengine_V8______5_3L______Gasoline______VIN_____8th___________M__Isuzu  = 39,
    eengine_L4______2_8L______Gasoline______VIN_____8th___________8__Isuzu  = 40,
    eengine_L5______3_5L______Gasoline______VIN_____8th___________6__Isuzu  = 41,
    eengine_L4______2_9L______Gasoline______VIN_____8th___________9__Isuzu  = 42,
    eengine_L5_____3_7L______Gasoline______VIN_____8th___________E__Isuzu  = 43,
    eengine_L5______3_7L______Gasoline______VIN_____8th___________E__Isuzu  = 44,
}enumEngine_Isuzu;


#endif