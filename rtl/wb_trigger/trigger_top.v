//-----------------------------------------------------
// Design Name : trigger
// File Name   : trigger.v
//-----------------------------------------------------
module trigger_top
	(
	input           reset,
	input           clk,
	// Lines
	input [3:0]	t_sel1, t_sel2,
	input		clr,
	output		trig_o
	//
	);
wire out1,out2;

div_frec_adj div1(clk,t_sel1,out1);	
div_frec_adj div2(clk,t_sel2,out2);	

trigger_pulse pulse(out1,out2,clr,trig_o);

endmodule
