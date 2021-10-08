/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "My7Seg.h"

#include "pico/stdlib.h"

int main() {

	My7Seg Display1A(16,18);
	My7Seg Display1B(8,10);
	My7Seg Display2(0,2);

	Display1A.enable();
	Display1B.enable();
	Display2.enable();

	while(1){

		for(int value=0; value<16; ++value){
			//for(int i = 0; i<16; ++i){
				Display2.setdigit(value, rand() % 10, true);
			//}
		}
		Display1A.setValue2(double(987.6), double(123.4),1);
		Display1B.setValue(double(1234.5678), 4);

		sleep_ms(1000);

	}

}
