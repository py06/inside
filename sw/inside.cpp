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
#define SET_DAY 1
#define SET_MONTH 2
#define SET_YEAR 3
#define SET_TIME 4
#define SET_HOUR 5
#define SET_MINUTE 6
#define SAVE_RTC 7
#define MAX_SETTINGS_STATE (SAVE_RTC)

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
	char date[16];
	char strHour[2], strMinute[2];

	switch(screen_id) {
	case FIRST_SCREEN:
		lcd.clear();
		lcd.setCursor(0,0);
		rtc_getDateStr(date);
		lcd.print(date);
		lcd.setCursor(0,1);
		lcd.print(rtc_formatNumber(strHour, hour()));
		lcd.print(":");
		lcd.print(rtc_formatNumber(strMinute, minute()));
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

static void handle_standard_events()
{
	switch(events) {
	case VALID_LONG_PRESS:
		context = DISPLAY_SETTINGS;
		events &= ~(VALID_LONG_PRESS | VALID_PRESS);
		settings_state = SET_DATE;
		break;
	}
}

static void handle_settings_events()
{
	bool state_incr = false;
	int val = 0;
	static int newday, newmonth, newyear;
	static int newhour, newminute;
	char strDay[2], strMonth[2], strHour[2], strMinute[2];

	switch(events) {
	case VALID_PRESS:
		state_incr = true;;
		events &= ~VALID_PRESS;
		break;
	case VALID_LONG_PRESS:
		context = DISPLAY_STANDARD;
		events &= ~(VALID_LONG_PRESS | VALID_PRESS);
		lcd.noBlink();
		return; /* exit abruptly in case of long press */
	case UP_PRESS:
		val = 1;
		events &= ~UP_PRESS;
		break;
	case DOWN_PRESS:
		val = -1;
		events &= ~DOWN_PRESS;
		break;
	}

	switch(settings_state) {
	case SET_DATE:
		newday = day();
		newmonth = month();
		newyear = year();
		state_incr = true;
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("SET DATE:");
		lcd.setCursor(0, 1);
		lcd.print(rtc_formatNumber(strDay, day()));
		lcd.print("/");
		lcd.print(rtc_formatNumber(strMonth, month()));
		lcd.print("/");
		lcd.print(year());
	case SET_DAY:
		lcd.setCursor(1, 1);
		lcd.blink();
		newday += val;
		if (val) { /* refresh day on screen */
			lcd.setCursor(0, 1);
			lcd.print(rtc_formatNumber(strDay, newday));
			lcd.setCursor(1, 1);
		}
		break;
	case SET_MONTH:
		newmonth += val;
		lcd.setCursor(4, 1);
		if (val) { /* refresh day on screen */
			lcd.setCursor(3, 1);
			lcd.print(rtc_formatNumber(strMonth, newmonth));
			lcd.setCursor(4, 1);
		}
		break;
	case SET_YEAR:
		newyear += val;
		lcd.setCursor(9, 1);
		if (val) { /* refresh day on screen */
			lcd.setCursor(6, 1);
			lcd.print(newyear);
			lcd.setCursor(9, 1);
		}
		break;
	case SET_TIME:
		newhour = hour();
		newminute = minute();
		state_incr = true;
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("SET TIME:");
		lcd.setCursor(0,1);
		lcd.print(rtc_formatNumber(strHour, hour()));
		lcd.print(":");
		lcd.print(rtc_formatNumber(strMinute, minute()));
	case SET_HOUR:
		newhour += val;
		lcd.setCursor(1, 1);
		lcd.blink();
		if (val) { /* refresh day on screen */
			lcd.setCursor(0, 1);
			lcd.print(rtc_formatNumber(strHour, newhour));
			lcd.setCursor(1, 1);
		}
		break;
	case SET_MINUTE:
		newminute += val;
		lcd.setCursor(4, 1);
		lcd.blink();
		if (val) { /* refresh day on screen */
			lcd.setCursor(3, 1);
			lcd.print(rtc_formatNumber(strMinute, newminute));
			lcd.setCursor(4, 1);
		}
		break;
	case SAVE_RTC:
		setTime(newhour, newminute, second(),
			newday, newmonth, newyear);
		context = DISPLAY_STANDARD;
		lcd.noBlink();
		return;
	}

	if (state_incr)
		settings_state = settings_state + 1;
}

static void handle_events()
{
	if (context == DISPLAY_STANDARD)
		handle_standard_events();
	else
		handle_settings_events();
}

static void settings_screen()
{
	char strDay[2];
	char strMonth[2];
	char strHour[2];
	char strMinute[2];

	switch(settings_state) {
	case SET_DATE:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("SET DATE:");
		lcd.setCursor(0,1);
		lcd.print(rtc_formatNumber(strDay, day()));
		lcd.print("/");
		lcd.print(rtc_formatNumber(strMonth, month()));
		lcd.print("/");
		lcd.print(year());
	case SET_DAY:
	case SET_MONTH:
	case SET_YEAR:
		break;
	case SET_TIME:
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("SET TIME:");
		lcd.setCursor(0,1);
		lcd.print(rtc_formatNumber(strHour, hour()));
		lcd.print(":");
		lcd.print(rtc_formatNumber(strMinute, minute()));
	case SET_HOUR:
	case SET_MINUTE:
		break;
	case SAVE_RTC:
		context = DISPLAY_STANDARD;
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
}


void loop()
{
	t.update();
	manage_keypad();
	handle_events();
}

