#ifndef _GM_VEHICLE_PROFILE_H
#define _GM_VEHICLE_PROFILE_H

typedef struct _structFormatTable
{
    unsigned char StartByte;/*Startbyte use to decode*/
    unsigned char StopByte;/*Number Row of Table DTC*/
} structFormatTable;
typedef struct _structDTCTableProfile
{
    structFormatTable  FormatTable;
    unsigned short const * pTableDTC;
} structDTCTableProfile;

typedef struct _structGMProfile
{
    uint8         CommPin;
    uint16        GMBaudrate;
    unsigned char       AldlID;
    const structDTCTableProfile * pstrt_DTCTableProfile;
} structGMProfile;
#define NA      0

/*DTC table X_Y : Mean  DTC parse code from start byte x                      */
/*Y is Number tables in Same type DTC table                                   */

/*Dtc_Table1_1[37][8]   *//*Start 1- Stop 37*/
/*Dtc_Table1_3[18][8]   *//*Start 1- Stop 18*/
/*Dtc_Table1_4[8][8]   *//*Start 1- Stop 8*/
/*Dtc_Table1_5[2][8]   *//*Start 1- Stop 2*/
/*Dtc_Table1_7[32][8]   *//*Start 1- Stop 32*/
/*Dtc_Table3_1[7][8]   *//*Start 3- Stop 9*/
/*Dtc_Table3_2[5][8]   *//*Start 3- Stop 7*/
/*Dtc_Table3_3[3][8]   *//*Start 3- Stop 5*/
/*Dtc_Table3_4[4][8]   *//*Start 3- Stop 6*/
/*Dtc_Table3_5[7][8]   *//*Start 3- Stop 9*/
/*Dtc_Table3_6[11][8]   *//*Start 3- Stop 13*/
/*Dtc_Table3_11[5][8]   *//*Start 3- Stop 7*/
/*Dtc_Table3_12[4][8]   *//*Start 3- Stop 6*/
/*Dtc_Table3_13[4][8]   *//*Start 3- Stop 6*/
/*Dtc_Table3_14[3][8]   *//*Start 3- Stop 5*/
/*Dtc_Table6_2[9][8]   *//*Start 6- Stop 14*/
/*Dtc_Table6_3[5][8]   *//*Start 6- Stop 10*/
/*Dtc_Table11_1[3][8]   *//*Start 11- Stop 13*/
/*Dtc_Table12_1[3][8]   *//*Start 12- Stop 14*/
/*Dtc_Table12_2[4][8]   *//*Start 12- Stop 15*/
/*Dtc_Table13[6][8]   *//*Start 13- Stop 18*/
/*Dtc_Table15[7][8]   *//*Start 15- Stop 21*/
/*Dtc_Table25[12][8]   *//*Start 25- Stop 36*/
/*Dtc_Table46_1[20][8]   *//*Start 46- Stop 65*/
/*Dtc_Table51[14][8]   *//*Start 51- Stop 64*/

/*GM table have 384 option but have many dupplicate option*/
/*Index of enum below is result of remove duplicate*/
enum
{
    TABLE1,TABLE2_1,TABLE2_2,TABLE2_3,TABLE2_4,TABLE3_1,TABLE3_2,TABLE3_3,TABLE4_1,
    TABLE4_2,TABLE4_3,TABLE4_4,TABLE5_2,TABLE5_1,TABLE5_5,TABLE5_3,TABLE6_1,TABLE6_2,
    TABLE6_3,TABLE7_1,TABLE7_2,TABLE7_3,TABLE7_4,TABLE8_1,TABLE8_2,TABLE8_3,TABLE8_4,
    TABLE8_5,TABLE8_6,TABLE9_1,TABLE9_3,TABLE9_4,TABLE9_6,TABLE9_7,TABLE10_1,TABLE10_3,
    TABLE10_4,TABLE10_5,TABLE10_7,TABLE10_10,TABLE11_1,TABLE11_2,TABLE11_3,TABLE11_4,
    TABLE11_5,TABLE11_8,TABLE11_9,TABLE11_11,TABLE11_15,TABLE11_16,TABLE12_1,TABLE12_2,
    TABLE12_3,TABLE12_4,TABLE12_5,TABLE12_6,TABLE12_7,TABLE12_8,TABLE12_10,TABLE12_11,
    TABLE12_13,TABLE13_1,TABLE13_2,TABLE13_3,TABLE13_4,TABLE13_5,TABLE13_8,TABLE13_9,
    TABLE13_10,TABLE13_13,TABLE13_14,TABLE14_1,TABLE14_2,TABLE14_3,TABLE14_4,TABLE14_5,
    TABLE14_6,TABLE14_9,TABLE15_1,TABLE15_3,TABLE15_4,TABLE15_5,TABLE15_6,TABLE15_7
};
#ifdef _PROC_GM_OBD1_C
#ifdef _NEW_STRUCT_SEARCH
/*use to */
unsigned char const NumberRowDtcTableLUT[84]=//number row of dtc table, number colum alway is 8
{
    3,3,7,3,3,3,7,3,3,3,
    7,6,3,3,3,4,3,3,4,3,
    3,4,3,3,3,3,5,3,4,4,
    4,3,7,20,3,3,4,4,7,11,
    3,3,5,4,4,37,9,12,14,
    11,3,3,4,4,5,4,37,9,14,
    11,2,3,3,4,4,4,2,9,5,
    18,32,3,3,5,4,4,4,8,3,18,
    4,4,12,18
};
unsigned char const StartByteDtcTable[84]=/**/
{
    11,12,15,11,12,12,3,11,12,11,3,13,11,12,11,12,12,11,12,11,12,12,3,12,11,12,3,3,3
    ,12,12,3,3,46,12,3,3,3,3,3,12,3,3,3,3,1,6,25,51,3,12,3,3,3,3,3,1,6,51,3,1,12,3,3,
    3,3,1,6,6,1,1,12,3,3,3,3,3,1,12,1,3,3,25,1
};
unsigned short sDtcTableIndex;
#endif

unsigned short const Dtc_Table1[3][8]=
{
    12,13,14,15,21,22,23,24,
    25,31,32,33,34,35,41,42,
    43,44,45,51,52,53,54,55
};

unsigned short const Dtc_Table1_1[37][8]=//start byte decode 13 14 36 37 , 8bit
{
    13,14,21,22,23,32,33,42,
    44,45,51,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,

    13,14,21,23,24,32,33,42,
    44,45,51,NA,NA,NA,NA,NA
};
unsigned short const Dtc_Table1_3[18][8]=/*Start Byte Decode DTC byte1*/
{
    /*End  Byte Decode DTC byte18*/
    269 , 270 , 271 , 272 , 273 , 274 , 275 , 277 ,
    13 ,  14 ,  15 ,  16 ,  17 ,  18 ,  19 ,  21 ,
    278 , 279 , 280 , 281 , 282 , 283 , 284 , 285 ,
    22 ,  23 ,  24 ,  25 ,  26 ,  27 ,  28 ,  29 ,
    287 , 288 , 289 , 290 , 291 , 292 , 293 , 294 ,

    31 ,  32 ,  33 ,  34 ,  35 ,  36 ,  37 ,  38 ,
    295 , 297 , 298 , 299 , 300 , 301 , 302 , 303 ,
    39 ,  41 ,  42 ,  43 ,  44 ,  45 ,  46 ,  47 ,
    304 , 305 , 307 , 308 , 309 , 310 , 311 , 312 ,
    48 ,  49 ,  51 ,  52 ,  53 ,  54 ,  55 ,  56 ,

    313 , 314 , 315 , 317 , 318 , 319 , 320 , 321 ,
    57 ,  58 ,  59 ,  61 ,  62 ,  63 ,  64 ,  65 ,
    322 , 323 , 324 , 325 , 327 , 328 , 329 , 330 ,
    66 ,  67 ,  68 ,  69 ,  71 ,  72 ,  73 ,  74 ,
    331 , 332 , 333 , 334 , 335 , 337 , 338 , 339 ,

    75 ,  76 ,  77 ,  78 ,  79 ,  81 ,  82 ,  83 ,
    340 , 341 , 342 , 343 , 344 , 345 , 347 , 348 ,
    84 ,  85 ,  86 ,  87 ,  88 ,  89 ,  91 ,  92
};
unsigned short const Dtc_Table1_4[8][8]=/**/
{
    1 ,2 ,3 ,4 ,5 ,6 ,7 ,NA,
    8 ,9 ,10,11,12,13,14,15,
    16,17,18,19,20,21,22,23,
    24,25,26,27,28,29,30,31,
    32,33,34,35,36,37,38,39,

    40,41,42,43,44,45,46,47,
    48,49,50,51,52,53,54,55,
    56,57,58,59,60,61,62,63
};
unsigned short const Dtc_Table1_5[2][8]=
{
    13,14,21,22,23,24,32,33,
    44,45,51,66,19,NA,NA,NA
};

unsigned short const Dtc_Table1_7[32][8]=
{
    12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 ,
    20 ,21 ,22 ,23 ,24 ,25 ,26 ,27 ,
    28 ,29 ,30 ,31 ,32 ,33 ,34 ,35 ,
    36 ,37 ,38 ,39 ,40 ,41 ,42 ,43 ,
    44 ,45 ,46 ,47 ,48 ,49 ,50 ,51 ,

    52 ,53 ,54 ,55 ,56 ,57 ,58 ,59 ,
    60 ,61 ,62 ,63 ,64 ,65 ,66 ,67 ,
    68 ,69 ,70 ,71 ,72 ,73 ,74 ,75 ,
    76 ,77 ,78 ,79 ,80 ,81 ,82 ,83 ,
    84 ,85 ,86 ,87 ,88 ,89 ,90 ,91 ,

    92 ,93 ,94 ,95 ,96 ,97 ,98 ,99 ,
    100,101,102,103,104,105,106,107,
    108,109,110,111,112,113,114,115,
    116,117,118,119,120,121,122,123,
    124,125,126,127,128,129,130,131,

    132,133,134,135,136,137,138,139,
    268,269,270,271,272,273,274,275,
    276,277,278,279,280,281,282,283,
    284,285,286,287,288,289,290,291,
    292,293,294,295,296,297,298,299,

    300,301,302,303,304,305,306,307,
    308,309,310,311,312,313,314,315,
    316,317,318,319,320,321,322,323,
    324,325,326,327,328,329,330,331,
    332,333,334,335,336,337,338,339,

    340,341,342,343,344,345,346,347,
    348,349,350,351,352,353,354,355,
    356,357,358,359,360,361,362,363,
    364,365,366,367,368,369,370,371,
    372,373,374,375,376,377,378,379,

    380,381,382,383,384,385,386,387,
    388,389,390,391,392,393,394,395
};
unsigned short const Dtc_Table1_9[2][8]=
{
    13,14,21,23,24,32,33,42,
//  44,45,51,66,NA,NA,NA,NA
    44,45,51,NA,NA,NA,NA,NA//Feb2610 Si modified as new database
};

unsigned short const Dtc_Table1_10[2][8]=
{
    13,14,21,23,24,32,33,42,
    44,45,51,43,NA,NA,NA,NA//Feb2610 Si modified as new database
};

unsigned short const Dtc_Table1_11[20][8]=
{
    13,14,15,16,17,18,19,21,
    22,23,24,25,26,27,28,29,
    31,32,33,34,35,36,37,38,
    39,41,42,43,44,45,46,47,
    48,49,51,52,53,54,55,56,

    57,58,59,61,62,63,64,65,
    66,67,68,69,71,72,73,74,
    75,76,77,78,79,81,82,83,
    NA,85,86,87,88,89,91,92,
    93,94,95,96,97,98,99,NA,

    13,14,15,16,17,18,19,21,
    22,23,24,25,26,27,28,29,
    31,32,33,34,35,36,37,38,
    39,41,42,43,44,45,46,47,
    48,49,51,52,53,54,55,56,

    57,58,59,61,62,63,64,65,
    66,67,68,69,71,72,73,74,
    75,76,77,78,79,81,82,83,
    NA,85,86,87,88,89,91,92,
    93,94,95,96,97,98,99,NA
};

//----------------------------------------------
unsigned short const Dtc_Table3_1[7][8]=
{
    12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,
    28,29,30,31,32,33,34,35,
    36,37,38,39,40,41,42,43,
    44,45,46,47,48,49,50,51,
    52,53,54,55,56,57,58,59,
    60,61,62,63,64,65,66,67
};
unsigned short const Dtc_Table3_2[5][8]=
{
    12,13,14,15,16,21,22,23,
    24,25,26,31,32,33,34,35,
    36,41,42,43,44,45,46,51,
    52,53,54,55,56,61,62,63,
    64,65,66,NA,NA,NA,NA,NA
};
unsigned short const Dtc_Table3_3[3][8]=
{
    12,13,14,15,21,22,23,24,
    25,31,32,33,34,35,41,42,
    43,44,45,51,52,53,54,55
};
unsigned short const Dtc_Table3_4[4][8]=
{
    12,13,14,15,21,22,23,24,
    25,31,32,33,34,35,41,42,
    43,44,45,46,51,53,54,55,
    46,56,61,62,64,65,66,NA
};
unsigned short const Dtc_Table3_5[7][8]=
{
    12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,
    28,29,30,31,32,33,34,35,
    36,37,38,39,40,41,42,43,
    44,45,46,47,48,49,50,51,

    52,53,54,55,56,57,58,59,
    60,61,62,63,64,65,66,67
};
unsigned short const Dtc_Table3_6[11][8]=
{
    12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,
    28,29,30,31,32,33,34,35,
    36,37,38,39,40,41,42,43,
    44,45,46,47,48,49,50,51,

    52,53,54,55,56,57,58,59,
    60,61,62,63,64,65,66,67,
    68,69,70,71,72,73,74,75,
    76,77,78,79,80,81,82,83,
    84,85,86,87,88,89,90,91,

    92,93,94,95,96,97,98,99

};



unsigned short const Dtc_Table3_11[5][8]=
{
    12,13,14,15,16,21,22,23,
    24,25,26,31,32,33,34,35,
    36,41,42,43,44,45,46,51,
    52,53,54,55,56,61,62,63,
    64,65,66,67,68,69,71,72
};
unsigned short const Dtc_Table3_12[4][8]=
{
    12,13,14,15,21,22,23,24,
    25,31,32,33,34,35,41,42,
    43,44,45,51,52,53,54,55,
    39,61,46,62,36,65,66,56
};
unsigned short const Dtc_Table3_13[4][8]=
{
    12,13,14,15,21,22,23,24,
    25,66,27,33,34,35,26,42,
    43,44,45,51,52,53,28,65,
    NA,NA,71,NA,NA,NA,19,29
};
unsigned short const Dtc_Table3_14[3][8]=
{
    41,13,14,15,21,22,23,24,
    25,66,32,33,34,35,26,42,
    43,44,45,51,31,53,62,65
};
unsigned short const Dtc_Table3_15[4][8]=/*Hungv added 02 Jan 2010 - mask with tool Techforce*/
{
    12,13,14,15,21,22,23,24,
    25,31,32,33,34,35,41,42,
    26,43,44,45,51,53,54,55,
    46,56,61,62,36,NA,66,67
};


//Feb2610 Si added to test new database
unsigned short const Dtc_Table3_16[4][8]=/*Hungv added 02 Jan 2010 - mask with tool Techforce*/
{
    12,13,14,15,NA,21,22,23,
    24,25,NA,NA,32,33,34,NA,
    NA,41,42,43,44,45,46,51,
    52,53,54,NA,NA,NA,62,NA
};

unsigned short const Dtc_Table3_17[11][8]=//Feb2610 Si modified as new database
{
    12,13,14,15,16,17,18,19,
    22,21,22,23,24,NA,26,27,
    28,29,33,31,32,NA,34,NA,
    NA,37,38,39,44,41,42,43,
    44,45,46,47,48,49,55,51,

    52,53,54,55,NA,NA,58,NA,
    68,69,77,71,64,65,66,67,
    27,65,66,67,68,92,77,71,
    NA,NA,74,75,NA,NA,NA,NA,
    88,NA,NA,NA,NA,NA,NA,NA,

    66,67,68,99,NA,NA,NA,NA
};

unsigned short const Dtc_Table3_18[3][8]=//Feb2610 Si modified as new database
{
    12,13,14,15,21,22,23,24,
    25,NA,32,33,34,35,NA,42,
    NA,44,45,51,NA,53,54,55
};

unsigned short const Dtc_Table3_19[4][8]=//Feb2610 Si modified as new database
{
    12,13,14,15,NA,21,22,23,
    24,25,NA,NA,32,33,34,NA,
    NA,41,42,43,44,45,46,51,
    52,53,54,NA,NA,NA,62,NA
};

unsigned short const Dtc_Table3_20[5][8]=//Feb2610 Si added as new database
{
    12,13,14,15,16,21,22,23,
    24,25,NA,31,32,33,34,NA,
    36,41,42,43,44,45,46,51,
    52,53,54,55,56,61,62,63,
    64,65,66,NA,NA,NA,NA,NA
};


unsigned short const Dtc_Table3_21[11][8]=
{
    12,13,14,15,16,17,18,19,//BYTE 3
    22,21,22,23,24,NA,26,27,//BYTE 4
    28,29,33,31,32,NA,34,NA,//BYTE 5
    NA,37,38,39,44,41,42,43,//BYTE 6
    44,45,46,47,48,49,55,51,//BYTE 7
    52,53,54,55,NA,NA,58,NA,//BYTE 8
    64,65,66,67,68,69,77,71,//BYTE 9
    NA,NA,74,75,NA,NA,NA,NA,//BYTE 10
    88,NA,NA,NA,NA,NA,NA,NA,//BYTE 11
    NA,NA,99,91,92,NA,NA,95,//BYTE 12
    92,NA,NA,95,96,97,98,99//BYTE 13
};

unsigned short const Dtc_Table3_22[4][8]=//Feb2610 Si modified as new database
{
    12,13,14,15,NA,21,22,23,
    24,25,NA,NA,32,33,34,NA,
    NA,41,42,43,44,45,NA,51,
    52,53,54,NA,NA,NA,NA,NA
};

unsigned short const Dtc_Table3_23[5][8]=//Feb2610 Si added as new database
{
    12,13,14,15,16,21,22,23,
    24,25,NA,31,32,33,34,35,
    36,41,42,43,44,45,46,51,
    52,53,54,55,56,61,62,63,
    64,65,66,NA,NA,NA,NA,NA
};

unsigned short const Dtc_Table3_24[3][8]=//Feb2610 Si modified as new database
{
    12,13,14,15,21,22,NA,24,
    26,27,32,33,34,38,39,42,
    43,44,45,51,52,NA,54,55
};

unsigned short const Dtc_Table3_25[8][8]=
{
    12,13,14,15,16,17,18,19,//BYTE 3
    22,21,22,23,24,NA,26,27,//BYTE 4
    28,NA,33,31,32,NA,34,NA,//BYTE 5
    NA,37,38,39,44,41,42,43,//BYTE 6
    44,45,46,47,48,NA,55,51,//BYTE 7
    52,53,54,55,NA,57,58,59,//BYTE 8
    66,61,62,63,64,65,66,67,//BYTE 9
    68,69,77,71,NA,73,74,75//BYTE 10
};

unsigned short const Dtc_Table3_26[3][8]=
{
    41,13,14,15,21,22,23,24,
    25,66,NA,33,34,35,26,42,
    43,44,45,51,31,53,62,65
};

unsigned short const Dtc_Table3_27[3][8]=
{
    12,13,14,15,NA,21,22,23,
    24,25,NA,NA,32,33,34,NA,
    NA,NA,42,43,44,45,NA,51
};

unsigned short const Dtc_Table3_28[5][8]=
{
    12,13,14,15,16,21,22,23,
    24,25,26,31,32,33,34,35,
    NA,NA,42,43,44,45,NA,51,
    52,53,54,55,56,61,62,63,
    64,65,66,NA,NA,NA,NA,NA
};

unsigned short const Dtc_Table3_29[4][8]=
{
    12,13,14,15,NA,21,22,23,
    24,25,NA,NA,32,33,34,NA,
    NA,NA,42,43,44,45,NA,51,
    NA,NA,NA,55,NA,NA,NA,NA
};

unsigned short const Dtc_Table3_30[3][8]=
{
    12,13,14,15,21,22,23,24,
    25,NA,32,33,34,35,NA,42,
    NA,44,45,51,NA,NA,NA,55,
};


unsigned short const Dtc_Table3_31[7][8]=
{
    12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,
    28,29,30,31,32,33,34,35,
    36,37,38,39,40,41,42,43,
    44,45,46,47,48,49,50,51,
    52,53,54,55,56,57,58,59,
    60,61,62,63,64,65,66,67
};

//-----------------------------------------
unsigned short const Dtc_Table6_2[9][8]=
{
    13,14,15,16,17,18,19,21,
    22,23,24,25,26,27,28,29,
    31,32,33,34,35,36,37,38,
    39,41,42,43,44,45,46,47,
    48,49,51,52,53,54,55,56,

    57,58,59,61,62,63,64,65,
    66,67,68,69,71,72,73,74,
    75,76,77,78,79,81,82,83,
    84,85,86,87,88,89,91,92
};
unsigned short const Dtc_Table6_3[5][8]=
{
    13,14,15,16,17,18,19,21,
    22,23,24,25,26,27,28,29,
    31,32,33,34,35,36,37,38,
    39,41,42,43,44,45,46,47,
    48,49,51,52,53,54,55,56
};

unsigned short const Dtc_Table6_4[9][8]=
{
    13,14,15,NA,NA,NA,NA,21,
    22,NA,24,NA,NA,NA,28,NA,
    31,32,33,34,NA,NA,37,38,
    39,NA,42,43,44,45,NA,NA,
    NA,NA,51,NA,53,54,55,NA,

    NA,58,59,NA,NA,NA,NA,NA,
    NA,NA,68,69,71,72,73,74,
    75,NA,NA,NA,79,81,82,83,
    NA,58,59,61,NA,63,NA,NA
};

unsigned short const Dtc_Table6_5[5][8]=
{
    13,14,15,16,NA,NA,NA,21,
    22,23,24,25,NA,NA,28,NA,
    31,32,33,34,35,NA,37,38,
    39,41,42,43,44,45,46,NA,
    NA,NA,51,52,53,54,55,NA
};

unsigned short const Dtc_Table6_6[5][8]=
{
    13,14,15,16,NA,NA,NA,21,
    22,23,24,25,NA,NA,28,NA,
    31,32,33,34,35,36,37,38,
    39,41,42,43,44,45,46,NA,
    NA,NA,51,52,53,54,55,NA
};

//-------------------------------------------------

unsigned short const Dtc_Table11_1[3][8]=
{
    12,13,14,15,21,NA,23,24,
    NA,NA,32,NA,34,35,41,42,
    43,44,45,51,52,NA,54,55
};
//-------------------------------------------------
unsigned short const Dtc_Table12_1[3][8]=
{
    12,13,14,15,21,22,23,24,
    25,31,32,33,34,35,41,42,
    43,44,45,51,52,53,54,55
};
unsigned short const Dtc_Table12_2[4][8]=
{
    12,13,14,15,16,21,22,23,
    24,25,26,31,32,33,34,35,
    36,41,42,43,44,45,46,51,
    51,52,53,54,56,61,62,63
};
unsigned short const Dtc_Table13[6][8]=
{
    NA,NA,NA,12,13,14,15,16,
    17,18,19,20,21,22,23,24,
    25,26,27,NA,NA,30,31,32,
    33,34,35,36,37,38,NA,NA,
    NA,NA,NA,44,45,NA,NA,NA,

    NA,NA,51,NA,NA,NA,NA,NA
};
unsigned short const Dtc_Table15[7][8]=
{
    12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,
    28,29,30,31,32,33,34,35,
    36,37,38,39,NA,NA,NA,NA,
    44,45,NA,NA,NA,NA,NA,51,

    52,NA,NA,NA,NA,NA,NA,NA,
    60,61,NA,63,64,65,66,67
};
unsigned short const Dtc_Table25[12][8]=
{
    12,13,14,15,NA,NA,21,22,
    23,24,25,26,27,NA,NA,31,
    32,33,34,35,36,37,38,NA,
    41,NA,NA,NA,51,52,53,54,
    NA,NA,61,62,63,64,65,NA,

    NA,71,72,73,74,NA,NA,NA,
    268,269,270,271,NA,NA,277,278,
    279,280,281,282,283,NA,NA,287,
    288,289,290,291,292,293,294,NA,
    297,NA,NA,NA,307,308,309,310,

    NA,NA,317,318,319,320,321,NA,
    NA,327,328,329,330,NA,NA,NA
};
unsigned short const Dtc_Table46_1[20][8]=
{
    269,270,271,272,273,274,275,277,
    278,279,280,281,282,283,284,285,
    287,288,289,290,291,292,293,294,
    295,297,298,299,300,301,302,303,
    304,305,307,308,309,310,311,312,

    313,314,315,317,318,319,320,321,
    322,323,324,325,327,328,329,330,
    331,332,333,334,335,337,338,339,
    340,341,342,343,344,345,347,348,
    349,350,351,352,353,354,355,NA,

    13,14,15,16,17,18,19,21,
    22,23,24,25,26,27,28,29,
    31,32,33,34,35,36,37,38,
    39,41,42,43,44,45,46,47,
    48,49,51,52,53,54,55,56,

    57,58,59,61,62,63,64,65,
    66,67,68,69,71,72,73,74,
    75,76,77,78,79,81,82,83,
    84,85,86,87,88,89,91,92,
    93,94,95,96,97,98,99,NA

};
//---------------------------------------
unsigned short const Dtc_Table51[14][8]=
{
    269,270,271,272,273,274,275,277,
    278,279,280,281,282,283,284,285,
    287,288,289,290,291,292,293,294,
    295,297,298,299,300,301,302,303,
    304,305,307,308,309,310,311,312,

    313,314,315,317,318,319,320,321,
    322,323,324,325,327,328,329,330,
    13,14,15,16,17,18,19,21,
    22,23,24,25,26,27,28,29,
    31,32,33,34,35,36,37,38,

    39,41,42,43,44,45,46,47,
    48,49,51,52,53,54,55,56,
    57,58,59,61,62,63,64,65,
    66,67,68,69,71,72,73,74
};

unsigned short const Dtc_Table51_B[2][8]=
{
    13,14,21,23,24,32,33,42,
    44,45,51,66,NA,NA,NA,NA
};

unsigned short const Dtc_Table51_1[2][8]=
{
    13,14,21,23,24,32,33,NA,
    44,45,51,66,NA,NA,NA,NA
};

unsigned short const Dtc_Table51_2[12][8]=
{
    13,14,15,16,17,NA,NA,21,
    22,23,24,25,26,27,28,29,
    31,NA,NA,34,NA,36,24,38,
    39,41,42,43,44,45,NA,47,
    NA,NA,51,NA,NA,NA,NA,NA,
    NA,58,66,61,62,63,64,NA,
    88,NA,67,68,65,69,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    NA,NA,NA,NA,NA,NA,NA,NA,
    13,14,15,16,17,NA,NA,21,
    22,23,24,25,26,27,28,29,
    31,NA,NA,34,NA,36,24,38
};
//-------------------------------
unsigned short const Dtc_Table53[5][8]=
{
    12,13,14,15,16,21,22,23,
    24,25,NA,31,32,33,34,35,
    36,41,42,43,44,45,46,51,
    52,53,54,55,56,61,62,63,
    64,65,66,NA,NA,NA,NA,NA
};

unsigned short const Dtc_Table53_1[5][8]=
{
    12,13,14,15,16,21,22,23,
    24,25,26,27,28,32,33,34,
    36,41,42,43,44,45,46,51,
    52,53,NA,55,NA,61,62,63,
    64,65,66,67,68,69,71,72
};

//----------------------------------------------------------------------------
/******************************************************************************/

structDTCTableProfile strtDTCTableProfile1 =
{
    {9,11},
    &Dtc_Table1[0][0]
};

structDTCTableProfile strtDTCTableProfile1_1 =
{
    {1,37},
    &Dtc_Table1_1[0][0]
};
structDTCTableProfile strtDTCTableProfile1_3 =
{
    {1,18},
    &Dtc_Table1_3[0][0]
};
structDTCTableProfile strtDTCTableProfile1_4 =
{
    {1,8},
    &Dtc_Table1_4[0][0]
};
structDTCTableProfile strtDTCTableProfile1_5 =
{
    {1,2},
    &Dtc_Table1_5[0][0]
};
structDTCTableProfile strtDTCTableProfile1_7 =
{
    {1,32},
    &Dtc_Table1_7[0][0]
};

structDTCTableProfile strtDTCTableProfile1_9 =
{
    {1,2},
    &Dtc_Table1_9[0][0]
};

structDTCTableProfile strtDTCTableProfile1_10 =
{
    {1,2},
    &Dtc_Table1_10[0][0]
};

structDTCTableProfile strtDTCTableProfile1_11=
{
    {1,20},
    &Dtc_Table1_11[0][0]
};

//-----------------------------------------
structDTCTableProfile strtDTCTableProfile3_1 =
{
    {3,9},
    &Dtc_Table3_1[0][0]
};
structDTCTableProfile strtDTCTableProfile3_2 =
{
    {3,7},
    &Dtc_Table3_2[0][0]
};
structDTCTableProfile strtDTCTableProfile3_3 =
{
    {3,5},
    &Dtc_Table3_3[0][0]
};
structDTCTableProfile strtDTCTableProfile3_4 =
{
    {3,6},
    &Dtc_Table3_4[0][0]
};
structDTCTableProfile strtDTCTableProfile3_5 =
{
    {3,9},
    &Dtc_Table3_5[0][0]
};
structDTCTableProfile strtDTCTableProfile3_6 =
{
    {3,13},
    &Dtc_Table3_6[0][0]
};
structDTCTableProfile strtDTCTableProfile3_11 =
{
    {3,7},
    &Dtc_Table3_11[0][0]
};
structDTCTableProfile strtDTCTableProfile3_12 =
{
    {3,6},
    &Dtc_Table3_12[0][0]
};
structDTCTableProfile strtDTCTableProfile3_13 =
{
    {3,6},
    &Dtc_Table3_13[0][0]
};
structDTCTableProfile strtDTCTableProfile3_14 =
{
    {3,5},
    &Dtc_Table3_14[0][0]
};
structDTCTableProfile strtDTCTableProfile3_15 =
{
    {3,6},
    &Dtc_Table3_15[0][0]
};

structDTCTableProfile strtDTCTableProfile3_16 =
{
    {3,6},
//&Dtc_Table3_2[0][0]
    &Dtc_Table3_16[0][0]//Feb2610 Si modified as new database
};

structDTCTableProfile strtDTCTableProfile3_17 =
{
    {3,13},
    &Dtc_Table3_17[0][0]//Feb2610 Si modified as new database
};

//Feb2610 Si modified to test new database

structDTCTableProfile strtDTCTableProfile3_18 =
{
    {3,5},
    &Dtc_Table3_18[0][0]
};


structDTCTableProfile strtDTCTableProfile3_19 =
{
    {3,6},
    &Dtc_Table3_19[0][0]
};

structDTCTableProfile strtDTCTableProfile3_20 =
{
    {3,7},
    &Dtc_Table3_20[0][0]
};


structDTCTableProfile strtDTCTableProfile3_21 =
{
    {3,13},
    &Dtc_Table3_21[0][0]
};


structDTCTableProfile strtDTCTableProfile3_22 =
{
    {3,6},
    &Dtc_Table3_22[0][0]
};

structDTCTableProfile strtDTCTableProfile3_23 =
{
    {3,7},
    &Dtc_Table3_23[0][0]
};

structDTCTableProfile strtDTCTableProfile3_24 =
{
    {3,5},
    &Dtc_Table3_24[0][0]
};

structDTCTableProfile strtDTCTableProfile3_25 =
{
    {3,10},
    &Dtc_Table3_25[0][0]
};

structDTCTableProfile strtDTCTableProfile3_26 =
{
    {3,5},
    &Dtc_Table3_26[0][0]
};

structDTCTableProfile strtDTCTableProfile3_27 =
{
    {3,5},
    &Dtc_Table3_27[0][0]
};

structDTCTableProfile strtDTCTableProfile3_28 =
{
    {3,7},
    &Dtc_Table3_28[0][0]
};

structDTCTableProfile strtDTCTableProfile3_29 =
{
    {3,6},
    &Dtc_Table3_29[0][0]
};

structDTCTableProfile strtDTCTableProfile3_30 =
{
    {3,5},
    &Dtc_Table3_30[0][0]
};

structDTCTableProfile strtDTCTableProfile3_31 =
{
    {0,6},
    &Dtc_Table3_31[0][0]
};

/////////////////////////////////////////
structDTCTableProfile strtDTCTableProfile6_2 =
{
    {6,14},
    &Dtc_Table6_2[0][0]
};
structDTCTableProfile strtDTCTableProfile6_3 =
{
    {6,10},
    &Dtc_Table6_3[0][0]
};

structDTCTableProfile strtDTCTableProfile6_4 =
{
    {6,14},
    &Dtc_Table6_4[0][0]
};


structDTCTableProfile strtDTCTableProfile6_5 =
{
    {6,10},
    &Dtc_Table6_5[0][0]
};

structDTCTableProfile strtDTCTableProfile6_6 =
{
    {6,10},
    &Dtc_Table6_6[0][0]
};

//---------------------------------------

structDTCTableProfile strtDTCTableProfile10 =
{
    {11,13},
    &Dtc_Table11_1[0][0]
};
//---------------------------------------
structDTCTableProfile strtDTCTableProfile11_1 =
{
    {11,13},
    &Dtc_Table11_1[0][0]
};
structDTCTableProfile strtDTCTableProfile12_1 =
{
    {12,14},
    &Dtc_Table12_1[0][0]
};
structDTCTableProfile strtDTCTableProfile12_2 =
{
    {12,15},
    &Dtc_Table12_2[0][0]
};
structDTCTableProfile strtDTCTableProfile13 =
{
    {13,18},
    &Dtc_Table13[0][0]
};
structDTCTableProfile strtDTCTableProfile15 =
{
    {15,21},
    &Dtc_Table15[0][0]
};
structDTCTableProfile strtDTCTableProfile25 =
{
    {25,36},
    &Dtc_Table25[0][0]
};
structDTCTableProfile strtDTCTableProfile46_1 =
{
    {46,65},
    &Dtc_Table46_1[0][0]
};
//---------------------------------------
structDTCTableProfile strtDTCTableProfile51 =
{
    {51,64},
    &Dtc_Table51[0][0]
};

structDTCTableProfile strtDTCTableProfile51_B =
{
    {51,52},
    &Dtc_Table51_B[0][0]
};

structDTCTableProfile strtDTCTableProfile51_1 =
{
    {51,52},
    &Dtc_Table51_1[0][0]
};

structDTCTableProfile strtDTCTableProfile51_2 =
{
    {51,62},
    &Dtc_Table51_2[0][0]
};

//--------------------------------

structDTCTableProfile strtDTCTableProfile53 =
{
    {53,57},
    &Dtc_Table53[0][0]
};

structDTCTableProfile strtDTCTableProfile53_1 =
{
    {53,57},
    &Dtc_Table53_1[0][0]
};

/******************************************************************************/
const structGMProfile GMProfile_0=
{
    PIN_D,
    BAUDRATE80,
    NA,
    &strtDTCTableProfile11_1
};

const structGMProfile GMProfile_1=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_2=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile15
};
const structGMProfile GMProfile_3=
{
    PIN_D,
    BAUDRATE80,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_4=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_5=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_6=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile3_1
};
const structGMProfile GMProfile_7=
{
    PIN_D,
    BAUDRATE80,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_8=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_9=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_10=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile3_1
};
const structGMProfile GMProfile_11=
{
    PIN_D,
    BAUDRATE80,
    NA,
    &strtDTCTableProfile13
};
const structGMProfile GMProfile_12=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_13=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_14=
{
    PIN_D,
    BAUDRATE80,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_15=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_2
};
const structGMProfile GMProfile_16=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_17=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_18=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_2
};
const structGMProfile GMProfile_19=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_20=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_21=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_2
};
const structGMProfile GMProfile_22=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_23=
{
    PIN_D,
    BAUDRATE100,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_24=
{
    PIN_D,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile11_1
};
const structGMProfile GMProfile_25=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_26=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_2
};
const structGMProfile GMProfile_27=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_28=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_4
};
const structGMProfile GMProfile_29=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_15
};
const structGMProfile GMProfile_30=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_2
};
const structGMProfile GMProfile_31=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_32=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_5
};
const structGMProfile GMProfile_33=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile46_1
};
const structGMProfile GMProfile_34=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_35=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_36=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_4
};
const structGMProfile GMProfile_37=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_14
};
const structGMProfile GMProfile_38=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_16
};
const structGMProfile GMProfile_39=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_6
};

const structGMProfile GMProfile_40=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_41=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_42=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_2
};
const structGMProfile GMProfile_43=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_4
};
const structGMProfile GMProfile_44=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_14
};
const structGMProfile GMProfile_45=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_1
};
const structGMProfile GMProfile_46=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_2
};
const structGMProfile GMProfile_47=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile25
};
const structGMProfile GMProfile_48=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile51
};
const structGMProfile GMProfile_49=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_6
};

const structGMProfile GMProfile_50=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_51=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_52=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_4/*Hung fixed 02 Feb 2010 to match with Tool techforce and 3140 tool*/
};
const structGMProfile GMProfile_53=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_14
};
const structGMProfile GMProfile_54=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_11
};
const structGMProfile GMProfile_55=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_12
};
const structGMProfile GMProfile_56=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_1
};
const structGMProfile GMProfile_57=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_2
};
const structGMProfile GMProfile_58=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile51
};
const structGMProfile GMProfile_59=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_6
};
const structGMProfile GMProfile_60=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_5
};

const structGMProfile GMProfile_61=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_62=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_63=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_4
};
const structGMProfile GMProfile_64=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_12
};
const structGMProfile GMProfile_65=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_13
};
const structGMProfile GMProfile_66=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_5
};
const structGMProfile GMProfile_67=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_2
};
const structGMProfile GMProfile_68=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_3
};
const structGMProfile GMProfile_69=
{
    PIN_M,
    BAUDRATE8192,
    0xF5,
    &strtDTCTableProfile1_3
};
const structGMProfile GMProfile_70=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_7
};

const structGMProfile GMProfile_71=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_72=
{
    PIN_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_3
};
const structGMProfile GMProfile_73=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_11
};
const structGMProfile GMProfile_74=
{
    PIN_M,
    BAUDRATE8192,
    0xF5,
    &strtDTCTableProfile3_13
};
const structGMProfile GMProfile_75=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_13
};
const structGMProfile GMProfile_76=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_12
};
const structGMProfile GMProfile_77=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_4
};


const structGMProfile GMProfile_78=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile12_1
};
const structGMProfile GMProfile_79=
{
    PIN_M,
    BAUDRATE8192,
    0xF5,
    &strtDTCTableProfile1_3
};
const structGMProfile GMProfile_80=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_13
};
const structGMProfile GMProfile_81=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_12
};
const structGMProfile GMProfile_82=
{
    PIN_M,
    BAUDRATE8192,
    0xF1,
    &strtDTCTableProfile25
};
const structGMProfile GMProfile_83=
{
    PIN_M,
    BAUDRATE8192,
    0xF5,
    &strtDTCTableProfile1_3
};
//Feb2610 Si added to test new database
const structGMProfile GMProfile_84=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_21
};

const structGMProfile GMProfile_85 =
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_9
};

const structGMProfile GMProfile_86=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_17
};

const structGMProfile GMProfile_87=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_20
};

const structGMProfile GMProfile_88=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_18
};

const structGMProfile GMProfile_89=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_21
};

const structGMProfile GMProfile_90=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_19
};


const structGMProfile GMProfile_91=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_4
};

const structGMProfile GMProfile_92=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile51_B
};

const structGMProfile GMProfile_93=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_9
};

const structGMProfile GMProfile_94=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_21
};

const structGMProfile GMProfile_95=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_19
};

const structGMProfile GMProfile_96=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_10
};

const structGMProfile GMProfile_97=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile51_1
};

const structGMProfile GMProfile_98=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile53
};

const structGMProfile GMProfile_99=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile53_1
};


const structGMProfile GMProfile_100=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_22
};

const structGMProfile GMProfile_101=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_10
};

const structGMProfile GMProfile_102=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_5
};

const structGMProfile GMProfile_103=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_23
};

const structGMProfile GMProfile_104=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_24
};

const structGMProfile GMProfile_105=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile3_25
};

const structGMProfile GMProfile_106=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile1_11
};

const structGMProfile GMProfile_107=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile6_6
};

const structGMProfile GMProfile_108=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_19
};

const structGMProfile GMProfile_109=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_26
};

const structGMProfile GMProfile_110=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_27
};

const structGMProfile GMProfile_111=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_28
};

const structGMProfile GMProfile_112=
{
    PIN_M,
    BAUDRATE8192,
    0xF4,
    &strtDTCTableProfile51_2
};

const structGMProfile GMProfile_113=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_29
};

const structGMProfile GMProfile_114=
{
    PIN_L_M,
    BAUDRATE8192,
    0xF0,
    &strtDTCTableProfile3_30
};

const structGMProfile GMProfile_115=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile1
};

const structGMProfile GMProfile_116=
{
    PIN_E,
    BAUDRATE160,
    0xFF,       /*Sent pulse when reading dtc 160 baud*/
    &strtDTCTableProfile3_31
};
const structGMProfile GMProfile_117=
{
    PIN_E,
    BAUDRATE160,
    NA,
    &strtDTCTableProfile3_31
};

/******************************************************************************/
const structGMProfile *pGMProfile[]=
{
    &GMProfile_0,&GMProfile_1,&GMProfile_2,&GMProfile_3,
    &GMProfile_4,&GMProfile_5,&GMProfile_6,&GMProfile_7,
    &GMProfile_8,&GMProfile_9,&GMProfile_10,&GMProfile_11,
    &GMProfile_12,&GMProfile_13,&GMProfile_14,&GMProfile_15,
    &GMProfile_16,&GMProfile_17,&GMProfile_18,&GMProfile_19,
    &GMProfile_20,&GMProfile_21,&GMProfile_22,&GMProfile_23,
    &GMProfile_24,&GMProfile_25,&GMProfile_26,&GMProfile_27,
    &GMProfile_28,&GMProfile_29,&GMProfile_30,&GMProfile_31,
    &GMProfile_32,&GMProfile_33,&GMProfile_34,&GMProfile_35,
    &GMProfile_36,&GMProfile_37,&GMProfile_38,&GMProfile_39,
    &GMProfile_40,&GMProfile_41,&GMProfile_42,&GMProfile_43,
    &GMProfile_44,&GMProfile_45,&GMProfile_46,&GMProfile_47,
    &GMProfile_48,&GMProfile_49,&GMProfile_50,&GMProfile_51,
    &GMProfile_52,&GMProfile_53,&GMProfile_54,&GMProfile_55,
    &GMProfile_56,&GMProfile_57,&GMProfile_58,&GMProfile_59,
    &GMProfile_60,&GMProfile_61,&GMProfile_62,&GMProfile_63,
    &GMProfile_64,&GMProfile_65,&GMProfile_66,&GMProfile_67,
    &GMProfile_68,&GMProfile_69,&GMProfile_70,&GMProfile_71,
    &GMProfile_72,&GMProfile_73,&GMProfile_74,&GMProfile_75,
    &GMProfile_76,&GMProfile_77,&GMProfile_78,&GMProfile_79,
    &GMProfile_80,&GMProfile_81,&GMProfile_82,&GMProfile_83,
    &GMProfile_84,&GMProfile_85,&GMProfile_86,&GMProfile_87,
    &GMProfile_88,&GMProfile_89,&GMProfile_90,&GMProfile_91,
    &GMProfile_92,&GMProfile_93,&GMProfile_94,&GMProfile_95,
    &GMProfile_96,&GMProfile_97,&GMProfile_98,&GMProfile_99,
    &GMProfile_100,&GMProfile_101,&GMProfile_102,&GMProfile_103,
    &GMProfile_104,&GMProfile_105,&GMProfile_106,&GMProfile_107,
    &GMProfile_108,&GMProfile_109,&GMProfile_110,&GMProfile_111,
    &GMProfile_112,&GMProfile_113,&GMProfile_114,&GMProfile_115,
    &GMProfile_116,&GMProfile_117
};
structDTCTableProfile *listtable[]=
{
		&strtDTCTableProfile1 ,
		&strtDTCTableProfile1_1 ,
		&strtDTCTableProfile1_3 ,
		&strtDTCTableProfile1_4 ,
		&strtDTCTableProfile1_5 ,
		&strtDTCTableProfile1_7 ,
		&strtDTCTableProfile1_9 ,
		&strtDTCTableProfile1_10 ,
		&strtDTCTableProfile1_11,
		&strtDTCTableProfile3_1 ,
		&strtDTCTableProfile3_2 ,
		&strtDTCTableProfile3_3 ,
		&strtDTCTableProfile3_4 ,
		&strtDTCTableProfile3_5 ,
		&strtDTCTableProfile3_6 ,
		&strtDTCTableProfile3_11 ,
		&strtDTCTableProfile3_12 ,
		&strtDTCTableProfile3_13 ,
		&strtDTCTableProfile3_14 ,
		&strtDTCTableProfile3_15 ,
		&strtDTCTableProfile3_16 ,
		&strtDTCTableProfile3_17 ,
		&strtDTCTableProfile3_18 ,
		&strtDTCTableProfile3_19 ,
		&strtDTCTableProfile3_20 ,
		&strtDTCTableProfile3_21 ,
		&strtDTCTableProfile3_22 ,
		&strtDTCTableProfile3_23 ,
		&strtDTCTableProfile3_24 ,
		&strtDTCTableProfile3_25 ,
		&strtDTCTableProfile3_26 ,
		&strtDTCTableProfile3_27 ,
		&strtDTCTableProfile3_28 ,
		&strtDTCTableProfile3_29 ,
		&strtDTCTableProfile3_30 ,
		&strtDTCTableProfile3_31 ,
		&strtDTCTableProfile6_2 ,
		&strtDTCTableProfile6_3 ,
		&strtDTCTableProfile6_4 ,
		&strtDTCTableProfile6_5 ,
		&strtDTCTableProfile6_6 ,
		&strtDTCTableProfile10 ,
		&strtDTCTableProfile11_1 ,
		&strtDTCTableProfile12_1 ,
		&strtDTCTableProfile12_2 ,
		&strtDTCTableProfile13 ,
		&strtDTCTableProfile15 ,
		&strtDTCTableProfile25 ,
		&strtDTCTableProfile46_1 ,
		&strtDTCTableProfile51 ,
		&strtDTCTableProfile51_B ,
		&strtDTCTableProfile51_1 ,
		&strtDTCTableProfile51_2 ,
		&strtDTCTableProfile53 ,
		&strtDTCTableProfile53_1 ,
		0
};
char* pliststring[]=
{
		"strtDTCTableProfile1",
		"strtDTCTableProfile1_1",
		"strtDTCTableProfile1_3",
		"strtDTCTableProfile1_4",
		"strtDTCTableProfile1_5",
		"strtDTCTableProfile1_7",
		"strtDTCTableProfile1_9",
		"strtDTCTableProfile1_10",
		"strtDTCTableProfile1_11",
		"strtDTCTableProfile3_1",
		"strtDTCTableProfile3_2",
		"strtDTCTableProfile3_3",
		"strtDTCTableProfile3_4",
		"strtDTCTableProfile3_5",
		"strtDTCTableProfile3_6",
		"strtDTCTableProfile3_11",
		"strtDTCTableProfile3_12",
		"strtDTCTableProfile3_13",
		"strtDTCTableProfile3_14",
		"strtDTCTableProfile3_15",
		"strtDTCTableProfile3_16",
		"strtDTCTableProfile3_17",
		"strtDTCTableProfile3_18",
		"strtDTCTableProfile3_19",
		"strtDTCTableProfile3_20",
		"strtDTCTableProfile3_21",
		"strtDTCTableProfile3_22",
		"strtDTCTableProfile3_23",
		"strtDTCTableProfile3_24",
		"strtDTCTableProfile3_25",
		"strtDTCTableProfile3_26",
		"strtDTCTableProfile3_27",
		"strtDTCTableProfile3_28",
		"strtDTCTableProfile3_29",
		"strtDTCTableProfile3_30",
		"strtDTCTableProfile3_31",
		"strtDTCTableProfile6_2",
		"strtDTCTableProfile6_3",
		"strtDTCTableProfile6_4",
		"strtDTCTableProfile6_5",
		"strtDTCTableProfile6_6",
		"strtDTCTableProfile10",
		"strtDTCTableProfile11_1",
		"strtDTCTableProfile12_1",
		"strtDTCTableProfile12_2",
		"strtDTCTableProfile13",
		"strtDTCTableProfile15",
		"strtDTCTableProfile25",
		"strtDTCTableProfile46_1",
		"strtDTCTableProfile51",
		"strtDTCTableProfile51_B",
		"strtDTCTableProfile51_1",
		"strtDTCTableProfile51_2",
		"strtDTCTableProfile53",
		"strtDTCTableProfile53_1",
		null
};
#else

extern unsigned short const Dtc_Table1[3][8];
extern unsigned short const Dtc_Table1_1[37][8];//start byte decode 13 14 36 37 , 8bit
extern unsigned short const Dtc_Table1_3[18][8];/*Start Byte Decode DTC byte1*/
extern unsigned short const Dtc_Table1_4[8][8];/**/
extern unsigned short const Dtc_Table1_5[2][8];
extern unsigned short const Dtc_Table1_7[32][8];
extern unsigned short const Dtc_Table1_9[2][8];
extern unsigned short const Dtc_Table1_10[2][8];
extern unsigned short const Dtc_Table1_11[20][8];
extern unsigned short const Dtc_Table3_1[7][8];
extern unsigned short const Dtc_Table3_2[5][8];
extern unsigned short const Dtc_Table3_3[3][8];
extern unsigned short const Dtc_Table3_4[4][8];
extern unsigned short const Dtc_Table3_5[7][8];
extern unsigned short const Dtc_Table3_6[11][8];
extern unsigned short const Dtc_Table3_11[5][8];
extern unsigned short const Dtc_Table3_12[4][8];
extern unsigned short const Dtc_Table3_13[4][8];
extern unsigned short const Dtc_Table3_14[3][8];
extern unsigned short const Dtc_Table3_15[4][8];/*Hungv added 02 Jan 2010 - mask with tool Techforce*/
extern unsigned short const Dtc_Table3_16[4][8];/*Hungv added 02 Jan 2010 - mask with tool Techforce*/
extern unsigned short const Dtc_Table3_17[11][8];//Feb2610 Si modified as new database
extern unsigned short const Dtc_Table3_18[3][8];//Feb2610 Si modified as new database
extern unsigned short const Dtc_Table3_19[4][8];//Feb2610 Si modified as new database
extern unsigned short const Dtc_Table3_20[5][8];//Feb2610 Si added as new database
extern unsigned short const Dtc_Table3_21[11][8];
extern unsigned short const Dtc_Table3_22[4][8];//Feb2610 Si modified as new database
extern unsigned short const Dtc_Table3_23[5][8];//Feb2610 Si added as new database
extern unsigned short const Dtc_Table3_24[3][8];//Feb2610 Si modified as new database
extern unsigned short const Dtc_Table3_25[8][8];
extern unsigned short const Dtc_Table3_26[3][8];
extern unsigned short const Dtc_Table3_27[3][8];
extern unsigned short const Dtc_Table3_28[5][8];
extern unsigned short const Dtc_Table3_29[4][8];
extern unsigned short const Dtc_Table3_30[3][8];
extern unsigned short const Dtc_Table3_31[7][8];
extern unsigned short const Dtc_Table6_2[9][8];
extern unsigned short const Dtc_Table6_3[5][8];
extern unsigned short const Dtc_Table6_4[9][8];
extern unsigned short const Dtc_Table6_5[5][8];
extern unsigned short const Dtc_Table6_6[5][8];
extern unsigned short const Dtc_Table11_1[3][8];
extern unsigned short const Dtc_Table12_1[3][8];
extern unsigned short const Dtc_Table12_2[4][8];
extern unsigned short const Dtc_Table13[6][8];
extern unsigned short const Dtc_Table15[7][8];
extern unsigned short const Dtc_Table25[12][8];
extern unsigned short const Dtc_Table46_1[20][8];
extern unsigned short const Dtc_Table51[14][8];
extern unsigned short const Dtc_Table51_B[2][8];
extern unsigned short const Dtc_Table51_1[2][8];
extern unsigned short const Dtc_Table51_2[12][8];
extern unsigned short const Dtc_Table53[5][8];
extern unsigned short const Dtc_Table53_1[5][8];

extern const structGMProfile GMProfile_0;
extern const structGMProfile GMProfile_1;
extern const structGMProfile GMProfile_2;
extern const structGMProfile GMProfile_3;
extern const structGMProfile GMProfile_4;
extern const structGMProfile GMProfile_5;
extern const structGMProfile GMProfile_6;
extern const structGMProfile GMProfile_7;
extern const structGMProfile GMProfile_8;
extern const structGMProfile GMProfile_9;
extern const structGMProfile GMProfile_10;
extern const structGMProfile GMProfile_11;
extern const structGMProfile GMProfile_12;
extern const structGMProfile GMProfile_13;
extern const structGMProfile GMProfile_14;
extern const structGMProfile GMProfile_15;
extern const structGMProfile GMProfile_16;
extern const structGMProfile GMProfile_17;
extern const structGMProfile GMProfile_18;
extern const structGMProfile GMProfile_19;
extern const structGMProfile GMProfile_20;
extern const structGMProfile GMProfile_21;
extern const structGMProfile GMProfile_22;
extern const structGMProfile GMProfile_23;
extern const structGMProfile GMProfile_24;
extern const structGMProfile GMProfile_25;
extern const structGMProfile GMProfile_26;
extern const structGMProfile GMProfile_27;
extern const structGMProfile GMProfile_28;
extern const structGMProfile GMProfile_29;
extern const structGMProfile GMProfile_30;
extern const structGMProfile GMProfile_31;
extern const structGMProfile GMProfile_32;
extern const structGMProfile GMProfile_33;
extern const structGMProfile GMProfile_34;
extern const structGMProfile GMProfile_35;
extern const structGMProfile GMProfile_36;
extern const structGMProfile GMProfile_37;
extern const structGMProfile GMProfile_38;
extern const structGMProfile GMProfile_39;
extern const structGMProfile GMProfile_40;
extern const structGMProfile GMProfile_41;
extern const structGMProfile GMProfile_42;
extern const structGMProfile GMProfile_43;
extern const structGMProfile GMProfile_44;
extern const structGMProfile GMProfile_45;
extern const structGMProfile GMProfile_46;
extern const structGMProfile GMProfile_47;
extern const structGMProfile GMProfile_48;
extern const structGMProfile GMProfile_49;
extern const structGMProfile GMProfile_50;
extern const structGMProfile GMProfile_51;
extern const structGMProfile GMProfile_52;
extern const structGMProfile GMProfile_53;
extern const structGMProfile GMProfile_54;
extern const structGMProfile GMProfile_55;
extern const structGMProfile GMProfile_56;
extern const structGMProfile GMProfile_57;
extern const structGMProfile GMProfile_58;
extern const structGMProfile GMProfile_59;
extern const structGMProfile GMProfile_60;
extern const structGMProfile GMProfile_61;
extern const structGMProfile GMProfile_62;
extern const structGMProfile GMProfile_63;
extern const structGMProfile GMProfile_64;
extern const structGMProfile GMProfile_65;
extern const structGMProfile GMProfile_66;
extern const structGMProfile GMProfile_67;
extern const structGMProfile GMProfile_68;
extern const structGMProfile GMProfile_69;
extern const structGMProfile GMProfile_70;
extern const structGMProfile GMProfile_71;
extern const structGMProfile GMProfile_72;
extern const structGMProfile GMProfile_73;
extern const structGMProfile GMProfile_74;
extern const structGMProfile GMProfile_75;
extern const structGMProfile GMProfile_76;
extern const structGMProfile GMProfile_77;
extern const structGMProfile GMProfile_78;
extern const structGMProfile GMProfile_79;
extern const structGMProfile GMProfile_80;
extern const structGMProfile GMProfile_81;
extern const structGMProfile GMProfile_82;
extern const structGMProfile GMProfile_83;
extern const structGMProfile GMProfile_84;
extern const structGMProfile GMProfile_85;
extern const structGMProfile GMProfile_86;
extern const structGMProfile GMProfile_87;
extern const structGMProfile GMProfile_88;
extern const structGMProfile GMProfile_89;
extern const structGMProfile GMProfile_90;
extern const structGMProfile GMProfile_91;
extern const structGMProfile GMProfile_92;
extern const structGMProfile GMProfile_93;
extern const structGMProfile GMProfile_94;
extern const structGMProfile GMProfile_95;
extern const structGMProfile GMProfile_96;
extern const structGMProfile GMProfile_97;
extern const structGMProfile GMProfile_98;
extern const structGMProfile GMProfile_99;
extern const structGMProfile GMProfile_100;
extern const structGMProfile GMProfile_101;
extern const structGMProfile GMProfile_102;
extern const structGMProfile GMProfile_103;
extern const structGMProfile GMProfile_104;
extern const structGMProfile GMProfile_105;
extern const structGMProfile GMProfile_106;
extern const structGMProfile GMProfile_107;
extern const structGMProfile GMProfile_108;
extern const structGMProfile GMProfile_109;
extern const structGMProfile GMProfile_110;
extern const structGMProfile GMProfile_111;
extern const structGMProfile GMProfile_112;
extern const structGMProfile GMProfile_113;
extern const structGMProfile GMProfile_114;
extern const structGMProfile GMProfile_115;
extern const structGMProfile GMProfile_116;
extern const structGMProfile GMProfile_117;
extern const structGMProfile *pGMProfile[];

#endif
//#ifdef _NEW_STRUCT_SEARCH
//extern unsigned char const NumberRowDtcTableLUT[84];
//extern unsigned char const StartByteDtcTable[84];
//extern unsigned short sDtcTableIndex;
//
//#endif

#endif
