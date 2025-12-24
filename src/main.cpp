#include <Arduino.h>
// Here, it is attempted to find a functioning edgeDetection for TouchRead, in hopes of making good touch toggle switches
// read the README.md to understand the weird variable names.

#define touchPin 13
#define threshold 20 //You may have to change this. to find a new threshold, uncomment the last line and observe the value when touched and not.

void setup() {
  Serial.begin(115200);
  pinMode(touchPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}
int trough;
bool state;
int touchAtB; 
uint64_t timeAtB;

void loop() {

  if(touchRead(touchPin)<threshold){  //if the touch value has crossed threshold while going down (if finger is in contact)
    touchAtB=touchRead(touchPin);//record BC
    timeAtB=millis();
  }
  if(touchRead(touchPin)>threshold&&  //if finger has crossed threshold while going up (finger is lifting off)
    touchRead(touchPin)>touchAtB&&
    (millis()-timeAtB)>100   //for stability and to prevent twitching
  ){ //see if it is CD
    Serial.println("trough detected");
    touchAtB=touchRead(touchPin);
    state=!state;
  }
  
  digitalWrite(LED_BUILTIN,state);
  delay(50);
  //uncomment the following line to get the touch value 
  // Serial.println(touchRead(touchPin));
}
