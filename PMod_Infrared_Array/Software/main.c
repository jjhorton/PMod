/**
 * Copyright (c) 2021 James Horton
 *
 *	Simple example for working with the AMG 8834 sesnor
 *
 */


#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"


int main() {
    // Enable UART so we can print status output
    stdio_init_all();
    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c0, 1000000);

		//Setup the I2C pins
		gpio_set_function(16, GPIO_FUNC_I2C);
    gpio_set_function(17, GPIO_FUNC_I2C);
    gpio_pull_up(16);
    gpio_pull_up(17);

    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(16, 17, GPIO_FUNC_I2C));

		//setup the pins for the flashing status LED
		int8_t on_off = 0;
		gpio_init(22);
		gpio_set_dir(22, GPIO_OUT);

		while(1) {
			sleep_ms(50);

			on_off = !on_off;
			gpio_put(22, on_off);

    	int addr = 0b01101000;
			//int addr = 0x69;
			int ret;
			uint8_t rxdata[2];
			uint8_t val = 0x80;

			//read the therminster
			val = 0x0E;
			i2c_write_blocking(i2c0, addr, &val, 1, true);
			ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, true);
			float thermist  = 0.0625 * ((int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4);

			printf("Therm: %6.2f\n", thermist);

			//read the pixel values
			val = 0x80;
			i2c_write_blocking(i2c0, addr, &val, 1, true);

			for(int i = 0; i<63;++i){
				ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, true);
				if(i%8 == 0){
					printf("\n");
				}
				float result  = (int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4;
				printf("%6.2f, ", 0.25*result);
			}
			ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, false);
			//printf("%6.2f \n ", 0.25*(((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0])));
			float result  = (int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4;
			printf("%6.2f \n", 0.25*result);
		}
  return 0;

}
