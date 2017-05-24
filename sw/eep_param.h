#ifndef EEP_PARAM_H
#define EEP_PARAM_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define EEP_CALIB_MAGIC 0x6c9a
#define EEP_MISC_MAGIC 0x6c9b

class Param {
private:
	uint16_t _base;
	uint16_t _magic;
	uint16_t _size;

	uint16_t _atmoco2;
	float _r0;
	float _rl;

public:
	Param(void);
	Param(unsigned long base, int size);
	unsigned long getBase(void);
	void setBase(unsigned long);
	int getSize(void);
	void setSize(int);
	int getMagic(void);
	void setMagic(int);
	int readParam(void);
	int saveParam();
	float getR0(void);
	void setR0(float);
	float getRl(void);
	void setRl(float);
	uint16_t getAtmoco2(void);
	void setAtmoco2(int);
	void setAtmoco2(float);
};
#endif
