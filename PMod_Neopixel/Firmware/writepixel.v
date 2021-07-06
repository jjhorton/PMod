module writepixel(
	clk, valid,
	pixel_r, pixel_g, pixel_b,
	d_out, busy);

	input 	wire 	clk;
	input 	wire 	valid;
	input 	wire [7:0]	pixel_r;
	input 	wire	[7:0]	pixel_g;
	input 	wire	[7:0]	pixel_b;

	output 	wire 	d_out;
	output 	wire		busy;

	reg [2:0] state = 0;
	reg [31:0] counter =0;
	reg [4:0] count_bit = 0;
	reg [23:0] my_value = 0;
	reg pixel_clk = 0;
	reg data_out = 0;
	reg busy_out = 0;

	// states for the state machine
	parameter 	IDLE 	= 0;
	parameter 	STATE1	= 1;
	parameter 	STATE2	= 2;
	parameter 	STATE3	= 3;
	parameter 	STATE4	= 4;

	// clock rate for calculating the clock divider
	parameter 	clk_in_rate_hz = 12_000_000;
	parameter		clk_pixel_rate_hz = 2_500_000;
	parameter 	clk_divider_count = clk_in_rate_hz/(clk_pixel_rate_hz);

	//clock divider for setting the rate that the state can change
	always @(posedge clk) begin
		if (counter < clk_divider_count)
			counter <= counter + 1'b1;
		else
			begin
			counter <= 0;
			pixel_clk <= ~pixel_clk;
			end
	end

	// data_ready used to trigger the next bit each time
	reg data_ready = 0;
	//read in the value for the output
	always @(posedge clk) begin
		if (valid == 1)
		begin
			my_value[23:16] <= pixel_g;
			my_value[15:8] <= pixel_r;
			my_value[7:0] <= pixel_b;
			data_ready <= 1'b1;
		end

		if (busy)
			data_ready <= 1'b0;
	end

	//output the ready state, based on the state register
	always @(posedge clk) begin
		if ((state == IDLE)||((state == STATE4)&(count_bit == 0)))
		//if (state == IDLE)
			busy_out <= 1'b0;
		else
			busy_out <= 1'b1;
	end

	//state machine for sending each value
	always @(posedge pixel_clk) begin
		case(state)
			IDLE:
				begin
					if (data_ready == 1)
						state <= STATE1;
						count_bit <= 24;
				end
			STATE1:
				begin
					//first part, always high
					data_out <= 1'b1;
					state <= STATE3;
					count_bit <= count_bit - 1;
				end
			STATE2:
				begin
					//second part, always high
					data_out <= 1'b1;
					state <= STATE3;
				end
			STATE3:
				begin
					// high for a 1, low for 0
					data_out <= my_value [count_bit];
					state <= STATE4;
				end
			STATE4:
				begin
					// alway low
					data_out <= 1'b0;
					if(count_bit == 0)
						state <= IDLE;
					else
						state <= STATE1;
				end
			endcase

		end

		assign d_out = data_out;
		assign busy = busy_out;

endmodule
