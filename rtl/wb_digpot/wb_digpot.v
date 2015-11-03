`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Modulo DIGITAL-POT
//////////////////////////////////////////////////////////////////////////////////
module wb_digpot(
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
	// DigPot Wires
	output    	   INC_o, //Salida de Incremento	
	output		   UDn_o, //Salida de direccion de incremento
	output		   CSn_o //Activación del dispositivo
);

//---------------------------------------------------------------------------
// Actual DigPot engine
//---------------------------------------------------------------------------

wire dp_cyc0, dp_cyc1, dp_busy, clk_out0;

reg [7:0] set_digpot= 8'b00000000; //Primer bit indica el sentido de movimiento Wiper: 0-Abajo, 1-Arriba
											  //Ultimos 7 bits indican el numero de pasos del wiper
reg [7:0] default0 = 8'b00000000;

div_frec divider0(
	.clk( clk ),
	.clk_out( clk_out0 )
);


inc_pulse inc_pulse0(
	.clk_in( clk_out0 ),
	.reset( reset ),
	.num( set_digpot[6:0] ),
	.dp_cyc0( dp_cyc0 ),
	.dp_cyc1( dp_cyc1 ),
	.dp_busy( dp_busy ),
	.clk_out( INC_o )
);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------


wire wb_wr = wb_stb_i & wb_cyc_i &  wb_we_i;
wire cycle = ~(dp_cyc0 | dp_busy);

reg  ack;

assign wb_ack_o  = wb_stb_i & wb_cyc_i & ack;

assign UDn_o = set_digpot[7];
assign CSn_o = 1'b0;


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
			if (wb_adr_i[2] == 1'b0 & cycle) 
				begin
				set_digpot <= wb_dat_i[7:0];
				end
			end
		end
		
		if (dp_cyc1) 
			begin
				set_digpot <= default0;
			end
end

endmodule

