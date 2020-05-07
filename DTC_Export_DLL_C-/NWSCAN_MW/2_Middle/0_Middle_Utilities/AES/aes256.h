/*
Name: 1- Network Scan
2- YMME
3- DTC definition for all Makes
4- Hybrid Test
5- Trip Cycle
6- Active Test
7- Special Function
8- Oil Reset
9- DLC locator
10- VIN Decode
11- Battery Reset
Version: V01.00.00    		Date: Sep 23, 2014		Log: Initial release for all 1,2,3,4,5,6,7,8,9,10,11(key doc V01.00.07 Sep 23,2014)
*/
typedef enum 
{
    NWS =1,
    YMME =2,
    DTC_DEF_ALL_MAKE =3,
    HYBRID =4,
    TRIPCYCLE =5,
    ACTIVETEST =6,
    SPECIALFUNCTION =7,
    OILRESET=8,
    DLCLOCATOR=9,
    VINDECOD=10,
    BATTERYRESET=11

}enumKeyType;

extern int VDS_aes_encrypt( enumKeyType eKeyType, unsigned char* input, unsigned char* output, int length);
extern int VDS_aes_decrypt (enumKeyType eKeyType, unsigned char* input, unsigned char* output, int length );
    