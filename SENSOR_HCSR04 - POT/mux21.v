`timescale 1ns / 1ps

module mux21(
    input i1,
	 input i2,
	 input s,
    output reg out
    );
    
always @(*)
	begin
	
		case({s})
		2'b0: begin out=i2; end
		2'b1: begin out=i1; end
		
		endcase
	end
endmodule


