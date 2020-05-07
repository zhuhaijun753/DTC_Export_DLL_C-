/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description: this file is used to store functions involving to display
                are commonly used in many UI processes
Layer: Application
Accessibility: All UI processes may access this file
================================================================================
*******************************************************************************/

#ifndef __LCD_CALLBACK_H__
#define __LCD_CALLBACK_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/

/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/



/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 29, 2011
                2. Oct082014 Lap Dang change prototype
*Function name: DispFlashScreen
*Descrtiption : This screen is currently used in 2 cases, power up and 
                    in process firmware version
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void DispFlashScreen(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. October 22 2014
*Function name: Proc_Null_Function
*Descrtiption : Just do nothing
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void Proc_Null_Function(void);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. January 05 2015
*Function name: FunctionLinkingDisplayNop
*Descrtiption : Just do nothing
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void     FunctionLinkingDisplayNop(structVehDB * p_strtVehDB, uint8 b_Total, uint8 b_Present) ;

/*------------------------------------------------------------------------------
*Engineer     : KhaVo
*Historical   : 1. December 07, 2011
*Function name: FlashLinkIcon
*Descrtiption :
*Input        : None
*Output       :
*-----------------------------------------------------------------------------*/
void FlashLinkIcon(void);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 18 2014
*Function name: INN_GUI_Text_ProgressBar_ForceFullProgressBar
*Descrtiption : force full progress bar
*Input        : None
*Output       : None
*-----------------------------------------------------------------------------*/
void INN_GUI_Text_ProgressBar_ForceFullProgressBar(void);














/*==============================================================================
                                COMMON UI STRING FUNCTIONs

==============================================================================*/
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 14 2014
*Function name: Common_UI_Protocol_String_Get
*Descrtiption :
*Input        : 
                enumProtocol eProtocol - protocol need to get string
                uint8   *p_bProtocolStr - pointer to buffer to store protocol string
*Output       : enumbool - status to see get protocol string succesful or not
*-----------------------------------------------------------------------------*/
enumbool Common_UI_Protocol_String_Get(enumProtocol eProtocol,
                                       uint8   *p_bProtocolStr);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 14 2014
*Function name: Common_UI_Make_String_Get
*Descrtiption :
*Input        : 
                enumMake eMake - make value need to get string
                uint8   *p_bMakeStr- pointer to buffer to store make string
*Output       : enumbool - status to see get make string succesful or not
*-----------------------------------------------------------------------------*/
enumbool Common_UI_Make_String_Get(enumMake eMake,
                                   uint8   *p_bMakeStr);

/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2915
*Function name: Common_UI_GroupSystem_String_Get
*Descrtiption :
*Input        : 
                enumMFRGroupSystem eGroupSystem - group system value need to get string
                uint8   *p_bGroupSystemStr- pointer to buffer to store group system string
*Output       : enumbool - status to see getting group system string succesful or not
*-----------------------------------------------------------------------------*/
enumbool Common_UI_GroupSystem_String_Get(enumMFRGroupSystem eGroupSystem,
                                          uint8   *p_bGroupSystemStr);
                                   
/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. Jan2315
*Function name: Common_UI_System_String_Get
*Descrtiption :
*Input        : 
                enumSystem eSystem - system value need to get string
                uint8   *p_bMakeStr- pointer to buffer to store system string
*Output       : enumbool - status to see get make string succesful or not
*-----------------------------------------------------------------------------*/
enumbool Common_UI_System_String_Get(enumSystem eSystem,
                                     uint8   *p_bMakeStr);


/*------------------------------------------------------------------------------
*Engineer     : Lap Dangruong
*Historical   : 1. November 14 2014
*Function name: Common_UI_Make_String_Get
*Descrtiption :
*Input        : 
                enumSubSystem eSubSystem - subsystem value need to get string
                uint8   *p_bMakeStr- pointer to buffer to store subsystem string
*Output       : enumbool - status to see get make string succesful or not
*-----------------------------------------------------------------------------*/
enumbool Common_UI_SubSystem_String_Get(enumSubSystem eSubSystem,
                                        uint8   *p_bSubSysStr);






#endif
