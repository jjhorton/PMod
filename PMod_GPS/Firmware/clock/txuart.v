`default_nettype none

module txuart(i_clk, i_wr, i_data, o_uart_tx,o_busy);

	parameter	CLOCKS_PERBAUD = 217;

	// inputs to the system
	input	wire		i_clk;
	input	wire		i_wr;
	input 	wire	[7:0]	i_data;

	// output of the system
	output	wire		o_uart_tx;
	output	reg		o_busy;

	// State machine states
	//
	localparam [3:0] START 	= 4'h0,
		/*BIT_ZERO	= 4'h1,
		BIT_ONE		= 4'h2,
		BIT_TWO		= 4'h3,
		BIT_THREE	= 4'h4,
		BIT_FOUR	= 4'h5,
		BIT_FIVE	= 4'h6,
		BIT_SIX		= 4'h7,
		BIT_SEVEN	= 4'h8,*/
		LAST		= 4'h8,
		IDLE		= 4'hf;

	// local registers
	// Used to sort the internal data

	reg	[31:0]	counter;
	reg	[3:0]	state;
	reg	[8:0] 	lcl_data;
	reg		baud_stb;

	// busy output
	//
	initial o_busy = 1'b0;
	initial state  =  IDLE;

	always @(posedge i_clk)
		if((i_wr)&&(!o_busy))
			// Start a new byte, state START=0
			{ o_busy , state } <= { 1'b1 , START };
		else if (baud_stb)
		begin
			if (state == IDLE) //Stay in the idel state
				{ o_busy, state } <= { 1'b0, IDLE };
			else if (state < LAST) begin
				o_busy <= 1'b1;
				state <= state + 1;
			end else // wait for IDLE
				{ o_busy, state } <= {1'b1, IDLE};
		end

	// lcl_data
	//
	// This is where we sort a local copy of our data that is read in

	initial lcl_data = 9'h1ff;
	always @(posedge i_clk)
		if ((i_wr)&&(!o_busy))
			lcl_data <= { i_data, 1'b0 };
		else if (baud_stb)
			lcl_data <= { 1'b1, lcl_data[8:1] };


	//o_uart_tx
	//
	//This is the serial output which is being set

	assign o_uart_tx = lcl_data[0];

	// baud counter
	//

	initial baud_stb = 1'b1;
	initial counter = 0;

	always @(posedge i_clk)
		if ((i_wr)&&(!o_busy))
		begin
			counter <= CLOCKS_PERBAUD - 1'b1;
			baud_stb <= 1'b0;
		end else if(!baud_stb)
		begin
			counter <= counter - 1'b1;
			baud_stb <= (counter == 32'h01);

		end else if (state != IDLE)
		begin
			counter <= CLOCKS_PERBAUD - 1'b1;
			baud_stb <= 1'b0;
		end


endmodule
