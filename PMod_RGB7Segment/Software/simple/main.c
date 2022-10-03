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


	gpio_init(18);
	gpio_set_dir(18, GPIO_OUT);
	gpio_put(18, 1);

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

    		int addr = 0x30;// 0b011000;
			int ret;
			uint8_t rxdata[2];
			uint8_t val[2];




			val[0] = 0xFC;
			i2c_write_blocking(i2c0, addr, &val[0], 1, true);
			i2c_read_blocking(i2c0, addr, &rxdata[0], 1, true);

			printf("Chip ID: ");
			printf("%x \n", rxdata[0]);

			//sleep_ms(10);

			//reset the chip
			val[0] = 0xFE;
			val[1] = 0xC5;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			val[0] = 0xFD;
			val[1] = 0x04;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			val[0] = 0x3F;
			val[1] = 0xAE;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);


			sleep_ms(100);


			// set global current
			//enable
			val[0] = 0xFE;
			val[1] = 0xC5; //unlock
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			// select page 4
			val[0] = 0xFD;
			val[1] = 0x04;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			// check the global current level
			rxdata[0] = 0;
			val[0] = 0x01;
			i2c_write_blocking(i2c0, addr, &val[0], 1, true);
			i2c_read_blocking(i2c0, addr, &rxdata[0], 1, true);
			printf("Global Current: Before ");
			printf("%x ", rxdata[0]);

			// set global current
			val[0] = 0x01;
			val[1] = 0xFF;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			// check the global current level
			rxdata[0] = 0;
			val[0] = 0x01;
			i2c_write_blocking(i2c0, addr, &val[0], 1, true);
			i2c_read_blocking(i2c0, addr, &rxdata[0], 1, true);
			printf("After: ");
			printf("%x \n", rxdata[0]);

			// select page 2
			val[0] = 0xFE;
			val[1] = 0xC5; //unlock
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			val[0] = 0xFD;
			val[1] = 0x02; //page 2
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			// set pwm for led 0
			for( int x = 0; x<0xB4; x++){
				val[0] = x;
				val[1] = 0xFF;

				i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			}

			// select page 2
			val[0] = 0xFE;
			val[1] = 0xC5; //unlock
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			val[0] = 0xFD;
			val[1] = 0x03; //page 2
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			// set pwm for led 0
			for( int x = 0; x<0xAB; x++){
				val[0] = x;
				val[1] = 0xFF;

				i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			}

			//Unlock
			val[0] = 0xFE;
			val[1] = 0xC5; //unlock
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			// select page 4
			val[0] = 0xFD;
			val[1] = 0x04;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			//set global condif to enable
			val[0] = 0x00;
			val[1] = 0x01;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

		


			// select page 0
			val[0] = 0xFE;
			val[1] = 0xC5; //unlock
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			val[0] = 0xFD;
			val[1] = 0x00;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			// set pwm for led 0
			for( int x = 1; x<0xAB; x=x+3){
				val[0] = x;
				val[1] = 0xFF;
				i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			}

			// select page 1
			val[0] = 0xFE;
			val[1] = 0xC5; //unlock
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);

			val[0] = 0xFD;
			val[1] = 0x01;
			i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			// set pwm for led 0
			for( int x = 1; x<0xAB; x=x+3){
				val[0] = x;
				val[1] = 0xFF;
				i2c_write_blocking(i2c0, addr, &val[0], 2, true);
			}

			printf("\n\n\n");
			sleep_ms(1000);

		}
  return 0;

}
