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

		//set the LE pin low
		gpio_put(OUTPUT_PINS[0], 1);
		sleep_ms(10);
		// set the data pins

		gpio_put(OUTPUT_PINS[3], 1); // 0.5
		gpio_put(OUTPUT_PINS[2], 1); // 1
		gpio_put(OUTPUT_PINS[5], 1); // 2
		gpio_put(OUTPUT_PINS[4], 1); // 4
		gpio_put(OUTPUT_PINS[7], 1); // 8
		gpio_put(OUTPUT_PINS[6], 1); // 16

		// set the LE Pin High to enable the output

		gpio_put(8, 1); // set the LED pin high
		sleep_ms(1000);


		sleep_ms(10);
		
		gpio_put(OUTPUT_PINS[3], 0);
		gpio_put(OUTPUT_PINS[2], 0);
		gpio_put(OUTPUT_PINS[5], 0);
		gpio_put(OUTPUT_PINS[4], 0);
		gpio_put(OUTPUT_PINS[7], 0);
		gpio_put(OUTPUT_PINS[6], 0); // set LE low again
		
		gpio_put(8, 0); // set the LED pin low
		sleep_ms(1000);
	}
}
