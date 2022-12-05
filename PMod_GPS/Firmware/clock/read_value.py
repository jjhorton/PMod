import serial
import numpy as np
import matplotlib.pyplot as plt

ser = serial.Serial('/dev/ttyUSB1', 115200 ,timeout=0.25)
data_store = []

plt.ion()

fig = plt.figure()
ax = fig.add_subplot(111)
line1, = ax.plot(np.arange(-128,128,1), np.zeros(256), 'r-')
ax.axis([ -128, 127,0,1])
#h = ax.hist(np.zeros(16), bins=16, range=(-127,128))


while(1):
    my_data = ser.readline()

    for i in range(0,len(my_data)):
        if (my_data[i] > 128):
            value = my_data[i] - 256
        else:
            value = my_data[i]

        data_store.append(value)

        print("num: ", i, " value: ", value)

        print("mean error", np.mean(np.array(data_store)))

        if (len(data_store)>1):
            counts, bins = np.histogram(np.array(data_store), bins=256, range=(-128,127))
            print(counts)

            line1.set_ydata(counts/len(data_store))
            fig.canvas.draw()
            fig.canvas.flush_events()