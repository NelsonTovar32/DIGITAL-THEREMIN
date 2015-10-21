`timescale 1ns / 1ps

//////////////////////////////////////////////////////////////////////////////////
// Engineer: Nelson Tovar
// Create Date:    10:37:03 09/18/2015 
// Module Name:    HCSR04 
// Project Name:   DIGITAL-THEREMIN
//////////////////////////////////////////////////////////////////////////////////

module HCSR04(
   input echo,        //Declaramos la entrada ECHO del sensor
   input clk,        //Declaramos la entrada clk 50MHz
   output reg [31:0] out     //Declaramos la salida outp
   );
 
reg [31:0] stnby;
reg [31:0] stnby2;

initial
begin
out=0;
stnby=0;
stnby2=0;
end
		 always @(posedge clk or negedge echo)
			begin
				if(!echo)
					begin
					stnby<=stnby2;
					out<=stnby2;
					stnby<=0;
					end
				else if(echo)
					begin
					stnby<=stnby+1;
					stnby2<=stnby;
					end
				end
endmodule
