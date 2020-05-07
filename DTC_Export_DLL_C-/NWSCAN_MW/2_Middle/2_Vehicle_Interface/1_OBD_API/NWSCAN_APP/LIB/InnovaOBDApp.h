/******************************************************************************
 ===============================================================================
                         Lap Dang Dev
 * Filename : InnovaOBDApp.h
 * Description:
 
 *  Created on: Lap Dang  Nov 3, 2014
 *
 *  Version         : V01.00.00
===============================================================================
******************************************************************************/

#ifndef _INNOVAOBDAPP_H_
#define _INNOVAOBDAPP_H_

#define MAX_LEN_VIN_NUMBER  17
#pragma pack(1)
typedef struct _structOBD2VinNumber
{
   uint8 strVinNumber[MAX_LEN_VIN_NUMBER];
   uint8 validcode;
}structOBD2VinNumber;

#define MAX_LEN_CALIBRATION_ID  11
typedef struct _structOBD2CalibID
{
   uint8 strCalibID[MAX_LEN_CALIBRATION_ID];
   uint8 validcode;
}structOBD2CalibID;


#pragma pack()



#ifndef OBD2_ECM
#define OBD2_ECM        2
#endif
#ifndef OBD2_TCM
#define OBD2_TCM        3
#endif

#define OBD2_ECM_IDX    0
#define OBD2_TCM_IDX    1
#define MAX_LEN_RES_BUFF 255

#define OBD2_PROTOCOl_ID            (g_strtOBD2Profiles[OBD2_ECM_IDX].iLinkedIdx1)//use to load database
#define OBD2_PROTOCOL_MAIN          (g_strtOBD2Profiles[OBD2_ECM_IDX].Protocol)

#define OBD2_ECM_ADDR               (g_strtOBD2Profiles[OBD2_ECM_IDX].EcuAddr)
#define OBD2_TCM_ADDR               (g_strtOBD2Profiles[OBD2_TCM_IDX].EcuAddr)




extern structVehicleProfile      g_strtNWScanVehicleProfile;
extern structLinkProfile         g_strtNWScanLinkProfile;
extern uint8 strResBufferData[NUM_RES_BUF][MAX_LEN_RES_BUFF];


#ifndef p_strtNWScanLinkProfile
#define p_strtNWScanLinkProfile           (&g_strtNWScanLinkProfile)
#endif

#endif /* 2_MIDDLE_2_VEHICLE_INTERFACE_NWSCAN_APP_LIB_INNOVAOBDAPP_H_ */
