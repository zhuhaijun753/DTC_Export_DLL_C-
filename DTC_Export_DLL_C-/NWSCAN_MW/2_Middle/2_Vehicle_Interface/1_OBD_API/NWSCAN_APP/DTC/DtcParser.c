/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : DtcParser.c
Description     : use to decode dtc
Engineer        : Lap Dang - Created 18 Jan 2011
History         :

|-Version     |   Date       |  Engineer   |        Note                     -|
  +V01.00.00    18Jan2011         Lap Dang      *Initialize
  +
  +
  +
  +
  +
  +
  +
===============================================================================
******************************************************************************/
#define DTCPASER_C
#include "PlatFormType.h"
#include "VBI_Utility.h"
#include "SYS_Utility.h"
#include "DtcParser.h"
#include "string.h"
#include "stdio.h"


#define __SPRINTF(a,b,c)			sprintf((char*)(a),(b),(c))

static uint32 __DtcGetValasFrameDtc(structDtcParser * p_strtDtcParser,uint8 bFrm)
{
    uint8 bIdx=0;
uint32 iDecDtc =0;
    while(bIdx<bFrm)
        {
            iDecDtc+=p_strtDtcParser->pDtc[bIdx];
            bIdx++;
            if(bIdx<bFrm)
                    iDecDtc <<=8;
        }
    return iDecDtc;
}
static void __Parse_DTC_HEX_FULL(structDtcParser * p_strtDtcParser)
{
    char patern[]="%02X";
    patern[2]=p_strtDtcParser->bFrameDtc+'0';
    __SPRINTF(p_strtDtcParser->arrDtcOutPut,patern,__DtcGetValasFrameDtc(p_strtDtcParser,p_strtDtcParser->bFrameDtc));
}



/*
 * New lib source code
 * */
static void __Parser_DTC_1BYTE_HB_LB(structDtcParser * p_strtDtcParser)
{
	sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%d-%d",
            p_strtDtcParser->pDtc[0] >> 4, p_strtDtcParser->pDtc[0] & 0x0F);
}
static void __Parser_DTC_DEC_2DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%02d", p_strtDtcParser->pDtc[0]);
}
static void __Parser_DTC_DEC_3DIGIT(structDtcParser * p_strtDtcParser)
{
//    sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%03d",
//            __DtcGetValasFrameDtc(p_strtDtcParser, 1));
    /*
     * Hung Vo Updated on 13 July 2015 , to fix some bug with 2 byte dtc
     * */
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%03d",
                __DtcGetValasFrameDtc(p_strtDtcParser, p_strtDtcParser->bFrameDtc));
}
static void __Parser_DTC_DEC_4DIGIT(structDtcParser * p_strtDtcParser)
{

	__SPRINTF(p_strtDtcParser->arrDtcOutPut,"%04d",
            __DtcGetValasFrameDtc(p_strtDtcParser, 2));
}
static void __Parser_DTC_DEC_5DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%05d",
            __DtcGetValasFrameDtc(p_strtDtcParser, 2));
}
static void __Parser_DTC_DEC(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%d",
            __DtcGetValasFrameDtc(p_strtDtcParser, p_strtDtcParser->bFrameDtc));
}

static void __Parser_DTC_HEX_2DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%02X", p_strtDtcParser->pDtc[0]);
}
static void __Parser_DTC_HEX_3DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%03X", p_strtDtcParser->pDtc[0]);
}
static void __Parser_DTC_HEX_4DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%04X",
            __DtcGetValasFrameDtc(p_strtDtcParser, 2));
}
static void __Parser_DTC_HEX_5DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%05X",
            __DtcGetValasFrameDtc(p_strtDtcParser, 3));
}
static void __Parser_DTC_HEX_6DIGIT(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%06X",
            __DtcGetValasFrameDtc(p_strtDtcParser, 3));
}
static void __Parser_DTC_HEX(structDtcParser * p_strtDtcParser)
{
	__SPRINTF(p_strtDtcParser->arrDtcOutPut, "%X",
            __DtcGetValasFrameDtc(p_strtDtcParser, p_strtDtcParser->bFrameDtc));
}


static void __Parser_DTC_HONDA_MAIN_SUB_HEX(
        structDtcParser * p_strtDtcParser)
{

    if (p_strtDtcParser->bFrameDtc > 1)
    {
        uint8 bMain1,bMain2,bSub;
        bMain1=p_strtDtcParser->pDtc[0];
        bMain2=bMain1&0xF;
        bMain1=bMain1&0xF0;
        bMain1 >>=4;
        bSub=p_strtDtcParser->pDtc[1];
        if(bMain1>0)
        {
            sprintf((char*)p_strtDtcParser->arrDtcOutPut,"%d%d-%X",bMain1,bMain2,bSub);
        }
        else
        {
            sprintf((char*)p_strtDtcParser->arrDtcOutPut,"%d-%X",bMain2,bSub);
        }
    }
}

static void __Parser_DTC_MAIN_DEC_5DIGIT_SUB_DEC_3(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc==3)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%05d-%03d",
        __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_HEX_SUB_1BYTE_HEX(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {

        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%X-%X",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}

static void __Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%X-%d",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}

static void __Parser_DTC_MAIN_HEX_SUB_1BYTE_HEX_NO_TRIM(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        char patern[20];
        sprintf(patern, "%%0%dX-%%02X", (p_strtDtcParser->bFrameDtc - 1)*2);
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, patern,
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC_NO_TRIM(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        char patern[20];
        sprintf(patern, "%%0%dX-%%03d", (p_strtDtcParser->bFrameDtc - 1)*2);
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, patern,
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC_2(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {

        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%X-%02d",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC_3(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut,"%X-%03d",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_DEC_SUB_1BYTE_HEX(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%d-%X",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_DEC_SUB_1BYTE_DEC(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%d-%d",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_DEC_SUB_1BYTE_HEX_NO_TRIM(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        char patern[20];
        sprintf(patern, "%%0%dd-%%02X", (p_strtDtcParser->bFrameDtc - 1)*2);
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, patern,
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_DEC_SUB_1BYTE_DEC_2(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%d-%02d",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_MAIN_DEC_SUB_1BYTE_DEC_3(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 1)
    {
        sprintf((char*)p_strtDtcParser->arrDtcOutPut, "%d-%03d",
                __DtcGetValasFrameDtc(p_strtDtcParser,
                        p_strtDtcParser->bFrameDtc - 1),
                p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc - 1]);
    }
}
static void __Parser_DTC_SAE(structDtcParser * p_strtDtcParser)
{
    uint8 DTCCategory[] = {'P','C','B','U'};
    uint8 bTemp=p_strtDtcParser->pDtc[0]>>6;
    uint8 bIdx=1;
    uint8 *pCharTemp;
    p_strtDtcParser->arrDtcOutPut[0]=DTCCategory[bTemp&3];
    bTemp&=0x3F;
    sprintf((char*)&p_strtDtcParser->arrDtcOutPut[1],"%02X",p_strtDtcParser->pDtc[0]&0x3F);
    pCharTemp=&p_strtDtcParser->arrDtcOutPut[3];
    while(bIdx<p_strtDtcParser->bFrameDtc)
    {
        sprintf((char*)pCharTemp,"%02X",p_strtDtcParser->pDtc[bIdx]);
        pCharTemp+=2;
        bIdx++;
    }
}
static void __Parser_DTC_MAIN_SAE_SUB_1BYTE_HEX(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 2)
    {
        uint8 bTemp=p_strtDtcParser->bFrameDtc;
        p_strtDtcParser->bFrameDtc--;
        __Parser_DTC_SAE(p_strtDtcParser);
        sprintf((char*)&p_strtDtcParser->arrDtcOutPut[(p_strtDtcParser->bFrameDtc*2)+1],"-%X",p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc]);
        p_strtDtcParser->bFrameDtc=bTemp;
    }

}
static void __Parser_DTC_MAIN_SAE_SUB_1BYTE_HEX_NO_TRIM(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 2)
    {
        uint8 bTemp=p_strtDtcParser->bFrameDtc;
        p_strtDtcParser->bFrameDtc--;
        __Parser_DTC_SAE(p_strtDtcParser);
        sprintf((char*)&p_strtDtcParser->arrDtcOutPut[(p_strtDtcParser->bFrameDtc*2)+1],"-%02X",p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc]);
        p_strtDtcParser->bFrameDtc=bTemp;
    }

}
static void __Parser_DTC_MAIN_SAE_SUB_1BYTE_DEC_NO_TRIM(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 2)
    {
        uint8 bTemp=p_strtDtcParser->bFrameDtc;
        p_strtDtcParser->bFrameDtc--;
        __Parser_DTC_SAE(p_strtDtcParser);
        sprintf((char*)&p_strtDtcParser->arrDtcOutPut[(p_strtDtcParser->bFrameDtc*2)+1],"-%03d",p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc]);
        p_strtDtcParser->bFrameDtc=bTemp;
    }

}
static void __Parser_DTC_MAIN_SAE_SUB_1BYTE_DEC(
        structDtcParser * p_strtDtcParser)
{
    if (p_strtDtcParser->bFrameDtc > 2)
        {
            uint8 bTemp=p_strtDtcParser->bFrameDtc;
            p_strtDtcParser->bFrameDtc--;
            __Parser_DTC_SAE(p_strtDtcParser);
            sprintf((char*)&p_strtDtcParser->arrDtcOutPut[(p_strtDtcParser->bFrameDtc*2)+1],"-%d",p_strtDtcParser->pDtc[p_strtDtcParser->bFrameDtc]);
            p_strtDtcParser->bFrameDtc=bTemp;
        }
}

/*-----------------------------------------------------------------------------
*Engineer       : Lap Dang
*Date           : 20July2010
*Function name  : ParserDtc
*Description    : parser dtc to ascii
*Input          : p_strtDtcParser
*Output         : ascii dtc with max len 10bytes
-----------------------------------------------------------------------------*/
void ParserDtc(structDtcParser * p_strtDtcParser)
{
    uint8 bIdx=0;
    const structDtcParserFunc strtDtcParserFunc[]=
    {
        {edtcdisplaytype_DTC_1BYTE_HB_LB,__Parser_DTC_1BYTE_HB_LB},
        {edtcdisplaytype_DTC_DEC,__Parser_DTC_DEC},
        {edtcdisplaytype_DTC_DEC_2DIGIT,__Parser_DTC_DEC_2DIGIT},
        {edtcdisplaytype_DTC_DEC_3DIGIT,__Parser_DTC_DEC_3DIGIT},
        {edtcdisplaytype_DTC_DEC_4DIGIT,__Parser_DTC_DEC_4DIGIT},
        {edtcdisplaytype_DTC_DEC_5DIGIT,__Parser_DTC_DEC_5DIGIT},
        {edtcdisplaytype_DTC_HEX,__Parser_DTC_HEX},
        {edtcdisplaytype_DTC_HEX_2DIGIT,__Parser_DTC_HEX_2DIGIT},
        {edtcdisplaytype_DTC_HEX_3DIGIT,__Parser_DTC_HEX_3DIGIT},
        {edtcdisplaytype_DTC_HEX_4DIGIT,__Parser_DTC_HEX_4DIGIT},
        {edtcdisplaytype_DTC_HEX_5DIGIT,__Parser_DTC_HEX_5DIGIT},
        {edtcdisplaytype_DTC_HEX_6DIGIT,__Parser_DTC_HEX_6DIGIT},
        {edtcdisplaytype_DTC_MAIN_DEC_SUB_1BYTE_DEC,__Parser_DTC_MAIN_DEC_SUB_1BYTE_DEC},
        {edtcdisplaytype_DTC_MAIN_DEC_SUB_1BYTE_DEC_2,__Parser_DTC_MAIN_DEC_SUB_1BYTE_DEC_2},
        {edtcdisplaytype_DTC_MAIN_DEC_SUB_1BYTE_DEC_3,__Parser_DTC_MAIN_DEC_SUB_1BYTE_DEC_3},
        {edtcdisplaytype_DTC_MAIN_DEC_SUB_1BYTE_HEX,__Parser_DTC_MAIN_DEC_SUB_1BYTE_HEX},
        {edtcdisplaytype_DTC_MAIN_DEC_SUB_1BYTE_HEX_NO_TRIM,__Parser_DTC_MAIN_DEC_SUB_1BYTE_HEX_NO_TRIM},
        {edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_DEC,__Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC},
        {edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_DEC_2,__Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC_2},
        {edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_DEC_3,__Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC_3},
        {edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_HEX,__Parser_DTC_MAIN_HEX_SUB_1BYTE_HEX},
        {edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_HEX_NO_TRIM,__Parser_DTC_MAIN_HEX_SUB_1BYTE_HEX_NO_TRIM},

		{edtcdisplaytype_DTC_MAIN_HEX_SUB_1BYTE_DEC_NO_TRIM,__Parser_DTC_MAIN_HEX_SUB_1BYTE_DEC_NO_TRIM},

		{edtcdisplaytype_DTC_MAIN_SAE_SUB_1BYTE_DEC,__Parser_DTC_MAIN_SAE_SUB_1BYTE_DEC},
        {edtcdisplaytype_DTC_MAIN_SAE_SUB_1BYTE_DEC_NO_TRIM,__Parser_DTC_MAIN_SAE_SUB_1BYTE_DEC_NO_TRIM},
        {edtcdisplaytype_DTC_MAIN_SAE_SUB_1BYTE_HEX,__Parser_DTC_MAIN_SAE_SUB_1BYTE_HEX},
        {edtcdisplaytype_DTC_MAIN_SAE_SUB_1BYTE_HEX_NO_TRIM,__Parser_DTC_MAIN_SAE_SUB_1BYTE_HEX_NO_TRIM},

        {edtcdisplaytype_DTC_SAE,__Parser_DTC_SAE},
        {edtcdisplaytype_DTC_HONDA_MAIN_SUB_HEX,__Parser_DTC_HONDA_MAIN_SUB_HEX},
        {edtcdisplaytype_DTC_MAIN_DEC_5DIGIT_SUB_DEC_3,__Parser_DTC_MAIN_DEC_5DIGIT_SUB_DEC_3},


        {DTC_MAX            ,Null}
    };
    memset(p_strtDtcParser->arrDtcOutPut,0,MAX_LEN_DTC_ASCII);
    while(strtDtcParserFunc[bIdx].fDtcParser != Null)
    {
        if(strtDtcParserFunc[bIdx].eDTCType == p_strtDtcParser->eDTCType)
        {
            strtDtcParserFunc[bIdx].fDtcParser(p_strtDtcParser);
            return;
        }
        bIdx++;
    }
    //Not found will display raw hex
    __Parse_DTC_HEX_FULL(p_strtDtcParser);
}
