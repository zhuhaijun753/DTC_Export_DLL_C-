/*******************************************************************************
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/
#ifndef _CABLE_ID_H
#define _CABLE_ID_H



typedef enum _enumCableId
{

    CABLE_GENERIC       =0,
    CABLE_GM_OBD1       =1,
    CABLE_FORD_OBD1     =2,
    CABLE_CHRYSLER_OBD1 =3,
    CABLE_TOYOTA_OBD1   =4,
    CABLE_HONDA_OBD1    =5,
    CABLE_KIA_20_PINS=6,
    CABLE_TOYOTA_17_PINS=7,
    CABLE_TOYOTA_22_PINS=8,
    CABLE_BMW_20_PINS=9,
    CABLE_NISSAN_14_PINS=10,
    CABLE_BMW_16_PINS=11,
    CABLE_BENZ_38_PINS=12,
    CABLE_CHRYSLER_16_PINS=13,
    CABLE_BENZ_14PIN_PINS=14,
    CABLE_MAZDA_17_PINS=15,
    CABLE_MIT_12_16_PINS=16,
    CABLE_NISSAN_14_TSURU=17,
    CABLE_UNKNOWN
} enumCableId;



//=========================== Prototype Function =============================//
enumCableId GetCableID (void);
enumbool CheckCableChange(enumCableId* p_eRefCableID);

#endif