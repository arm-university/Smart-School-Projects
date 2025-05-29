#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  lcd.init();                      // Initialize the lcd 
  lcd.backlight();                 // Turn the backlight on
  lcd.setCursor(2,0);              // Set cursor col 2 row 0
  lcd.print("Hello, world!");      // Output a string
  lcd.setCursor(1,1);              // Set cursor col 1 row 1
  lcd.print("Arm Education");      // Output a string
}

void loop()
{
}
