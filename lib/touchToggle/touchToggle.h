#ifndef touchToggle_h
#define touchToggle_h

#include "Arduino.h"

class touchToggle
{
  public:
    touchToggle(int touchPin, int touchThreshold);
    void begin();
    bool getState(); //makes a toggle that toggles on touch and returns the state of the toggle (LOW/HIGH) as of the moment
    bool tapped(); //just returns a HIGH if detected a trough (A-D) and a low if there is no trough
  private:
    int _touchPin;
    int _touchThreshold;
    uint64_t timeAtB;
    int touchAtB; 
    bool state;
};

#endif