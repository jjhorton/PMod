module writepixel(
	input clk,
	input value,
	input valid,

	output d_out,
	output busy);

	reg [2:0] state = 0;
	reg [31:0] counter =0;
	reg my_value = 0;
	reg pixel_clk = 0;
	reg data_out = 0;
	reg busy_out = 0;

	// states for the state machine
	parameter 	IDLE 	= 0;
	parameter 	STATE1= 1;
	parameter 	STATE2= 2;
	parameter 	STATE3= 3;
	parameter 	STATE4= 4;

	// clock rate for calculating the clock divider
	parameter 	clk_in_rate_hz = 12_000_000;
	parameter		clk_pixel_rate_hz = 80_000;
	parameter 	clk_divider_count = clk_in_rate_hz/(clk_pixel_rate_hz);

	//clock divider for setting the rate that the state can change
	always @(posedge clk) begin
		if (counter > clk_divider_count)
			counter <= counter + 1;
		else
			counter <= 0;
			pixel_clk <= ~pixel_clk;
	end

	// data_ready used to trigger the next bit each time
	reg data_ready = 0;
	//read in the value for the output
	always @(posedge clk) begin
		if (valid == 1)
		begin
			my_value <= value;
			data_ready <= 1'b1;
		end

		if (busy)
			data_ready <= 1'b0;
	end

	//output the ready state, based on the state register
	always @(posedge clk) begin
		if (state == IDLE)
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
				end
			STATE1:
				begin
					//first part, always high
					data_out <= 1'b1;
					state <= STATE2;
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
					data_out <= my_value;
					state <= STATE4;
				end
			STATE4:
				begin
					// alway low
					data_out <= 1'b0;
					state <= IDLE;
				end
			endcase

		end

		assign d_out = data_out;
		assign busy = busy_out;

endmodule
