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
L JJH_Library:SN74LVC8T245DWR IC?
U 1 1 61C3820F
P 5600 2050
F 0 "IC?" H 6250 2315 50  0000 C CNN
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
L JJH_Library:SN74LVC8T245DWR IC?
U 1 1 61C3989E
P 5600 4100
F 0 "IC?" H 6250 4365 50  0000 C CNN
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
L Connector_Generic:Conn_02x06_Counter_Clockwise J?
U 1 1 61C3C515
P 2200 2600
F 0 "J?" H 2250 3017 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 2250 2926 50  0000 C CNN
F 2 "" H 2200 2600 50  0001 C CNN
F 3 "~" H 2200 2600 50  0001 C CNN
	1    2200 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x06_Counter_Clockwise J?
U 1 1 61C3D51F
P 2250 4700
F 0 "J?" H 2300 5117 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 2300 5026 50  0000 C CNN
F 2 "" H 2250 4700 50  0001 C CNN
F 3 "~" H 2250 4700 50  0001 C CNN
	1    2250 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Counter_Clockwise J?
U 1 1 61C3F404
P 9000 3700
F 0 "J?" H 9050 4217 50  0000 C CNN
F 1 "Conn_02x08_Counter_Clockwise" H 9050 4126 50  0000 C CNN
F 2 "" H 9000 3700 50  0001 C CNN
F 3 "~" H 9000 3700 50  0001 C CNN
	1    9000 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61C461D7
P 2800 5350
F 0 "#PWR?" H 2800 5100 50  0001 C CNN
F 1 "GND" H 2805 5177 50  0000 C CNN
F 2 "" H 2800 5350 50  0001 C CNN
F 3 "" H 2800 5350 50  0001 C CNN
	1    2800 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 61C48293
P 2250 1800
F 0 "#PWR?" H 2250 1650 50  0001 C CNN
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
L power:GND #PWR?
U 1 1 61C4EF48
P 1600 5300
F 0 "#PWR?" H 1600 5050 50  0001 C CNN
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
L power:GND #PWR?
U 1 1 61C55D53
P 6250 3300
F 0 "#PWR?" H 6250 3050 50  0001 C CNN
F 1 "GND" H 6255 3127 50  0000 C CNN
F 2 "" H 6250 3300 50  0001 C CNN
F 3 "" H 6250 3300 50  0001 C CNN
	1    6250 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61C5A127
P 6250 5400
F 0 "#PWR?" H 6250 5150 50  0001 C CNN
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
	8500 3400 8800 3400
Text GLabel 8500 3400 0    50   Input ~ 0
Out_R0
Text GLabel 8500 3500 0    50   Input ~ 0
Out_B0
Wire Wire Line
	8800 3500 8500 3500
Text GLabel 8500 3600 0    50   Input ~ 0
Out_R1
Text GLabel 8500 3700 0    50   Input ~ 0
Out_B1
Text GLabel 8500 3800 0    50   Input ~ 0
Out_A0
Text GLabel 8500 3900 0    50   Input ~ 0
Out_A2
Text GLabel 8500 4000 0    50   Input ~ 0
Out_CLK
Text GLabel 8500 4100 0    50   Input ~ 0
Out_OE
Text GLabel 9700 4100 2    50   Input ~ 0
Out_GND
Text GLabel 9700 4000 2    50   Input ~ 0
Out_Latch
Text GLabel 9700 3900 2    50   Input ~ 0
Out_A3
Text GLabel 9700 3800 2    50   Input ~ 0
Out_A1
Text GLabel 9700 3700 2    50   Input ~ 0
Out_A4
Text GLabel 9700 3600 2    50   Input ~ 0
Out_G1
Text GLabel 9700 3500 2    50   Input ~ 0
Out_GND
Text GLabel 9700 3400 2    50   Input ~ 0
Out_G0
Wire Wire Line
	8800 3600 8500 3600
Wire Wire Line
	8500 3700 8800 3700
Wire Wire Line
	8800 3800 8500 3800
Wire Wire Line
	8500 3900 8800 3900
Wire Wire Line
	8800 4000 8500 4000
Wire Wire Line
	8500 4100 8800 4100
Wire Wire Line
	9300 4100 9700 4100
Wire Wire Line
	9300 4000 9700 4000
Wire Wire Line
	9700 3900 9300 3900
Wire Wire Line
	9300 3800 9700 3800
Wire Wire Line
	9300 3700 9700 3700
Wire Wire Line
	9700 3600 9300 3600
Wire Wire Line
	9300 3500 9700 3500
Wire Wire Line
	9300 3400 9700 3400
Text GLabel 7300 4550 2    50   Input ~ 0
Out_R0
Text GLabel 7300 4450 2    50   Input ~ 0
Out_B0
Text GLabel 7300 4350 2    50   Input ~ 0
Out_R1
Text GLabel 7300 4250 2    50   Input ~ 0
Out_B1
Text GLabel 7300 4150 2    50   Input ~ 0
Out_A0
Text GLabel 7300 4050 2    50   Input ~ 0
Out_A1
Text GLabel 7300 3950 2    50   Input ~ 0
Out_CLK
Text GLabel 7300 3850 2    50   Input ~ 0
Out_OE
Text GLabel 7300 3750 2    50   Input ~ 0
Out_GND
Text GLabel 7300 3650 2    50   Input ~ 0
Out_Latch
Text GLabel 7300 3550 2    50   Input ~ 0
Out_A3
Text GLabel 7300 3450 2    50   Input ~ 0
Out_A2
Text GLabel 7300 3350 2    50   Input ~ 0
Out_A4
Text GLabel 7300 3250 2    50   Input ~ 0
Out_G1
Text GLabel 7300 3150 2    50   Input ~ 0
Out_GND
Text GLabel 7300 3050 2    50   Input ~ 0
Out_G0
Text GLabel 4500 2550 0    50   Input ~ 0
Out_R0
Text GLabel 4500 2750 0    50   Input ~ 0
Out_B0
Text GLabel 4500 2900 0    50   Input ~ 0
Out_R1
Text GLabel 4500 3100 0    50   Input ~ 0
Out_B1
Text GLabel 4500 3400 0    50   Input ~ 0
Out_A0
Text GLabel 4500 3500 0    50   Input ~ 0
Out_A1
Text GLabel 4500 4100 0    50   Input ~ 0
Out_CLK
Text GLabel 4500 4000 0    50   Input ~ 0
Out_OE
Text GLabel 4500 4400 0    50   Input ~ 0
Out_GND
Text GLabel 4500 3700 0    50   Input ~ 0
Out_A3
Text GLabel 4500 3600 0    50   Input ~ 0
Out_A2
Text GLabel 4500 3800 0    50   Input ~ 0
Out_A4
Text GLabel 4500 3000 0    50   Input ~ 0
Out_G1
Text GLabel 4500 2650 0    50   Input ~ 0
Out_G0
$EndSCHEMATC
