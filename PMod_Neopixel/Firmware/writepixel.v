module writepixel(
	input CLK,
	input value,
	input valid,

	output d_out,
	output ready);

	reg [2:0] state = 0;
	reg [31:0] counter =0;
	reg pixel_clk = 0

	parameter 	clk_in_rate_hz = 12_000_000;
	parameter		clk_pixel_rate_hz = 80_000;
	parameter 	clk_divider_count = clk_in_rate_hz/(clk_pixel_rate_hz);

	//clock deivder for setting the rate that the state can change
	always @(posedge CLK) begin
		if (counter > clk_divider_count)
			counter <= counter + 1;
		else
			counter <= 0;
			pixel_clk <= ~pixel_clk;
	end

	//state machine for sending each value
	always @(posedge CLK) begin

	end


endmodule
