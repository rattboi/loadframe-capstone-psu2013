EESchema Schematic File Version 2  date Wed 12 Jun 2013 07:38:58 PM PDT
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
LIBS:custom
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title ""
Date "13 jun 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4600 4500 0    60   Input ~ 0
EncoderA
Text HLabel 4600 4600 0    60   Input ~ 0
EncoderB
Text HLabel 4600 4200 0    60   Input ~ 0
ToggleSpeed
Text HLabel 4600 4300 0    60   Input ~ 0
ToggleA
Text HLabel 4600 4400 0    60   Input ~ 0
ToggleB
Text HLabel 4600 4000 0    60   Input ~ 0
TareLVDT
Text HLabel 4600 4100 0    60   Input ~ 0
TareLOADC
$Comp
L CONN_8X2 P401
U 1 1 514E1455
P 6750 4350
F 0 "P401" H 6750 4800 60  0000 C CNN
F 1 "IO_PANEL" V 6750 4350 50  0000 C CNN
F 2 "" H 6750 4350 60  0000 C CNN
F 3 "" H 6750 4350 60  0000 C CNN
	1    6750 4350
	1    0    0    -1  
$EndComp
$Comp
L R R407
U 1 1 514E1464
P 6300 3650
F 0 "R407" V 6380 3650 50  0000 C CNN
F 1 "10k" V 6300 3650 50  0000 C CNN
F 2 "" H 6300 3650 60  0000 C CNN
F 3 "" H 6300 3650 60  0000 C CNN
	1    6300 3650
	-1   0    0    1   
$EndComp
$Comp
L R R406
U 1 1 514E1473
P 6100 3650
F 0 "R406" V 6180 3650 50  0000 C CNN
F 1 "10k" V 6100 3650 50  0000 C CNN
F 2 "" H 6100 3650 60  0000 C CNN
F 3 "" H 6100 3650 60  0000 C CNN
	1    6100 3650
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR090
U 1 1 514E14E6
P 7250 4000
F 0 "#PWR090" H 7250 4000 30  0001 C CNN
F 1 "GND" H 7250 3930 30  0001 C CNN
F 2 "" H 7250 4000 60  0000 C CNN
F 3 "" H 7250 4000 60  0000 C CNN
	1    7250 4000
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR091
U 1 1 514E14F5
P 7250 4100
F 0 "#PWR091" H 7250 4100 30  0001 C CNN
F 1 "GND" H 7250 4030 30  0001 C CNN
F 2 "" H 7250 4100 60  0000 C CNN
F 3 "" H 7250 4100 60  0000 C CNN
	1    7250 4100
	0    -1   -1   0   
$EndComp
$Comp
L R R405
U 1 1 514E1513
P 5900 3650
F 0 "R405" V 5980 3650 50  0000 C CNN
F 1 "10k" V 5900 3650 50  0000 C CNN
F 2 "" H 5900 3650 60  0000 C CNN
F 3 "" H 5900 3650 60  0000 C CNN
	1    5900 3650
	-1   0    0    1   
$EndComp
$Comp
L R R404
U 1 1 514E1538
P 5700 3650
F 0 "R404" V 5780 3650 50  0000 C CNN
F 1 "10k" V 5700 3650 50  0000 C CNN
F 2 "" H 5700 3650 60  0000 C CNN
F 3 "" H 5700 3650 60  0000 C CNN
	1    5700 3650
	-1   0    0    1   
$EndComp
$Comp
L R R403
U 1 1 514E1547
P 5500 3650
F 0 "R403" V 5580 3650 50  0000 C CNN
F 1 "10k" V 5500 3650 50  0000 C CNN
F 2 "" H 5500 3650 60  0000 C CNN
F 3 "" H 5500 3650 60  0000 C CNN
	1    5500 3650
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR092
U 1 1 514E15BC
P 5500 3400
F 0 "#PWR092" H 5500 3490 20  0001 C CNN
F 1 "+5V" H 5500 3490 30  0000 C CNN
F 2 "" H 5500 3400 60  0000 C CNN
F 3 "" H 5500 3400 60  0000 C CNN
	1    5500 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR093
U 1 1 514E15C9
P 5700 3400
F 0 "#PWR093" H 5700 3490 20  0001 C CNN
F 1 "+5V" H 5700 3490 30  0000 C CNN
F 2 "" H 5700 3400 60  0000 C CNN
F 3 "" H 5700 3400 60  0000 C CNN
	1    5700 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR094
U 1 1 514E15CF
P 5900 3400
F 0 "#PWR094" H 5900 3490 20  0001 C CNN
F 1 "+5V" H 5900 3490 30  0000 C CNN
F 2 "" H 5900 3400 60  0000 C CNN
F 3 "" H 5900 3400 60  0000 C CNN
	1    5900 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR095
U 1 1 514E15D5
P 6100 3400
F 0 "#PWR095" H 6100 3490 20  0001 C CNN
F 1 "+5V" H 6100 3490 30  0000 C CNN
F 2 "" H 6100 3400 60  0000 C CNN
F 3 "" H 6100 3400 60  0000 C CNN
	1    6100 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR096
U 1 1 514E15DB
P 6300 3400
F 0 "#PWR096" H 6300 3490 20  0001 C CNN
F 1 "+5V" H 6300 3490 30  0000 C CNN
F 2 "" H 6300 3400 60  0000 C CNN
F 3 "" H 6300 3400 60  0000 C CNN
	1    6300 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR097
U 1 1 514E1600
P 7250 4200
F 0 "#PWR097" H 7250 4200 30  0001 C CNN
F 1 "GND" H 7250 4130 30  0001 C CNN
F 2 "" H 7250 4200 60  0000 C CNN
F 3 "" H 7250 4200 60  0000 C CNN
	1    7250 4200
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR098
U 1 1 514E160F
P 7250 4300
F 0 "#PWR098" H 7250 4300 30  0001 C CNN
F 1 "GND" H 7250 4230 30  0001 C CNN
F 2 "" H 7250 4300 60  0000 C CNN
F 3 "" H 7250 4300 60  0000 C CNN
	1    7250 4300
	0    -1   -1   0   
$EndComp
$Comp
L R R402
U 1 1 514E1A01
P 5300 3650
F 0 "R402" V 5380 3650 50  0000 C CNN
F 1 "5.1k" V 5300 3650 50  0000 C CNN
F 2 "" H 5300 3650 60  0000 C CNN
F 3 "" H 5300 3650 60  0000 C CNN
	1    5300 3650
	-1   0    0    1   
$EndComp
$Comp
L R R401
U 1 1 514E1A1A
P 5100 3650
F 0 "R401" V 5180 3650 50  0000 C CNN
F 1 "5.1k" V 5100 3650 50  0000 C CNN
F 2 "" H 5100 3650 60  0000 C CNN
F 3 "" H 5100 3650 60  0000 C CNN
	1    5100 3650
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR099
U 1 1 514E1A27
P 5300 3400
F 0 "#PWR099" H 5300 3490 20  0001 C CNN
F 1 "+5V" H 5300 3490 30  0000 C CNN
F 2 "" H 5300 3400 60  0000 C CNN
F 3 "" H 5300 3400 60  0000 C CNN
	1    5300 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR0100
U 1 1 514E1A2D
P 5100 3400
F 0 "#PWR0100" H 5100 3490 20  0001 C CNN
F 1 "+5V" H 5100 3490 30  0000 C CNN
F 2 "" H 5100 3400 60  0000 C CNN
F 3 "" H 5100 3400 60  0000 C CNN
	1    5100 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4000 6350 4000
Wire Wire Line
	4600 4100 6350 4100
Wire Wire Line
	7150 4000 7250 4000
Wire Wire Line
	7150 4100 7250 4100
Wire Wire Line
	4600 4200 6350 4200
Wire Wire Line
	5900 4200 5900 3900
Wire Wire Line
	4600 4300 6350 4300
Wire Wire Line
	5700 4300 5700 3900
Wire Wire Line
	4600 4400 6350 4400
Wire Wire Line
	5500 4400 5500 3900
Connection ~ 5900 4200
Connection ~ 5700 4300
Connection ~ 5500 4400
Wire Wire Line
	7250 4200 7150 4200
Wire Wire Line
	7250 4300 7150 4300
Wire Wire Line
	4600 4500 6350 4500
Wire Wire Line
	4600 4600 6350 4600
Wire Wire Line
	5300 3900 5300 4500
Connection ~ 5300 4500
Wire Wire Line
	6100 3900 6100 4100
Connection ~ 6100 4100
Wire Wire Line
	6300 3900 6300 4000
Connection ~ 6300 4000
$Comp
L +5V #PWR0101
U 1 1 514E1B45
P 7200 4500
F 0 "#PWR0101" H 7200 4590 20  0001 C CNN
F 1 "+5V" H 7200 4590 30  0000 C CNN
F 2 "" H 7200 4500 60  0000 C CNN
F 3 "" H 7200 4500 60  0000 C CNN
	1    7200 4500
	0    1    1    0   
$EndComp
$Comp
L GND #PWR0102
U 1 1 514E1B4B
P 7250 4600
F 0 "#PWR0102" H 7250 4600 30  0001 C CNN
F 1 "GND" H 7250 4530 30  0001 C CNN
F 2 "" H 7250 4600 60  0000 C CNN
F 3 "" H 7250 4600 60  0000 C CNN
	1    7250 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7150 4600 7250 4600
Wire Wire Line
	7150 4500 7200 4500
Wire Wire Line
	5100 3900 5100 4600
Connection ~ 5100 4600
Text HLabel 4600 4700 0    60   Input ~ 0
Aux1
Text HLabel 4600 4800 0    60   Input ~ 0
LCDTX
$Comp
L R R409
U 1 1 51525955
P 4900 3650
F 0 "R409" V 4980 3650 50  0000 C CNN
F 1 "10k" V 4900 3650 50  0000 C CNN
F 2 "" H 4900 3650 60  0000 C CNN
F 3 "" H 4900 3650 60  0000 C CNN
	1    4900 3650
	-1   0    0    1   
$EndComp
$Comp
L R R408
U 1 1 51525964
P 4700 3650
F 0 "R408" V 4780 3650 50  0000 C CNN
F 1 "10k" V 4700 3650 50  0000 C CNN
F 2 "" H 4700 3650 60  0000 C CNN
F 3 "" H 4700 3650 60  0000 C CNN
	1    4700 3650
	-1   0    0    1   
$EndComp
Wire Wire Line
	6350 4700 4600 4700
Wire Wire Line
	7150 4700 7200 4700
Wire Wire Line
	7200 4700 7200 4800
Wire Wire Line
	7200 4800 4600 4800
Wire Wire Line
	4900 3900 4900 4700
Connection ~ 4900 4700
Wire Wire Line
	4700 3900 4700 4800
Connection ~ 4700 4800
$Comp
L +5V #PWR0103
U 1 1 51525AC4
P 4900 3400
F 0 "#PWR0103" H 4900 3490 20  0001 C CNN
F 1 "+5V" H 4900 3490 30  0000 C CNN
F 2 "" H 4900 3400 60  0000 C CNN
F 3 "" H 4900 3400 60  0000 C CNN
	1    4900 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR0104
U 1 1 51525ACA
P 4700 3400
F 0 "#PWR0104" H 4700 3490 20  0001 C CNN
F 1 "+5V" H 4700 3490 30  0000 C CNN
F 2 "" H 4700 3400 60  0000 C CNN
F 3 "" H 4700 3400 60  0000 C CNN
	1    4700 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 4400 7400 4400
Wire Wire Line
	7400 4400 7400 4900
Wire Wire Line
	7400 4900 4600 4900
Text HLabel 4600 4900 0    60   Input ~ 0
Aux2
Text Notes 4550 3200 0    60   ~ 0
NOTE: DO NOT POPULATE ANY RESISTORS!
$EndSCHEMATC
