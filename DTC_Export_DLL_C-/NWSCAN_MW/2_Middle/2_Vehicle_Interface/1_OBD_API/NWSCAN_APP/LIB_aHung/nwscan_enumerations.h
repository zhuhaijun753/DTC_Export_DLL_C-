/******************************************************************************
===============================================================================
                        Lap Dang Dev
Filename        : nwscan_enumerations.h
Synchronize with file enum
File Excel :US_Enums_v1 1 84
Author : Lap Dang 
Building : 8/17/2015 9:07:29 AM
History         :

|-Version     |   Date       |  Engineer   |        Note                     -|
  +
  +
  +
  +
  +
===============================================================================
******************************************************************************/


#ifndef NWSCAN_ENUMERATIONS_H
#define NWSCAN_ENUMERATIONS_H


#define eNWSCAN_SYSTEM_MAX              0xFFFF
#define eNWSCAN_MANUFACTURE_MAX         0xFFFF
#define eNWSCAN_SUBSYSTEM_MAX           0xFFFF


#define ReadDTCTypeMAX	255

#define emake_Am_____General	emake_Am_____General
#define emake_Gmc	emake_Gmc
#define emake_Srt	emake_Srt
#define emake_Bmw	emake_Bmw
#define emake_CHRYSLER	emake_Chrysler
#define emake_FORD	emake_Ford
#define emake_HONDA	emake_Honda
#define emake_TOYOTA	emake_Toyota

#define emanufacturer_CHRYSLER	emanufacturer_Chrysler
#define emanufacturer_Bmw	emanufacturer_Bmw
#define emanufacturer_Gm	emanufacturer_Gm
#define emanufacturer_Kia	emanufacturer_Kia
#define emanufacturer_Land_____Rover	emanufacturer_Land_____Rover
#define emanufacturer_Jaguar	emanufacturer_Jaguar
#define emanufacturer_FORD	emanufacturer_Ford
#define emanufacturer_MAZDA	emanufacturer_Mazda
#define emanufacturer_VOLKSWAGEN	emanufacturer_Volkswagen
#define emanufacturer_HONDA	emanufacturer_Honda
#define emanufacturer_TOYOTA	emanufacturer_Toyota
#define emanufacturer_MERCEDES_BENZ	emanufacturer_Mercedes_Benz
#define emanufacturer_HYUNDAI	emanufacturer_Hyundai
#define emanufacturer_NISSAN	emanufacturer_Nissan
#define emanufacturer_VOLVO	emanufacturer_Volvo

#define enumVariants_BMW    enumVariant_BMW
#define enumBmwReadDtcTypes	enumBmwreaddtctype_BMW
#define enumBmwEraseDtcTypes	enumBmwerasedtctype_BMW
#define enumCommands_BMW	enumCommand_BMW
#define enumBmwParserDtcTypes	enumBmwparserdtctype_BMW
#define enumBmwVariantDecodes	enumBmwvariantdecode_BMW
#define enumBmwVariantFormulas	enumBmwvariantformula_BMW
#define enumMessageIds_BMW	enumMessageid_BMW
#define enumHondaOptions	enumHondaoption_Honda
#define enumDisplayVisibles_Honda	enumDisplayvisible_Honda
#define enumUnitInfoResults	enumUnitinforesult_Honda
#define enumDtcReadTypes_Honda	enumDtcreadtype_Honda
#define enumMercedes_Suppliers	enumMercedes_Supplier_Mercedes_Benz
#define enumMercedes_Qualifiers	enumMercedes_Qualifier_Mercedes_Benz
#define enumProgramIds_Nissan	enumProgramid_Nissan
#define enumDtcReadTypes_Mercedes_Benz	enumDtcreadtype_Mercedes_Benz
#define enumDtcReadTypes_Toyota	enumDtcreadtype_Toyota
#define enumDtcReadTypes_Volkswagen	enumDtcreadtype_Volkswagen




#endif
