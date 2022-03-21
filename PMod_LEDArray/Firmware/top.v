module top (CLK, o_PMOD1A, o_PMOD1B);

    input   wire    CLK;

	output 	wire 	[7:0]	o_PMOD1A;
	output 	wire 	[7:0]	o_PMOD1B;


    reg [7:0] tx_value [0:15];
	reg [7:0] pmod1a;
	reg [7:0] pmod1b = 8'b00000000;
    reg valid;
    reg [7:0] value;
    reg busy;

    initial begin 
        tx_value[0][7:0]  = 8'b00000110;
        tx_value[1][7:0]  = 8'b01011011;
        tx_value[2][7:0]  = 8'b01001111;
        tx_value[3][7:0]  = 8'b11100110;
        tx_value[4][7:0]  = 8'b01101101;
        tx_value[5][7:0]  = 8'b01111101;
        tx_value[6][7:0]  = 8'b00000111;
        tx_value[7][7:0]  = 8'b01111111;
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
    parameter 	clk_in_rate_hz = 25_000_000;
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

    writepixels writepixels(CLK , pmod1a[6], pmod1a[7], pps);

    assign pmod1a[5:0] = 6'b000000;

	assign o_PMOD1A = pmod1a;
	assign o_PMOD1B = pmod1a;

endmodule
