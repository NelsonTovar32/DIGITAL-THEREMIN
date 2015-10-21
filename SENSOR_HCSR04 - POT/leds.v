`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:06:31 09/18/2015 
// Design Name: 
// Module Name:    leds 
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
module leds(
    input [31:0] in,
	 input [7:0] com,
	 output reg  [1:0] ld
    );

reg [31:0] x;	 
always @(*)
			begin
			x<=(in*10)/58;
			if(x>com)
			begin
			ld=2'b01;
			end
			else
			begin
			ld=2'b10;
			end
			end
	
endmodule



