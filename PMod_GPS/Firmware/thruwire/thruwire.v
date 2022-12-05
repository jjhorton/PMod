module thruwire(clk, in_tx, in_rx, pmod_tx, pmod_rx, pps, ledr, ledg);
	input clk;
	input in_rx;
	output in_tx;

	input pmod_rx;
	output pmod_tx;

	input pps;

	output ledr;
	output ledg;

	reg led;
	always @(posedge clk)
		led <= !led;

	assign ledg = led;

	assign pmod_tx = in_rx;
	assign in_tx = pmod_rx;
	assign ledr = !pps;
	
endmodule
