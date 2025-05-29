
#include <Arduino_MKRGPS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int i = 1;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  if (GPS.begin(GPS_MODE_SHIELD)) {
  //if (GPS.begin()) { // Use this cand remove line 16 if using cable instead of shield.

    //lcd.print("GPS ready.");
    Serial.println("GPS ready");
    lcd.setCursor(0,0);
    lcd.print("GPS ready");
  } else {
    //lcd.print("GPS failed.");
    Serial.println("GPS failed");
    lcd.setCursor(0,0);
    lcd.print("GPS failed");
  }
}

void loop() {
  if (GPS.available()) {
    //lcd.clear();
    // read GPS values
    float latitude   = GPS.latitude();
    float longitude  = GPS.longitude();
    float altitude   = GPS.altitude();
    int   satellites = GPS.satellites();
    Serial.print("LAT: ");
    Serial.println(latitude, 7);
    lcd.setCursor(0,0);
    lcd.print("LAT:");
    lcd.print(latitude, 7);
    Serial.print("LON: ");
    Serial.println(longitude, 7);
    lcd.setCursor(0,1);
    lcd.print("LON:");
    lcd.print(longitude, 7);
    delay(1000);
    Serial.print("ALT: ");
    Serial.print(altitude);
    Serial.println("m");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALT: ");
    lcd.println(altitude, 7);
    lcd.setCursor(0,1);
    Serial.print("SAT: ");
    Serial.println(satellites);
    lcd.print("SAT: ");
    lcd.println(satellites, 7);
    delay(1000);
  }
}
