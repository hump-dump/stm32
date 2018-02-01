#ifndef _JOYSTICK_H
#define _JOYSTICK_H

//**********************
// joystick
//**********************

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
#endif

typedef uint8_t bool;
#define true 1
#define false 0

typedef enum {
  JSTATE_UNKNOWN,
  JSTATE_NOT_PRESSED,
  JSTATE_PRESSED
} eJoystickButtonState;

typedef enum {
  JSTATE_UNDEFINED,
  JSTATE_CENTER,
  JSTATE_UP,
  JSTATE_DOWN,
  JSTATE_LEFT,
  JSTATE_RIGHT
} eJoystickState;

#define JADC_CENTER_LOW 1800
#define JADC_CENTER_HIGH 2200
#define JADC_LOW_LIMIT 1000
#define JADC_UP_LIMIT 3000

struct sJoystickStatus {
  eJoystickButtonState mJoystickButtonState;
  eJoystickState mHorizontal;
  eJoystickState mVertical;
} joystickStatus;

void initJoystickStatus();
bool updateJoystickStatus(const int32_t newState);
bool updateJoystickPosition(const uint16_t X, const uint16_t Y);

#endif  // _JOYSTICK_H