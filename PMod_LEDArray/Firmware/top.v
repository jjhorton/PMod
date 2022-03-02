module top (CLK, RX, o_PMOD1A, o_PMOD1B);

    input   wire    CLK;
	input 	wire 	RX;

	output 	wire 	[7:0]	o_PMOD1A;
	output 	wire 	[7:0]	o_PMOD1B;


    reg [7:0] value = 8'b11001010;
	reg [7:0] pmod1a;
	reg [7:0] pmod1b = 8'b00000000;
    reg valid = 1'b1;
    reg busy;

    writepixels writepixels(CLK ,RX, value[7:0], pmod1a[0], pmod1a[2], busy);

    assign pmod1a[7:3] = 5'b00000;
    assign pmod1a[1] = 0;

	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1b;

endmodule
