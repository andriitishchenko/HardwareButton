# HardwareButton
Hardware::Button - Library for detecting button clicks, multiple clicks and long press on a button for use with the Arduino environment.

# Example
```
Hardware::Button button = Hardware::Button(2);
//  
  button.onPress = &onPress;
  button.onLongPress = &onLongPress;
  button.onLongPressing = &onLongPressing;
  button.onMultiplePress = &onMultiplePress;

//optional settings
  button.id = 100;
  button.setPressTimeout(600);
  button.setLongPressTimeout(1000);
  button.setMultiPressTimeout(260);
```
# Usage 
1 Install library

2 open demo project "HardwareButton->ButtonDemo"
