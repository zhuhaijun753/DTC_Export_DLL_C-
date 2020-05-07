/******************************************************************************=
================================================================================
Lap Dang Dev
Filename:
Description:
Layer:
Accessibility:
================================================================================
*******************************************************************************/

#ifndef __MLSTRING_UTILITIES_H__
#define __MLSTRING_UTILITIES_H__

/*==============================================================================
*                                 CONSTANTS
*=============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/

#ifdef __MLSTRING_UTILITIES_C__

#else

#endif

/*==============================================================================
*                                 PROTOTYPES
==============================================================================*/
void xsprintf( void *buff, const void* fmt, ...);
void mlsprintf(void* const* MLbuff, const void* const* MLfmt, ...);
void mltailsprintf(void* const* MLbuff, const void* const* MLfmt, ...);
void mlstrcat(void* const* MLBuffDestination,const void* const* MLBuffSource);
void xstrcpy(void* BuffDestination,const void* BuffSource);
void mlstrcpy(void* const* MLBuffDestination,const void* const* MLBuffSource);
void mlstrncpy(void* const* MLBuffDestination,const void* const* MLBuffSource, uint8 bSize);
uint16 mlstrlen(void* const* MLBuff);
uint16 GetstrLenBuff(void *buff);
void* GetStrOffset(void* p_strBuff, uint16 wOffset);

#endif


