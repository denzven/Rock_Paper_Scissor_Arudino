// Music.h
#ifndef Music_h
#define Music_h

#include <Arduino.h>

class Music {
  private:
    int BuzzerPin;
  public:
    Music(int pin);
    void startUp();
    void win();
    void lose();
    void draw();
};

#endif
