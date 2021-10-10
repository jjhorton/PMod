#include <stdio.h>
#include <stdlib.h>
#include "Vwritepixel.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

void tick(int tickcount, Vwritepixel *tb, VerilatedVcdC* tfp){
	tb->eval();

	if(tfp)
		tfp->dump(tickcount * 10-2);

	tb->clk = 1;
	tb->eval();
	if(tfp)
		tfp->dump(tickcount * 10);

	tb->clk = 0;
	tb->eval();
	if (tfp) {
		tfp->dump(tickcount * 10 + 5);
		tfp->flush();
	}
}

int main(int argc, char **argv){
	Verilated::commandArgs(argc, argv);

	// Instantiate the design
	Vwritepixel *tb = new Vwritepixel;

	unsigned tickcount = 0;

	//generate a trace
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("trace.vcd");

	//copy the data
	tb->pixel_r =  int8_t(255);
	tb->pixel_g = int8_t(0);
	tb->pixel_b = int8_t(0);
	tb->valid = 1;

	for(int i=0; i<2000; i++){
		if(i==1000) {
			tb->pixel_b =  int8_t(255);
			tb->valid = 1;
		}

		tick(++tickcount, tb, tfp);
		tb->valid = 0;

	}
}
