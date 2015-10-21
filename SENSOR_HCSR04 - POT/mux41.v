`timescale 1ns / 1ps

module mux41(
    input [3:0] i1,
	 input [3:0] i2,
	 input [3:0] i3,
	 input [3:0] i4,
    input s0,s1,
    output reg[3:0] out
    );
    
always @(i1,i2,i3,i4,s0,s1)
	begin
	
		case({s1,s0})
		2'b00: begin out=i1; end
		2'b01: begin out=i2; end
		2'b10: begin out=i3; end
		2'b11: begin out=i4; end
		endcase
	end
endmodule
