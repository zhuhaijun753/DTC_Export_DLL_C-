/******************************************************************************
 ===============================================================================
                         Lap Dang Dev
 * Filename : VCI_App.h
 * Description:
 
 *  Created on: Lap Dang  Oct 18, 2014
 *
 *  Version         : V01.00.00
===============================================================================
******************************************************************************/

#ifndef VCI_APP_H_
#define VCI_APP_H_

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Historical   : 20July2010
*Function name: gf_VCI_DWCan_Link
*Description  :
*Input        : p_strtLinkProfile
*Output       : enumSystemStatus
-------------------------------------------------------------------------------*/
void gf_VCI_SWCan_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_DWCan_Link
*Input        : structLinkProfile * p_strtCANProfile
*Output       :
*Description  :
*if SID belong to OBD2 1,2,3,4,5,6,7,8,9,A -> Parser str data base on offset of J1979
*
*
*
*
*Historical   :
*     1. Creation Lap Dang Aug 2, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_DWCan_Link(structLinkProfile * p_strtLinkProfile);


/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 10Apr2010
*Function name  : PWM_Link
*Description    : handle PWM processing
*Input: none
*Output:none
-----------------------------------------------------------------------------*/
void PWM_Link (structLinkProfile * p_strtLinkProfile);

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang,Lap Dang
*Date           : 10Apr2010
*Function name  : VPW_Link
*Description    : handle VPW processing
*Input: none
*Output:none
-----------------------------------------------------------------------------*/
void VPW_Link (structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
Engineer               : Nguyen Thi Hoa Cuc , Lap Dang modified 31July2010
Historical             : 1.May 252010 Create
Function Name          : ISO9141_Link
Description            : Link to ECU with request buffer in p_strtLinkProfile
                         and receive responses in accordance with ISO9141
Input                  : 1.p_strtLinkProfile     the struct that contains response buffers
Output                 : None
------------------------------------------------------------------------------*/
void ISO9141_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
Engineer               : Lap Dang
Historical             : 06 July 2011
Function Name          : ISO_Link
Description            : Link to ECU with request buffer in p_strtLinkProfile
                         and receive responses in accordance with ISO9141
Input                  : 1.p_strtLinkProfile     the struct that contains response buffers
Output                 : None
------------------------------------------------------------------------------*/
void ISO_Link(structLinkProfile * p_strtLinkProfile);



/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 20July2010
*Function name  : InitProfileFordAbsIso
*Description    :
*Input          : p_strtLinkProfile
*Output         : none
-----------------------------------------------------------------------------*/
enumProtocol FiveBauds_Link(structLinkProfile * p_strtLinkProfile,uint8 bNumRetry,
                            enumProtocol (*fHandleKwInit)(structLinkProfile * p_strtLinkProfile));



/*------------------------------------------------------------------------------
Engineer:   Lap Dang
Date :31 July 2010
Function Name:  Kw_Link
Description:    link kw
Input:      1.p_strtLinkProfile
Output:     none
------------------------------------------------------------------------------*/
void Kw_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
Engineer:   Lap Dang
Historical: 24 July 2010
Function Name:  SendWakeUp
Description:    send wakeup +-------_____________--------+     High
                            + TIdle+     TInil   +             Low
                                   +            Twup     +
Input:      pstrtTWkUp
Output:     None
------------------------------------------------------------------------------*/
void SendWakeUp(structLinkProfile * p_strtLinkProfile);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_KW1281_ProfileInit
*Input        : structLinkProfile * p_strtLinkProfile,
                               enumDLCPinName eKrx,enumDLCPinName eKtx,
                               enumDLCPinName dlcinit,
                               uint8 bFBAddr
*Output       :void
*Description  : init hardware dlc pins and fivebaud address
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 5, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_KW1281_ProfileInit(structLinkProfile * p_strtLinkProfile,
                               enumDLCPinName eKrx,enumDLCPinName eKtx,
                               enumDLCPinName dlcinit,
                               uint8 bFBAddr);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_Kw1281_Init
*Input        : structLinkProfile * p_strtLinkProfile
*Input        enumbool IsFullFrame = eTRUE , keep raw data of kw1281
*Output       : structResponseBuffer *
*Description  :
* use to init fivebaud and retrieve ecu id
*
*
*Historical   :
*     1. Creation Lap Dang Sep 5, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_Kw1281_Init(structLinkProfile * p_strtLinkProfile,enumbool IsFullFrame);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_Kw1281_Link
*Input        : structLinkProfile * p_strtLinkProfile
                enumbool IsEnableReinit
*Output       : structResponseBuffer *
*Description  :

    >  gf_VBI_Resp_ResetAll(p_strtLinkProfile); //Clear all response buffer before linking
    uint8 cmd_1281_07[]={4,3,0,7,3};//read dtc
    gf_VBI_Profile_LoadReq(p_strtLinkProfile,cmd_1281_07);
    > Load command 03 [cnt] [title] 03

    if result = null or status != VALID_RES : Fail
    else    successful
*
*Historical   :
*     1. Creation Lap Dang Sep 5, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_Kw1281_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
Engineer:   Lap Dang
Historical: 17 Dec 2010
Function Name:  KW2000_Link
Description:    Link to ECU with request buffer in p_strtLinkProfile
                and receive responses in accordance with KW2000
Input:      1.p_strtLinkProfile     the struct that contains response buffers
Output:     None
------------------------------------------------------------------------------*/
void KW2000_Link(structLinkProfile * p_strtLinkProfile);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_KWFB_Init
*Input        : structLinkProfile * p_strtLinkProfile
*Output       : enumbool - eTRUE : OK , eFALSE : fail
*Description  :
*fast init with service 81
*
*
*Historical   :
*     1. Creation Lap Dang Sep 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VCI_KWFB_Init(structLinkProfile * p_strtLinkProfile);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_KWFBLink
*Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking
*Output       : structResponseBuffer *
     1.Equal null -> Fail
     2.Not equal null -> check status  , Successfu
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_KWFBLink(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_MBIso_Init
*Input        : structLinkProfile * p_strtLinkProfile uint8 bNumRetryFB
*Output       : structResponseBuffer *
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
structResponseBuffer * gf_VCI_MBIso_Init(structLinkProfile * p_strtLinkProfile,uint8 bNumRetryFB);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_MBIso_Link
*Input        : structLinkProfile * p_strtLinkProfile pRom_Req pCmdLink,enumbool IsAutoInitFB
*Output       : structResponseBuffer *
*Description  :
*link cmd x with format of MBISO
*
*
*Historical   :
*     1. Creation Lap Dang Sep 8, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_MBIso_Link(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLink,enumbool IsAutoInitFB);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_MBIso_EcuInfoParser
*Input        : structResponseBuffer * pstrtResponseBuffer
*Output       :
*Description  :
*will parse ecu info as format of structOemInfo_Mercedes
*
*
*Historical   :
*     1. Creation Lap Dang Sep 8, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_MBIso_EcuInfoParser(structResponseBuffer * pstrtResponseBuffer);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_MUT_Init
*Input        : structLinkProfile * p_strtLinkProfile,uint8 bNumRetryFB
*Output       : structResponseBuffer *
*Description  :
* data will contain system check code
* (could be reference in p_strtLinkProfile->strtKlineInitParam.sSysCode)
*
*Historical   :
*     1. Creation Lap Dang Sep 8, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_MUT_Init(structLinkProfile * p_strtLinkProfile,uint8 bNumRetryFB);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_MUT_Link
*Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLink,enumbool IsAutoInitFB
*Output       : structResponseBuffer *
*Description  :
*pCmdLink contain list cmd 1 byte of MUT
*Ex : Read dtc 3,4,5 -> pCmdLink={3,3,4,5}
*if any single command fail , it will assign data 00 , one in this list command ok  , buffer response will valid
*Historical   :
*     1. Creation Lap Dang Sep 8, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_MUT_Link(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLink,enumbool IsAutoInitFB);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_ChryslerSCILink
*Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking
*Output       : structResponseBuffer *
*Description  :
* send data using none header mode
*
*
*Historical   :
*     1. Creation Lap Dang Oct 7, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_ChryslerSCILink(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_GM_DWCan_Link
*Input        : structLinkProfile * p_strtCANProfile
*Output       :
*Description  :
*Keep raw data of response
00000243 04 03 A9 81 18 00 00 3F FF
00000543 08 81 40 35 00 BF 00 00 00
00000543 08 81 40 45 00 BF 00 00 00
00000543 08 81 40 50 00 BF 00 00 00
00000543 08 81 45 50 00 BF 00 00 00
00000543 08 81 41 10 04 BF 00 00 00
00000543 08 81 C1 40 00 7F 00 00 00
00000543 08 81 00 00 00 FF 00 00 00
*
*
*
*
*Historical   :
*     1. Creation Lap Dang Aug 2, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_GM_DWCan_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_GMAldlInitProfile
*Input        : structLinkProfile * p_strtLinkProfile,
                enumDLCPinName eKrx,
                enumDLCPinName eKtx,
                uint32 iBaud
                bHdr
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_GMAldlInitProfile(structLinkProfile * p_strtLinkProfile,enumDLCPinName eKrx, enumDLCPinName eKtx, uint32 iBaud,uint8 bHdr);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_GMAldlLink
*Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking
*Output       : structResponseBuffer *
*Description  :
* Null or ! VALID_RES : Fail
* VALID_RES : Successful
*
*Historical   :
*     1. Creation Lap Dang Sep 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_GMAldlLink(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_Honda9XInit
*Input        : structLinkProfile * p_strtLinkProfile
                enumDLCPinName eKrx
                enumDLCPinName eKtx
                uint32 iBaud
                uint8 bFBAddr
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 4, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_Honda9XInit(structLinkProfile * p_strtLinkProfile,
        enumDLCPinName eKrx, enumDLCPinName eKtx, uint32 iBaud, uint8 bFBAddr);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VCI_Honda9X
 *Input        : structLinkProfile * p_strtLinkProfile,
 pRom_Req pCmdWakeUp,
 pRom_Req pCmdLinking
 *Output       :structResponseBuffer *
 1.Equal null -> Fail
 2.Not equal null -> check status  , Successful
 *Description  :
 * pCmdWakeUp ,pCmdLinking not use if equal Null
 * must call function gf_VCI_Honda9XInit before use this function
 * timing will use default of HOnda
 *Historical   :
 *     1. Creation Lap Dang Aug 29, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_Honda9X(structLinkProfile * p_strtLinkProfile,
                                        pRom_Req pCmdWakeUp,
                                        pRom_Req pCmdLinking);

                                        /*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_HondaBosh_InitFB
*Input        : structLinkProfile * p_strtLinkProfile
                structHondaBoshEcuInfo *pstrtHondaBoshEcuInfo
*Output       : eTRUE : OK , eFALSE : Fail
*Description  : this struct will contain ecu id and soft id of link ecu
*
*
*
*Historical   :
*     1. Creation Lap Dang Sep 5, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VCI_HondaBosh_InitFB(structLinkProfile * p_strtLinkProfile,structHondaBoshEcuInfo *pstrtHondaBoshEcuInfo);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_HondaBosh_Link
*Input        : structLinkProfile * p_strtLinkProfile,
                pRom_Req pCmd,
                enumbool IsAutoInit
*Output       : structResponseBuffer *
*Description  :
*IsAutoInit=eTRUE : enable auto init if link fail
*
*
*Historical   :
*     1. Creation Lap Dang Sep 5, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_HondaBosh_Link(structLinkProfile * p_strtLinkProfile,
                                             pRom_Req pCmd,
                                             enumbool IsAutoInit);

void gf_VCI_Honda99Init(structLinkProfile * p_strtLinkProfile,
                        enumDLCPinName eKrx,
                        enumDLCPinName eKtx,
                        uint32 iBaud,
                        uint8 bFBAddr);


void gf_VCI_Honda99Parser(structResponseBuffer *pstrtResponseBuffer);

structResponseBuffer * gf_VCI_Honda99B(structLinkProfile * p_strtLinkProfile,
                                       pRom_Req pCmdWakeUp,
                                       pRom_Req pCmdLinking);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:
*Input        :

*Output       :
*Description  :
*example
*   uint32 iCANReqID=0x750;
    uint8  bTgtAddr =0xDD;
*   [750] [08]<DD> 01 3E 00 00 00 00 00
*   [758] [08]<DD> 01 7E 00 00 00 00 00
*Historical   :
*     1. Creation Lap Dang Aug 26, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_ToyotaCanSubAddr(structLinkProfile * p_strtLinkProfile);


void gf_VBI_ProtocolStdLink(structLinkProfile  *p_strtLinkProfile,
                            enumProtocol eProtocol,
                            Rom_Req *pCmdLink,
                            Rom_Req *pCmdReInit,
                            Rom_Req *pCmdKeepAlive);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_ChryslerCCD2Link
*Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking
*Output       : structResponseBuffer *
*Description  :
* send data using none header mode
*
*
*Historical   :
*     1. Creation Lap Dang Oct 7, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_ChryslerCCD2Link(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_ChryslerCCDLink
*Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking
*Output       : structResponseBuffer *
*Description  :
* send data using none header mode
*
*
*Historical   :
*     1. Creation Lap Dang Oct 7, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_ChryslerCCDLink(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking);

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 21 Feb 2011
*Function name  : gf_VCI_DDL1_Link
*Description    :
*Input          : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking

*Output:none
-----------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_DDL1_Link(structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking);


//TODO :need add more detail
structResponseBuffer * gf_VCI_TP_Can_Link(structLinkProfile * p_strtLinkProfile);
structResponseBuffer * gf_VCI_TP_Can_Kw_Link(structLinkProfile * p_strtLinkProfile);
structResponseBuffer * gf_VCI_TP_Can_Kw1281_Link(structLinkProfile * p_strtLinkProfile);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:structResponseBuffer* gf_VCI_Volvo_KW_Link(structLinkProfile * p_strtLinkProfile)
*Input        :
*Output       :!= Null is valid response
*Description  :
*this will send data as format [0x84,0x40,0x13],[0xB2,0xF0,0x03],[0x7C] hdr = 84 , tag = 40 src =13 , cmd [0xB2,0xF0,0x03] , cs = 7C
*
*
*Historical   :
*     1. Creation Lap Dang Mar 30, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_Volvo_KW_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:structResponseBuffer* gf_VCI_BMW_DS2_Link(structLinkProfile * p_strtLinkProfile,enumbool IsDS2MID)
*Input        :IsDS2MID=eTRUE if use DS2_MID , Other set eFALSE
*Output       :!=Null if successful
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Mar 31, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_BMW_DS2_Link(structLinkProfile * p_strtLinkProfile,enumbool IsDS2MID);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:structResponseBuffer* gf_VCI_BMW_KWB8_Link(structLinkProfile * p_strtLinkProfile)
*Input        :
*Output       :structResponseBuffer* !=null if successful
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Apr 10, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_BMW_KWB8_Link(structLinkProfile * p_strtLinkProfile);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:structResponseBuffer * gf_VCI_BMW_KwOnCAN_Link(structLinkProfile * p_strtLinkProfile)
*Input        :structLinkProfile * p_strtLinkProfile , KwSrcaddr
*Output       :structResponseBuffer *
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Apr 11, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_BMW_KwOnCAN_Link(structLinkProfile * p_strtLinkProfile);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void gf_VCI_Volvo_DWCan_Link(structLinkProfile * p_strtLinkProfile)
*Input        : structLinkProfile * p_strtLinkProfile
*Output       : structResponseBuffer * !=null if valid
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Apr 1, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_Volvo_DWCan_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:structResponseBuffer * gf_VCI_Volvo_DWCan_Link_DetectAddr(structLinkProfile * p_strtLinkProfile,uint8 *pDataFrameDetect)
*Input        :structLinkProfile * p_strtLinkProfile,uint8 *pDataFrameDetect
*Input        pDataFrameDetect [LEN][Data]
*Output       :structResponseBuffer* - !=null if valid
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Apr 8, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_Volvo_DWCan_Link_DetectAddr(structLinkProfile * p_strtLinkProfile,uint8 *pDataFrameDetect);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structLinkProfile *gf_VDM_GetLinkProfile(void)
 *Input        :
 *Output       : structLinkProfile *
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  11:24:15 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structLinkProfile *gf_VDM_GetLinkProfile(void);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structResponseBuffer* gf_VCI_HyundaiISO_InitFB(structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  4:28:20 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_HyundaiISO_InitFB(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structResponseBuffer* gf_VCI_HyndaiISO_Link(structLinkProfile * p_strtLinkProfile)
 *Input        : structLinkProfile * p_strtLinkProfile
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:31:19 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_HyndaiISO_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VCI_Fiat_SWCan_Link(structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Aug 2, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_Fiat_SWCan_Link(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name:void gf_VCI_Keyword_Init(structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *if fast init , data will send out wakeup and set response 0 to valid resp
 *if fivebaud , obd message will send out and validate data , set response 0 to valid if ok
 *
 *Historical   :
 *     1. Creation Lap Dang  8:43:26 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_Keyword_Init(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void gf_VCI_Custom_DWCan_Link(structLinkProfile * p_strtLinkProfile,
							  void * pCmdFCtrl,
		   	   	   	   	   	  enumCanMesgType (*pf_ClassifyFrameType)(uint8 * strData))
*Input        : structLinkProfile * p_strtCANProfile
*Output       :
*Description  :
*use to send DWCAN protocol with special require in
*handle flowcontrol
*Example control message arrFcTxMessage[]= {8,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
*
00 00 07 B0  08 01 04 18 00 FF 00 00 00
00 00 07 DA  08 F1 10 0A 58 02 00 01 02
00 00 07 DA  08 F1 20 01 00 11 01 00 00
*=> bOffsetRxFrame=0 : {F1 10 0A 58 02 00 01 02 F1 20 01 00 11 01 00 00}
*=> bOffsetRxFrame=1 : {10 0A 58 02 00 01 02 01 00 11 01 00 00}
*Historical   :
*     1. Creation Lap Dang Aug 2, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_Custom_DWCan_Link(structLinkProfile * p_strtLinkProfile,
							  void * pCmdFCtrl,
		   	   	   	   	   	  enumCanMesgType (*pf_ClassifyFrameType)(uint8 * strData),
							  uint8 bOffsetRxFrame);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VCI_DWCanSetMaxLinkTime(uint32 Second)
 *Input        :
 *Output       :
 *Description  :
 *use to set custom maximum linking time live
 *default will be 180Seconds if get negative 78 / 21
 *Auto reset Linked Time to default when get out function
 *Historical   :
 *     1. Creation Lap Dang  11:10:45 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_DWCanSetMaxLinkTime(uint32 Second);
/*
 * This function use for dwcan link of peugeot
 * */
#define gf_VCI_Peugeot_DWCan_Link(p_strtLinkProfile,pCmdFCtrl)	gf_VCI_Custom_DWCan_Link(p_strtLinkProfile,pCmdFCtrl,Null,0)
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VCI_OBDTruck_J1708Link
 *Input        : structLinkProfile * p_strtLinkProfile,pRom_Req pCmdLinking
 *Output       : structResponseBuffer *
 *Description  :
 * send data using none header mode
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Oct 7, 2014
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_OBDTruck_J1708Link(
		structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structResponseBuffer * gf_VCI_OBDTruck_J1939Link(
 structLinkProfile * p_strtLinkProfile)

 XX=p_strtLinkProfile->strtReqBuf.bHeader
 YY= p_strtLinkProfile->strtReqBuf.bSrcAddr
 Addr Request = p_strtLinkProfile->strtReqBuf.iCANReqID|(XX-YY)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  4:19:10 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer * gf_VCI_OBDTruck_J1939Link(
		structLinkProfile * p_strtLinkProfile);

#endif /* VCI_APP_H_ */
