//**********************
// usb_logger
//**********************

#include <string.h>

#include "usbd_cdc_if.h"

#include "usb_logger.h"

void _log( char *str ) {
  CDC_Transmit_FS((unsigned char *)str, strnlen(str,MAX_LOG_STR_LEN));
  HAL_Delay(20);
  CDC_Transmit_FS((unsigned char *)"\n\r", 2);
  HAL_Delay(20);
}
