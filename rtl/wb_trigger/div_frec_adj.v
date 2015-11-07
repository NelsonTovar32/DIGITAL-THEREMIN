`timescale 1ms / 100us

module div_frec_adj(clk,num,clk_out);
    input clk;
	 input [3:0] num;
    output reg clk_out;
    reg rst;
    reg [25:0] counter;
	 //F_out= (F_in / 2p)

integer p=26'd10000000;

initial
rst=0;
	 always @(posedge clk or negedge rst)
			begin
			
			/* //clk 50Mhz
			case (num)
			4'b0000: begin p <= 26'd249; end // 10us
			4'b0001: begin p <= 26'd499; end // 20us
			4'b0010: begin p <= 26'd1249999; end // 50ms
			4'b0011: begin p <= 26'd2499999;end // 100ms 
			4'b0100: begin p <= 26'd3749999; end // 150ms
			4'b0101: begin p <= 26'd4999999; end // 200ms
			4'b0110: begin p <= 26'd6249999; end // 250ms
			4'b0111: begin p <= 26'd7499999; end // 300ms
			4'b1000: begin p <= 26'd8749999; end  // 350ms
			4'b1001: begin p <= 26'd9999999; end // 400ms
			4'b1010: begin p <= 26'd11249999; end  // 450ms
			4'b1011: begin p <= 26'd12499999; end // 500ms
			4'b1100: begin	p <= 26'd13749999; end  // 550ms
			4'b1101: begin	p <= 26'd14999999; end  // 600ms
			4'b1110: begin	p <= 26'd16249999; end  // 650ms
			4'b1111: begin	p <= 26'd17499999; end // 700ms
			default: begin	p <= 26'd1249999;end // 50ms
			endcase
			*/

			//clk 100MHz
			case (num)
			4'b0000: begin p <= 26'd499; end // 10us
			4'b0001: begin p <= 26'd999; end // 20us
			4'b0010: begin p <= 26'd2499999; end // 50ms
			4'b0011: begin p <= 26'd4999999;end // 100ms 
			4'b0100: begin p <= 26'd7499999; end // 150ms
			4'b0101: begin p <= 26'd9999999; end // 200ms
			4'b0110: begin p <= 26'd12499999; end // 250ms
			4'b0111: begin p <= 26'd14999999; end // 300ms
			4'b1000: begin p <= 26'd17499999; end  // 350ms
			4'b1001: begin p <= 26'd19999999; end // 400ms
			4'b1010: begin p <= 26'd22499999; end  // 450ms
			4'b1011: begin p <= 26'd24999999; end // 500ms
			4'b1100: begin p <= 26'd27499999; end  // 550ms
			4'b1101: begin p <= 26'd29999999; end  // 600ms
			4'b1110: begin p <= 26'd32499999; end  // 650ms
			4'b1111: begin p <= 26'd34999999; end // 700ms
			default: begin p <= 26'd2499999;end // 50ms
			endcase
			

		
				if(!rst)
					 begin
					 rst<=1;
					 counter<=26'd0;
					 clk_out <= 1'b0;
					 end
					else if(counter==p)
						begin
						counter<=26'd0;
						clk_out <= ~clk_out;
						end
					 else if(counter>p)
						begin
						counter<=26'd0;
						end
					 else
					 begin
					 counter<=counter+1;
					 end
			end

endmodule
