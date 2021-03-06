EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J1
U 1 1 60870F83
P 2700 1750
F 0 "J1" H 2750 2167 50  0000 C CNN
F 1 "Conn_02x06_Odd_Even" H 2750 2076 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x06_P2.54mm_Vertical" H 2700 1750 50  0001 C CNN
F 3 "~" H 2700 1750 50  0001 C CNN
	1    2700 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 60871E3A
P 5900 1950
F 0 "D1" V 5939 1832 50  0000 R CNN
F 1 "LED" V 5848 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 5900 1950 50  0001 C CNN
F 3 "~" H 5900 1950 50  0001 C CNN
	1    5900 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 60873A1F
P 5900 1450
F 0 "R1" H 5970 1496 50  0000 L CNN
F 1 "330" H 5970 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5830 1450 50  0001 C CNN
F 3 "~" H 5900 1450 50  0001 C CNN
	1    5900 1450
	1    0    0    -1  
$EndComp
Text GLabel 5900 1150 1    50   Input ~ 0
LED0
$Comp
L power:GND #PWR0101
U 1 1 60874556
P 5900 2250
F 0 "#PWR0101" H 5900 2000 50  0001 C CNN
F 1 "GND" H 5905 2077 50  0000 C CNN
F 2 "" H 5900 2250 50  0001 C CNN
F 3 "" H 5900 2250 50  0001 C CNN
	1    5900 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 1300 5900 1150
Wire Wire Line
	5900 1600 5900 1800
Wire Wire Line
	5900 2100 5900 2250
$Comp
L Device:LED D2
U 1 1 608761F1
P 6350 1950
F 0 "D2" V 6389 1832 50  0000 R CNN
F 1 "LED" V 6298 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6350 1950 50  0001 C CNN
F 3 "~" H 6350 1950 50  0001 C CNN
	1    6350 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 608761F7
P 6350 1450
F 0 "R2" H 6420 1496 50  0000 L CNN
F 1 "330" H 6420 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6280 1450 50  0001 C CNN
F 3 "~" H 6350 1450 50  0001 C CNN
	1    6350 1450
	1    0    0    -1  
$EndComp
Text GLabel 6350 1150 1    50   Input ~ 0
LED1
$Comp
L power:GND #PWR0102
U 1 1 608761FE
P 6350 2250
F 0 "#PWR0102" H 6350 2000 50  0001 C CNN
F 1 "GND" H 6355 2077 50  0000 C CNN
F 2 "" H 6350 2250 50  0001 C CNN
F 3 "" H 6350 2250 50  0001 C CNN
	1    6350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 1300 6350 1150
Wire Wire Line
	6350 1600 6350 1800
Wire Wire Line
	6350 2100 6350 2250
$Comp
L Device:LED D3
U 1 1 608794F8
P 6750 1950
F 0 "D3" V 6789 1832 50  0000 R CNN
F 1 "LED" V 6698 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6750 1950 50  0001 C CNN
F 3 "~" H 6750 1950 50  0001 C CNN
	1    6750 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 608794FE
P 6750 1450
F 0 "R3" H 6820 1496 50  0000 L CNN
F 1 "330" H 6820 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6680 1450 50  0001 C CNN
F 3 "~" H 6750 1450 50  0001 C CNN
	1    6750 1450
	1    0    0    -1  
$EndComp
Text GLabel 6750 1150 1    50   Input ~ 0
LED2
$Comp
L power:GND #PWR0103
U 1 1 60879505
P 6750 2250
F 0 "#PWR0103" H 6750 2000 50  0001 C CNN
F 1 "GND" H 6755 2077 50  0000 C CNN
F 2 "" H 6750 2250 50  0001 C CNN
F 3 "" H 6750 2250 50  0001 C CNN
	1    6750 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 1300 6750 1150
Wire Wire Line
	6750 1600 6750 1800
Wire Wire Line
	6750 2100 6750 2250
$Comp
L Device:LED D4
U 1 1 6087950E
P 7200 1950
F 0 "D4" V 7239 1832 50  0000 R CNN
F 1 "LED" V 7148 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 7200 1950 50  0001 C CNN
F 3 "~" H 7200 1950 50  0001 C CNN
	1    7200 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 60879514
P 7200 1450
F 0 "R4" H 7270 1496 50  0000 L CNN
F 1 "330" H 7270 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7130 1450 50  0001 C CNN
F 3 "~" H 7200 1450 50  0001 C CNN
	1    7200 1450
	1    0    0    -1  
$EndComp
Text GLabel 7200 1150 1    50   Input ~ 0
LED3
$Comp
L power:GND #PWR0104
U 1 1 6087951B
P 7200 2250
F 0 "#PWR0104" H 7200 2000 50  0001 C CNN
F 1 "GND" H 7205 2077 50  0000 C CNN
F 2 "" H 7200 2250 50  0001 C CNN
F 3 "" H 7200 2250 50  0001 C CNN
	1    7200 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1300 7200 1150
Wire Wire Line
	7200 1600 7200 1800
Wire Wire Line
	7200 2100 7200 2250
$Comp
L Device:LED D5
U 1 1 6087FA3A
P 7600 1950
F 0 "D5" V 7639 1832 50  0000 R CNN
F 1 "LED" V 7548 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 7600 1950 50  0001 C CNN
F 3 "~" H 7600 1950 50  0001 C CNN
	1    7600 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 6087FA40
P 7600 1450
F 0 "R5" H 7670 1496 50  0000 L CNN
F 1 "330" H 7670 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7530 1450 50  0001 C CNN
F 3 "~" H 7600 1450 50  0001 C CNN
	1    7600 1450
	1    0    0    -1  
$EndComp
Text GLabel 7600 1150 1    50   Input ~ 0
LED4
$Comp
L power:GND #PWR0105
U 1 1 6087FA47
P 7600 2250
F 0 "#PWR0105" H 7600 2000 50  0001 C CNN
F 1 "GND" H 7605 2077 50  0000 C CNN
F 2 "" H 7600 2250 50  0001 C CNN
F 3 "" H 7600 2250 50  0001 C CNN
	1    7600 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 1300 7600 1150
Wire Wire Line
	7600 1600 7600 1800
Wire Wire Line
	7600 2100 7600 2250
$Comp
L Device:LED D6
U 1 1 6087FA50
P 8050 1950
F 0 "D6" V 8089 1832 50  0000 R CNN
F 1 "LED" V 7998 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 8050 1950 50  0001 C CNN
F 3 "~" H 8050 1950 50  0001 C CNN
	1    8050 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 6087FA56
P 8050 1450
F 0 "R6" H 8120 1496 50  0000 L CNN
F 1 "330" H 8120 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7980 1450 50  0001 C CNN
F 3 "~" H 8050 1450 50  0001 C CNN
	1    8050 1450
	1    0    0    -1  
$EndComp
Text GLabel 8050 1150 1    50   Input ~ 0
LED5
$Comp
L power:GND #PWR0106
U 1 1 6087FA5D
P 8050 2250
F 0 "#PWR0106" H 8050 2000 50  0001 C CNN
F 1 "GND" H 8055 2077 50  0000 C CNN
F 2 "" H 8050 2250 50  0001 C CNN
F 3 "" H 8050 2250 50  0001 C CNN
	1    8050 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 1300 8050 1150
Wire Wire Line
	8050 1600 8050 1800
Wire Wire Line
	8050 2100 8050 2250
$Comp
L Device:LED D7
U 1 1 6087FA66
P 8450 1950
F 0 "D7" V 8489 1832 50  0000 R CNN
F 1 "LED" V 8398 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 8450 1950 50  0001 C CNN
F 3 "~" H 8450 1950 50  0001 C CNN
	1    8450 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 6087FA6C
P 8450 1450
F 0 "R7" H 8520 1496 50  0000 L CNN
F 1 "330" H 8520 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8380 1450 50  0001 C CNN
F 3 "~" H 8450 1450 50  0001 C CNN
	1    8450 1450
	1    0    0    -1  
$EndComp
Text GLabel 8450 1150 1    50   Input ~ 0
LED6
$Comp
L power:GND #PWR0107
U 1 1 6087FA73
P 8450 2250
F 0 "#PWR0107" H 8450 2000 50  0001 C CNN
F 1 "GND" H 8455 2077 50  0000 C CNN
F 2 "" H 8450 2250 50  0001 C CNN
F 3 "" H 8450 2250 50  0001 C CNN
	1    8450 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1300 8450 1150
Wire Wire Line
	8450 1600 8450 1800
Wire Wire Line
	8450 2100 8450 2250
$Comp
L Device:LED D8
U 1 1 6087FA7C
P 8900 1950
F 0 "D8" V 8939 1832 50  0000 R CNN
F 1 "LED" V 8848 1832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 8900 1950 50  0001 C CNN
F 3 "~" H 8900 1950 50  0001 C CNN
	1    8900 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R8
U 1 1 6087FA82
P 8900 1450
F 0 "R8" H 8970 1496 50  0000 L CNN
F 1 "330" H 8970 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8830 1450 50  0001 C CNN
F 3 "~" H 8900 1450 50  0001 C CNN
	1    8900 1450
	1    0    0    -1  
$EndComp
Text GLabel 8900 1150 1    50   Input ~ 0
LED7
$Comp
L power:GND #PWR0108
U 1 1 6087FA89
P 8900 2250
F 0 "#PWR0108" H 8900 2000 50  0001 C CNN
F 1 "GND" H 8905 2077 50  0000 C CNN
F 2 "" H 8900 2250 50  0001 C CNN
F 3 "" H 8900 2250 50  0001 C CNN
	1    8900 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 1300 8900 1150
Wire Wire Line
	8900 1600 8900 1800
Wire Wire Line
	8900 2100 8900 2250
Text GLabel 3150 1850 2    50   Input ~ 0
LED0
Wire Wire Line
	3000 1850 3150 1850
Text GLabel 2350 1850 0    50   Input ~ 0
LED1
Wire Wire Line
	2500 1850 2350 1850
Text GLabel 3150 1750 2    50   Input ~ 0
LED2
Wire Wire Line
	3000 1750 3150 1750
Text GLabel 2350 1750 0    50   Input ~ 0
LED3
Wire Wire Line
	2500 1750 2350 1750
Text GLabel 3150 1650 2    50   Input ~ 0
LED4
Wire Wire Line
	3000 1650 3150 1650
Text GLabel 2350 1650 0    50   Input ~ 0
LED5
Wire Wire Line
	2500 1650 2350 1650
Text GLabel 3150 1550 2    50   Input ~ 0
LED6
Wire Wire Line
	3000 1550 3150 1550
Text GLabel 2350 1550 0    50   Input ~ 0
LED7
Wire Wire Line
	2500 1550 2350 1550
$Comp
L power:GND #PWR0109
U 1 1 608849A4
P 2350 1950
F 0 "#PWR0109" H 2350 1700 50  0001 C CNN
F 1 "GND" V 2355 1822 50  0000 R CNN
F 2 "" H 2350 1950 50  0001 C CNN
F 3 "" H 2350 1950 50  0001 C CNN
	1    2350 1950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 608851EE
P 3150 1950
F 0 "#PWR0110" H 3150 1700 50  0001 C CNN
F 1 "GND" V 3155 1822 50  0000 R CNN
F 2 "" H 3150 1950 50  0001 C CNN
F 3 "" H 3150 1950 50  0001 C CNN
	1    3150 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3150 1950 3000 1950
Wire Wire Line
	2500 1950 2350 1950
NoConn ~ 3000 2050
NoConn ~ 2500 2050
$EndSCHEMATC
