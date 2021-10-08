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

	//LedDisp Display1A(16,18);
	//LedDisp Display1B(8,10);
	MyLedDisp Display2(0,2);

	uint8_t display[16];


	//Display1A.enable();
	//Display1B.enable();
	Display2.enable();

	while(1){

		for(int value=0; value<16; ++value){
			//for(int i = 0; i<16; ++i){
				Display2.setdigit(value, rand() % 10, true);
			//}
		}
		//Display1A.setValue2(double(987.6), double(123.4),1);
		//Display1B.setValue(double(1234.5678), 4);

		sleep_ms(1000);

	}

}
