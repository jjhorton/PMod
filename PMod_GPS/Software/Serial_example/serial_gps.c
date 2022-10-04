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
    char message[256];

    while (1) {
        // send any chars from stdio straight to the host
        if (uart_is_readable(UART_ID)>0) {
            char c = uart_getc(UART_ID);
            if (c < 128) {
                //printf("%c",c);

                if(c == '\n')
                {
                    //end of the line, process the line
                    if(strncmp(message,"$GNRMC", 6)==0) {
                        printf("found GNRMC\n");
                        printf("%s\n",message);
                        //extract the time
                        int hours = 10*(message[7]-'0') + (message[8]-'0');
                        int mins = 10*(message[9]-'0') + (message[10]-'0');
                        int secs = 10*(message[11]-'0') + (message[12]-'0');

                        printf("UTC time is: %02i:%02i:%02i \n", hours, mins, secs);

                        //extract the date
                    }
                    char_count = 0;

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