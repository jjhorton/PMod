/**
 * HUB75 display controller
 * Code to demonstrate the hub75 display board with custom image
 * Copyright (c) James Horton
 *
 * Based on files origonally from:
 * https://github.com/raspberrypi/pico-examples/tree/master/pio/hub75
 *
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "hub75.pio.h"


#define DATA_BASE_PIN 8
#define DATA_N_PINS 6
#define ROWSEL_BASE_PIN 14
#define ROWSEL_N_PINS 5
#define CLK_PIN 19
#define STROBE_PIN 20
#define OEN_PIN 21

#define WIDTH 64
#define HEIGHT 64

const int PIN_LED = 24;

const int I2C_SDA = 0;
const int I2C_SCL = 1;

// varribles for the images
float my_temps[64];
float upscaled_temps[4096];
int select_img; 
uint16_t my_values_1[WIDTH * HEIGHT];
uint16_t my_values_2[WIDTH * HEIGHT];


//
// Lookup table the colourmap
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

static inline uint32_t gamma_correct_565_888(uint16_t pix) {
    uint32_t r_gamma = pix & 0xf800u;
    r_gamma *= r_gamma;
    uint32_t g_gamma = pix & 0x07e0u;
    g_gamma *= g_gamma;
    uint32_t b_gamma = pix & 0x001fu;
    b_gamma *= b_gamma;
    return (b_gamma >> 2 << 16) | (g_gamma >> 14 << 8) | (r_gamma >> 24 << 0);
}


void core1_entry() {
    PIO pio = pio0;
    uint sm_data = 0;
    uint sm_row = 1;

    uint data_prog_offs = pio_add_program(pio, &hub75_data_rgb888_program);
    uint row_prog_offs = pio_add_program(pio, &hub75_row_program);
    hub75_data_rgb888_program_init(pio, sm_data, data_prog_offs, DATA_BASE_PIN, CLK_PIN);
    hub75_row_program_init(pio, sm_row, row_prog_offs, ROWSEL_BASE_PIN, ROWSEL_N_PINS, STROBE_PIN);

    uint32_t gc_row[2][WIDTH];
    //uint16_t *img = (uint16_t*)my_values;


    while (1) {

        uint16_t *img;
        if (select_img == 1){
            img = (uint16_t*)my_values_1;
        }
        else{
            img = (uint16_t*)my_values_2;
        }

        //hub75 write to screen
        for (int rowsel = 0; rowsel < (1 << ROWSEL_N_PINS); ++rowsel) {
            for (int x = 0; x < WIDTH; ++x) {
                gc_row[0][x] = gamma_correct_565_888(img[rowsel * WIDTH + x]);
                gc_row[1][x] = gamma_correct_565_888(img[((1u << ROWSEL_N_PINS) + rowsel) * WIDTH + x]);
            }
            for (int bit = 0; bit < 8; ++bit) {
                hub75_data_rgb888_set_shift(pio, sm_data, data_prog_offs, bit);
                for (int x = 0; x < WIDTH; ++x) {
                    pio_sm_put_blocking(pio, sm_data, gc_row[0][x]);
                    pio_sm_put_blocking(pio, sm_data, gc_row[1][x]);
                }
                // Dummy pixel per lane
                pio_sm_put_blocking(pio, sm_data, 0);
                pio_sm_put_blocking(pio, sm_data, 0);
                // SM is finished when it stalls on empty TX FIFO
                hub75_wait_tx_stall(pio, sm_data);
                // Also check that previous OEn pulse is finished, else things can get out of sequence
                hub75_wait_tx_stall(pio, sm_row);

                // Latch row data, pulse output enable for new row.
                pio_sm_put_blocking(pio, sm_row, rowsel | (100u * (1u << bit) << 5));
            }
        }
    }
}


int main() {
    stdio_init_all();

    select_img = 1; 

    multicore_launch_core1(core1_entry);

    for (int i = 0; i<(WIDTH * HEIGHT); i++){
        my_values_1[i] = 0xc7;
        my_values_2[i] = 0xc7;
    }

        // This example will use I2C0 on the default SDA and SCL pins (0, 1 on a Pico)
	i2c_init(i2c0, 1000000);

	//Setup the I2C pins for camera
	gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
	gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
	gpio_pull_up(I2C_SDA);
	gpio_pull_up(I2C_SCL);

	// Make the I2C pins available to picotool
	bi_decl(bi_2pins_with_func(I2C_SDA, I2C_SCL, GPIO_FUNC_I2C));

    // read and interp 
	int addr = 0b01101000;

    int8_t on_off = 0;
	gpio_init(PIN_LED);
	gpio_set_dir(PIN_LED, GPIO_OUT);

	uint8_t val = 0x80;
    int ret;
	uint8_t rxdata[2];

    while(1){
        on_off = !on_off;
		gpio_put(PIN_LED, on_off);

        printf("start \n");

		i2c_write_blocking(i2c0, addr, &val, 1, true);

		for(int i = 0; i<64; ++i){
			ret = i2c_read_blocking(i2c0, addr, &rxdata[0], 2, true);
		    float result  = (int16_t)((((uint16_t)rxdata[1] << 8) | ((uint16_t)rxdata[0]))<< 4) >> 4;
            result = result*0.25;
            printf("%6.2f, ", result);

            my_temps[i]  = result;
        }
        printf("\n");


        //uint16_t upscaled_temps[64*64];

        /*
        //upscale in 8x8 blocks of color
        for (int i = 0; i<8; i++){
            for (int j = 0; j<8; j++){
                for(int a = 0; a < 8; a++){
                    for(int b = 0; b< 8; b++){
                        upscaled_temps[(((j*8)+b)*WIDTH)+((i*8)+a)] = my_temps[(j*8)+i];
                    }
                }
            }
        }
        */
        
        // 2D linear interpolation 
        for (int i = 0; i<8; i++){
            for (int j = 0; j<8; j++){

                if(i<7){
                    //first cell is the actual value from the sensor
                    upscaled_temps[(((j*8))*WIDTH)+((i*9))] = my_temps[(j*8)+i];

                    //calculate inter factor between each of the pixelsa
                    float i_diff = (my_temps[(j*8)+(i+1)] - my_temps[(j*8)+i])/9;

                    for(int a = 1; a < 9; a++){
                        float step = i_diff*a;
                        upscaled_temps[(((j*8))*WIDTH)+((i*9)+a)] = my_temps[(j*8)+i] + step;
                    }
                }
                else{
                    upscaled_temps[(((j*8))*WIDTH)+(((i+1)*8)-1)] = my_temps[(j*8)+i];
                }

            }
        }

        for (int i = 0; i<(WIDTH); i++){
            for (int j = 0; j<8; j++){
                for(int a = 0; a < 8; a++){
                    float diff = 0;
                    float ref_start; 
                    float ref_end;
                    if (j==7){
                        //end pixels
                        ref_start = upscaled_temps[(((j*8))*WIDTH)+i];
                        ref_end = upscaled_temps[((((j)*8)-1)*WIDTH)+i];
                        diff = (ref_end-ref_start)/8;
                    }
                    else {
                        //middle pixels
                        ref_start = upscaled_temps[(((j*8))*WIDTH)+i];
                        ref_end = upscaled_temps[((((j+1)*8))*WIDTH)+i];
                        diff = (ref_end -ref_start)/8;
                    }

                    for(int b = 1; b < 8; b++){
                        float step = diff*b;
                        upscaled_temps[(((j*8)+b)*WIDTH)+i] = ref_start + step;
                    }
                }
            }
        }

        //for (int i = 0; i<(WIDTH * HEIGHT); i++){
        //    my_values[i] = 0xc7;
        //}   

        
        for (int i = 0; i<HEIGHT; i++){
            for (int j = 0; j<WIDTH; j++){

                float max_temp = 45;
                float min_temp = 5;
                float steps_temp = 80;

                float scale_temp = steps_temp/(max_temp-min_temp);

                int16_t lookup_value = 80 - ((upscaled_temps[(j*WIDTH)+i]-min_temp)*scale_temp);

                if(i==2 && j==2){
                        printf("Start: %6.2f, ", max_temp);
                        printf("End: %6.2f, ", min_temp);
                        printf("Step: %6.2f \n ", scale_temp);
                        printf("Step: %6.2f \n ",upscaled_temps[(j*WIDTH)+i]);
                        printf("Step: %6.2f \n ",lookup_value );
                    }
  
                uint16_t value_r = (( RGB_LOOKUP[lookup_value][0] >> 3) & 0x1f) << 11;
                uint16_t value_g = (( RGB_LOOKUP[lookup_value][1] >> 2) & 0x3f) << 5;
                uint16_t value_b = (  RGB_LOOKUP[lookup_value][2] >> 3) & 0x1f;

                uint16_t rgb_value = (uint16_t) (value_r | value_g | value_b);

                if (select_img==2){
                    my_values_1[(i*WIDTH)+j ] = rgb_value;
                }
                else{
                    my_values_2[(i*WIDTH)+j ] = rgb_value;
                }
            }
        }
        if (select_img==1){
            select_img = 2;
        }
        else{
            select_img = 1;
        }

    }

}
