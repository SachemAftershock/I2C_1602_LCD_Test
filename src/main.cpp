#include <Arduino.h>

/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(1, 0); // set the cursor to column 1, line 0
  lcd.print("AFTERSHOCK 263");  // Print a message to the LCD
  lcd.setCursor(2, 1); // set the cursor to column 2, line 1
  lcd.print("Charged Up !");  // Print a message to the LCD.
  delay(3000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0); // set the cursor to column 0jjhkjh, line 0
  lcd.print("Status Busy/Idle");  // Print a message to the LCD

  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      //lcd.write(Serial.read());
      lcd.setCursor(2, 1); // set the cursor to column 2, line 1
      lcd.print("ERROR: ");
      lcd.write(Serial.read());
    }
  }
}