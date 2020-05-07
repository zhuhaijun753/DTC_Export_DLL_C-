#ifndef DTCPASER_H
#define DTCPASER_H
#ifdef DTCPASER_C
typedef void(*funcDtcParser)(structDtcParser * p_strtDtcParser);
typedef struct _structDtcParserFunc
{
    enumDTCType     eDTCType;
    funcDtcParser   fDtcParser;
}structDtcParserFunc;
/*Local Function*/
static void __Parse_SaeDTCDecode(structDtcParser * p_strtDtcParser);
static void __Parse_DTC_DEC(structDtcParser * p_strtDtcParser);
static void __Parse_DTC_HEX(structDtcParser * p_strtDtcParser);
static void __Parse_DTC_DEC_FULL(structDtcParser * p_strtDtcParser);
static void __Parse_DTC_HEX_FULL(structDtcParser * p_strtDtcParser);
static void __Parse_DTC_MAIN_SUB_HEX(structDtcParser * p_strtDtcParser);
#endif
void ParserDtc(structDtcParser *p_strtDtcParser);

#endif
