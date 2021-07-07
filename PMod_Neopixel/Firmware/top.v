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
	reg [3:0] pixel_count = 4'b0000;

	always @(posedge CLK) begin
		if (counter[22] == 1'b1)
			begin
			if ((busy == 1'b0)&(valid == 1'b0))
				begin
					pixel_count <= pixel_count + 1'b1;
					valid <= 1'b1;
					if (pixel_count == (10 - 1 ))
					begin
						counter <= 0;
						pixel_count <= 0;
					end
				end
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
					8'b00100000,  //Red
					8'b00000000,  //Green
					8'b00000000,  //Blue
					pmod1a[0],
					busy);

	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1b;

endmodule
