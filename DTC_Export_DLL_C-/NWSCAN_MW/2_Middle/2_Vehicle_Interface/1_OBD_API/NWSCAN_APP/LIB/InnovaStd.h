/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : InnovaStd.h
Synchronize with file enum
File Excel :Global_Enums_v02.00.00
Author : Lap Dang 
Building : 9/18/2015 3:02:34 PM
History         :

|-Version     |   Date       |  Engineer   |        Note                     -|
  +
  +
  +
  +
  +
===============================================================================
******************************************************************************/


#ifndef INNOVA_STD_H
#define INNOVA_STD_H


#ifndef eSubSystem_MAX
#define eSubSystem_MAX  65535
#endif
#ifndef eSystem_MAX
#define eSystem_MAX  65535
#endif

#ifndef eEngine_MAX
#define eEngine_MAX     65535
#endif

typedef uint16 enumvariants;
typedef uint16 enumCommands;
typedef uint16 enumCommandList;
typedef uint16 enumEcuIds;
typedef uint16 enumECUPartNumbers;
typedef uint16 enumECUTypes;
typedef uint16 enumLookupTables;
typedef uint16 enumMessageIds;
typedef uint16 enumReadDtcCommandList;
typedef uint16 enumTimings;
#define eTimingMax			65535
#define elookuptable_MAX      65535
#define ecommand_MAX		65535
#define ePPCMD_MAX		    65535
#define eReadDtcCmdList_MAX 65535
#define ePCMD_MAX       	ecommand_MAX
#define DTC_MAX 			255
#define Is_Can_Protocol(a) ((a==CAN500KBAUD_MODE)||(a==XCAN500KBAUD_MODE)\
     ||(a==CAN250KBAUD_MODE)||(a==XCAN250KBAUD_MODE)||(a==CAN_MODE)?eTRUE:eFALSE)

#define NEG_SERVICE             0x7F

#define PROTOCOL_NO              	eprotocol_PROTOCOL_NO              
#define PROTOCOL_VPW             	eprotocol_PROTOCOL_VPW             
#define PROTOCOL_PWM             	eprotocol_PROTOCOL_PWM             
#define PROTOCOL_ISO9141         	eprotocol_PROTOCOL_ISO9141         
#define PROTOCOL_KW2000          	eprotocol_PROTOCOL_KW2000          
#define PROTOCOL_CAN500KBAUD     	eprotocol_PROTOCOL_CAN500KBAUD     
#define PROTOCOL_XCAN500KBAUD    	eprotocol_PROTOCOL_XCAN500KBAUD    
#define PROTOCOL_CAN250KBAUD     	eprotocol_PROTOCOL_CAN250KBAUD     
#define PROTOCOL_XCAN250KBAUD    	eprotocol_PROTOCOL_XCAN250KBAUD    
#define PROTOCOL_BOSCH           	eprotocol_PROTOCOL_BOSCH           
#define PROTOCOL_RESERVE_10      	eprotocol_PROTOCOL_RESERVE_10      
#define PROTOCOL_RESERVE_11      	eprotocol_PROTOCOL_RESERVE_11      
#define PROTOCOL_RESERVE_12      	eprotocol_PROTOCOL_RESERVE_12      
#define PROTOCOL_RESERVE_13      	eprotocol_PROTOCOL_RESERVE_13      
#define PROTOCOL_RESERVE_14      	eprotocol_PROTOCOL_RESERVE_14      
#define PROTOCOL_KW              	eprotocol_PROTOCOL_KW              
#define PROTOCOL_KW1281          	eprotocol_PROTOCOL_KW1281          
#define PROTOCOL_MUT             	eprotocol_PROTOCOL_MUT             
#define PROTOCOL_CAN_C_UDS       	eprotocol_PROTOCOL_CAN_C_UDS       
#define PROTOCOL_CAN_I_UDS       	eprotocol_PROTOCOL_CAN_I_UDS       
#define PROTOCOL_RESERVE_20      	eprotocol_PROTOCOL_RESERVE_20      
#define PROTOCOL_CCD2            	eprotocol_PROTOCOL_CCD2            
#define PROTOCOL_SDL             	eprotocol_PROTOCOL_SDL             
#define PROTOCOL_UBP             	eprotocol_PROTOCOL_UBP             
#define PROTOCOL_MCAN            	eprotocol_PROTOCOL_MCAN            
#define PROTOCOL_MCAN_UDS    	eprotocol_PROTOCOL_MCAN_____UDS    
#define PROTOCOL_H99B            	eprotocol_PROTOCOL_H99B            
#define PROTOCOL_95HM            	eprotocol_PROTOCOL_95HM            
#define PROTOCOL_92HM            	eprotocol_PROTOCOL_92HM            
#define PROTOCOL_CAN             	eprotocol_PROTOCOL_CAN             
#define PROTOCOL_RESERVE_30      	eprotocol_PROTOCOL_RESERVE_30      
#define PROTOCOL_RESERVE_31      	eprotocol_PROTOCOL_RESERVE_31      
#define PROTOCOL_CCD             	eprotocol_PROTOCOL_CCD             
#define PROTOCOL_SCI             	eprotocol_PROTOCOL_SCI             
#define PROTOCOL_RESERVE_34      	eprotocol_PROTOCOL_RESERVE_34      
#define PROTOCOL_RESERVE_35      	eprotocol_PROTOCOL_RESERVE_35      
#define PROTOCOL_RESERVE_36      	eprotocol_PROTOCOL_RESERVE_36      
#define PROTOCOL_RESERVE_37      	eprotocol_PROTOCOL_RESERVE_37      
#define PROTOCOL_RESERVE_38      	eprotocol_PROTOCOL_RESERVE_38      
#define PROTOCOL_RESERVE_39      	eprotocol_PROTOCOL_RESERVE_39      
#define PROTOCOL_RESERVE_40      	eprotocol_PROTOCOL_RESERVE_40      
#define PROTOCOL_RESERVE_41      	eprotocol_PROTOCOL_RESERVE_41      
#define PROTOCOL_OBD1            	eprotocol_PROTOCOL_OBD1            
#define PROTOCOL_RESERVE_43      	eprotocol_PROTOCOL_RESERVE_43      
#define PROTOCOL_RESERVE_44      	eprotocol_PROTOCOL_RESERVE_44      
#define PROTOCOL_RESERVE_45      	eprotocol_PROTOCOL_RESERVE_45      
#define PROTOCOL_RESERVE_46      	eprotocol_PROTOCOL_RESERVE_46      
#define PROTOCOL_RESERVE_47      	eprotocol_PROTOCOL_RESERVE_47      
#define PROTOCOL_DDL1            	eprotocol_PROTOCOL_DDL1            
#define PROTOCOL_SWCAN           	eprotocol_PROTOCOL_SWCAN           
#define PROTOCOL_RESERVE_50      	eprotocol_PROTOCOL_RESERVE_50      
#define PROTOCOL_MB_ISO          	eprotocol_PROTOCOL_MB_ISO          
#define PROTOCOL_KWFB            	eprotocol_PROTOCOL_KWFB            
#define PROTOCOL_BMW_CAN         	eprotocol_PROTOCOL_BMW_CAN         
#define PROTOCOL_TPCAN_2_0       	eprotocol_PROTOCOL_TPCAN_2_0       
#define PROTOCOL_TPCAN_1_6_KW1281	eprotocol_PROTOCOL_TPCAN_1_6_KW1281
#define PROTOCOL_TPCAN_1_6_KW2000	eprotocol_PROTOCOL_TPCAN_1_6_KW2000
#define PROTOCOL_KWSSM           	eprotocol_PROTOCOL_KWSSM           
#define PROTOCOL_DDL2            	eprotocol_PROTOCOL_DDL2            
#define PROTOCOL_DS2             	eprotocol_PROTOCOL_DS2             
#define PROTOCOL_CAN_UDS         	eprotocol_PROTOCOL_CAN_UDS         
#define PROTOCOL_CANUDS          	eprotocol_PROTOCOL_CANUDS          
#define PROTOCOL_CAN_D2          	eprotocol_PROTOCOL_CAN_D2          
#define PROTOCOL_CAN_GGD         	eprotocol_PROTOCOL_CAN_GGD         
#define PROTOCOL_ALDL            	eprotocol_PROTOCOL_ALDL            
#define PROTOCOL_GMLAN           	eprotocol_PROTOCOL_GMLAN           
#define PROTOCOL_MAX             	eprotocol_PROTOCOL_MAX             
#define PROTOCOL_CAN_C           	eprotocol_PROTOCOL_CAN_C           
#define PROTOCOL_TCAN            	eprotocol_PROTOCOL_TCAN            
#define PROTOCOL_DS1             	eprotocol_PROTOCOL_DS1             
#define PROTOCOL_DS2_MID         	eprotocol_PROTOCOL_DS2_MID         
#define PROTOCOL_D2              	eprotocol_PROTOCOL_D2              
#define PROTOCOL_GGD             	eprotocol_PROTOCOL_GGD             
#define Suzuki_SDL               	eprotocol_Suzuki_SDL               
#define PROTOCOL_SUBARU_KWP_4800 	eprotocol_PROTOCOL_SUBARU_KWP_4800 
#define PROTOCOL_SUBARU_FHICAN   	eprotocol_PROTOCOL_SUBARU_FHICAN   
#define PROTOCOL_SUBARU_TMC      	eprotocol_PROTOCOL_SUBARU_TMC      
#define PROTOCOL_SUBARU_KWP_10400	eprotocol_PROTOCOL_SUBARU_KWP_10400
#define PROTOCOL_SUBARU_KWP_1953 	eprotocol_PROTOCOL_SUBARU_KWP_1953 

#include "1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\enums.h"

typedef enumBuffername	enumBufferName;
typedef enumInittype	enumInitType;
typedef enumDlc	enumDLCPinName;
typedef enumDlcvoltage	enumVoltageLevel;
typedef enumReLap Dangor	enumPUReLap Dangor;
typedef enumPd_ReLap Dangor	enumPDReLap Dangor;
typedef enumUartdata	enumUartDataType;
typedef enumChecksum	enumCheckSumType;
typedef enumDtcdisplaytype	enumDTCType;
typedef enumVref	enumVreftype;
typedef enumConnector	enumConnectors;
typedef enumInnovagroup	enumInnovaGroups;
typedef enumDtcstatuse	enumTypeDtcStatus;
typedef enumDtcdisplaytype DTC_DISP_TYPE;


#define GROUP_ABS	einnovagroup_GROUP_ABS
#define GROUP_SRS	einnovagroup_GROUP_SRS
#define GROUP_OBDII	einnovagroup_GROUP_OBDII
#define GROUP_ENH_TCM	einnovagroup_GROUP_ENH_TCM
#define GROUP_ENH_ECM	einnovagroup_GROUP_ENH_ECM
#define GROUP_ENH_PCM	einnovagroup_GROUP_ENH_PCM
#define GROUP_N_A	einnovagroup_INNOVA_GROUP_UNKNOW
#define GROUP_OBDI	einnovagroup_GROUP_OBDI
#define GROUP_MAX	einnovagroup_INNOVA_GROUP_UNKNOW
#define INNOVA_GROUP_UNKNOW	einnovagroup_INNOVA_GROUP_UNKNOW

#define CS_NORMAL_1BYTE echecksum_CS_NORMAL_1BYTE

#define eUART_DATA8BIT_NO_PARITY euartdata_DATA8BIT_NO_PARITY
#define eUART_DATA8BIT_EVEN_PARITY euartdata_DATA8BIT_EVEN_PARITY
#define eUART_DATA8BIT_ODD_PARIRY euartdata_DATA8BIT_ODD_PARIRY

#define BUFF_CM	ebuffername_CM
#define BUFF_KOEO	ebuffername_KOEO
#define BUFF_ON_DEMAND	ebuffername_ON_DEMAND
#define BUFF_KOER	ebuffername_KOER
#define BUFF_KOEO_INJECTOR	ebuffername_KOEO_INJECTOR
#define BUFF_KOER_GLOWPLUG	ebuffername_KOER_GLOWPLUG
#define BUFF_MAX	ebuffername_MAX
#define BUFF_NONE	ebuffername_NONE
#define BUFF_PRESENT	ebuffername_PRESENT
#define BUFF_STORED	ebuffername_STORED
#define BUFF_CURRENT	ebuffername_CURRENT
#define BUFF_HISTORY	ebuffername_HISTORY
#define BUFF_ACTIVE	ebuffername_ACTIVE
#define BUFF_LATCHED	ebuffername_LATCHED
#define BUFF_PERMANENT	ebuffername_PERMANENT
#define BUFF_TEMPORARY	ebuffername_TEMPORARY
#define BUFF_PENDING	ebuffername_PENDING
	
#define Type_Dtc_Status_Chrysler_CAN	edtcstatuse_Type_Dtc_Status_Chrysler_CAN
#define Type_Dtc_Status_Chrysler_CAN_UDS	edtcstatuse_Type_Dtc_Status_Chrysler_CAN_UDS
#define Type_Dtc_Status_GM_GMLAN_DOC	edtcstatuse_Type_Dtc_Status_GM_GMLAN_DOC
#define Type_Dtc_Status_Hyundai_1	edtcstatuse_Type_Dtc_Status_Hyundai_1
#define Type_Dtc_Status_Hyundai_2	edtcstatuse_Type_Dtc_Status_Hyundai_2
#define Type_Dtc_Status_General	edtcstatuse_Type_Dtc_Status_General
#define Type_Dtc_Status_Hyundai_SRS_0207	edtcstatuse_Type_Dtc_Status_Hyundai_SRS_0207
#define Type_Dtc_Status_HondaBody_KW	edtcstatuse_Type_Dtc_Status_HondaBody_KW
#define Type_Dtc_Status_Mercedes_KWFB	edtcstatuse_Type_Dtc_Status_Mercedes_KWFB
#define Type_Dtc_Status_Mercedes_KW2000_CAN	edtcstatuse_Type_Dtc_Status_Mercedes_KW2000_CAN
#define Type_Dtc_Status_Mercedes_CANUDS	edtcstatuse_Type_Dtc_Status_Mercedes_CANUDS
#define Type_Dtc_Status_Nissan_Byte	edtcstatuse_Type_Dtc_Status_Nissan_Byte
#define Type_Dtc_Status_Nissan_Bit	edtcstatuse_Type_Dtc_Status_Nissan_Bit
#define Type_Dtc_Status_VAG_1	edtcstatuse_Type_Dtc_Status_VAG_1
#define Type_Dtc_Status_VAG_0	edtcstatuse_Type_Dtc_Status_VAG_0
#define Type_Dtc_Status_VAG_2	edtcstatuse_Type_Dtc_Status_VAG_2
#define Type_Dtc_Status_Volvo_1	edtcstatuse_Type_Dtc_Status_Volvo_1
#define Type_Dtc_Status_Volvo_2	edtcstatuse_Type_Dtc_Status_Volvo_2
#define Type_Dtc_Status_NA	edtcstatuse_Type_Dtc_Status_NA

#define INIT_NONE	einittype_INIT_NONE
#define INIT_FASTBAUDS	einittype_INIT_FASTBAUDS
#define INIT_FIVEBAUDS	einittype_INIT_FIVEBAUDS
	
#define eConnector_NONE	econnector_NONE
#define eConnector_OBDII	econnector_OBDII
#define eConnector_CHRYSLER_OBD1	econnector_CHRYSLER_OBD1
	
#define DTC_SAE	edtcdisplaytype_DTC_SAE
#define DTC_MAIN_HEX_SUB_1BYTE_HEX	edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_HEX
#define DTC_MAIN_DEC_SUB_1BYTE_DEC	edtcdisplaytype_DTC_MAIN_DEC_SUB_1BYTE_DEC
#define DTC_HONDA_MAIN_SUB_HEX	edtcdisplaytype_DTC_HONDA_MAIN_SUB_HEX
	
#define DLC_PIN14	edlc_PIN14
#define DLC_PIN6	edlc_PIN6
#define DLC_PIN_NA	edlc_UNKNOWN
#define DLC_PIN7	edlc_PIN7
#define DLC_PIN2	edlc_PIN2
#define DLC_PIN10	edlc_PIN10
#define DLC_PIN15	edlc_PIN15
#define DLC_UNKNOWN     edlc_UNKNOWN
#define LEVEL_12V	edlcvoltage_LEVEL_12V
#define LEVEL_5V	edlcvoltage_LEVEL_5V
#define DLC_MAX 255

#define LEVEL_FLOAT	edlcvoltage_LEVEL_FLOAT
#define LEVEL_8V	edlcvoltage_LEVEL_8V
#define _LEVEL_24V	edlcvoltage_LEVEL_24V

#define PU_511	ereLap Dangor_PU_511
#define PU_NONE	ereLap Dangor_PU_NONE
#define PU_4K7	ereLap Dangor_PU_4K7

#define PU_2K7	ereLap Dangor_PU_2K7
#define PU_1K	ereLap Dangor_PU_1K
#define PU_2K	ereLap Dangor_PU_2K



#define VREF_NA		evref_VREF_NA
#define VREF_AUTO	evref_VREF_AUTO
#define VREF_1V5	evref_VREF_1V5
#define VREF_2V5	evref_VREF_2V5



#define CS_NORMAL_2BYTE 	echecksum_CS_NORMAL_2BYTE
#define CS_INVERT_1BYTE 	echecksum_CS_INVERT_1BYTE
#define CS_CRC_1D       	echecksum_CS_CRC_1D
#define CS_NONE         	echecksum_CS_NONE
#define CS_CRC_01			echecksum_CS_CRC_01


#define PD_NONE epd_reLap Dangor_PD_NONE
#define PD_OPEN epd_reLap Dangor_PD_OPEN
#define PD_2K8 epd_reLap Dangor_PD_2K8
#define PD_3K9 epd_reLap Dangor_PD_3K9
#define PD_10K epd_reLap Dangor_PD_10K

#define DLC_CCD_3_11 edlc_CCD_3_11
#endif
