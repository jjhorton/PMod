# GPS examples


# Thruwire 
The thruwire example used the FPGA to simply route the serial signals between the GPS module and the USB. The Timepulse signal is used to control the red LED on the icebreaker board.

The command to see the GPS message from the GPS module the following command can be used with the serial port replaced with the following command. The standard baud rate is 9600. 

```bash
screen /dev/tty.usbserial-ib2u9O9Z1 9600  
```

## Clock test

The purpose of this example is to compare the 1pps and the accuracey of the on-board clock on the devboard

