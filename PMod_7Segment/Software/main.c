/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

const int GM1640_CLK = 2;
const int  GM1640_DATA = 0;


void enable_display(){

	int command1[] = {1,1,1,1,0,0,0,1};

	gpio_put(GM1640_DATA,0);
	sleep_ms(0.2);
	gpio_put(GM1640_CLK,0);
	sleep_ms(0.2);

	for(int i=0; i < 8; ++i ){
		gpio_put(GM1640_DATA,command1[i]);
		sleep_ms(0.2);
		gpio_put(GM1640_CLK,1);
		sleep_ms(0.4);
		gpio_put(GM1640_CLK,0);
		sleep_ms(0.2);
	}

	gpio_put(GM1640_DATA,0);
	sleep_ms(0.2);
	gpio_put(GM1640_CLK,1);
	sleep_ms(0.2);
	gpio_put(GM1640_DATA,1);

}


void txData(){

	int addr[] = {0,0,0,0,0,0,1,1};
	int data[] = {0,0,0,0,0,0,0,1};

	gpio_put(GM1640_DATA,0);
	sleep_ms(0.2);
	gpio_put(GM1640_CLK,0);
	sleep_ms(0.2);

	for(int i=0; i < 8; ++i ){
		gpio_put(GM1640_DATA,addr[i]);
		sleep_ms(0.2);
		gpio_put(GM1640_CLK,1);
		sleep_ms(0.4);
		gpio_put(GM1640_CLK,0);
		sleep_ms(0.2);
	}

	for(int i=0 ; i < 8; ++i ){
		gpio_put(GM1640_DATA,data[i]);
		sleep_ms(0.2);
		gpio_put(GM1640_CLK,1);
		sleep_ms(0.4);
		gpio_put(GM1640_CLK,0);
		sleep_ms(0.2);
	}

	gpio_put(GM1640_DATA,0);
	sleep_ms(0.2);
	gpio_put(GM1640_CLK,1);
	sleep_ms(0.2);
	gpio_put(GM1640_DATA,1);


	return;
}


int main() {

	//setup the GPIO pins as OUTPUTS
	gpio_init(GM1640_CLK);
	gpio_set_dir(GM1640_CLK, GPIO_OUT);
	gpio_put(GM1640_CLK,1);

	gpio_init(GM1640_DATA);
	gpio_set_dir(GM1640_DATA, GPIO_OUT);
	gpio_put(GM1640_DATA,1);

	enable_display();
	sleep_ms(20);

	while(1){

		//gpio_put(GM1640_CLK,0);
		//sleep_ms(10);
		//gpio_put(GM1640_CLK,1);

		txData();
		sleep_ms(100);

	}

}
