/*
* Hardware::Button - Library for detecting button clicks, multiple clicks and long press on a button for use with the Arduino environment.
* Copyright (c) by Andrii Tishchenko, 2016
* This work is licensed under a BSD style license.
* https://github.com/andriitishchenko/HardwareButton
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include <inttypes.h>

/*
|Hardware
|- class Button;
*/
namespace Hardware {
extern "C" {
  class Button;
  typedef void (*callbackButtonEvent)(Button&);

#ifndef ulong_type
#define ulong_type
  typedef unsigned long ulong;
#endif
}

/*
class Button provide a simple way to handle hardware button iteractions

example:
#include "Button.h"
Hardware::Button button(2, false);
or
Hardware::Button button(2);
...
loop(){
  button.update();
}
*/
class Button
{
public:

  // pin: hardware pin
  // activeLow: depends on HIGH or LOW connection state
  Button(int pin, int activeLow);

  // pin: hardware pin
  // LOW load for connection state
  Button(int pin);

  //this function must invoke from main LOOP
  void update();

  // set millisec for press detection
  // default 600
  void setPressTimeout(int value);

  // set millisec for long press detection
  // default 1000
  void setLongPressTimeout(int value);

  // set millisec for multi press detection
  // default 260
  void setMultiPressTimeout(int value);

  // callback for button press
  callbackButtonEvent onPress;

  // callback for button long press
  callbackButtonEvent onLongPress;

  // callback while button holding pressed
  callbackButtonEvent onLongPressing;

  // callback for on multiple press, count of press get from property .pressCount
  callbackButtonEvent onMultiplePress;

  //button identifier
  int id;

  // press count for multiple presses
  int pressCount;

  // button status
  // readonly
  bool isPressed;

private:
  void init(int pin, int activeLow);

  int _pin; //hardware pin
  int _pressTimeout; //press button speed setting (600)
  int _longPressTimeout; //long press delay setting (100)
  int _multiPressTimeout; //delay between multiple press (260)

  //button states
  int _buttonReleased;
  int _buttonPressed;

  //helper vars
  ulong _startTime;
  ulong _releaseTime;
};
}
#endif


