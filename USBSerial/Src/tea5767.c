//**********************
// tea5767 radio control
//**********************

#include <string.h>
#include "stm32f1xx_hal.h"
#include "tea5767.h"

#include "usb_logger.h"

void tea5767_clearbuffers() {
  memset(outbuffer, 0, 5);
  memset(inbuffer, 0, 5);
}

void tea5767_clearsttus() {
  mTea5767Status.RF = 0;       // Byte: 1 bit: 7
  mTea5767Status.BLF = 0;      // Byte: 1 bit: 6
  mTea5767Status.PLL = 0;     // Byte: 2 bit: 0:7, Byte: 2 bit: 0:5 
  mTea5767Status.STEREO = 0;   // Byte: 3 bit: 7
  mTea5767Status.PLL_IF = 0;   // Byte: 3 bit: 0:6
  mTea5767Status.LEVEL = 0;    // Byte: 4 bit: 4:7
  mTea5767Status.CI = 0;       // Byte: 4 bit: 0:3
  mTea5767Status.unused = 0;   // Byte: 5 bit: 0:7
}

void tea5767_init() {
  _log("tea5767_init()");
  tea5767_clearbuffers();
  tea5767_clearsttus();
}

char* statustostr() {
  return mLogString;
}

int8_t tea5767_readStatus(I2C_HandleTypeDef *device) {
  _log("tea5767_readStatus()");
  int8_t result = 0;

  if(HAL_OK == HAL_I2C_Master_Transmit(device, TEA5767_I2C_ADDR << 1, outbuffer, 1, 100)) {
    HAL_Delay(20);
    memset(inbuffer, 0, 5);
    if(HAL_OK == HAL_I2C_Master_Receive(device,  TEA5767_I2C_ADDR << 1, inbuffer, 5, 100)) {
      _log(statustostr());
    } else {
      HAL_I2C_GetError(device);
      result = -1;
    }
  } else {
    HAL_I2C_GetError(device);
    result = -1;
  }

  return result;
}
