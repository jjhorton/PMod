# Building the Software

With the Pico SDK added to the path we can then build the hub75 using the standard workflow:

```
mkdir Build
cd Build
cmake ..
make
```

The resulting .u2f file can then be copied onto the RP2040 in the standard way, using the run and prog button so the RP2040 board appears as a usb drive, then the u2f file can then be copied.  

# Hookup information
Mapping of the pins between the PMod connectors on the RP2040 PMod Board and the HUB75 display pins

| RP2040 Pin | Pmod Connector | PMod Pin | Hub75 |
|------------|----------------|----------|-------|
| 22         | PMod1a         | 1        | NC    |
| 23         | PMod1a         | 2        | NC    |
| 20         | PMod1a         | 3        | LATCH |
| 21         | PMod1a         | 4        | OE    |
| 18         | PMod1a         | 5        | E     |
| 19         | PMod1a         | 6        | CLK   |
| 16         | PMod1a         | 7        | C     |
| 17         | PMod1a         | 8        | D     |
| 14         | PMod1b         | 1        | A     |
| 15         | PMod1b         | 2        | B     |
| 12         | PMod1b         | 3        | G1    |
| 13         | PMod1b         | 4        | B1    |
| 10         | PMod1b         | 5        | B0    |
| 11         | PMod1b         | 6        | R1    |
| 08         | PMod1b         | 7        | R0    |
| 09         | PMod1b         | 8        | G0    |
