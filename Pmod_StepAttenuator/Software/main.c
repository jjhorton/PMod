#include "pico/stdlib.h"


const uint OUTPUT_PINS[] = {0, 1, 2, 3, 4, 5, 6, 7};

int setup_output(){
	for(int x = 0; x<8; x++) {
			gpio_init(OUTPUT_PINS[x]);
			gpio_set_dir(OUTPUT_PINS[x], GPIO_OUT);
			gpio_put(OUTPUT_PINS[x],0);

	}
}

int main() {
	//initalise the output pins
	setup_output();

	//uint8_t my_value = 0;

	//setup the LED pin
	gpio_init(8);
	gpio_set_dir(8, GPIO_OUT);
	gpio_put(8, 0); // set the LED pin low

	while(1){
		uint8_t my_value = 0b00000001;

		for(int x =0; x<64; x++){
			//set the LE pin low
			gpio_put(OUTPUT_PINS[0], 1);
			sleep_ms(10);
			// set the data pins

			gpio_put(OUTPUT_PINS[2], (x >> 1) & 1U); // 0.5
			gpio_put(OUTPUT_PINS[3], (x >> 2) & 1U); // 1
			gpio_put(OUTPUT_PINS[4], (x >> 3) & 1U); // 2
			gpio_put(OUTPUT_PINS[5], (x >> 4) & 1U); // 4
			gpio_put(OUTPUT_PINS[6], (x >> 5) & 1U); // 8
			gpio_put(OUTPUT_PINS[7], (x >> 6) & 1U); // 16

		// set the LE Pin High to enable the output

			gpio_put(8, 1); // set the LED pin high
			sleep_ms(2000);
		}

		/*sleep_ms(10);
		
		gpio_put(OUTPUT_PINS[3], 0);
		gpio_put(OUTPUT_PINS[2], 0);
		gpio_put(OUTPUT_PINS[5], 0);
		gpio_put(OUTPUT_PINS[4], 0);
		gpio_put(OUTPUT_PINS[7], 0);
		gpio_put(OUTPUT_PINS[6], 0); // set LE low again
		
		gpio_put(8, 0); // set the LED pin low
		sleep_ms(2000);*/
	}
}
