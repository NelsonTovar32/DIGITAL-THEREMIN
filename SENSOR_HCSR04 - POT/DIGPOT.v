`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    06:10:10 10/05/2015 
// Design Name: 
// Module Name:    DIGPOT 
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
module DIGPOT(
    input cs_in,
	 input clk,
    input [6:0] wp_in,
    output reg cs_o,
    output reg INC,
    output reg U_D
    );
	 
reg [6:0] counter;
reg [6:0] clk_count;





always @(cs_in)
			begin
				if(!cs_in)
					begin
					cs_o=0;
					end
				else if(cs_in)
					begin
					cs_o=1;
					end
			end
			
always @(*)
			begin
				if(wp_in<7'b1100100 && cs_in==0)
				begin
					   if(wp_in>=counter)
						begin
						clk_count=wp_in-counter;
						U_D=1;
						end
						else if(wp_in<counter)
						begin
						clk_count=counter-wp_in;
						U_D=0;
						end
				end
				else if(wp_in>=7'b1100100 && cs_in==0)
				begin
						if(wp_in>=7'b1111111)
						begin
						counter=7'b0000000;
						end
						else if(wp_in>=7'b1111100)
						begin
						counter=7'b1111111;
						end
				end
				
				
			end


			
task pulse;
input clk_in;
input [6:0] num;
output reg out;
begin
if(clk_in==0)
	begin
	out=0;
	end
end
endtask
			
endmodule


