/******************************************************************************************************************
* Engineer    : automatic generated
* Date        : 12/4/2015
* Version   : V01.00.01
********************************************************************************************************************/


#ifndef __ENUMS_GlobalTruck_H__
#define __ENUMS_GlobalTruck_H__





typedef enum _enumReaddtccommandlist_GlobalTruck{
    ereaddtccommandlist_UNKNOWN_GlobalTruck   = 0,
    ereaddtccommandlist_80_____C2_____00___1_GlobalTruck  = 1,
}enumReaddtccommandlist_GlobalTruck;


typedef enum _enumMessageid_GlobalTruck{
    emessageid_UNKNOWN_GlobalTruck   = 0,
    emessageid_ECM_DTCID_0000_GlobalTruck  = 1,
    emessageid_TCM_DTCID_0000_GlobalTruck  = 2,
    emessageid_ABS_DTCID_0000_GlobalTruck  = 3,
    emessageid_IPC_DTCID_0000_GlobalTruck  = 4,
    emessageid_VMS_DTCID_0000_GlobalTruck  = 5,
    emessageid_FUE_DTCID_0000_GlobalTruck  = 6,
    emessageid_CCS_DTCID_0000_GlobalTruck  = 7,
    emessageid_PTS_DTCID_0000_GlobalTruck  = 8,
}enumMessageid_GlobalTruck;


typedef enum _enumCommand_GlobalTruck{
    ecommand_UNKNOWN_GlobalTruck   = 0,
    ecommand_80_____C2_____00_GlobalTruck  = 1,
    ecommand_C3_____03_____00_____00_____A0_GlobalTruck  = 2,
}enumCommand_GlobalTruck;


typedef enum _enumDtcreadtype_GlobalTruck{
    edtcreadtype_UNKNOWN_GlobalTruck   = 0,
    edtcreadtype_ReadDTCType_ID0000_GlobalTruck  = 1,
}enumDtcreadtype_GlobalTruck;


typedef enum _enumCommandlist_GlobalTruck{
    ecommandlist_UNKNOWN_GlobalTruck   = 0,
    ecommandlist_80_____C2_____00_GlobalTruck  = 1,
    ecommandlist_C3_____03_____00_____00_____A0_GlobalTruck  = 2,
}enumCommandlist_GlobalTruck;


typedef enum _enumTiming_GlobalTruck{
    etiming_UNKNOWN_GlobalTruck   = 0,
    etiming_TimingP_OBDTruck_J1708_GlobalTruck  = 1,
}enumTiming_GlobalTruck;


typedef enum _enumSystem_GlobalTruck{
    esystem_UNKNOWN_GlobalTruck   = 0,
    esystem_OBDII_GlobalTruck  = 1,
    esystem_ECM_GlobalTruck  = 2,
    esystem_TCM_GlobalTruck  = 3,
    esystem_ABS_GlobalTruck  = 4,
    esystem_IPC_GlobalTruck  = 5,
    esystem_VMS_GlobalTruck  = 6,
    esystem_FUE_GlobalTruck  = 7,
    esystem_CCS_GlobalTruck  = 8,
    esystem_PTS_GlobalTruck  = 9,
}enumSystem_GlobalTruck;


typedef enum _enumSheet1_GlobalTruck{
    esheet1_UNKNOWN_GlobalTruck   = 0,
}enumSheet1_GlobalTruck;


#endif