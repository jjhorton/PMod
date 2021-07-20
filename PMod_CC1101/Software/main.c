#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/binary_info.h"
#include "cc1101.h"

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

// initalise the CC1101
static void setup_cc1101(){
	write_register(CC1101_FSCTRL1,  0x08);
	write_register(CC1101_FSCTRL0,  0x00);
	write_register(CC1101_FREQ2,    F2_433);
	write_register(CC1101_FREQ1,    F1_433);
	write_register(CC1101_FREQ0,    F0_433);
	write_register(CC1101_MDMCFG4,  0x5B);
	write_register(CC1101_MDMCFG3,  0xF8);
	write_register(CC1101_MDMCFG2,  0x03);
	write_register(CC1101_MDMCFG1,  0x22);
	write_register(CC1101_MDMCFG0,  0xF8);
	write_register(CC1101_CHANNR,   0x00);
	write_register(CC1101_DEVIATN,  0x47);
	write_register(CC1101_FREND1,   0xB6);
	write_register(CC1101_FREND0,   0x10);
	write_register(CC1101_MCSM0 ,   0x18);
	write_register(CC1101_FOCCFG,   0x1D);
	write_register(CC1101_BSCFG,    0x1C);
	write_register(CC1101_AGCCTRL2, 0xC7);
	write_register(CC1101_AGCCTRL1, 0x00);
	write_register(CC1101_AGCCTRL0, 0xB2);
	write_register(CC1101_FSCAL3,   0xEA);
	write_register(CC1101_FSCAL2,   0x2A);
	write_register(CC1101_FSCAL1,   0x00);
	write_register(CC1101_FSCAL0,   0x11);
	write_register(CC1101_FSTEST,   0x59);
	write_register(CC1101_TEST2,    0x81);
	write_register(CC1101_TEST1,    0x35);
	write_register(CC1101_TEST0,    0x09);
	write_register(CC1101_IOCFG2,   0x0B); 	//serial clock.synchronous to the data in synchronous serial mode
	write_register(CC1101_IOCFG0,   0x06);  	//asserts when sync word has been sent/received, and de-asserts at the end of the packet
	write_register(CC1101_PKTCTRL1, 0x04);		//two status bytes will be appended to the payload of the packet,including RSSI LQI and CRC OK
									//No address check
	write_register(CC1101_PKTCTRL0, 0x05);		//whitening off;CRC Enable£»variable length packets, packet length configured by the first byte after sync word
	write_register(CC1101_ADDR,     0x00);		//address used for packet filtration.
	write_register(CC1101_PKTLEN,   0x3D); 	//61 bytes max length
}

static void setupread_cc1101(){
	uint8_t id;
	read_registers(CC1101_FSCTRL1, &id,1); 	printf("CC1101_FSCTRL1 	0x%2x\n", id);
	read_registers(CC1101_FSCTRL0, &id,1); 	printf("CC1101_FSCTRL0 	0x%2x\n", id);
	read_registers(CC1101_FREQ2, &id,1); 		printf("CC1101_FREQ2 	0x%2x\n", id);
	read_registers(CC1101_FREQ1, &id,1); 		printf("CC1101_FREQ1 	0x%2x\n", id);
	read_registers(CC1101_FREQ0, &id,1); 		printf("CC1101_FREQ0 	0x%2x\n", id);
	read_registers(CC1101_MDMCFG4, &id,1); 	printf("CC1101_MDMCFG4 	0x%2x\n", id);
	read_registers(CC1101_MDMCFG3, &id,1); 	printf("CC1101_MDMCFG3 	0x%2x\n", id);
	read_registers(CC1101_MDMCFG2, &id,1); 	printf("CC1101_MDMCFG2 	0x%2x\n", id);
	read_registers(CC1101_MDMCFG1, &id,1); 	printf("CC1101_MDMCFG1 	0x%2x\n", id);
	read_registers(CC1101_MDMCFG0, &id,1); 	printf("CC1101_MDMCFG0 	0x%2x\n", id);
	read_registers(CC1101_CHANNR, &id,1); 	printf("CC1101_CHANNR 0x%2x\n", id);
	read_registers(CC1101_DEVIATN, &id,1); 	printf("CC1101_DEVIATN 	0x%2x\n", id);
	read_registers(CC1101_FREND1, &id,1); 	printf("CC1101_FREND1 0x%2x\n", id);
	read_registers(CC1101_FREND0, &id,1); 	printf("CC1101_FREND0 0x%2x\n", id);
	read_registers(CC1101_MCSM0, &id,1); 		printf("CC1101_MCSM0 	0x%2x\n", id);
	read_registers(CC1101_FOCCFG, &id,1); 	printf("CC1101_FOCCFG 	0x%2x\n", id);
	read_registers(CC1101_BSCFG, &id,1); 		printf("CC1101_BSCFG 	0x%2x\n", id);
	read_registers(CC1101_AGCCTRL2, &id,1); printf("CC1101_AGCCTRL2 	0x%2x\n", id);
	read_registers(CC1101_AGCCTRL1, &id,1); printf("CC1101_AGCCTRL1 	0x%2x\n", id);
	read_registers(CC1101_AGCCTRL0, &id,1); printf("CC1101_AGCCTRL0 	0x%2x\n", id);
	read_registers(CC1101_FSCAL3, &id,1); printf("CC1101_FSCAL3 	0x%2x\n", id);
	read_registers(CC1101_FSCAL2, &id,1); printf("CC1101_FSCAL2 	0x%2x\n", id);
	read_registers(CC1101_FSCAL1, &id,1); printf("CC1101_FSCAL1 	0x%2x\n", id);
	read_registers(CC1101_FSCAL0, &id,1); printf("CC1101_FSCAL0 	0x%2x\n", id);
	read_registers(CC1101_FSTEST, &id,1); printf("CC1101_FSTEST 	0x%2x\n", id);
	read_registers(CC1101_TEST2, &id,1); printf("CC1101_TEST2 	0x%2x\n", id);
	read_registers(CC1101_TEST1, &id,1); printf("CC1101_TEST1 	0x%2x\n", id);
	read_registers(CC1101_TEST0, &id,1); printf("CC1101_TEST0		0x%2x\n", id);
	read_registers(CC1101_IOCFG2, &id,1); printf("CC1101_IOCFG2 	0x%2x\n", id);
	read_registers(CC1101_IOCFG0, &id,1); printf("CC1101_IOCFG0 	0x%2x\n", id);
	read_registers(CC1101_PKTCTRL1, &id,1); printf("CC1101_PKTCTRL1 	0x%2x\n", id);
	read_registers(CC1101_PKTCTRL0, &id,1); printf("CC1101_PKTCTRL0 	0x%2x\n", id);
	read_registers(CC1101_ADDR, &id,1); printf("CC1101_ADDR 	0x%2x\n", id);
	read_registers(CC1101_PKTLEN, &id,1); printf("CC1101_PKTLEN 	0x%2x\n", id);
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
		setup_cc1101();
		setupread_cc1101();

		sleep_ms(3000);
	}
}
