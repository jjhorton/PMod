#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "MyLedDisp.h"

MyLedDisp::MyLedDisp(int data_pin , int clk_pin)
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

void MyLedDisp::enable()
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

void MyLedDisp::txData(uint8_t pos, uint8_t data)
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


void MyLedDisp::setDisplay(uint8_t data[16])
{
	for(uint8_t pos = 0; pos<16; pos++){
		this->txData(pos, data[pos]);
	}
}
