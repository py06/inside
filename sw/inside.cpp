/* INSIDE - Indoor quality

setup:
 - ATmel avr atmega328p
 - I2C io expander for lcd (waveshare PCF8574) - i2c @0x38
 - LCD 16x2 blue (HD44780U) thru I2C io expander to limit pins used
 - DHT22 temperature and humidity sensor (analog)
 - RTC i2c module for time keeping and timestamping - i2c @0x68
 - AT24C32 eeprom (with rtc module) to store a few data - 32kB - i2c @0x57
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
#include "rtc.h"
#include "keypad.h"

#define AREF_VOLTAGE 3.3
#define TEMP_PIN 13
#define LED_PIN 12
#define LIGHT_SENSOR A0
#define CO2_SENSOR A1

int led_state = LOW;

/* initialize the library with the numbers of the interface pins */
LiquidCrystal_I2C lcd(0x38, 16, 2);
dht DHT;

void setup()
{
	analogReference(EXTERNAL); /*tell analog input to use an external
	       			voltage ref and tie AREF pin to some
	       			voltage (3.3 in my case) */

	Serial.begin(115200);

	rtc_init();

	/* Configure LED pin as output */
	pinMode(LED_PIN, OUTPUT);
	led_state = LOW;
	digitalWrite(LED_PIN, led_state);

	/* Configure VLD_BTN pin as input */
	pinMode(VLD_BTN, INPUT);

	/* Configure LIGHT & CO2 sensor pins as input */
	pinMode(CO2_SENSOR, INPUT);
	pinMode(LIGHT_SENSOR, INPUT);

	// set up the LCD's number of columns and rows:
	lcd.begin();
	lcd.backlight();

	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("INSIDE");
	lcd.setCursor(0,1);
	lcd.print("peewhy.net");
	delay(2000);

}

static void update_screen(LiquidCrystal_I2C lcd, float temp, float hum,
			  int light, int co2lvl)
{
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("t:");
	lcd.print(temp);
	lcd.print("C  ");
	lcd.print(" l:");
	lcd.print(light);
	lcd.setCursor(0,1);
	lcd.print("h:");
	lcd.print(hum);
	lcd.print("%");
	lcd.print(" CO2:");
	lcd.print(co2lvl);
	lcd.print(" ppm");
}

void loop()
{
	static unsigned long timer = millis();
	static int deciSeconds = 0;
	static int vldSts = 0;
	static float co2lvl = 0;
	static float lightlvl = 0;

	if (millis() >= timer) {
		deciSeconds++; /* 1000 ms is equal to 10 deciSecond */
		timer += 1000;
		if (deciSeconds == 10000) /* Reset to 0 after 1000 seconds. */
			deciSeconds = 0;
		/* Get sensor values */
		co2lvl = analogRead(CO2_SENSOR);
		lightlvl = analogRead(LIGHT_SENSOR);

		vldSts = get_validButton();
		Serial.print("Valid = ");
		Serial.println(vldSts);
		Serial.print("light = ");
		Serial.print(lightlvl);
		Serial.print(" CO2 = ");
		Serial.println(co2lvl);

		rtc_digitalClockDisplay();
		if (led_state == HIGH)
			led_state = LOW;
		else
			led_state = HIGH;
		digitalWrite(LED_PIN, led_state);
		update_screen(lcd, DHT.temperature, DHT.humidity, lightlvl,
			      co2lvl);
	}
}

