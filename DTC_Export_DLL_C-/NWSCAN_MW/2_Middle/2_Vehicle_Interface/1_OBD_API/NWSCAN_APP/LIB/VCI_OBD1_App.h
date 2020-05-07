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

#ifndef VCI_OBD1_APP_H_
#define VCI_OBD1_APP_H_

/*
 * GM
 * */

/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: gf_VCI_GMOBD1_Init
*Input        : structLinkProfile * p_strtLinkProfile
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Mar 11, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
void gf_VCI_GMOBD1_Init(structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer       : Thanh Luu
 *Date           :
 *Function name  : GM_OBD1_Link
 *Description    : Link to GM's vehicle
 *Input          : pstrGMProfile, p_strtLinkProfile
 *Output         :
 *-----------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_GMOBD1_ReadDtc(structLinkProfile * p_strtLinkProfile);

/*
 * Chrysler
 * */
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VCI_ChryslerOBD1_Load
 *Input        :structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 12, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_ChryslerOBD1_Load(structVehDB * p_strtVehDB,
        structLinkProfile * p_strtLinkProfile);


/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structResponseBuffer* gf_VCI_ChryslerOBD1_ReadDtc(structLinkProfile * p_strtLinkProfile)
 *Input        :structLinkProfile * p_strtLinkProfile
 *Output       : structResponseBuffer
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 12, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_ChryslerOBD1_ReadDtc(
        structLinkProfile * p_strtLinkProfile);
/**
 * Honda OBD1
 */
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VCI_HondaOBD1_Load(structVehDB * p_strtVehDB,
        structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 13, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_HondaOBD1_Load(structVehDB * p_strtVehDB,
        structLinkProfile * p_strtLinkProfile);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structResponseBuffer* gf_VCI_HondaOBD1_ReadDtc(
        structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 13, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_HondaOBD1_ReadDtc(
        structLinkProfile * p_strtLinkProfile);


/*
 * Toyota OBD1
 * */

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VCI_ToyotaOBD1_Load
 *Input        :structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 12, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_ToyotaOBD1_Load(structVehDB * p_strtVehDB,
                              structLinkProfile * p_strtLinkProfile);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: structResponseBuffer* gf_VCI_ToyotaOBD1_ReadDtc(structLinkProfile * p_strtLinkProfile)
*Input        :
*Output       :
*Description  :
*
*
*
*Historical   :
*     1. Creation Lap Dang Mar 14, 2015
*
*
*
*
-------------------------------------------------------------------------------*/
structResponseBuffer* gf_VCI_ToyotaOBD1_ReadDtc(structLinkProfile * p_strtLinkProfile);

/*
 * FORD OBD1
 * */
/*------------------------------------------------------------------------------
*Engineer       : Hai Tran
*Date           : 17 Sep 2011
*Function name  : enumbool gf_VCI_FordOBD1_IsWaitIgnitionOff(structLinkProfile * p_strtLinkProfile,
											uint16 TimeOffMs,
											void (*pfProgressBar)(uint16 sPercent))  //wait ignition off 10s

*Description    :
*Input          :
*Output         :
*-----------------------------------------------------------------------------*/
enumbool gf_VCI_FordOBD1_IsWaitIgnitionOff(structLinkProfile * p_strtLinkProfile,
											uint16 TimeOffMs,
											void (*pfProgressBar)(uint16 sPercent));

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 20July2010
*Function name  : WaitDLC_Idle
*Description    : wait dlc idle in iTime_ms
                  idle level is high or low depend on user
*Input          : eDLCRxPinName,iTime_ms
*Output         : none
-----------------------------------------------------------------------------*/
void gf_EnterModeOBD1(enumOBD1Mode eOBD1Mode);
/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: gf_VCI_ToyotaOBD1_Load
 *Input        :structVehDB * p_strtVehDB,structLinkProfile * p_strtLinkProfile
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Mar 12, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_FordOBD1_Load(structVehDB * p_strtVehDB,
                              structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_KOEO_Link(structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_KOER_Init(structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_KOER_Link(structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_Wiggle_Link(structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_Enter_Wiggle_Mode(void);
void Ford_OBD1_CylBalance_Link(structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_TimingTest(structLinkProfile * p_strtLinkProfile);
void Ford_OBD1_OutputCheck_Link(structLinkProfile * p_strtLinkProfile);
void Wait_End_Slow_code(structLinkProfile * p_strtLinkProfile);
void Wait_KLine_High(structLinkProfile * p_strtLinkProfile,uint8 Second);
enumbool Ford_OBD1_Erase(structLinkProfile * p_strtLinkProfile);
enumbool gf_VCI_FordOBD1_IsIgnitionOn(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: enumBusStatus gf_VCI_Ford_ReadKlineStatus(structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *read status of Kline RX
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:23:25 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
enumBusStatus gf_VCI_Ford_ReadKlineStatus(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VCI_Ford_OBD1_Init_HW(structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  11:59:48 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VCI_Ford_OBD1_Init_HW(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: sint8 gf_VCI_Ford_GetNumberCylinder(structLinkProfile * p_strtLinkProfile)
 *Input        :structLinkProfile * p_strtLinkProfile
 *Output       : >=0 if successful / <0 if fail
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:31:42 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
sint8 gf_VCI_Ford_GetNumberCylinder(structLinkProfile * p_strtLinkProfile);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: sint8 gf_VCI_Ford_GetGooseCode(structLinkProfile * p_strtLinkProfile)
 *Input        :
 *Output       :>=0 is goosecode if successful , <0 : Fail
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang  8:33:52 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
sint8 gf_VCI_Ford_GetGooseCode(structLinkProfile * p_strtLinkProfile);

#endif /* VCI_APP_H_ */
