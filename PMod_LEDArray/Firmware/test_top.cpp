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
/*
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
*/
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


	for(int i=0; i<8192; i++){
		tick(++tickcount, tb, tfp);
		if(tickcount==16){
			tb->RX = 1;
		}
		else {
			tb->RX = 0;
		}
	}

	Verilated::mkdir("logs");
	VerilatedCov::write("logs/coverage.dat");

}
