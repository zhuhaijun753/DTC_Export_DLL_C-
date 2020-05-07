/**
  ******************************************************************************
  * @file    usbd_hid_core.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   header file for the usbd_hid_core.c file.
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

#ifndef __USB_HID_CORE_H_
#define __USB_HID_CORE_H_

#include  <2_Middle\5_Communication\1_Usb\2_Core\Libraries\STM32_USB_Device_Library\Core\inc\usbd_ioreq.h>

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_HID
  * @brief This file is the Header file for USBD_msc.c
  * @{
  */


/** @defgroup USBD_HID_Exported_Defines
  * @{
  */
#define USB_HID_CONFIG_DESC_SIZ       34
#define USB_HID_DESC_SIZ              9
#define HID_MOUSE_REPORT_DESC_SIZE    85

#define HID_DESCRIPTOR_TYPE           0x21
#define HID_REPORT_DESC               0x22


#define HID_REQ_SET_PROTOCOL          0x0B
#define HID_REQ_GET_PROTOCOL          0x03

#define HID_REQ_SET_IDLE              0x0A
#define HID_REQ_GET_IDLE              0x02

#define HID_REQ_SET_REPORT            0x09
#define HID_REQ_GET_REPORT            0x01

#define NO_REQ                        0xFF

#define MSC_HID_COMPOLap DangE_CFG_LEN (USB_LEN_CFG_DESC + 2*USB_LEN_IF_DESC + USB_HID_DESC_SIZ + 3*USB_LEN_EP_DESC)
/**
  * @}
  */
typedef struct _structHidOutData
{
    unsigned int iReportId;
    unsigned int iCommand;
    unsigned int iAddress;
    unsigned int iSize;
    unsigned int iFlashBuffer[128];
} structHidOutData;   /*Data from Host to device*/

typedef struct _structHidInData
{
    unsigned int   iInSize;             /*Buffer size to send to PC*/
    unsigned char* p_bDataBuffer;       /*Buffer to send to PC*/
} structHidInData;           /*Data from Device to host*/

typedef struct _structUSBData
{
    structHidOutData strtHidOut;
    structHidInData  strtHidIn;
} structUSBData;
/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */


/**
  * @}
  */



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */

extern USBD_Class_cb_TypeDef  USBD_HID_cb;
extern USBD_Class_cb_TypeDef  USBD_MSC_cb;

extern unsigned char  blUsbForceStallFlag;
extern unsigned char  blUsbIsBusy;

/**
  * @}
  */

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
uint8_t USBD_HID_SendReport (USB_OTG_CORE_HANDLE  *pdev,
                                 uint8_t *report,
                                 uint16_t len);
/**
  * @}
  */

#endif  // __USB_HID_CORE_H_
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
