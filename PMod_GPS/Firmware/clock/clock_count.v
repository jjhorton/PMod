module clock_count(clk, in_tx, in_rx, pmod_tx, pmod_rx, pps, ledr, ledg);
	input clk;
	input in_rx;
	output in_tx;

	input pmod_rx;
	output pmod_tx;

	input pps;

	output ledr;
	output ledg;

	parameter 	CLOCK_PER_SECOND=10_000_000;
	parameter 	WIDTH=32;

	reg last_pps;
	reg [(WIDTH-1):0] clock_counter;
	reg [(WIDTH-1):0] clock_error;

	always @(posedge clk)
	begin
		last_pps <= pps;

		if ((last_pps== 1'b0) && (pps== 1'b1)) 
		begin
			//the rising edge of the 1pps clock
			/* verilator lint_off WIDTH */
			clock_error <= clock_counter - CLOCK_PER_SECOND;
			/* verilator lint_on WIDTH */

			//rest the clock counter
			clock_counter <= 0;
			
		end
		else
		begin
			//count up for each clock cycle
			clock_counter <= clock_counter + 1'b1;
		end



	end

	assign ledg = 1'b1;

	assign pmod_tx = in_rx;
	assign in_tx = pmod_rx;
	assign ledr = !pps;
	
endmodule
