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


void txData(uint8_t pos, uint8_t data){

	//int addr[] = {0,0,0,0,0,0,1,1};
	uint8_t addr = 0b11000000 + pos;
	//uint8_t data = 0b00000001;

	gpio_put(GM1640_DATA,0);
	sleep_ms(0.2);
	gpio_put(GM1640_CLK,0);
	sleep_ms(0.2);

	for(int i=0; i < 8; ++i ){
		gpio_put(GM1640_DATA,(addr >> i) & 1U);
		sleep_ms(0.2);
		gpio_put(GM1640_CLK,1);
		sleep_ms(0.4);
		gpio_put(GM1640_CLK,0);
		sleep_ms(0.2);
	}

	for(int i=0 ; i < 8; ++i ){
		gpio_put(GM1640_DATA,(data >> i) & 1U);
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

void setdigit(uint8_t pos, uint8_t value){

	uint8_t output = 0b00000000;

	switch(value){
		case 0:
			output = 0b00111111;
			break;
		case 1:
			output = 0b00000110;
			break;
		case 2:
			output = 0b01011011;
			break;
		case 3:
			output = 0b01001111;
			break;
		case 4:
			output = 0b01100110;
			break;
		case 5:
			output = 0b01101101;
			break;
		case 6:
			output = 0b01111101;
			break;
		case 7:
			output = 0b00000111;
			break;
		case 8:
			output = 0b01111111;
			break;
		case 9:
			output = 0b01101111;
			break;
		default:
			output = 0b00000000;
			break;

	}

	txData(pos, output);
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

		for(int value=0; value<10; ++value){
			for(int i = 0; i<8; ++i){
				setdigit(rand() % 10, value);
			}
			sleep_ms(1000);
		}
		sleep_ms(100);

	}

}
