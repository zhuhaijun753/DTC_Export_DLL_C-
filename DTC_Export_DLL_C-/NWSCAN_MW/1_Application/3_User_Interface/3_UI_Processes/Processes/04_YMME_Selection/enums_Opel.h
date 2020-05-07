/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 10/14/2015
* Version   : V01.00.01
********************************************************************************************************************/


#ifndef __ENUMS_Opel_H__
#define __ENUMS_Opel_H__





typedef enum _enumCommand_Opel{
    ecommand_UNKNOWN_Opel   = 0,
    ecommand_3E_Opel  = 1,
    ecommand_82_Opel  = 2,
    ecommand_01_____3E_____00_____00_____00_____00_____00_____00_Opel  = 3,
    ecommand_F0_____F0_____10_____01_____19_____02_Opel  = 4,
    ecommand_B2_____00_Opel  = 5,
    ecommand_81_Opel  = 6,
    ecommand_14_____FF_____00_Opel  = 7,
    ecommand_18_____00_____FF_____00_Opel  = 8,
    ecommand_12_____00_Opel  = 9,
    ecommand_B1_____00_Opel  = 10,
    ecommand_01_____20_____00_____00_____00_____00_____00_____00_Opel  = 11,
    ecommand_01_____04_____00_____00_____00_____00_____00_____00_Opel  = 12,
    ecommand_03_____A9_____81_____12_____00_____00_____00_____00_Opel  = 13,
    ecommand_03_____A9_____81_____5A_____00_____00_____00_____00_Opel  = 14,
    ecommand_B0_____00_Opel  = 15,
    ecommand_11_____00_Opel  = 16,
    ecommand_10_____00_Opel  = 17,
}enumCommand_Opel;


typedef enum _enumReaddtccommandlist_Opel{
    ereaddtccommandlist_UNKNOWN_Opel   = 0,
    ereaddtccommandlist_18_____00_____FF_____00___1_Opel  = 1,
    ereaddtccommandlist_03_____A9_____81_____12_____00_____00_____00_____00___2_Opel  = 2,
    ereaddtccommandlist_03_____A9_____81_____5A_____00_____00_____00_____00___3_Opel  = 3,
}enumReaddtccommandlist_Opel;


typedef enum _enumCommandlist_Opel{
    ecommandlist_UNKNOWN_Opel   = 0,
    ecommandlist_81_Opel  = 1,
    ecommandlist_14_____FF_____00_Opel  = 2,
    ecommandlist_12_____00_Opel  = 3,
    ecommandlist_B1_____00_Opel  = 4,
    ecommandlist_01_____20_____00_____00_____00_____00_____00_____00_Opel  = 5,
    ecommandlist_01_____04_____00_____00_____00_____00_____00_____00_Opel  = 6,
    ecommandlist_B0_____00_Opel  = 7,
    ecommandlist_10_____00_Opel  = 8,
}enumCommandlist_Opel;


typedef enum _enumEcuinfotype_Opel{
    eecuinfotype_UNKNOWN_Opel   = 0,
}enumEcuinfotype_Opel;


typedef enum _enumDtcreadtype_Opel{
    edtcreadtype_UNKNOWN_Opel   = 0,
    edtcreadtype_ReadDTCType_ID0000_Opel  = 1,
    edtcreadtype_ReadDTCType_ID0001_Opel  = 2,
}enumDtcreadtype_Opel;


typedef enum _enumLookuptable_Opel{
    elookuptable_UNKNOWN_Opel   = 0,
}enumLookuptable_Opel;


typedef enum _enumMessageid_Opel{
    emessageid_UNKNOWN_Opel   = 0,
    emessageid_OPEL_ECM_KW_11_Opel  = 1,
    emessageid_OPEL_TCM_KW_18pin7_Opel  = 2,
    emessageid_OPEL_TCM_KW_18pin3_Opel  = 3,
    emessageid_OPEL_ABS_KW_28_Opel  = 4,
    emessageid_OPEL_SRS_KW_FB62_Opel  = 5,
    emessageid_OPEL_ECM_CAN614500k_Opel  = 6,
    emessageid_OPEL_ECM_CAN614500kType2_Opel  = 7,
    emessageid_OPEL_TCM_CAN614500K_Opel  = 8,
    emessageid_OPEL_ABS_CAN614500K_Opel  = 9,
    emessageid_OPEL_SDM_SWCAN133K_Opel  = 10,
    emessageid_OPEL_TCM_KW52_FB2D_Opel  = 11,
    emessageid_OPEL_SRS_KW52_FB61_Opel  = 12,
}enumMessageid_Opel;


typedef enum _enumSystem_Opel{
    esystem_UNKNOWN_Opel   = 0,
}enumSystem_Opel;


typedef enum _enumSubsystem_Opel{
    esubsystem_UNKNOWN_Opel   = 0,
}enumSubsystem_Opel;


typedef enum _enumTiming_Opel{
    etiming_UNKNOWN_Opel   = 0,
    etiming_Twup_GM_KW10400_Opel  = 1,
    etiming_TimingP_GM_KW_Opel  = 2,
    etiming_TimingW_GM_KW_Opel  = 3,
    etiming_TimingP_GM_CAN_Opel  = 4,
    etiming_TimingP_GM_SWCAN_Opel  = 5,
    etiming_Kw1281Default_Opel  = 6,
    etiming_TimingP_Chrysler_CAN_Opel  = 7,
    etiming_TimingP_Chrysler_CAN_C_UDS_Opel  = 8,
    etiming_TimingP_Chrysler_CAN_I_UDS_Opel  = 9,
    etiming_TimingP_Chrysler_CCD_Opel  = 10,
    etiming_TimingP_Chrysler_CCD2_Opel  = 11,
    etiming_TimingP_Chrysler_KW2000_Opel  = 12,
    etiming_TimingP_Chrysler_KWFB_Opel  = 13,
    etiming_TimingP_Chrysler_MB_ISO_Opel  = 14,
    etiming_TimingP_Chrysler_MUT_Opel  = 15,
    etiming_TimingP_Chrysler_SCI_Opel  = 16,
    etiming_TimingP_Chrysler_VPW_Opel  = 17,
    etiming_TimingP_Ford_CAN_Opel  = 18,
    etiming_TimingP_Ford_CAN_UDS_Opel  = 19,
    etiming_TimingP_Ford_ISO9141_Opel  = 20,
    etiming_TimingP_Ford_MCAN_Opel  = 21,
    etiming_TimingP_Ford_MCAN_____UDS_Opel  = 22,
    etiming_TimingP_Ford_PWM_Opel  = 23,
    etiming_TimingP_Ford_UBP_Opel  = 24,
    etiming_TimingP_GM_ALDL_Opel  = 25,
    etiming_TimingP_GM_GMLAN_Opel  = 26,
    etiming_TimingP_GM_SDL_Opel  = 27,
    etiming_TimingP_GM_VPW_Opel  = 28,
    etiming_TimingP_Honda_92HM_Opel  = 29,
    etiming_TimingP_Honda_95HM_Opel  = 30,
    etiming_TimingP_Honda_BOSCH_Opel  = 31,
    etiming_TimingP_Honda_CAN_Opel  = 32,
    etiming_TimingP_Honda_H99B_Opel  = 33,
    etiming_TimingP_Honda_KW2000_Opel  = 34,
    etiming_TimingP_Toyota_CAN_Opel  = 35,
    etiming_TimingP_Toyota_ISO9141_Opel  = 36,
    etiming_TimingP_Toyota_KW2000_Opel  = 37,
    etiming_TimingP_Toyota_VPW_Opel  = 38,
    etiming_TimingW_Chrysler_MB_ISO_Opel  = 39,
    etiming_TimingW_Chrysler_MUT_Opel  = 40,
    etiming_TimingW_Ford_ISO9141_Opel  = 41,
    etiming_TimingW_Honda_BOSCH_Opel  = 42,
    etiming_TimingW_Toyota_ISO9141_Opel  = 43,
    etiming_Twup_Chrysler_KW2000_Opel  = 44,
    etiming_Twup_Chrysler_KWFB_Opel  = 45,
    etiming_Twup_Ford_UBP_Opel  = 46,
    etiming_Twup_GM_KW_Opel  = 47,
    etiming_Twup_Honda_92HM_Opel  = 48,
    etiming_Twup_Honda_95HM_Opel  = 49,
    etiming_Twup_Honda_H99B_Opel  = 50,
    etiming_Twup_Honda_KW2000_Opel  = 51,
    etiming_Twup_Toyota_KW2000_10400_Opel  = 52,
    etiming_Twup_Toyota_KW2000_9600_Opel  = 53,
    etiming_TwupHonda_00_Opel  = 54,
    etiming_TimingP_Normal_Opel  = 55,
    etiming_TimingP_CANNormal_Opel  = 56,
    etiming_TimingW_Normal_Opel  = 57,
    etiming_TwupGeneral_Opel  = 58,
    etiming_Twup_GM_KW9600_Opel  = 59,
    etiming_TimingP_Volvo_D2_Opel  = 60,
    etiming_TimingP_Volvo_GGD_Opel  = 61,
    etiming_TimingP_Volvo_KW_Opel  = 62,
    etiming_TimingW_Volvo_D2_Opel  = 63,
    etiming_Twup_Volvo_KW_Opel  = 64,
    etiming_Twup_Volvo_GGD_Opel  = 65,
    etiming_Twup_Volvo_D2_Opel  = 66,
    etiming_TimingW_Volvo_GGD_Opel  = 67,
    etiming_TimingW_Volvo_KW_Opel  = 68,
    etiming_TimingP_BMW_KW2000_Opel  = 69,
    etiming_TimingP_Mercedes_Benz_CAN_Opel  = 70,
    etiming_TimingP_Mercedes_Benz_CAN_UDS_Opel  = 71,
    etiming_TimingP_Nissan_DDL1_Opel  = 72,
}enumTiming_Opel;


typedef enum _enumErasetype_Opel{
    eerasetype_UNKNOWN_Opel   = 0,
}enumErasetype_Opel;


typedef enum _enumModel_Opel{
    emodel_UNKNOWN_Opel   = 0,
}enumModel_Opel;


typedef enum _enumEngine_Opel{
    eengine_UNKNOWN_Opel   = 0,
}enumEngine_Opel;


#endif