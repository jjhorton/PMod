import serial
import io

ser = serial.Serial('/dev/tty.usbmodem1102', 115200 ,timeout=0.25)

ser.write(b'A')
ser.write(bytes([1,3,7,15,31,63,127,1,3,63,3,1,3,1,3,1]))
#for a in range(16):
    #ser.write(int.to_bytes(a,length=8, byteorder='little'))
#    ser.write(bytes(a))

ser.close()