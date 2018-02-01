#ifndef _TEA5767_H
#define _TEA5767_H

//**********************
// tea5767 radio control
//**********************

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
#endif

#define TEA5767_I2C_ADDR 0x60
uint8_t *pData;
uint8_t outbuffer[5];
uint8_t inbuffer[5];

typedef struct {
  uint8_t RF;       // Byte: 1 bit: 7
  #define RF_BYTE 0x0
  #define RF_MASK 0b10000000
  uint8_t BLF;      // Byte: 1 bit: 6
  #define BLF_BYTE 0x0
  #define BLF_MASK 0b01000000
  uint16_t PLL;     // Byte: 2 bit: 0:7, Byte: 2 bit: 0:5 
  #define PLL0_BYTE 0x1
  #define PLL0_MASK 0b11111111
  #define PLL1_BYTE 0x0
  #define PLL1_MASK 0b00111111
  uint8_t STEREO;   // Byte: 3 bit: 7
  #define STEREO_BYTE 0x2
  #define STEREO_MASK 0b10000000
  uint8_t PLL_IF;   // Byte: 3 bit: 0:6
  #define PLL_IF_BYTE 0x2
  #define PLL_IF_MASK 0b01111111
  uint8_t LEVEL;    // Byte: 4 bit: 4:7
  #define LEVEL_BYTE 0x3
  #define LEVEL_MASK 0b11110000
  uint8_t CI;       // Byte: 4 bit: 0:3
  #define CI_BYTE 0x3
  #define CI_MASK 0b00001111
  uint8_t unused;   // Byte: 5 bit: 0:7
  #define UNUSED_BYTE 0x4
  #define UNUSED_MASK 0b11111111
} sTea5767Status;

typedef struct {
  uint8_t Mute;       // Byte: 1 bit: 7
  uint8_t SM;      // Byte: 1 bit: 6, search mode
  uint16_t PLL;     // Byte: 2 bit: 0:7, Byte: 2 bit: 0:5 
  uint8_t SUD;   // Byte: 3 bit: 7, if SUD = 1 search forward, 0 - search backward
  uint8_t SSL;   // Byte: 3 bit: 5:6, search stop level
  uint8_t HLSI;    // Byte: 3 bit: 4, High side injection HLSI = 1 - activated
  uint8_t MS;       // Byte: 3 bit: 3, MS = 1 mono is forsed, 0 - stereo
  uint8_t ML;   // Byte: 3 bit: 2, ML = 1, left channel muted
  uint8_t MR;   // Byte: 3 bit: 1, MR = 1, right channel muted
  uint8_t SWP1;   // Byte: 3 bit: 0, SWP1 = 1, software port 1 hight
  uint8_t SWP2;   // Byte: 4 bit: 7, SWP2 = 1, software port 1 hight
  uint8_t STBY;   // Byte: 4 bit: 6, STBY = 1, standby mode activated
  uint8_t BL;   // Byte: 4 bit: 5, BL = 1, Japan, else EU
  uint8_t XTAL;   // Byte: 4 bit: 4, Clock frequency
  uint8_t SMUTE;   // Byte: 4 bit: 3, SMUTE = 1, software mute active
  uint8_t HCC;   // Byte: 4 bit: 2, HCC = 1, High Control Cut is on
  uint8_t SNC;   // Byte: 4 bit: 1, SNC = 1, Stereo Noise Canceling is on
  uint8_t SI;   // Byte: 4 bit: 0, Search indicator, SI = 1, software port 1 is output for ready flag
  uint8_t PLLREF;   // Byte: 5 bit: 7, PLLREF = 1, 6.5MHz is used as reference frequency for PLL
  uint8_t DTC;   // Byte: 5 bit: 6, De-emphasis time constant, DTC = 1 constant is 75uS alse 50uS 
  uint8_t unused;   // Byte: 5 bit: 0:5, unused 
} sTea5767Config;

sTea5767Status mTea5767Status;

void tea5767_init();
int8_t tea5767_write(I2C_HandleTypeDef *device);
int8_t tea5767_readStatus(I2C_HandleTypeDef *device);

#endif  // _TEA5767_H