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

const int I2C_SDA = 16;
const int I2C_SCL = 17;
const int PIN_TX = 9;
const int PIN_LED0 = 22;
const int PIN_LED1 = 23;

const int POS_LOOKUP[] = {7,15,23,31,39,47,55,63,
												6,14,22,30,38,46,54,62,
												5,13,21,29,37,45,53,61,
												4,12,20,28,36,44,52,60,
												3,11,19,27,35,43,51,59,
												2,10,18,26,34,42,50,58,
												1, 9,17,25,33,41,49,57,
												0, 8,16,24,32,40,48,56};

int main() {
    //set_sys_clock_48();
		stdio_init_all();

		// Neopixel setup
		PIO pio = pio0;
		int sm = 0;

		uint offset = pio_add_program(pio, &ws2812_program);
		ws2812_program_init(pio, sm, offset, PIN_TX, 800000, false);

		// This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
		i2c_init(i2c0, 1000000);

		//Setup the I2C pins
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

		int16_t result[64];

		while(1) {
			sleep_ms(50);

			on_off = !on_off;
			gpio_put(PIN_LED0, on_off);

			int addr = 0b01101000;
			//int addr = 0x69;
			int ret;
			uint8_t rxdata[2];
			uint8_t val = 0x80;

			//read the therminster
			//val = 0x0E;
			//i2c_write_blocking(i2c1, addr, &val, 1, true);
			//ret = i2c_read_blocking(i2c1, addr, &rxdata[0], 2, true);
			//float thermist  = 0.0625 * ((int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4);
			//printf("Therm: %6.2f\n", thermist);

			//read the pixel values
			val = 0x80;
			i2c_write_blocking(i2c0, addr, &val, 1, true);

			for(int i = 0; i<64;++i){
				ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, true);
				result[i]  = (int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4;
				printf("%6.2f, ", 0.25*result[i]);
			}
			printf("/n");
			ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, false);
			//printf("%6.2f \n ", 0.25*(((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0])));
			//float result  = (int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4;

			gpio_put(PIN_LED1, 1);

			for (int i = 0; i < (64); i++) {
				//int8_t value = *((uint8_t*)&(result[i])+1
				//int8_t value = ((uint16_t)result[i]) >> 4;
				//put_pixel(urgb_u32(255-value,0,0));
				float value = result[i]*0.25;
				if(value>50){
					put_pixel(urgb_u32(128*(value-50)/50,0,0));}
				else if(value>30) {
						put_pixel(urgb_u32(128+(64*(value-30)/20),128+(64*(value-30)/20),0));}
				else if(value>20) {
						put_pixel(urgb_u32(0,32+(32*(value-10)/10),0));}
				else{
					put_pixel(urgb_u32(0,0,64+(128*(value+20)/40)));}
			}

			sleep_ms(100);

			gpio_put(PIN_LED1, 0);
		}

}
