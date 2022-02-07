#include <stdio.h>
#include <stdlib.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

void tick(int tickcount, Vtop *tb, VerilatedVcdC* tfp){
	tb->eval();

	if(tfp)
		tfp->dump(tickcount * 10-2);

	tb->CLK = 1;
	tb->eval();
	if(tfp)
		tfp->dump(tickcount * 10);

	tb->CLK = 0;
	tb->eval();
	if (tfp) {
		tfp->dump(tickcount * 10 + 5);
		tfp->flush();
	}
}

int serial_tx(int tick_count, int tick_start, int8_t data_byte, Vtop *tb, VerilatedVcdC* tfp){
	//function for transmitting the serial message 
	int clkperbaud = 625;

	if(tick_count > tick_start){
		//we should be have tx a serial message
		int start_delay = tick_start + (clkperbaud); 
		int bits_completed = (tick_count - start_delay)/clkperbaud;

		if(tick_count < start_delay) {
			tb->RX = 0;
			return 0;
		}
		if (bits_completed < 10) {
			// set RX to be the required data
			tb->RX = ((data_byte>>bits_completed)&1); 
			return 0; 
		}
		else{
			// the message has been sent, idle state
			tb->RX = 1;
			return 1;
		}
	}
	else{
		// we have not got to the point in time when the message should be sent
		tb->RX = 1;
		return 0;
	}

}

int main(int argc, char **argv){
	Verilated::commandArgs(argc, argv);
	// Instantiate the design
	Vtop *tb = new Vtop;

	unsigned tickcount = 0;

	//generate a trace
	Verilated::debug(0);
	Verilated::traceEverOn(true);
	Verilated::mkdir("logs");

	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("trace.vcd");

	uint8_t rgb_values[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12},
		{13,14,15}};

	int increase = 0;
	int rgb = 0; int led = 0; 
	int start = 150;

	for(int i=0; i<250000; i++){
		increase = serial_tx(tickcount, start, rgb_values[led][rgb], tb, tfp);
		tick(++tickcount, tb, tfp);

		if(increase == 1){
			rgb++; 
			if(rgb > 2){
				led++; rgb= 0;
			}
			start = tickcount + 1000;
		}
		
	}

	Verilated::mkdir("logs");
	VerilatedCov::write("logs/coverage.dat");

}
