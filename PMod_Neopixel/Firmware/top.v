module top (CLK,o_PMOD1A, o_PMOD1B, RX);

	input  	wire 	CLK;
	input 	wire 	RX;

	output 	wire 	[7:0]	o_PMOD1A;
	output 	wire 	[7:0]	o_PMOD1B;

	parameter 	WIDTH=24;

	reg [7:0] pmod1a;
	reg [7:0] pmod1b;
	wire 		busy;
	reg 		valid;
	reg [WIDTH:0] counter;
	reg [3:0] pixel_count = 4'b0000;

	reg [3:0] rx_count = 4'b0000;
	reg [3:0] led_count = 4'b0000;

	wire [7:0]	rx_byte;
	wire 		rx_valid;
	
	wire        pixel_tx;


	reg [7:0] r_value [9:0];
	reg [7:0] g_value [9:0];
	reg [7:0] b_value [9:0];
	
	reg [7:0] r_value_tx;
	reg [7:0] g_value_tx;
	reg [7:0] b_value_tx;

	initial begin
		r_value[0] = 8'b11111111;
		r_value[1] = 8'b01000000;
		r_value[2] = 8'b00100000;
		r_value[3] = 8'b00010000;
		r_value[4] = 8'b00001000;
		r_value[5] = 8'b00000100;
		r_value[6] = 8'b00000010;
		r_value[7] = 8'b00000001;
		r_value[8] = 8'b00000000;
		r_value[9] = 8'b00001000;

		g_value[0] = 8'b01000000;
		g_value[1] = 8'b00000000;
		g_value[2] = 8'b00100000;
		g_value[3] = 8'b00000000;
		g_value[4] = 8'b00000000;
		g_value[5] = 8'b00000000;
		g_value[6] = 8'b00000000;
		g_value[7] = 8'b00000000;
		g_value[8] = 8'b00000000;
		g_value[9] = 8'b00001000;

		b_value[0] = 8'b00000000;
		b_value[1] = 8'b00000000;
		b_value[2] = 8'b00000000;
		b_value[3] = 8'b00000010;
		b_value[4] = 8'b00000100;
		b_value[5] = 8'b00001000;
		b_value[6] = 8'b00010000;
		b_value[7] = 8'b00100000;
		b_value[8] = 8'b01000000;
		b_value[9] = 8'b10000000;

	end
	
		
	writepixel writepixel(CLK ,valid,
					r_value_tx,  //Red
					g_value_tx,  //Green
					b_value_tx,  //Blue
					pixel_tx,
					busy);

	//Serial RX receiver
	rxuart rxuart(CLK, RX, rx_byte, rx_valid);

	always @(posedge CLK) begin
		if (counter[WIDTH-1] == 1'b1)
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
						r_value_tx <= r_value[pixel_count];
						g_value_tx <= g_value[pixel_count];
						b_value_tx <= b_value[pixel_count];
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
					r_value[led_count][7:0] <= rx_byte[7:0];
				if (rx_count == 1)
					b_value[led_count][7:0] <= rx_byte[7:0];
				if (rx_count == 2)
					g_value[led_count][7:0] <= rx_byte[7:0];

				if (rx_count < 2)
					rx_count <= rx_count + 1'b1;
				else
					begin
						rx_count <= 4'b0000;
						if (led_count < 9)
							led_count <= led_count + 1'b1;
						else
							led_count <= 0;
					end
			end
			
		pmod1a[3] <= 1'b0;
        pmod1a[0] <= pixel_tx;
        pmod1a[1] <= valid;
        pmod1a[2] <= busy;
        
        pmod1b[7:0] <= r_value[pixel_count]; 
        pmod1a[7:4] <= pixel_count;
    
	end



	//pmod1a[7:1] = 7'b0000000;
    //pmod1a[0] = pixel_tx;
    
	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1b;

endmodule
