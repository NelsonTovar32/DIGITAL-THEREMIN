//---------------------------------------------------------------------------
// Wishbone Trigger-Echo
//
// Register Description: WriteCycle
//
//    0x00 Set_Trig      [ clr | t_sel1 | t_sel2 ]
//
// Register Description: ReadCycle
//
//    0x01 c_out      Counter of 16Bits
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
	// Trigger-Echo Wires
	output		   trig_o,
	input		   echo_i
);

//---------------------------------------------------------------------------
// Actual TRIGGER-ECHO engine
//---------------------------------------------------------------------------


reg [8:0] set_trig= 9'b000000010;
wire [15:0] c_out;

trigger_top trigger0(
	.clk( clk ),
	.reset( reset ),
	.t_sel1( set_trig[3:0] ),
	.t_sel2( set_trig[7:4] ),
	.clr( set_trig[8] ),
	.trig_o( trig_o)
);

echo_top echo0(
	.clk( clk ),
	.reset( reset ),
	.echo_in( echo_i ),
	.c_out( c_out )
);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------


wire wb_wr = wb_stb_i & wb_cyc_i &  wb_we_i;
wire wb_rd = wb_stb_i & wb_cyc_i & ~wb_we_i;

reg  ack;

assign wb_ack_o = wb_stb_i & wb_cyc_i & ack;


always @(posedge clk)
begin
	if (reset) 
		begin
		wb_dat_o[31:16] <= 16'b0;
		end 
	else 
		begin
		wb_dat_o[31:16] <= 16'b0;
		ack    <= 0;
		if (wb_wr & ~ack )  //Write cycle: Ajuste de trigger
			begin
			ack <= 1;
			if (wb_adr_i[2] == 1'b0) 
				begin
				set_trig <= wb_dat_i[8:0];
				end
			end

		else if (wb_rd & ~ack) //Read cycle: Lectura de contador
			begin
			ack <= 1;
			case(wb_adr_i[3:2])
          		2'b01:begin  
			    wb_dat_o[31:16]<=0;
			    wb_dat_o[15:0] <= c_out;
			      end
          		 default: wb_dat_o <= 32'b100; 
        		endcase
			end
		end
end


endmodule

