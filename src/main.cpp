#include <Arduino.h>
#include <touchToggle.h>
// Here, it is attempted to find a functioning edgeDetection for TouchRead, in hopes of making good touch toggle switches
// read the README.md to understand the weird variable names.


touchToggle toggleOn13(13,20);

void setup() {
  Serial.begin(115200);
  toggleOn13.begin();
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN,toggleOn13.getState());
  delay(50);
  //uncomment the following line to get the touch value 
  // Serial.println(touchRead(touchPin));
}

