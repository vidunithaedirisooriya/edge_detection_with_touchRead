#include "Arduino.h"
#include "touchToggle.h"

touchToggle::touchToggle(int touchPin, int touchThreshold){
    _touchPin = touchPin;
    _touchThreshold = touchThreshold;
    timeAtB;
    touchAtB;
    state;
}

void touchToggle::begin(){
    pinMode(_touchPin,INPUT);
}

bool touchToggle::getState(){

  if(touchRead(_touchPin)<_touchThreshold){  //if the touch value has crossed touchThreshold while going down (if finger is in contact)
    touchAtB=touchRead(_touchPin);//record BC
    timeAtB=millis();
  }
  if(touchRead(_touchPin)>_touchThreshold&&  //if finger has crossed touchThreshold while going up (finger is lifting off)
    touchRead(_touchPin)>touchAtB&&
    (millis()-timeAtB)>100   //for stability and to prevent twitching
  ){ //see if it is CD
    touchAtB=touchRead(_touchPin);
    state=!state;
  }
  return state;
}

bool touchToggle::tapped(){

  if(touchRead(_touchPin)<_touchThreshold){  //if the touch value has crossed touchThreshold while going down (if finger is in contact)
    touchAtB=touchRead(_touchPin);//record BC
    timeAtB=millis();
  }
  if(touchRead(_touchPin)>_touchThreshold&&  //if finger has crossed touchThreshold while going up (finger is lifting off)
    touchRead(_touchPin)>touchAtB&&
    (millis()-timeAtB)>100   //for stability and to prevent twitching
  ){ //see if it is CD
    touchAtB=touchRead(_touchPin);
    state=HIGH;
  }else{
    state=LOW;
  }
  return state;
}