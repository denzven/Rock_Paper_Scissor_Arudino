//Btn.cpp

// Include Libraries
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Btn.h"

// Set of functions for Btn Onject during game
Btn::Btn(int pin) {
  BtnPin = pin;
  pinMode(BtnPin, INPUT_PULLUP);
};

// Checks if pressed btn state is true or not
bool Btn::press(){
  return digitalRead(BtnPin) == LOW;
};