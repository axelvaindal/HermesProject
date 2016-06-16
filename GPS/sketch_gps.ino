#include "GPS.h"
#include "Arduino.h"



GPS gps;

//SoftwareSerial ss(6, 5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //ss.begin(9600);
}

void loop() {
  
  gps.read();
}
