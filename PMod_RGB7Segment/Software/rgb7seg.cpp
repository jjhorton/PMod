#include <stdio.h>

#include "rgb7seg.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

RGB7Seg::RGB7Seg()
{
    //initilisation of the board

	//Setup the I2C bus
    i2c_init(i2c0, 1000000);
	gpio_set_function(16, GPIO_FUNC_I2C);
    gpio_set_function(17, GPIO_FUNC_I2C);
    gpio_pull_up(16);
    gpio_pull_up(17);

     bi_decl(bi_2pins_with_func(16, 17, GPIO_FUNC_I2C));

    //set the power up pin to high
    gpio_init(18);
	gpio_set_dir(18, GPIO_OUT);
	gpio_put(18, 1);

    if( get_id() == 0x60){
        //the chip has been found

        //reset the system
        this->reset();
        //set the global current
        this->set_current(0xff);
        //set the default value for each LED
        this->enable();

    }

}

uint8_t RGB7Seg::get_id()
{
    //get the ID from the chip 
    uint8_t addr = address;
    uint8_t rxdata = 0;
    uint8_t val[2];
    val[0] = 0xFC;
	i2c_write_blocking(i2c0, addr, &val[0], 1, true);
	i2c_read_blocking(i2c0, addr, &rxdata, 1, true);

    printf("Chip ID: ");
	printf("%x \n", rxdata);

    return rxdata;
}

uint8_t RGB7Seg::select_page(uint8_t page)
{
    if( page != current_page){
        // check if the page is in range 0-4 
        if( page < 6){

		    this->unlock();
            uint8_t addr = address;
            uint8_t val[2]; 

    		val[0] = 0xFD;
	    	val[1] = page;
            i2c_write_blocking(i2c0, addr, &val[0], 2, true);

            current_page = page;
            return 0;
        }
        return -1;
    }
    else
    {
        //we are already on the page we need 
        return 0;
    }
}

void RGB7Seg::unlock()
{
    uint8_t addr = address;
    uint8_t val[2]; 
    val[0] = 0xFE;
	val[1] = 0xC5;
	i2c_write_blocking(i2c0, addr, &val[0], 2, true);
}

uint8_t RGB7Seg::reset()
{
    this->select_page(4);
    uint8_t addr = address;
    uint8_t val[2]; 
	val[0] = 0x3F;
	val[1] = 0xAE;
	i2c_write_blocking(i2c0, addr, &val[0], 2, true);
    return 1;
}

void RGB7Seg::enable()
{
    this->select_page(4);
    uint8_t addr = address;
    uint8_t val[2]; 
    val[0] = 0x00;
	val[1] = 0x01;
	i2c_write_blocking(i2c0, addr, &val[0], 2, true);
}

void RGB7Seg::set_current(uint8_t current)
{
    this->select_page(4);
    uint8_t addr = address;
    uint8_t val[2]; 
    val[0] = 0x01;
	val[1] = current;
	i2c_write_blocking(i2c0, addr, &val[0], 2, true);
}

uint8_t RGB7Seg::get_current()
{
    this->select_page(4);
    uint8_t addr = address;
    uint8_t val[2]; 
	uint8_t rxdata[2];
	val[0] = 0x01;

	i2c_write_blocking(i2c0, addr, &val[0], 1, true);
	i2c_read_blocking(i2c0, addr, &rxdata[0], 1, true);

    return rxdata[0];
}

void RGB7Seg::set_scaling()
{
    this->select_page(2);
    uint8_t addr = address;
    uint8_t val[2]; 

	for( int x = 0; x<0xB4; x++){
		val[0] = x;
		val[1] = 0xFF;
		i2c_write_blocking(i2c0, addr, &val[0], 2, true);
	}

    this->select_page(3);
    // set pwm for led 0
	for( int x = 0; x<0xAB; x++){
		val[0] = x;
		val[1] = 0xFF;
		i2c_write_blocking(i2c0, addr, &val[0], 2, true);
	}

}

void RGB7Seg::set_LED(int pos, uint8_t value[3])
{
    set_pixel(Led_lookup[pos],value[0]);
    set_pixel(Led_lookup[pos]+1,value[1]);
    set_pixel(Led_lookup[pos]+2,value[2]);
}

void RGB7Seg::set_segment(uint8_t segment, uint8_t digit, uint8_t value[3])
{
    //u_int8_t leds[3] = Led_segments[segment][digit];

    for(int i; i<3; i++){
        if(Led_segments[segment][digit][i] != 0){
            set_LED(Led_segments[segment][digit][i]-1, value);
        }
    }

}

void RGB7Seg::set_pixel(int pos, int value)
{
    uint8_t addr = address;
    uint8_t val[2]; 
    if(pos<0xB4){
        this->select_page(0);
        val[0] = pos;
    }
    else {
        this->select_page(1);
        val[0] = pos - 0xB4;

    }
    if ((pos%3) == 0){value = value/2;}

    val[1] = value;
    i2c_write_blocking(i2c0, addr, &val[0], 2, true);

}

void RGB7Seg::set_digit(uint8_t pos, uint8_t value, uint8_t my_rgb_value[3])
{
    uint8_t rgb_value[3];
    /*
    uint8_t rgb_on[3];
    rgb_on[0]= 0x00;
    rgb_on[1]= 0x00;
    rgb_on[2]= 0xD5; 

    uint8_t rgb_off[3];
    rgb_off[0]= 0x10;
    rgb_off[1]= 0x00;
    rgb_off[2]= 0x00; 

    printf("Pos %i\n", pos);
    for(uint8_t my_seg=0; my_seg<8; my_seg++){
        printf("%i ", Led_digit[value][my_seg]);

        if (Led_digit[value][my_seg]==1){
            set_segment(pos,my_seg,my_rgb_value);
            printf("H ",my_seg);
            //this->set_segment(int(my_seg),int(pos),my_rgb_value);
        }
        else{
            set_segment(pos,my_seg,rgb_off);
            printf("L ",my_seg);
            //this->set_segment(int(my_seg),int(pos),rgb_off);
        }
    }
    printf("\n");
    */

    for(int x=0; x<8; x++ ){
		uint8_t rgb_value[3];
		rgb_value[0]= 0x00;
		rgb_value[1]= 0x00;
		rgb_value[2]= 0x00;
		if (Led_digit[value][x] == 1 ){
			rgb_value[0]= my_rgb_value[0];
	    	rgb_value[1]= my_rgb_value[1];
			rgb_value[2]= my_rgb_value[2];
		}
	    set_segment(0,x,rgb_value);
					
	}

    return;
}	
