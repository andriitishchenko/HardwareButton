 #include "hardware.h"

//DEMO APPLICATION
//details here 
//https://123d.circuits.io/circuits/445550-button-class-press-long-press-double-press/edit

//button declaration
Hardware::Button button(2, false);
//or
//Hardware::Button button(2);

//methods
void onPress(Hardware::Button& sender)
{
  Serial.println(" onPress ");
}

void onLongPress(Hardware::Button& sender)
{
  Serial.println(" onLongPress ");
}

void onLongPressing(Hardware::Button& sender)
{
  Serial.println(" onLongPressing ");
}

void onMultiplePress(Hardware::Button& sender)
{
  Serial.print(sender.pressCount);
  Serial.println(" onMultiplePress ");
}


void setup() {
  Serial.begin(9600);
  button.onPress = onPress;
  button.onLongPress=onLongPress;
  button.onLongPressing=onLongPressing;
  button.onMultiplePress=onMultiplePress;
  
  //optional settings
  button.id = 100;
  button.setPressTimeout(600);
  button.setLongPressTimeout(1000);
  button.setMultiPressTimeout(260);

}

void loop() {
  button.update();
  delay(100);
}

