module writepixels(clk, valid, value, 
    d_clk, d_out, busy);

    input 	wire 	clk;
	input 	wire 	valid;
	input 	wire    [7:0]	value;

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

    parameter 	WIDTH=8;

    // registers for the system
    reg [2:0]           state = 0;
    reg [2:0]           bit_counter;
    reg [(WIDTH-1):0]   my_value;
    reg [7:0]           counter =0;
    reg sys_clk;
    reg data_out = 1;
    reg data_ready = 1'b0;
    reg clk_out = 1;
	reg busy_out;

    // clock rate for calculating the clock divider
	parameter 	clk_in_rate_hz = 12_000_000;
	parameter	clk_pixel_rate_hz = 1_000_000;
	parameter 	clk_divider_count = (clk_in_rate_hz/clk_pixel_rate_hz);

	//clock divider for setting the rate that the state can change
	always @(posedge clk) begin
		if (counter < (clk_divider_count[8:1]-1) )
			begin
                counter <= counter + 1'b1;
			end
		else
            begin
			    counter <= 0;
			    sys_clk <= ~sys_clk;
			end
	end

    //read in the data from input on valid signal
	always @(posedge clk) begin
		if (valid == 1)
		begin
			my_value <= value;
			data_ready <= 1'b1;
		end

		if (busy_out)
			data_ready <= 1'b0;
	end

    //if our status is not idle, system is busy
    always @(posedge clk) begin
		if (state != IDLE)
			busy_out <= 1'b1;
		else
			busy_out <= 1'b0;
	end

    //state machine for sending values
	always @(posedge sys_clk) begin
		case(state)
			IDLE:
				begin
                    //idle is both clk and data high
                    data_out    <= 1;
                    clk_out     <= 1;

                    //change to start tx if data avalible
                    if (data_ready == 1)
                    begin
                        state <= START;
                    end
                end
            START:
				begin
                    state <= DATA_1;

                    // set data and clk to indicate the start
                    data_out    <= 0;
                    clk_out     <= 1;

                    //initalise the bit counter
                    bit_counter <= 0;
                end
            DATA_1:
				begin
                    state <= DATA_2;

                    data_out <= my_value[bit_counter];
                    clk_out <= 0;
                end
            DATA_2:
				begin
                    state <= DATA_3;

                    data_out <= my_value[bit_counter];
                    clk_out <= 1;
                end
            DATA_3:
				begin
                    state <= DATA_4;
                    data_out <= my_value[bit_counter];
                    clk_out <= 1;
                end
            DATA_4:
				begin
                    if(bit_counter < 7)
                        begin
                        state <= DATA_1; 
                        bit_counter <= bit_counter + 1 ;
                        end
                    else
                        begin
                        state <= FINISH;
                        bit_counter <= 0;
                        end

                    data_out <= my_value[bit_counter];
                    clk_out <= 0;
                end
            FINISH:
				begin
                    // set data to indicate end of bits to be written 
                    data_out    <= 0;
                    clk_out     <= 1;
                    // the next state is Idle
                    state <= IDLE;
                end
    
        endcase
    end

    assign d_out = data_out;
    assign d_clk = clk_out;
    assign busy = busy_out;

endmodule
