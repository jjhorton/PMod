# Firmware example for LED Array 

This is an example that runs on the iceSugar Pro and iceBreaker FPGA development boards, and the PMod LED Array board. 

# Building and running 

To run the whole module though the verilator test, which will produce a VCD file output run, this is tested with verilator 5.006.

```
Make Test
```

To Build the FPGA image for the iceSugar Pro Development board using Yosys and Next-pnr use the following command
```
Make build-ecp5 
```

Assuming the full toolset is install it is also possible to program the ECP from the Makefile
```
make prog-ecp5
```

The data is sent over the serial link to the board to be disabled, an example can be found here in the repo, but may require some modification:
```
python3 Audio_data.py
```

# Github actions
As part of the Github Actions that run on this repo, the FPGA image for both the ECP5 and iceBreaker are automatically created. 

[![PMod LED Array](https://github.com/jjhorton/PMod/actions/workflows/LedArray.yml/badge.svg)](https://github.com/jjhorton/PMod/actions/workflows/LedArray.yml)
