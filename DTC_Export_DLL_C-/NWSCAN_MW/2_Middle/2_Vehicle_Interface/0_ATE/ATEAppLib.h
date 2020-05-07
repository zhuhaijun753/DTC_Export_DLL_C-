/*
*Revision : 1.0.0        14 Aug 2014
*Author : Hung Vo
*@Important  : This lib just work with OBD API from version V01.01.05
*How to use this lib
*Step1 : define processor : #define _ENABLE_ATE_FUNCTION_=1

*Step2 : Insert process into file Processes.h
	2.1 Extern used process: 
			#if _ENABLE_ATE_FUNCTION_
					void ATE_Process(void);
			#endif
	2.2 Insert Process :
					  const structProcHandler g_strtPhocHandlerList[]={...
					...
				#if _ENABLE_ATE_FUNCTION_
						{
							.eProc  = PROC_USB,
							.fpProc = ATE_Process
						},
				#endif
					...
*Step3 : Insert this section code into switch(p_strtUSBData->strtHidOut.iCommand) 
          (void USBProcessData(structUSBData *p_strtUSBData), USBInterface.c )

         #if _ENABLE_ATE_FUNCTION_
            case UsbATEHID: //UsbATEHID = 98
              ATE_HID_USBProcessData(p_strtUSBData);
            break;
          #endif
*Step3 : Handle Serial Number barcode scanner
	*3.1 : define in struct structToolSetting
		#define MAX_SIZE_SERIAL_NUMBER  22  //[Len 1Byte][Data 20bytes][status 1byte]
		typedef struct _structToolSetting
		{
		......
		#if _ENABLE_ATE_FUNCTION_
			uint8 SerialNumber[MAX_SIZE_SERIAL_NUMBER];
		#endif
		} structToolSetting;
	*3.2 : Insert this section code to file MemoryInterfaceInternalFlash.c

		#if _ENABLE_ATE_FUNCTION_
		void ATE_SetFunctionSaveSerialNumber(void(*pfsave)(uint8*pSerialNumber),void*(*pfLoad)(void));
		void ATE_SaveSerialNumber(uint8*pSerialNumber);
		void ATE_SaveSerialNumber(uint8*pSerialNumber)
		{      
			 structToolSetting* p_strtToolSetting =&g_strtToolSetting;
			 if(pSerialNumber==null || pSerialNumber[0]==0) //Invalid Serial Number
			   return;
			 memcpy(p_strtToolSetting->SerialNumber,
					pSerialNumber,
					MAX_SIZE_SERIAL_NUMBER);
			 SaveToolSetting(p_strtToolSetting);
		}
		void* ATE_LoadSerialNumber(void);
		void* ATE_LoadSerialNumber(void)
		{
		   structToolSetting* p_strtToolSetting =&g_strtToolSetting;
		   return p_strtToolSetting->SerialNumber;
		}
		#endif
	*3.3 : register function ATE_SetFunctionSaveSerialNumber into function void LoadToolSetting(structToolSetting* p_strtToolSetting) of file MemoryInterfaceInternalFlash.c
		LoadToolSetting(...)
		{
		....
			#if _ENABLE_ATE_FUNCTION_
				ATE_SetFunctionSaveSerialNumber(ATE_SaveSerialNumber,ATE_LoadSerialNumber);
			#endif
			...
		}

inform to supporter Innova
*/

void ATE_HID_USBProcessData(structUSBData *p_strtUSBData);
void ATE_Process(void);

