`default_nettype none

module rxuart(i_clk, i_uart_rx, o_rx_byte, o_rx_valid);

	//standard value set for 12MHz clock with 115200 baud
	parameter CLKS_PERBAUD = 625;

	input	wire	i_clk;
	input 	wire	i_uart_rx;
	output	[7:0]	o_rx_byte;
	output	wire	o_rx_valid;

	// possible states
	localparam [3:0] IDLE		=	4'h0,
			 START		=	4'h1,
			 DATA_BITS 	=	4'h2,
			 STOP_BIT	=	4'h3,
			 CLEAN_UP	=	4'h4;

	reg	[3:0]	state;
	reg	[31:0]	clock_count;
	reg	[2:0] 	count_bit;
	reg	[7:0]	rx_data;
	reg		valid;

	always @(posedge i_clk)
	begin
		case(state)
			IDLE:
			begin
				//o_rx_byte <= 8'b00000000;
				clock_count <= 0;

				if(i_uart_rx == 1'b0)
					state <= START;
				else
					state <= IDLE;
			end
			START:
			begin
				if(clock_count == (CLKS_PERBAUD-1)/2)
				begin
					if (i_uart_rx == 1'b0)
					begin
						clock_count <= 0;
						count_bit <= 0;
						state <= DATA_BITS;
					end
					else
						state <= IDLE;
				end
				else
					clock_count <= clock_count + 1'b1;

			end
			DATA_BITS:
			begin
				if(clock_count < CLKS_PERBAUD-1)
					clock_count <= clock_count + 1'b1;
				else
				begin
					clock_count <= 0; //reset the clock counter
					rx_data[count_bit] <= i_uart_rx;

					//check if we are at the last bit
					if (count_bit< 7)
					begin
						count_bit <= count_bit + 1'b1;
						state <= DATA_BITS;
					end
					else
					begin
						count_bit <= 3'b000;
						state <= STOP_BIT;
					end
				end
			end
			STOP_BIT:
			begin
				if(clock_count < CLKS_PERBAUD-1)
					clock_count <= clock_count + 1'b1;
				else
				begin
					state <= CLEAN_UP;
					clock_count <= 0;
					//byte = rx_data;
					valid <= 1'b1;
				end
			end
			CLEAN_UP:
			begin
				//o_rx_byte <= 0;
				valid <= 1'b0;
				state <= IDLE;
				rx_data <= 8'b00000000;
			end

			default :
				state <= IDLE;
		endcase
	end

	assign o_rx_byte = rx_data;
	assign o_rx_valid = valid;

endmodule
