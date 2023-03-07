// LED.h
#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED {
  private:
    int LedPin;
  public:
    LED(int pin);
    void startUp();
    void On();
    void Off();
};

#endif