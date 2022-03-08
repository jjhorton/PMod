module top (CLK, RX, o_PMOD1A, o_PMOD1B);

    input   wire    CLK;
	input 	wire 	RX;

	output 	wire 	[7:0]	o_PMOD1A;
	output 	wire 	[7:0]	o_PMOD1B;


    reg [7:0] tx_value [0:15];
	reg [7:0] pmod1a;
	reg [7:0] pmod1b = 8'b00000000;
    reg valid;
    reg [7:0] value;
    reg busy;

    initial begin 
        tx_value[0][7:0]  = 8'b11111111;
        tx_value[1][7:0]  = 8'b10011001;
        tx_value[2][7:0]  = 8'b10111101;
        tx_value[3][7:0]  = 8'b10111111;
        tx_value[4][7:0]  = 8'b11111111;
        tx_value[5][7:0]  = 8'b11111111;
        tx_value[6][7:0]  = 8'b11111111;
        tx_value[7][7:0]  = 8'b11111111;
        tx_value[8][7:0]  = 8'b11111111;
        tx_value[9][7:0]  = 8'b10000001;
        tx_value[10][7:0] = 8'b11111011;
        tx_value[11][7:0] = 8'b11111011;
        tx_value[12][7:0] = 8'b11111011;
        tx_value[13][7:0] = 8'b11111011;
        tx_value[14][7:0] = 8'b11000111;
        tx_value[15][7:0] = 8'b11111111;
    end

    // generate one pulse per second to update display on
    parameter 	clk_in_rate_hz = 12_000_000;
    reg [31:0] clk_counter=7900;
    reg pps;

    always @(posedge CLK) begin
        if (clk_counter < clk_in_rate_hz)
            begin
                clk_counter <= clk_counter + 1;
                pps <= 0;
            end
        else
            begin
                clk_counter <= 0;
                pps <= 1;
            end
    end

    // state Machine for setting display
    // State Machine States
    parameter 	IDLE 	    = 0;
	parameter 	INITDISPLAY	= 1;
    parameter 	PAUSE	    = 2;
    parameter 	SETADDR	    = 3;
    parameter 	SETDISPLAY	= 4;

    reg [3:0] byte_count;
    reg [31:0] pause_counter;
    reg [3:0] state;
    reg [7:0] pos = 8'b00000000;

    always @(posedge CLK) begin
		case(state)
			IDLE:
            begin
                if(pps == 1)
                    state <= INITDISPLAY;

                valid <= 0;
            end

            INITDISPLAY:
            begin
                // if the display is not busy set the input
                if((busy == 0) & (valid == 0))
                begin
                    value <= 8'b10001001;
                    valid <= 1;
                    state <= PAUSE;
                    byte_count <= 0;
                    pos <= 8'b11111111;
                end
                else
                    valid <= 0;

                pause_counter <= 0;
            end

            PAUSE:
            begin 
                valid <= 0;
                pause_counter <= pause_counter + 1;
                if(pause_counter < (clk_in_rate_hz/10000) )
                    state <= PAUSE;
                else
                    state <= SETDISPLAY;
            end

            SETADDR:
            begin
                // if the display is not busy set the input
                if((busy == 0) & (valid == 0))
                begin
                    value <= 8'b11000000;
                    valid <= 1;
                    state <= SETDISPLAY;
                end
                else
                    valid <= 0;

            end

            SETDISPLAY:
            begin 
                // if the display is not busy set the input
                if((busy == 0) & (valid == 0))
                begin
                    pos <= 8'b11000000 + byte_count;
                    value <= tx_value[byte_count];
                    valid <= 1;

                    if(byte_count<15)
                    begin
                        state <= SETDISPLAY;
                        byte_count <= byte_count + 1;
                    end
                    else
                        state <= IDLE;
                end
                else
                    valid <= 0;
            end
        endcase
    end

    writepixels writepixels(CLK ,valid, pos, value, pmod1a[6], pmod1a[7], busy);

    assign pmod1a[0] = CLK;
    assign pmod1a[1] = valid;
    assign pmod1a[3:2] = state[1:0];
    assign pmod1a[4] = pps;
    assign pmod1a[5] = busy;

	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1b;

endmodule
