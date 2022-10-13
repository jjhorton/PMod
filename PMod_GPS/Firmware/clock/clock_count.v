`include "txuart.v"

module clock_count(clk, in_tx, in_rx, pmod_tx, pmod_rx, pps, ledr, ledg, my_error);
	input clk;
	input in_rx;
	output in_tx;

	input pmod_rx;
	output pmod_tx;

	input pps;

	output ledr;
	output ledg;

	output [(WIDTH-1):0] my_error;

	parameter 	CLOCK_RATE_HZ = 32'd10_000_000;
	parameter 	BAUD_RATE = 32'd115_200;
	parameter 	CLK_PERBAUD = (CLOCK_RATE_HZ/BAUD_RATE);
	parameter 	CLOCK_PER_SECOND=CLOCK_RATE_HZ;
	parameter 	WIDTH=32;

	reg last_pps;
	reg [(WIDTH-1):0] clock_counter;
	reg [(WIDTH-1):0] clock_error;
	reg data_valid;

	always @(posedge clk)
	begin
		last_pps <= pps;

		if ((last_pps== 1'b0) && (pps== 1'b1)) 
		begin
			//the rising edge of the 1pps clock

			/* verilator lint_off WIDTH */
			clock_error <= clock_counter - CLOCK_PER_SECOND;
			/* verilator lint_on WIDTH */

			data_valid <= 1'b1;
			//rest the clock counter
			clock_counter <= 0;
			
		end
		else
		begin
			//count up for each clock cycle
			clock_counter <= clock_counter + 1'b1;
			data_valid <= 1'b0;
		end



	end

	assign my_error = clock_error;
	assign ledg = 1'b1;

	assign pmod_tx = in_rx;
	//assign in_tx = pmod_rx;
	assign ledr = !pps;

	//prepare the TX data
	reg [7:0] error_char;
	reg uart_busy;
	reg tx_stb;

	always @(posedge clk)
	begin
		tx_stb <= data_valid;
		if (data_valid==1'b1)
		begin
			error_char[7] <= clock_error[(WIDTH-1)];
			error_char[6:0] <= clock_error[6:0]; 
		end
	end

	txuart #(CLK_PERBAUD) transmitter(clk, tx_stb, error_char, in_tx, uart_busy);

endmodule
