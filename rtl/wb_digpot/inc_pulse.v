`timescale 1ns / 1ps

module inc_pulse(
    input clk_in,
	 input [6:0] num,
	 input reset,
    output  clk_out,
	 output reg dp_busy,
	 output reg dp_cyc0,
	 output reg dp_cyc1
	 );
	 
	 //Internal Registers & Wires
	 parameter k_en=8'b01101110;
	 reg stop =1'b0;
	 reg ena =1'b0;
	 reg [6:0] counter=7'b0;
	 reg [7:0] counter_en1=8'b0;
	   
	 wire clk_a = ena & clk_in & ~stop;

	 assign clk_out = ~clk_a & ena & dp_busy;
	 	 
always @(negedge clk_in or negedge ena)
			begin
				if(!ena)
					 begin
					 counter<=7'b0; 
					 dp_busy <= 1'b1;
					 stop <= 1'b0;
					 end
				else if(counter>=num[6:0])
						begin
						counter<=7'b0;
						dp_busy <= 1'b0;
						stop <=1'b1;
						end
				else
					 begin
						 if(num[6:0]==7'b0) begin
						 counter<=7'b0;
						 end
						 else begin
						 counter<=counter+1;
						 end
					 end
			end

always @(negedge dp_busy or posedge clk_in)
			begin
				if(clk_in)
					begin
					dp_cyc0 = 1'b0;
					dp_cyc1 = 1'b0;
						if(counter_en1>=k_en)begin
						ena <=1'b0;
						counter_en1<=7'b0;
						end
						else begin
						ena <=1'b1;
						counter_en1<=counter_en1+1;
						end
					end
				else
					begin
					dp_cyc0 =1'b1;
					dp_cyc1 =1'b1;
					end
			end

endmodule


