`timescale 1ms / 100us

module clk_simple(clk,clk_out);
    input clk;
    output reg clk_out;
    reg rst;
    reg [25:0] counter;
	 parameter k=26'd10000000;
	 //Se ajusta el parametro para el valor de salida
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


