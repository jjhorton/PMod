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

	uint8_t output;

	while(1) {


		printf("%x \n", Display.get_id());

		Display.enable();
		Display.set_current(0xFF);

		printf("Current: %x \n", Display.get_current());

		Display.set_scaling();
		Display.get_id();


		for(int x=0; x<351; x++){
			uint8_t rgb_value[3];
			rgb_value[0]= 0x00;
			rgb_value[1]= 0x00;
			rgb_value[2]= 0x00;
			Display.set_LED(x,rgb_value);
		}

		uint8_t rgb_value[3];
		rgb_value[0]= 0x18;
		rgb_value[1]= 0xD5;
		rgb_value[2]= 0xC8;

		for(int counter=0; counter<10; counter++){
			
				for(int x=0; x<8; x++ ){
					u_int8_t rgb_value[3];
					rgb_value[0]= 0x00;
					rgb_value[1]= 0x00;
					rgb_value[2]= 0x00;
					if (Led_digit[counter][x] == 1 ){
						rgb_value[0]= 0x18;
						rgb_value[1]= 0xD5;
						rgb_value[2]= 0xC8;
					}
					Display.set_segment(0,x,rgb_value);
					
				}
		

			//Display.set_digit(0,counter,rgb_value);
			sleep_ms(5000);
		}
	
		/*
		for(int y=0; y<2; y++){

			for(int counter=0; counter<10; counter++){
				uint8_t rgb_value[3];
				rgb_value[0]= 0x18;
				rgb_value[1]= 0xD5;
				rgb_value[2]= 0xC8;
				
				Display.set_digit(y,counter,rgb_value);
				sleep_ms(100);
			}

		}
		*/

/*			//set a given segment to be on
			for(int counter=0; counter<10; counter++){
				/*
				for(int x=0; x<8; x++ ){
					u_int8_t rgb_value[3];
					rgb_value[0]= 0x00;
					rgb_value[1]= 0x00;
					rgb_value[2]= 0x00;
					if (Led_digit[counter][x] == 1 ){
						rgb_value[0]= 0x18;
						rgb_value[1]= 0xD5;
						rgb_value[2]= 0xC8;
					}
					Display.set_segment(y,x,rgb_value);
					
				}
			
				
				u_int8_t rgb_value[3];
				rgb_value[0]= 0x18;
				rgb_value[1]= 0xD5;
				rgb_value[2]= 0xC8;
				
				Display.set_digit(y,counter,rgb_value);
				
				sleep_ms(1000);

			}
		}
*/		

	}
  return 0;

}
