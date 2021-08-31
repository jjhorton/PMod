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

void set_blank(int led_num){
		sleep_ms(50);

		for (int i = 0; i < (led_num); ++i){
			put_pixel(urgb_u32(0,0,0));
		}
		sleep_ms(50);
}

int valueinarray(int val, int arr[], int len){
    int i;
    for(i = 0; i < len; i++){
        if(arr[i] == val) return 1;
    }
    return 0;
}

void setcross(){
		int inner[] = {0,7,9,14,18,21,27,28,35,36,42,45,49,54,56,63};
		int inner_len = sizeof(inner) / sizeof(inner[0]);

		int outer[] = {1,6,8,10,13,15,17,19,20,22,26,29,34,37,42,43,44,46,48,50,53,55,57,62};
		int outer_len = sizeof(outer) / sizeof(outer[0]);

		for (int i = 0; i < (64); ++i){
			if (valueinarray(i, inner, inner_len)) {
				put_pixel(urgb_u32(128,0,0));
			}
			else {
				if (valueinarray(i, outer, outer_len)) {
					put_pixel(urgb_u32(4,0,0));
				}
				else{
				put_pixel(urgb_u32(0,0,0));
				}
			}
		}
		sleep_ms(100);
}

void settick(){
		int inner[] = {33,40,41,49,42,50,58,51,35,43,44,28,36,37,21,29,30,14,22,23,7,15};
		int inner_len = sizeof(inner) / sizeof(inner[0]);

		for (int i = 0; i < (64); ++i){
			if (valueinarray(i, inner, inner_len)) {
				put_pixel(urgb_u32(0,32,0));
			}
			else {
				put_pixel(urgb_u32(0,0,0));
			}
		}
		sleep_ms(100);
}

void setsquare(int x){
		int rgb[] = {0,0,16};

		if(x == 3){
			int values[] = {0,1,2,3,4,5,6,7,8,15,16,23,24,31,32,39,40,47,48,55,56,57,58,59,60,61,62,63};
			int values_len = sizeof(values) / sizeof(values[0]);
			for (int i = 0; i < (64); ++i){
				if (valueinarray(i, values, values_len)) {
					put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]));
				}
				else {
					put_pixel(urgb_u32(0,0,0));
				}
			}}
		if(x == 2){
			int values[] = {9,10,11,12,13,14,17,22,25,30,33,38,41,46,49,50,51,52,53,54};
			int values_len = sizeof(values) / sizeof(values[0]);
			for (int i = 0; i < (64); ++i){
				if (valueinarray(i, values, values_len)) {
					put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]));
				}
				else {
					put_pixel(urgb_u32(0,0,0));
				}
			}}
		if(x == 1){
			int values[] = {18,19,20,21,26,29,34,37,42,43,44,45};
			int values_len = sizeof(values) / sizeof(values[0]);
			for (int i = 0; i < (64); ++i){
				if (valueinarray(i, values, values_len)) {
					put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]));
				}
				else {
					put_pixel(urgb_u32(0,0,0));
				}
			}}
		else{
				int values[] = {27,28,35,36};
				int values_len = sizeof(values) / sizeof(values[0]);
				for (int i = 0; i < (64); ++i){
					if (valueinarray(i, values, values_len)) {
						put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]));
					}
					else {
						put_pixel(urgb_u32(0,0,0));
					}
				}}

		sleep_ms(100);
}


const int PIN_TX = 0;


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
		int len = 64;

		while(1) {

			set_blank(len);
			sleep_ms(1000);

			setcross();
			sleep_ms(5000);

			settick(len);
			sleep_ms(5000);

			set_blank(len);
			sleep_ms(1000);

			for(int i=0; i < 4; i++){
				setsquare(i);
				sleep_ms(500);}

			sleep_ms(1000);

			for(int i=3; i > -1; --i){
				setsquare(i);
				sleep_ms(500);}


			set_blank(len);
			sleep_ms(1000);

			for(uint8_t counter=0; counter<255; counter++)
			{
				int led_select = rand() % 64 ;

				int led_num = (64*counter/256)+1;
				for (int i = 0; i < (led_num); ++i) {
						if (i== led_select){
							put_pixel(urgb_u32((counter), (counter),(counter)));
						}
						else {
							put_pixel(urgb_u32(16,0,0));
						}

					}
				sleep_ms(100);
			}
		}

}
