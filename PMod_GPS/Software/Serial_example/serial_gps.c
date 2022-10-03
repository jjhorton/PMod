#include <stdio.h>
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

    sleep_ms(2000);
    printf("hello world\n");

    while (1) {
        // send any chars from stdio straight to the host
        char c = uart_getc(UART_ID);
        if (c < 128) printf(c);
    }

}