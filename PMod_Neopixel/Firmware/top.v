module top (
	input  CLK,

	output P1A1, P1A2, P1A3, P1A4, P1A5, P1A6, P1A7, P1A8,
	output P1B1, P1B2, P1B3, P1B4, P1B5, P1B6, P1B7, P1B8
);

	reg [7:0] pmod1a = 8'b00000000;
	reg [7:0] pmod1b = 8'b00000000;

	always @(posedge CLK) begin
		pmod1a <= pmod1a + 8'b00000001;
		pmod1b <= pmod1b + 8'b00000001;
	end


	assign {P1A1, P1A2, P1A3, P1A4, P1A5, P1A6, P1A7, P1A8} = pmod1a;
	assign {P1B1, P1B2, P1B3, P1B4, P1B5, P1B6, P1B7, P1B8} = pmod1b;

endmodule
