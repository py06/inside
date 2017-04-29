/* INSIDE - Indoor quality

setup:
 - ATmel avr atmega328p
 - I2C io expander for lcd (waveshare PCF8574)
 - LCD 16x2 blue (HD44780U) thru I2C io expander
 to limit pin used
 - DHT22 temperature and humidity sensor (analog)
 - RTC i2c module for time keeping and timestamping
 - Push buttons on digital pins for small keyboard

 Copyright 2017 Pierre-Yves Kerbrat

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <DS3232RTC.h>
#include <Time.h>

#define AREF_VOLTAGE 3.3
#define TEMP_PIN 13
#define LED_PINi 12
#define LIGHT_SENSOR A0

int led_state = LOW;

/* initialize the library with the numbers of the interface pins */
LiquidCrystal_I2C lcd(0x38, 16, 2);
dht DHT;

void printDigits(int digits)
{
	//utility function for digital clock display: prints preceding
	//colon and leading 0
	Serial.print(':');
	if(digits < 10)
		Serial.print('0');
	Serial.print(digits);
}

void digitalClockDisplay(void)
{
	//digital clock display of the time
	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.print(' ');
	Serial.print(day());
	Serial.print(' ');
	Serial.print(month());
	Serial.print(' ');
	Serial.print(year());
	Serial.println();
}

void setup()
{
	analogReference(EXTERNAL); /*tell analog input to use an external
	       			voltage ref and tie AREF pin to some
	       			voltage (3.3 in my case) */

	Serial.begin(115200);

	setSyncProvider(RTC.get);   // the function to get the time from the RTC
	if(timeStatus() != timeSet)
		Serial.println("Unable to sync with the RTC");
	else
		Serial.println("RTC has set the system time");


	// set up the LCD's number of columns and rows:
	lcd.begin();
	lcd.backlight();

	lcd.clear();                  // start with a blank screen
	lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
	lcd.print("LM35 v2");    // change text to whatever you like. keep it clean!
	lcd.setCursor(0,1);           // set cursor to column 0, row 1
	lcd.print("peewhy.net");
	delay(2000);

}

void loop()
{
	digitalClockDisplay();
	delay(1000);
}

