module writepixel(
	clk, valid,
	value, d_clk
	d_out, busy);

    input 	wire 	clk;
	input 	wire 	valid;
	input 	wire [7:0]	value;

    output  wire    d_clk;
    output  wire    d_out;
    output  wire    busy;

    // statemachine states
	parameter 	IDLE 	= 0;
	parameter 	START	= 1;
    parameter   DATA_1  = 2;
    parameter   DATA_2  = 3;
    parameter   DATA_3  = 4;
    parameter   DATA_4  = 5;
    parameter   FINISH  = 6;

    //
    reg [2:0] state = 0;
    reg [2:0] bit_counter;
    reg data_out = 0;
    reg clk_out = 0;
	reg busy_out = 0;

    // clock rate for calculating the clock divider
	parameter 	clk_in_rate_hz = 12_000_000;
	parameter	clk_pixel_rate_hz = 1_000_000;
	parameter 	clk_divider_count = clk_in_rate_hz/(clk_pixel_rate_hz);



    //state machine for sending values
	always @(posedge pixel_clk) begin
		case(state)
			IDLE:
				begin
                    //
                    data_out    <= 1;
                    clk_out     <= 1;
                end
            START:
				begin
                    state <= DATA_2;

                    //initalise the bit counter
                    bit_counter <= 0;
                end
            DATA_1:
				begin
                    state <= DATA_2;

                    data_out <= ;
                    clk_out <= 0;
                end
            DATA_2:
				begin
                    state <= DATA_3;

                    data_out = ;
                    clk_out = 1;
                end
            DATA_3:
				begin
                    state <= DATA_4;
                    
                    bit_counter <= bit_counter + 1 ;
                    data_out = ;
                    clk_out = 1;
                end
            DATA_4:
				begin
                    if(bit_counter < 8)
                        state <= DATA_1; 
                    else
                        state <= FINISH;

                    data_out = ;
                    clk_out = 0;
                end
            FINISH:
				begin
                    // set data to indicate end of bits to be written 
                    data_out    <= 0;
                    clk_out     <= 1;
                    // the next state is Idle
                    state <= IDLE
                end
            

)