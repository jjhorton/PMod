/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "ws2812.pio.h"

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

// Output pins to match RP2040 PMod Board
// - PMOOD1A AMG8833 Thermal Camera PMOD
// - PMOOD1B Neopixel Array Board (8x8)

const int I2C_SDA = 16;
const int I2C_SCL = 17;
const int PIN_TX = 9;
const int PIN_LED0 = 22;
const int PIN_LED1 = 23;

const int BRIGHTNESS = 8;

// position lookup table to map the positions rotated 90 degrees
const int POS_LOOKUP[] = {0, 8,16,24,32,40,48,56,
												1, 9,17,25,33,41,49,57,
												2,10,18,26,34,42,50,58,
												3,11,19,27,35,43,51,59,
												4,12,20,28,36,44,52,60,
												5,13,21,29,37,45,53,61,
												6,14,22,30,38,46,54,62,
												7,15,23,31,39,47,55,63};

// Lookup table the colourmap
const int RGB_LOOKUP[][3] = {{255,14,240},{255,13,240},{255,12,240},{255,11,240},
														{255,10,240},{255,9,240},{255,8,240},{255,7,240},
														{255,6,240},{255,5,240},{255,4,240},{255,3,240},
														{255,2,240},{255,1,240},{255,0,240},{255,0,224},
														{255,0,208},{255,0,192},{255,0,176},{255,0,160},
														{255,0,144},{255,0,128},{255,0,112},{255,0,96 },
														{255,0,80 },{255,0,64 },{255,0,48 },{255,0,32 },
														{255,0,16 },{255,0,0  },{255,10,0 },{255,20,0 },
														{255,30,0 },{255,40,0 },{255,50,0 },{255,60,0 },
														{255,70,0 },{255,80,0 },{255,90,0 },{255,100,0},
														{255,110,0},{255,120,0},{255,130,0},{255,140,0},
														{255,150,0},{255,160,0},{255,170,0},{255,180,0},
														{255,190,0},{255,200,0},{255,210,0},{255,220,0},
														{255,230,0},{255,240,0},{255,250,0},{253,255,0},
														{215,255,0},{176,255,0},{138,255,0},{101,255,0},
														{62,255,0 },{23,255,0 },{0,255,16 },{0,255,54 },
														{0,255,92 },{0,255,131},{0,255,168},{0,255,208},
														{0,255,244},{0,228,255},{0,212,255},{0,196,255},
														{0,180,255},{0,164,255},{0,148,255},{0,132,255},
														{0,116,255},{0,100,255},{0,84,255 },{0,68,255 },
														{0,50,255 },{0,34,255 },{0,18,255 },{0,2,255  },
														{0,0,255  },{1,0,255  },{2,0,255  },{3,0,255  },
														{4,0,255  },{5,0,255 }};

int main() {
    //set_sys_clock_48();
		stdio_init_all();

		// Neopixel setup with pio
		PIO pio = pio0;
		int sm = 0;

		uint offset = pio_add_program(pio, &ws2812_program);
		ws2812_program_init(pio, sm, offset, PIN_TX, 800000, false);

		// This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
		i2c_init(i2c0, 1000000);

		//Setup the I2C pins for camera
		gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
		gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
		gpio_pull_up(I2C_SDA);
		gpio_pull_up(I2C_SCL);

		// Make the I2C pins available to picotool
		bi_decl(bi_2pins_with_func(I2C_SDA, I2C_SCL, GPIO_FUNC_I2C));

		//setup the pins for the flashing status LED
		int8_t on_off = 0;
		gpio_init(PIN_LED0);
		gpio_set_dir(PIN_LED0, GPIO_OUT);

		gpio_init(PIN_LED1);
		gpio_set_dir(PIN_LED1, GPIO_OUT);

		// array to store a frame of values from the camera
		int16_t result[64];

		//main loop, shouldn't exit this
		while(1) {
			sleep_ms(50);

			on_off = !on_off;
			gpio_put(PIN_LED0, on_off);

			int addr = 0b01101000;

			int ret;
			uint8_t rxdata[2];
			uint8_t val = 0x80;

			//read the values from the thermal camera
			val = 0x80;
			i2c_write_blocking(i2c0, addr, &val, 1, true);

			for(int i = 0; i<64;++i){
				ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, true);
				result[i]  = (int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4;
				printf("%6.2f, ", 0.25*result[i]);
			}
			printf("/n");
			ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, false);

			// Write the values to the Neopixel Array
			for (int i = 0; i < (64); i++) {
				int value = 90 - (result[POS_LOOKUP[i]]*0.25);
				put_pixel(urgb_u32(RGB_LOOKUP[value][0]/BRIGHTNESS,RGB_LOOKUP[value][1]/BRIGHTNESS,RGB_LOOKUP[value][2]/BRIGHTNESS));
			}
			sleep_ms(100); //required delay at TX sequence


		}

}
