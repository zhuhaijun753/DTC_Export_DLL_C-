/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : SYS_Utility.h
Description     : Define common parameter as standard of Innova
Engineer        : Lap Dang - Created 17 Jan 2011
History         :

|-Version     |   Date       |  Engineer   |        Note                     -|
  +V01.00.00    17Jan2011         Lap Dang      *Initialize
  +V01.00.01    19Jan2011         Lap Dang      fixed livedata supported to 160 items
                                              added structDtcParser
  +
  +
  +
  +
  +
===============================================================================
******************************************************************************/
#ifndef SYS_UTILITY_H
#define SYS_UTILITY_H
#include "InnovaStd.h"
#include "VBI_Utility.h"

//#define NUM_OEM_PROFILE             100//Hung Vo changed as Thanh Requested on 30 Oct 2013

#ifndef INVALID_CODE
#define INVALID_CODE 0
#endif

#ifndef VALID_CODE
#define VALID_CODE  0xAA
#endif

#define _FLASH_BASE_SIZE_SMALL_ 256

typedef enumSystemStatus (*pfunctionProtocolLink)(void * p_strtVehicleProfile, pRom_Req pCmdLink,pRom_Req pCmdWK);
typedef void *(*pfunctionVehConfig)(void * p_VehicleProfile);



typedef enumQueryPrcSt (*pfMakeProtocolQuery)(void * p_VehicleProfile);

typedef enumbool (*pfMakeProtocolReadDtc)(void * p_VehicleProfile,
        void * p_strtListReadDTC);
typedef enumErasePrcSt (*pfMakeProtocolErase)(void * p_strtVehicleProfile);
typedef enumKeepAlivePrcSt (*pfProtocolKeepalive)(void * p_strtVehicleProfile);
typedef enumExitPrcSt (*pfProtocolExit)(void * p_strtVehicleProfile);
typedef void (*pfMakeProtocolDtcParser)(void * p_strtVehicleProfile);

typedef enumEcuInfoPrcSt (*pfMakeProtocolEcuInfo)(void * p_strtVehicleProfile,void * p_ReadEcu);


typedef uint16  _ManufactureType;
typedef uint16 enumController;

typedef enumbool (*pfunc_IsValidDtc)(uint8 * pDtc, uint8 bFmt);
#define MODULE_NA       0xFFFF
//#define GENERIC         __MAX_TYPE(_ManufactureType)    /*Indicate OBD2 Selection*/

typedef void(*pfunctionConfig)(void);
#pragma pack(1)
typedef struct _structVehDB
{
    enumProtocol    eProtocol       ;
    structDLCName   strtDLC_CANH_RX ;
    structDLCName   strtDLC_CANL_TX ;
    structDLCName   strtDLC_Init    ;/*Five Baud */

    enumVreftype        eVref;
    uint32              iBaudrate;
    enumUartDataType    eUartDataType;

    structTimingP       *pstrtTimingP;
    structTimingW       *pstrtTimingW;
    structTimingWakeUp  *pstrtTimingWakeUp;

    enumCheckSumType eCheckSumType;
    enumInitType    eInitType;
    uint8           bFB;

    uint32 Hdr1;//CAN TX
    uint32 Hdr2;//CAN RX1
    uint32 Hdr3;//CAN RX2
    uint32 Hdr4;//CAN RX3
    uint32 Hdr5;//CAN RX4

    enumCommandList                 ePPCmdQuery;

    enumCommands                    ePCmdKeepAlive;

    enumReadDtcCommandList          eReadDtcCmdID;

    enumCommandList                 ePPCmdErase;

    enumCommands                    ePCmdExit;

    enumCommandList                 ePPCmdEcuInfo;

    DTC_DISP_TYPE                   DtcDispType;
    uint8                           DtcEraseType;
    uint8                           EcuInfoParserType;
    uint16                          sDTCTableID;/*Use in lookup table dtc */
    uint8                           DtcReadType;/*can be use to mark some oem protocol with some special processing data*/

    uint16                          sSystem;
    uint16                          sSubSystem;

    enumbool                        IsCanMode;
    uint32                          iProfileID;//Use to tracking database

    uint8 bKwHdr;
    uint8 bKwTag;
    uint8 bKwSrc;
    enumConnectors                  eConnector;
    enumbool                        eAutoFmtKW;
} structVehDB;

#pragma pack()

#define strt_prot_lib_X(Make,n)     const structVehDB strt##Make##DB_##n
#define pstrt_prot_lib_X(Make,n)    &strt##Make##DB_##n
#define ROM_Cmd_NA                  0

#define SIZE_OF_OEM_DTC         162
#define OEM_INFO_LEN            50

typedef enum _enumOemDtcBuffStatus
{
    OEM_DTC_INVALID=0,
    OEM_DTC_NOTSUPPORT_DB,//Can not implement since missing database or some problem from ECU : Ex Honda Srs
    OEM_DTC_READDTC_NOTSUPPORTED,
    OEM_DTC_VALID=0xAA,
}enumOemDtcBuffStatus;
#pragma pack(1)
typedef struct _structOEMDTCBuffer
{
#ifdef _MSC_VER
	uint8   DtcDispType;
#else
    DTC_DISP_TYPE   DtcDispType;
#endif
    uint8           NumberDTC;                           /*1byte*/
    uint8           bFormatDtc;
    uint8           DTC[SIZE_OF_OEM_DTC];/*16x3 = 48byte*/
    uint8           bTypeDtcStatusType;/*Use to indicate parser type of dtc status of each dtc
                                    as normal / general , oem : GM , Chrysler , Mercedes ....
                                    since each dtc could be have multti - status*/
    uint8 			bOffSetRawDtc;
    uint8           Reserves[8];
#ifdef _MSC_VER
	uint8   eStatus;
#else
    enumOemDtcBuffStatus    eStatus;
#endif
} structOEMDTCBuffer;    /*Total :  55 bytes*/

#ifdef _MSC_VER
#define USED_OEM_BUFFER (2+2+1+sizeof(uint16)+4+sizeof(structOEMDTCBuffer)+4+4+2+2+1)
#else
#define USED_OEM_BUFFER (2+2+1+sizeof(enumProtocol)+4+sizeof(structOEMDTCBuffer)+4+4+2+2+1)
#endif
typedef enum _enumSystemtype
{
    eTYPE_SYSTEM=1,
    eTYPE_SUBSYSTEM=2,
    eTYPE_UNKNOW=0xff
}enumSystemtype;
typedef structVehDB*(*pfunction_ProfileIDToVehDB)(void *p_strtVehicleProfile) ;
typedef struct _structVehProfileInfo
{
        uint16 sNumProfileSupported;
        uint32 *pListAddressProfileIDs;
        uint16 sPresentIdx;
        pfunction_ProfileIDToVehDB pf_ProfileIDToVehDB;
        uint8   bInnovaGroup;
        enumConnectors eConnectorAddition;
        uint8 bStatus;
}structVehProfileInfo;

typedef struct _structOemProfile
{
    uint16              sSubSystem;
    uint16              sSystem;
    uint8               bSelInnGroup;
#ifdef _MSC_VER
	uint16   Protocol;
#else
    enumProtocol        Protocol;
#endif
    uint32              EcuAddr ;

    union
    {
      structOEMDTCBuffer  strtOEMDTCBuffer;
      void *pUserData;/**/
    };
    uint8               OemInfo[OEM_INFO_LEN];


    uint8               Reserve[_FLASH_BASE_SIZE_SMALL_-USED_OEM_BUFFER-OEM_INFO_LEN-4];

    uint32              iLinkedIdx1;                                                       //4
    uint32              iProfileID;//Know as Message ID
    uint32				iLinkedBaudRate;
    enumCommands        eCmdKeepAliveDetect;
    enumCommands        eCmdQueryActive;
    uint8               ValidStatus;                    /* = 0xaa (VALID_CODE, valid data) 1*/
}structOemProfile;
#pragma pack()

typedef enumQueryPrcSt (*pfNWS_Proc_Query)(void * p_strtVehicleProfile);
typedef enumLinkPrcSt (*pfNWS_Proc_ReadDtc)(void * p_strtVehicleProfile);
typedef enumErasePrcSt (*pfNWS_Proc_Erase)(void * p_strtVehicleProfile);
typedef enumKeepAlivePrcSt (*pfNWS_Proc_Keepalive)(void * p_strtVehicleProfile);
typedef enumExitPrcSt (*pfNWS_Proc_Exit)(void * p_strtVehicleProfile);
typedef void (*pfNWS_Proc_DtcParser)(void * p_strtVehicleProfile);
typedef enumEcuInfoPrcSt (*pfNWS_Proc_EcuInfo)(void * p_strtVehicleProfile);

typedef struct _structNWS_Proc_Libs
{
    pfNWS_Proc_Query             pfProtQuery;
    pfNWS_Proc_ReadDtc           pfProtReadDtc;
    pfNWS_Proc_Erase             pfProtErase ;
    pfNWS_Proc_Keepalive         pfProtKeepalive;
    pfNWS_Proc_Exit              pfProtExit;
    pfNWS_Proc_DtcParser         pfDtcParser;
    pfNWS_Proc_EcuInfo           pfProtEcuInfo;
} structNWS_Proc_Libs;
//

typedef struct _structVehNWScanSupported
{
    _ManufactureType                 eVehicle;
    p_ROM_Str                   pVehVersion;
    //const structVehicleOEMModule    *p_strtVehOEMModule;
    
    //uint16        *p_ListModule;
    /*format 
    Module1       2Bytes
    Module2       2Bytes
    ...
    ModuleN       2Bytes

    MODULE_NA     End of List  
    */
    /*
     * Core Libs
     * */
    pfunctionProtocolLink              pf_ProtocolLink;
    pfunctionVehConfig                 pfLoadVehDbToProfile;

    pfMakeProtocolQuery              pfMakeQuery;

    pfMakeProtocolReadDtc            pfMakeDtc;
    pfMakeProtocolErase              pfMakeProtErase ;
    pfMakeProtocolDtcParser          pfMakeParser;
    pfMakeProtocolEcuInfo            pfMakeEcuInfo;


    const void **ppUserData;      /*Use to point to other database depend on user application
                                ex : Mercedes will use it protocol library , Livedata lib ...*/

} structVehNWScanSupported;
#define VehNWScanEND    {GENERIC,Null,Null,Null,Null,Null,Null,Null,Null}
typedef enum _enumVBIProcessType
{
    VBI_TYPE_QUERY,
    VBI_TYPE_READDTC,
    VBI_TYPE_ERASEDTC,
    VBI_TYPE_KEEPALIVE,
    VBI_TYPE_EXIT,
    VBI_TYPE_ECUINFO,
    VBI_TYPE_CUSTOM_LINK
}enumVBIProcessType;


#pragma pack(1)

typedef struct _structNWScanYmmeUsing
{
    //uint16 sVehicle;
    uint16 sMake;
    union
    {
       struct
       {
        enumbool use_bYear:1;
        enumbool use_sMake:1;
        enumbool use_sModel:1;
        enumbool use_sEngine:1;
        enumbool use_sTrim:1;
        enumbool use_sTrasmission:1;
        enumbool use_sOption1:1;
        enumbool use_sOption2:1;

        enumbool use_sOption3:1;
        enumbool use_sBodyCode:1;
        enumbool bit1_2:1;
        enumbool bit1_3:1;
        enumbool bit1_4:1;
        enumbool bit1_5:1;
        enumbool bit1_6:1;
        enumbool bit1_7:1;
       };
       uint8 bData[2];
    };
    const void *pMwLib;
}structNWScanYmmeUsing;
typedef enum _enumNWS_Market
{
	_NWS_MARKET_US=1,
	_NWS_MARKET_MX=2,
	_NWS_MARKET_VN=3,
	_NWS_MARKET_CN=4,
	_NWS_MARKET_IN=5,
	_NWS_MARKET_JP=6,
	_NWS_MARKET_EU=7,
	_NWS_MARKET_AU=8,
}enumNWS_Market;
#define _NWS_MARKET_DEFAULT	_NWS_MARKET_US
typedef struct _structNwSYmme
{
    uint8  bYear;
    uint16 sMake;
    uint16 sModel;
    uint16 sEngine;
    uint16 sTrim;
    uint16 sTransmission;
    uint16 sOption1;
    uint16 sOption2;
    uint16 sOption3;
    uint16 sSystem;
    uint16 sSubSystem;
} structNwSYmme;
#pragma pack()
//structNwSYmme                   g_strtNwSYmme;

#pragma pack(1)

//structVehDB* gf_SYS_ProfileIDToVehDB(uint32 iProfileID)
struct _structVehicleProfile
{
    
    uint16               s_Query_SubSystem;//Present Module
    uint16                  s_Query_System;
    uint16            sManufacture;
    enumInnovaGroups            bInnovaGroup;
    enumConnectors				eConnector;	/*Save Present Connector*/
    structNwSYmme               strtNwSYmme;
    uint8 						bReserve[10];

    structOemProfile            *p_strtOemProfiles;
    uint16                      sMaxNumOemProfile;

    structLinkProfile           *p_strtLinkProfile;
    structVehNWScanSupported    strtVehNWScanSupported;
    structNWS_Proc_Libs         strtNWS_Proc_Libs;
    void (*pf_Query)(struct _structVehicleProfile *p_strtVehicleProfile);
    void (*pf_ReadDtc)(struct _structVehicleProfile *p_strtVehicleProfile);
    void (*pf_EraseDtc)(struct _structVehicleProfile *p_strtVehicleProfile);
    void (*pf_KeepAlive)(struct _structVehicleProfile *p_strtVehicleProfile);
    void (*pf_Exit)(struct _structVehicleProfile *p_strtVehicleProfile);
    void (*pf_EcuInfo)(struct _structVehicleProfile *p_strtVehicleProfile);

    //structVehDB *(*pfLoadVehDbToProfile)(struct _structVehicleProfile * p_VehicleProfile);
    pfunctionVehConfig pfLoadVehDbToProfile;
    //enumSystemStatus (*pf_ProtocolLink)(struct _structVehicleProfile * p_VehicleProfile,pRom_Req pCmdLink,pRom_Req pCmdWK);
    pfunctionProtocolLink pf_ProtocolLink;
    uint16                      sNumModuleActive;
    enumVBIProcessType          eVBIPresentProcType;
    structVehProfileInfo        strtVehProfileInfo;
    structVehDB strtVehDB;
    void *pstrtVehBuffer;//Depend on application structVehicleDataBuffer
};
typedef  struct _structVehicleProfile structVehicleProfile;
#pragma pack()

/*
 * OBD1 section
 *
 * */

#define PIN_D       edlc_PIN7_OBD1
#define PIN_L       edlc_PIN7_OBD1
#define PIN_M       edlc_PIN7_OBD1
#define PIN_L_M     edlc_PIN7_OBD1
#define PIN_E       edlc_PIN15_OBD1

#define BAUDRATE80      80
#define BAUDRATE100     100
#define BAUDRATE160     160
#define BAUDRATE8192    8192



void gf_Util_ShiftLeftBuff(uint8 *p_bDataBuff,uint16 bSize,uint8 bNumOffSet);
void gf_Util_ShiftRightBuff(uint8 *p_bDataBuff,uint16 bSize,uint8 bNumOffSet);
uint32 gf_Util_Byte2Int_BIndian(uint8 *pByte);
signed char gf_Util_DataGetBitPos(uint8 bData);
void gf_SYS_DelayUs(uint16 sUs);
void gf_SYS_DelayMs(uint32 iMs);
void gf_Util_BufferCopy(uint8 * tag,uint8 *src,uint32 iLen);
void gf_Util_BufferSet(uint8*src,uint32 iLen,uint8 Val);

#define g_CheckBreakCondition()     gf_SYS_CheckBreakCondition(p_strtLinkProfile)
#define g_FlashLinkIcon()           gf_SYS_FlashLinkIcon(p_strtLinkProfile)
#define __BUFF_COPY_(a,b,n) gf_Util_BufferCopy((uint8*)(a),(uint8*)(b),(n))

#ifndef DEBUG_LINE
#if DEBUG_LEVEL != 0
#define DEBUG_LINE(a ...) printf(">>");printf(a);printf("\r\n")
#else
#ifdef _MSC_VER
#define DEBUG_LINE
#else
#define DEBUG_LINE(a ...)
#endif
#endif
#endif

#if DEBUG_LEVEL == 2
    #define DEBUG_LEVEL2_LINE    DEBUG_LINE
#else
    #define DEBUG_LEVEL2_LINE
#endif
#endif
