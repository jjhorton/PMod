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

//extern uint16_t my_temps[64];
uint16_t my_temps[64];
uint16_t my_values[WIDTH * HEIGHT];

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

        uint16_t *img = (uint16_t*)my_values;

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

    multicore_launch_core1(core1_entry);

    for (int i = 0; i<(WIDTH * HEIGHT); i++){
        my_values[i] = 0xc7;
    }

    uint32_t gc_row[2][WIDTH];
    uint16_t *img = (uint16_t*)my_values;


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

            if (result > 25) {
                my_temps[i]  = 0xc7;
            }
            else{
                my_temps[i] = 0x00;
            }
        }
        printf("\n");

        for(int i = 0; i<64; ++i){
            printf("%i",my_temps[i]);
        }
        printf("\n");

        for (int i = 0; i<(WIDTH * HEIGHT); i++){
            my_values[i] = 0xc7;
        }   

        for (int i = 0; i<8; i++){
            for (int j = 0; j<8; j++){
                my_values[(i*WIDTH)+j] = my_temps[(i*8)+j];
                printf("%i, ",(i*8)+j);
                printf("%i, ",my_values[(i*WIDTH)+j]);
            }
        }

        printf("\n");
        /*
        for (int i = 0; i<(WIDTH); ++i){
            for (int j = 0; j<(HEIGHT); ++j){
                printf("%i",my_values[(i*WIDTH)+j]);
            }
        }
        printf("\n");
        */


        sleep_ms(200);
    }

}
