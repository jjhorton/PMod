module top (
	CLK,
	o_PMOD1A, o_PMOD1B
);

	input  	wire 	CLK;

	output 	wire 	[7:0]	o_PMOD1A;
	output 	wire 	[7:0]	o_PMOD1B;


	reg [7:0] pmod1a;
	reg [7:0] pmod1b = 8'b00000000;
	reg 		busy;
	reg 		valid;
	reg [27:0] counter;


	always @(posedge CLK) begin
		if (counter[20] == 1'b1)
			begin
			valid <= 1'b1;
			counter <= 0;
			end
		else
			begin
			if (~busy)
				counter <= counter + 1'b1;
			end

		if (busy == 1'b1)
			valid <= 1'b0;

	end

	writepixel writepixel(CLK ,valid,
					8'b00000000,
					8'b00000000,
					8'b10000000,
					pmod1a[0],
					busy);

	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1b;

endmodule
