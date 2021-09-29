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

const int RGB_LOOKUP[][3] = {{255,14,240},{255,13,240},{255,12,240},{255,11,240},
														{255,10,240},{255,9,240},{255,8,240},{255,7,240},
														{255,6,240},{255,5,240},{255,4,240},{255,3,240},
														{255,2,240},{255,1,240},{255,0,240},{255,0,224},
														{255,0,208},{255,0,192},{255,0,176},{255,0,160},
														{255,0,144},{255,0,128},{255,0,112},{255,0,96 },
														{255,0,80 },{255,0,64 },{255,0,48 },{255,0,32 },
														{255,0,16 },{255,0,0  },{255,10,0 },{255,20,0 },
														{255,30,0 },{255,40,0 },{255,50,0 },{255,60,0 },
														{255,70,0 },{255,80,0 },{255,90,0 },{255,100,0},
														{255,110,0},{255,120,0},{255,130,0},{255,140,0},
														{255,150,0},{255,160,0},{255,170,0},{255,180,0},
														{255,190,0},{255,200,0},{255,210,0},{255,220,0},
														{255,230,0},{255,240,0},{255,250,0},{253,255,0},
														{215,255,0},{176,255,0},{138,255,0},{101,255,0},
														{62,255,0 },{23,255,0 },{0,255,16 },{0,255,54 },
														{0,255,92 },{0,255,131},{0,255,168},{0,255,208},
														{0,255,244},{0,228,255},{0,212,255},{0,196,255},
														{0,180,255},{0,164,255},{0,148,255},{0,132,255},
														{0,116,255},{0,100,255},{0,84,255 },{0,68,255 },
														{0,50,255 },{0,34,255 },{0,18,255 },{0,2,255  },
														{0,0,255  },{1,0,255  },{2,0,255  },{3,0,255  },
														{4,0,255  },{5,0,255 }};

static inline void put_pixel(uint32_t pixel_grb_0,uint32_t pixel_grb_1) {
    pio_sm_put_blocking(pio0, 0, pixel_grb_0 << 8u);
		pio_sm_put_blocking(pio1, 0, pixel_grb_1 << 8u);
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
			put_pixel(urgb_u32(0,0,0),urgb_u32(0,0,0));
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
/*
void setcross(){
		int inner[] = {0,7,9,14,18,21,27,28,35,36,42,45,49,54,56,63};
		int inner_len = sizeof(inner) / sizeof(inner[0]);

		int outer[] = {1,6,8,10,13,15,17,19,20,22,26,29,34,37,41,43,44,46,48,50,53,55,57,62};
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
*/
void setsquare(int x){
		int rgb[] = {0,0,16};

		if(x == 3){
			int values[] = {0,1,2,3,4,5,6,7,8,15,16,23,24,31,32,39,40,47,48,55,56,57,58,59,60,61,62,63};
			int values_len = sizeof(values) / sizeof(values[0]);
			for (int i = 0; i < (64); ++i){
				if (valueinarray(i, values, values_len)) {
					put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]),urgb_u32(rgb[0],rgb[1],rgb[2]));
				}
				else {
					put_pixel(urgb_u32(0,0,0),urgb_u32(0,0,0));
				}
			}}
		if(x == 2){
			int values[] = {9,10,11,12,13,14,17,22,25,30,33,38,41,46,49,50,51,52,53,54};
			int values_len = sizeof(values) / sizeof(values[0]);
			for (int i = 0; i < (64); ++i){
				if (valueinarray(i, values, values_len)) {
					put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]),urgb_u32(rgb[0],rgb[1],rgb[2]));
				}
				else {
					put_pixel(urgb_u32(0,0,0),urgb_u32(0,0,0));
				}
			}}
		if(x == 1){
			int values[] = {18,19,20,21,26,29,34,37,42,43,44,45};
			int values_len = sizeof(values) / sizeof(values[0]);
			for (int i = 0; i < (64); ++i){
				if (valueinarray(i, values, values_len)) {
					put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]),urgb_u32(rgb[0],rgb[1],rgb[2]));
				}
				else {
					put_pixel(urgb_u32(0,0,0),urgb_u32(0,0,0));
				}
			}}
		else{
				int values[] = {27,28,35,36};
				int values_len = sizeof(values) / sizeof(values[0]);
				for (int i = 0; i < (64); ++i){
					if (valueinarray(i, values, values_len)) {
						put_pixel(urgb_u32(rgb[0],rgb[1],rgb[2]),urgb_u32(rgb[0],rgb[1],rgb[2]));
					}
					else {
						put_pixel(urgb_u32(0,0,0),urgb_u32(0,0,0));
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
    PIO pio_0 = pio0;
		PIO pio_1 = pio1;
    int sm = 0;

    uint offset_0 = pio_add_program(pio_0, &ws2812_program);
		uint offset_1 = pio_add_program(pio_1, &ws2812_program);
    ws2812_program_init(pio_0, sm, offset_0, 9, 800000, false);
		ws2812_program_init(pio_1, sm, offset_1, 17, 800000, false);

    int t = 0;
		int len = 128;

		int led_rgb[8][16][3];

		for(uint8_t counter_1=0; counter_1<8; counter_1++){
			for(uint8_t counter_2=0; counter_2<16; counter_2++){
				led_rgb[counter_1][counter_2][0] = RGB_LOOKUP[counter_1*3 + counter_2*4][0]/8;
				led_rgb[counter_1][counter_2][1] = RGB_LOOKUP[counter_1*3 + counter_2*4][1]/8;
				led_rgb[counter_1][counter_2][2] = RGB_LOOKUP[counter_1*3 + counter_2*4][2]/8;
			}
		}

		while(1) {

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

			for(uint8_t counter_1=0; counter_1<8; counter_1++)
			{
				for(uint8_t counter_2=0; counter_2<8; counter_2++)
				{
						put_pixel(urgb_u32(led_rgb[counter_1][counter_2][0],led_rgb[counter_1][counter_2][1],
							led_rgb[counter_1][counter_2][2]),urgb_u32(led_rgb[counter_1][counter_2+8][0],
								led_rgb[counter_1][counter_2+8][1],led_rgb[counter_1][counter_2+8][2]));
				}
			}

			sleep_ms(1000);

			for(uint8_t my_shift=0; my_shift<16; my_shift++ )
			{
				for(uint8_t counter_1=0; counter_1<8; counter_1++){
					for(uint8_t counter_2=0; counter_2<16; counter_2++){
						led_rgb[counter_1][counter_2][0] = RGB_LOOKUP[(my_shift + counter_1)*3 + counter_2*4][0]/8;
						led_rgb[counter_1][counter_2][1] = RGB_LOOKUP[(my_shift + counter_1)*3 + counter_2*4][1]/8;
						led_rgb[counter_1][counter_2][2] = RGB_LOOKUP[(my_shift + counter_1)*3 + counter_2*4][2]/8;
					}
				}

				for(uint8_t counter_1=0; counter_1<8; counter_1++)
				{
					for(uint8_t counter_2=0; counter_2<8; counter_2++)
					{
						put_pixel(urgb_u32(led_rgb[counter_1][counter_2][0],led_rgb[counter_1][counter_2][1],
							led_rgb[counter_1][counter_2][2]),urgb_u32(led_rgb[counter_1][counter_2+8][0],
								led_rgb[counter_1][counter_2+8][1],led_rgb[counter_1][counter_2+8][2]));
					}
				}
				sleep_ms(500);
			}

			set_blank(len);
			sleep_ms(100);
		}

}
