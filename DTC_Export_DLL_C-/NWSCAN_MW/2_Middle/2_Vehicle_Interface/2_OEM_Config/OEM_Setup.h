/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename: OEM_Setup.h
Description: main operation of tool start from here
layer: Main Application Layer
Accessability:connect to Middle layer UserInterface.c Only
===============================================================================
******************************************************************************/
/*
===============================================================================
                                INCLUDED FILES
===============================================================================
*/
#ifndef __OEM_SETUP_H
#define __OEM_SETUP_H
void gf_Init_OEM_Profile(structVehicleProfile * p_strtVeh);
enumbool gf_Search_Index_OEM_Module(enumVehicle eVehicle,enumController eOEMModule,uint8 *bIdx);
void gf_Init_Vehicle_Module(structVehicleProfile * p_strtVeh);
const char * gf_GetOBDAPI_Version(void);
#endif
