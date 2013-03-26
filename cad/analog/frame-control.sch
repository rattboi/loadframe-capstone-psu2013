EESchema Schematic File Version 2  date Mon 25 Mar 2013 03:30:28 PM PDT
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
LIBS:frame-control-cache
EELAYER 27 0
EELAYER END
$Descr User 11000 8500
encoding utf-8
Sheet 1 4
Title ""
Date "25 mar 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LPC1114FBD48/302 U101
U 1 1 513027AE
P 4600 4450
F 0 "U101" H 3250 6850 50  0000 C CNN
F 1 "LPC1114FBD48/302" H 3600 2100 50  0000 C CNN
F 2 "MODULE" H 4600 5150 50  0001 C CNN
F 3 "DOCUMENTATION" H 4600 5450 50  0001 C CNN
	1    4600 4450
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P101
U 1 1 514CAA93
P 1750 1350
F 0 "P101" H 1750 1650 60  0000 C CNN
F 1 "JTAG" V 1750 1350 50  0000 C CNN
F 2 "" H 1750 1350 60  0000 C CNN
F 3 "" H 1750 1350 60  0000 C CNN
	1    1750 1350
	1    0    0    -1  
$EndComp
NoConn ~ 2150 1350
NoConn ~ 2150 1450
NoConn ~ 1350 1150
NoConn ~ 1350 1450
$Comp
L GND #PWR01
U 1 1 514CAD98
P 1250 1600
F 0 "#PWR01" H 1250 1600 30  0001 C CNN
F 1 "GND" H 1250 1530 30  0001 C CNN
F 2 "" H 1250 1600 60  0000 C CNN
F 3 "" H 1250 1600 60  0000 C CNN
	1    1250 1600
	1    0    0    -1  
$EndComp
$Comp
L C C104
U 1 1 514CB071
P 2350 3500
F 0 "C104" H 2400 3600 50  0000 L CNN
F 1 "10n" H 2400 3400 50  0000 L CNN
F 2 "" H 2350 3500 60  0000 C CNN
F 3 "" H 2350 3500 60  0000 C CNN
	1    2350 3500
	1    0    0    -1  
$EndComp
$Comp
L C C101
U 1 1 514CB0FE
P 2000 3500
F 0 "C101" H 2050 3600 50  0000 L CNN
F 1 "100n" H 2050 3400 50  0000 L CNN
F 2 "" H 2000 3500 60  0000 C CNN
F 3 "" H 2000 3500 60  0000 C CNN
	1    2000 3500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 514CB585
P 2150 3200
F 0 "#PWR02" H 2150 3160 30  0001 C CNN
F 1 "+3.3V" H 2150 3310 30  0000 C CNN
F 2 "" H 2150 3200 60  0000 C CNN
F 3 "" H 2150 3200 60  0000 C CNN
	1    2150 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 514CB809
P 2900 3450
F 0 "#PWR03" H 2900 3450 30  0001 C CNN
F 1 "GND" H 2900 3380 30  0001 C CNN
F 2 "" H 2900 3450 60  0000 C CNN
F 3 "" H 2900 3450 60  0000 C CNN
	1    2900 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 514CB959
P 2900 3750
F 0 "#PWR04" H 2900 3750 30  0001 C CNN
F 1 "GND" H 2900 3680 30  0001 C CNN
F 2 "" H 2900 3750 60  0000 C CNN
F 3 "" H 2900 3750 60  0000 C CNN
	1    2900 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 514CBA48
P 2350 3700
F 0 "#PWR05" H 2350 3700 30  0001 C CNN
F 1 "GND" H 2350 3630 30  0001 C CNN
F 2 "" H 2350 3700 60  0000 C CNN
F 3 "" H 2350 3700 60  0000 C CNN
	1    2350 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 514CBAC0
P 2000 3700
F 0 "#PWR06" H 2000 3700 30  0001 C CNN
F 1 "GND" H 2000 3630 30  0001 C CNN
F 2 "" H 2000 3700 60  0000 C CNN
F 3 "" H 2000 3700 60  0000 C CNN
	1    2000 3700
	1    0    0    -1  
$EndComp
$Comp
L C C105
U 1 1 514CBB4D
P 2350 4000
F 0 "C105" H 2400 4100 50  0000 L CNN
F 1 "10n" H 2400 3900 50  0000 L CNN
F 2 "" H 2350 4000 60  0000 C CNN
F 3 "" H 2350 4000 60  0000 C CNN
	1    2350 4000
	1    0    0    -1  
$EndComp
$Comp
L C C102
U 1 1 514CBBC5
P 2000 4000
F 0 "C102" H 2050 4100 50  0000 L CNN
F 1 "100n" H 2050 3900 50  0000 L CNN
F 2 "" H 2000 4000 60  0000 C CNN
F 3 "" H 2000 4000 60  0000 C CNN
	1    2000 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 514CBD03
P 2000 4200
F 0 "#PWR07" H 2000 4200 30  0001 C CNN
F 1 "GND" H 2000 4130 30  0001 C CNN
F 2 "" H 2000 4200 60  0000 C CNN
F 3 "" H 2000 4200 60  0000 C CNN
	1    2000 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 514CBD3C
P 2350 4200
F 0 "#PWR08" H 2350 4200 30  0001 C CNN
F 1 "GND" H 2350 4130 30  0001 C CNN
F 2 "" H 2350 4200 60  0000 C CNN
F 3 "" H 2350 4200 60  0000 C CNN
	1    2350 4200
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X101
U 1 1 514CBF51
P 2600 4800
F 0 "X101" H 2600 4950 60  0000 C CNN
F 1 "12MHz" H 2600 4650 60  0000 C CNN
F 2 "" H 2600 4800 60  0000 C CNN
F 3 "" H 2600 4800 60  0000 C CNN
	1    2600 4800
	1    0    0    -1  
$EndComp
$Comp
L C C106
U 1 1 514CBFD9
P 2900 5000
F 0 "C106" H 2950 5100 50  0000 L CNN
F 1 "18pF" H 2950 4900 50  0000 L CNN
F 2 "" H 2900 5000 60  0000 C CNN
F 3 "" H 2900 5000 60  0000 C CNN
	1    2900 5000
	1    0    0    -1  
$EndComp
$Comp
L C C103
U 1 1 514CC120
P 2300 5000
F 0 "C103" H 2350 5100 50  0000 L CNN
F 1 "18pF" H 2350 4900 50  0000 L CNN
F 2 "" H 2300 5000 60  0000 C CNN
F 3 "" H 2300 5000 60  0000 C CNN
	1    2300 5000
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 514CC1BC
P 2300 5200
F 0 "#PWR09" H 2300 5200 30  0001 C CNN
F 1 "GND" H 2300 5130 30  0001 C CNN
F 2 "" H 2300 5200 60  0000 C CNN
F 3 "" H 2300 5200 60  0000 C CNN
	1    2300 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 514CC1E0
P 2900 5200
F 0 "#PWR010" H 2900 5200 30  0001 C CNN
F 1 "GND" H 2900 5130 30  0001 C CNN
F 2 "" H 2900 5200 60  0000 C CNN
F 3 "" H 2900 5200 60  0000 C CNN
	1    2900 5200
	1    0    0    -1  
$EndComp
$Sheet
S 1150 2850 550  200 
U 514CB4EE
F0 "Power" 50
F1 "Power.sch" 50
F2 "PWRGD" I R 1700 2950 60 
$EndSheet
$Comp
L CONN_5X2 P106
U 1 1 514CB388
P 8450 5850
F 0 "P106" H 8450 6150 60  0000 C CNN
F 1 "LOADC" V 8450 5850 50  0000 C CNN
F 2 "" H 8450 5850 60  0000 C CNN
F 3 "" H 8450 5850 60  0000 C CNN
	1    8450 5850
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P105
U 1 1 514CB47E
P 7450 6600
F 0 "P105" H 7450 6900 60  0000 C CNN
F 1 "LVDT" V 7450 6600 50  0000 C CNN
F 2 "" H 7450 6600 60  0000 C CNN
F 3 "" H 7450 6600 60  0000 C CNN
	1    7450 6600
	1    0    0    -1  
$EndComp
NoConn ~ 8050 5650
NoConn ~ 8050 6050
NoConn ~ 7050 6400
NoConn ~ 7050 6800
$Comp
L +5V #PWR011
U 1 1 514CBE60
P 8850 5650
F 0 "#PWR011" H 8850 5740 20  0001 C CNN
F 1 "+5V" H 8850 5740 30  0000 C CNN
F 2 "" H 8850 5650 60  0000 C CNN
F 3 "" H 8850 5650 60  0000 C CNN
	1    8850 5650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 514CBEA1
P 7850 6400
F 0 "#PWR012" H 7850 6490 20  0001 C CNN
F 1 "+5V" H 7850 6490 30  0000 C CNN
F 2 "" H 7850 6400 60  0000 C CNN
F 3 "" H 7850 6400 60  0000 C CNN
	1    7850 6400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 514CBF90
P 7850 6850
F 0 "#PWR013" H 7850 6850 30  0001 C CNN
F 1 "GND" H 7850 6780 30  0001 C CNN
F 2 "" H 7850 6850 60  0000 C CNN
F 3 "" H 7850 6850 60  0000 C CNN
	1    7850 6850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 514CC047
P 8850 6100
F 0 "#PWR014" H 8850 6100 30  0001 C CNN
F 1 "GND" H 8850 6030 30  0001 C CNN
F 2 "" H 8850 6100 60  0000 C CNN
F 3 "" H 8850 6100 60  0000 C CNN
	1    8850 6100
	1    0    0    -1  
$EndComp
$Sheet
S 8000 3550 1050 1000
U 512FFF69
F0 "Analog Frontend" 60
F1 "Analog.sch" 60
F2 "ADCI" I L 8000 3950 60 
F3 "ADCCLK" I L 8000 3750 60 
F4 "ADCO" I L 8000 3850 60 
F5 "ADCEN" I L 8000 3650 60 
F6 "~DACEN" I L 8000 4250 60 
F7 "DACCLK" I L 8000 4350 60 
F8 "DACIN" I L 8000 4450 60 
$EndSheet
$Comp
L CONN_3 K101
U 1 1 514CDF8C
P 7400 4400
F 0 "K101" V 7350 4400 50  0000 C CNN
F 1 "LCD" V 7450 4400 40  0000 C CNN
F 2 "" H 7400 4400 60  0000 C CNN
F 3 "" H 7400 4400 60  0000 C CNN
	1    7400 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 514CE0B9
P 7000 4600
F 0 "#PWR015" H 7000 4600 30  0001 C CNN
F 1 "GND" H 7000 4530 30  0001 C CNN
F 2 "" H 7000 4600 60  0000 C CNN
F 3 "" H 7000 4600 60  0000 C CNN
	1    7000 4600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 514CE164
P 7050 4250
F 0 "#PWR016" H 7050 4340 20  0001 C CNN
F 1 "+5V" H 7050 4340 30  0000 C CNN
F 2 "" H 7050 4250 60  0000 C CNN
F 3 "" H 7050 4250 60  0000 C CNN
	1    7050 4250
	1    0    0    -1  
$EndComp
$Comp
L R R101
U 1 1 514CF277
P 5700 1550
F 0 "R101" V 5780 1550 50  0000 C CNN
F 1 "1.5k" V 5700 1550 50  0000 C CNN
F 2 "" H 5700 1550 60  0000 C CNN
F 3 "" H 5700 1550 60  0000 C CNN
	1    5700 1550
	1    0    0    -1  
$EndComp
$Comp
L LED D101
U 1 1 514CF5BF
P 5700 1100
F 0 "D101" H 5700 1200 50  0000 C CNN
F 1 "L1" H 5700 1000 50  0000 C CNN
F 2 "" H 5700 1100 60  0000 C CNN
F 3 "" H 5700 1100 60  0000 C CNN
	1    5700 1100
	0    1    1    0   
$EndComp
$Comp
L TST P102
U 1 1 514CFA51
P 5700 1300
F 0 "P102" H 5700 1550 40  0000 C CNN
F 1 "TST" H 5700 1250 30  0000 C CNN
F 2 "" H 5700 1300 60  0000 C CNN
F 3 "" H 5700 1300 60  0000 C CNN
	1    5700 1300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR017
U 1 1 514CFB84
P 5700 1800
F 0 "#PWR017" H 5700 1800 30  0001 C CNN
F 1 "GND" H 5700 1730 30  0001 C CNN
F 2 "" H 5700 1800 60  0000 C CNN
F 3 "" H 5700 1800 60  0000 C CNN
	1    5700 1800
	1    0    0    -1  
$EndComp
$Comp
L R R102
U 1 1 514CFCF6
P 6100 1600
F 0 "R102" V 6180 1600 50  0000 C CNN
F 1 "1.5k" V 6100 1600 50  0000 C CNN
F 2 "" H 6100 1600 60  0000 C CNN
F 3 "" H 6100 1600 60  0000 C CNN
	1    6100 1600
	1    0    0    -1  
$EndComp
$Comp
L LED D102
U 1 1 514CFCFC
P 6100 1150
F 0 "D102" H 6100 1250 50  0000 C CNN
F 1 "L2" H 6100 1050 50  0000 C CNN
F 2 "" H 6100 1150 60  0000 C CNN
F 3 "" H 6100 1150 60  0000 C CNN
	1    6100 1150
	0    1    1    0   
$EndComp
$Comp
L TST P103
U 1 1 514CFD02
P 6100 1350
F 0 "P103" H 6100 1600 40  0000 C CNN
F 1 "TST" H 6100 1300 30  0000 C CNN
F 2 "" H 6100 1350 60  0000 C CNN
F 3 "" H 6100 1350 60  0000 C CNN
	1    6100 1350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR018
U 1 1 514CFD08
P 6100 1850
F 0 "#PWR018" H 6100 1850 30  0001 C CNN
F 1 "GND" H 6100 1780 30  0001 C CNN
F 2 "" H 6100 1850 60  0000 C CNN
F 3 "" H 6100 1850 60  0000 C CNN
	1    6100 1850
	1    0    0    -1  
$EndComp
$Comp
L R R103
U 1 1 514CFD38
P 6500 1650
F 0 "R103" V 6580 1650 50  0000 C CNN
F 1 "1.5k" V 6500 1650 50  0000 C CNN
F 2 "" H 6500 1650 60  0000 C CNN
F 3 "" H 6500 1650 60  0000 C CNN
	1    6500 1650
	1    0    0    -1  
$EndComp
$Comp
L LED D103
U 1 1 514CFD3E
P 6500 1200
F 0 "D103" H 6500 1300 50  0000 C CNN
F 1 "L3" H 6500 1100 50  0000 C CNN
F 2 "" H 6500 1200 60  0000 C CNN
F 3 "" H 6500 1200 60  0000 C CNN
	1    6500 1200
	0    1    1    0   
$EndComp
$Comp
L TST P104
U 1 1 514CFD44
P 6500 1400
F 0 "P104" H 6500 1650 40  0000 C CNN
F 1 "TST" H 6500 1350 30  0000 C CNN
F 2 "" H 6500 1400 60  0000 C CNN
F 3 "" H 6500 1400 60  0000 C CNN
	1    6500 1400
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR019
U 1 1 514CFD4A
P 6500 1900
F 0 "#PWR019" H 6500 1900 30  0001 C CNN
F 1 "GND" H 6500 1830 30  0001 C CNN
F 2 "" H 6500 1900 60  0000 C CNN
F 3 "" H 6500 1900 60  0000 C CNN
	1    6500 1900
	1    0    0    -1  
$EndComp
$Sheet
S 7700 1200 900  850 
U 514D0E4D
F0 "InterfaceButtons" 50
F1 "Interface.sch" 50
F2 "EncoderA" I L 7700 1350 60 
F3 "EncoderB" I L 7700 1450 60 
F4 "ESTOP" I L 7700 1550 60 
F5 "ToggleA" I L 7700 1650 60 
F6 "ToggleB" I L 7700 1750 60 
F7 "TareLVDT" I L 7700 1850 60 
F8 "TareLOADC" I L 7700 1950 60 
$EndSheet
Wire Wire Line
	2150 1150 2650 1150
Wire Wire Line
	2650 1150 2650 2750
Wire Wire Line
	2650 2750 2900 2750
Wire Wire Line
	2600 2850 2900 2850
Wire Wire Line
	2600 1250 2600 2850
Wire Wire Line
	2600 1250 2150 1250
Wire Wire Line
	2150 1550 2550 1550
Wire Wire Line
	2550 1550 2550 2950
Wire Wire Line
	1350 1250 1250 1250
Wire Wire Line
	1250 1250 1250 1600
Wire Wire Line
	1350 1550 1250 1550
Connection ~ 1250 1550
Wire Wire Line
	1350 1350 1250 1350
Connection ~ 1250 1350
Wire Wire Line
	2000 3300 2900 3300
Connection ~ 2350 3300
Wire Wire Line
	2150 3300 2150 3200
Connection ~ 2150 3300
Wire Wire Line
	2900 3700 2900 3750
Wire Wire Line
	2900 3400 2900 3450
Wire Wire Line
	2800 3800 2800 3300
Wire Wire Line
	2800 3600 2900 3600
Connection ~ 2800 3300
Wire Wire Line
	2000 3800 2800 3800
Connection ~ 2350 3800
Connection ~ 2800 3600
Wire Wire Line
	2900 4700 2900 4800
Wire Wire Line
	2300 4800 2300 4400
Wire Wire Line
	2300 4400 2900 4400
Wire Wire Line
	8850 6050 8850 6100
Wire Wire Line
	7850 6800 7850 6850
Wire Wire Line
	6500 4900 7900 4900
Wire Wire Line
	6500 3200 7750 3200
Wire Wire Line
	7050 4400 7000 4400
Wire Wire Line
	7000 4400 7000 4600
Wire Wire Line
	7050 4300 7050 4250
Wire Wire Line
	6750 2600 6750 1000
Wire Wire Line
	6500 2600 6750 2600
Wire Wire Line
	6750 1000 6500 1000
Wire Wire Line
	6500 2700 6800 2700
Wire Wire Line
	6800 2700 6800 950 
Wire Wire Line
	6800 950  6100 950 
Wire Wire Line
	6500 2800 6850 2800
Wire Wire Line
	6850 2800 6850 900 
Wire Wire Line
	6850 900  5700 900 
Wire Wire Line
	7850 6500 7950 6500
Wire Wire Line
	7850 6600 8000 6600
Wire Wire Line
	8050 6700 7850 6700
Wire Wire Line
	8050 6150 8050 6700
Wire Wire Line
	7950 6500 7950 6250
Wire Wire Line
	8000 6600 8000 6200
Wire Wire Line
	6500 6150 8050 6150
Wire Wire Line
	8000 6200 6500 6200
Wire Wire Line
	7950 6250 6550 6250
Wire Wire Line
	8950 5750 8850 5750
Wire Wire Line
	8950 5500 8950 5750
Wire Wire Line
	9000 5850 8850 5850
Wire Wire Line
	9000 5450 9000 5850
Wire Wire Line
	8850 5950 9050 5950
Wire Wire Line
	9050 5950 9050 5400
Wire Wire Line
	9050 5400 6500 5400
Wire Wire Line
	6500 5450 9000 5450
Wire Wire Line
	6550 5500 8950 5500
Wire Wire Line
	8000 3650 7900 3650
Wire Wire Line
	7850 3750 8000 3750
Wire Wire Line
	8000 3850 7800 3850
Wire Wire Line
	8000 3950 7750 3950
Wire Wire Line
	7750 3950 7750 3200
Wire Wire Line
	8000 4450 7950 4450
Wire Wire Line
	8000 4350 7900 4350
Wire Wire Line
	7900 4350 7900 4900
Wire Wire Line
	8000 4250 7850 4250
Wire Wire Line
	7850 4250 7850 4850
Wire Wire Line
	7700 1350 7100 1350
Wire Wire Line
	7100 1350 7100 3750
Wire Wire Line
	7700 1450 7150 1450
Wire Wire Line
	7150 1450 7150 3800
Wire Wire Line
	7700 1550 7200 1550
Wire Wire Line
	7200 1550 7200 3850
Wire Wire Line
	7700 1650 7250 1650
Wire Wire Line
	7250 1650 7250 3900
Wire Wire Line
	7700 1750 7300 1750
Wire Wire Line
	7300 1750 7300 3950
Wire Wire Line
	7700 1850 7350 1850
Wire Wire Line
	7350 1850 7350 4000
Wire Wire Line
	7700 1950 7400 1950
Wire Wire Line
	7400 1950 7400 4050
Wire Wire Line
	7400 4050 6500 4050
NoConn ~ 6500 2400
NoConn ~ 6500 3000
NoConn ~ 6500 4250
NoConn ~ 6500 4350
NoConn ~ 6500 4450
NoConn ~ 6500 4550
NoConn ~ 6500 5200
NoConn ~ 6500 5300
NoConn ~ 6500 5000
Wire Wire Line
	6500 3100 6500 3150
Wire Wire Line
	6500 3150 7800 3150
Wire Wire Line
	7800 3150 7800 3850
Wire Wire Line
	6500 2900 6550 2900
Wire Wire Line
	6550 2900 6550 3100
Wire Wire Line
	6550 3100 7850 3100
Wire Wire Line
	7850 3100 7850 3750
Wire Wire Line
	6500 2500 6600 2500
Wire Wire Line
	6600 2500 6600 3050
Wire Wire Line
	6600 3050 7900 3050
Wire Wire Line
	7900 3050 7900 3650
Wire Wire Line
	6500 3950 6500 4000
Wire Wire Line
	6500 4000 7350 4000
Wire Wire Line
	6500 3850 6550 3850
Wire Wire Line
	6550 3850 6550 3950
Wire Wire Line
	6550 3950 7300 3950
Wire Wire Line
	6500 3750 6600 3750
Wire Wire Line
	6600 3750 6600 3900
Wire Wire Line
	6600 3900 7250 3900
Wire Wire Line
	6500 3650 6650 3650
Wire Wire Line
	6650 3650 6650 3850
Wire Wire Line
	6650 3850 7200 3850
Wire Wire Line
	6500 3550 6700 3550
Wire Wire Line
	6700 3550 6700 3800
Wire Wire Line
	6700 3800 7150 3800
Wire Wire Line
	6500 3300 6750 3300
Wire Wire Line
	6750 3300 6750 3750
Wire Wire Line
	6750 3750 7100 3750
Wire Wire Line
	6500 4150 6700 4150
Wire Wire Line
	6700 4150 6700 4500
Wire Wire Line
	6700 4500 7050 4500
Wire Wire Line
	6500 4800 6500 4850
Wire Wire Line
	6500 4850 7850 4850
Wire Wire Line
	7950 4450 7950 4950
Wire Wire Line
	7950 4950 6550 4950
Wire Wire Line
	6550 4950 6550 5100
Wire Wire Line
	6550 5100 6500 5100
Wire Wire Line
	7050 6500 7000 6500
Wire Wire Line
	7000 6500 7000 6300
Wire Wire Line
	7050 6600 6950 6600
Wire Wire Line
	6950 6600 6950 6350
Wire Wire Line
	7050 6700 6900 6700
Wire Wire Line
	6900 6700 6900 6400
Wire Wire Line
	7000 6300 6600 6300
Wire Wire Line
	6950 6350 6650 6350
Wire Wire Line
	6900 6400 6700 6400
Wire Wire Line
	8000 5750 8050 5750
Wire Wire Line
	8000 5550 8000 5750
Wire Wire Line
	8050 5850 7950 5850
Wire Wire Line
	7950 5850 7950 5600
Wire Wire Line
	8050 5950 7900 5950
Wire Wire Line
	7900 5950 7900 5650
Wire Wire Line
	6500 5450 6500 5500
Wire Wire Line
	6550 5500 6550 5600
Wire Wire Line
	6550 5600 6500 5600
Wire Wire Line
	8000 5550 6600 5550
Wire Wire Line
	6600 5550 6600 5700
Wire Wire Line
	6600 5700 6500 5700
Wire Wire Line
	7950 5600 6650 5600
Wire Wire Line
	6650 5600 6650 5800
Wire Wire Line
	6650 5800 6500 5800
Wire Wire Line
	7900 5650 6700 5650
Wire Wire Line
	6700 5650 6700 5900
Wire Wire Line
	6700 5900 6500 5900
Wire Wire Line
	6500 6200 6500 6250
Wire Wire Line
	6550 6250 6550 6350
Wire Wire Line
	6550 6350 6500 6350
Wire Wire Line
	6600 6300 6600 6450
Wire Wire Line
	6600 6450 6500 6450
Wire Wire Line
	6650 6350 6650 6550
Wire Wire Line
	6650 6550 6500 6550
Wire Wire Line
	6700 6400 6700 6650
Wire Wire Line
	6700 6650 6500 6650
Wire Wire Line
	1700 2950 2900 2950
Connection ~ 2550 2950
$EndSCHEMATC
