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

#include "rgb7seg.h"


int main() {
    // Enable UART so we can print status output
    stdio_init_all();

	RGB7Seg Display;

	uint8_t value = 0;
	uint8_t output;

	while(1) {


		printf("%x \n", Display.get_id());

		Display.enable();
		Display.set_current(0xFF);

		printf("Current: %x \n", Display.get_current());

		Display.set_scaling();


		for(int y=0; y<22; y++)
		{
			for(int x=0; x<351; x++){
				if(x==y){
					u_int8_t rgb_value[3];
					rgb_value[0]= 0xFF;
					rgb_value[1]= 0x00;
					rgb_value[2]= 0xFF;
					Display.set_LED(x,rgb_value);
				}
				else{
					u_int8_t rgb_value[3];
					rgb_value[0]= 0x00;
					rgb_value[1]= 0x00;
					rgb_value[2]= 0x00;
					Display.set_LED(x,rgb_value);
				}
			}
			sleep_ms(100);
		}

		value = value*2;

	}
  return 0;

}
