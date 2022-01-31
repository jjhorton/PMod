from matplotlib import image
import numpy as np

from matplotlib import pyplot

# load the image
data = image.imread('test_image.jpg')

#data = np.asarray(image)

print(data.size)
print(data[0].size)
print(data[0][0].size)

#pyplot.imshow(data[:,:,0])
#pyplot.show()

f = open("mountains_128x64_rgb565.h", "w")

f.write("static char __attribute__((aligned(4))) mountains_128x64[] = {\n")

MASK5 = 0b011111
MASK6 = 0b111111

for x in range(64):
	for y in range(128):
		r = data[x,y,0]
		g = data[x,y,1]
		b = data[x,y,2]

		print(bin(int(r & 0b11111000)))
		print(bin(int(g & 0b11111100)))
		print(bin(int(b & 0b11111000)))

		d2 = (int(r & 0b11111000)) | (int(g & 0b11100000) >> 5)
		d1 = (int(g & 0b00011100) << 3) | (int(b & 0b11111000) >> 3)

		#d1 = (int(r & 0b11111000))
		#d2 = (int(b & 0b11111000) >> 3)

		print(bin(d1))
		print(bin(d2))
		#d1 = ((int((2^5)*data[x,y,0]/256) & MASK5))
		#d2 = (int((2^5)*data[x,y,2]/256) & MASK5)

		#d1 = data[x,y,0]
		#d2 = 0

		#f.write("0x%0.2X, 0x%0.2X, 0x%0.2X, " % (data[x,y,0],data[x,y,1], data[x,y,2]))

		print("0x%0.2X, 0x%0.2X, " % (d1,d2))
		my_str = "0x%0.2X, 0x%0.2X, " % (d1,d2)

		#f.write("0x%0.2X, 0x%0.2X, " % (d1,d2))
		f.write(my_str.lower())

		if ( ((y+1) %8) ==0 ) :
			f.write("\n")


f.write("};")

f.close()
