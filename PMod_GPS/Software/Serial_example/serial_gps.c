#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/uart.h"

//uart parameters
#define UART_ID uart1
#define BAUD_RATE 9600
#define UART_TX_PIN 8
#define UART_RX_PIN 9


int main() {

    // see: https://github.com/raspberrypi/pico-examples/blob/master/uart/lcd_uart/lcd_uart.c
    stdio_init_all();
    uart_init(UART_ID, BAUD_RATE);
    uart_set_translate_crlf(UART_ID, false);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);


    //1pps LED
    gpio_init(13);
	gpio_set_dir(13, GPIO_IN);

    gpio_init(24);
	gpio_set_dir(24, GPIO_OUT);


    sleep_ms(2000);
    printf("hello world\n");

    int char_count = 0;
    char message[128];

    while (1) {
        // send any chars from stdio straight to the host
        if (uart_is_readable(UART_ID)>0) {
            char c = uart_getc(UART_ID);
            if (c < 128) {
                printf("%c",c);

                if(c == '\n')
                {
                    //end of the line, process the line
                    char_count = 0;
                    if(strncmp(message,"$GNRMC", 6)) {
                        printf("found GNRMC");
                    }

                }
                else
                {
                    //add to the message arrary
                    message[char_count++] = c;
                }
            }    
        }
        else{
            sleep_ms(25);
        }

        //Read 1PPS and show on the board
        gpio_put(24, gpio_get(13));

    }

}