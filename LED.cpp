// LED.cpp

// Include Libraries
#include "Arduino.h"
#include "HardwareSerial.h"
#include "LED.h"

// Set of functions for led during game
LED::LED(int pin) {
  LedPin = pin;
  pinMode(LedPin, OUTPUT);
};

void LED::startUp(){
  digitalWrite(LedPin,HIGH);
  delay(250);
  digitalWrite(LedPin,LOW);
  delay(250);
};

void LED::On(){
  digitalWrite(LedPin,HIGH);
};

void LED::Off(){
  digitalWrite(LedPin,LOW);
};