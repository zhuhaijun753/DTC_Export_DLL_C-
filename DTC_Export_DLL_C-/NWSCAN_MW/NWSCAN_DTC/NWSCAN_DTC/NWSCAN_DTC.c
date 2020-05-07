// NWSCAN_DTC.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include <iostream>
//#include <fstream>
#include "stdio.h"
#include "NWSCAN_APP\LIB\PlatFormType.h"
#include <NWSCAN_APP\LIB\SYS_Utility.h>

#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\ff.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\enums.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMMESelection.h>
#include <1_Application\3_User_Interface\3_UI_Processes\Processes\04_YMME_Selection\YMME_Structure.h>
#include <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Structure.h>

#include "NWSCAN_APP\MW_LIB\Makes_Adapter_App.h"
#include <2_Middle\0_Middle_Utilities\AES\aes256.h>
#include <stdlib.h>
#include <D:\[INNOVA]_DLL PC-Link\DTC\Release\DTC_APP\DTC_Adapter_App.h>
#include <NWSCAN_APP\MW_LIB\Makes_Adapter_App.h>

//VDS_aes_decrypt(enumKeyType eKeyType, unsigned char* input, unsigned char* output, int length);
//typedef int(__cdecl *VDS_aes_decrypt)(enumKeyType eKeyType, unsigned char* input, unsigned char* output, int length);


#pragma pack(push,1)
typedef struct _structOEMDTCBufferTest
{
#ifdef _MSC_VER
	uint8   DtcDispType;
#else
	DTC_DISP_TYPE   DtcDispType;
#endif	
	uint8           NumberDTC;                           /*1byte*/
	uint8           bFormatDtc;
	uint8           DTC[SIZE_OF_OEM_DTC];/*16x3 = 48byte*/
	uint8           bTypeDtcStatusType;/*Use to indicate parser type of dtc status of each dtc
									   as normal / general , oem : GM , Chrysler , Mercedes ....
									   since each dtc could be have multti - status*/
	uint8           Reserves[9];
#ifdef _MSC_VER
	uint8    eStatus;
#else
	enumOemDtcBuffStatus    eStatus;
#endif	
} structOEMDTCBufferTest;    /*Total :  55 bytes*/
#pragma pack(pop)


#pragma pack(push,1)
typedef struct _structOemProfileTest
{
	uint16              sSubSystem;
	uint16              sSystem;
	uint8               bSelInnGroup;
#ifdef _MSC_VER
	uint16   Protocol;
#else
	enumProtocol        Protocol;
#endif
	uint32              EcuAddr;
	union
	{
		structOEMDTCBufferTest  strtOEMDTCBuffer;
		void *pUserData;/**/
	};
	uint8               OemInfo[OEM_INFO_LEN];
	//TODO : resolve align memory pragma pack(1)
	//uint8               Reserve[_FLASH_BASE_SIZE_SMALL_-USED_OEM_BUFFER-OEM_INFO_LEN-4];

	uint32              iLinkedIdx1;                                                       //4
	uint32              iProfileID;//Know as Message ID
	uint32				iLinkedBaudRate;
	enumCommands        eCmdKeepAliveDetect;
	enumCommands        eCmdQueryActive;
	uint8               ValidStatus;                    /* = 0xaa (VALID_CODE, valid data) 1*/
}structOemProfileTest;
#pragma pack(pop)

int main()
{
	structOEMDTCBuffer strtOEMDTCBufferTest;
	structOemProfile strtOemProfileTest;
	structMFRVinProfile strtMFRVinProfileTest;
	enumOBDLanguage eMemLanguage= eMEM_LANGUAGE_ENGLISH;
	structListDTCType strtListDTCTypeTest;
	uint8 pDef[1024]="";
	uint32 iDefSize=1024;
	uint8 idata;
	printf("Hello world\n");
	printf("sizeof(structOemProfile) = %d\n", sizeof(structOemProfileTest));
	printf("sizeof(structOEMDTCBufferTest) = %d\n", sizeof(structOEMDTCBufferTest));
	printf("sizeof(strtOEMDTCBufferTest.DTC) = %d\n", sizeof(strtOEMDTCBufferTest.DTC));
	printf("sizeof(strtOEMDTCBufferTest.bFormatDtc) = %d\n", sizeof(strtOEMDTCBufferTest.bFormatDtc));
	printf("sizeof(strtOEMDTCBufferTest.bTypeDtcStatusType) = %d\n", sizeof(strtOEMDTCBufferTest.bTypeDtcStatusType));
	printf("sizeof(strtOEMDTCBufferTest.DtcDispType) = %d\n", sizeof(strtOEMDTCBufferTest.DtcDispType));
	printf("sizeof(strtOEMDTCBufferTest.eStatus) = %d\n", sizeof(strtOEMDTCBufferTest.eStatus));
	//printf("sizeof(strtOemProfileTest.Protocol) = %d\n", sizeof(strtOemProfileTest.Protocol));
	//printf("sizeof(strtOemProfileTest.eCmdKeepAliveDetect) = %d\n", sizeof(strtOemProfileTest.eCmdKeepAliveDetect));
	//printf("sizeof(strtOemProfileTest.eCmdQueryActive) = %d\n", sizeof(strtOemProfileTest.eCmdQueryActive));
	memset(&strtMFRVinProfileTest, 0, sizeof(structMFRVinProfile));
	memset(&strtOemProfileTest, 0, sizeof(structOemProfile));
	memset(&strtListDTCTypeTest, 0, sizeof(structListDTCType));

	FILE *Edit_File;
	Edit_File = fopen("dataOEM.bin", "r");
	if (Edit_File==NULL)
	{											
		printf("Khong tim thay file");
	}
	else
	{
	//	fseek(ifReadFile, 0, SEEK_END);
	//	ifReadFile.read((char*)&strtMFRVinProfileTest,sizeof(structMFRVinProfile));
		fread((char*)&strtOemProfileTest, sizeof(structOemProfile), 1, Edit_File);
	//	ifReadFile.read((char*)&idata, sizeof(idata));
	//	printf("Data = %d\n", idata);
	//	cout << "mo duoc file!\n";
	//	printf("Group = %d\n", strtOemProfileTest.bSelInnGroup);
	//	printf("Protocol = %d\n", strtOemProfileTest.Protocol);
	}
	fclose(Edit_File);
	Edit_File = fopen("dataYMME.bin", "r");
	if (Edit_File == NULL)
	{
		printf("Khong tim thay file");
	}
	else
	{
		fread((char*)&strtMFRVinProfileTest,sizeof(structMFRVinProfile),1, Edit_File);
	//	printf("Year = %d\n", strtMFRVinProfileTest.eYear);
	//	printf("Make = %d\n", strtMFRVinProfileTest.eMake);
	}
	fclose(Edit_File);
	Edit_File = fopen("dataDTC.bin", "r");
	if (Edit_File == NULL)
	{
		printf("Khong tim thay file");
	}
	else
	{
		fread((char*)&strtListDTCTypeTest, sizeof(structListDTCType),1, Edit_File);
	//	printf("NoItem = %d\n", strtListDTCTypeTest.bNoItem);
	//	printf("Field = %d\n", strtListDTCTypeTest.eMFRField);
	}

		/*gf_VDM_Dtc_GetDTCInfo(&strtOemProfileTest,
							  bIdxDtc,
							  &strtListDTCTypeTest);*/
		gf_VDM_DTC_Library_GetDef_OBD1(12, 1, "111", pDef, 65535);

 		/*gf_VDM_DTC_OEM_GetDef(&strtMFRVinProfileTest,
							  &strtOemProfileTest,
							  eMemLanguage,
							  &strtListDTCTypeTest,
							  pDef,
							  iDefSize);*/

	fclose(Edit_File);
	printf(pDef);
	getchar();
    return 0;
}

