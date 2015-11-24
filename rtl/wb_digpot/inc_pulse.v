`timescale 1ns / 1ps

module inc_pulse(
    input clk_in,
	 input[6:0] num,
	 input reset,
    output  clk_out,
	 output reg dp_busy
	 );
	 
	 //Internal Registers & Wires
	 reg ena =1'b0;
	 reg busy=1'b0;

	 assign clk_out = clk_in & ena;
	 	 
always @(negedge clk_in)
			begin
				if(num>7'b0 && num<=7'b1100100)
						begin
						busy <= 1'b1;
						ena = 1'b1;
						end
				else if(num==7'b0)
					 begin
						 ena = 1'b0;
						 busy <= 1'b0;
					 end
				else
					 begin
						 busy <= 1'b0;
						 ena = 1'b0;
					 end
			end
			
always @(posedge clk_in)
			begin
				dp_busy = busy;
			end

endmodule

