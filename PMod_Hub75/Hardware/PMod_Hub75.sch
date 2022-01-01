EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PMod Board for Hub75 LED matrix"
Date ""
Rev "v0.1"
Comp "James Horton"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Licensed Under CERN Open Hardware Licence Version 2 - Permissive"
$EndDescr
$Comp
L JJH_Library:SN74LVC8T245DWR IC1
U 1 1 61C3820F
P 5600 2050
F 0 "IC1" H 6250 2315 50  0000 C CNN
F 1 "SN74LVC8T245DWR" H 6250 2224 50  0000 C CNN
F 2 "SOIC127P1030X265-24N" H 6750 2150 50  0001 L CNN
F 3 "http://www.ti.com/lit/gpn/sn74lvc8t245" H 6750 2050 50  0001 L CNN
F 4 "8-Bit Dual-Supply Bus Transceiver with Configurable Voltage-Level Shifting and Three-State Outputs" H 6750 1950 50  0001 L CNN "Description"
F 5 "2.65" H 6750 1850 50  0001 L CNN "Height"
F 6 "595-SN74LVC8T245DWR" H 6750 1750 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/SN74LVC8T245DWR?qs=dT9u2OTAaVX2fwsENIjeqA%3D%3D" H 6750 1650 50  0001 L CNN "Mouser Price/Stock"
F 8 "Texas Instruments" H 6750 1550 50  0001 L CNN "Manufacturer_Name"
F 9 "SN74LVC8T245DWR" H 6750 1450 50  0001 L CNN "Manufacturer_Part_Number"
	1    5600 2050
	1    0    0    -1  
$EndComp
$Comp
L JJH_Library:SN74LVC8T245DWR IC2
U 1 1 61C3989E
P 5600 4100
F 0 "IC2" H 6250 4365 50  0000 C CNN
F 1 "SN74LVC8T245DWR" H 6250 4274 50  0000 C CNN
F 2 "SOIC127P1030X265-24N" H 6750 4200 50  0001 L CNN
F 3 "http://www.ti.com/lit/gpn/sn74lvc8t245" H 6750 4100 50  0001 L CNN
F 4 "8-Bit Dual-Supply Bus Transceiver with Configurable Voltage-Level Shifting and Three-State Outputs" H 6750 4000 50  0001 L CNN "Description"
F 5 "2.65" H 6750 3900 50  0001 L CNN "Height"
F 6 "595-SN74LVC8T245DWR" H 6750 3800 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/SN74LVC8T245DWR?qs=dT9u2OTAaVX2fwsENIjeqA%3D%3D" H 6750 3700 50  0001 L CNN "Mouser Price/Stock"
F 8 "Texas Instruments" H 6750 3600 50  0001 L CNN "Manufacturer_Name"
F 9 "SN74LVC8T245DWR" H 6750 3500 50  0001 L CNN "Manufacturer_Part_Number"
	1    5600 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J1
U 1 1 61C3C515
P 2200 2600
F 0 "J1" H 2250 3017 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 2250 2926 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 2200 2600 50  0001 C CNN
F 3 "~" H 2200 2600 50  0001 C CNN
	1    2200 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J2
U 1 1 61C3D51F
P 2250 4700
F 0 "J2" H 2300 5117 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 2300 5026 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 2250 4700 50  0001 C CNN
F 3 "~" H 2250 4700 50  0001 C CNN
	1    2250 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J3
U 1 1 61C3F404
P 9600 3700
F 0 "J3" H 9650 4217 50  0000 C CNN
F 1 "Conn_02x08_Counter_Clockwise" H 9650 4126 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 9600 3700 50  0001 C CNN
F 3 "~" H 9600 3700 50  0001 C CNN
	1    9600 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 61C461D7
P 2800 5350
F 0 "#PWR0101" H 2800 5100 50  0001 C CNN
F 1 "GND" H 2805 5177 50  0000 C CNN
F 2 "" H 2800 5350 50  0001 C CNN
F 3 "" H 2800 5350 50  0001 C CNN
	1    2800 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0102
U 1 1 61C48293
P 2250 1800
F 0 "#PWR0102" H 2250 1650 50  0001 C CNN
F 1 "+3V3" H 2265 1973 50  0000 C CNN
F 2 "" H 2250 1800 50  0001 C CNN
F 3 "" H 2250 1800 50  0001 C CNN
	1    2250 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5350 2800 4900
Wire Wire Line
	2800 4900 2550 4900
Wire Wire Line
	2800 4900 2800 2800
Wire Wire Line
	2800 2800 2500 2800
Connection ~ 2800 4900
Wire Wire Line
	2550 5000 2750 5000
Wire Wire Line
	2750 5000 2750 2900
Wire Wire Line
	2750 1900 2250 1900
Wire Wire Line
	2250 1900 2250 1800
Wire Wire Line
	2500 2900 2750 2900
Connection ~ 2750 2900
Wire Wire Line
	2750 2900 2750 1900
Wire Wire Line
	2250 1900 1650 1900
Wire Wire Line
	1650 1900 1650 2900
Wire Wire Line
	1650 5000 2050 5000
Connection ~ 2250 1900
Wire Wire Line
	2000 2800 1600 2800
Wire Wire Line
	1600 4900 2050 4900
$Comp
L power:GND #PWR0103
U 1 1 61C4EF48
P 1600 5300
F 0 "#PWR0103" H 1600 5050 50  0001 C CNN
F 1 "GND" H 1605 5127 50  0000 C CNN
F 2 "" H 1600 5300 50  0001 C CNN
F 3 "" H 1600 5300 50  0001 C CNN
	1    1600 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2800 1600 4900
Wire Wire Line
	1650 2900 2000 2900
Connection ~ 1650 2900
Wire Wire Line
	1650 2900 1650 5000
Connection ~ 1600 4900
Wire Wire Line
	1600 4900 1600 5300
$Comp
L power:GND #PWR0104
U 1 1 61C55D53
P 6250 3300
F 0 "#PWR0104" H 6250 3050 50  0001 C CNN
F 1 "GND" H 6255 3127 50  0000 C CNN
F 2 "" H 6250 3300 50  0001 C CNN
F 3 "" H 6250 3300 50  0001 C CNN
	1    6250 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 61C5A127
P 6250 5400
F 0 "#PWR0105" H 6250 5150 50  0001 C CNN
F 1 "GND" H 6255 5227 50  0000 C CNN
F 2 "" H 6250 5400 50  0001 C CNN
F 3 "" H 6250 5400 50  0001 C CNN
	1    6250 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 5200 6900 5400
Wire Wire Line
	6900 5400 6250 5400
Wire Wire Line
	6250 5400 5600 5400
Wire Wire Line
	5600 5400 5600 5200
Connection ~ 6250 5400
Connection ~ 5600 5200
Wire Wire Line
	5600 5200 5600 5100
Wire Wire Line
	5600 3050 5600 3150
Wire Wire Line
	5600 3300 6250 3300
Connection ~ 5600 3150
Wire Wire Line
	5600 3150 5600 3300
Wire Wire Line
	6250 3300 6900 3300
Wire Wire Line
	6900 3300 6900 3150
Connection ~ 6250 3300
Wire Wire Line
	9100 3400 9400 3400
Text GLabel 9100 3400 0    50   Input ~ 0
Out_R0
Text GLabel 9100 3500 0    50   Input ~ 0
Out_B0
Wire Wire Line
	9400 3500 9100 3500
Text GLabel 9100 3600 0    50   Input ~ 0
Out_R1
Text GLabel 9100 3700 0    50   Input ~ 0
Out_B1
Text GLabel 9100 3800 0    50   Input ~ 0
Out_A
Text GLabel 9100 3900 0    50   Input ~ 0
Out_C
Text GLabel 9100 4000 0    50   Input ~ 0
Out_CLK
Text GLabel 9100 4100 0    50   Input ~ 0
Out_OE
Text GLabel 10300 4000 2    50   Input ~ 0
Out_Latch
Text GLabel 10300 3900 2    50   Input ~ 0
Out_D
Text GLabel 10300 3800 2    50   Input ~ 0
Out_B
Text GLabel 10300 3700 2    50   Input ~ 0
Out_E
Text GLabel 10300 3600 2    50   Input ~ 0
Out_G1
Text GLabel 10300 3400 2    50   Input ~ 0
Out_G0
Wire Wire Line
	9400 3600 9100 3600
Wire Wire Line
	9100 3700 9400 3700
Wire Wire Line
	9400 3800 9100 3800
Wire Wire Line
	9100 3900 9400 3900
Wire Wire Line
	9400 4000 9100 4000
Wire Wire Line
	9100 4100 9400 4100
Wire Wire Line
	9900 4100 10300 4100
Wire Wire Line
	9900 4000 10300 4000
Wire Wire Line
	10300 3900 9900 3900
Wire Wire Line
	9900 3800 10300 3800
Wire Wire Line
	9900 3700 10300 3700
Wire Wire Line
	10300 3600 9900 3600
Wire Wire Line
	9900 3500 10300 3500
Wire Wire Line
	9900 3400 10300 3400
Text GLabel 7200 5100 2    50   Input ~ 0
Out_R0
Text GLabel 7200 5000 2    50   Input ~ 0
Out_B0
Text GLabel 7200 4800 2    50   Input ~ 0
Out_R1
Text GLabel 7200 4700 2    50   Input ~ 0
Out_B1
Text GLabel 7200 4500 2    50   Input ~ 0
Out_A
Text GLabel 7200 4400 2    50   Input ~ 0
Out_B
Text GLabel 7200 2750 2    50   Input ~ 0
Out_CLK
Text GLabel 7200 2650 2    50   Input ~ 0
Out_OE
Text GLabel 7200 2550 2    50   Input ~ 0
Out_Latch
Text GLabel 7200 2950 2    50   Input ~ 0
Out_D
Text GLabel 7200 3050 2    50   Input ~ 0
Out_C
Text GLabel 7200 2850 2    50   Input ~ 0
Out_E
Text GLabel 7200 4600 2    50   Input ~ 0
Out_G1
Text GLabel 7200 4900 2    50   Input ~ 0
Out_G0
Text GLabel 1500 4800 0    50   Input ~ 0
In_R0
Text GLabel 1500 4700 0    50   Input ~ 0
In_B0
Text GLabel 3050 4600 2    50   Input ~ 0
In_B1
Text GLabel 3050 4500 2    50   Input ~ 0
In_A
Text GLabel 1500 4500 0    50   Input ~ 0
In_B
Text GLabel 3000 2600 2    50   Input ~ 0
In_CLK
Text GLabel 3000 2500 2    50   Input ~ 0
In_OE
Text GLabel 3000 2700 2    50   Input ~ 0
In_D
Text GLabel 1500 2700 0    50   Input ~ 0
In_C
Text GLabel 1500 2600 0    50   Input ~ 0
In_E
Text GLabel 1500 4600 0    50   Input ~ 0
In_G1
Text GLabel 3050 4800 2    50   Input ~ 0
In_G0
Text GLabel 3050 4700 2    50   Input ~ 0
In_R1
Text GLabel 1500 2500 0    50   Input ~ 0
In_Latch
NoConn ~ 2000 2400
NoConn ~ 2500 2400
Wire Wire Line
	2500 2500 3000 2500
Wire Wire Line
	3000 2600 2500 2600
Wire Wire Line
	2500 2700 3000 2700
Wire Wire Line
	2000 2700 1500 2700
Wire Wire Line
	1500 2600 2000 2600
Wire Wire Line
	2000 2500 1500 2500
Wire Wire Line
	1500 4500 2050 4500
Wire Wire Line
	1500 4600 2050 4600
Wire Wire Line
	2550 4500 3050 4500
Wire Wire Line
	3050 4600 2550 4600
Wire Wire Line
	2550 4700 3050 4700
Wire Wire Line
	3050 4800 2550 4800
Wire Wire Line
	2050 4700 1500 4700
Wire Wire Line
	1500 4800 2050 4800
Text GLabel 5300 4500 0    50   Input ~ 0
In_B1
Text GLabel 5300 4400 0    50   Input ~ 0
In_A
Text GLabel 5300 4900 0    50   Input ~ 0
In_G0
Text GLabel 5300 4700 0    50   Input ~ 0
In_R1
Text GLabel 5300 5000 0    50   Input ~ 0
In_R0
Text GLabel 5300 4800 0    50   Input ~ 0
In_B0
Text GLabel 5300 4300 0    50   Input ~ 0
In_B
Text GLabel 5300 4600 0    50   Input ~ 0
In_G1
Text GLabel 5350 2950 0    50   Input ~ 0
In_C
Text GLabel 5350 2750 0    50   Input ~ 0
In_E
Text GLabel 5350 2450 0    50   Input ~ 0
In_Latch
Text GLabel 5350 2650 0    50   Input ~ 0
In_CLK
Text GLabel 5350 2550 0    50   Input ~ 0
In_OE
Text GLabel 5350 2850 0    50   Input ~ 0
In_D
Wire Wire Line
	5600 4300 5300 4300
Wire Wire Line
	5300 4400 5600 4400
Wire Wire Line
	5600 4500 5300 4500
Wire Wire Line
	5300 4600 5600 4600
Wire Wire Line
	5600 4700 5300 4700
Wire Wire Line
	5300 4800 5600 4800
Wire Wire Line
	5600 4900 5300 4900
Wire Wire Line
	5300 5000 5600 5000
Wire Wire Line
	6900 5100 7200 5100
Wire Wire Line
	7200 5000 6900 5000
Wire Wire Line
	6900 4900 7200 4900
Wire Wire Line
	7200 4800 6900 4800
Wire Wire Line
	6900 4700 7200 4700
Wire Wire Line
	7200 4600 6900 4600
Wire Wire Line
	6900 4500 7200 4500
Wire Wire Line
	7200 4400 6900 4400
$Comp
L Device:R R2
U 1 1 61E0F5FC
P 5200 4200
F 0 "R2" V 5250 4400 50  0000 C CNN
F 1 "10k" V 5200 4200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5130 4200 50  0001 C CNN
F 3 "~" H 5200 4200 50  0001 C CNN
	1    5200 4200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 4200 5350 4200
$Comp
L Device:R R1
U 1 1 61E16905
P 5200 2150
F 0 "R1" V 5250 2350 50  0000 C CNN
F 1 "10k" V 5200 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5130 2150 50  0001 C CNN
F 3 "~" H 5200 2150 50  0001 C CNN
	1    5200 2150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 2150 5350 2150
$Comp
L power:+3V3 #PWR0106
U 1 1 61E19688
P 4600 4100
F 0 "#PWR0106" H 4600 3950 50  0001 C CNN
F 1 "+3V3" V 4615 4228 50  0000 L CNN
F 2 "" H 4600 4100 50  0001 C CNN
F 3 "" H 4600 4100 50  0001 C CNN
	1    4600 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 61E1AD69
P 4700 4500
F 0 "#PWR0107" H 4700 4250 50  0001 C CNN
F 1 "GND" H 4705 4327 50  0000 C CNN
F 2 "" H 4700 4500 50  0001 C CNN
F 3 "" H 4700 4500 50  0001 C CNN
	1    4700 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61E1B60D
P 4700 4350
F 0 "C2" H 4450 4400 50  0000 L CNN
F 1 "100n" H 4400 4300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4738 4200 50  0001 C CNN
F 3 "~" H 4700 4350 50  0001 C CNN
	1    4700 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4100 4700 4100
Wire Wire Line
	5050 4200 4700 4200
Wire Wire Line
	4700 4200 4700 4100
Connection ~ 4700 4200
Connection ~ 4700 4100
Wire Wire Line
	4700 4100 5600 4100
$Comp
L power:+3V3 #PWR0108
U 1 1 61E30D79
P 4600 2050
F 0 "#PWR0108" H 4600 1900 50  0001 C CNN
F 1 "+3V3" V 4615 2178 50  0000 L CNN
F 2 "" H 4600 2050 50  0001 C CNN
F 3 "" H 4600 2050 50  0001 C CNN
	1    4600 2050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 61E30D7F
P 4700 2450
F 0 "#PWR0109" H 4700 2200 50  0001 C CNN
F 1 "GND" H 4705 2277 50  0000 C CNN
F 2 "" H 4700 2450 50  0001 C CNN
F 3 "" H 4700 2450 50  0001 C CNN
	1    4700 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 61E30D85
P 4700 2300
F 0 "C1" H 4450 2350 50  0000 L CNN
F 1 "100n" H 4400 2250 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4738 2150 50  0001 C CNN
F 3 "~" H 4700 2300 50  0001 C CNN
	1    4700 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2050 4700 2050
Wire Wire Line
	5050 2150 4700 2150
Wire Wire Line
	4700 2150 4700 2050
Connection ~ 4700 2150
Connection ~ 4700 2050
Wire Wire Line
	4700 2050 5600 2050
Wire Wire Line
	5350 2450 5600 2450
Wire Wire Line
	5350 2550 5600 2550
Wire Wire Line
	5600 2650 5350 2650
Wire Wire Line
	5350 2750 5600 2750
Wire Wire Line
	5600 2850 5350 2850
Wire Wire Line
	5350 2950 5600 2950
Wire Wire Line
	6900 3050 7200 3050
Wire Wire Line
	7200 2950 6900 2950
Wire Wire Line
	6900 2850 7200 2850
Wire Wire Line
	7200 2750 6900 2750
Wire Wire Line
	6900 2650 7200 2650
Wire Wire Line
	7200 2550 6900 2550
$Comp
L Device:R R3
U 1 1 61E5D90E
P 7350 2250
F 0 "R3" V 7400 2050 50  0000 C CNN
F 1 "10k" V 7350 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7280 2250 50  0001 C CNN
F 3 "~" H 7350 2250 50  0001 C CNN
	1    7350 2250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 61E5F8B1
P 7750 2250
F 0 "#PWR0110" H 7750 2000 50  0001 C CNN
F 1 "GND" V 7755 2122 50  0000 R CNN
F 2 "" H 7750 2250 50  0001 C CNN
F 3 "" H 7750 2250 50  0001 C CNN
	1    7750 2250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 61E5FEDF
P 7750 2050
F 0 "#PWR0111" H 7750 1800 50  0001 C CNN
F 1 "GND" V 7755 1922 50  0000 R CNN
F 2 "" H 7750 2050 50  0001 C CNN
F 3 "" H 7750 2050 50  0001 C CNN
	1    7750 2050
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 61E606DF
P 7100 2050
F 0 "#PWR0112" H 7100 1900 50  0001 C CNN
F 1 "VCC" H 7115 2223 50  0000 C CNN
F 2 "" H 7100 2050 50  0001 C CNN
F 3 "" H 7100 2050 50  0001 C CNN
	1    7100 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 2150 7100 2150
Wire Wire Line
	7100 2150 7100 2050
Wire Wire Line
	6900 2050 7100 2050
Connection ~ 7100 2050
Wire Wire Line
	7750 2250 7500 2250
Wire Wire Line
	7200 2250 6900 2250
$Comp
L Device:C C3
U 1 1 61E716D4
P 7400 2050
F 0 "C3" V 7300 2150 50  0000 L CNN
F 1 "100n" V 7350 1800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7438 1900 50  0001 C CNN
F 3 "~" H 7400 2050 50  0001 C CNN
	1    7400 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 2050 7100 2050
Wire Wire Line
	7550 2050 7750 2050
$Comp
L Device:R R4
U 1 1 61E817F6
P 7350 4300
F 0 "R4" V 7400 4100 50  0000 C CNN
F 1 "10k" V 7350 4300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7280 4300 50  0001 C CNN
F 3 "~" H 7350 4300 50  0001 C CNN
	1    7350 4300
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 61E817FC
P 7750 4300
F 0 "#PWR0113" H 7750 4050 50  0001 C CNN
F 1 "GND" V 7755 4172 50  0000 R CNN
F 2 "" H 7750 4300 50  0001 C CNN
F 3 "" H 7750 4300 50  0001 C CNN
	1    7750 4300
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 61E81802
P 7750 4100
F 0 "#PWR0114" H 7750 3850 50  0001 C CNN
F 1 "GND" V 7755 3972 50  0000 R CNN
F 2 "" H 7750 4100 50  0001 C CNN
F 3 "" H 7750 4100 50  0001 C CNN
	1    7750 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0115
U 1 1 61E81808
P 7100 4100
F 0 "#PWR0115" H 7100 3950 50  0001 C CNN
F 1 "VCC" H 7115 4273 50  0000 C CNN
F 2 "" H 7100 4100 50  0001 C CNN
F 3 "" H 7100 4100 50  0001 C CNN
	1    7100 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4200 7100 4200
Wire Wire Line
	7100 4200 7100 4100
Wire Wire Line
	6900 4100 7100 4100
Connection ~ 7100 4100
Wire Wire Line
	7750 4300 7500 4300
Wire Wire Line
	7200 4300 6900 4300
$Comp
L Device:C C4
U 1 1 61E81814
P 7400 4100
F 0 "C4" V 7300 4200 50  0000 L CNN
F 1 "100n" V 7350 3850 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7438 3950 50  0001 C CNN
F 3 "~" H 7400 4100 50  0001 C CNN
	1    7400 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 4100 7100 4100
Wire Wire Line
	7550 4100 7750 4100
$Comp
L power:GND #PWR0116
U 1 1 61E9061A
P 5350 2250
F 0 "#PWR0116" H 5350 2000 50  0001 C CNN
F 1 "GND" V 5355 2122 50  0000 R CNN
F 2 "" H 5350 2250 50  0001 C CNN
F 3 "" H 5350 2250 50  0001 C CNN
	1    5350 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 61E90D68
P 5350 2350
F 0 "#PWR0117" H 5350 2100 50  0001 C CNN
F 1 "GND" V 5355 2222 50  0000 R CNN
F 2 "" H 5350 2350 50  0001 C CNN
F 3 "" H 5350 2350 50  0001 C CNN
	1    5350 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 2250 5350 2250
Wire Wire Line
	5350 2350 5600 2350
NoConn ~ 6900 2350
NoConn ~ 6900 2450
$Comp
L power:VCC #PWR0120
U 1 1 61D2486A
P 9300 6150
F 0 "#PWR0120" H 9300 6000 50  0001 C CNN
F 1 "VCC" V 9300 6400 50  0000 C CNN
F 2 "" H 9300 6150 50  0001 C CNN
F 3 "" H 9300 6150 50  0001 C CNN
	1    9300 6150
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0121
U 1 1 61D29B56
P 8900 6150
F 0 "#PWR0121" H 8900 6000 50  0001 C CNN
F 1 "+3V3" V 8915 6278 50  0000 L CNN
F 2 "" H 8900 6150 50  0001 C CNN
F 3 "" H 8900 6150 50  0001 C CNN
	1    8900 6150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8900 6150 9300 6150
Text Notes 8550 5950 0    50   ~ 0
Connect the VCC (Output level for HUB75)\nto the 3V3 from the PMod Connector 
$Comp
L power:GND #PWR?
U 1 1 61D511B2
P 10300 4100
F 0 "#PWR?" H 10300 3850 50  0001 C CNN
F 1 "GND" V 10305 3972 50  0000 R CNN
F 2 "" H 10300 4100 50  0001 C CNN
F 3 "" H 10300 4100 50  0001 C CNN
	1    10300 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61D511B8
P 10300 3500
F 0 "#PWR?" H 10300 3250 50  0001 C CNN
F 1 "GND" V 10305 3372 50  0000 R CNN
F 2 "" H 10300 3500 50  0001 C CNN
F 3 "" H 10300 3500 50  0001 C CNN
	1    10300 3500
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
