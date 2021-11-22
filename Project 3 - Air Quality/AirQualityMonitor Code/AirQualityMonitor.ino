#include "arduino_secrets.h"
#include "thingProperties.h"
#include "Air_Quality_Sensor.h"
AirQualitySensor sensor(A0);
  

void setup(void) {
  Serial.begin(9600);
  delay(1500); 

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  if (sensor.init()) {
        Serial.println("Sensor ready.");
    } else {
        Serial.println("Sensor ERROR!");
    }
}

void loop(void) {
    int quality = sensor.slope();
    int reading;
    ArduinoCloud.update();
    reading=(sensor.getValue());
    Serial.print("Sensor value: ");
    Serial.println(sensor.getValue());

    if (quality == AirQualitySensor::FORCE_SIGNAL) {
        Serial.println("High pollution! Force signal.");
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        Serial.println("High pollution!");
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
        Serial.println("Low pollution!");
    } else if (quality == AirQualitySensor::FRESH_AIR) {
        Serial.println("Fresh air.");
    }

    delay(1000);
}
  



void onReadingChange() {
  // Do something
}
