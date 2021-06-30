/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}


const int PIN_TX = 21;

int main() {
    //set_sys_clock_48();
    stdio_init_all();
    puts("WS2812 Smoke Test");

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;

    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, PIN_TX, 800000, false);

    int t = 0;
		int len = 10;

		while(1) {

			for (int i = 0; i < (len); ++i) {
					//put_pixel(urgb_u32(0, 0, 0));
					put_pixel(0);
			}
			sleep_ms(1000);

			for(uint8_t counter=0; counter<255; counter++)
			{
				int led_num = (10*counter/256)+1;
				for (int i = 0; i < (led_num); ++i) {
						put_pixel(urgb_u32((counter)/4, (255-counter)/8,0));
					}
				sleep_ms(100);
			}
		}

}
