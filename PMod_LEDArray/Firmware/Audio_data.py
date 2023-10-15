import pyaudio
import matplotlib.pyplot as plt
import numpy as np
import wave
import time
import serial
import io

ser = serial.Serial('/dev/tty.usbmodem1102', 115200 ,timeout=0.25)

CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100
RECORD_SECONDS = 5

p = pyaudio.PyAudio()

stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                input=True,
                frames_per_buffer=CHUNK)

print("* recording")

largest = np.zeros(2000)

for a in range(0,2000):
    data = stream.read(CHUNK)
    values = np.frombuffer(data, np.int16)
    values = values - np.mean(values)
    largest[a] = np.max(values)
    freq_amp = np.log2(np.abs(np.fft.fftshift(np.fft.fft(values,32))))[16:32]
    upscale = 1
    in_scaled = (freq_amp*upscale)-4
    tx_amp = np.power(2,np.abs(np.array(in_scaled, dtype=np.int8)))-1

    ser.write(b'A')
    ser.write(bytes(tx_amp))

    # Testing random values
    #ser.write(bytes(np.random.randint(-127,128,size=16, dtype=np.int8)))
    #time.sleep(0.1)

print(np.max(largest))

plt.subplot(3,1,1)
plt.plot(values)
plt.subplot(3,1,2)
plt.plot(tx_amp)
plt.subplot(3,1,3)
plt.plot(freq_amp)
#plt.xlim(512,512+16)
plt.show()

