# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile
ARDUINO_DIR   = /usr/share/arduino
ARDMK_DIR     = /usr/share/arduino
#AVR_TOOLS_DIR = /usr

# Platform conf
BOARD_TAG  = uno #don't select atmega328 (it tries to uppload at 57600bps)
MONITOR_PORT  = /dev/ttyACM0
ISP_PORT = /dev/ttyACM*

# Required libraries for project
ARDUINO_LIBS = LiquidCrystal_I2C DHT Wire Time DS3232RTC OneButton

# Avrdude conf (flash board)
AVRDUDE      = /usr/bin/avrdude
AVRDUDE_CONF = /etc/avrdude.conf

include $(ARDMK_DIR)/Arduino.mk

# !!! Important. You have to use make ispload to upload when using ISP programmer
