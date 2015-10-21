`timescale 1ns / 1ps

module demux14(
    	 
    input s0,s1,
    output reg [3:0]o
	 
    );
    
always @(s0,s1)
	begin
	
		case({s1,s0})
		2'b00: begin o[0]=0;o[1]=1;o[2]=1;o[3]=1; end
		2'b01: begin o[1]=0;o[0]=1;o[2]=1;o[3]=1; end
		2'b10: begin o[2]=0;o[0]=1;o[1]=1;o[3]=1; end
		2'b11: begin o[3]=0;o[0]=1;o[1]=1;o[2]=1; end
		endcase
	end
endmodule
