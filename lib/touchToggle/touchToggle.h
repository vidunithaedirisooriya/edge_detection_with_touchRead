#ifndef touchToggle_h
#define touchToggle_h

#include "Arduino.h"

class touchToggle
{
  public:
    touchToggle(int touchPin, int touchThreshold);
    void begin();
    bool getState();
  private:
    int _touchPin;
    int _touchThreshold;
    uint64_t timeAtB;
    int touchAtB; 
    bool state;
};

#endif