# PMod boards
A selection of Random PMod Boards to be used with FPGA's that use the Digilent PMod standard connection

# Board Status
The boards in the table are being checked using github actions ![Kibot](https://github.com/INTI-CMNB/KiBot) for the KiCAD files and also building the example code for each one online. The fabrication files produced using Gitfub actions also includes a PDF of the schematic and GERBER files for getting PCB's built using ![JLCPCB](https://jlcpcb.com).

| Board | Build Status | Description |
| --- | --- |
| PMod CC1101 | Work in progress | sub-1GHz Transceiver board based on a CC1101 |
| PMod LED |   | Contains 8 LED's which can be individually turned on and off |
| PMod NeoPixel | [![PMod NeoPixel](https://github.com/jjhorton/PMod/actions/workflows/neopixel.yml/badge.svg)](https://github.com/jjhorton/PMod/actions/workflows/neopixel.yml) | A board with 10 WS2812 RGB LED's |
| PMod Infrared Array | [![PMod Infrared Array](https://github.com/jjhorton/PMod/actions/workflows/infrared_array.yml/badge.svg)](https://github.com/jjhorton/PMod/actions/workflows/infrared_array.yml) | contains an 8x8 IR Thermal sensor |
