`timescale 1ns / 1ps

module DECtoBIN(
    input [31:0] in,
	 
	 output reg [3:0] un,de,ce,mi
    );
	 
reg [31:0] x;

always @(*)
			begin
			x=(in*10)/58;
			un=x%10;
			de=(x/10)%10;
			ce=(x/100)%10;
			mi=(x/1000)%10;
			end
	
endmodule

