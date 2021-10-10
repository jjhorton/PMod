/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "MyLedDisp.h"

#include "pico/stdlib.h"

int main() {


	MyLedDisp Display2(0,2);
	Display2.enable();

	uint8_t display_buff[16];

	for(uint8_t pos = 0; pos<16; pos++){
		display_buff[pos] = 0b00000000;
	}

	display_buff[0] = 0b10000010;
	display_buff[1] = 0b10000001;
	display_buff[2] = 0b11111110;
	display_buff[3] = 0b10000000;
	display_buff[4] = 0b00000000;
	display_buff[5] = 0b10000010;
	display_buff[6] = 0b10000001;
	display_buff[7] = 0b11111110;
	display_buff[8] = 0b10000000;
	display_buff[9] = 0b00000000;
	display_buff[10] = 0b11111111;
	display_buff[11] = 0b00001000;
	display_buff[12] = 0b00001000;
	display_buff[13] = 0b11111111;

	while(1){

		for(uint8_t pos = 0; pos<16; pos++){
			//display_buff[pos] =
			//display_buff[pos] <<= 1;
		}

	  Display2.setDisplay(display_buff);

		sleep_ms(1000);

	}

}
