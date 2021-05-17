#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/binary_info.h"

// for PMOD0 output
#define SPI_RX_PIN 12
#define SPI_SCK_PIN 10
#define SPI_TX_PIN 11
#define SPI_CSN_PIN 13

/*
// for PMOD1 output
#define SPI_RX_PIN 16
#define SPI_SCK_PIN 18
#define SPI_TX_PIN 19
#define SPI_CSN_PIN 17
*/

#define READ_BIT 0x80
#define READ_BURST 0xC0

static inline void cs_select() {
    asm volatile("nop \n nop \n nop");
    gpio_put(SPI_CSN_PIN, 0);  // Active low
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect() {
    asm volatile("nop \n nop \n nop");
    gpio_put(SPI_CSN_PIN, 1);
    asm volatile("nop \n nop \n nop");
}

// write to a SPI register
static void write_register(uint8_t reg, uint8_t data) {
    uint8_t buf[2];
    buf[0] = reg & 0x7f;  // remove read bit as this is a write
    buf[1] = data;
    cs_select();
    spi_write_blocking(spi1, buf, 2);
    cs_deselect();
    sleep_ms(10);
}

//read from a SPI register
static void read_registers(uint8_t reg, uint8_t *buf, uint16_t len) {
    // For this particular device, we send the device the register we want to read
    // first, then subsequently read from the device. The register is auto incrementing
    // so we don't need to keep sending the register we want, just the first.
    reg |= READ_BIT;
    cs_select();
    spi_write_blocking(spi1, &reg, 1);
    sleep_ms(10);
    spi_read_blocking(spi1, 0, buf, len);
    cs_deselect();
    sleep_ms(10);
}


// the main function
int main(){
	stdio_init_all();
	sleep_ms(5000);
	printf("Hello, Reading raw data from registers via SPI...\n");

	// initalise the required pins
	spi_init(spi1, 500 * 1000);
  gpio_set_function(SPI_RX_PIN, GPIO_FUNC_SPI);
  gpio_set_function(SPI_SCK_PIN, GPIO_FUNC_SPI);
  gpio_set_function(SPI_TX_PIN, GPIO_FUNC_SPI);

	bi_decl(bi_3pins_with_func(SPI_RX_PIN, SPI_TX_PIN, SPI_SCK_PIN, GPIO_FUNC_SPI));

	// Chip select is active-low, so we'll initialise it to a driven-high state
	gpio_init(SPI_CSN_PIN);
	gpio_set_dir(SPI_CSN_PIN, GPIO_OUT);
	gpio_put(SPI_CSN_PIN, 1);
	// Make the CS pin available to picotool
	bi_decl(bi_1pin_with_name(SPI_CSN_PIN, "SPI CS"));

	// See if SPI is working - interrograte the device for its I2C ID number, should be 0x60
	uint8_t id;
	while(1){
		read_registers(0x30, &id,1);
		printf("Partnum is 0x%2x\n", id);
		read_registers(0x31, &id,2);
		printf("Version is 0x%2x\n", id);
		read_registers(0x32, &id,1);
		printf("Freqtest is 0x%2x\n", id);


		write_register(0x0B,0x12);
		read_registers(0x0B, &id,1);
		printf("CC1101_IOCFG2 0x%x\n", id);


		write_register(0x00,0x1);
		read_registers(0x00, &id,1);
		printf("CC1101_IOCFG2 0x%x\n", id);

		read_registers(0x34, &id,1);
		printf("FSCTRL1 0x%x\n", id);
		write_register(0x36,0x34);
		read_registers(0x36, &id,1);
		printf("FSCTRL1 0x%x\n", id);


		write_register(0x0C,0x00);

		sleep_ms(1000);
	}
}
