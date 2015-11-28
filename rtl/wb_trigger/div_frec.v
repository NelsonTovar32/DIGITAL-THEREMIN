//-----------------------------------------------------
// Design Name : div_frec
// Description: Divisor de frecuencia
// File Name   : div_frec.v
//-----------------------------------------------------
module div_frec(clk,clk_out);
    
	 input clk;
    output reg clk_out;
	 
	 
	 //Internal Registers & Parameters
    reg rst;
    reg [25:0] counter;
	 //parameter k=26'd49;// 1 us para 100Mhz
	 parameter k=26'd24;// 1 us para 50Mhz
	 
//F_out= (F_in / 2k)

initial
rst=0;

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


