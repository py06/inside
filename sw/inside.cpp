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
#include <idDHTLib.h>
#include <Timer.h>
#include <Time.h>
#include "rtc.h"
#include "keypad.h"

#define AREF_VOLTAGE 3.3
#define TEMP_PIN 3
#define LED_PIN 12
#define LIGHT_SENSOR A0
#define CO2_SENSOR A1

#define UNKNOWN_STATE -1
#define SET_DATE 0
#define SET_TIME 1

#define UNKNOWN_SCREEN -1
#define FIRST_SCREEN 0
#define SECOND_SCREEN 1
#define THIRD_SCREEN 2
#define MAX_SCREEN (THIRD_SCREEN + 1)


/* initialize the library with the numbers of the interface pins */
LiquidCrystal_I2C lcd(0x38, 16, 2);
idDHTLib DHTLib(TEMP_PIN, idDHTLib::DHT22);
Timer t;

int refreshEvent, ledEvent, sensorEvent;
int screen_id = FIRST_SCREEN;
int settings_state = UNKNOWN_STATE;

static float co2lvl = 0;
static float lightlvl = 0;
static float temp = 0;
static float humidity = 0;

static void refresh_screen(void);
static void get_sensor_data(void);

void setup()
{
	analogReference(EXTERNAL); /*tell analog input to use an external
	       			voltage ref and tie AREF pin to some
	       			voltage (3.3 in my case) */

	Serial.begin(115200);

	rtc_init();
	init_keypad();

	init_keypad();

	/* Configure LED pin as output */
	pinMode(LED_PIN, OUTPUT);

	/* Configure VLD_BTN pin as input */
	pinMode(VLD_BTN, INPUT);

	/* Configure LIGHT & CO2 sensor pins as input */
	pinMode(CO2_SENSOR, INPUT);
	pinMode(LIGHT_SENSOR, INPUT);

	/* try to get first read values ready before display */
	get_sensor_data();

	// set up the LCD's number of columns and rows:
	lcd.begin();
	lcd.backlight();

	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("INSIDE");
	lcd.setCursor(0,1);
	lcd.print("peewhy.net");
	delay(2000);

	ledEvent = t.oscillate(LED_PIN, 1000, HIGH);
	refreshEvent = t.every(3000, refresh_screen);
	sensorEvent = t.every(1000, get_sensor_data);
}

static void get_sensor_data()
{
	int sts = 0;
	int tb, hb;

	/* Get sensor values */
	co2lvl = analogRead(CO2_SENSOR);
	lightlvl = analogRead(LIGHT_SENSOR);
	sts = DHTLib.acquireAndWait();
	if (sts != IDDHTLIB_OK) {
#ifdef DEBUG
		Serial.print("Error reading DHT22: ");
		Serial.println(sts);
#endif
	} else {
		temp = DHTLib.getCelsius();
		humidity = DHTLib.getHumidity();
	}

}

static void update_screen(LiquidCrystal_I2C lcd, float temp, float hum,
			  int light, int co2lvl)
{
	switch(screen_id) {
	case FIRST_SCREEN:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print(day());
		lcd.print("/");
		lcd.print(month());
		lcd.print("/");
		lcd.print(year());
		lcd.setCursor(0,1);
		lcd.print(hour());
		lcd.print(":");
		lcd.print(minute());
		break;
	case SECOND_SCREEN:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("temp: ");
		lcd.print(temp);
		lcd.print("C");
		lcd.setCursor(0,1);
		lcd.print("humidity: ");
		lcd.print(hum);
		lcd.print("%");
		break;
	case THIRD_SCREEN:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("CO2: ");
		lcd.print(co2lvl);
		lcd.print(" ppm");
		lcd.setCursor(0,1);
		lcd.print("light: ");
		lcd.print(light);
		break;
	default:
		screen_id = UNKNOWN_SCREEN;
		break;
	}
	screen_id = (screen_id + 1) % MAX_SCREEN;
}

static void settings_screen()
{
	switch(settings_state) {
	case SET_DATE:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("SET DATE:");
		lcd.setCursor(0,1);
		lcd.print(day());
		lcd.print("/");
		lcd.print(month());
		lcd.print("/");
		lcd.print(year());
		break;
	case SET_TIME:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("SET TIME:");
		lcd.setCursor(0,1);
		lcd.print(hour());
		lcd.print(":");
		lcd.print(minute());
		break;
	default:
	       settings_state = SET_DATE;
	       break;
	}
}

static void refresh_screen()
{
#ifdef DEBUG_VERBOSE
	static int vldSts = 0;
#endif

	if (get_displayContext() == DISPLAY_STANDARD) {
		update_screen(lcd, temp, humidity,
			      lightlvl, co2lvl);
#ifdef DEBUG_VERBOSE
		vldSts = keypad_status();
		Serial.print(" keypad = ");
		Serial.println(vldSts);
		Serial.print(" light = ");
		Serial.println(lightlvl);
		Serial.print(" CO2 = ");
		Serial.println(co2lvl);
		Serial.print(" temp = ");
		Serial.println(temp);
		Serial.print(" humidity = ");
		Serial.println(humidity);
		rtc_digitalClockDisplay();
		Serial.println("");
#endif

	} else {
		settings_screen();
	}
	manage_keypad();

}


void loop()
{
	t.update();
}

