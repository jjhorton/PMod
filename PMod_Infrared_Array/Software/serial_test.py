import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate

import serial

ser = serial.Serial('/dev/tty.usbmodem0000000000001', 115200 ,timeout=1)
#ser.reset_input_buffer()

my_result = np.zeros([8,8],dtype=np.float32)
my_counter = 0

mymin,mymax = 1,8
X = np.linspace(mymin,mymax,8)
Y = np.linspace(mymin,mymax,8)
x,y = np.meshgrid(X,Y)

mult_by = 16

Xnew = np.linspace(mymin,mymax,8*mult_by)
Ynew = np.linspace(mymin,mymax,8*mult_by)

f = interpolate.interp2d(x,y,my_result ,kind='linear')
my_display = f(Xnew,Ynew)

fg = plt.figure()
ax = fg.gca()
h = ax.imshow(my_display, vmin=0, vmax=40,cmap=plt.get_cmap('inferno'))
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
            if mult_by == 1:
                my_display = my_result
            else:
                #f = interpolate.interp2d(x,y,my_result ,kind='linear')
                f = interpolate.RectBivariateSpline(X,Y,my_result)
                my_display = f(Xnew,Ynew)

            h.set_data(np.fliplr(np.flip(my_display)))
            plt.draw(), plt.pause(1e-4)
            print(my_result)
            print(my_result.dtype)

    else:
        my_counter = 0
    #my_values = csv.reader(my_data, delimiter=',')
    #print(my_values.split(","))
    #list(my_values)
