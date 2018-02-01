//**********************
// joystick
//**********************

#include "joystick.h"


void initJoystickStatus() {
  joystickStatus.mJoystickButtonState = JSTATE_UNKNOWN;
  joystickStatus.mHorizontal = JSTATE_CENTER;
  joystickStatus.mVertical = JSTATE_CENTER;
}

bool updateJoystickStatus(const int32_t newState) {
  bool isChanged = false;
  switch (joystickStatus.mJoystickButtonState)  {
    case JSTATE_UNKNOWN : {
      if( 0 == newState ) {
        joystickStatus.mJoystickButtonState = JSTATE_PRESSED;
        isChanged = true;
      } else if( 1 == newState ) {
        joystickStatus.mJoystickButtonState = JSTATE_NOT_PRESSED;
        isChanged = true;
      }
      break;
    }
    case JSTATE_NOT_PRESSED: {
      if( 0 == newState ) {
        joystickStatus.mJoystickButtonState = JSTATE_PRESSED;
        isChanged = true;
      }
      break;
    }
    case JSTATE_PRESSED: {
      if( 1 == newState ) {
        joystickStatus.mJoystickButtonState = JSTATE_NOT_PRESSED;
        isChanged = true;
      }
      break;
    }
    default: {
      break; 
    }
  }
  return isChanged;
}

// -1 low 
//  0 center
//  1 high
int8_t calculatePosition( const uint16_t pos ) {
    int8_t state = 0;
    return state;
}

bool updateJoystickPosition(const uint16_t X, const uint16_t Y)
{
  bool isChanged = false;
  eJoystickState newXState = JSTATE_UNDEFINED;
  eJoystickState newYState = JSTATE_UNDEFINED;

  if((JADC_LOW_LIMIT > X) ) {
    newXState = JSTATE_LEFT;
  } else if(JADC_UP_LIMIT < X) {
    newXState = JSTATE_RIGHT;
  } else if((JADC_CENTER_LOW < X) && (JADC_CENTER_HIGH > X)) {
    newXState = JSTATE_CENTER;
  }

  if((JSTATE_UNDEFINED != newXState) && (newXState != joystickStatus.mHorizontal)) {
    joystickStatus.mHorizontal = newXState;
    isChanged = true;
  }

  if(JADC_LOW_LIMIT > Y) {
    newYState = JSTATE_DOWN;
  } else if(JADC_UP_LIMIT < Y) {
    newYState = JSTATE_UP;
  } else if((JADC_CENTER_LOW < Y) && (JADC_CENTER_HIGH > Y)) {
    newYState = JSTATE_CENTER;
  }

  if((JSTATE_UNDEFINED != newYState) && (newYState != joystickStatus.mVertical)) {
    joystickStatus.mVertical = newYState;
    isChanged = true;
  }

  return isChanged;
}
