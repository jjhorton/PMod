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



for a in range(2000):
    data = stream.read(CHUNK)
    values = np.frombuffer(data, np.int16)
    values = values - np.mean(values)
    #freq_amp = np.log2(np.abs(np.fft.fftshift(np.fft.fft(values)))[512:512+15])
    freq_amp = np.log2(np.abs(np.fft.fftshift(np.fft.fft(values,32))))[16:32]
    upscale = np.divide(8,np.max(freq_amp))
    in_scaled = freq_amp*upscale
    tx_amp = np.power(2,np.array(in_scaled, dtype=np.int8))-1

    ser.write(b'A')
    ser.write(bytes(tx_amp))


plt.subplot(2,1,1)
plt.plot(values)
plt.subplot(2,1,2)
plt.plot(tx_amp)
#plt.xlim(512,512+16)
plt.show()

