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


	for(int i=0; i<64000; i++){
		tick(++tickcount, tb, tfp);
	}

	Verilated::mkdir("logs");
	VerilatedCov::write("logs/coverage.dat");

}
