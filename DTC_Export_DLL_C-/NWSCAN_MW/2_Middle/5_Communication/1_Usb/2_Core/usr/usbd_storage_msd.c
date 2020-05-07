/**
  ******************************************************************************
  * @file    usbd_storage_msd.c
  * @author  MCD application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   This file provides the disk operations functions.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "2_Middle\5_Communication\1_Usb\2_Core\Libraries\STM32_USB_Device_Library\Class\msc\inc\usbd_msc_mem.h"
#include "2_Middle\5_Communication\1_Usb\2_Core\Libraries\STM32_USB_Device_Library\Core\inc\usb_conf.h"

#if _NAND_FLASH
//#include <AppDriver\NandFlash\Media\Media.h>
//#include <AppDriver\NandFlash\Media\MedNandFlash.h>
//#include <AppDriver\NandFlash\Managed\ManagedNandFlash.h>
//#include <AppDriver\NandFlash\Managed\NandSpareScheme.h>
//#include <AppDriver\NandFlash\Managed\NandFlashModel.h>
//#include <AppDriver\NandFlash\Managed\TranslatedNandFlash.h>
//#include <AppDriver\NandFlash\Managed\RawNandFlash.h>

#include <2_Middle\3_Storage\2_Driver\3_Nand_Flash\2_Driver\Media\Media.h>
#include "nandfs.h"    
extern Media medias[];

#endif

#include <2_Middle\3_Storage\2_Driver\0_FAT_Driver\FatFs\inc\diskio.h>
#include <trace.h>

#include <PlatFormType.h>
#include <OBDToolSetting.h>   

#if (_SD_CARD == 1)
#include <SDCard.h>
extern SD_CardInfo SDCardInfo;
#endif

extern structToolSetting    g_strtToolSetting;
extern enumUsbStorageMode eUsbMassStorageMode;





/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */


/** @defgroup STORAGE
  * @brief media storage application module
  * @{
  */

/** @defgroup STORAGE_Private_TypesDefinitions
  * @{
  */
/**
  * @}
  */


/** @defgroup STORAGE_Private_Defines
  * @{
  */

#define STORAGE_LUN_NBR                  1
/**
  * @}
  */


/** @defgroup STORAGE_Private_Macros
  * @{
  */
/**
  * @}
  */


/** @defgroup STORAGE_Private_Variables
  * @{
  */
/* USB Mass storage Standard Inquiry Data */
const int8_t  STORAGE_Inquirydata[] = {//36

  /* LUN 0 */
  0x00,		
  0x80,		
  0x02,		
  0x02,
  (USBD_STD_INQUIRY_LENGTH - 5),
  0x00,
  0x00,	
  0x00,
#if (MATCO_TOOLS)
  'I', 'n', 'n', 'o', 'v', 'a', ' ', ' ', /* Manufacturer : 8 bytes */
  'O', 'B', 'D', 'M', 'D', 'x', '5', ' ',/* Product      : 16 Bytes */
  'F', 'l', 'a', 's', 'h', ' ', ' ', ' ',
  '1', '.', '0' ,'0',                     /* Version      : 4 Bytes */
#else
  'I', 'n', 'n', 'o', 'v', 'a', ' ', ' ', /* Manufacturer : 8 bytes */
  'O', 'B', 'D', '3', '1', '3', '0', 'E', /* Product      : 16 Bytes */
  'F', 'l', 'a', 's', 'h', ' ', ' ', ' ',
  '1', '.', '0' ,'0',                     /* Version      : 4 Bytes */
#endif
};

/**
  * @}
  */

extern const int8_t* USB_p_bMscInquiryData;
/** @defgroup STORAGE_Private_FunctionPrototypes
  * @{
  */
int8_t STORAGE_Init (uint8_t lun);

int8_t STORAGE_GetCapacity (uint8_t lun,
                           uint32_t *block_num,
                           uint32_t *block_size);

int8_t  STORAGE_IsReady (uint8_t lun);

int8_t  STORAGE_IsWriteProtected (uint8_t lun);

int8_t STORAGE_Read (uint8_t lun,
                        uint8_t *buf,
                        uint32_t blk_addr,
                        uint16_t blk_len);

int8_t STORAGE_Write (uint8_t lun,
                        uint8_t *buf,
                        uint32_t blk_addr,
                        uint16_t blk_len);

int8_t STORAGE_GetMaxLun (void);


USBD_STORAGE_cb_TypeDef USBD_MICRO_SDIO_fops =
{
  STORAGE_Init,
  STORAGE_GetCapacity,
  STORAGE_IsReady,
  STORAGE_IsWriteProtected,
  STORAGE_Read,
  STORAGE_Write,
  STORAGE_GetMaxLun,
  (int8_t *)STORAGE_Inquirydata,
};

USBD_STORAGE_cb_TypeDef  *USBD_STORAGE_fops = &USBD_MICRO_SDIO_fops;

__IO uint32_t count = 0;
/**
  * @}
  */


/** @defgroup STORAGE_Private_Functions
  * @{
  */


/**
  * @brief  Initialize the storage medium
  * @param  lun : logical unit number
  * @retval Status
  */

int8_t STORAGE_Init (uint8_t lun)
{

  return (0);
}

/**
  * @brief  return medium capacity and block size
  * @param  lun : logical unit number
  * @param  block_num :  number of physical block
  * @param  block_size : size of a physical block
  * @retval Status
  */
int8_t STORAGE_GetCapacity (uint8_t lun, uint32_t *block_num, uint32_t *block_size)
{

    *block_size =  512;
#if (_NAND_FLASH == 1)
    *block_num =  (uint32_t)(medias[lun].size /
                             (512 /
                              medias[lun].blockSize));
#elif (_SD_CARD == 1) /* Jun 20, 2014 - CuongHL added for SDcard */
	*block_num = SDCardInfo.CardCapacity / 512; 
#else
    *block_num = 0;
#endif
    return (0);

}

/**
  * @brief  check whether the medium is ready
  * @param  lun : logical unit number
  * @retval Status
  */
int8_t  STORAGE_IsReady (uint8_t lun)
{
    /*March2214 V27a Lap Dang modified to enable/disable mass storage mode follow USB Command*/
    int8_t bReturn = -1;
    if(eUsbMassStorageMode == eUSBMODE_STORAGE_ENABLE)
    {
        bReturn = 0;
    }
    
    return bReturn;    
}

/**
  * @brief  check whether the medium is write-protected
  * @param  lun : logical unit number
  * @retval Status
  */
int8_t  STORAGE_IsWriteProtected (uint8_t lun)
{
  return  0;
}

/**
  * @brief  Read data from the medium
  * @param  lun : logical unit number
  * @param  buf : Pointer to the buffer to save data
  * @param  blk_addr :  address of 1st block to be read
  * @param  blk_len : nmber of blocks to be read
  * @retval Status
  */
int8_t STORAGE_Read (uint8_t lun,
                 uint8_t *buf,
                 uint32_t blk_addr,
                 uint16_t blk_len)
{
#if (_FILE_SYSTEM == 1) /* Jun 20, 2014 - CuongHL disabled (_NAND_FLASH == 1) */
    DRESULT res = RES_ERROR;
    res = disk_read(lun,buf, blk_addr, blk_len);
    if (res)
    {
        return -1;
    }
#endif
  return 0;
}
/**
  * @brief  Write data to the medium
  * @param  lun : logical unit number
  * @param  buf : Pointer to the buffer to write from
  * @param  blk_addr :  address of 1st block to be written
  * @param  blk_len : nmber of blocks to be read
  * @retval Status
  */
int8_t STORAGE_Write (uint8_t lun,
                  uint8_t *buf,
                  uint32_t blk_addr,
                  uint16_t blk_len)
{
#if (_FILE_SYSTEM == 1) /* Jun 20, 2014 - CuongHL disabled (_NAND_FLASH == 1) */
    DRESULT res = RES_ERROR;
    TRACE_ERROR_WP( "UWrite: 0x%x Count: 0x%x\r\n", blk_addr, blk_len);

    res = disk_write(lun, buf, blk_addr,blk_len);
    res = disk_ioctl(lun, CTRL_SYNC, (void*)0);
    if (res)
    {
        return -1;
    }
#endif
    return (0);
}

/**
  * @brief  Return number of supported logical unit
  * @param  None
  * @retval number of logical unit
  */

int8_t STORAGE_GetMaxLun (void)
{
  return (STORAGE_LUN_NBR - 1);
}
/**
  * @}
  */


/**
  * @}
  */


/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

