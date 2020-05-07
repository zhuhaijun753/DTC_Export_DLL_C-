/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : ProtocolUtility.h
Description     : Define structure for API driver
Engineer        : Lap Dang - Created 17 Jan 2011
History         :

|-Version     |   Date       |  Engineer   |        Note                     -|
  +V01.00.00    17Jan2011         Lap Dang      *Initialize
  +V01.00.01    20Jan2011         Lap Dang      fixed align memory,pack...
  +V01.00.02    24Feb2011         Lap Dang      added field eDLCRxPinName in DLC profile
  +V01.00.03    28Feb2011         Lap Dang      added protocol PROTOCOL_KW476 Renault ABS
  +V01.00.04    18May2011         Lap Dang      synchronize enumprotocol with R&D V01.00.30
  +
  +
  +
===============================================================================
******************************************************************************/
#ifndef _PROTOCOL_UTILITY_H
#define _PROTOCOL_UTILITY_H
#include "InnovaStd.h"


typedef enum _enumService
{
    SID01= 0x01,SID02= 0x02,SID03= 0x03,SID04= 0x04,SID05= 0x05,SID06= 0x06,
    SID07= 0x07,SID08= 0x08,SID09= 0x09,SID0A= 0x0A,SID0B= 0x0B,SID0C= 0x0C,
    SID0D= 0x0D,SID0E= 0x0E,SID0F= 0x0F,SID10= 0x10,SID11= 0x11,SID12= 0x12,
    SID13= 0x13,SID14= 0x14,SID15= 0x15,SID16= 0x16,SID17= 0x17,SID18= 0x18,
    SID19= 0x19,SID1A= 0x1A,SID1B= 0x1B,SID1C= 0x1C,SID1D= 0x1D,SID1E= 0x1E,
    SID1F= 0x1F,SID20= 0x20,SID21= 0x21,SID22= 0x22,SID23= 0x23,SID24= 0x24,
    SID25= 0x25,SID26= 0x26,SID27= 0x27,SID28= 0x28,SID29= 0x29,SID2A= 0x2A,
    SID2B= 0x2B,SID2C= 0x2C,SID2D= 0x2D,SID2E= 0x2E,SID2F= 0x2F,SID30= 0x30,
    SID31= 0x31,SID32= 0x32,SID33= 0x33,SID34= 0x34,SID35= 0x35,SID36= 0x36,
    SID37= 0x37,SID38= 0x38,SID39= 0x39,SID3A= 0x3A,SID3B= 0x3B,SID3C= 0x3C,
    SID3D= 0x3D,SID3E= 0x3E,SID3F= 0x3F,SID40= 0x40,SID41= 0x41,SID42= 0x42,
    SID43= 0x43,SID44= 0x44,SID45= 0x45,SID46= 0x46,SID47= 0x47,SID48= 0x48,
    SID49= 0x49,SID4A= 0x4A,SID4B= 0x4B,SID4C= 0x4C,SID4D= 0x4D,SID4E= 0x4E,
    SID4F= 0x4F,SID50= 0x50,SID51= 0x51,SID52= 0x52,SID53= 0x53,SID54= 0x54,
    SID55= 0x55,SID56= 0x56,SID57= 0x57,SID58= 0x58,SID59= 0x59,SID5A= 0x5A,
    SID5B= 0x5B,SID5C= 0x5C,SID5D= 0x5D,SID5E= 0x5E,SID5F= 0x5F,SID60= 0x60,
    SID61= 0x61,SID62= 0x62,SID63= 0x63,SID64= 0x64,SID65= 0x65,SID66= 0x66,
    SID67= 0x67,SID68= 0x68,SID69= 0x69,SID6A= 0x6A,SID6B= 0x6B,SID6C= 0x6C,
    SID6D= 0x6D,SID6E= 0x6E,SID6F= 0x6F,SID70= 0x70,SID71= 0x71,SID72= 0x72,
    SID73= 0x73,SID74= 0x74,SID75= 0x75,SID76= 0x76,SID77= 0x77,SID78= 0x78,
    SID79= 0x79,SID7A= 0x7A,SID7B= 0x7B,SID7C= 0x7C,SID7D= 0x7D,SID7E= 0x7E,
    SID7F= 0x7F,SID80= 0x80,SID81= 0x81,SID82= 0x82,SID83= 0x83,SID84= 0x84,
    SID85= 0x85,SID86= 0x86,SID87= 0x87,SID88= 0x88,SID89= 0x89,SID8A= 0x8A,
    SID8B= 0x8B,SID8C= 0x8C,SID8D= 0x8D,SID8E= 0x8E,SID8F= 0x8F,SID90= 0x90,
    SID91= 0x91,SID92= 0x92,SID93= 0x93,SID94= 0x94,SID95= 0x95,SID96= 0x96,
    SID97= 0x97,SID98= 0x98,SID99= 0x99,SID9A= 0x9A,SID9B= 0x9B,SID9C= 0x9C,
    SID9D= 0x9D,SID9E= 0x9E,SID9F= 0x9F,SIDA0= 0xA0,SIDA1= 0xA1,SIDA2= 0xA2,
    SIDA3= 0xA3,SIDA4= 0xA4,SIDA5= 0xA5,SIDA6= 0xA6,SIDA7= 0xA7,SIDA8= 0xA8,
    SIDA9= 0xA9,SIDAA= 0xAA,SIDAB= 0xAB,SIDAC= 0xAC,SIDAD= 0xAD,SIDAE= 0xAE,
    SIDAF= 0xAF,SIDB0= 0xB0,SIDB1= 0xB1,SIDB2= 0xB2,SIDB3= 0xB3,SIDB4= 0xB4,
    SIDB5= 0xB5,SIDB6= 0xB6,SIDB7= 0xB7,SIDB8= 0xB8,SIDB9= 0xB9,SIDBA= 0xBA,
    SIDBB= 0xBB,SIDBC= 0xBC,SIDBD= 0xBD,SIDBE= 0xBE,SIDBF= 0xBF,SIDC0= 0xC0,
    SIDC1= 0xC1,SIDC2= 0xC2,SIDC3= 0xC3,SIDC4= 0xC4,SIDC5= 0xC5,SIDC6= 0xC6,
    SIDC7= 0xC7,SIDC8= 0xC8,SIDC9= 0xC9,SIDCA= 0xCA,SIDCB= 0xCB,SIDCC= 0xCC,
    SIDCD= 0xCD,SIDCE= 0xCE,SIDCF= 0xCF,SIDD0= 0xD0,SIDD1= 0xD1,SIDD2= 0xD2,
    SIDD3= 0xD3,SIDD4= 0xD4,SIDD5= 0xD5,SIDD6= 0xD6,SIDD7= 0xD7,SIDD8= 0xD8,
    SIDD9= 0xD9,SIDDA= 0xDA,SIDDB= 0xDB,SIDDC= 0xDC,SIDDD= 0xDD,SIDDE= 0xDE,
    SIDDF= 0xDF,SIDE0= 0xE0,SIDE1= 0xE1,SIDE2= 0xE2,SIDE3= 0xE3,SIDE4= 0xE4,
    SIDE5= 0xE5,SIDE6= 0xE6,SIDE7= 0xE7,SIDE8= 0xE8,SIDE9= 0xE9,SIDEA= 0xEA,
    SIDEB= 0xEB,SIDEC= 0xEC,SIDED= 0xED,SIDEE= 0xEE,SIDEF= 0xEF,SIDF0= 0xF0,
    SIDF1= 0xF1,SIDF2= 0xF2,SIDF3= 0xF3,SIDF4= 0xF4,SIDF5= 0xF5,SIDF6= 0xF6,
    SIDF7= 0xF7,SIDF8= 0xF8,SIDF9= 0xF9,SIDFA= 0xFA,SIDFB= 0xFB,SIDFC= 0xFC,
    SIDFD= 0xFD,SIDFE= 0xFE,SIDFF= 0xFF
} enumService;
typedef enum _enumPid
{
    PID0  = 0x00,PID1  = 0x01,PID2  = 0x02,PID3  = 0x03,PID4  = 0x04,PID5  = 0x05,PID6  = 0x06,
    PID7  = 0x07,PID8  = 0x08,PID9  = 0x09,PIDA  = 0x0A,PIDB  = 0x0B,PIDC  = 0x0C,PIDD  = 0x0D,
    PIDE  = 0x0E,PIDF  = 0x0F,PID10 = 0x10,PID11 = 0x11,PID12 = 0x12,PID13 = 0x13,PID14 = 0x14,
    PID15 = 0x15,PID16 = 0x16,PID17 = 0x17,PID18 = 0x18,PID19 = 0x19,PID1A = 0x1A,PID1B = 0x1B,
    PID1C = 0x1C,PID1D = 0x1D,PID1E = 0x1E,PID1F = 0x1F,PID20 = 0x20,PID21 = 0x21,PID22 = 0x22,
    PID23 = 0x23,PID24 = 0x24,PID25 = 0x25,PID26 = 0x26,PID27 = 0x27,PID28 = 0x28,PID29 = 0x29,
    PID2A = 0x2A,PID2B = 0x2B,PID2C = 0x2C,PID2D = 0x2D,PID2E = 0x2E,PID2F = 0x2F,PID30 = 0x30,
    PID31 = 0x31,PID32 = 0x32,PID33 = 0x33,PID34 = 0x34,PID35 = 0x35,PID36 = 0x36,PID37 = 0x37,
    PID38 = 0x38,PID39 = 0x39,PID3A = 0x3A,PID3B = 0x3B,PID3C = 0x3C,PID3D = 0x3D,PID3E = 0x3E,
    PID3F = 0x3F,PID40 = 0x40,PID41 = 0x41,PID42 = 0x42,PID43 = 0x43,PID44 = 0x44,PID45 = 0x45,
    PID46 = 0x46,PID47 = 0x47,PID48 = 0x48,PID49 = 0x49,PID4A = 0x4A,PID4B = 0x4B,PID4C = 0x4C,
    PID4D = 0x4D,PID4E = 0x4E,PID4F = 0x4F,PID50 = 0x50,PID51 = 0x51,PID52 = 0x52,PID53 = 0x53,
    PID54 = 0x54,PID55 = 0x55,PID56 = 0x56,PID57 = 0x57,PID58 = 0x58,PID59 = 0x59,PID5A = 0x5A,
    PID5B = 0x5B,PID5C = 0x5C,PID5D = 0x5D,PID5E = 0x5E,PID5F = 0x5F,PID60 = 0x60,PID61 = 0x61,
    PID62 = 0x62,PID63 = 0x63,PID64 = 0x64,PID65 = 0x65,PID66 = 0x66,PID67 = 0x67,PID68 = 0x68,
    PID69 = 0x69,PID6A = 0x6A,PID6B = 0x6B,PID6C = 0x6C,PID6D = 0x6D,PID6E = 0x6E,PID6F = 0x6F,
    PID70 = 0x70,PID71 = 0x71,PID72 = 0x72,PID73 = 0x73,PID74 = 0x74,PID75 = 0x75,PID76 = 0x76,
    PID77 = 0x77,PID78 = 0x78,PID79 = 0x79,PID7A = 0x7A,PID7B = 0x7B,PID7C = 0x7C,PID7D = 0x7D,
    PID7E = 0x7E,PID7F = 0x7F,PID80 = 0x80,PID81 = 0x81,PID82 = 0x82,PID83 = 0x83,PID84 = 0x84,
    PID85 = 0x85,PID86 = 0x86,PID87 = 0x87,PID88 = 0x88,PID89 = 0x89,PID8A = 0x8A,PID8B = 0x8B,
    PID8C = 0x8C,PID8D = 0x8D,PID8E = 0x8E,PID8F = 0x8F,PID90 = 0x90,PID91 = 0x91,PID92 = 0x92,
    PID93 = 0x93,PID94 = 0x94,PID95 = 0x95,PID96 = 0x96,PID97 = 0x97,PID98 = 0x98,PID99 = 0x99,
    PID9A = 0x9A,PID9B = 0x9B,PID9C = 0x9C,PID9D = 0x9D,PID9E = 0x9E,PID9F = 0x9F,PIDA0 = 0xA0,
    PIDA1 = 0xA1,PIDA2 = 0xA2,PIDA3 = 0xA3,PIDA4 = 0xA4,PIDA5 = 0xA5,PIDA6 = 0xA6,PIDA7 = 0xA7,
    PIDA8 = 0xA8,PIDA9 = 0xA9,PIDAA = 0xAA,PIDAB = 0xAB,PIDAC = 0xAC,PIDAD = 0xAD,PIDAE = 0xAE,
    PIDAF = 0xAF,PIDB0 = 0xB0,PIDB1 = 0xB1,PIDB2 = 0xB2,PIDB3 = 0xB3,PIDB4 = 0xB4,PIDB5 = 0xB5,
    PIDB6 = 0xB6,PIDB7 = 0xB7,PIDB8 = 0xB8,PIDB9 = 0xB9,PIDBA = 0xBA,PIDBB = 0xBB,PIDBC = 0xBC,
    PIDBD = 0xBD,PIDBE = 0xBE,PIDBF = 0xBF,PIDC0 = 0xC0,PIDC1 = 0xC1,PIDC2 = 0xC2,PIDC3 = 0xC3,
    PIDC4 = 0xC4,PIDC5 = 0xC5,PIDC6 = 0xC6,PIDC7 = 0xC7,PIDC8 = 0xC8,PIDC9 = 0xC9,PIDCA = 0xCA,
    PIDCB = 0xCB,PIDCC = 0xCC,PIDCD = 0xCD,PIDCE = 0xCE,PIDCF = 0xCF,PIDD0 = 0xD0,PIDD1 = 0xD1,
    PIDD2 = 0xD2,PIDD3 = 0xD3,PIDD4 = 0xD4,PIDD5 = 0xD5,PIDD6 = 0xD6,PIDD7 = 0xD7,PIDD8 = 0xD8,
    PIDD9 = 0xD9,PIDDA = 0xDA,PIDDB = 0xDB,PIDDC = 0xDC,PIDDD = 0xDD,PIDDE = 0xDE,PIDDF = 0xDF,
    PIDE0 = 0xE0,PIDE1 = 0xE1,PIDE2 = 0xE2,PIDE3 = 0xE3,PIDE4 = 0xE4,PIDE5 = 0xE5,PIDE6 = 0xE6,
    PIDE7 = 0xE7,PIDE8 = 0xE8,PIDE9 = 0xE9,PIDEA = 0xEA,PIDEB = 0xEB,PIDEC = 0xEC,PIDED = 0xED,
    PIDEE = 0xEE,PIDEF = 0xEF,PIDF0 = 0xF0,PIDF1 = 0xF1,PIDF2 = 0xF2,PIDF3 = 0xF3,PIDF4 = 0xF4,
    PIDF5 = 0xF5,PIDF6 = 0xF6,PIDF7 = 0xF7,PIDF8 = 0xF8,PIDF9 = 0xF9,PIDFA = 0xFA,PIDFB = 0xFB,
    PIDFC = 0xFC,PIDFD = 0xFD,PIDFE = 0xFE,PIDFF = 0xFF
} enumPid;
typedef enum _enumUsartMode
{
  PROTOCOL_USART_RX,
  PROTOCOL_USART_TX,
  PROTOCOL_USART_RTX,
  PROTOCOL_RS485_RX,
  PROTOCOL_RS485_TX,
  PROTOCOL_RS485_RTX,
        
} enumUsartMode;

typedef enum _enumNegStatus
{
    NEG00_G_REJECT          =0x00,
    NEG10_G_REJECT          =0x10,
    NEG11_SER_NOT_SUPP      =0x11,
    NEG12_SUB_FUNC_NOT_SUPP =0x12,
    NEG21_BUSY              =0x21,
    NEG23_NOT_COMPLETE      =0x23,
    NEG22_COND_NOT_CORR     =0x22,
    NEG78_PENDING           =0x78,
    NEG_UNKNOW              =0xFF
} enumNegStatus;

typedef enum _enumKwType
{
    KW_NOT_STD=0,
    KW_STD = 1
} enumKwType;

typedef enum _enumKwFmtType
{
    KW_MANUAL_FMT=0,
    KW_AUTO_FMT = 1
} enumKwFmtType;

#pragma pack(1)
typedef struct _structValItem
{
    uint16 sMin;
    uint16 sMax;
} structValItem;

typedef struct _structTimingP
{
    /*Unit 1 Mili second*/
    /*Interbyte timing of response data*/
    structValItem p1;
    /*InterFrame Timing*/
    structValItem p2;
    /*Iming between Ecu Res to Test Req*/
    structValItem p3;
    /*Interbyte timing of Req data*/
    structValItem p4;
} structTimingP;

typedef struct _structTimingW
{
    /*unit 1ms*/
    /*T Fivebaud to Sync*/
    structValItem w1;
    /*T Sync to Kb1*/
    structValItem w2;
    /*T Kb1 to Kb2*/
    structValItem w3;
    /*T Kb2 to ~Kb2 or
    ~Kb2 to ~Addr5bps*/
    structValItem w4;
    /*T Idle high*/
    structValItem w5;
} structTimingW;
/*
*use to save data request
*/
#define ENABLE_FORCE_CAN_MULTI_REQ		0xEE

typedef void* (*pfunction_ProtPara)(void *pArg);
typedef struct _structRequestBuffer
{

    uint32 iCANReqID;
    uint8 bTgtAddr;
    uint8 bSrcAddr;
    uint8 bHeader;

    /*Use to save other parameter in request*/
    uint8    bReqLen     ;
    uint8   *p_bReqData  ; /*Use in general request*/


    uint8   bCnt;//could be use in some case need counter as TPCAN
    uint8   arrReserve[8];
    uint8   bForceMultiReqCAN;/*Some Vehicle require send multi request
    with len of CAN just is 8 byte as FORD
    Hung Vo added 18 July 2015*/
    pfunction_ProtPara pf_SetProtocolPara;/*Use this function to pass some argument for corelib protocol
                                          such as vpw , pwm filter byte
                                          */
} structRequestBuffer;
#pragma pack()

typedef enum _enumModuleStatus
{
    VALID_RES           =0xAA, /*Valid data in Datalink/Network layer
                        (Note: eNegative response is valid)*/
    ERROR_DATA      =1, /*Data error in Datalink/Network layer, eg:
                            ERROR_SOF,
                            ERROR_PACKAGE,
                            ERROR_CRC,
                            ERROR_TARGET_ADDR,
                            ERROR_SOURCE_ADDR �
                        */
    TIME_OUT        =2, /*Not receiving any data for this response buffer*/
    BUFF_OVERFLOW =3,  /*Receiving buffer is overflow*/
    BUFF_BUSY       =4,/*Waiting for processing , will skip when call function get free buffer*/
    BUFF_LOCKED=5,/*Read Only Buffer , need to reset buffer to enable write data*/

} enumModuleStatus;
/*
* iResBuff=DEFAULT_RESPONSE_ADDR and blAssignAddr is false -> determine data of
* response process will be save in any buffer response that is free !
*/
#define DEFAULT_RESPONSE_ADDR   0xFFFFFFFF
/*minimum of number response buffer is 4
because there are some vehicle or some module have larger 3 part in 1 module
example SRS chrysler has 3 part of 1 srs module: left-righ-center part of srs
and we must use 1 temp buffer to save and transfer or convert data for 3 part above
*/
#define NUM_RES_BUF             4
#define ALL_RES_BUFF            NUM_RES_BUF



typedef struct _structRequestService
{
    uint8 const  *  p_Req;

    enumBufferName  eBuffName;

    uint8          bOffSet;             /*OffSet of raw data will parsed dtc*/

    uint8          DtcFrameSize;        /*Use to split dtc*/

    uint8          eFormatDtc;          /*use to display dtc <0 ,1,2 ... n><dtc status>*/

} structRequestService;
/*
*use to save data response
*/
#pragma pack(1)
typedef struct _structResponseBuffer
{
    uint32  iResAddr;                   /* Addr of response*/
    uint8   bSID;                       /* Service of response*/
    uint8   bPID;                       /* PID of response*/
    uint8   bFrameID;                   /* Frame of response*/
    uint16  sResLen;                    /* Response len data*/

    //uint8   strData[SIZE_OF_DATA_RES];  /* save raw data without SID, PID, Frame,
    //                                       Address, Header byte, and Check Sum.*/

    uint16  sSizeBuff;
    uint8   *pstrData;
    //Info parse Dtc
    enumBufferName eBuffName;           /*Buffer name follow request type*/
    uint8          bRawDtcFrmSize;          /*Format dtc follow request type*/
    uint8          bOffSet;             /*OffSet of raw data will parsed dtc*/
    uint8          bDispDtcFmtSize;     /*Use to split dtc*/

    uint16          sExpectLen;//Use to validate can data

    uint8           bNumFrameRes;/*use to handle multi frame of response of oem service*/
    uint8           Reserves[10];
    enumModuleStatus eStatus;           /*Save status of Link Process*/
} structResponseBuffer;
typedef struct _structSplitFrameCan
{
    uint8 bNumFrm;
    uint8 arrFrame[49];
} structSplitFrameCan;

#pragma pack()

typedef enum _enumFormatHeader
{
    HAS_LEN_BYTE    =0,  /*Len byte is not mixed with header byte*/
    NO_LEN_BYTE     =1,  /*Len byte is mixed with header byte*/
    HEADER_1BYTE_LEN=2,  /*Header with only len byte , don't have header byte
                           just include cmd and cs :          [02 03 05]*/
    HDR_1BYTE_ALL   =3,     /*just include len , cmd and cs : [03 03 06]*/
    HDR_1BYTE_CMD   =4,     /*just cmd :                      [01 03 04]*/

    NONE_HEADER     =7   /*this mode allow user define manual header
                           and manual include checksum or not
                           Response data is original data from ECU
                           do not process any raw data!!!
                           */
} enumFormatHeader;

#pragma pack(1)
#define ENABLE_DETECT_SINGLE_FRAME	3

typedef struct _structProtParKline
{
    /*
    * use to save header format type
    * use in Kline Iso Protocol
    */
    enumFormatHeader eFormatHeader      :3  ;/*Header Link*/
    /*use to save init type of kline*/
    enumInitType     eInitType          :2  ;
    /*
    * use to save header format type
    * use in Kline Iso Protocol
    */
    enumFormatHeader eFormatHeaderInit   :3  ;/*Header Link*/

    enumFormatHeader eFormatDetected     :3  ;/*after query KW will be assign for all process link*/

    uint8   DetectSingleFrame:2;/* ENABLE_DETECT_SINGLE_FRAME : using this feature*/
    uint8 strReserve                     :3  ;
} structProtParKline; /*2Bytes*/
#pragma pack()


/*
*use to define protocol
*/

typedef uint8 enumProtocolSubType;

typedef enum _enumDDL1Status
{
    eDDL1FAIL,//Timeout without response
    eDDL1SUCCESS,//Link successful
    eDDL1ERROR//with error data response
} enumDDL1Status;
#pragma pack(1)
typedef struct _structBitMode
{
    /*use to save parameter for kline protocol*/
    structProtParKline strtProtParKline       ; /*2Bytes*/
    /*true  : Push data to prior addr assigned
      false : push data to free buffer (iResAddr == 0xFFFFFFFF)
    */
    enumbool AddrAssigned                   ;
    enumbool blAutoFmt                      ;/*Flag allow autodetect format when initialize*/
    enumbool blKwStandard                   ;/*TRUE : -> Auto assign in kw mode Cx with Addr 33
                                                 FALSE: -> Cx or 8x base on Header*/
    enumProtocolSubType eProtocolSubType    ;
    enumProtocol eProcotocol                ;
    enumProtocol eProtocolDetected;
} structBitMode;
#pragma pack()

#pragma pack(1)
typedef struct _structTimingWakeUp
{
    /*Unit timing is mili second*/
    /*T idle High*/
    uint16 sTIdle;
    /*T Wakup low*/
    uint16 sTInil;
    /*T Wakup high*/
    uint16 sTWup;
} structTimingWakeUp, *pstructTimingWakeUp;
/*+-------_____________--------+     High
  + TIdle+     TInil   +             Low
         +            Twup     +
*/
#pragma pack()

#pragma pack(1)

typedef struct _structKw1281Timing
{
    /*Unit 1ms*/
    /*T tr_6*/
    uint32 T_Tester2Ecu;
    /*T tr_7*/
    uint32 T_Ecu2Tester;
    /*T t_rb*/
    uint32 T_BlTimeOut ;
} structKw1281Timing;
#pragma pack()

#pragma pack(1)
typedef struct _structCanAddrFilter
{
    /*
    *use to set range filter address
    */
    /*Start filter addr*/
    uint32       iRxAddrStart;
    /*End Filter addr*/
    uint32       iRxAddrEnd;
    /*Set Range 2*/
    uint32       iRxAddrStart2;
    uint32       iRxAddrEnd2;
} structCanAddrFilter;
#pragma pack()

typedef enum _enumMuxNo
{
    _MUX1,
    _MUX2,
    _MUX_NA
} enumMuxNo;
typedef enum _enumDLCType
{
    DLC_RX,
    DLC_TX,
    DLC_INIT
} enumDLCType;
typedef enum _enumUserUart
{
    USER_UART1,
    USER_UART2,
    USER_UART3,
    USER_UART4,
    USER_UART5,
    USER_UART6,
    USER_USART_UNKNOWN
} enumUserUart;

#pragma pack(1)

typedef struct _structDLCProfile
{
    enumDLCPinName   eDlCPinName;  /*User permission : Write/Read */
    enumVoltageLevel eVolLevel;    /*User permission : Write/Read */
    enumPUReLap Dangor    eReLap Dangor;
    enumUserUart     eUserUart;    /*User permission : Read only  */
    enumMuxNo        eMuxNo;

    enumDLCType      eDLCType;
    enumPDReLap Dangor    ePDResistor;
} structDLCProfile;
typedef struct _structDLCName
{
    enumDLCPinName   eDlCPinName;  /*User permission : Write/Read */
    enumVoltageLevel eVolLevel;    /*User permission : Write/Read */
    enumPUReLap Dangor    eReLap Dangor;
}structDLCName;
#pragma pack()


#pragma pack(1)
typedef struct _structKlineInitParameter
{
    /*Key word in Five bauds process*/
    uint16       sKeyWord;
    union
    {
        /*System check code in MUT protocol*/
        uint16  sSysCode;
        /*Block title use in KW1281 Protocol*/
        uint8   bBlockCnt;
    };
    /*Use in five bauds init*/
    uint8            bAddr5bps;
    structDLCProfile strtDLCRx;
    structDLCProfile strtDLCTx;
    structDLCProfile strtDLCInit;
    uint32           iUserOpt;     /*Use in some special option of protocol
                                     ex: mode dlc in field GM_ABS_Protocol x
                                   */
    enumUartDataType eUartDataType;
    enumCheckSumType eCheckSumType;
    uint8 bPoly;
    structValItem p2_Detected;
    enumDLCPinName   eDlcRxSave;//Use to tracking ignition pin function Read Only
    structDLCProfile strtDLCPinRx_Save;//Use to reset dlc pin voltage
    structDLCProfile strtDLCPinTx_Save;//Use to reset dlc pin voltage
    structDLCProfile strtDLCPinInit_Save;//Use to reset dlc pin voltage
} structKlineInitParameter;

typedef struct _structCanInitInfo
{
    structDLCProfile strtDLCCanH;
    structDLCProfile strtDLCCanL;
} structCanInitInfo;
#pragma pack()



#define __Kline_Hw(a,av,b,bv,c,cv)  p_strtLinkProfile->strtKlineInitParam.strtDLCTx.eDlCPinName  = a;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCTx.eVolLevel    = av;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCRx.eDlCPinName  = b;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCRx.eVolLevel    = bv;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCInit.eDlCPinName= c;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCInit.eVolLevel  = cv

#define __Kline_ReLap Dangor(ar,br,cr)   p_strtLinkProfile->strtKlineInitParam.strtDLCTx.eReLap Dangor=ar;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCRx.eReLap Dangor=br;\
    p_strtLinkProfile->strtKlineInitParam.strtDLCInit.eReLap Dangor=cr





#define FIFO_CAN_SIZE                   50

#define MAX_DATA_LEN                    8
#pragma pack(1)
typedef struct _structCanRx
{
    uint32 iAddr;
    uint8  bLen;
    uint8  Data[MAX_DATA_LEN];
} structCanRx,structCanTx;
#pragma pack()

typedef enum _enumCanMesgType
{
    SINGLE_FRAME        = 0,
    FIRST_FRAME         = 1,
    CONSECUTIVE_FRAME   = 2,
    ERROR_FRAME
} enumCanMesgType;

#pragma pack(1)

typedef struct _structCanFiFo
{
    uint8       bIdxRead;
    uint8       bIdxWrite;
    enumbool    blOverFlow;
    structCanRx strtCanRx[FIFO_CAN_SIZE];
} structCanFiFo;

#define REQUEST_MESSAGE_BUF_SIZE                    12/*J1850 protocol*/
#define J1850_Header_Size                           2
#define HeaderOffSetAddr                            J1850_Header_Size
#define Max_Len_Data_J1850                          9
/*
*use this format to determine 1 frame J1850
*/
typedef struct _structJ1850Frame
{
    union
    {
        struct
        {
            /*Header of frame J1850*/
            uint8 Header[J1850_Header_Size];
            uint8 Addr;
            /*Data Request of J1850*/
            uint8 Data[Max_Len_Data_J1850];
        };
        uint8 DataFrame[REQUEST_MESSAGE_BUF_SIZE];
    };
} structJ1850Frame;

#pragma pack()
typedef enum _enumSystemStatus
{
    SYSTEM_NORMAL   =0,/*system normal*/
    ERROR_VECU      =1,/*Error : link vehicle without Ecu Voltage*/
    ERROR_VBUS      =2,/*Error or No Error depend on user define*/
    USER_BREAK      =3,/*Depending on user define*/
	ERROR_CONNECTOR =4
} enumSystemStatus;

typedef enumSystemStatus (*fCheckBreakFunc)(void);


typedef void (*fFuncQueryInfo)(const void * strtVehDB,uint8 b_Total,uint8 b_Present);

#define MAX_LEN_DTC_ASCII       20 /*Hung Vo increase to 20 cover all parse dtc string*/
typedef struct _structDtcParser
{
    /*P123456-003*/
    enumDTCType  eDTCType;
    uint8        bFrameDtc;
    uint8    *   pDtc;//Raw buffer dtc
    uint8        arrDtcOutPut[MAX_LEN_DTC_ASCII];
    uint8        bTypeParserBuffName;
} structDtcParser;
typedef enum _enumSWCanMode
{
    SWCan_Sleep,
    SWCan_HSMode,
    SWCan_WakeUp,
    SWCan_Normal,
} enumSWCanMode;
typedef struct _structNwScanProgress
{
    uint8 bTotal;
    uint8 bPresent;
} structNwScanProgress;

typedef struct _structLinkProfile
{
    /*this struct is save special parameter of each protocol*/
    structBitMode                   strtMode;
    //enumMarket                      eMarket;
    /*use to assign baudrate (unit : <Kline-bps >  <Can-Kbps>)*/
    uint32                          iBaudrate;
    /*
    *use to save range filter addr for Can
    *or use to save some special parameter of kline process
    */
    /*Use in Can Protocol*/
    structCanAddrFilter         strtCanAddrFilter;
    /*use in Kline Protocol*/
    structKlineInitParameter    strtKlineInitParam;
    structCanInitInfo           strtCanInitInfo;
    enumProtocol                eMuxProtocol;//Use for Mux protocol

    /*Use to save timing of protocol*/
    ///*Use in Kw1281 Protocol*/
    structKw1281Timing          *pstrtKw1281Timing;
    /*Use in general Protocol*/
    structTimingP               *pstrtTimingP;
    /*use to save timing W in Init process Kline*/
    const structTimingW               *   pstrtTimingW;
    /*use to point to timing TWup in wakup process Kline*/
    const structTimingWakeUp    *   pstrtTWup;

    /*use to save data request*/
    structRequestBuffer             strtReqBuf;
    /*use to save data response after link process*/

    structResponseBuffer            strtResBuf [NUM_RES_BUF];

    fFuncQueryInfo pf_DisplayQueryInfo;
    /*
    *user can define specific function to check break condition
    *example : check error power -> break link -> return result error vecu
    *.....
    */
    fCheckBreakFunc pf_CheckBreakCondition;
    /*
    *user can define specific function to flash link icon even
    *example on-off led or linkicon....
    */
    fFunction pf_FlashLinkIcon ;

    void *               pCanBase; //Use in local CAN protocol
    structCanFiFo        strtCanFiFo;

    structDtcParser strtDtcParser;//Present dtc format used in function parser
    structNwScanProgress strtNwScanProgress;
    void *pUserData;/*be used depend on any purpose as :
                     timing of kw1281 , .....*/

    void (*pDBLogReq)(struct _structLinkProfile *pstrtLinkProfile);
    void (*pDBLogRes)(struct _structLinkProfile *pstrtLinkProfile);

    uint8 (*pDBSetOffSetOfResp)(struct _structLinkProfile *pstrtLinkProfile);
} structLinkProfile;
#pragma pack()


#define DEBUG_LOG_REQ(a)       gf_SYS_DBLogReqData(a)
#define DEBUG_LOG_RES(a)       gf_SYS_DBLogResData(a)

#define SIZE_OF_DATA_RES        p_strtLinkProfile->strtResBuf.sSizeBuff
typedef struct _structAddrTable
{
    uint32 iReq;
    uint32 iRes;
} structAddrTable;

/*Useful macro*/
typedef enumSystemStatus(*pfunction)(structLinkProfile * p_strtLinkProfile);
typedef enumProtocol (*pfGetProtocol)(structLinkProfile * p_strtLinkProfile);
typedef void (*pfLink)(structLinkProfile * p_strtLinkProfile);
typedef void (*fProBar)(uint16 sParameter);
typedef enum _enumQueryPrcSt
{
    QUERY_NORMAL          =0,/*system normal*/
    QUERY_ERROR_VECU      =1,/*Error : link vehicle without Ecu Voltage*/
    QUERY_ERROR_VBUS      =2,/*Error or No Error depend on user define*/
    QUERY_USER_BREAK      =3,/*Depending on user define*/
	QUERY_NOTSUPPORTED	=4
} enumQueryPrcSt;

typedef enum _enumLinkPrcSt
{
    LINK_NORMAL          =0,/*system normal*/
    LINK_ERROR_VECU      =1,/*Error : link vehicle without Ecu Voltage*/
    LINK_ERROR_VBUS      =2,/*Error or No Error depend on user define*/
    LINK_USER_BREAK      =3,/*Depending on user define*/
	LINK_NOTSUPPORTED	=4
} enumLinkPrcSt;

typedef enumQueryPrcSt(*pfunction_Query)(structLinkProfile * p_strtLinkProfile);
typedef enum _enumErasePrcSt
{

        eERASE_SUCCESS=1,
        eERASE_FAIL,
        eERASE_NOTSUPPORT,
        eERASE_ERROR_VECU,
        eERASE_USER_BREAK,
} enumErasePrcSt;
typedef enumErasePrcSt(*pfunction_Erase)(structLinkProfile * p_strtLinkProfile);

typedef enum _enumExitPrcSt
{
    EXIT_NORMAL         =0,/*system normal*/
    EXIT_ERROR_VECU      =1,/*Error : link vehicle without Ecu Voltage*/
    EXIT_ERROR_VBUS      =2,/*Error or No Error depend on user define*/
    EXIT_USER_BREAK      =3,/*Depending on user define*/
	EXIT_NOTSUPPORTED	=4
} enumExitPrcSt;
typedef enumExitPrcSt(*pfunction_Exit)(structLinkProfile * p_strtLinkProfile);

typedef enum _enumKeepAlivePrcSt
{
    K_ALIVE_NORMAL          =0,/*system normal*/
    K_ALIVE_ERROR_VECU      =1,/*Error : link vehicle without Ecu Voltage*/
    K_ALIVE_ERROR_VBUS      =2,/*Error or No Error depend on user define*/
    K_ALIVE_USER_BREAK      =3,/*Depending on user define*/
	K_ALIVE_NOTSUPPORTED	=4
} enumKeepAlivePrcSt;

typedef enumKeepAlivePrcSt(*pfunction_KeepAlive)(structLinkProfile * p_strtLinkProfile);

typedef enum _enumEcuInfoPrcSt
{
    ECUINFO_NORMAL         =0,/*system normal*/
    ECUINFO_ERROR_VECU      =1,/*Error : link vehicle without Ecu Voltage*/
    ECUINFO_ERROR_VBUS      =2,/*Error or No Error depend on user define*/
    ECUINFO_USER_BREAK      =3,/*Depending on user define*/
	ECUINFO_NOTSUPPORTED	=4
} enumEcuInfoPrcSt;
typedef enumEcuInfoPrcSt(*pfunction_EcuInfo)(structLinkProfile * p_strtLinkProfile);

typedef struct _structLinkProcess
{
    /*Use to assign Protocol*/
    enumProtocol            eProt;
    /*use to classify same protocol , but use difference query,link...*/
    enumProtocolSubType     eProtSubType;
    /*Use to assign implement function for above protocol*/
    pfunction_Query         pf_Query;
    pfunction               pf_Link;
    pfunction_Erase         pf_Erase;
    pfunction_KeepAlive     pf_KeepAlive;
    pfunction_Exit          pf_Exit;
    pfunction_EcuInfo       pf_EcuInfo;
} structLinkProcess;

typedef void(*pfunctionLinkProcess)(structLinkProcess * p_strtLinkProcess,structLinkProfile * p_strtLinkProfile);

typedef struct _structLinkProcessNew
{
    /*Use to assign Protocol*/
    enumProtocol            eProt;
    /*use to classify same protocol , but use difference query,link...*/
    enumProtocolSubType     eProtSubType;
    /*Use to assign implement function for above protocol*/
    pfunction_Query         pf_Query;
    pfunction               pf_Link;
    pfunction_Erase         pf_Erase;
    pfunction_KeepAlive     pf_KeepAlive;
    pfunction_Exit          pf_Exit;
    enumDTCType             eDTCType;
} structLinkProcessNew;

typedef void(*pfunctionLinkProcessNew)(structLinkProcessNew * p_strtLinkProcess,structLinkProfile * p_strtLinkProfile);

/*Use this struct for Global OBDII Process*/
typedef struct _structFuncBasicProtocol
{
    /*Use to assign Protocol*/
    enumProtocol    eProt;
    /*Use to assign implement function for above protocol*/
    pfLink       pfunc;
} structFuncBasicProtocol;


typedef enum _enumOBD1Mode
{
    PROTOCOL_OBD1_GND,
    PROTOCOL_OBD1_3K9,
    PROTOCOL_OBD1_10K,
    OBD1_MODE_OPEN
} enumOBD1Mode;
typedef float(*pfGetEcuVoltage)(void);

/*
 * ECU ID for Honda
 * */
#define HONDA_BOSH_MAX_LEN_TT   12
#define HONDA_BOSH_MAX_LEN_BB   8
#define HONDA_ECU_ID_LEN        (HONDA_BOSH_MAX_LEN_TT+HONDA_BOSH_MAX_LEN_BB)
#pragma pack(1)
typedef struct _structHondaBoshEcuInfo
{
  uint8 strEcuID_TT[HONDA_BOSH_MAX_LEN_TT];  /*ECU ID (Control unit identification) : TT (TT number)*/
  uint8 strpSoftID_BB[HONDA_BOSH_MAX_LEN_BB]; /*ID (Software identification) : BB (BB number)*/
}structHondaBoshEcuInfo;
#pragma pack()

/*
 * End Of Honda
 * */
/******************************************************************************/
#ifdef _PROTOCOL_UTILITY_C
/******************************************************************************/
/*
*define for basic general timing Wakeup , P, W
*/
const structTimingWakeUp g_strtTwupGeneral       = {300,25,50};
const structTimingP      g_strtTimingP_Normal    = {{0,20},{25,100},{55,5000},{5,20}};/*unit ms*/
const structTimingW      g_strtTimingW_Normal    = {{60,1270},{5,20},{0,20},{25,50},{300,1000}}; /*unit ms*/
const structKw1281Timing g_strtKw1281Default       = {5,100,1200};
#else
extern const structTimingWakeUp g_strtTwupGeneral;
extern const structTimingP      g_strtTimingP_Normal ;
extern const structTimingW      g_strtTimingW_Normal;
extern const structKw1281Timing g_strtKw1281Default;
#endif /*_PROTOCOL_UTILITY_C*/

/*******************************************
*Get Prototype function
*Version :  V1.0.0
*Author : Lap Dang
******************************************"*/
/*Local Function*/
/*Global Function*/
uint8 gf_VBI_Profile_CalCS(unsigned char * pStartBuffer, unsigned char bNumberData);
uint16 gf_VBI_Profile_CalcCS2Byte(unsigned char * pStartBuffer, unsigned char bNumberData);
uint8 gf_VBI_Profile_CalcCSInv(unsigned char * pStartBuffer, unsigned char bNumberData);
structResponseBuffer * gf_VBI_Resp_OfAddr(structLinkProfile * p_strtLinkProfile, uint32 iAddr);
void gf_VBI_Profile_LoadReq(structLinkProfile * p_strtLinkProfile,uint8 const * parrReq);
void SetKlineHeaderType(structLinkProfile * p_strtLinkProfile, enumFormatHeader eHeaderLink,enumFormatHeader eHeaderInit);
void SetKlineLinkType(structLinkProfile * p_strtLinkProfile,enumKwType eKwType,enumKwFmtType eKwFmtType);
void SetFormatHeader(structLinkProfile * p_strtLinkProfile, uint8 bHeader,uint8 bTagAddr,uint8 bSrcAddr);
void SetKlineDataFormat(structLinkProfile * p_strtLinkProfile, uint32 iBaudRate,enumUartDataType eUartDataType);
void gf_VBI_Profile_SetCS(structLinkProfile * p_strtLinkProfile,enumCheckSumType eCS,uint8 bPoly);
uint8 gf_VBI_Profile_CalCrc(unsigned char * pStartBuffer, unsigned char bNumberData,uint8 Poly);
uint8 gf_VBI_Profile_CalCS(unsigned char * pStartBuffer, unsigned char bNumberData);
uint16 gf_VBI_Profile_CalcCS2Byte(unsigned char * pStartBuffer, unsigned char bNumberData);
uint8 gf_VBI_Profile_CalcCSInv(unsigned char * pStartBuffer, unsigned char bNumberData);
uint8 gf_VBI_OBD2_SID_OffSet(uint8 bSID,uint8 * pDataReq,structLinkProfile * p_strtLinkProfile);
structResponseBuffer * gf_VBI_Resp_OfAddr(structLinkProfile * p_strtLinkProfile, uint32 iAddr);
enumNegStatus gf_VBI_Resp_NegativeHandler(uint8 * Data);
enumbool gf_VBI_Resp_x_IsPoLap Dangive(structLinkProfile * p_strtLinkProfile,uint8 bNoBuff);
enumbool gf_VBI_Resp_IsPoLap Dangive(structLinkProfile * p_strtLinkProfile);
void gf_VBI_Resp_RemoveNegative(structLinkProfile * p_strtLinkProfile);
void gf_VBI_Resp_ResetAll(structLinkProfile * p_strtLinkProfile);
void gf_VBI_Resp_x_ResetAll(structLinkProfile * p_strtLinkProfile,uint8 bIdxBuff);
void gf_VBI_Profile_LoadReq(structLinkProfile * p_strtLinkProfile,uint8 const * parrReq);
enumbool gf_VBI_Resp_IsValid(structLinkProfile * p_strtLinkProfile);
enumModuleStatus gf_VBI_Resp_x_GetState(structLinkProfile * p_strtLinkProfile,uint8 bBuffNo);
void SetKlineLinkType(structLinkProfile * p_strtLinkProfile,enumKwType eKwType,enumKwFmtType eKwFmtType);
sint8 gf_VBI_Resp_OfDtcType(structLinkProfile * p_strtLinkProfile,uint8 eFormatDtc);
void gf_VBI_Profile_SetCS(structLinkProfile * p_strtLinkProfile,enumCheckSumType eCS,uint8 bPoly);
uint8 gf_VBI_Profile_CalCrc(unsigned char * pStartBuffer, unsigned char bNumberData,uint8 Poly);
enumSystemStatus gf_SYS_CheckBreakCondition(structLinkProfile * p_strtLinkProfile);
void gf_SYS_FlashLinkIcon(structLinkProfile * p_strtLinkProfile);
void gf_SYS_DBLogReqData(structLinkProfile * p_strtLinkProfile);
void gf_SYS_DBLogResData(structLinkProfile * p_strtLinkProfile);
void gf_VBI_OBD2FrameParseData(structLinkProfile * p_strtLinkProfile);

structResponseBuffer * gf_VBI_Resp_OfIdx(structLinkProfile * p_strtLinkProfile,uint8 sbIdx);
enumbool gf_VBI_Resp_IdxCopy_x_y(structLinkProfile * p_strtLinkProfile,uint8 srcidx,uint8 btgidx);
enumbool gf_VBI_Resp_Copy_x_y(structResponseBuffer * BuffTgt,structResponseBuffer * Buffsrc);
uint8 gf_VBI_Resp_GetNumValid(structLinkProfile * p_strtLinkProfile);
enumbool gf_VBI_IsOBD2Mode(structLinkProfile * p_strtLinkProfile);

sint8 gf_VBI_IdxOfResp(structLinkProfile * p_strtLinkProfile,structResponseBuffer * pstrtResponseBuffer);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_Resp_GetMaxSizeOfAllRespData
*Input        : structLinkProfile * p_strtLinkProfile
*Output       : uint16
*Description  :
*get max len of buffer store response data
*use this function to merge all response buffer to 1 buffer
*since some case , have large response buffer of physical
*
*Historical   :
*     1. Creation Lap Dang Sep 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
uint16 gf_VBI_Resp_GetMaxSizeOfAllRespData(structLinkProfile * p_strtLinkProfile);

sint8 gf_VBI_Resp_GetFreeBuffIdx(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_RespStrt_IsValid
*Input        : structResponseBuffer * pstrtRespBuff
*Output       : enumbool , eTRUE: VALID , eFALSE : Invalid
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 8, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VBI_RespStrt_IsValid(structResponseBuffer * pstrtRespBuff);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_SYS_DisplayQueryInfo
*Input        : display info of current vehicle db
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 12, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_SYS_DisplayQueryInfo(structLinkProfile * p_strtLinkProfile,void *pstrtVehDB);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_LinkProfileLoadRestoreLinkType
*Input        : structLinkProfile * p_strtLinkProfile
*Output       :
*Description  :
*eFormatHeader=eFormatDetected
*
*
*Historical   :
*     1. Creation Lap Dang Oct 9, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VBI_LinkProfileLoadRestoreLinkType(structLinkProfile * p_strtLinkProfile);

structResponseBuffer * gf_VBI_Resp_GetFreeBuffer(structLinkProfile * p_strtLinkProfile);


void gf_VBI_Resp_X_ReleaseLock(structLinkProfile *p_strtLinkProfile,
        sint8 sbIdx);

void gf_VBI_Resp_ReleaseLock(structLinkProfile *p_strtLinkProfile);

void gf_VBI_StrtResp_SetLock(structResponseBuffer *pResBuff);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VBI_CAN_Set_Force_MultiRequest(structLinkProfile *p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *set force multi request for CAN even with message has len <=8 , ex : special case for FORD CAN
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  11:02:18 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VBI_CAN_Set_Force_MultiRequest(structLinkProfile *p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VBI_KW_EnableDetectSingleFrame(structLinkProfile *p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *enable dectected single frame to speed up performance kline protocol
 *auto reset if any called function kline
 *
 *Historical   :
 *     1. Creation Lap Dang  2:18:35 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VBI_KW_EnableDetectSingleFrame(structLinkProfile *p_strtLinkProfile);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VBI_KW_ResetDetectSingleFrame(structLinkProfile *p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *enable dectected single frame to speed up performance kline protocol
 *auto reset if any called function kline
 *
 *Historical   :
 *     1. Creation Lap Dang  2:18:35 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VBI_KW_ResetDetectSingleFrame(structLinkProfile *p_strtLinkProfile);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumbool gf_VBI_KW_IsEnableDetectedSingleFrame(structLinkProfile *p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  2:21:39 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VBI_KW_IsEnableDetectedSingleFrame(structLinkProfile *p_strtLinkProfile);
#endif/*_PROTOCOL_UTILITY_H*/
