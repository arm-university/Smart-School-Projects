#include "arduino_secrets.h"
#include "thingProperties.h"
// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)

void setup() {
  Serial.begin(9600);
  delay(1500); 
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);  
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
    // print the sensor values:
  Serial.print(analogRead(xpin));
  xAxis=int(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  yAxis=int(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  zAxis=int(analogRead(xpin));
  // delay before next reading:
  delay(100);
  
  
}


void onXpinChange() {
  // Do something
}

void onYpinChange() {
  // Do something
}

void onZpinChange() {
  // Do something
}

void onXAxisChange() {
  // Do something
}

void onYAxisChange() {
  // Do something
}

void onZAxisChange() {
  // Do something
}
