#include <avr/eeprom.h>
#include "eep_param.h"

struct calib {
	uint16_t atmoco2;
	float r0;
	float rl;
};

struct calib EEMEM eepcalib;
struct calib calib;

Param::Param()
{
	_base = 0;
	_size = 30;
}

Param::Param(unsigned long base, int size)
{
	_base = base;
	_size = size;
}

int Param::readParam()
{
	eeprom_read_block((void *)&calib, (const void *)&eepcalib,
			  sizeof(struct calib));
#ifdef DEBUG_PARAM
	Serial.println("read eeprom");
	Serial.print("atmoco2=");
	Serial.println(calib.atmoco2);
	Serial.print("r0=");
	Serial.println(calib.r0);
	Serial.print("rl=");
	Serial.println(calib.rl);
#endif
	_atmoco2 = calib.atmoco2;
	_r0 = calib.r0;
	_rl = calib.rl;
	return 0;
}

int Param::saveParam()
{
	calib.atmoco2 = _atmoco2;
	calib.r0 = _r0;
	calib.rl = _rl;
#ifdef DEBUG_PARAM
	Serial.println("write eeprom");
	Serial.print("atmoco2=");
	Serial.println(calib.atmoco2);
	Serial.print("r0=");
	Serial.println(calib.r0);
	Serial.print("rl=");
	Serial.println(calib.rl);
#endif
	eeprom_update_block((const void *)&calib, (void *)&eepcalib,
			    sizeof(struct calib));
	return 0;
}

uint16_t Param::getAtmoco2()
{
	return _atmoco2;
}

void Param::setAtmoco2(int ppm)
{
	_atmoco2 = ppm;
}

void Param::setAtmoco2(float ppm)
{
	_atmoco2 = (uint16_t) ppm;
}

float Param::getR0()
{
	return _r0;
}

void Param::setR0(float r)
{
	_r0 = r;
}

float Param::getRl()
{
	return _rl;
}

void Param::setRl(float r)
{
	_rl = r;
}

