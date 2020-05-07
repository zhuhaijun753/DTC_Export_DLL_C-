/******************************************************************************************************************
* Author    : automatic generated
* Date      : 4/15/2015
*
********************************************************************************************************************/

#ifndef __ENUMS_YMME_OBD1_H__
#define __ENUMS_YMME_OBD1_H__

    
typedef enum _enumOBD1year{
    eOBD1year_UNKNOWN = 0,
    eOBD1year_1981,
    eOBD1year_1982,
    eOBD1year_1983,
    eOBD1year_1984,
    eOBD1year_1985,
    eOBD1year_1986,
    eOBD1year_1987,
    eOBD1year_1988,
    eOBD1year_1989,
    eOBD1year_1990,
    eOBD1year_1991,
    eOBD1year_1992,
    eOBD1year_1993,
    eOBD1year_1994,
    eOBD1year_1995,
    eOBD1year_OTHERS = 0xFE,
    eOBD1year_MAX = 0xFF
} enumOBD1year;

    
typedef enum _enumOBD1vin8{
    eOBD1vin8_UNKNOWN = 0,
    eOBD1vin8_1,
    eOBD1vin8_3,
    eOBD1vin8_4,
    eOBD1vin8_5,
    eOBD1vin8_6,
    eOBD1vin8_7,
    eOBD1vin8_8,
    eOBD1vin8_9,
    eOBD1vin8_A,
    eOBD1vin8_B,
    eOBD1vin8_C,
    eOBD1vin8_D,
    eOBD1vin8_E,
    eOBD1vin8_F,
    eOBD1vin8_G,
    eOBD1vin8_H,
    eOBD1vin8_J,
    eOBD1vin8_K,
    eOBD1vin8_L,
    eOBD1vin8_M,
    eOBD1vin8_N,
    eOBD1vin8_OTHER,
    eOBD1vin8_P,
    eOBD1vin8_R,
    eOBD1vin8_S,
    eOBD1vin8_T,
    eOBD1vin8_U,
    eOBD1vin8_W,
    eOBD1vin8_X,
    eOBD1vin8_Y,
    eOBD1vin8_Z,
    eOBD1vin8_OTHERS = 0xFE,
    eOBD1vin8_MAX = 0xFF
} enumOBD1vin8;

    
typedef enum _enumOBD1truck{
    eOBD1truck_UNKNOWN = 0,
    eOBD1truck_NO,
    eOBD1truck_YES,
    eOBD1truck_OTHERS = 0xFE,
    eOBD1truck_MAX = 0xFF
} enumOBD1truck;

    
typedef enum _enumOBD1trucktype{
    eOBD1trucktype_UNKNOWN = 0,
    eOBD1trucktype_OTHER,
    eOBD1trucktype_P_TRUCK,
    eOBD1trucktype_S_TRUCK,
    eOBD1trucktype_OTHERS = 0xFE,
    eOBD1trucktype_MAX = 0xFF
} enumOBD1trucktype;

    
typedef enum _enumOBD1heavyduty{
    eOBD1heavyduty_UNKNOWN = 0,
    eOBD1heavyduty_NO,
    eOBD1heavyduty_YES,
    eOBD1heavyduty_OTHERS = 0xFE,
    eOBD1heavyduty_MAX = 0xFF
} enumOBD1heavyduty;

    
typedef enum _enumOBD1lit{
    eOBD1lit_UNKNOWN = 0,
    eOBD1lit_2_5L,
    eOBD1lit_2_8L,
    eOBD1lit_5_0L,
    eOBD1lit_5_5L,
    eOBD1lit_OTHER,
    eOBD1lit_OTHERS = 0xFE,
    eOBD1lit_MAX = 0xFF
} enumOBD1lit;

    
typedef enum _enumOBD1vin4{
    eOBD1vin4_UNKNOWN = 0,
    eOBD1vin4_A,
    eOBD1vin4_B,
    eOBD1vin4_C,
    eOBD1vin4_D,
    eOBD1vin4_E,
    eOBD1vin4_F,
    eOBD1vin4_H,
    eOBD1vin4_J,
    eOBD1vin4_K,
    eOBD1vin4_L,
    eOBD1vin4_N,
    eOBD1vin4_OTHER,
    eOBD1vin4_R,
    eOBD1vin4_T,
    eOBD1vin4_U,
    eOBD1vin4_V,
    eOBD1vin4_W,
    eOBD1vin4_Y,
    eOBD1vin4_OTHERS = 0xFE,
    eOBD1vin4_MAX = 0xFF
} enumOBD1vin4;

    
typedef enum _enumOBD1engine{
    eOBD1engine_UNKNOWN = 0,
    eOBD1engine_CNG,
    eOBD1engine_OTHER,
    eOBD1engine_SFI,
    eOBD1engine_TBI,
    eOBD1engine_OTHERS = 0xFE,
    eOBD1engine_MAX = 0xFF
} enumOBD1engine;

    
typedef enum _enumOBD1make{
    eOBD1make_UNKNOWN = 0,
    eOBD1make_BUICK,
    eOBD1make_ISUZU,
    eOBD1make_OTHER,
    eOBD1make_TURBO,
    eOBD1make_OTHERS = 0xFE,
    eOBD1make_MAX = 0xFF
} enumOBD1make;

    
typedef enum _enumOBD1transmission{
    eOBD1transmission_UNKNOWN = 0,
    eOBD1transmission_4L60E_TRANS,
    eOBD1transmission_4L80E_TRANS,
    eOBD1transmission_MANUAL_TRANS,
    eOBD1transmission_OTHER,
    eOBD1transmission_OTHERS = 0xFE,
    eOBD1transmission_MAX = 0xFF
} enumOBD1transmission;

    
typedef enum _enumOBD1vehspeed{
    eOBD1veh_speed_UNKNOWN = 0,
    eOBD1veh_speed_AUTO3SPEED,
    eOBD1veh_speed_AUTO4SPEED,
    eOBD1veh_speed_OTHER,
    eOBD1veh_speed_OTHERS = 0xFE,
    eOBD1veh_speed_MAX = 0xFF
} enumOBD1vehspeed;

    
typedef enum _enumOBD1speeddenLap Dangy{
    eOBD1speeddenLap Dangy_UNKNOWN = 0,
    eOBD1speeddenLap Dangy_NO,
    eOBD1speeddenLap Dangy_YES,
    eOBD1speeddenLap Dangy_OTHERS = 0xFE,
    eOBD1speeddenLap Dangy_MAX = 0xFF
} enumOBD1speeddenLap Dangy;

    
typedef enum _enumOBD1year84_5{
    eOBD1year84_5_UNKNOWN = 0,
    eOBD1year84_5_NO,
    eOBD1year84_5_YES,
    eOBD1year84_5_OTHERS = 0xFE,
    eOBD1year84_5_MAX = 0xFF
} enumOBD1year84_5;

    
typedef enum _enumOBD1maf{
    eOBD1maf_UNKNOWN = 0,
    eOBD1maf_NO,
    eOBD1maf_YES,
    eOBD1maf_OTHERS = 0xFE,
    eOBD1maf_MAX = 0xFF
} enumOBD1maf;

    
typedef enum _enumOBD1federalemission{
    eOBD1federalemission_UNKNOWN = 0,
    eOBD1federalemission_NO,
    eOBD1federalemission_YES,
    eOBD1federalemission_OTHERS = 0xFE,
    eOBD1federalemission_MAX = 0xFF
} enumOBD1federalemission;

    
typedef enum _enumOBD1varfuelvehicle{
    eOBD1varfuelvehicle_UNKNOWN = 0,
    eOBD1varfuelvehicle_NO,
    eOBD1varfuelvehicle_YES,
    eOBD1varfuelvehicle_OTHERS = 0xFE,
    eOBD1varfuelvehicle_MAX = 0xFF
} enumOBD1varfuelvehicle;

    
typedef enum _enumOBD1reatta{
    eOBD1reatta_UNKNOWN = 0,
    eOBD1reatta_NO,
    eOBD1reatta_YES,
    eOBD1reatta_OTHERS = 0xFE,
    eOBD1reatta_MAX = 0xFF
} enumOBD1reatta;

    
typedef enum _enumOBD1vin10_17_val2{
    eOBD1vin10_17_val2_UNKNOWN = 0,
    eOBD1vin10_17_val2_NO,
    eOBD1vin10_17_val2_YES,
    eOBD1vin10_17_val2_OTHERS = 0xFE,
    eOBD1vin10_17_val2_MAX = 0xFF
} enumOBD1vin10_17_val2;


#endif
