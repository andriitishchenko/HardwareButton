#include "hardware.h"

/*
* DEMO APPLICATION
* example
* https://123d.circuits.io/circuits/445550-button-class-press-long-press-double-press
* https://123d.circuits.io/circuits/1691281-single-double-long-button
*/
Hardware::Button button = Hardware::Button(2, false);
Hardware::Button *button_pt = new Hardware::Button(2, false);
void onPress(Hardware::Button& sender)
{
  Serial.print(" onPress ");
  Serial.println(sender.id);
}

void onLongPress(Hardware::Button& sender)
{
  Serial.print(" onLongPress ");
  Serial.println(sender.id);
}

void onLongPressing(Hardware::Button& sender)
{
  Serial.print(" onLongPressing ");
  Serial.println(sender.id);
}

void onMultiplePress(Hardware::Button& sender)
{
  Serial.print(sender.pressCount);
  Serial.print(" onMultiplePress ");
  Serial.println(sender.id);
}

void setup() {
  Serial.begin(9600);
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
  
  button_pt->onPress = &onPress;
  button_pt->onLongPress = &onLongPress;
  button_pt->onLongPressing = &onLongPressing;
  button_pt->onMultiplePress = &onMultiplePress;

//optional settings
  button_pt->id = 200;
  button_pt->setPressTimeout(600);
  button_pt->setLongPressTimeout(1000);
  button_pt->setMultiPressTimeout(260);
}

void loop() {
  button.update();
  button_pt->update();
  delay(100);
}

