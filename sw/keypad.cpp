#include <Arduino.h>
#include "OneButton.h"
#include "keypad.h"

int context = DISPLAY_STANDARD;
int events = 0;

OneButton valid(VLD_BTN, true);
OneButton up(UP_BTN, true);
OneButton down(DWN_BTN, true);

int get_displayContext()
{
	return context;
}

int get_validButton()
{
	return digitalRead(VLD_BTN);
}

int get_upButton()
{
	return digitalRead(UP_BTN);
}
int get_downButton()
{
	return digitalRead(DWN_BTN);
}

int keypad_status()
{
	return get_validButton()<<2 | get_upButton()<<1 | get_downButton();
}

void manage_keypad(){
	valid.tick();
	up.tick();
	down.tick();
}

static void validLongPress() {
#ifdef DEBUG
	Serial.println("VALID button: long press event");
#endif
	events |= VALID_LONG_PRESS;
}

static void validPress() {
	events |= VALID_PRESS;
}

static void upPress() {
#ifdef DEBUG
	Serial.println("UP button: click event");
#endif
	events |= UP_PRESS;
}

static void downPress() {
#ifdef DEBUG
	Serial.println("DOWN button: click event");
#endif
	events |= DOWN_PRESS;
}

void init_keypad()
{
	context = DISPLAY_STANDARD;
	events = 0;
	valid.setPressTicks(LONG_PRESS_TIME);
	valid.attachLongPressStart(validLongPress);
	valid.attachClick(validPress);
	up.attachClick(upPress);
	down.attachClick(downPress);
}

void deinit_keypad()
{
}
