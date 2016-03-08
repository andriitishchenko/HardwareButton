/*
* Hardware::Button - Library for detecting button clicks, multiple clicks and long press on a button for use with the Arduino environment.
* Copyright (c) by Andrii Tishchenko, 2016
* This work is licensed under a BSD style license.
* https://github.com/andriitishchenko/HardwareButton
* https://123d.circuits.io/circuits/445550-button-class-press-long-press-double-press
* https://123d.circuits.io/circuits/1691281-single-double-long-button
*/

#include "Button.h"

namespace Hardware
{

void Button::init(int pin, int activeLow) {
  pinMode(pin, INPUT);
  _pin = pin;

  _pressTimeout = 600;
  _longPressTimeout = 1000;
  _multiPressTimeout = 260;

  isPressed = false;


  if (activeLow) {
    _buttonReleased = HIGH;
    _buttonPressed = LOW;
    digitalWrite(pin, HIGH);
  } else {
    _buttonReleased = LOW;
    _buttonPressed = HIGH;
  } // if


  onPress = NULL;
  onLongPress = NULL;
  onLongPressing = NULL;
  onMultiplePress = NULL;
}


Button::Button(int pin) {
  this->init(pin, false);
}

Button::Button(int pin, int activeLow)
{
  this->init(pin, activeLow);
} // Button


void Button::setPressTimeout(int value) {
  _pressTimeout = value;
}

void Button::setLongPressTimeout(int value) {
  _longPressTimeout = value;
}

void Button::setMultiPressTimeout(int value) {
  _multiPressTimeout = value;
}

void Button::update(void)
{
  int pinState = digitalRead(_pin);
  ulong now = millis();

  if (pinState == _buttonPressed) {
    if (_startTime != 0)
    {
      if ((ulong)(now - _startTime) > _pressTimeout) { //holding button
        if (onLongPressing) onLongPressing(*this);
      }
    }
    else {
      _startTime = now;
    }
    isPressed = true;
  }
  else if (_startTime != 0) {
    if ((ulong)(now - _startTime) > _longPressTimeout) //button released
    {
      _releaseTime = 0;
      if (onLongPress) onLongPress(*this);
    }
    else {
      //expectng multipress:
      if (_releaseTime != 0)
      {
        pressCount++;
      }
      else
      {
        pressCount = 1;
      }
      _releaseTime = now;
    }
    _startTime = 0;
    isPressed = false;
  }

  if (_releaseTime != 0)
  {
    if ( (ulong)(now - _releaseTime) > _multiPressTimeout)
    {
      if (pressCount == 1)
      {
        if (onPress) onPress(*this);
      }
      else
      {
        if (onMultiplePress) onMultiplePress(*this);
      }
      _releaseTime = 0;
      _startTime = 0;
    }
  }
}
}

