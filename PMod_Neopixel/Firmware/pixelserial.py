import numpy as np
import time

import serial

def segments(data, size=1):
    for a in range(0, len(data), size):
        yield data[a:a + size]

ser = serial.Serial('/dev/tty.usbserial-ib2u9O9Z1',19200)

print(ser.name)
print(ser.baudrate)

#ser.write(b'z')
#time.sleep(1)
#ser.write(b'A')
#time.sleep(1)

x = bytes(bytearray(range(256)))


for count in segments(x):
	print(count)
	ser.write(0b00000000)
	ser.write(0b00000000)
	ser.write(count)

	time.sleep(0.1)

ser.close()


#ser = serial.Serial('/dev/tty.usbserial-ib2u9O9Z1',115200,timeout=1)

#ser.write(0b10000000)
#time.sleep(1)
#ser.write(0b00000000)

#ser.close()
