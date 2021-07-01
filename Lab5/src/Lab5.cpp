/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/WindyCity_IOT/Labs/Lab5/src/Lab5.ino"
/*
 * Project Lab5
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
#line 8 "d:/WindyCity_IOT/Labs/Lab5/src/Lab5.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
uint16_t value;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D5, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  value = analogRead(A5);
  Serial.println(value);

  uint16_t intensity = map(value, 0, 4096, 0, 255);
  analogWrite(D5, intensity);
  delay(300);
}