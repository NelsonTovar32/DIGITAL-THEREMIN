//-----------------------------------------------------
// Design Name : Echo_counter
// Description: Contador de tiempo en us.(Microsegundos enteros)
// File Name   : echo_counter.v
//-----------------------------------------------------

module echo_counter(
    input clk_in,
    output reg [15:0] c_out,    input reset,
    input  echo_in );
	 
	 //Internal Registers & Wires
	 reg [15:0] counter;

always @(posedge clk_in)
			begin
				if(reset)
						begin
						counter <= 16'b0;
						end
				else if(echo_in)
						begin
						counter <= counter+1;
						end
				else
					 begin
						counter <= 16'b0;
					 end
			end
			
always @(negedge echo_in)
			begin
				c_out = counter;
			end

endmodule

