module top (CLK,o_PMOD1A, o_PMOD1B, RX);

	input  	wire 	CLK;
	input 	wire 	RX;

	output 	wire 	[7:0]	o_PMOD1A;
	output 	wire 	[7:0]	o_PMOD1B;


	reg [7:0] pmod1a;
	reg [7:0] pmod1b = 8'b00000000;
	reg 		busy;
	reg 		valid;
	reg [27:0] counter;
	reg [3:0] pixel_count = 4'b0000;

	reg [3:0] rx_count = 4'b0000;

	reg [7:0]	rx_byte;
	reg 		rx_valid;


	reg [7:0] r_value [0:9];
	reg [7:0] g_value [0:9];
	reg [7:0] b_value [0:9];

	initial begin
		r_value[0][7:0] = 8'b00000000;
		r_value[1][7:0] = 8'b01000000;
		r_value[2][7:0] = 8'b00100000;
		r_value[3][7:0] = 8'b00000000;
		r_value[4][7:0] = 8'b00000000;
		r_value[5][7:0] = 8'b00000000;
		r_value[6][7:0] = 8'b00000000;
		r_value[7][7:0] = 8'b00000000;
		r_value[8][7:0] = 8'b00000000;
		r_value[9][7:0] = 8'b00001000;

		g_value[0][7:0] = 8'b01000000;
		g_value[1][7:0] = 8'b00000000;
		g_value[2][7:0] = 8'b00100000;
		g_value[3][7:0] = 8'b00000000;
		g_value[4][7:0] = 8'b00000000;
		g_value[5][7:0] = 8'b00000000;
		g_value[6][7:0] = 8'b00000000;
		g_value[7][7:0] = 8'b00000000;
		g_value[8][7:0] = 8'b00000000;
		g_value[9][7:0] = 8'b00001000;

		b_value[0][7:0] = 8'b00000000;
		b_value[1][7:0] = 8'b00000000;
		b_value[2][7:0] = 8'b00000000;
		b_value[3][7:0] = 8'b00000010;
		b_value[4][7:0] = 8'b00000100;
		b_value[5][7:0] = 8'b00001000;
		b_value[6][7:0] = 8'b00010000;
		b_value[7][7:0] = 8'b00100000;
		b_value[8][7:0] = 8'b01000000;
		b_value[9][7:0] = 8'b10000000;

	end

	always @(posedge CLK) begin
		pmod1a[7:1] = 7'b0000000;
	end

	always @(posedge CLK) begin
		if (counter[20] == 1'b1)
			begin
			if ((busy == 1'b0)&(valid == 1'b0))
				begin
					if (pixel_count > (10-1))
					begin
						pixel_count <= 0;
						counter <= 0;
					end
					else
					begin
						valid <= 1'b1;
						pixel_count <= pixel_count + 1'b1;
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

	//Read in the serial values and write them to the LED's in order
	always @(posedge CLK) begin
		if (rx_valid == 1'b1)
			begin
				if (rx_count == 0)
					r_value[0][7:0] <= rx_byte[7:0];
				if (rx_count == 1)
					b_value[0][7:0] <= rx_byte[7:0];
				if (rx_count == 2)
					g_value[0][7:0] <= rx_byte[7:0];

				if (rx_count < 2)
					rx_count <= rx_count + 1'b1;
				else
					rx_count <= 4'b0000;

			end
	end

	writepixel writepixel(CLK ,valid,
					r_value[pixel_count-1][7:0],  //Red
					g_value[pixel_count-1][7:0],  //Green
					b_value[pixel_count-1][7:0],  //Blue
					pmod1a[0],
					busy);

	//Serial RX receiver
	rxuart rxuart(CLK, RX, rx_byte, rx_valid);


	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1b;

endmodule
