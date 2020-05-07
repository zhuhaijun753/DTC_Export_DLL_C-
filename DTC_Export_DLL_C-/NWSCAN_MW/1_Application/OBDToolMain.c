/******************************************************************************
===============================================================================
Lap Dang Dev
Filename: OBDToolMain.c
History:    
        1. October 02, 2014 - Lap Dang restructure all of project
Description:
Layer:
Accessibility:
===============================================================================
******************************************************************************/


#include <PlatFormType.h>

#include    "SystemDriver.h"
#include    "OBDToolSetting.h"
#include    "GUIManager.h"
#include    "GuiKey.h"
#include    "Processes.h"
#include    "OBDToolManager.h"
#include    <1_Application\3_User_Interface\5_Vehicle_Data_Process\Vehicle_Data_Manager.h>

#if APP_TERMINAL
#define _PROC_GM_OBD1_C
#define  _NEW_STRUCT_SEARCH
#include "GMOBD1_DB.h"
#endif

#if (MATCO_TOOLS)
__root const unsigned char FirmwareID[] @ ".VERSIONSEGMENT" = "V01.00.08";//Jan2115 Lap Dang modified
#else
__root const unsigned char FirmwareID[] @ ".VERSIONSEGMENT" = "V01.02.08";//Oct092014 Lap Dang modified
#endif


__root static const unsigned char strBuildDate[] @ ".BUILD_INFO"= __DATE__;
__root static const unsigned char strBuildTime[] @ ".BUILD_INFO"= __TIME__;










/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Oct1314 Lap Dang customized, cleaned up
*Function name: main
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/

void main(void)
{
    SystemDriverInit();
    ToolSettingInit();
    ToolUserInit();
#if APP_TERMINAL
    terminal_main();
    uint16 sIdx=0;
    while(pliststring[sIdx]!=null)
    {
    	//printf("%s\r\n",pliststring[sIdx]);
    	structDTCTableProfile *pTemp = listtable[sIdx];
        //structFormatTable  FormatTable;
        //unsigned short const * pTableDTC;
    	uint8 DataIdx=pTemp->FormatTable.StartByte;
    	 unsigned short const  *pRow = pTemp->pTableDTC;
    	uint8 Pos=0;
    	uint8 bitmatch[]={0x80,0x40,0x20,0x10,8,4,2,1};
    	while(DataIdx<=pTemp->FormatTable.StopByte)
    	{

    		for(uint8 bit=0;bit<8;bit++)
    		{
    			char *buff="CURRENT";
    			if(pRow[bit]>0xFF)
    			{
    				buff="HISTORY";
    			}
                        if(pRow[bit]==0)
                          continue;
    			printf("%s;%s;%d;%02X;%02X,DTC_DEC_2DIGIT;%d\r\n",pliststring[sIdx],
    					buff,Pos,
						bitmatch[bit],
						pRow[bit]&0xFF,
						pRow[bit]&0xFF);

    		}
                Pos++;
    		pRow+=8;
    		DataIdx++;
    	}

    	//HISTORY
		//

    	sIdx++;
    }
    while(eTRUE)
    {

    }
#else
    while (1)
    {
        SystemState_Process();
        GUI_KeyProcess();
        Proc_Process();
        GUI_LcdUpdate();
    };
#endif
}

//
//#define structLDFFSupported void
//enumbool gf_VBI_OBD2_ReadLDData(structVehDataOBD2Data *p_strtVehDataOBD2Data);
//enumbool gf_VBI_OBD2_ReadLiveData(structVehDataOBD2Data *p_strtVehDataOBD2Data);
//enumbool gf_VBI_OBD2_ReLinkLiveData(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//structLDFFSupported* p_strtLDFFSupported,
//uint8 bUnitType,
//uint16 sIdxItem,uint16 sNoItem);
//enumbool gf_VBI_OBD2_FindLDSupportedItem(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//structLDFFSupported* p_strtLDFFSupported,
//uint8 bUnitType);
//enumbool gf_VBI_OBD2_LDGetDescription(uint16 sIdxItem,
//                                      structLDFFSupported* p_strtLDFFSupported,
//                                      uint8 bLanguage,
//                                      uint8 *pDescription,
//                                      uint8 *pbLenStr);
//
//enumbool gf_VBI_OBD2_ReadLDData(structVehDataOBD2Data *p_strtVehDataOBD2Data){}
//enumbool gf_VBI_OBD2_ReadLiveData(structVehDataOBD2Data *p_strtVehDataOBD2Data){}
//enumbool gf_VBI_OBD2_ReLinkLiveData(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//structLDFFSupported* p_strtLDFFSupported,
//uint8 bUnitType,
//uint16 sIdxItem,uint16 sNoItem){}
//enumbool gf_VBI_OBD2_FindLDSupportedItem(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//structLDFFSupported* p_strtLDFFSupported,
//uint8 bUnitType){}
//enumbool gf_VBI_OBD2_LDGetDescription(uint16 sIdxItem,
//                                      structLDFFSupported* p_strtLDFFSupported,
//                                      uint8 bLanguage,
//                                      uint8 *pDescription,
//                                      uint8 *pbLenStr){}
//enumbool gf_VBI_OBD2_ReadFFData(structVehDataOBD2Data *p_strtVehDataOBD2Data);
//enumbool gf_VBI_OBD2_FindFFItem(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//                                structLDFFSupported* p_strtLDFFSupported,
//                                uint8 bUnitType);
//
//enumbool gf_VBI_OBD2_FFGetDescription(uint16 sIdxItem,
//                                      structLDFFSupported* p_strtLDFFSupported,
//                                      uint8 bLanguage,
//                                      uint8 *pDescription,
//                                      uint8 *pbLenStr);
//
//enumbool gf_VBI_OBD2_ReadFFData(structVehDataOBD2Data *p_strtVehDataOBD2Data){}
//
//enumbool gf_VBI_OBD2_FindFFItem(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//                                structLDFFSupported* p_strtLDFFSupported,
//                                uint8 bUnitType){}
//enumbool gf_VBI_OBD2_FFGetDescription(uint16 sIdxItem,
//                                      structLDFFSupported* p_strtLDFFSupported,
//                                      uint8 bLanguage,
//                                      uint8 *pDescription,
//                                      uint8 *pbLenStr){}
//enumbool gf_VBI_OBD2_FindLDItem(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//                                structLDFFSupported* p_strtLDFFSupported,
//                                uint8 bUnitType);
//enumbool gf_VBI_OBD2_FindLDItem(structVehDataOBD2Data *p_strtVehDataOBD2Data,
//                                structLDFFSupported* p_strtLDFFSupported,
//                                uint8 bUnitType)
//{}
