/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __OBD_TOOL_CONF_H__
#define __OBD_TOOL_CONF_H__


#if (OBD3130E)
#include    "OBD31x0E_Conf.h"

#elif (MATCO_TOOLS)
#include    "MD75_85_Conf.h"

#else
#error Do not spec Series
#endif

#endif


