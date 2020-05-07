#ifndef _VDM_ADAPTER_H_
#define _VDM_ADAPTER_H_

#ifdef _VDM_ADAPTER_C_

static uint32 GetAddrModule(structLinkProfile * p_strtLinkProfile);
static void __Resp_x_RemoveFirstByte(structLinkProfile * p_strtLinkProfile,sint8 bIdxBuff);
static void __Resp_RemoveFirstByte(structLinkProfile * p_strtLinkProfile);

static void __NWScan_OBD2ParserDtc(structVehicleProfile * p_VehicleProfile);
static void __NwScan_DtcParserDefault(structVehicleProfile * p_VehicleProfile);
static void __NwScanGetUpdateProgress(structVehicleProfile * p_strtVehicleProfile);
static void __NwScanLink(structVehicleProfile * p_strtVehicleProfile);
static void __NwScanErase(structVehicleProfile * p_strtVehicleProfile);
static void __NwScanExit(structVehicleProfile * p_strtVehicleProfile);
static void __NwScanKeepAlive(structVehicleProfile * p_strtVehicleProfile);
static void __NwScanQuery(structVehicleProfile * p_strtVehicleProfile);
static enumbool _Is_Dtc_Type_status_General(structOEMDTCBuffer * pstrtOEMDTCBuffer);
#else
#endif
/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 24 April 2013
*Function name  : gf_VDM_IsExistCtrlProfile
*Description    : check exist controller profile
*Input          :
                uint16 sSubSystem : Module input
                structVehicleProfile * p_strtVehicleProfile
*Output         :
                eTRUE   : Exist
                eFALSE  : Not Exist
-----------------------------------------------------------------------------*/
enumbool gf_VDM_IsExistCtrlProfile(structVehicleProfile * p_strtVehicleProfile,uint16 sSubSystem,uint16 sSystem);

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 24 May 2013
*Function name  : gf_VDM_InsertCtrlProfile
*Description    : use to insert new controller profile to struct vehicle profile
*Input          :
                uint16 sCtrlName new controller will be inserted
                structVehicleProfile * p_strtVehicleProfile
*Output         : None
-----------------------------------------------------------------------------*/
void gf_VDM_InsertCtrlProfile(structVehicleProfile * p_strtVehicleProfile,uint16 sSubSystem,uint16 sSystem);

void gf_VBI_Resp_Remove_nFirstBytes(structLinkProfile * p_strtLinkProfile,uint8 bNumByte,sint8 BufferIdx);
void gf_VBI_Resp_Remove_nByte_FmtDtc(structLinkProfile * p_strtLinkProfile,uint16 sNumByte,uint8 eFormatDtc);
void gf_VBI_Resp_DTC_m2nbytes(structLinkProfile * p_strtLinkProfile, uint8 b_mBytes, uint8 b_nBytes);
void gf_VBI_Resp_x_DTC_m2nbytes(structLinkProfile * p_strtLinkProfile, uint8 b_mBytes, uint8 b_nBytes,sint8 bIdxResBuff);
void gf_VBI_Resp_Remove_nByte_FmtDtc(structLinkProfile * p_strtLinkProfile,uint16 sNumByte,uint8 eFormatDtc);
void gf_VBI_Resp_SetToDefault(structLinkProfile * p_strtLinkProfile);
void gf_VBI_Resp_X_SetToDefault(structLinkProfile * p_strtLinkProfile,uint8 bIdxBuff);
sint8 gf_VBI_Resp_OfBufferName(structLinkProfile * p_strtLinkProfile,enumBufferName eBufferName);
void * gf_GetVehVersion(structVehicleProfile * p_strtVehicleProfile);


enumbool gf_VDM_Initialize(structVehicleProfile * p_strtVehicleProfile, structLinkProfile * gp_strtLinkProfile, const structVehNWScanSupported * p_strtVehNWScanSupported);
void * gf_VDM_DTC_GetDtcString(structVehicleProfile * p_strtVehicleProfile,enumBufferName * pBuffName,uint8 bDtcNo);
void * gf_VDM_DTC_GetRawData(structVehicleProfile * p_strtVehicleProfile,uint8 * pFmtDtc,uint8 bDtcNo);

void gf_VDM_RemoveCtrlProfile(structVehicleProfile * p_strtVehicleProfile,uint16 sSubSystem,uint16 sSystem);
structOemProfile * gf_VDM_GetActiveProfile(structVehicleProfile * p_strtVehicleProfile);
void gf_VDM_SetActiveProfile(structVehicleProfile * p_strtVehicleProfile,uint16 sSubSystem,uint16 sSystem);
structVehDB * gf_VDM_GetActive_DB(structVehicleProfile * p_strtVehicleProfile);
enumbool gf_IsPresentModuleSupported(structVehicleProfile * p_strtVehicleProfile);
void * gf_VDM_DTC_GetDtcString(structVehicleProfile * p_strtVehicleProfile,enumBufferName * pBuffName,uint8 bDtcNo);
void * gf_VDM_DTC_GetRawData(structVehicleProfile * p_strtVehicleProfile,uint8 * pFmtDtc,uint8 bDtcNo);
const char * gf_OBDAPI_GetVersion(void);
structVehDB * gf_VDM_DB_GetDataOfIdx(structVehicleProfile * p_VehicleProfile,uint32 iIdx);
uint32 gf_VDM_DB_GetNumDB(structVehicleProfile * p_VehicleProfile);
enumbool gf_VBI_IsLinkSuccess(structVehicleProfile * p_strtVehicleProfile);
void gf_VBI_RespDtc_SetValToPos(structLinkProfile * p_strtLinkProfile,
                                uint8 bVal,
                                uint8 bPos,
                                uint8 bFrame);
enumbool gf_VDM_IsValidDtc(uint8 * pDtc,uint8 bFmt);
uint8 gf_VDM_NwScan_GetMax_FmtDtcBytes(structVehicleProfile * p_strtVehicleProfile);
enumbool gf_VDM_NwScan_IsDtcDupplicate(structOEMDTCBuffer * pstrtOEMDTCBuffer, uint8 * pDtc,enumBufferName eBufferName, uint8 bFmtDtc);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_OemProfileParseDtc
*Input        :structOemProfile * p_strtOemProfile,
               structLinkProfile * p_strtLinkProfile,
               DTC_DISP_TYPE DtcDispType,
               uint8 bStdFmtDtc
*Output       :
*Description  :
*pstrtResponseBuffer->pstrData
*pstrtResponseBuffer->bDtcFrameSize
*pstrtResponseBuffer->sResLen
*pstrtResponseBuffer->eBuffName
*pstrtResponseBuffer->bOffSet
*pstrtResponseBuffer->bFormatDtc
*
*
*Historical   :
*     1. Creation Lap Dang Sep 12, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VDM_OemProfileParseDtc(structOemProfile * p_strtOemProfile,
                               structLinkProfile * p_strtLinkProfile,
                               DTC_DISP_TYPE DtcDispType,
                               uint8 bStdFmtDtc);

void gf_VBI_ResStrt_RemoveFirstByte(structResponseBuffer *p_strtResponseBuffer,uint8 bNumFirstByte);
void gf_VDM_OemProfileParseDtcFromSingleRespBuffer(structOemProfile * p_strtOemProfile,
                                                    structResponseBuffer * pstrtResponseBuffer,
                                                    DTC_DISP_TYPE DtcDispType,
                                                    uint8 bStdFmtDtc);
/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_DTC_GetRawFromOemProfile
*Input        : structOemProfile * p_strtOemProfile
*Output       : out put frame dtc pFmtDtc
*Description  :
*get status dtc by data of index (*pFmtDtc)+1
*
*
*Historical   :
*     1. Creation Lap Dang Sep 13, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void* gf_VDM_DTC_GetRawFromOemProfile(structOemProfile * p_strtOemProfile,
                                      uint8 * pFmtDtc,
                                      uint8 bDtcNo);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name:
*Input        :structOemProfile * p_strtOemProfile,
               enumBufferName * pBuffName,
               uint8 bDtcNo,
               structDtcParser * p_strtDtcParser
*Output       :
    string of display dtc
    pBuffName buffer name of dtc

*Description  :
*
*
*Historical   :
*     1. Creation Lap Dang Sep 13, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void *gf_VDM_DTC_GetDtcStringFromOemProfile(structOemProfile * p_strtOemProfile,
                                            enumBufferName * pBuffName,
                                            uint8 bDtcNo,
                                            structDtcParser * p_strtDtcParser);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_OemProfileIsValid
*Input        : structOemProfile *pstrtOemProfile
*Output       : enumbool
*Description  :
*checking valid status of oemprofile
*
*
*Historical   :
*     1. Creation Lap Dang Sep 15, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VDM_OemProfileIsValid(structOemProfile *pstrtOemProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_GetNumberOemProfile
*Input        : structVehicleProfile * p_strtVehicleProfile
*Output       : uint16
*Description  :
*get number active module controller profile
*
*
*Historical   :
*     1. Creation Lap Dang Oct 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
uint16 gf_VDM_GetNumberOemProfile(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_GetOemProfileOfModule
*Input        : structVehicleProfile * p_strtVehicleProfile,uint16 sSubSystem
*Output       : structOemProfile *
*Description  :
*get oemprofile of module x
*
*
*Historical   :
*     1. Creation Lap Dang Oct 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structOemProfile *gf_VDM_GetOemProfileOfModule(structVehicleProfile * p_strtVehicleProfile,uint16 sSubSystem,uint16 sSystem);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_GetOemProfileOfIdx
*Input        : structVehicleProfile * p_strtVehicleProfile,uint8 bIdx
*Output       : structOemProfile *
*Description  :
*get oem profile of idx x
*
*
*Historical   :
*     1. Creation Lap Dang Oct 6, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
structOemProfile *gf_VDM_GetOemProfileOfIdx(structVehicleProfile * p_strtVehicleProfile,uint16 sIdx);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VBI_IsLinkSuccess
*Input        : structVehicleProfile * p_strtVehicleProfile
*Output       : enumbool
*Description  :
*Check present link profile status
*
*
*Historical   :
*     1. Creation Lap Dang Oct 7, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumbool gf_VBI_IsLinkSuccess(structVehicleProfile * p_strtVehicleProfile);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_GetSystemType
*Input        : structOemProfile *p_strtOemProfile
*Output       : enumSystemtype
*Description  :
*Check system type to get correct enumeration type system or subsystem
*
*
*Historical   :
*     1. Creation Lap Dang Oct 7, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
enumSystemtype gf_VDM_GetSystemType(structOemProfile *p_strtOemProfile);

void gf_VBI_strtResp_Data_m2nbytes(structResponseBuffer * p_strtResBuf,uint8 b_mBytes,
        uint8 b_nBytes);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VDM_OemProfileReinit
*Input        : structVehicleProfile * p_strtVehicleProfile
*Output       : void
*Description  :
*reinit present linked profile
*
*
*Historical   :
*     1. Creation Lap Dang Oct 15, 2014
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VDM_OemProfileReinit(structVehicleProfile * p_strtVehicleProfile);


void gf_VBI_Resp_SetOffSetParser(structLinkProfile * gp_strtLinkProfile,uint8 (*pf)(struct _structLinkProfile *pstrtLinkProfile));

void gf_VDM_Set_FuncCatchVehDbFromID(structVehicleProfile * p_strtVehicleProfile,
                                     structVehDB*(*pf_ProfileIDToVehDB)(structVehicleProfile * p_strtVehicleProfile),
                                     uint16 sNumProfileActive,uint32 *pListAddressProfileID);

enumbool gf_VDM_IsUsingOptimizeVehDB(structVehicleProfile * p_strtVehicleProfile);

void gf_VDM_OemProfileDtcReset(structOemProfile * p_strtOemProfile);

void gf_VDM_Dtc_RemoveAllInvalidDtc(structVehicleProfile * p_VehicleProfile);

void gf_VDM_Dtc_RemoveDtcAtIndex(structVehicleProfile * p_VehicleProfile,uint8 bIdxDtcRemoved);

sint32 gf_VDM_DtcGetNumDtc(structVehicleProfile * p_VehicleProfile);

enumbool gf_VDM_IsExistItem_Uint8(uint8 *pList,uint8 bSize,uint8 bOption);

enumCommands gf_VDM_GetDetectKeepAliveCmd(structVehicleProfile * p_VehicleProfile);

void gf_VDM_SetKeepAliveService(structVehicleProfile * p_VehicleProfile,enumCommands eCMD);

enumCommands gf_VDM_GetActiveQueryCmd(structVehicleProfile * p_VehicleProfile);

void gf_VDM_SetActiveQueryCmd(structVehicleProfile * p_VehicleProfile,enumCommands eCMD);


void gf_VDM_ResetKeepAliveService(structVehicleProfile * p_VehicleProfile);

uint8 gf_VDM_RemoveFirstSID_MultiResp(structLinkProfile *p_strtLinkProfile);

void gf_VDM_Resp_Set_OffsetRemove_nByte(structVehicleProfile * p_strtVehicleProfile,uint8 bNumOffet);


void gf_VDM_SYS_Data_Init(structVehicleProfile * p_strtVehicleProfile,
                             structOemProfile*p_strtOemProfile,
                             uint16 sNumOemProfile,
                             structLinkProfile*pstrtLinkProfile,
                             uint8*p_RAMRespDatas,
                             uint16 sSizeRamRespData);

void gf_VBI_Profile_SetProtocolDetected(structLinkProfile *pstrtLinkProfile,enumProtocol eProtocol);


enumProtocol gf_VBI_Profile_GetProtocolDetected(structLinkProfile *pstrtLinkProfile);

enumbool gf_VDM_Query_IsScanedProtocolX(structVehicleProfile * p_strtVehicleProfile,enumProtocol eProtocol);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void gf_VDM_Resp_Set_LiveDataFormat(void)
*Input        :
*Output       :
*Description  :
*use to force set offset to 0 , need to restore in when after finish present fucntion
*by call this function gf_VDM_Resp_Reset_LiveDataFormat
*
*Historical   :
*     1. Creation Lap Dang Apr 16, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VDM_Resp_Set_LiveDataFormat(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: void gf_VDM_Resp_Reset_LiveDataFormat(void)
*Input        :
*Output       :
*Description  :
*disable livedata mode
*
*
*Historical   :
*     1. Creation Lap Dang Apr 16, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VDM_Resp_Reset_LiveDataFormat(void);

void gf_VDM_OemProfileSetNoDTC(structOemProfile * p_strtOemProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_ConfigUpdateProgressBarPara(enumbool IsEnable)
 *Input        : IsEnable : eTRUE will disable calculate progress bar parameter , user need implement calculate
 *Output       :
 *Description  :
 *effece on  p_strtVehicleProfile->p_strtLinkProfile->strtNwScanProgress
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  10:28:39 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_ConfigUpdateProgressBarPara(enumbool IsEnable);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_SYS_SetOBDConnector(structVehicleProfile * p_strtVehicleProfile,enumConnectors eConnector)
 *Input        :
 *Output       :
 *Description  :
 *Set connector to system
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  12:13:10 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_SYS_SetOBDConnector(structVehicleProfile * p_strtVehicleProfile,enumConnectors eConnector);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name:void gf_VDM_OemProfileParseDtcFromSingleRespBuffer_WithLimitDtc(
		structOemProfile * p_strtOemProfile,
		structResponseBuffer * pstrtResponseBuffer, DTC_DISP_TYPE DtcDispType,
		uint8 bStdFmtDtc, uint8 bLimitNumDtc)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  11:46:13 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_OemProfileParseDtcFromSingleRespBuffer_WithLimitDtc(
		structOemProfile * p_strtOemProfile,
		structResponseBuffer * pstrtResponseBuffer, DTC_DISP_TYPE DtcDispType,
		uint8 bStdFmtDtc, uint8 bLimitNumDtc);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumbool gf_VDM_IsChangeActiveSystem(void)
 *Input        :
 *Output       :
 *Description  :
 *This function will auto reset flag change system
 *This function will depend on function gf_VDM_SetActiveProfile
 *
 *Historical   :
 *     1. Creation Lap Dang  8:52:09 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumbool gf_VDM_IsChangeActiveSystem(void);
#endif
