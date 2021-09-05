/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

//const int pin_clk = 2;
//const int  pin_data = 0;


class My7Seg {
	private:
		uint8_t pin_clk;
		uint8_t pin_data;
  public:
    My7Seg(int data_pin , int clk_pin) {
      pin_clk = clk_pin;
			pin_data = data_pin;

			gpio_init(pin_clk);
			gpio_set_dir(pin_clk, GPIO_OUT);
			gpio_put(pin_clk,1);

			gpio_init(pin_data);
			gpio_set_dir(pin_data, GPIO_OUT);
			gpio_put(pin_data,1);
		}

		void enable(){
			//command to turn on the display
			int command1[] = {1,1,1,1,0,0,0,1};
			//initallisation
			gpio_put(pin_data,0);
			sleep_ms(0.2);
			gpio_put(pin_clk,0);
			sleep_ms(0.2);
			//send the bits
			for(int i=0; i < 8; ++i ){
				gpio_put(pin_data,command1[i]);
				sleep_ms(0.2);
				gpio_put(pin_clk,1);
				sleep_ms(0.4);
				gpio_put(pin_clk,0);
				sleep_ms(0.2);
			}
			//end the transmission
			gpio_put(pin_data,0);
			sleep_ms(0.2);
			gpio_put(pin_clk,1);
			sleep_ms(0.2);
			gpio_put(pin_data,1);

			sleep_ms(10);

		}

		void txData(uint8_t pos, uint8_t data){

			uint8_t addr = 0b11000000 + pos;

			gpio_put(pin_data,0);
			sleep_ms(0.2);
			gpio_put(pin_clk,0);
			sleep_ms(0.2);

			for(int i=0; i < 8; ++i ){
				gpio_put(pin_data,(addr >> i) & 1U);
				sleep_ms(0.2);
				gpio_put(pin_clk,1);
				sleep_ms(0.4);
				gpio_put(pin_clk,0);
				sleep_ms(0.2);
			}

			for(int i=0 ; i < 8; ++i ){
				gpio_put(pin_data,(data >> i) & 1U);
				sleep_ms(0.2);
				gpio_put(pin_clk,1);
				sleep_ms(0.4);
				gpio_put(pin_clk,0);
				sleep_ms(0.2);
			}
			gpio_put(pin_data,0);
			sleep_ms(0.2);
			gpio_put(pin_clk,1);
			sleep_ms(0.2);
			gpio_put(pin_data,1);
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

			this->txData(pos, output);
		}
};


int main() {

	My7Seg Display1(0,2);

	Display1.enable();

	while(1){

		for(int value=0; value<10; ++value){
			for(int i = 0; i<8; ++i){
				Display1.setdigit(rand() % 10, value);
			}
			sleep_ms(1000);
		}
		sleep_ms(100);

	}

}
