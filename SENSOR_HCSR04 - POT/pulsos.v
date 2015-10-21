`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:19:28 10/05/2015 
// Design Name: 
// Module Name:    pulsos 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module pulsos(
    input clk,
	 input [6:0] num,
    output reg clk_out);
	 
	 
    
    reg [25:0] counter;
	 

always @(posedge clk or negedge rst)
			begin
				if(!rst)
					 begin
					 rst<=1;
					 counter<=26'd0;
					 clk_out <= 1'b0;
					 end
					else if(counter==k)
						begin
						counter<=26'd0;
						clk_out <= ~clk_out;
						end
					 else
					 begin
					 counter<=counter+1;
					 end
			end

endmodule


