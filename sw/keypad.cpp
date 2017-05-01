#include <Arduino.h>
#include "keypad.h"

int get_validButton()
{
	return digitalRead(VLD_BTN);
}
