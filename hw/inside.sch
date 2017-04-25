EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:mq135
LIBS:sensors
LIBS:crumpschemes
LIBS:maxim
LIBS:Arduino_Pro_Mini-cache
LIBS:switches
LIBS:inside-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Inside"
Date "25 apr 2017"
Rev "001"
Comp "peewhy.net"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DHT22_TEMPERATURE_HUMIDITY TH?
U 1 1 58FF439D
P 9900 2250
F 0 "TH?" H 9900 3300 60  0000 C CNN
F 1 "DHT22_TEMPERATURE_HUMIDITY" H 9900 3200 60  0000 C CNN
F 2 "" H 9900 2250 60  0000 C CNN
F 3 "" H 9900 2250 60  0000 C CNN
	1    9900 2250
	1    0    0    -1  
$EndComp
$Comp
L LCD16X2 DS?
U 1 1 58FF43C1
P 1950 4300
F 0 "DS?" H 1150 4700 50  0000 C CNN
F 1 "LCD16X2" H 2650 4700 50  0000 C CNN
F 2 "WC1602A" H 1950 4250 50  0001 C CIN
F 3 "" H 1950 4300 50  0001 C CNN
	1    1950 4300
	1    0    0    -1  
$EndComp
$Comp
L MQ135 U?
U 1 1 58FF4AB0
P 2500 2250
F 0 "U?" H 2600 2250 60  0000 C CNN
F 1 "MQ135" H 2450 2700 60  0000 C CNN
F 2 "~" H 2500 2250 60  0000 C CNN
F 3 "~" H 2500 2250 60  0000 C CNN
	1    2500 2250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 58FF4FB3
P 1750 1050
F 0 "#PWR?" H 1750 900 50  0001 C CNN
F 1 "+5V" H 1750 1190 50  0000 C CNN
F 2 "" H 1750 1050 50  0001 C CNN
F 3 "" H 1750 1050 50  0001 C CNN
	1    1750 1050
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF531F
P 3150 2350
F 0 "R?" V 3230 2350 50  0000 C CNN
F 1 "10k" V 3150 2350 50  0000 C CNN
F 2 "" V 3080 2350 50  0001 C CNN
F 3 "" H 3150 2350 50  0001 C CNN
	1    3150 2350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF5370
P 1300 1950
F 0 "R?" V 1380 1950 50  0000 C CNN
F 1 "100k" V 1300 1950 50  0000 C CNN
F 2 "" V 1230 1950 50  0001 C CNN
F 3 "" H 1300 1950 50  0001 C CNN
	1    1300 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58FF537F
P 1300 2250
F 0 "#PWR?" H 1300 2000 50  0001 C CNN
F 1 "GND" H 1300 2100 50  0000 C CNN
F 2 "" H 1300 2250 50  0001 C CNN
F 3 "" H 1300 2250 50  0001 C CNN
	1    1300 2250
	1    0    0    -1  
$EndComp
$Comp
L BSS138 Q?
U 1 1 58FF53A6
P 1500 1700
F 0 "Q?" H 1700 1775 50  0000 L CNN
F 1 "BSS138" H 1700 1700 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1700 1625 50  0001 L CIN
F 3 "" H 1500 1700 50  0001 L CNN
	1    1500 1700
	1    0    0    -1  
$EndComp
Text GLabel 4050 1700 2    60   Output ~ 0
CO2
Text GLabel 1000 1700 0    60   Input ~ 0
SWON
$Comp
L +5V #PWR?
U 1 1 58FF5523
P 9200 2250
F 0 "#PWR?" H 9200 2100 50  0001 C CNN
F 1 "+5V" H 9200 2390 50  0000 C CNN
F 2 "" H 9200 2250 50  0001 C CNN
F 3 "" H 9200 2250 50  0001 C CNN
	1    9200 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58FF5548
P 10050 2800
F 0 "#PWR?" H 10050 2550 50  0001 C CNN
F 1 "GND" H 10050 2650 50  0000 C CNN
F 2 "" H 10050 2800 50  0001 C CNN
F 3 "" H 10050 2800 50  0001 C CNN
	1    10050 2800
	1    0    0    -1  
$EndComp
Text GLabel 9550 2650 0    60   Output ~ 0
TH
$Comp
L PCF8574 U?
U 1 1 58FF563E
P 2000 5950
F 0 "U?" H 1650 6550 50  0000 L CNN
F 1 "PCF8574" H 2100 6550 50  0000 L CNN
F 2 "" H 2000 5950 50  0001 C CNN
F 3 "" H 2000 5950 50  0001 C CNN
	1    2000 5950
	0    -1   -1   0   
$EndComp
Entry Wire Line
	2000 5450 2100 5350
Entry Wire Line
	2100 5450 2200 5350
Entry Wire Line
	2200 5450 2300 5350
Entry Wire Line
	2300 5450 2400 5350
Entry Wire Line
	2200 4800 2300 4900
Entry Wire Line
	2300 4800 2400 4900
Entry Wire Line
	2400 4800 2500 4900
Entry Wire Line
	2500 4800 2600 4900
Text Label 2000 5450 0    60   ~ 0
11
Text Label 2100 5450 0    60   ~ 0
12
Text Label 2200 5450 0    60   ~ 0
13
Text Label 2300 5450 0    60   ~ 0
14
$Comp
L GND #PWR?
U 1 1 58FF5E5B
P 3150 6050
F 0 "#PWR?" H 3150 5800 50  0001 C CNN
F 1 "GND" H 3150 5900 50  0000 C CNN
F 2 "" H 3150 6050 50  0001 C CNN
F 3 "" H 3150 6050 50  0001 C CNN
	1    3150 6050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 58FF5EC6
P 850 5250
F 0 "#PWR?" H 850 5100 50  0001 C CNN
F 1 "+5V" H 850 5390 50  0000 C CNN
F 2 "" H 850 5250 50  0001 C CNN
F 3 "" H 850 5250 50  0001 C CNN
	1    850  5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58FF6041
P 850 6450
F 0 "#PWR?" H 850 6200 50  0001 C CNN
F 1 "GND" H 850 6300 50  0000 C CNN
F 2 "" H 850 6450 50  0001 C CNN
F 3 "" H 850 6450 50  0001 C CNN
	1    850  6450
	1    0    0    -1  
$EndComp
Text GLabel 1700 7000 3    60   BiDi ~ 0
SDA
Text GLabel 1550 7000 3    60   Input ~ 0
SCL
Text Notes 2000 6700 0    60   ~ 0
A0 = 1\nA1 = 1\nA2 = 1\naddress=0x4e
$Comp
L +5V #PWR?
U 1 1 58FF61C3
P 3800 4600
F 0 "#PWR?" H 3800 4450 50  0001 C CNN
F 1 "+5V" H 3800 4740 50  0000 C CNN
F 2 "" H 3800 4600 50  0001 C CNN
F 3 "" H 3800 4600 50  0001 C CNN
	1    3800 4600
	1    0    0    -1  
$EndComp
$Comp
L R_VARIABLE 10K
U 1 1 58FF61D2
P 3800 5000
F 0 "10K" V 3900 4900 50  0000 L CNN
F 1 "R_VARIABLE" V 3700 4950 50  0000 L CNN
F 2 "" V 3730 5000 50  0001 C CNN
F 3 "" H 3800 5000 50  0001 C CNN
	1    3800 5000
	1    0    0    -1  
$EndComp
$Comp
L MMBF170 Q?
U 1 1 58FF66D9
P 3050 5550
F 0 "Q?" H 3250 5625 50  0000 L CNN
F 1 "MMBF170" H 3250 5550 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 3250 5475 50  0001 L CIN
F 3 "" H 3050 5550 50  0001 L CNN
	1    3050 5550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF6510
P 2050 5100
F 0 "R?" V 2130 5100 50  0000 C CNN
F 1 "4.7k" V 2050 5100 50  0000 C CNN
F 2 "" V 1980 5100 50  0001 C CNN
F 3 "" H 2050 5100 50  0001 C CNN
	1    2050 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 1900 3350 1900
Wire Wire Line
	3150 2100 3150 2200
Wire Wire Line
	2950 2100 3150 2100
Wire Wire Line
	3150 2500 3150 2550
Wire Wire Line
	3150 2550 3350 2550
Connection ~ 3350 2550
Wire Wire Line
	1300 2100 1300 2250
Wire Wire Line
	1300 1800 1300 1700
Wire Wire Line
	1300 1700 1000 1700
Wire Wire Line
	1600 1900 1850 1900
Wire Wire Line
	2950 1700 4050 1700
Wire Wire Line
	9750 2250 9750 2400
Wire Wire Line
	9750 2400 9200 2400
Wire Wire Line
	9200 2400 9200 2250
Wire Wire Line
	10050 2250 10050 2800
Wire Wire Line
	9850 2250 9850 2650
Wire Wire Line
	9850 2650 9550 2650
Wire Bus Line
	2300 4900 2600 4900
Wire Bus Line
	2600 4900 2600 5350
Wire Bus Line
	2600 5350 2100 5350
Connection ~ 2600 4900
Connection ~ 2500 4900
Connection ~ 2400 4900
Connection ~ 2300 4900
Connection ~ 2400 5350
Connection ~ 2300 5350
Connection ~ 2200 5350
Connection ~ 2100 5350
Wire Wire Line
	1600 5450 1500 5450
Wire Wire Line
	1500 5450 1500 4800
Wire Wire Line
	1700 5450 1700 5400
Wire Wire Line
	1700 5400 1600 5400
Wire Wire Line
	1600 5400 1600 4800
Wire Wire Line
	1800 5450 1800 5350
Wire Wire Line
	1800 5350 1700 5350
Wire Wire Line
	1700 5350 1700 4800
Wire Wire Line
	850  5250 850  5400
Wire Wire Line
	2700 5950 3800 5950
Wire Wire Line
	3150 5750 3150 6050
Wire Wire Line
	1200 5950 1300 5950
Wire Wire Line
	850  5400 1300 5400
Connection ~ 1200 5400
Wire Wire Line
	1200 5400 1200 6600
Wire Wire Line
	1300 5400 1300 4800
Wire Wire Line
	1200 4800 1200 5000
Wire Wire Line
	1200 5000 750  5000
Wire Wire Line
	750  5000 750  6400
Wire Wire Line
	750  6400 850  6400
Wire Wire Line
	850  6400 850  6450
Wire Wire Line
	1900 6450 2100 6450
Wire Wire Line
	2000 6450 2000 6600
Wire Wire Line
	2000 6600 1200 6600
Connection ~ 1200 5950
Connection ~ 2000 6450
Connection ~ 2100 6450
Connection ~ 1900 6450
Wire Wire Line
	1700 6450 1700 7000
Wire Wire Line
	1600 6450 1600 6850
Wire Wire Line
	1600 6850 1550 6850
Wire Wire Line
	1550 6850 1550 7000
Wire Wire Line
	3800 4850 3800 4600
Wire Wire Line
	3800 5950 3800 5150
Connection ~ 3150 5950
Wire Wire Line
	1400 4800 1400 5200
Wire Wire Line
	1400 5200 3450 5200
Wire Wire Line
	3450 5200 3450 5000
Wire Wire Line
	3450 5000 3750 5000
Wire Wire Line
	2200 5100 3200 5100
Wire Wire Line
	2650 5100 2650 4850
Wire Wire Line
	2650 4850 2600 4850
Wire Wire Line
	2600 4850 2600 4800
Wire Wire Line
	3200 5100 3200 4600
Wire Wire Line
	3200 4600 3800 4600
Connection ~ 2650 5100
Connection ~ 3800 4600
Wire Wire Line
	2700 4800 2700 5300
Wire Wire Line
	2700 5300 3150 5300
Wire Wire Line
	3150 5300 3150 5350
Wire Wire Line
	1900 5100 1900 5450
Wire Wire Line
	1900 5300 2500 5300
Wire Wire Line
	2500 5300 2500 5550
Wire Wire Line
	2500 5550 2850 5550
Connection ~ 1900 5300
Wire Wire Line
	1600 1500 1600 1050
Wire Wire Line
	1600 1050 1750 1050
Wire Wire Line
	1750 1050 1750 2100
Wire Wire Line
	1750 1700 1950 1700
Wire Wire Line
	1750 2100 1950 2100
Connection ~ 1750 1700
Text Notes 4150 1850 0    60   ~ 0
Analog
Text Notes 750  1850 0    60   ~ 0
Digital
Text Notes 9250 2800 0    60   ~ 0
Analog
Text GLabel 8100 5250 0    60   BiDi ~ 0
SDA
Text GLabel 8100 5100 0    60   Input ~ 0
SCL
$Comp
L +5V #PWR?
U 1 1 58FF7453
P 8850 4700
F 0 "#PWR?" H 8850 4550 50  0001 C CNN
F 1 "+5V" H 8850 4840 50  0000 C CNN
F 2 "" H 8850 4700 50  0001 C CNN
F 3 "" H 8850 4700 50  0001 C CNN
	1    8850 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58FF74C2
P 8850 5950
F 0 "#PWR?" H 8850 5700 50  0001 C CNN
F 1 "GND" H 8850 5800 50  0000 C CNN
F 2 "" H 8850 5950 50  0001 C CNN
F 3 "" H 8850 5950 50  0001 C CNN
	1    8850 5950
	1    0    0    -1  
$EndComp
$Comp
L DS3231 U?
U 1 1 58FF76E5
P 8850 5200
F 0 "U?" H 8750 5675 50  0000 R CNN
F 1 "DS3231" H 8750 5600 50  0000 R CNN
F 2 "Housings_SOIC:SOIC-16_7.5x10.3mm_Pitch1.27mm" H 8900 4800 50  0001 L CNN
F 3 "" H 9120 5450 50  0001 C CNN
	1    8850 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 5100 8350 5100
Wire Wire Line
	8100 5250 8300 5250
Wire Wire Line
	8300 5250 8300 5200
Wire Wire Line
	8300 5200 8350 5200
Wire Wire Line
	9350 5400 10550 5400
Text GLabel 9950 4900 2    60   Output ~ 0
ALRM
Wire Wire Line
	9750 5100 9350 5100
Wire Wire Line
	9750 4750 9750 5100
Wire Wire Line
	9750 4900 9950 4900
Wire Wire Line
	8350 5400 8150 5400
Wire Wire Line
	8150 5400 8150 6000
Wire Wire Line
	8150 6000 7950 6000
$Comp
L +5V #PWR?
U 1 1 58FF7A97
P 9750 4350
F 0 "#PWR?" H 9750 4200 50  0001 C CNN
F 1 "+5V" H 9750 4490 50  0000 C CNN
F 2 "" H 9750 4350 50  0001 C CNN
F 3 "" H 9750 4350 50  0001 C CNN
	1    9750 4350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF7AA6
P 9750 4600
F 0 "R?" V 9830 4600 50  0000 C CNN
F 1 "10k" V 9750 4600 50  0000 C CNN
F 2 "" V 9680 4600 50  0001 C CNN
F 3 "" H 9750 4600 50  0001 C CNN
	1    9750 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4450 9750 4350
$Comp
L C C?
U 1 1 58FF7C74
P 9150 4700
F 0 "C?" H 9175 4800 50  0000 L CNN
F 1 "20nF" H 9175 4600 50  0000 L CNN
F 2 "" H 9188 4550 50  0001 C CNN
F 3 "" H 9150 4700 50  0001 C CNN
	1    9150 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8850 5700 8850 5950
Connection ~ 8850 5800
$Comp
L ARDUINO_PRO_MINI U?
U 1 1 58FF7EDC
P 5800 4850
F 0 "U?" H 5500 5600 60  0000 C CNN
F 1 "ARDUINO_PRO_MINI" H 5800 2900 60  0000 C CNN
F 2 "" H 5800 4850 60  0000 C CNN
F 3 "" H 5800 4850 60  0000 C CNN
	1    5800 4850
	1    0    0    -1  
$EndComp
Text GLabel 6750 5850 2    60   Input ~ 0
TH
Wire Wire Line
	6400 5850 6750 5850
Connection ~ 9750 4900
$Comp
L BATTERY BT?
U 1 1 58FF818A
P 10550 5600
F 0 "BT?" H 10650 5700 50  0000 L CNN
F 1 "CR 2032 3V" H 10650 5600 50  0000 L CNN
F 2 "" V 10550 5660 50  0001 C CNN
F 3 "" V 10550 5660 50  0001 C CNN
	1    10550 5600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58FF821B
P 10550 6000
F 0 "#PWR?" H 10550 5750 50  0001 C CNN
F 1 "GND" H 10550 5850 50  0000 C CNN
F 2 "" H 10550 6000 50  0001 C CNN
F 3 "" H 10550 6000 50  0001 C CNN
	1    10550 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 6000 10550 5800
$Comp
L GND #PWR?
U 1 1 58FF8298
P 9400 4800
F 0 "#PWR?" H 9400 4550 50  0001 C CNN
F 1 "GND" H 9400 4650 50  0000 C CNN
F 2 "" H 9400 4800 50  0001 C CNN
F 3 "" H 9400 4800 50  0001 C CNN
	1    9400 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 4700 9000 4700
Wire Wire Line
	9300 4700 9400 4700
Wire Wire Line
	9400 4700 9400 4800
Text GLabel 6700 6000 2    60   Input ~ 0
CO2
Wire Wire Line
	6400 5950 6650 5950
Wire Wire Line
	6650 5950 6650 6000
Wire Wire Line
	6650 6000 6700 6000
$Comp
L GND #PWR?
U 1 1 58FF852C
P 4500 5100
F 0 "#PWR?" H 4500 4850 50  0001 C CNN
F 1 "GND" H 4500 4950 50  0000 C CNN
F 2 "" H 4500 5100 50  0001 C CNN
F 3 "" H 4500 5100 50  0001 C CNN
	1    4500 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4350 5150 4350
Wire Wire Line
	5150 4350 5150 4650
Wire Wire Line
	4500 4650 5250 4650
Wire Wire Line
	4500 4650 4500 5100
Connection ~ 5150 4650
Text GLabel 6900 6350 2    60   BiDi ~ 0
SDA
Text GLabel 6900 6500 2    60   Output ~ 0
SCL
Wire Wire Line
	6400 6350 6900 6350
Wire Wire Line
	6400 6450 6800 6450
Wire Wire Line
	6800 6450 6800 6500
Wire Wire Line
	6800 6500 6900 6500
Text GLabel 6650 4250 2    60   Output ~ 0
UART_TX
Text GLabel 6650 4400 2    60   Input ~ 0
UART_RX
Wire Wire Line
	6400 4250 6650 4250
Wire Wire Line
	6650 4400 6500 4400
Wire Wire Line
	6500 4400 6500 4350
Wire Wire Line
	6500 4350 6400 4350
Text GLabel 6800 4600 2    60   Output ~ 0
SWON
Wire Wire Line
	6400 4550 6700 4550
Wire Wire Line
	6700 4550 6700 4600
Wire Wire Line
	6700 4600 6800 4600
Wire Notes Line
	4550 600  4550 2800
Wire Notes Line
	550  600  550  2800
Wire Notes Line
	550  600  4550 600 
Wire Notes Line
	8950 750  8950 3250
Wire Notes Line
	8950 3250 10800 3250
Wire Notes Line
	10800 3250 10800 750 
Wire Notes Line
	8950 800  8950 850 
Wire Notes Line
	10800 750  8950 750 
Wire Notes Line
	7700 4050 7700 6550
Wire Notes Line
	7700 6550 11150 6550
Wire Notes Line
	11150 6550 11150 4050
Wire Notes Line
	11150 4050 7700 4050
Wire Notes Line
	600  3650 4000 3650
Wire Notes Line
	4000 3650 4000 7450
Wire Notes Line
	4000 7450 600  7450
Wire Notes Line
	600  7450 600  3650
Text GLabel 4800 7250 2    60   BiDi ~ 0
SDA
$Comp
L +5V #PWR?
U 1 1 58FF8BD3
P 4700 6700
F 0 "#PWR?" H 4700 6550 50  0001 C CNN
F 1 "+5V" H 4700 6840 50  0000 C CNN
F 2 "" H 4700 6700 50  0001 C CNN
F 3 "" H 4700 6700 50  0001 C CNN
	1    4700 6700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 58FF8BE2
P 4400 6700
F 0 "#PWR?" H 4400 6550 50  0001 C CNN
F 1 "+5V" H 4400 6840 50  0000 C CNN
F 2 "" H 4400 6700 50  0001 C CNN
F 3 "" H 4400 6700 50  0001 C CNN
	1    4400 6700
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF8BF1
P 4700 6950
F 0 "R?" V 4780 6950 50  0000 C CNN
F 1 "R" V 4700 6950 50  0000 C CNN
F 2 "" V 4630 6950 50  0001 C CNN
F 3 "" H 4700 6950 50  0001 C CNN
	1    4700 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 6700 4700 6800
Wire Wire Line
	4700 7100 4700 7250
Wire Wire Line
	4700 7250 4800 7250
Text GLabel 4750 7450 2    60   Output ~ 0
SCL
$Comp
L R R?
U 1 1 58FF8D2F
P 4400 6950
F 0 "R?" V 4480 6950 50  0000 C CNN
F 1 "R" V 4400 6950 50  0000 C CNN
F 2 "" V 4330 6950 50  0001 C CNN
F 3 "" H 4400 6950 50  0001 C CNN
	1    4400 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6700 4400 6800
Wire Wire Line
	4400 7100 4400 7450
Wire Wire Line
	4400 7450 4750 7450
$Comp
L GND #PWR?
U 1 1 58FF90BC
P 3350 2600
F 0 "#PWR?" H 3350 2350 50  0001 C CNN
F 1 "GND" H 3350 2450 50  0000 C CNN
F 2 "" H 3350 2600 50  0001 C CNN
F 3 "" H 3350 2600 50  0001 C CNN
	1    3350 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1900 3350 2600
Wire Notes Line
	550  2800 4550 2800
$Comp
L SW_PUSH_DUAL SW?
U 1 1 58FF9459
P 5800 2050
F 0 "SW?" H 5850 2150 50  0000 L CNN
F 1 "UP BTN" H 5800 1780 50  0000 C CNN
F 2 "" H 5800 2250 50  0001 C CNN
F 3 "" H 5800 2250 50  0001 C CNN
	1    5800 2050
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH_DUAL SW?
U 1 1 58FF9477
P 5800 900
F 0 "SW?" H 5850 1000 50  0000 L CNN
F 1 "VLD BTN" H 5800 630 50  0000 C CNN
F 2 "" H 5800 1100 50  0001 C CNN
F 3 "" H 5800 1100 50  0001 C CNN
	1    5800 900 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 58FF9899
P 5050 700
F 0 "#PWR?" H 5050 550 50  0001 C CNN
F 1 "+5V" H 5050 840 50  0000 C CNN
F 2 "" H 5050 700 50  0001 C CNN
F 3 "" H 5050 700 50  0001 C CNN
	1    5050 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 900  5050 900 
Wire Wire Line
	5050 900  5050 700 
Text GLabel 5400 1100 0    60   Output ~ 0
VLD
Wire Wire Line
	5400 1100 5600 1100
$Comp
L GND #PWR?
U 1 1 58FF9A8A
P 6450 1300
F 0 "#PWR?" H 6450 1050 50  0001 C CNN
F 1 "GND" H 6450 1150 50  0000 C CNN
F 2 "" H 6450 1300 50  0001 C CNN
F 3 "" H 6450 1300 50  0001 C CNN
	1    6450 1300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF9A99
P 6300 1100
F 0 "R?" V 6380 1100 50  0000 C CNN
F 1 "10k" V 6300 1100 50  0000 C CNN
F 2 "" V 6230 1100 50  0001 C CNN
F 3 "" H 6300 1100 50  0001 C CNN
	1    6300 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 1100 6150 1100
Wire Wire Line
	6450 1100 6450 1300
$Comp
L +5V #PWR?
U 1 1 58FF9BF8
P 5050 1850
F 0 "#PWR?" H 5050 1700 50  0001 C CNN
F 1 "+5V" H 5050 1990 50  0000 C CNN
F 2 "" H 5050 1850 50  0001 C CNN
F 3 "" H 5050 1850 50  0001 C CNN
	1    5050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2050 5050 2050
Wire Wire Line
	5050 2050 5050 1850
Text GLabel 5400 2250 0    60   Output ~ 0
UP
Wire Wire Line
	5400 2250 5600 2250
$Comp
L GND #PWR?
U 1 1 58FF9C02
P 6450 2450
F 0 "#PWR?" H 6450 2200 50  0001 C CNN
F 1 "GND" H 6450 2300 50  0000 C CNN
F 2 "" H 6450 2450 50  0001 C CNN
F 3 "" H 6450 2450 50  0001 C CNN
	1    6450 2450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF9C08
P 6300 2250
F 0 "R?" V 6380 2250 50  0000 C CNN
F 1 "10k" V 6300 2250 50  0000 C CNN
F 2 "" V 6230 2250 50  0001 C CNN
F 3 "" H 6300 2250 50  0001 C CNN
	1    6300 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 2250 6150 2250
Wire Wire Line
	6450 2250 6450 2450
$Comp
L SW_PUSH_DUAL SW?
U 1 1 58FF9C10
P 7500 1450
F 0 "SW?" H 7550 1550 50  0000 L CNN
F 1 "DWN BTN" H 7500 1180 50  0000 C CNN
F 2 "" H 7500 1650 50  0001 C CNN
F 3 "" H 7500 1650 50  0001 C CNN
	1    7500 1450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 58FF9C16
P 6750 1250
F 0 "#PWR?" H 6750 1100 50  0001 C CNN
F 1 "+5V" H 6750 1390 50  0000 C CNN
F 2 "" H 6750 1250 50  0001 C CNN
F 3 "" H 6750 1250 50  0001 C CNN
	1    6750 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1450 6750 1450
Wire Wire Line
	6750 1450 6750 1250
Text GLabel 7100 1650 0    60   Output ~ 0
DWN
Wire Wire Line
	7100 1650 7300 1650
$Comp
L GND #PWR?
U 1 1 58FF9C20
P 8150 1850
F 0 "#PWR?" H 8150 1600 50  0001 C CNN
F 1 "GND" H 8150 1700 50  0000 C CNN
F 2 "" H 8150 1850 50  0001 C CNN
F 3 "" H 8150 1850 50  0001 C CNN
	1    8150 1850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58FF9C26
P 8000 1650
F 0 "R?" V 8080 1650 50  0000 C CNN
F 1 "10k" V 8000 1650 50  0000 C CNN
F 2 "" V 7930 1650 50  0001 C CNN
F 3 "" H 8000 1650 50  0001 C CNN
	1    8000 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 1650 7850 1650
Wire Wire Line
	8150 1650 8150 1850
Text GLabel 6800 4850 2    60   Input ~ 0
UP
Text GLabel 6800 5000 2    60   Input ~ 0
DWN
Text GLabel 6800 5150 2    60   Input ~ 0
VLD
Wire Wire Line
	6800 4850 6400 4850
Wire Wire Line
	6800 5000 6700 5000
Wire Wire Line
	6700 5000 6700 4950
Wire Wire Line
	6700 4950 6400 4950
Wire Wire Line
	6800 5150 6550 5150
Wire Wire Line
	6550 5150 6550 5050
Wire Wire Line
	6550 5050 6400 5050
Wire Notes Line
	4850 500  4850 2800
Wire Notes Line
	4850 2800 8350 2800
Wire Notes Line
	8350 2800 8350 500 
Wire Notes Line
	8350 500  4850 500 
Wire Wire Line
	4500 3750 4500 4450
Wire Wire Line
	4500 4450 4900 4450
Wire Wire Line
	4900 4450 4900 4750
Wire Wire Line
	4900 4750 5250 4750
$Comp
L +BATT #PWR?
U 1 1 58FFA396
P 4500 3750
F 0 "#PWR?" H 4500 3600 50  0001 C CNN
F 1 "+BATT" H 4500 3890 50  0000 C CNN
F 2 "" H 4500 3750 50  0001 C CNN
F 3 "" H 4500 3750 50  0001 C CNN
	1    4500 3750
	1    0    0    -1  
$EndComp
Text Notes 5200 3750 2    60   ~ 0
range 5V-12V
$EndSCHEMATC
