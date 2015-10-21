`timescale 1ns / 1ps

module LOGIC(
    input clk_in, echo_in,
	 input clear,
	 //input [7:0] sw,
	 output [3:0] anodo,
	 output [6:0] ssegm,
	 //output [1:0] lds,
	 output trigger_out
	 );

wire a,b,c,s0,s1;
wire [3:0]u,d,ce,m;
wire [3:0]k;
wire [31:0] num;

clk_simple #(1249999) clk_1(clk_in,a); //20 HZ: 1249999- 50ms , 1249999....5Hz 4999999   24999999
clk_simple #(499) clk_2(clk_in,b); //100kHz - 10us ok
clk_simple #(24) clk_3(clk_in,c); //1MHz - 1us

clk_simple #(99999) clk_s0(clk_in,s0); //250 Hz

clk_simple #(199999) clk_s1(clk_in,s1); //125 Hz

trigger_pulse(a,b,clear,trigger_out);

HCSR04(echo_in,c,num);

//leds(num,sw,lds);

DECtoBIN(num,u,d,ce,m);

mux41 mux1(u,d,ce,m,s0,s1,k);

BCDtoSSEG btss_1(k,ssegm);

demux14 demux_anodo(s0,s1,anodo);



endmodule

