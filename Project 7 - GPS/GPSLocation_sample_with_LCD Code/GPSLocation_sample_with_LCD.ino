/*
  GPS Location

  This sketch uses the GPS to determine the location of the board
  and prints it to the Serial monitor.

  Circuit:
   - MKR board
   - MKR GPS attached via I2C cable

  This example code is in the public domain.
*/

#include <Arduino_MKRGPS.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// initialize the library with the numbers of the interface pins

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // If you are using the MKR GPS as shield, change the next line to pass
  // the GPS_MODE_SHIELD parameter to the GPS.begin(...)

  if (!GPS.begin()) {
    Serial.println("Failed to initialize GPS!");
    while (1);
  }


}

void loop() {
  
  Serial.println("standby");

  delay(5000);


  Serial.print("delay ");

  for (int i = 0; i < 10; i++) {

    delay(1000);

    Serial.print(".");

  }

  Serial.println();
  
  Serial.print("Location: ");

  // wake up the GPS

  Serial.println("wakeup");

  GPS.wakeup();

  Serial.print("wait location ... ");

  // wait for new GPS data to become available

  unsigned long startMillis = millis();

  while (!GPS.available());

  unsigned long endMillis = millis();

  Serial.print(endMillis - startMillis);

  Serial.println(" ms");

  // read GPS values

  float latitude   = GPS.latitude();

  float longitude  = GPS.longitude();

  float altitude   = GPS.altitude();

  int   satellites = GPS.satellites();

  // print GPS values

  Serial.println();

  Serial.println("Location: ");

  Serial.println(latitude, 7);
  
  //lcd.println(latitude, 7);

  Serial.println(", ");

  Serial.println(longitude, 7);

  Serial.print("Altitude: ");

  Serial.print(altitude);

  Serial.println("m");

  Serial.print("Number of satellites: ");

  Serial.println(satellites);
  
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  
  lcd.print(longitude,7);
  
  lcd.setCursor(0, 1);
  
  lcd.print(latitude,7);
  
  delay(5000);
  
  Serial.println();

}