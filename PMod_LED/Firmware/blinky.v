`default_nettype none

module blinky(CLK, LED);
	input 	wire 					CLK;
	output 	wire 	[7:0]		LED;

	parameter 	WIDTH=27;

	reg 	[WIDTH-1:0]		counter;
	reg 	[7:0]					display;

	initial counter = 0;
	initial display = 8'b00000001;

	always	@(posedge CLK)
	begin
		counter <= counter +1'b1;

		if (counter[WIDTH-1] == 1)
		begin
			// When the counter reaches top value shift the LEd accross one
			counter <= 0;
			display = display << 1;
		end
	end

	assign LED = display;
endmodule
