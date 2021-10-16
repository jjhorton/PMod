/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "MyLedDisp.h"

#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "pico/stdlib.h"

int main() {

	stdio_init_all();

	//I2C setup for the thermal array
	i2c_init(i2c0, 1000000);
	gpio_set_function(0, GPIO_FUNC_I2C);
	gpio_set_function(1, GPIO_FUNC_I2C);
	gpio_pull_up(0);
	gpio_pull_up(1);
	bi_decl(bi_2pins_with_func(0, 1, GPIO_FUNC_I2C));
	//int addr = 0b01101000;
	float result[64];
	int ret;

	//initalise the displays
	MyLedDisp Display1(16,18);
	MyLedDisp Display2(20,22);
	Display1.enable();
	Display2.enable();

	uint8_t display_buff[16];

	for(uint8_t pos = 0; pos<16; pos++){
		display_buff[pos] = 0b00000000;
	}

	Display1.setDisplay(display_buff);
	Display2.setDisplay(display_buff);

	// values for averageing
	int ref_idx[16];
	int ref_rem[16];

	int counter = 0;

	while(1){

		// read in the values from the tempurature array
		uint8_t rxdata[2];
		int addr = 0b01101000;
		uint8_t val = 0x80;
		i2c_write_blocking(i2c0, addr, &val, 1, true);
		for(int i = 0; i<63;++i){
			uint8_t rxdata[2];
			ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, true);
			result[i]  = (float) 0.25*((int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4);
			if(i%8 == 0){
				printf("\n");
			}
			printf("%i %6.2f ", i, rxdata[1]);
		}

		//find the maximum values
		uint8_t  max_i = 0;
		float max_value = 0;

		for(uint8_t  i = 0; i<63;++i){
			if(result[i] > max_value){
					max_i = i; max_value = result[i];
			}
		}
		printf("\nTherm: %6.2f\n", max_i);

		// set the display buffer to zeros
		for(int i = 0; i<16;++i){
			display_buff[i] = 0b00000000;
		}

		ref_idx[counter] = max_i%8;
		ref_rem[counter] = max_i/8;

		int avg_idx=0; int avg_rem=0;
		//int ref_idx = 0; int ref_rem = 1;


		for(int i = 0; i<16;++i){
			avg_idx=(avg_idx+ref_idx[i]);
			avg_rem=(avg_rem+ref_rem[i]);
		}

		avg_idx=int8_t(avg_idx>>4);
		avg_rem=int8_t(avg_rem>>4);
		printf("Counter: %6i\n", avg_idx);
		/*
		avg_rem=avg_rem/16;
		*/
		//avg_idx=ref_idx[counter];
		//avg_rem=ref_rem[counter];

		printf("Counter: %6i\n", counter);
		counter++;
		if (counter>15){counter=0;}

		display_buff[avg_idx+8] = (0b00000011 << (int)(avg_rem));
		display_buff[avg_idx+1+8] = (0b00000011 << (int)(avg_rem));


	  Display1.setDisplay(display_buff);
		Display2.setDisplay(display_buff);

		sleep_ms(50);

	}

}
