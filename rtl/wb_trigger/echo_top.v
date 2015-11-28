//-----------------------------------------------------
// Design Name : Echo_Top
// File Name   : echo_top.v
//-----------------------------------------------------
module echo_top
	(
	input           reset,
	input           clk,
	// Lines
	input           echo_in,
	output  [15:0] c_out
	//
	);
wire out1,out2;

div_frec div1(clk,out1);	
echo_counter echo_count(out1,c_out,reset,echo_in);

endmodule
