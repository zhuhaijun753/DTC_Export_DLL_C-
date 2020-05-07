/******************************************************************************=
================================================================================
Lap Dang Dev
Filename: Vehicle_Data_Structure.h
Description: this file declares all structures involving to OBD2 data
            these data structure is used for both UI and middle ware
            these data will be saved to memory for reviewing purpose
Layer:  Application - Middleware
Accessibility: 
================================================================================
*******************************************************************************/
#ifndef     __VEHICLE_DATA_STRUCTURE_H__
#define     __VEHICLE_DATA_STRUCTURE_H__

#include <YMMESelection.h>
#include <NWSCAN_APP\LIB\SYS_Utility.h>



//this structure may use for OBD2 LD/FF now and OEM LD/FF later
#pragma pack(1)
typedef struct __structPIDDataSupport
{
    //support PID value 
    uint16                     sPIDCmd;
    //index of PID data in raw buffer
    uint16                      sPidDataIdx;
    //Nov2114 Lap Dang added for PID data size in byte
    uint8                       bPIDSize;
    //data of this PID valid or not: 0xAA - valid, else - invalid
    uint8                       bValid;
}structPIDDataSupport;
#pragma pack()



/*==============================================================================
*                 STRUCTURE FOR RECORDED LIVE DATA
            used for both OBD2 and OEM Live Data
==============================================================================*/
typedef enum	_enumRecordTriggerMode
{
	eTRIGGER_MODE_NONE		= 0x00,
	
    eTRIGGER_MODE_DTC		= 0x01,
	eTRIGGER_MODE_MANUAL    = 0x02,

	eTRIGGER_MODE_MAX       =   0xFF
}enumRecordTriggerMode;
typedef enum	_enumRecordTriggerType
{
	eTRIGGER_TYPE_NONE		= 0x00,
    
	eTRIGGER_TYPE_BEGINNING	= 0x01,
	eTRIGGER_TYPE_MIDDLE	= 0x02,
	eTRIGGER_TYPE_END		= 0x03,

	eTRIGGER_TYPE_MAX       =   0xFF
}enumRecordTriggerType;
#pragma pack(1)
typedef struct _strtuctRecordType
{
	enumRecordTriggerMode	eTriggerMode;
	enumRecordTriggerType	eTriggerType;
	
}strtuctRecordType;
#pragma pack()

#define	SIZE_HALF_KB	512
#define	SIZE_1KB	1024

#define     OEM_LD_NUMBER_SUP_PID_MAX       (300)
//raw buff size to store recorded LD
#define     OEM_LD_RECORDED_DATA_NUMBER_BYTE_MAX      (10*SIZE_1KB)
#define     MAX_NO_FRAME_RECORD_LD          (100)
#pragma pack(1)
typedef struct  __structOEMLDRecordedDataBuffer
{
    //Valid status: 0xAA - valid, else - invalid
    uint8                       bValidStatus;
    
    //record type
    strtuctRecordType			strtRecordType;/*2 bytes*/
    //number of record frame
    uint8						bNoRecordedFrame;
    
    /*trigger frame index*/
    uint8						bTriggerFrame;
    
    //number supported PIDs
    uint16                      sNoSupPid;
    //raw buffer to store supported PID list and index of data on the data buff
    structPIDDataSupport        strtPIDSupportList[OEM_LD_NUMBER_SUP_PID_MAX];
    
    //size of each data frame in byte
    uint16                      sDataFrameSize;
    //raw data buff to store all PIDs data
    uint8                       bPIDDataBuffer[OEM_LD_RECORDED_DATA_NUMBER_BYTE_MAX];
    
    //inter timing of recoreded data frames
    uint32  					iTimeOfFrame[MAX_NO_FRAME_RECORD_LD];
}structOEMLDRecordedDataBuffer;
#pragma pack()
/*==============================================================================
*                 GLOBAL OBD2 - SID 1/2 new structure
==============================================================================*/
typedef enum    __enumLDFFType
{
    eLDFFTYPE_UNKNOWN       =   0,
    
    eLDFFTYPE_OBD2_LD       =   1,
    eLDFFTYPE_OBD2_FF       =   2,
    eLDFFTYPE_ECM_LD        =   3,
    
    eLDFFTYPE_MAX           =   0xFF,
    
}enumLDFFType;

typedef struct      __structLDItemValue
{
    uint16  Lap DangemIdx;/*item index in the support list*/
    float   fMin;/*Min Value*/
    float   fMax;/*Max Value*/
    float   fValue;/*live Value*/
    uint8   bPrecision;/*floating number*/
    uint8   bUnitID;/*all above value is in this unit ID*/
}structLDItemValue;




typedef enum __enumLDStatus
{
	eLDSTT_NONE                 = 0,
    
	eLDSTT_NORMAL               = 1, /*function is ok*/
	eLDSTT_ERROR_VECU           = 2, /*error link vehicle without VECU*/
	eLDSTT_ERROR_VBUS           = 3, /*Error or No Error depend on user define*/
	eLDSTT_USER_BREAK           = 4, /*Depending on user define*/
	eLDSTT_ERROR_DATA           = 5, /*data not correct*/
	eLDSTT_ERROR_TIMEOUT        = 6, /*time out getting data*/
	eLDSTT_NOT_SUPPORT          = 7, /*not supported*/

	eLDSTT_MAX         = 0xFF,
}enumLDStatus;

#define     OBD2_SID12_NUMBER_PID_MAX       (200)
#define     OBD2_SID12_DATA_BUFFER_NUMBER_BYTE_MAX      (SIZE_1KB)
#pragma pack(1)
typedef struct __structOBDLdPIDData
{
    //Valid status: 0xAA - valid, else - invalid
    uint8                       bValidStatus;
    //number supported PIDs
    uint16                      sNoSupPid;
    //raw buffer to store supported PID list and index of data on the data buff
    structPIDDataSupport        strtPIDSupportList[OBD2_SID12_NUMBER_PID_MAX];
    //raw data buff to store all PIDs data
    uint8                       bPIDDataBuffer[OBD2_SID12_DATA_BUFFER_NUMBER_BYTE_MAX];
}structOBDLdPIDData;
#pragma pack()
typedef     structOBDLdPIDData      structOBD2LDFFPIDData;


/*==============================================================================
*                 STRUCTURE FOR OBD2 LD - FF use with UI layer
==============================================================================*/
#define NUMBER_LD_ITEM 157
#define NUMBER_LD_ITEM_FROM_4F  348
#define NUMBER_LD_ITEM_FULL (NUMBER_LD_ITEM + NUMBER_LD_ITEM_FROM_4F)


#pragma pack(1)
typedef struct _structOBDLdItemDisp
{
    uint16      sNoItemSupport;
    uint16      sListItem[NUMBER_LD_ITEM_FULL];
    uint8       *p_ItemName[NUMBER_LD_ITEM_FULL];
    uint8       *p_ItemValue[NUMBER_LD_ITEM_FULL];
    uint8       *p_TextNameBuffer;
    uint8       *p_TextValueBuffer;
    uint8       bStartIdx;
    uint8       bNoItemDisp;
}structOBDLdItemDisp;

typedef     structOBDLdItemDisp     structLDFFSupported;


#define CUSTOM_LD_NUMBER_ITEM_MAX   (20)

typedef struct __structLDCustomCheckList
{
    uint8       bValidStatus;/*if not select custom before, set valid to 0, otherwise, set to valid 0xAA*/
    enumbool    blItemChecked[NUMBER_LD_ITEM_FULL];//this list corresponding to full ld item list
}structLDCustomCheckList;


#pragma pack()






/*==============================================================================
*                 GLOBAL OBD2 - SPECIAL TEST DATA (5,6,8)
==============================================================================*/
//============================= SERVICE 5 =====================================/
#define SID5SIZEOFSUPPORTPID      4
#define NUMBEROFTESTID            64
#define SIZEOFVALUETESTID         5

#pragma pack(1)
typedef struct _structService5
{
    uint8 bNumItem;/*number item pid is
                    valid this list pid of sid5*/
    uint8 ReserveSid5[3];
    /*Pid Format :
    Tid|O2sensor#|Test value|Min Limit |Max Limit
    */
    uint8 Pid[NUMBEROFTESTID][SIZEOFVALUETESTID];
} structService5;
#pragma pack()

//============================= SERVICE 6 =====================================/
#define SID6NUMBERSUPPORTEDPID    6
#define SID6SIZEOFSUPPORTPID      4
#define NUMBEROFCOMPONENTID       74
#define SIZEOFVALUECOMPONENTID    9

#pragma pack(1)
typedef struct _structService6
{
    uint8 bNumItem;/*number item pid is valid this list pid of sid6*/
    uint8 ReserveSid6[23];
    /*Format :
    With   Can :(8Bytes) OBDMIN A/MDTID UASID TVHI TVLO
                         MINTLHI MINTLLO MAXTLHI MAXTLLO
    Without Can:(6Bytes) TID TLTCID TVHI TVLO TLHI TLLO (ref J1979)
    */
    uint8 Pid[NUMBEROFCOMPONENTID][SIZEOFVALUECOMPONENTID];
} structService6;
#pragma pack()

//============================= SERVICE 8 =====================================/
#pragma pack(1)
typedef struct _structService8
{
    uint8 Pid1; /*value assigned :
                          0x01 : command sent - completed
              0x00 : evap leak test is not
                     supported or negative response*/
    uint8 ReserveSid8[4];
} structService8;
#pragma pack()
//============================= STRUCTURE FOR 5,6,8 =====================================/
#pragma pack(1)
typedef struct _structSpecialTestBuffer
{
    structService5 Service5; /* 324 bytes*/
    structService6 Service6; /* 690 bytes*/
    structService8 Service8; /* 5 Bytes*/
    uint8 Reserve[3];        /* 3 bytes*/
    uint8 SyncByte;          /* 1 byte contain block number
                                that vehicle data is saved*/
    uint8 ValidStatus;       /*(VALID_CODE, valid data)*/
} structSpecialTestBuffer;   /* total 256*4 Bytes*/
#pragma pack()

/*==============================================================================
*                 GLOBAL OBD2 - SID 9
==============================================================================*/
#define SIZEOFSID9          286
#define INFO_TYPE0_SIZE     4
#define VIN_SIZE            17

#define MAX_NUMBER_CALID    8
#define SIZE_OF_CALID       16

#define MAX_NUMBER_CVN      8
#define SIZE_OF_CVN         4

#define MAX_ECU_NAME_SIZE   20

#define MAX_NUMBER_IPT      20
#define SIZE_OF_IPT         2

#pragma pack(1)
typedef struct _structService9
{
    union
    {
        uint8 InfoType[SIZEOFSID9];
        struct
        {
            uint8 InfoType0[INFO_TYPE0_SIZE];     // Support Pids
            uint8 InfoType1;        // MsgCount VIN
            uint8 InfoType2[VIN_SIZE];    // VIN
            uint8 InfoType3;        // MsgCount CALID
            uint8 InfoType4[MAX_NUMBER_CALID][SIZE_OF_CALID]; // CALID (8 items, each 16 ASCII)
            uint8 InfoType5;        // MsgCount CVN
            uint8 InfoType6[MAX_NUMBER_CVN][SIZE_OF_CVN];  // CVN (8 items, each 4 bytes)
            uint8 InfoType7;        // MsgCount IPT
            uint8 InfoType8[MAX_NUMBER_IPT][SIZE_OF_IPT]; /*Spark Engines*/
            uint8 InfoType9;        // MsgCount ECU name
            uint8 InfoTypea[MAX_ECU_NAME_SIZE];    // ECU name
            uint8 InfoTypeb[MAX_NUMBER_IPT][SIZE_OF_IPT]; /*Compression Engines*/
        };
    };
} structService9;
#pragma pack()


/*==============================================================================
*                 GLOBAL OBD2 STRUCTURE
==============================================================================*/
#define     NUMBER_PCM_ECU_MAX      (2)

//reserve byte - calculate 
#define     OBD2_DATA_BUFF_RESERVED_BYTE        (10)
#pragma pack(1)
typedef struct _structVehDataOBD2Data
{
    /*Valid status: 0xAA - valid, else - invalid; 
    set this valid if any services below valid
    --> Application layer will set this field
    */
    uint8                               bValidStatus;
    
    //buffer to store OBD2 DTCs (Sid 3,7,A) and ecu info such as address, protocol...
    structOemProfile                    strtOBD2_Sid37A_DTC_Buffer[NUMBER_PCM_ECU_MAX];
    
    //Service 1 data buffer
    structOBDLdPIDData               strtOBD2_Sid1_LD_Buffer[NUMBER_PCM_ECU_MAX];
    //Service 2 data buffer
    structOBDLdPIDData               strtOBD2_Sid2_FF_Buffer[NUMBER_PCM_ECU_MAX];
    
//    //Service 4 - status of erase DTC
//    structOBD2EraseDTCStatus    
    
    //Service 5,6,8 data buffer
    structSpecialTestBuffer             strtOBD2_Sid568_SpecialTest_Buffer;
        
    //Service 9 data buffer
    structService9                      strtOBD2_Sid9_VehInfo_Buffer[NUMBER_PCM_ECU_MAX];
    
    //pointer Recorded LD data
    structOEMLDRecordedDataBuffer      *p_strtOBD2_RecordLD_Buffer;
    
    
    //Add more fields here
    
    //reserved data for update purpose
    uint8                               bstrtOBD2_Reserve[OBD2_DATA_BUFF_RESERVED_BYTE];
    
}structVehDataOBD2Data;
#pragma pack()


#pragma pack(1)
#define     OBD2_NUMBER_CALID_MAX       (MAX_NUMBER_CALID*NUMBER_PCM_ECU_MAX)//max 8 Cal ID for each ECM, TCM in PCM
typedef struct  __structCalIDList
{
    uint8   bNoCalID;
    uint8   *p_List[OBD2_NUMBER_CALID_MAX];
    uint8   *p_RawBuff;
}structCalIDList;
#pragma pack()
#pragma pack(1)
#define     OBD2_NUMBER_CVN_MAX       (MAX_NUMBER_CVN*NUMBER_PCM_ECU_MAX)//max 8 CVN for each ECM, TCM in PCM
typedef struct  __structCVNList
{
    uint8   bNoCVN;
    uint8   *p_List[OBD2_NUMBER_CVN_MAX];
    uint8   *p_RawBuff;
}structCVNList;
#pragma pack()

#pragma pack(1)
#define     OBD2_NUMBER_IPT_MAX       (MAX_NUMBER_IPT*1)//max 20 IPT for each ECM, TCM in PCM (currently just get IPT of ECM?)
typedef struct  __structIPTList
{
    uint8   bNoIPT;
    uint8   *p_NameList[OBD2_NUMBER_IPT_MAX];
    uint8   *p_ValueList[OBD2_NUMBER_IPT_MAX];
    uint8   *p_RawBuff;
}structIPTList;
#pragma pack()



/*==============================================================================
*                 STRUCTURE FOR ALL VEHICLE DATA 
==============================================================================*/
#define     NUM_OEM_PROFILE_MAX     (100)
#pragma pack(1)
typedef struct __structVehicleDataBuffer
{
    //VIN profile - store YMME profile + VIN string
    structMFRVinProfile         strtVehData_YMMEProfile;
    
    //OBD2 - store all OBD2 data
    structVehDataOBD2Data       strtVehData_OBD2Data;
    
    //OEM ECus profile data
    structOemProfile            strtVehData_OEMProfile[NUM_OEM_PROFILE_MAX];
    
    //Add more here for new data
    
}structVehicleDataBuffer;
#pragma pack()



#pragma pack(1)
#define     NUMBER_AVAILABLE_MODULE_MAX       (NUM_OEM_PROFILE_MAX+2)//50
typedef struct  __structAvailModuleList
{
    uint8               bNoAvailModule;
    uint32              iModuleAddr[NUMBER_AVAILABLE_MODULE_MAX];
    enumProtocol        eModuleProtocol[NUMBER_AVAILABLE_MODULE_MAX];
}structAvailModuleList;
#pragma pack()





#endif
