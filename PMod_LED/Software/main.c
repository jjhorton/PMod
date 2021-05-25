#include "pico/stdlib.h"

#define PMOD 1

#if (PMOD==0)
	//if plugged into pmod1
	//const uint OUTPUT_PINS[] = {9,11,13,15,8,10,12,14};
	const uint OUTPUT_PINS[] = {9, 8, 11, 10, 13, 12, 15, 14};
#else
	//if plugged into pmod0
	//const uint OUTPUT_PINS[] = {21,19,17,3,20,18,16,2};
	const uint OUTPUT_PINS[] = {21,20,19,18,17,16,3,2};
#endif

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

	while(1){
		uint8_t my_value = 0b00000001;
		for(int y = 0; y<8; y++){
			for(int x = 0; x<8; x++) {
				gpio_put(OUTPUT_PINS[x], (my_value >> x) & 1U);
			}
			my_value = my_value << 1;
			sleep_ms(500);
		}
	}
}
