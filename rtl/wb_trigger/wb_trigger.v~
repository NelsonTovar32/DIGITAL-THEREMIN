//---------------------------------------------------------------------------
// Wishbone Trigger 
//
// Register Description:
//
//    0x00 Set_Trig      [ clr | t_sel1 | t_sel2 ]
//
//
//---------------------------------------------------------------------------

module wb_trigger
(
	input              clk,
	input              reset,
	// Wishbone interface
	input              wb_stb_i,
	input              wb_cyc_i,
	output             wb_ack_o,
	input              wb_we_i,
	input       [31:0] wb_adr_i,
	input        [3:0] wb_sel_i,
	input       [31:0] wb_dat_i,
	output reg  [31:0] wb_dat_o,
	// Trigger Wires
	output		   trig_o
);

//---------------------------------------------------------------------------
// Actual TRIGGER engine
//---------------------------------------------------------------------------

reg [3:0]  t_sel1;
reg [3:0]  t_sel2;
reg [8:0] set_trig;

trigger_top trigger0(
	.clk( clk ),
	.reset( reset ),
	.t_sel1( t_sel1 ),
	.t_sel2( t_sel2 ),
	.clr( set_trig[8] ),
	.trig_o( trig_o)
);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------


wire wb_wr = wb_stb_i & wb_cyc_i &  wb_we_i;

reg  ack;

assign wb_ack_o       = wb_stb_i & wb_cyc_i & ack;


always @(posedge clk)
begin
	if (reset) 
		begin
		wb_dat_o[31:8] <= 24'b0;
		end 
	else 
		begin
		wb_dat_o[31:8] <= 24'b0;
		ack    <= 0;
		if (wb_wr & ~ack ) 
			begin
			ack <= 1;
			if (wb_adr_i[3:2] == 2'b01) 
				begin
				set_trig <= wb_dat_i[8:0];
				end
			end
		end
end


endmodule

