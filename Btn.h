// Btn.h
#ifndef Btn_h
#define Btn_h

#include <Arduino.h>

class Btn {
  private:
    int BtnPin;
  public:
    Btn(int pin);
    bool press();
};

#endif