#include <stdio.h>
#include <stdlib.h>
#include "Vblinky.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

void tick(int tickcount, Vblinky *tb, VerilatedVcdC* tfp){
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
	Vblinky *tb = new Vblinky;

	unsigned tickcount = 0;

	//generate a trace
	Verilated::debug(0);
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	Verilated::mkdir("logs");
	tb->trace(tfp, 99);
	tfp->open("trace.vcd");


	for(int i=0; i<32000; i++){
		tick(++tickcount, tb, tfp);
	}

	//write the coverage data out
	VerilatedCov::write("logs/coverage.dat");

}
