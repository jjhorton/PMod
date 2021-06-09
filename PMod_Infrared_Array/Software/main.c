/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Sweep through all 7-bit I2C addresses, to see if any slaves are present on
// the I2C bus. Print out a table that looks like this:
//
// I2C Bus Scan
//   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
// 0
// 1       @
// 2
// 3             @
// 4
// 5
// 6
// 7
//
// E.g. if slave addresses 0x12 and 0x34 were acknowledged.

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

// I2C reserves some addresses for special purposes. We exclude these from the scan.
// These are any addresses of the form 000 0xxx or 111 1xxx
bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int main() {
    // Enable UART so we can print status output
    stdio_init_all();
    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c1, 1000000);
    //gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    //gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    //gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    //gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
		gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);

    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(2, 3, GPIO_FUNC_I2C));

		int8_t on_off = 0;
		gpio_init(20);
		gpio_set_dir(20, GPIO_OUT);

		while(1) {
			sleep_ms(5000);

			on_off = !on_off;
			gpio_put(20, on_off);

    	int addr = 0b01101000;
			//int addr = 0x69;
			int ret;
			uint8_t rxdata[2];
			uint8_t val = 0x80;

			printf("-------------\n");

			i2c_write_blocking(i2c1, addr, &val, 1, true);

			for(int i = 0; i<63;++i){
				ret = i2c_read_blocking(i2c1, addr, &rxdata[0], 2, true);
				if(i%8 == 0){
					printf("\n");
				}
				printf("%6.2f, ", 0.25*(((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0])));
			}
			ret = i2c_read_blocking(i2c1, addr, &rxdata[0], 2, false);
			printf("%6.2f \n ", 0.25*(((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0])));
		}
  return 0;

}
