import numpy as np
import matplotlib.pyplot as plt

import serial

ser = serial.Serial('/dev/tty.usbmodem0000000000001', 115200 ,timeout=1)
#ser.reset_input_buffer()

my_result = np.zeros([8,8],dtype=np.float32)
my_counter = 0

fg = plt.figure()
ax = fg.gca()
h = ax.imshow(my_result, vmin=0, vmax=40,cmap=plt.get_cmap('inferno'))
plt.colorbar(h)

while(1):
    my_data = ser.readline()

    if len(my_data) > 20:
        if str(my_data)[-7] == ',':
            my_string = str(my_data)[3:-7]
        else:
            my_string = str(my_data)[3:-6]

        my_result[my_counter,0:8] = np.asarray(my_string.split(","),dtype=np.float32)
        my_counter = my_counter + 1

        if my_counter > 7:
            h.set_data(np.fliplr(np.flip(my_result)))
            plt.draw(), plt.pause(1e-3)
            print(my_result)
            print(my_result.dtype)

    else:
        my_counter = 0
    #my_values = csv.reader(my_data, delimiter=',')
    #print(my_values.split(","))
    #list(my_values)
