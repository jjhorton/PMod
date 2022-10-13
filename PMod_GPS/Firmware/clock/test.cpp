#include <stdio.h>
#include <stdlib.h>
#include "Vclock_count.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

void tick(int tickcount, Vclock_count *tb, VerilatedVcdC* tfp){
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
	Vclock_count *tb = new Vclock_count;

	unsigned tickcount = 0;

	//generate a trace
	Verilated::debug(0);
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	Verilated::mkdir("logs");
	tb->trace(tfp, 99);
	tfp->open("trace.vcd");


	for(int i=0; i<30; i++){
        tb->pps = 1;
        for(int j=0; j<=(i+3990); j++){
            tick(++tickcount, tb, tfp);
            tb->pps = 0;
        }
		printf("Input cycles %i Error %i\n", (signed char) (i), (signed char) (tb->my_error));
	}

	//write the coverage data out
	VerilatedCov::write("logs/coverage.dat");

}