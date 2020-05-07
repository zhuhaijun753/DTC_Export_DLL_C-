/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 9/29/2015
********************************************************************************************************************/

#ifndef __ENUMS_Ford_H__
#define __ENUMS_Ford_H__



    
    typedef enum _enumCommand_Ford{
        ecommand_UNKNOWN_Ford   = 0,
        ecommand_3E_____01_Ford  = 1,
        ecommand_02_____3E_____01_____00_____00_____00_____00_____00_Ford  = 2,
        ecommand_22_____02_____00_Ford  = 3,
        ecommand_14_Ford  = 4,
        ecommand_13_____FF_____FF_Ford  = 5,
        ecommand_13_Ford  = 6,
        ecommand_03_____22_____02_____00_____00_____00_____00_____00_Ford  = 7,
        ecommand_03_____14_____FF_____00_____00_____00_____00_____00_Ford  = 8,
        ecommand_04_____18_____00_____FF_____00_____00_____00_____00_Ford  = 9,
        ecommand_22_____F1_____13_Ford  = 10,
        ecommand_03_____22_____02_____02_____00_____00_____00_____00_Ford  = 11,
        ecommand_04_____14_____FF_____FF_____FF_____00_____00_____00_Ford  = 12,
        ecommand_03_____19_____02_____8F_____00_____00_____00_____00_Ford  = 13,
        ecommand_00_Ford  = 14,
        ecommand_03_____22_____DE_____1D_____00_____00_____00_____00_Ford  = 15,
        ecommand_04_____31_____01_____20_____1A_____00_____00_____00_Ford  = 16,
        ecommand_3E_Ford  = 17,
        ecommand_FF_Ford  = 18,
        ecommand_D0_Ford  = 19,
        ecommand_C1_Ford  = 20,
        ecommand_D1_Ford  = 21,
        ecommand_81_Ford  = 22,
        ecommand_1A_____80_Ford  = 23,
        ecommand_A3_Ford  = 24,
    
    }enumCommand_Ford;
    
    
    typedef enum _enumReaddtccommandlist_Ford{
        ereaddtccommandlist_UNKNOWN_Ford   = 0,
        ereaddtccommandlist_13_____FF_____FF_CM___1_Ford  = 1,
        ereaddtccommandlist_13_CM___2_Ford  = 2,
        ereaddtccommandlist_04_____18_____00_____FF_____00_____00_____00_____00_CM___3_Ford  = 3,
        ereaddtccommandlist_03_____19_____02_____8F_____00_____00_____00_____00_CM___4_Ford  = 4,
        ereaddtccommandlist_00___5_Ford  = 5,
        ereaddtccommandlist_D1___6_Ford  = 6,
        ereaddtccommandlist_D1___7_Ford  = 7,
        ereaddtccommandlist_A3___8_Ford  = 8,
    
    }enumReaddtccommandlist_Ford;
    
    
    typedef enum _enumCommandlist_Ford{
        ecommandlist_UNKNOWN_Ford   = 0,
        ecommandlist_22_____02_____00_Ford  = 1,
        ecommandlist_14_Ford  = 2,
        ecommandlist_03_____22_____02_____00_____00_____00_____00_____00_Ford  = 3,
        ecommandlist_03_____14_____FF_____00_____00_____00_____00_____00_Ford  = 4,
        ecommandlist_22_____F1_____13_Ford  = 5,
        ecommandlist_03_____22_____02_____02_____00_____00_____00_____00_Ford  = 6,
        ecommandlist_04_____14_____FF_____FF_____FF_____00_____00_____00_Ford  = 7,
        ecommandlist_00_Ford  = 8,
        ecommandlist_FF_Ford  = 9,
        ecommandlist_D0_Ford  = 10,
        ecommandlist_C1_Ford  = 11,
        ecommandlist_81_Ford  = 12,
        ecommandlist_1A_____80_Ford  = 13,
    
    }enumCommandlist_Ford;
    
    
    typedef enum _enumEcuinfotype_Ford{
        eecuinfotype_UNKNOWN_Ford   = 0,
        eecuinfotype_ECUTYPE_ID0001_Ford  = 1,
    
    }enumEcuinfotype_Ford;
    
    
    typedef enum _enumDtcreadtype_Ford{
        edtcreadtype_UNKNOWN_Ford   = 0,
        edtcreadtype_READDTCTYPE_ID0000_Ford  = 1,
        edtcreadtype_READDTCTYPE_ID0001_Ford  = 2,
        edtcreadtype_READDTCTYPE_ID0002_Ford  = 3,
        edtcreadtype_READDTCTYPE_ID0003_Ford  = 4,
        edtcreadtype_READDTCTYPE_ID0004_Ford  = 5,
        edtcreadtype_READDTCTYPE_ID0005_Ford  = 6,
        edtcreadtype_00_Ford  = 7,
    
    }enumDtcreadtype_Ford;
    
    
    typedef enum _enumLookuptable_Ford{
        elookuptable_UNKNOWN_Ford   = 0,
        elookuptable_DTC_____PARSER_____01_Ford  = 1,
    
    }enumLookuptable_Ford;
    
    
    typedef enum _enumMessageid_Ford{
        emessageid_UNKNOWN_Ford   = 0,
        emessageid_FORD_PCM_PWM_001_Ford  = 1,
        emessageid_FORD_PCM_ISO_____9141_002_Ford  = 2,
        emessageid_FORD_ABS_ISO_____9141_003_Ford  = 3,
        emessageid_FORD_ABS_PWM_004_Ford  = 4,
        emessageid_FORD_ACM_PWM_005_Ford  = 5,
        emessageid_FORD_CPM_PWM_006_Ford  = 6,
        emessageid_FORD_DDM_PWM_007_Ford  = 7,
        emessageid_FORD_DSM_PWM_008_Ford  = 8,
        emessageid_FORD_IABM_ISO_____9141_009_Ford  = 9,
        emessageid_FORD_EATC_PWM_010_Ford  = 10,
        emessageid_FORD_LCM_PWM_011_Ford  = 11,
        emessageid_FORD_RESCU_PWM_012_Ford  = 12,
        emessageid_FORD_VDM_PWM_013_Ford  = 13,
        emessageid_FORD_VIC_PWM_014_Ford  = 14,
        emessageid_FORD_CSM_ISO_____9141_015_Ford  = 15,
        emessageid_FORD_LCM_ISO_____9141_016_Ford  = 16,
        emessageid_FORD_FIM_PWM_017_Ford  = 17,
        emessageid_FORD_DDM_ISO_____9141_018_Ford  = 18,
        emessageid_FORD_DSM_ISO_____9141_019_Ford  = 19,
        emessageid_FORD_GEM_ISO_____9141_020_Ford  = 20,
        emessageid_FORD_RAP_ISO_____9141_021_Ford  = 21,
        emessageid_FORD_ARC_ISO_____9141_022_Ford  = 22,
        emessageid_FORD_PATS_PWM_023_Ford  = 23,
        emessageid_FORD_RCC_PWM_024_Ford  = 24,
        emessageid_FORD_SARC_ISO_____9141_025_Ford  = 25,
        emessageid_FORD_ECS_ISO_____9141_026_Ford  = 26,
        emessageid_FORD_4WAS_ISO_____9141_027_Ford  = 27,
        emessageid_FORD_HEC_PWM_028_Ford  = 28,
        emessageid_FORD_MC_PWM_029_Ford  = 29,
        emessageid_FORD_SCIL_PWM_030_Ford  = 30,
        emessageid_FORD_PSM_ISO_____9141_031_Ford  = 31,
        emessageid_FORD_NGSC_PWM_032_Ford  = 32,
        emessageid_FORD_PATS_ISO_____9141_033_Ford  = 33,
        emessageid_FORD_HEC_ISO_____9141_034_Ford  = 34,
        emessageid_FORD_PAM_ISO_____9141_035_Ford  = 35,
        emessageid_FORD_RASM_PWM_036_Ford  = 36,
        emessageid_FORD_RCM_ISO_____9141_037_Ford  = 37,
        emessageid_FORD_IC_PWM_038_Ford  = 38,
        emessageid_FORD_OTC_ISO_____9141_039_Ford  = 39,
        emessageid_FORD_FEM_PWM_040_Ford  = 40,
        emessageid_FORD_REM_PWM_041_Ford  = 41,
        emessageid_FORD_LPSDM_ISO_____9141_042_Ford  = 42,
        emessageid_FORD_RPSDM_ISO_____9141_043_Ford  = 43,
        emessageid_FORD_MC_ISO_____9141_044_Ford  = 44,
        emessageid_FORD_AFCM_PWM_045_Ford  = 45,
        emessageid_FORD_CTM_ISO_____9141_046_Ford  = 46,
        emessageid_FORD_INST_PWM_047_Ford  = 47,
        emessageid_FORD_4X4M_ISO_____9141_048_Ford  = 48,
        emessageid_FORD_ICU_PWM_049_Ford  = 49,
        emessageid_FORD_FFH_ISO_____9141_050_Ford  = 50,
        emessageid_FORD_RASM_ISO_____9141_051_Ford  = 51,
        emessageid_FORD_LTM_ISO_____9141_052_Ford  = 52,
        emessageid_FORD_EATC_UBP_053_Ford  = 53,
        emessageid_FORD_DSM_UBP_054_Ford  = 54,
        emessageid_FORD_CSM_UBP_055_Ford  = 55,
        emessageid_FORD_OTC_ISO_____9141_056_Ford  = 56,
        emessageid_FORD_TPM_PWM_057_Ford  = 57,
        emessageid_FORD_GEM_UBP_058_Ford  = 58,
        emessageid_FORD_4X4M_UBP_059_Ford  = 59,
        emessageid_FORD_AFCM_CAN_060_Ford  = 60,
        emessageid_FORD_HCM_ISO_____9141_061_Ford  = 61,
        emessageid_FORD_EATC_ISO_____9141_062_Ford  = 62,
        emessageid_FORD_GEM_PWM_063_Ford  = 63,
        emessageid_FORD_VAPS_PWM_064_Ford  = 64,
        emessageid_FORD_NAV_PWM_065_Ford  = 65,
        emessageid_FORD_PCSM_UBP_066_Ford  = 66,
        emessageid_FORD_DCSM_UBP_067_Ford  = 67,
        emessageid_FORD_VSM_UBP_068_Ford  = 68,
        emessageid_FORD_VEMS_PWM_069_Ford  = 69,
        emessageid_FORD_FICM_GATEWAY_CAN_070_Ford  = 70,
        emessageid_FORD_PCM_CAN_071_Ford  = 71,
        emessageid_FORD_TCM_CAN_072_Ford  = 72,
        emessageid_FORD_FOH_ISO_____9141_073_Ford  = 73,
        emessageid_FORD_PAM_UBP_074_Ford  = 74,
        emessageid_FORD_VDM_UBP_075_Ford  = 75,
        emessageid_FORD_IC_CAN_076_Ford  = 76,
        emessageid_FORD_EPB_PWM_077_Ford  = 77,
        emessageid_FORD_SCLM_PWM_078_Ford  = 78,
        emessageid_FORD_LTM_UBP_079_Ford  = 79,
        emessageid_FORD_ABS_CAN_080_Ford  = 80,
        emessageid_FORD_EATC_CAN_081_Ford  = 81,
        emessageid_FORD_TPM_CAN_082_Ford  = 82,
        emessageid_FORD_4X4M_CAN_083_Ford  = 83,
        emessageid_FORD_GEM_MCAN_084_Ford  = 84,
        emessageid_FORD_EATC_MCAN_085_Ford  = 85,
        emessageid_FORD_DCSM_MCAN_086_Ford  = 86,
        emessageid_FORD_DSM_MCAN_087_Ford  = 87,
        emessageid_FORD_VDM_MCAN_088_Ford  = 88,
        emessageid_FORD_VSM_MCAN_089_Ford  = 89,
        emessageid_FORD_FSSM_ISO_____9141_090_Ford  = 90,
        emessageid_FORD_OBD_FICM_CAN_091_Ford  = 91,
        emessageid_FORD_OBD_BCM_CAN_092_Ford  = 92,
        emessageid_FORD_BCM_CAN_093_Ford  = 93,
        emessageid_FORD_EPS_CAN_094_Ford  = 94,
        emessageid_FORD_IC_MCAN_095_Ford  = 95,
        emessageid_FORD_TBC_CAN_096_Ford  = 96,
        emessageid_FORD_RCM_CAN_097_Ford  = 97,
        emessageid_FORD_RETM_MCAN_098_Ford  = 98,
        emessageid_FORD_ACM_MCAN_099_Ford  = 99,
        emessageid_FORD_LTM_MCAN_100_Ford  = 100,
        emessageid_FORD_PAM_MCAN_101_Ford  = 101,
        emessageid_FORD_OCS_CAN_102_Ford  = 102,
        emessageid_FORD_PRB_MCAN_103_Ford  = 103,
        emessageid_FORD_SDARS_MCAN_104_Ford  = 104,
        emessageid_FORD_PLGM_ISO_____9141_105_Ford  = 105,
        emessageid_FORD_TBM_ISO_____9141_106_Ford  = 106,
        emessageid_FORD_EECV_PWM_107_Ford  = 107,
        emessageid_FORD_MCM_PWM_108_Ford  = 108,
        emessageid_FORD_NGS_PWM_109_Ford  = 109,
        emessageid_FORD_RATC_PWM_110_Ford  = 110,
        emessageid_FORD_DSP_MCAN_111_Ford  = 111,
        emessageid_FORD_DDM_MCAN_112_Ford  = 112,
        emessageid_FORD_VDM_CAN_113_Ford  = 113,
        emessageid_FORD_SASM_CAN_114_Ford  = 114,
        emessageid_FORD_RCU_MCAN_115_Ford  = 115,
        emessageid_FORD_HCM_CAN_116_Ford  = 116,
        emessageid_FORD_GEM_CAN_117_Ford  = 117,
        emessageid_FORD_HVAC_PWM_118_Ford  = 118,
        emessageid_FORD_HVAC_MCAN_119_Ford  = 119,
        emessageid_FORD_GEM_SJB_MCAN_120_Ford  = 120,
        emessageid_FORD_APIM_CAN_____UDS_121_Ford  = 121,
        emessageid_FORD_APIM_CAN_122_Ford  = 122,
        emessageid_FORD_FCIM_MCAN_123_Ford  = 123,
        emessageid_FORD_FDIM_MCAN_124_Ford  = 124,
        emessageid_FORD_PSCM_CAN_125_Ford  = 125,
        emessageid_FORD_HVAC_UBP_126_Ford  = 126,
        emessageid_FORD_AHCM_CAN_127_Ford  = 127,
        emessageid_FORD_CDIM_MCAN_128_Ford  = 128,
        emessageid_FORD_PCM_CAN_____UDS_129_Ford  = 129,
        emessageid_FORD_GEM_SJB_CAN_130_Ford  = 130,
        emessageid_FORD_SECM_CAN_131_Ford  = 131,
        emessageid_FORD_IPC_CAN_____UDS_132_Ford  = 132,
        emessageid_FORD_RCM_CAN_____UDS_133_Ford  = 133,
        emessageid_FORD_ACM_MCAN_____UDS_134_Ford  = 134,
        emessageid_FORD_ABS_CAN_____UDS_135_Ford  = 135,
        emessageid_FORD_DSP_MCAN_____UDS_136_Ford  = 136,
        emessageid_FORD_OCS_CAN_____UDS_137_Ford  = 137,
        emessageid_FORD_PAM_MCAN_____UDS_138_Ford  = 138,
        emessageid_FORD_FCIM_MCAN_____UDS_139_Ford  = 139,
        emessageid_FORD_TCCM_CAN_____UDS_140_Ford  = 140,
        emessageid_FORD_HVAC_MCAN_____UDS_141_Ford  = 141,
        emessageid_FORD_RFA_MCAN_____UDS_142_Ford  = 142,
        emessageid_FORD_HCM2_MCAN_____UDS_143_Ford  = 143,
        emessageid_FORD_C_CM_CAN_____UDS_144_Ford  = 144,
        emessageid_FORD_HCM_CAN_____UDS_145_Ford  = 145,
        emessageid_FORD_HD_LVL_ISO_____9141_146_Ford  = 146,
        emessageid_FORD_GPSM_MCAN_____UDS_147_Ford  = 147,
        emessageid_FORD_PAM_CAN_____UDS_148_Ford  = 148,
        emessageid_FORD_ACCM_CAN_____UDS_149_Ford  = 149,
        emessageid_FORD_ILCM_MCAN_150_Ford  = 150,
        emessageid_FORD_PSCM_CAN_____UDS_151_Ford  = 151,
        emessageid_FORD_HUD_CAN_____UDS_152_Ford  = 152,
        emessageid_FORD_RETM_MCAN_____UDS_153_Ford  = 153,
        emessageid_FORD_SODL_MCAN_____UDS_154_Ford  = 154,
        emessageid_FORD_SODR_MCAN_____UDS_155_Ford  = 155,
        emessageid_FORD_DCDC_CAN_____UDS_156_Ford  = 156,
        emessageid_FORD_BECM_MCAN_____UDS_157_Ford  = 157,
        emessageid_FORD_TCM_CAN_____UDS_158_Ford  = 158,
        emessageid_FORD_PCSM2_MCAN_159_Ford  = 159,
        emessageid_FORD_RHVAC_MCAN_____UDS_160_Ford  = 160,
        emessageid_FORD_BCMB_MCAN_____UDS_161_Ford  = 161,
        emessageid_FORD_SRM_MCAN_____UDS_162_Ford  = 162,
        emessageid_FORD_RCM_MCAN_163_Ford  = 163,
        emessageid_FORD_OCS_MCAN_164_Ford  = 164,
        emessageid_FORD_RLCMA_MCAN_____UDS_165_Ford  = 165,
        emessageid_FORD_DSP_CAN_____UDS_166_Ford  = 166,
        emessageid_FORD_FCDIM_CAN_____UDS_167_Ford  = 167,
        emessageid_FORD_ACM_CAN_____UDS_168_Ford  = 168,
        emessageid_FORD_FCIM_CAN_____UDS_169_Ford  = 169,
        emessageid_FORD_FLM_CAN_____UDS_170_Ford  = 170,
        emessageid_FORD_BDYCM_CAN_____UDS_171_Ford  = 171,
        emessageid_FORD_TPM_MCAN_____UDS_172_Ford  = 172,
        emessageid_FORD_SCCM_CAN_____UDS_173_Ford  = 173,
        emessageid_FORD_ATCM_CAN_____UDS_174_Ford  = 174,
        emessageid_FORD_CLM_CAN_____UDS_175_Ford  = 175,
        emessageid_FORD_HSWM_MCAN_____UDS_176_Ford  = 176,
        emessageid_FORD_GPCM_GATEWAY_CAN_____UDS_177_Ford  = 177,
        emessageid_FORD_NOX_GATEWAY_CAN_____UDS_178_Ford  = 178,
        emessageid_FORD_BDYCM_MCAN_____UDS_179_Ford  = 179,
        emessageid_FORD_FCDIM_MCAN_____UDS_180_Ford  = 180,
        emessageid_FORD_IPMB_MCAN_____UDS_181_Ford  = 181,
        emessageid_FORD_SASM_CAN_____UDS_182_Ford  = 182,
        emessageid_FORD_PDM_MCAN_____UDS_183_Ford  = 183,
        emessageid_FORD_SOBDM_CAN_____UDS_184_Ford  = 184,
        emessageid_FORD_GFM_CAN_____UDS_185_Ford  = 185,
        emessageid_FORD_TCU_MCAN_____UDS_186_Ford  = 186,
        emessageid_FORD_GWM_CAN_____UDS_187_Ford  = 187,
        emessageid_FORD_BCCM_CAN_____UDS_188_Ford  = 188,
        emessageid_FORD_IPC_MCAN_____UDS_189_Ford  = 189,
        emessageid_FORD_DDM_MCAN_____UDS_190_Ford  = 190,
        emessageid_FORD_IPMA_CAN_____UDS_191_Ford  = 191,
        emessageid_FORD_RTM_MCAN_____UDS_192_Ford  = 192,
        emessageid_FORD_RACM_CAN_____UDS_193_Ford  = 193,
        emessageid_FORD_VDM_CAN_____UDS_194_Ford  = 194,
        emessageid_FORD_DACMC_CAN_____UDS_195_Ford  = 195,
        emessageid_FORD_PCM_CAN_196_Ford  = 196,
        emessageid_FORD_PCM_CAN_____UDS_197_Ford  = 197,
        emessageid_FORD_BECM_CAN_____UDS_198_Ford  = 198,
        emessageid_FORD_DACMC_MCAN_____UDS_199_Ford  = 199,
        emessageid_FORD_DSM_MCAN_____UDS_200_Ford  = 200,
        emessageid_FORD_GSM_CAN_____UDS_201_Ford  = 201,
        emessageid_FORD_ICM_CAN_____UDS_202_Ford  = 202,
        emessageid_FORD_RGTM_MCAN_____UDS_203_Ford  = 203,
        emessageid_FORD_SCME_MCAN_204_Ford  = 204,
        emessageid_FORD_SCMG_MCAN_____UDS_205_Ford  = 205,
        emessageid_FORD_SCMH_MCAN_____UDS_206_Ford  = 206,
        emessageid_FORD_SOBDMC_CAN_____UDS_207_Ford  = 207,
        emessageid_FORD_TCU_CAN_____UDS_208_Ford  = 208,
        emessageid_FORD_TRCM_CAN_____UDS_209_Ford  = 209,
        emessageid_FORD_TRM_MCAN_____UDS_210_Ford  = 210,
        emessageid_FORD_APIM_CAN_____UDS3_11_211_Ford  = 211,
        emessageid_FORD_IPC_CAN_____UDS3_11_212_Ford  = 212,
        emessageid_FORD_RCM_CAN_____UDS3_11_213_Ford  = 213,
        emessageid_FORD_ABS_CAN_____UDS3_11_214_Ford  = 214,
        emessageid_FORD_OCS_CAN_____UDS3_11_215_Ford  = 215,
        emessageid_FORD_FCIM_CAN_____UDS3_11_216_Ford  = 216,
        emessageid_FORD_C_CM_CAN_____UDS3_11_217_Ford  = 217,
        emessageid_FORD_GPSM_CAN_____UDS3_11_218_Ford  = 218,
        emessageid_FORD_PAM_CAN_____UDS3_11_219_Ford  = 219,
        emessageid_FORD_ACCM_CAN_____UDS3_11_220_Ford  = 220,
        emessageid_FORD_PSCM_CAN_____UDS3_11_221_Ford  = 221,
        emessageid_FORD_HUD_CAN_____UDS3_11_222_Ford  = 222,
        emessageid_FORD_SODL_CAN_____UDS3_11_223_Ford  = 223,
        emessageid_FORD_SODR_CAN_____UDS3_11_224_Ford  = 224,
        emessageid_FORD_DCDC_CAN_____UDS3_11_225_Ford  = 225,
        emessageid_FORD_DSP_CAN_____UDS3_11_226_Ford  = 226,
        emessageid_FORD_FCDIM_CAN_____UDS3_11_227_Ford  = 227,
        emessageid_FORD_ACM_CAN_____UDS3_11_228_Ford  = 228,
        emessageid_FORD_BDYCM_CAN_____UDS3_11_229_Ford  = 229,
        emessageid_FORD_SCCM_CAN_____UDS3_11_230_Ford  = 230,
        emessageid_FORD_PDM_CAN_____UDS3_11_231_Ford  = 231,
        emessageid_FORD_SOBDM_CAN_____UDS3_11_232_Ford  = 232,
        emessageid_FORD_GFM_CAN_____UDS3_11_233_Ford  = 233,
        emessageid_FORD_GWM_CAN_____UDS3_11_234_Ford  = 234,
        emessageid_FORD_DDM_CAN_____UDS3_11_235_Ford  = 235,
        emessageid_FORD_IPMA_CAN_____UDS3_11_236_Ford  = 236,
        emessageid_FORD_RTM_CAN_____UDS3_11_237_Ford  = 237,
        emessageid_FORD_RACM_CAN_____UDS3_11_238_Ford  = 238,
        emessageid_FORD_DACMC_CAN_____UDS3_11_239_Ford  = 239,
        emessageid_FORD_BECM_CAN_____UDS3_11_241_Ford  = 240,
        emessageid_FORD_SOBDMC_CAN_____UDS3_11_242_Ford  = 241,
        emessageid_FORD_TCU_CAN_____UDS3_11_243_Ford  = 242,
        emessageid_FORD_RGTM_CAN_____UDS3_11_244_Ford  = 243,
        emessageid_FORD_SCMG_CAN_____UDS3_11_245_Ford  = 244,
        emessageid_FORD_SCMH_CAN_____UDS3_11_246_Ford  = 245,
        emessageid_FORD_VDM_CAN_____UDS3_11_247_Ford  = 246,
        emessageid_FORD_GSM_CAN_____UDS3_11_248_Ford  = 247,
        emessageid_FORD_HCM_CAN_____UDS3_11_249_Ford  = 248,
        emessageid_FORD_HSWM_CAN_____UDS3_11_250_Ford  = 249,
        emessageid_FORD_TRCM_CAN_____UDS3_11_251_Ford  = 250,
        emessageid_FORD_OBD1_KOEO_Ford  = 251,
        emessageid_FORD_OBD1_KOER_Ford  = 252,
        emessageid_FORD_OBD1_CYLBALANCETEST_Ford  = 253,
        emessageid_FORD_OBD1_OUTPUTCHECK_Ford  = 254,
        emessageid_FORD_OBD1_TIMINGCHECK_Ford  = 255,
        emessageid_FORD_OBD1_WIGGLETEST_Ford  = 256,
        emessageid_FORD_ABS_DDL1_252_Ford  = 257,
        emessageid_FORD_PCM_DDL1_253_Ford  = 258,
        emessageid_FORD_PCM_DDL1_254_Ford  = 259,
        emessageid_FORD_SRS_DDL1_255_Ford  = 260,
        emessageid_FORD_TCM_DDL1_256_Ford  = 261,
        emessageid_FORD_PCM_DDL2_257_Ford  = 262,
    
    }enumMessageid_Ford;
    
    
    typedef enum _enumSystem_Ford{
        esystem_UNKNOWN_Ford   = 0,
        esystem_PCM_Ford  = 1,
        esystem_ABS_Ford  = 2,
        esystem_CSM_Ford  = 3,
        esystem_IABM_Ford  = 4,
        esystem_DDM_Ford  = 5,
        esystem_DSM_Ford  = 6,
        esystem_EATC_Ford  = 7,
        esystem_FIM_Ford  = 8,
        esystem_LCM_Ford  = 9,
        esystem_ARC_Ford  = 10,
        esystem_GEM_Ford  = 11,
        esystem_RAP_Ford  = 12,
        esystem_PATS_Ford  = 13,
        esystem_RCC_Ford  = 14,
        esystem_SARC_Ford  = 15,
        esystem_ACM_Ford  = 16,
        esystem_CPM_Ford  = 17,
        esystem_RESCU_Ford  = 18,
        esystem_VDM_Ford  = 19,
        esystem_VIC_Ford  = 20,
        esystem_ECS_Ford  = 21,
        esystem_4WAS_Ford  = 22,
        esystem_OTC_Ford  = 23,
        esystem_HEC_Ford  = 24,
        esystem_MC_Ford  = 25,
        esystem_PSM_Ford  = 26,
        esystem_SCIL_Ford  = 27,
        esystem_PAM_Ford  = 28,
        esystem_NGSC_Ford  = 29,
        esystem_RASM_Ford  = 30,
        esystem_RCM_Ford  = 31,
        esystem_IC_Ford  = 32,
        esystem_FEM_Ford  = 33,
        esystem_LPSDM_Ford  = 34,
        esystem_REM_Ford  = 35,
        esystem_RPSDM_Ford  = 36,
        esystem_AFCM_Ford  = 37,
        esystem_CTM_Ford  = 38,
        esystem_4X4M_Ford  = 39,
        esystem_FFH_Ford  = 40,
        esystem_ICU_Ford  = 41,
        esystem_INST_Ford  = 42,
        esystem_TPM_Ford  = 43,
        esystem_HCM_Ford  = 44,
        esystem_NAV_Ford  = 45,
        esystem_PCSM_Ford  = 46,
        esystem_VAPS_Ford  = 47,
        esystem_VEMS_Ford  = 48,
        esystem_VSM_Ford  = 49,
        esystem_LTM_Ford  = 50,
        esystem_TCM_Ford  = 51,
        esystem_FOH_Ford  = 52,
        esystem_DCSM_Ford  = 53,
        esystem_EPB_Ford  = 54,
        esystem_SCLM_Ford  = 55,
        esystem_FSSM_Ford  = 56,
        esystem_OBD_FICM_Ford  = 57,
        esystem_BCM_Ford  = 58,
        esystem_EPS_Ford  = 59,
        esystem_OBD_BCM_Ford  = 60,
        esystem_TBC_Ford  = 61,
        esystem_RETM_Ford  = 62,
        esystem_OCS_Ford  = 63,
        esystem_PRB_Ford  = 64,
        esystem_SDARS_Ford  = 65,
        esystem_PLGM_Ford  = 66,
        esystem_TBM_Ford  = 67,
        esystem_MCM_Ford  = 68,
        esystem_NGS_SCLM_Ford  = 69,
        esystem_RATC_Ford  = 70,
        esystem_DSP_Ford  = 71,
        esystem_EECV_Ford  = 72,
        esystem_SASM_Ford  = 73,
        esystem_RCU_Ford  = 74,
        esystem_HVAC_Ford  = 75,
        esystem_APIM_Ford  = 76,
        esystem_GEM_SJB_Ford  = 77,
        esystem_FCIM_Ford  = 78,
        esystem_FDIM_Ford  = 79,
        esystem_PSCM_Ford  = 80,
        esystem_AHCM_Ford  = 81,
        esystem_CDIM_Ford  = 82,
        esystem_SECM_Ford  = 83,
        esystem_IPC_Ford  = 84,
        esystem_TCCM_Ford  = 85,
        esystem_C_CM_Ford  = 86,
        esystem_HCM2_Ford  = 87,
        esystem_HD_LVL_Ford  = 88,
        esystem_RFA_Ford  = 89,
        esystem_GPSM_Ford  = 90,
        esystem_ACCM_Ford  = 91,
        esystem_ILCM_Ford  = 92,
        esystem_HUD_Ford  = 93,
        esystem_BECM_Ford  = 94,
        esystem_DCDC_Ford  = 95,
        esystem_SODL_Ford  = 96,
        esystem_SODR_Ford  = 97,
        esystem_BCMB_Ford  = 98,
        esystem_SRM_Ford  = 99,
        esystem_PCSM2_Ford  = 100,
        esystem_RHVAC_Ford  = 101,
        esystem_BDYCM_Ford  = 102,
        esystem_FCDIM_Ford  = 103,
        esystem_FLM_Ford  = 104,
        esystem_RLCMA_Ford  = 105,
        esystem_SCCM_Ford  = 106,
        esystem_ATCM_Ford  = 107,
        esystem_CLM_Ford  = 108,
        esystem_HSWM_Ford  = 109,
        esystem_BCCM_Ford  = 110,
        esystem_GFM_Ford  = 111,
        esystem_GWM_Ford  = 112,
        esystem_IPMB_Ford  = 113,
        esystem_PDM_Ford  = 114,
        esystem_SOBDM_Ford  = 115,
        esystem_TCU_Ford  = 116,
        esystem_DACMC_Ford  = 117,
        esystem_RGTM_Ford  = 118,
        esystem_SOBDMC_Ford  = 119,
        esystem_TRM_Ford  = 120,
        esystem_IPMA_Ford  = 121,
        esystem_RTM_Ford  = 122,
        esystem_RACM_Ford  = 123,
        esystem_ICM_Ford  = 124,
        esystem_SCME_Ford  = 125,
        esystem_GSM_Ford  = 126,
        esystem_SCMG_Ford  = 127,
        esystem_SCMH_Ford  = 128,
        esystem_TRCM_Ford  = 129,
        esystem_ECM_Ford  = 130,
        esystem_SRS_Ford  = 131,
    
    }enumSystem_Ford;
    
    
    typedef enum _enumSubsystem_Ford{
        esubsystem_UNKNOWN_Ford   = 0,
        esubsystem_3E_____01_Ford  = 1,
        esubsystem_02_____3E_____01_____00_____00_____00_____00_____00_Ford  = 2,
        esubsystem_TRANSMISSION_Ford  = 3,
    
    }enumSubsystem_Ford;
    
    
    typedef enum _enumProgramid_Ford{
        eprogramid_UNKNOWN_Ford   = 0,
        eprogramid_TRANSMISSION_0053_Ford  = 1,
        eprogramid_TRANSMISSION_0054_Ford  = 2,
        eprogramid_TRANSMISSION_0055_Ford  = 3,
        eprogramid_TRANSMISSION_0056_Ford  = 4,
        eprogramid_TRANSMISSION_0057_Ford  = 5,
        eprogramid_TRANSMISSION_0058_Ford  = 6,
        eprogramid_TRANSMISSION_0059_Ford  = 7,
        eprogramid_TRANSMISSION_0060_Ford  = 8,
        eprogramid_TRANSMISSION_0061_Ford  = 9,
        eprogramid_TRANSMISSION_0062_Ford  = 10,
        eprogramid_TRANSMISSION_0063_Ford  = 11,
        eprogramid_TRANSMISSION_0064_Ford  = 12,
        eprogramid_TRANSMISSION_0065_Ford  = 13,
        eprogramid_TRANSMISSION_0066_Ford  = 14,
        eprogramid_TRANSMISSION_0067_Ford  = 15,
        eprogramid_TRANSMISSION_0068_Ford  = 16,
        eprogramid_TRANSMISSION_0069_Ford  = 17,
        eprogramid_TRANSMISSION_0070_Ford  = 18,
        eprogramid_TRANSMISSION_0071_Ford  = 19,
        eprogramid_TRANSMISSION_0072_Ford  = 20,
        eprogramid_TRANSMISSION_0073_Ford  = 21,
        eprogramid_TRANSMISSION_0074_Ford  = 22,
        eprogramid_TRANSMISSION_0075_Ford  = 23,
        eprogramid_TRANSMISSION_0076_Ford  = 24,
        eprogramid_TRANSMISSION_0111_Ford  = 25,
        eprogramid_TRANSMISSION_0112_Ford  = 26,
        eprogramid_TRANSMISSION_0113_Ford  = 27,
        eprogramid_TRANSMISSION_ALL_Ford  = 28,
        eprogramid_TRANSMISSION_0114_Ford  = 29,
    
    }enumProgramid_Ford;
    
    
    typedef enum _enumTiming_Ford{
        etiming_UNKNOWN_Ford   = 0,
        etiming_TWUP_FORD_PWM_Ford  = 1,
        etiming_TIMINGP_FORD_PWM_Ford  = 2,
        etiming_TIMINGW_FORD_PWM_Ford  = 3,
        etiming_TWUP_FORD_ISO9141_Ford  = 4,
        etiming_TIMINGP_FORD_ISO9141_Ford  = 5,
        etiming_TIMINGW_FORD_ISO9141_Ford  = 6,
        etiming_TWUP_FORD_UBP_Ford  = 7,
        etiming_TIMINGP_FORD_UBP_Ford  = 8,
        etiming_TIMINGW_FORD_UBP_Ford  = 9,
        etiming_TIMINGP_FORD_CAN_Ford  = 10,
        etiming_TIMINGP_FORD_MCAN_Ford  = 11,
        etiming_TIMINGP_FORD_CAN_UDS_Ford  = 12,
        etiming_TIMINGP_FORD_MCAN_____UDS_Ford  = 13,
        etiming_KW1281DEFAULT_Ford  = 14,
        etiming_TIMINGP_CHRYSLER_CAN_Ford  = 15,
        etiming_TIMINGP_CHRYSLER_CAN_C_UDS_Ford  = 16,
        etiming_TIMINGP_CHRYSLER_CAN_I_UDS_Ford  = 17,
        etiming_TIMINGP_CHRYSLER_CCD_Ford  = 18,
        etiming_TIMINGP_CHRYSLER_CCD2_Ford  = 19,
        etiming_TIMINGP_CHRYSLER_KW2000_Ford  = 20,
        etiming_TIMINGP_CHRYSLER_KWFB_Ford  = 21,
        etiming_TIMINGP_CHRYSLER_MB_ISO_Ford  = 22,
        etiming_TIMINGP_CHRYSLER_MUT_Ford  = 23,
        etiming_TIMINGP_CHRYSLER_SCI_Ford  = 24,
        etiming_TIMINGP_CHRYSLER_VPW_Ford  = 25,
        etiming_TIMINGP_GM_ALDL_Ford  = 26,
        etiming_TIMINGP_GM_CAN_Ford  = 27,
        etiming_TIMINGP_GM_GMLAN_Ford  = 28,
        etiming_TIMINGP_GM_KW_Ford  = 29,
        etiming_TIMINGP_GM_SDL_Ford  = 30,
        etiming_TIMINGP_GM_SWCAN_Ford  = 31,
        etiming_TIMINGP_GM_VPW_Ford  = 32,
        etiming_TIMINGP_HONDA_92HM_Ford  = 33,
        etiming_TIMINGP_HONDA_95HM_Ford  = 34,
        etiming_TIMINGP_HONDA_BOSCH_Ford  = 35,
        etiming_TIMINGP_HONDA_CAN_Ford  = 36,
        etiming_TIMINGP_HONDA_H99B_Ford  = 37,
        etiming_TIMINGP_HONDA_KW2000_Ford  = 38,
        etiming_TIMINGP_TOYOTA_CAN_Ford  = 39,
        etiming_TIMINGP_TOYOTA_ISO9141_Ford  = 40,
        etiming_TIMINGP_TOYOTA_KW2000_Ford  = 41,
        etiming_TIMINGP_TOYOTA_VPW_Ford  = 42,
        etiming_TIMINGW_CHRYSLER_MB_ISO_Ford  = 43,
        etiming_TIMINGW_CHRYSLER_MUT_Ford  = 44,
        etiming_TIMINGW_GM_KW_Ford  = 45,
        etiming_TIMINGW_HONDA_BOSCH_Ford  = 46,
        etiming_TIMINGW_TOYOTA_ISO9141_Ford  = 47,
        etiming_TWUP_CHRYSLER_KW2000_Ford  = 48,
        etiming_TWUP_CHRYSLER_KWFB_Ford  = 49,
        etiming_TWUP_GM_KW_Ford  = 50,
        etiming_TWUP_HONDA_92HM_Ford  = 51,
        etiming_TWUP_HONDA_95HM_Ford  = 52,
        etiming_TWUP_HONDA_H99B_Ford  = 53,
        etiming_TWUP_HONDA_KW2000_Ford  = 54,
        etiming_TWUP_TOYOTA_KW2000_10400_Ford  = 55,
        etiming_TWUP_TOYOTA_KW2000_9600_Ford  = 56,
        etiming_TWUPHONDA_00_Ford  = 57,
        etiming_TIMINGP_NORMAL_Ford  = 58,
        etiming_TIMINGP_CANNORMAL_Ford  = 59,
        etiming_TIMINGW_NORMAL_Ford  = 60,
        etiming_TWUPGENERAL_Ford  = 61,
        etiming_TWUP_GM_KW9600_Ford  = 62,
        etiming_TIMINGP_VOLVO_D2_Ford  = 63,
        etiming_TIMINGP_VOLVO_GGD_Ford  = 64,
        etiming_TIMINGP_VOLVO_KW_Ford  = 65,
        etiming_TIMINGW_VOLVO_D2_Ford  = 66,
        etiming_TWUP_VOLVO_KW_Ford  = 67,
        etiming_TWUP_VOLVO_GGD_Ford  = 68,
        etiming_TWUP_VOLVO_D2_Ford  = 69,
        etiming_TIMINGW_VOLVO_GGD_Ford  = 70,
        etiming_TIMINGW_VOLVO_KW_Ford  = 71,
        etiming_TIMINGP_BMW_KW2000_Ford  = 72,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_Ford  = 73,
        etiming_TIMINGP_MERCEDES_BENZ_CAN_UDS_Ford  = 74,
        etiming_TIMINGP_NISSAN_DDL1_Ford  = 75,
        etiming_TWUP_NISSAN_DDL1_Ford  = 76,
        etiming_TIMINGW_NISSAN_DDL1_Ford  = 77,
        etiming_TWUP_NISSAN_DDL2_Ford  = 78,
        etiming_TIMINGP_NISSAN_DDL2_Ford  = 79,
        etiming_TIMINGW_NISSAN_DDL2_Ford  = 80,
    
    }enumTiming_Ford;
    
    
    typedef enum _enumErasetype_Ford{
        eerasetype_UNKNOWN_Ford   = 0,
    
    }enumErasetype_Ford;
    
    
    typedef enum _enumModel_Ford{
        emodel_UNKNOWN_Ford   = 0,
        emodel_AEROSTAR_Ford  = 1,
        emodel_ASPIRE_Ford  = 2,
        emodel_BRONCO_Ford  = 3,
        emodel_CLUB_____WAGON_Ford  = 4,
        emodel_CONTOUR_Ford  = 5,
        emodel_CROWN_____VICTORIA_Ford  = 6,
        emodel_ECONOLINE_Ford  = 7,
        emodel_ECONOLINE_____WAGON_Ford  = 8,
        emodel_ESCORT_Ford  = 9,
        emodel_EXPLORER_Ford  = 10,
        emodel_F150_Ford  = 11,
        emodel_F250_Ford  = 12,
        emodel_F350_Ford  = 13,
        emodel_F450_Ford  = 14,
        emodel_MUSTANG_Ford  = 15,
        emodel_PROBE_Ford  = 16,
        emodel_RANGER_Ford  = 17,
        emodel_TAURUS_Ford  = 18,
        emodel_THUNDERBIRD_Ford  = 19,
        emodel_WINDSTAR_Ford  = 20,
        emodel_CONTINENTAL_Ford  = 21,
        emodel_MARK_____VIII_Ford  = 22,
        emodel_TOWN_____CAR_Ford  = 23,
        emodel_COUGAR_Ford  = 24,
        emodel_GRAND_____MARQUIS_Ford  = 25,
        emodel_MYSTIQUE_Ford  = 26,
        emodel_SABLE_Ford  = 27,
        emodel_TRACER_Ford  = 28,
        emodel_EXPEDITION_Ford  = 29,
        emodel_MOUNTAINEER_Ford  = 30,
        emodel_NAVIGATOR_Ford  = 31,
        emodel_EXCURSION_Ford  = 32,
        emodel_FOCUS_Ford  = 33,
        emodel_LS_Ford  = 34,
        emodel_ESCAPE_Ford  = 35,
        emodel_EXPLORER_____SPORT_Ford  = 36,
        emodel_EXPLORER_____SPORT_____TRAC_Ford  = 37,
        emodel_ESCORT_____ZX2_Ford  = 38,
        emodel_AVIATOR_Ford  = 39,
        emodel_BLACKWOOD_Ford  = 40,
        emodel_MARAUDER_Ford  = 41,
        emodel_F150_____HERITAGE_Ford  = 42,
        emodel_FREESTAR_Ford  = 43,
        emodel_GT_Ford  = 44,
        emodel_MONTEREY_Ford  = 45,
        emodel_ESCAPE_____HYBRID_Ford  = 46,
        emodel_FIVE_____HUNDRED_Ford  = 47,
        emodel_FREESTYLE_Ford  = 48,
        emodel_MARINER_Ford  = 49,
        emodel_MONTEGO_Ford  = 50,
        emodel_FUSION_Ford  = 51,
        emodel_MARK_____LT_Ford  = 52,
        emodel_ZEPHYR_Ford  = 53,
        emodel_MARINER_____HYBRID_Ford  = 54,
        emodel_MILAN_Ford  = 55,
        emodel_EDGE_Ford  = 56,
        emodel_EXPEDITION_____EL_Ford  = 57,
        emodel_MUSTANG_____SHELBY_____GT500_Ford  = 58,
        emodel_MKX_Ford  = 59,
        emodel_MKZ_Ford  = 60,
        emodel_NAVIGATOR_____L_Ford  = 61,
        emodel_TAURUS_____X_Ford  = 62,
        emodel_FLEX_Ford  = 63,
        emodel_MKS_Ford  = 64,
        emodel_FUSION_____HYBRID_Ford  = 65,
        emodel_TRANLap Dang_____CONNECT_Ford  = 66,
        emodel_MKT_Ford  = 67,
        emodel_MILAN_____HYBRID_Ford  = 68,
        emodel_FIESTA_Ford  = 69,
        emodel_MKZ_____HYBRID_Ford  = 70,
        emodel_C_MAX_Ford  = 71,
        emodel_C_MAX_____HYBRID_Ford  = 72,
        emodel_TH_NK_Ford  = 73,
        emodel_VILLAGER_Ford  = 74,
        emodel_E350_____WAGON_Ford  = 75,
    
    }enumModel_Ford;
    
    
    typedef enum _enumEngine_Ford{
        eengine_UNKNOWN_Ford   = 0,
        eengine_V6______3_0L_Ford  = 1,
        eengine_V6______3_8L_Ford  = 2,
        eengine_V6______4_0L_Ford  = 3,
        eengine_L4______1_3L_Ford  = 4,
        eengine_V8______5_0L_Ford  = 5,
        eengine_V8______5_8L_Ford  = 6,
        eengine_V8______7_3L_Ford  = 7,
        eengine_L6______4_9L_Ford  = 8,
        eengine_V8______7_5L_Ford  = 9,
        eengine_L4______2_0L_Ford  = 10,
        eengine_V6______2_5L_Ford  = 11,
        eengine_V8______4_6L_Ford  = 12,
        eengine_L4______1_8L_Ford  = 13,
        eengine_L4______1_9L_Ford  = 14,
        eengine_V6______3_2L_Ford  = 15,
        eengine_L4______2_3L_Ford  = 16,
        eengine_V8______3_4L_Ford  = 17,
        eengine_L4______1_6L_Ford  = 18,
        eengine_V10______6_8L_Ford  = 19,
        eengine_V6______4_2L_Ford  = 20,
        eengine_V8______5_4L_Ford  = 21,
        eengine_L4______2_5L_Ford  = 22,
        eengine_V6______3_3L_Ford  = 23,
        eengine_L6______5_9L_Ford  = 24,
        eengine_ELECTRIC_Ford  = 25,
        eengine_V6______3_5L_Ford  = 26,
        eengine_L6______2_4L_Ford  = 27,
        eengine_V8______3_9L_Ford  = 28,
        eengine_L6______7_2L_Ford  = 29,
        eengine_V8______6_0L_Ford  = 30,
        eengine_V8______6_9L_Ford  = 31,
        eengine_V6______3_9L_Ford  = 32,
        eengine_V8______6_4L_Ford  = 33,
        eengine_V8______6_7L_Ford  = 34,
        eengine_V6______3_7L_Ford  = 35,
        eengine_V8______6_2L_Ford  = 36,
        eengine_L3______1_0L_Ford  = 37,
        eengine_L4______1_5L_Ford  = 38,
    
    }enumEngine_Ford;
    

#endif