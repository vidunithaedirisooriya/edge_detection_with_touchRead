#include "Arduino.h"
#include "touchToggle.h"

touchToggle::touchToggle(int touchPin, int touchThreshold){
    _touchPin = touchPin;
    _touchThreshold = touchThreshold;
    timeAtBForGetState;
    timeAtBForTapped;
    touchAtBForGetState;
    touchAtBForTapped;
    state=LOW;
}

void touchToggle::begin(){
    pinMode(_touchPin,INPUT);
}

bool touchToggle::getState(){

  if(touchRead(_touchPin)<_touchThreshold){  //if the touch value has crossed touchThreshold while going down (if finger is in contact)
    touchAtBForGetState=touchRead(_touchPin);//record BC
    timeAtBForGetState=millis();
  }
  if(touchRead(_touchPin)>_touchThreshold&&  //if finger has crossed touchThreshold while going up (finger is lifting off)
    touchRead(_touchPin)>touchAtBForGetState&&
    (millis()-timeAtBForGetState)>100   //for stability and to prevent twitching
  ){ //see if it is CD
    touchAtBForGetState=touchRead(_touchPin);
    state=!state;
  }
  return state;
}

bool touchToggle::tapped(){

  if(touchRead(_touchPin)<_touchThreshold){  //if the touch value has crossed touchThreshold while going down (if finger is in contact)
    touchAtBForTapped=touchRead(_touchPin);//record BC
    timeAtBForTapped=millis();
  }
  if(touchRead(_touchPin)>_touchThreshold&&  //if finger has crossed touchThreshold while going up (finger is lifting off)
    touchRead(_touchPin)>touchAtBForTapped&&
    (millis()-timeAtBForTapped)>100   //for stability and to prevent twitching
  ){ //see if it is CD
    touchAtBForTapped=touchRead(_touchPin);
    tap=HIGH;
  }else{
    tap=LOW;
  }
  return tap;
}