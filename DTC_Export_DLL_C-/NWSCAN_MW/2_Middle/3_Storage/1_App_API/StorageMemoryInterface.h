
/******************************************************************************
===============================================================================
Lap Dang Dev
Filename: MemoryInterface.h
Description: Memory
Layer:
Accessibility:
===============================================================================
******************************************************************************/
#ifndef __STORAGE_MEMORY_INTERFACE_H__
#define __STORAGE_MEMORY_INTERFACE_H__

#include "MemoryInterfaceInternalFlash.h"
#include    "SDCardApp.h"
#include    "nandfs.h"


#define StorageSaveToolSetting(a)                  IntFlashSaveToolSetting(a)
#define StorageLoadToolSetting(a)                  IntFlashLoadToolSetting(a)
#define StorageClearToolSetting(a)                 IntFlashClearToolSetting(a)

#define StorageSaveSystemSetting(a)                IntFlashSaveSystemSetting(a)
#define StorageLoadSystemSetting(a)                IntFlashLoadSystemSetting(a)
#define StorageClearSystemSetting(a)               IntFlashClearSystemSetting(a)


#define ReadFirmwareVersion(a)              IntFlashReadFirmwareVersion(a)
#define ReadBootLoaderVersion(a)            IntFlashReadBootLoaderVersion(a)
#define ReadBufferFormat(a)                 IntFlashReadBufferFormat(a)



extern void ReadDatabaseVersion(uint8* p_strDatabase);

void StorageMemoryFormat(void);






#endif