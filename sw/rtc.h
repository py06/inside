void rtc_init(void);
void rtc_getDateStr(char *);
void rtc_digitalClockDisplay(void);
char *rtc_formatNumber(char *, int);
int rtc_saveDateTime(int, int, int, int, int, int);

