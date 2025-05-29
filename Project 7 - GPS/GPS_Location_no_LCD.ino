#include <Arduino_MKRGPS.h>

void setup() {
  // put your setup code here, to run once:
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  if (GPS.begin(GPS_MODE_SHIELD)) {
  //if (GPS.begin()) { // Use this cand remove line 7 if using cable instead of shield.
    //lcd.print("GPS ready.");
    Serial.println("GPS ready");
  } else {
    //lcd.print("GPS failed.");
    Serial.println("GPS failed");
  }
}

void loop() {
  if (GPS.available()) {
    // read GPS values
    float latitude   = GPS.latitude();
    float longitude  = GPS.longitude();
    float altitude   = GPS.altitude();
    int   satellites = GPS.satellites();
    Serial.print("LAT: ");
    Serial.println(latitude, 7);
    Serial.print("LON: ");
    Serial.println(longitude, 7);
    Serial.print("ALT: ");
    Serial.print(altitude);
    Serial.println("m");
    Serial.print("SAT: ");
    Serial.println(satellites);
    delay(1000);
  }
}
