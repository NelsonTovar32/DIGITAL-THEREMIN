`timescale 1ns / 1ps

module Contador(
    input reset,
	 input clock,
	 output reg [3:0] num, output reg cry	 
	 );

initial
begin
num=4'd0;
cry=1'b0;
end
		 always @(posedge clock or posedge reset)
			begin
				if(reset)
					begin
					num=4'b0000;
					end
				else if(num<4'b1001)
						begin
						num=num+1;
						cry=1'b0;
						end
				else if(num>=4'b1001)
						begin
						num=4'b0000;
						cry=1'b1;
						end
			end
endmodule

//Prueba git...x+1=x+2=x+3
