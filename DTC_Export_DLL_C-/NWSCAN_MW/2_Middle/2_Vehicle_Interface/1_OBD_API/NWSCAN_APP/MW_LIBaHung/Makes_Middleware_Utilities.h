/*******************************************************************************
================================================================================
                              Lap Dang Dev
 * Filename: Makes_Middleware_Utilities.h
 * Description:
 * Layer:
 * Accessibility:
 * Created on: Nov 13, 2015
 *      Author: Lap Dang
================================================================================
*******************************************************************************/

#ifndef MAKES_MIDDLEWARE_UTILITIES_H_
#define MAKES_MIDDLEWARE_UTILITIES_H_

#ifndef ePCMD_MAX
#define ePCMD_MAX    65535
#endif
#ifndef ePPCMD_MAX
#define ePPCMD_MAX    65535
#endif

#pragma pack(1)
//#define NWS_NUMBER_CMD_BYTE 50    /*Hung Vo modified from [10] to [50] on 17 Nov 2015*/
#define NWS_NUMBER_CMD_BYTE 255    /*Hung Vo modified from [50] to [255] on 01 Feb 2016*/
typedef struct _structpCmd
{
        uint8 bNoByte;
        uint8 bCmd[NWS_NUMBER_CMD_BYTE];
} structpCmd;
#pragma pack()


#pragma pack(1)
#define NWS_NUMBER_CMD_LIST 15
typedef struct _structListpCmd
{
        uint8 bNoCmd;
        //uint8 bListCmdID[NWS_NUMBER_CMD_LIST][NWS_NUMBER_CMD_BYTE];
        enumCommands eList_PCMDs[NWS_NUMBER_CMD_LIST];
} structListpCmd;
#pragma pack()

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: uint8 *gf_VDM_CMD_EnumCmdToData(enumCommands eCmd,uint8* pRamCmd)
 *Input        : enumCommands eCmd
 *Output       : uint8* pRamCmd
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Apr 27, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
uint8 *gf_VDM_CMD_EnumCmdToData(enumCommands eCmd, uint8* pRamCmd);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: structListpCmd * gf_VDM_CMD_EnumCmdListToListPCMD(enumCommandList sCmdListID,structListpCmd *pstrtListpCmd)

 *Input        : enumCommandList sCmdListID
 *Output       : structListpCmd *pstrtListpCmd
 *Description  :
 * command list to list command
 *
 *
 *Historical   :
 *     1. Creation Lap Dang Apr 27, 2015
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
structListpCmd * gf_VDM_CMD_EnumCmdListToListPCMD(enumCommandList sCmdListID,structListpCmd *pstrtListpCmd);

/*------------------------------------------------------------------------------
 *Engineer     : Lap Dang
 *Function name: void gf_VDM_DisableReLoadDBInProtocolLink(void)
 *Input        :
 *Output       :
 *Description  :
 * use this one to speed up process link
 * if want to skip reload database from sd
 *
 *Historical   :
 *     1. Creation Lap Dang  12:36:41 PM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
void gf_VDM_DisableReLoadDBInProtocolLink(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dang
*Function name: uint8* gf_VDM_NWSCAN_eCMDToData(enumCommands eCmd,uint8 pRamCmd[NWS_NUMBER_CMD_BYTE])
*Function
*Input        : enumCommands eCmd : ID Need to get corresponse data
*Input        uint8 pRamCmd[NWS_NUMBER_CMD_BYTE] : ram buffer content data
*Output       : null if not found , other : found
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
uint8* gf_VDM_NWSCAN_eCMDToData(enumCommands eCmd,uint8 pRamCmd[NWS_NUMBER_CMD_BYTE]);


/*------------------------------------------------------------------------------
 *Engineer     : LeTuan
 *Function name:int gf_VDM_Ford_Secure_SeedToKey(int seed, int s1, int s2, int s3, int s4, int s5)
 *Input        :
 *Output       :
 *Description  :
 *
 *
 *
 *Historical   :
 *     1. 24Sep20165 - LeTuan, (rewritten in C)
 *     2. Creation Lap Dang Mar 31, 2016  9:45:11 AM
 *
 *
 *
 *
 -------------------------------------------------------------------------------*/
int gf_VDM_Ford_Secure_SeedToKey(int seed, int s1, int s2, int s3, int s4, int s5);

#endif /* MAKES_MIDDLEWARE_UTILITIES_H_ */
