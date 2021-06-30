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
L Connector_Generic:Conn_02x06_Odd_Even J?
U 1 1 60A2E9D0
P 3300 6150
F 0 "J?" H 3350 6567 50  0000 C CNN
F 1 "Conn_02x06_Odd_Even" H 3350 6476 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 3300 6150 50  0001 C CNN
F 3 "~" H 3300 6150 50  0001 C CNN
	1    3300 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A2F9D4
P 3850 6350
F 0 "#PWR?" H 3850 6100 50  0001 C CNN
F 1 "GND" V 3855 6222 50  0000 R CNN
F 2 "" H 3850 6350 50  0001 C CNN
F 3 "" H 3850 6350 50  0001 C CNN
	1    3850 6350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A2FFBC
P 2800 6350
F 0 "#PWR?" H 2800 6100 50  0001 C CNN
F 1 "GND" V 2805 6222 50  0000 R CNN
F 2 "" H 2800 6350 50  0001 C CNN
F 3 "" H 2800 6350 50  0001 C CNN
	1    2800 6350
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60A3030B
P 2800 6450
F 0 "#PWR?" H 2800 6300 50  0001 C CNN
F 1 "+3V3" V 2815 6578 50  0000 L CNN
F 2 "" H 2800 6450 50  0001 C CNN
F 3 "" H 2800 6450 50  0001 C CNN
	1    2800 6450
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60A3054F
P 3850 6450
F 0 "#PWR?" H 3850 6300 50  0001 C CNN
F 1 "+3V3" V 3865 6578 50  0000 L CNN
F 2 "" H 3850 6450 50  0001 C CNN
F 3 "" H 3850 6450 50  0001 C CNN
	1    3850 6450
	0    1    1    0   
$EndComp
Text GLabel 3850 6050 2    50   Input ~ 0
SPI_CLK
Text GLabel 3850 6150 2    50   Input ~ 0
SPI_RX
Text GLabel 2800 6150 0    50   Input ~ 0
SPI_CSN
Text GLabel 2800 6050 0    50   Input ~ 0
SPI_TX
Wire Wire Line
	3850 6050 3600 6050
Wire Wire Line
	3600 6150 3850 6150
Wire Wire Line
	3850 6350 3600 6350
Wire Wire Line
	3600 6450 3850 6450
Wire Wire Line
	3100 6450 2800 6450
Wire Wire Line
	3100 6350 2800 6350
Wire Wire Line
	2800 6150 3100 6150
Wire Wire Line
	3100 6050 2800 6050
$Comp
L Connector:Conn_Coaxial J?
U 1 1 60A31A03
P 8800 1850
F 0 "J?" H 8900 1825 50  0000 L CNN
F 1 "Conn_Coaxial" H 8900 1734 50  0000 L CNN
F 2 "" H 8800 1850 50  0001 C CNN
F 3 " ~" H 8800 1850 50  0001 C CNN
	1    8800 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A326FB
P 8800 2050
F 0 "#PWR?" H 8800 1800 50  0001 C CNN
F 1 "GND" H 8805 1877 50  0000 C CNN
F 2 "" H 8800 2050 50  0001 C CNN
F 3 "" H 8800 2050 50  0001 C CNN
	1    8800 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C125
U 1 1 60A35692
P 8350 1850
F 0 "C125" V 8098 1850 50  0000 C CNN
F 1 "220pF" V 8189 1850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8388 1700 50  0001 C CNN
F 3 "~" H 8350 1850 50  0001 C CNN
	1    8350 1850
	0    1    1    0   
$EndComp
$Comp
L Device:C C123
U 1 1 60A35E36
P 7950 2100
F 0 "C123" H 8065 2146 50  0000 L CNN
F 1 "5.6pF" H 8065 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7988 1950 50  0001 C CNN
F 3 "~" H 7950 2100 50  0001 C CNN
	1    7950 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C122
U 1 1 60A36923
P 7450 2100
F 0 "C122" H 7565 2146 50  0000 L CNN
F 1 "8.2pF" H 7565 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7488 1950 50  0001 C CNN
F 3 "~" H 7450 2100 50  0001 C CNN
	1    7450 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C121
U 1 1 60A36D2F
P 6800 1750
F 0 "C121" V 6750 1600 50  0000 C CNN
F 1 "3.9pF" V 6750 1900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6838 1600 50  0001 C CNN
F 3 "~" H 6800 1750 50  0001 C CNN
	1    6800 1750
	0    1    1    0   
$EndComp
$Comp
L Device:C C131
U 1 1 60A3755B
P 6400 2100
F 0 "C131" H 6515 2146 50  0000 L CNN
F 1 "3.9pF" H 6515 2055 50  0000 L CNN
F 2 "" H 6438 1950 50  0001 C CNN
F 3 "~" H 6400 2100 50  0001 C CNN
	1    6400 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:C C124
U 1 1 60A37995
P 6400 1200
F 0 "C124" H 6285 1154 50  0000 R CNN
F 1 "220pF" H 6285 1245 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6438 1050 50  0001 C CNN
F 3 "~" H 6400 1200 50  0001 C CNN
	1    6400 1200
	-1   0    0    1   
$EndComp
$Comp
L Device:L L121
U 1 1 60A38065
P 6400 1600
F 0 "L121" H 6356 1554 50  0000 R CNN
F 1 "27nH" H 6356 1645 50  0000 R CNN
F 2 "Inductor_SMD:L_0603_1608Metric" H 6400 1600 50  0001 C CNN
F 3 "~" H 6400 1600 50  0001 C CNN
	1    6400 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:L L131
U 1 1 60A38A26
P 6800 1950
F 0 "L131" V 6750 2100 50  0000 C CNN
F 1 "27nH" V 6750 1800 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" H 6800 1950 50  0001 C CNN
F 3 "~" H 6800 1950 50  0001 C CNN
	1    6800 1950
	0    -1   -1   0   
$EndComp
$Comp
L Device:L L122
U 1 1 60A39321
P 7200 1850
F 0 "L122" V 7390 1850 50  0000 C CNN
F 1 "22nH" V 7299 1850 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" H 7200 1850 50  0001 C CNN
F 3 "~" H 7200 1850 50  0001 C CNN
	1    7200 1850
	0    -1   -1   0   
$EndComp
$Comp
L Device:L L123
U 1 1 60A3A077
P 7700 1850
F 0 "L123" V 7890 1850 50  0000 C CNN
F 1 "27nH" V 7799 1850 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" H 7700 1850 50  0001 C CNN
F 3 "~" H 7700 1850 50  0001 C CNN
	1    7700 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A3B067
P 7950 2350
F 0 "#PWR?" H 7950 2100 50  0001 C CNN
F 1 "GND" H 7955 2177 50  0000 C CNN
F 2 "" H 7950 2350 50  0001 C CNN
F 3 "" H 7950 2350 50  0001 C CNN
	1    7950 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A3B334
P 7450 2350
F 0 "#PWR?" H 7450 2100 50  0001 C CNN
F 1 "GND" H 7455 2177 50  0000 C CNN
F 2 "" H 7450 2350 50  0001 C CNN
F 3 "" H 7450 2350 50  0001 C CNN
	1    7450 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A3B60D
P 6400 950
F 0 "#PWR?" H 6400 700 50  0001 C CNN
F 1 "GND" H 6405 777 50  0000 C CNN
F 2 "" H 6400 950 50  0001 C CNN
F 3 "" H 6400 950 50  0001 C CNN
	1    6400 950 
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A3B8F2
P 6400 2350
F 0 "#PWR?" H 6400 2100 50  0001 C CNN
F 1 "GND" H 6405 2177 50  0000 C CNN
F 2 "" H 6400 2350 50  0001 C CNN
F 3 "" H 6400 2350 50  0001 C CNN
	1    6400 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 1850 7950 1850
Wire Wire Line
	8500 1850 8600 1850
Wire Wire Line
	7950 1950 7950 1850
Connection ~ 7950 1850
Wire Wire Line
	7950 1850 8200 1850
Wire Wire Line
	7450 1950 7450 1850
Wire Wire Line
	7450 1850 7550 1850
Wire Wire Line
	7350 1850 7450 1850
Connection ~ 7450 1850
Wire Wire Line
	7450 2250 7450 2350
Wire Wire Line
	7950 2350 7950 2250
Wire Wire Line
	6400 1050 6400 950 
Wire Wire Line
	6400 1350 6400 1450
Wire Wire Line
	6950 1750 7050 1750
Wire Wire Line
	7050 1950 7050 1850
Wire Wire Line
	7050 1850 7050 1750
Wire Wire Line
	7050 1950 6950 1950
Connection ~ 7050 1850
Wire Wire Line
	6400 1750 6650 1750
Wire Wire Line
	6650 1950 6400 1950
Wire Wire Line
	6400 2250 6400 2350
$Comp
L JJH_Library:CC1101RGPR U1
U 1 1 60A502FE
P 4600 1900
F 0 "U1" H 4575 2315 50  0000 C CNN
F 1 "CC1101RGPR" H 4575 2224 50  0000 C CNN
F 2 "" H 4250 1900 50  0001 C CNN
F 3 "" H 4250 1900 50  0001 C CNN
	1    4600 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60A55E7E
P 5550 2350
F 0 "#PWR?" H 5550 2200 50  0001 C CNN
F 1 "+3V3" V 5565 2478 50  0000 L CNN
F 2 "" H 5550 2350 50  0001 C CNN
F 3 "" H 5550 2350 50  0001 C CNN
	1    5550 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 2350 5400 2350
Wire Wire Line
	5400 2350 5400 2250
Wire Wire Line
	5400 2150 5250 2150
Wire Wire Line
	5400 2350 5400 2450
Wire Wire Line
	5400 2550 5250 2550
Connection ~ 5400 2350
Wire Wire Line
	5250 2450 5400 2450
Connection ~ 5400 2450
Wire Wire Line
	5400 2450 5400 2550
Wire Wire Line
	5400 2350 5250 2350
Wire Wire Line
	5250 2250 5400 2250
Connection ~ 5400 2250
Wire Wire Line
	5400 2250 5400 2150
$Comp
L power:GND #PWR?
U 1 1 60A59036
P 5550 2900
F 0 "#PWR?" H 5550 2650 50  0001 C CNN
F 1 "GND" V 5555 2772 50  0000 R CNN
F 2 "" H 5550 2900 50  0001 C CNN
F 3 "" H 5550 2900 50  0001 C CNN
	1    5550 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5250 2800 5400 2800
Wire Wire Line
	5400 2800 5400 2900
Wire Wire Line
	5400 2900 5550 2900
Wire Wire Line
	5400 2900 5400 3000
Wire Wire Line
	5400 3000 5250 3000
Connection ~ 5400 2900
Wire Wire Line
	5250 2900 5400 2900
Wire Wire Line
	6400 1950 5950 1950
Wire Wire Line
	5950 1900 5250 1900
$Comp
L Device:C C?
U 1 1 60A6949A
P 2900 2600
F 0 "C?" V 3000 2450 50  0000 C CNN
F 1 "27pF" V 2750 2600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2938 2450 50  0001 C CNN
F 3 "~" H 2900 2600 50  0001 C CNN
	1    2900 2600
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 60A69C8B
P 2900 3000
F 0 "C?" V 2950 3150 50  0000 C CNN
F 1 "27pF" V 2750 3000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2938 2850 50  0001 C CNN
F 3 "~" H 2900 3000 50  0001 C CNN
	1    2900 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A6D454
P 2600 2600
F 0 "#PWR?" H 2600 2350 50  0001 C CNN
F 1 "GND" V 2605 2472 50  0000 R CNN
F 2 "" H 2600 2600 50  0001 C CNN
F 3 "" H 2600 2600 50  0001 C CNN
	1    2600 2600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A6D7EE
P 2600 3000
F 0 "#PWR?" H 2600 2750 50  0001 C CNN
F 1 "GND" V 2605 2872 50  0000 R CNN
F 2 "" H 2600 3000 50  0001 C CNN
F 3 "" H 2600 3000 50  0001 C CNN
	1    2600 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 2700 3900 2600
Connection ~ 3150 2600
Wire Wire Line
	3150 2600 3050 2600
Wire Wire Line
	2750 2600 2600 2600
Wire Wire Line
	2600 3000 2750 3000
Wire Wire Line
	3050 3000 3150 3000
Wire Wire Line
	3900 2900 3900 3000
Connection ~ 3150 3000
Text GLabel 3750 1800 0    50   Input ~ 0
SPI_CLK
Text GLabel 3750 2100 0    50   Input ~ 0
SPI_RX
Text GLabel 3750 1900 0    50   Input ~ 0
SPI_CSN
Text GLabel 3750 2000 0    50   Input ~ 0
SPI_TX
Text GLabel 3750 2450 0    50   Input ~ 0
GDO0
Text GLabel 3750 2350 0    50   Input ~ 0
GDO2
Wire Wire Line
	3900 2450 3750 2450
Wire Wire Line
	3750 2350 3900 2350
Wire Wire Line
	3900 2100 3750 2100
Wire Wire Line
	3750 2000 3900 2000
Wire Wire Line
	3900 1900 3750 1900
Wire Wire Line
	3750 1800 3900 1800
$Comp
L Device:R R171
U 1 1 60A8D230
P 5550 3300
F 0 "R171" V 5450 3300 50  0000 C CNN
F 1 "56K" V 5650 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5480 3300 50  0001 C CNN
F 3 "~" H 5550 3300 50  0001 C CNN
	1    5550 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A8E43F
P 5850 3300
F 0 "#PWR?" H 5850 3050 50  0001 C CNN
F 1 "GND" V 5855 3172 50  0000 R CNN
F 2 "" H 5850 3300 50  0001 C CNN
F 3 "" H 5850 3300 50  0001 C CNN
	1    5850 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5850 3300 5700 3300
Wire Wire Line
	5400 3300 5250 3300
Text GLabel 2800 6250 0    50   Input ~ 0
GDO2
Text GLabel 3850 6250 2    50   Input ~ 0
GDO0
Wire Wire Line
	3850 6250 3600 6250
Wire Wire Line
	3100 6250 2800 6250
Wire Wire Line
	5950 1950 5950 1900
Connection ~ 6400 1950
Wire Wire Line
	5250 1800 5950 1800
Wire Wire Line
	5950 1800 5950 1750
Wire Wire Line
	5950 1750 6400 1750
Connection ~ 6400 1750
Wire Wire Line
	3150 2600 3900 2600
Wire Wire Line
	3150 3000 3900 3000
Wire Notes Line
	6950 4300 6950 6550
Wire Notes Line
	500  4300 11200 4300
Text Notes 2650 4550 0    118  ~ 0
PMod Connector 
NoConn ~ 3600 5950
NoConn ~ 3100 5950
$Comp
L Device:C C51
U 1 1 60E263E0
P 3150 3450
F 0 "C51" H 3035 3404 50  0000 R CNN
F 1 "100nF" H 3035 3495 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3188 3300 50  0001 C CNN
F 3 "~" H 3150 3450 50  0001 C CNN
	1    3150 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3150 3300 3150 3200
Wire Wire Line
	3150 3200 3900 3200
$Comp
L power:GND #PWR?
U 1 1 60E2AE47
P 3150 3700
F 0 "#PWR?" H 3150 3450 50  0001 C CNN
F 1 "GND" H 3155 3527 50  0000 C CNN
F 2 "" H 3150 3700 50  0001 C CNN
F 3 "" H 3150 3700 50  0001 C CNN
	1    3150 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60E2B410
P 3750 3700
F 0 "#PWR?" H 3750 3550 50  0001 C CNN
F 1 "+3V3" H 3765 3873 50  0000 C CNN
F 2 "" H 3750 3700 50  0001 C CNN
F 3 "" H 3750 3700 50  0001 C CNN
	1    3750 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	3750 3700 3750 3300
Wire Wire Line
	3750 3300 3900 3300
Wire Wire Line
	3150 3700 3150 3600
Text Notes 6350 3350 0    55   ~ 0
Designed optermised for 433MHz based on:\nhttps://www.ti.com/lit/ds/symlink/cc1101.pdf\n\nPage 25/26 for circuit and values selected \n
$Comp
L Device:Crystal_GND24_Small Y?
U 1 1 60E33551
P 3150 2800
F 0 "Y?" V 3250 2550 50  0000 L CNN
F 1 "26MHz" V 3050 2450 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_Abracon_ABM3C-4Pin_5.0x3.2mm" H 3150 2800 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/3/abrcs02719_1-2258580.pdf" H 3150 2800 50  0001 C CNN
F 4 "815-ABM3C-26-D4YT" H 3150 2800 50  0001 C CNN "Mouser No."
	1    3150 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3150 2600 3150 2700
Wire Wire Line
	3150 2900 3150 3000
$Comp
L power:GND #PWR?
U 1 1 60E3F2C7
P 3000 2800
F 0 "#PWR?" H 3000 2550 50  0001 C CNN
F 1 "GND" V 3005 2672 50  0000 R CNN
F 2 "" H 3000 2800 50  0001 C CNN
F 3 "" H 3000 2800 50  0001 C CNN
	1    3000 2800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60E3FC31
P 3300 2800
F 0 "#PWR?" H 3300 2550 50  0001 C CNN
F 1 "GND" V 3305 2672 50  0000 R CNN
F 2 "" H 3300 2800 50  0001 C CNN
F 3 "" H 3300 2800 50  0001 C CNN
	1    3300 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3300 2800 3250 2800
Wire Wire Line
	3050 2800 3000 2800
$EndSCHEMATC
