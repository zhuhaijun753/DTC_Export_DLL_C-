/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename: ISOK2000ProtocolDriver.h
Description: main operation of tool start from here
layer: Main Application Layer
Accessability:connect to Middle layer UserInterface.c Only
===============================================================================
******************************************************************************/
#ifndef _VBI_DEFAULT_APP_H
#define _VBI_DEFAULT_APP_H
#ifdef _VBI_DEFAULT_APP_C
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NWScanConfigDefault
*Description: load database to link profile base on protocol x
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output:
-----------------------------------------------------------------------------*/
static structVehDB * __NWScanConfigDefault(structVehicleProfile * p_VehicleProfile);
#endif
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: gf_VBI_Protocol_Iso_Load
*Description: load database to link profile
*Input:
    p_strtLinkProfile->strtReqBuf.bHeader=p_strtVehDB->Hdr1;
    p_strtLinkProfile->strtReqBuf.bTgtAddr=p_strtVehDB->Hdr2;
    p_strtLinkProfile->strtReqBuf.bSrcAddr=p_strtVehDB->Hdr3;
    p_strtLinkProfile->strtKlineInitParam.bAddr5bps  =p_strtVehDB->bFB;
    p_strtLinkProfile->strtMode.strtProtParKline.eInitType=p_strtVehDB->eInitType;

    p_strtLinkProfile->strtMode.blAutoFmt=eTRUE;
    p_strtLinkProfile->strtMode.blKwStandard=eTRUE;

*Output:
-----------------------------------------------------------------------------*/
void gf_VBI_Protocol_Iso_Load(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);


/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: gf_VBI_Protocol_DWCan_Load
*Description: load database to link profile Dual wire can protocol
*Input:
        structVehDB * p_strtVehDB               :present line database
        structLinkProfile * p_strtLinkProfile   :
        p_strtLinkProfile->strtReqBuf.iCANReqID = p_strtVehDB->Hdr1;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrStart = p_strtVehDB->Hdr2;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrEnd = p_strtVehDB->Hdr3;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrStart2 = p_strtVehDB->Hdr4;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrEnd2 = p_strtVehDB->Hdr5;
*Output:
-----------------------------------------------------------------------------*/
void gf_VBI_Protocol_DWCan_Load(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);


/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: gf_VBI_Protocol_SWCan_Load
*Description: load database to link profile single wire can protocol
*Input:
        structVehDB * p_strtVehDB               :present line database
        structLinkProfile * p_strtLinkProfile   :

        p_strtLinkProfile->strtReqBuf.iCANReqID = p_strtVehDB->Hdr1;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrStart = p_strtVehDB->Hdr2;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrEnd = p_strtVehDB->Hdr3;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrStart2 = p_strtVehDB->Hdr4;
        p_strtLinkProfile->strtCanAddrFilter.iRxAddrEnd2 = p_strtVehDB->Hdr5;
*Output:
-----------------------------------------------------------------------------*/
void gf_VBI_Protocol_SWCan_Load(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);


/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: gf_VBI_Protocol_KW_Load
*Description: load database to link profile kw protocol in both basic type
-standard : init with $81
-Not standard : Init by custom service ex: 10 81 ...
*Input:
        structVehDB * p_strtVehDB               :present line database
        structLinkProfile * p_strtLinkProfile   :

        p_strtLinkProfile->strtReqBuf.bHeader=p_strtVehDB->Hdr1;
        p_strtLinkProfile->strtReqBuf.bTgtAddr=p_strtVehDB->Hdr2;
        p_strtLinkProfile->strtReqBuf.bSrcAddr=p_strtVehDB->Hdr3;
        p_strtLinkProfile->strtMode.strtProtParKline.eInitType=p_strtVehDB->eInitType;

        p_strtLinkProfile->strtKlineInitParam.eCheckSumType = p_strtVehDB->eCheckSumType;
        p_strtLinkProfile->strtMode.blAutoFmt=eTRUE;
        p_strtLinkProfile->strtMode.blKwStandard=eTRUE;
*Output:
-----------------------------------------------------------------------------*/
void gf_VBI_Protocol_KW_Load(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);

/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: gf_VBI_Protocol_Pwm_Load
*Description: load database to link profile pwm protocol
*Input:
        structVehDB * p_strtVehDB               :present line database
        structLinkProfile * p_strtLinkProfile   :

        p_strtLinkProfile->strtReqBuf.bHeader=p_strtVehDB->Hdr1;
        p_strtLinkProfile->strtReqBuf.bTgtAddr=p_strtVehDB->Hdr2;
        p_strtLinkProfile->strtReqBuf.bSrcAddr=p_strtVehDB->Hdr3;

*Output:
-----------------------------------------------------------------------------*/
void gf_VBI_Protocol_Pwm_Load(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);

/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: gf_VBI_Protocol_Vpw_Load
*Description: load database to link profile vpw protocol
*Input:
        structVehDB * p_strtVehDB               :present line database
        structLinkProfile * p_strtLinkProfile   :
*Output:
-----------------------------------------------------------------------------*/
void gf_VBI_Protocol_Vpw_Load(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_ProtocolStdLink
*Input        : structVehicleProfile * p_strtVehicleProfile,Rom_Req *pCmdLink,Rom_Req *pCmdReInit
*Output       :
*Description  :
*handle some basic function generally PROTOCOL_VPW ,PROTOCOL_PWM ,PROTOCOL_CAN,PROTOCOL_SWCAN,PROTOCOL_KW,PROTOCOL_KW2000,PROTOCOL_ISO9141
*
*
*Historical   :
*     1. Creation Lap Dang Sep 11, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VBI_ProtocolStdLink(structLinkProfile  *p_strtLinkProfile,
                            enumProtocol eProtocol,
                            Rom_Req *pCmdLink,
                            Rom_Req *pCmdReInit,
                            Rom_Req *pCmdKeepAlive);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_ProtGeneral_VDB2Profile
*Input        : structVehDB * p_strtVehDB,structVehicleProfile * p_strtVehicleProfile
*Output       : eTRUE : OK , eFALSE : fail
*Description  :
*load data from vehicle db to  p_strtVehicleProfile->p_strtLinkProfile
*
*
*Historical   :
*     1. Creation Lap Dang Sep 11, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VBI_ProtGeneral_VDB2Profile(structVehDB * p_strtVehDB,structLinkProfile  *p_strtLinkProfile);
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NwScan_Prot_QueryDefault
*Description: this function will be used as default query process if use do not
init in their structure
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output: enumQueryPrcSt
-----------------------------------------------------------------------------*/
enumQueryPrcSt __NwScan_Prot_QueryDefault(structVehicleProfile * p_VehicleProfile);
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NwScan_Prot_EcuInfoDefault
*Description: this function will be used as default query process if use do not
init in their structure
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output: enumEcuInfoPrcSt
-----------------------------------------------------------------------------*/
enumEcuInfoPrcSt __NwScan_Prot_EcuInfoDefault(structVehicleProfile * p_VehicleProfile);
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NwScan_Prot_LinkDefault
*Description: this function will be used as default link process if use do not
init in their structure
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output: enumQueryPrcSt
-----------------------------------------------------------------------------*/
enumLinkPrcSt __NwScan_Prot_LinkDefault(structVehicleProfile * p_VehicleProfile);
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NwScan_Prot_EraseDefault
*Description: this function will be used as default erase process if use do not
init in their structure
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output: enumQueryPrcSt
-----------------------------------------------------------------------------*/
enumErasePrcSt __NwScan_Prot_EraseDefault(structVehicleProfile * p_VehicleProfile);
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NwScan_Prot_KeepAliveDefault
*Description: this function will be used as default keepalive process if use do not
init in their structure
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output: enumQueryPrcSt
-----------------------------------------------------------------------------*/
enumKeepAlivePrcSt __NwScan_Prot_KeepAliveDefault(structVehicleProfile * p_VehicleProfile);
/*-----------------------------------------------------------------------------
*Engineer: Lap Dang
*Date:13 Mar 2013
*Function name: __NwScan_Prot_ExitDefault
*Description: this function will be used as default exit process if use do not
init in their structure
*Input:
        structVehicleProfile * p_strtVehicleProfile
*Output: enumQueryPrcSt
-----------------------------------------------------------------------------*/
enumExitPrcSt __NwScan_Prot_ExitDefault(structVehicleProfile * p_VehicleProfile);
#endif/*_VEHICLEINTERFACE_H*/
