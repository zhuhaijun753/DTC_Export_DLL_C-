/**
  ******************************************************************************
  * @file    usbd_usr.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   This file includes the user application layer
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
#include <stdio.h>
#include  "2_Middle\5_Communication\1_Usb\2_Core\Libraries\STM32_USB_Device_Library\Core\inc\usbd_usr.h"
#include  "2_Middle\5_Communication\1_Usb\2_Core\Libraries\STM32_USB_Device_Library\Core\inc\usbd_ioreq.h"

#define USB_LOG_EN  0

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
* @{
*/

/** @defgroup USBD_USR
* @brief    This file includes the user application layer
* @{
*/

/** @defgroup USBD_USR_Private_TypesDefinitions
* @{
*/
/**
* @}
*/


/** @defgroup USBD_USR_Private_Defines
* @{
*/
/**
* @}
*/


/** @defgroup USBD_USR_Private_Macros
* @{
*/
/**
* @}
*/


/** @defgroup USBD_USR_Private_Variables
* @{
*/

USBD_Usr_cb_TypeDef USR_cb =
{
  USBD_USR_Init,
  USBD_USR_DeviceReset,
  USBD_USR_DeviceConfigured,
  USBD_USR_DeviceSuspended,
  USBD_USR_DeviceResumed,

  USBD_USR_DeviceConnected,
  USBD_USR_DeviceDisconnected,


};



/**
* @}
*/

/** @defgroup USBD_USR_Private_Constants
* @{
*/

/**
* @}
*/



/** @defgroup USBD_USR_Private_FunctionPrototypes
* @{
*/
/**
* @}
*/


/** @defgroup USBD_USR_Private_Functions
* @{
*/



/**
* @brief  USBD_USR_Init
*         Displays the message on LCD for host lib initialization
* @param  None
* @retval None
*/
void USBD_USR_Init(void)
{
#if USB_LOG_EN /*Dont log*/
#ifdef USE_USB_OTG_HS
  printf(" USB OTG HS HID Device\r\n");
#else
  printf(" USB OTG FS HID Device\r\n");
#endif
  printf("> USB device library started.\r\n");
  printf ("     USB Device Library v1.0.0rc1\r\n" );
#endif
}

/**
* @brief  USBD_USR_DeviceReset
*         Displays the message on LCD on device Reset Event
* @param  speed : device speed
* @retval None
*/
void USBD_USR_DeviceReset(uint8_t speed )
{
#if USB_LOG_EN /*Dont log*/
 switch (speed)
 {
   case USB_OTG_SPEED_HIGH:
     printf ("     USB Device Library v1.1.0 [HS]\r\n" );
     break;

  case USB_OTG_SPEED_FULL:
     printf ("     USB Device Library v1.1.0rc1 [FS]\r\n" );
     break;
 default:
     printf ("     USB Device Library v1.1.0 [??]\r\n" );
    break;
 }
#endif
}


/**
* @brief  USBD_USR_DeviceConfigured
*         Displays the message on LCD on device configuration Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceConfigured (void)
{
#if USB_LOG_EN
  printf("> HID Interface started.\r\n");
#endif

}
/**
* @brief  USBD_USR_DeviceConnected
*         Displays the message on LCD on device connection Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceConnected (void)
{
#if USB_LOG_EN
  printf("> USB Device Connected.\n");
#endif
}

/**
* @brief  USBD_USR_DeviceDisonnected
*         Displays the message on LCD on device disconnection Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceDisconnected (void)
{
#if USB_LOG_EN
  printf("> USB Device Disconnected.\n");
#endif
}

/**
* @brief  USBD_USR_DeviceSuspended
*         Displays the message on LCD on device suspend Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceSuspended(void)
{
#if USB_LOG_EN
    printf("> USB Device in Suspend Mode.\r\n");
#endif
  /* Users can do their application actions here for the USB-Reset */
}


/**
* @brief  USBD_USR_DeviceResumed
*         Displays the message on LCD on device resume Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceResumed(void)
{
#if USB_LOG_EN
    printf("> USB Device in Idle Mode.\r\n");
#endif
    /* Users can do their application actions here for the USB-Reset */
}
/**
* @}
*/

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/






























