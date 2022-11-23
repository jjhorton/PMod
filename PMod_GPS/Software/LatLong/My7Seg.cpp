#include <stdio.h>
#include <stdlib.h>

#include "My7Seg.h"
#include "pico/stdlib.h"

My7Seg::My7Seg(int data_pin , int clk_pin)
{
      pin_clk = clk_pin;
			pin_data = data_pin;

			gpio_init(pin_clk);
			gpio_set_dir(pin_clk, GPIO_OUT);
			gpio_put(pin_clk,1);

			gpio_init(pin_data);
			gpio_set_dir(pin_data, GPIO_OUT);
			gpio_put(pin_data,1);
}

void My7Seg::enable()
{
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

void My7Seg::txData(uint8_t pos, uint8_t data)
{
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

void My7Seg::setdigit(uint8_t pos, uint8_t value, bool decimal)
{
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
	if (decimal == true) {
		output = output + 0b10000000;
	}

	this->txData(pos, output);
}

void My7Seg::setValue(double value, uint8_t decimal){
		//decimal is the number of digits after decimal point
		bool dec = false;
		uint8_t digit = 0;

		long int my_value;

		int my_shift = 1;
		for(int i; i<(decimal); i++){
			my_shift = my_shift*10;
		}

		my_value = (value * my_shift);

		for(int pos=0; pos<8; ++pos){
			//check if the decimal value is needed
			if(decimal == pos){dec = true;}
			else {dec = false;}

			// work out the digit value
			digit = my_value%10;
			my_value = my_value/10;
			this->setdigit(7-pos, digit, dec);
		}
	}

	void My7Seg::setValue2(double value1, double value2, uint8_t decimal){
			//decimal is the number of digits after decimal point
			bool dec = false;
			uint8_t digit = 0;

			int my_shift = 1;
			for(int i; i<(decimal); i++){
				my_shift = my_shift*10;
			}

			int my_value1 = (value1 * my_shift);
			int my_value2 = (value2 * my_shift);

			for(int pos=0; pos<8; ++pos){
				//check if the decimal value is needed
				if((decimal == pos)||((decimal+4) == pos)){dec = true;}
				else {dec = false;}

				if(pos<4){
					// work out the digit value1
					digit = my_value2%10;
					my_value2 = my_value2/10;
				}
				else{
					// work out the digit value2
					digit = my_value1%10;
					my_value1 = my_value1/10;
				}
				this->setdigit(7-pos, digit, dec);
			}
		}
