#include "pico/stdlib.h"

#define PMOD 1

#if (PMOD==0)
	//if plugged into pmod1
	//const uint OUTPUT_PINS[] = {9,11,13,15,8,10,12,14};
	const uint OUTPUT_PINS[] = {9, 8, 11, 10, 13, 12, 15, 14};
#else
	//if plugged into pmod0
	//const uint OUTPUT_PINS[] = {21,19,17,3,20,18,16,2};
	const uint OUTPUT_PINS_1[] = {0,1,2,3,4,5,6,7};
	const uint OUTPUT_PINS_2[] = {8,9,10,11,12,13,14,15};
	const uint OUTPUT_PINS_3[] = {16,17,18,19,20,21,22,23};
#endif

int setup_output(){
	for(int x = 0; x<8; x++) {
			gpio_init(OUTPUT_PINS_1[x]);
			gpio_set_dir(OUTPUT_PINS_1[x], GPIO_OUT);
			gpio_put(OUTPUT_PINS_1[x],0);

			gpio_init(OUTPUT_PINS_2[x]);
			gpio_set_dir(OUTPUT_PINS_2[x], GPIO_OUT);
			gpio_put(OUTPUT_PINS_2[x],0);

			gpio_init(OUTPUT_PINS_3[x]);
			gpio_set_dir(OUTPUT_PINS_3[x], GPIO_OUT);
			gpio_put(OUTPUT_PINS_3[x],0);
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
				gpio_put(OUTPUT_PINS_1[x], (my_value >> x) & 1U);
				gpio_put(OUTPUT_PINS_2[x], (my_value >> x) & 1U);
				gpio_put(OUTPUT_PINS_3[x], (my_value >> x) & 1U);
			}
			my_value = my_value << 1;
			sleep_ms(100);
		}
	}
}
