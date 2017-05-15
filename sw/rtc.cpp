#include <stdio.h>
#include <Arduino.h>
#include <DS3232RTC.h>
#include <Time.h>

void rtc_init()
{
	setSyncProvider(RTC.get);   // the function to get the time from the RTC
#ifdef DEBUG
	if(timeStatus() != timeSet)
		Serial.println("Unable to sync with the RTC");
	else
		Serial.println("RTC has set the system time");
#endif
}

int rtc_saveDateTime(int hr,int min,int sec,int dy, int mnth, int yr){
	tmElements_t tm;
	time_t t;

	if( yr > 99)
		yr = yr - 1970;
	else
		yr += 30;
	tm.Year = yr;
	tm.Month = mnth;
	tm.Day = dy;
	tm.Hour = hr;
	tm.Minute = min;
	tm.Second = sec;
	t = makeTime(tm);
	RTC.set(t);
	setTime(t);
	return 0;
}

void rtc_getDateStr(char *date)
{
	sprintf(date, "%s ", dayShortStr(weekday()));
	if (day() < 10)
		sprintf(date + 4, "0%d ", day());
	else
		sprintf(date + 4, "%2d ", day());

	sprintf(date + 7, "%s ", monthShortStr(month()));
	sprintf(date + 11,"%4d", year());
}

char *rtc_formatNumber(char *str, int number)
{
	if (number < 10)
		sprintf(str, "0%d", number);
	else
		sprintf(str, "%2d", number);
	return str;
}

void rtc_printDigits(int digits)
{
	//utility function for digital clock display: prints preceding
	//colon and leading 0
	Serial.print(':');
	if(digits < 10)
		Serial.print('0');
	Serial.print(digits);
}

void rtc_digitalClockDisplay(void)
{
#ifdef DEBUG_VERBOSE
	//digital clock display of the time
	Serial.print(hour());
	rtc_printDigits(minute());
	rtc_printDigits(second());
	Serial.print(' ');
	Serial.print(day());
	Serial.print(' ');
	Serial.print(month());
	Serial.print(' ');
	Serial.print(year());
	Serial.println();
#endif
}

