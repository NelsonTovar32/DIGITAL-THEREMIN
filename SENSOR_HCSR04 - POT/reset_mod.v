`timescale 1ns / 1ps

module reset_mod(
	input rst_in,
	output reg a,b,c,d
    );

always @(*)
	begin
	
	case({rst_in})
	1'b0: begin a=1'b0;b=1'b0;c=1'b0;d=1'b0; end
	1'b1: begin	a=1'b1;b=1'b1;c=1'b1;d=1'b1; end
	endcase	
	end
endmodule

