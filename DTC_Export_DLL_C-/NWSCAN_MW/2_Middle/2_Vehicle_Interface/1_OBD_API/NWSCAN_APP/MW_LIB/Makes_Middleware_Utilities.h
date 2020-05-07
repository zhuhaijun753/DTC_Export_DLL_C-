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
#define NWS_NUMBER_CMD_BYTE 50    /*Hung Vo modified from [10] to [50] on 17 Nov 2015*/
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


#endif /* MAKES_MIDDLEWARE_UTILITIES_H_ */
