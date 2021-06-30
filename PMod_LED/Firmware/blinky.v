`default_nettype none

module blinky(CLK, LED);
	input 	wire 			CLK;
	output 	wire 	[7:0]	LED;

	parameter 	WIDTH=25;

	reg 	[WIDTH-1:0]		counter;
	reg 	[7:0]			display;

	initial counter = 0;
	initial display = 8'b00000001;

	always @(posedge CLK)
	begin
		counter <= counter +1'b1;

		if (counter[WIDTH-1] == 1)
		begin
			// When the counter reaches top value shift the LEd accross one
			counter <= 0;
			if (display== 8'b10000000)
				display <= 8'b00000001;
			else
				display <= display << 1;
		end
	end

	assign LED = display;
endmodule
