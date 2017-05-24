# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile
ARDUINO_DIR   = /home/peewhy/development/arduino/Arduino
ARDMK_DIR = /home/peewhy/development/arduino/Arduino-Makefile
ARCHITECTURE = avr

# Platform conf
BOARD_TAG  = uno #don't select atmega328 (it tries to uppload at 57600bps)
MONITOR_PORT  = /dev/ttyACM0
ISP_PORT = /dev/ttyACM*

# Required libraries for project
ARDUINO_LIB_PATH = $(ARDUINO_DIR)/hardware/arduino/avr/libraries
USER_LIB_PATH = $(ARDUINO_SKETCHBOOK)/libraries
ARDUINO_LIBS = LiquidCrystal_I2C idDHTLib Wire Time DS3232RTC Timer OneButton MQ135

# Avrdude conf (flash board)
AVRDUDE      = /usr/bin/avrdude
AVRDUDE_CONF = /etc/avrdude.conf

CPPFLAGS += -DDEBUG -DDEBUG_PARAM -DCALIB_FAST #-DDEBUG_VERBOSE
CFLAGS += -DDEBUG  -DDEBUG_PARAM -DCALIB_FAST #-DDEBUG_VERBOSE
include $(ARDMK_DIR)/Arduino.mk

# !!! Important. You have to use make ispload to upload when using ISP programmer
