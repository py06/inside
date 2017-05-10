#include <Arduino.h>
#include "OneButton.h"
#include "keypad.h"

int context;
OneButton valid(VLD_BTN, true);

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
}

static void context_switch() {
	context = !context;
}

void init_keypad()
{
	context = DISPLAY_STANDARD;
	valid.setPressTicks(LONG_PRESS_TIME);
	valid.attachLongPressStart(context_switch);
}

void deinit_keypad()
{
}
