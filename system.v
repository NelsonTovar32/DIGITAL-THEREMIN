//---------------------------------------------------------------------------
// LatticeMico32 System On A Chip
//
// Top Level Design for the Nexys3 
//---------------------------------------------------------------------------

module system
#(
	parameter   bootram_file     = "../firmware/hw-test/image.ram",
        //parameter   bootram_file     = "../firmware/timer-test/image.ram",
        //parameter   bootram_file     = "../firmware/digpot_test/image.ram",
	//parameter   bootram_file     = "../firmware/pwm_test/image.ram",
	//parameter   bootram_file     = "../firmware/pwm_sensor_test/image.ram",

	parameter   clk_freq         = 100000000,
        //parameter   clk_freq       = 50000000,
	parameter   uart_baud_rate   = 1152000
) (
	input             clk,
	// Debug 
	output            led,
	input             rst,
	// GPIO
	//input [7:0]	 gpio_ik,
	//output [7:0]	 gpio_ok,
	inout [8:0] gpio_io,
	
	// DIGPOT
	output 		  digpot_INC,
	output		  digpot_UDn,
	output            digpot_CSn,
	// TRIGGER-ECHO 0 NOTA
	output		  trigger_o0,
	input		  echo_in0,
	// TRIGGER-ECHO 1 VOLUMEN
	output		  trigger_o1,
	input		  echo_in1
	
);


wire sys_clk = clk;
wire sys_clk_n = ~clk;


	
//------------------------------------------------------------------
// Whishbone Wires
//------------------------------------------------------------------
wire         gnd   =  1'b0;
wire   [3:0] gnd4  =  4'h0;
wire  [31:0] gnd32 = 32'h00000000;

 
wire [31:0]  lm32i_adr,
             lm32d_adr,
//             timer1_adr,
             spi0_adr,
             i2c0_adr,
             timer0_adr,
             gpio0_adr,
             ddr0_adr,
             bram0_adr,
             sram0_adr,
	     trigger0_adr,
	     trigger1_adr,
	     digpot0_adr;


wire [31:0]  lm32i_dat_r,
             lm32i_dat_w,
             lm32d_dat_r,
             lm32d_dat_w,
//	     timer1_dat_r,
//           timer1_dat_w,
             spi0_dat_r,
             spi0_dat_w,
             i2c0_dat_r,
             i2c0_dat_w,
             timer0_dat_r,
             timer0_dat_w,
             gpio0_dat_r,
             gpio0_dat_w,
             bram0_dat_r,
             bram0_dat_w,
             sram0_dat_w,
             sram0_dat_r,
             ddr0_dat_w,
             ddr0_dat_r,
	     trigger0_dat_w,
	     trigger0_dat_r,
	     trigger1_dat_w,
	     trigger1_dat_r,
	     digpot0_dat_w,
 	     digpot0_dat_r;

wire [3:0]   lm32i_sel,
             lm32d_sel,
//             timer1_sel,
             spi0_sel,
             i2c0_sel,
             timer0_sel,
             gpio0_sel,
             bram0_sel,
             sram0_sel,
             ddr0_sel,
	     trigger0_sel,
	     trigger1_sel,
	     digpot0_sel;


wire         lm32i_we,
             lm32d_we,
//             timer1_we,
             spi0_we,
             i2c0_we,
             timer0_we,
             gpio0_we,
             bram0_we,
             sram0_we,
             ddr0_we,
	     trigger0_we,
	     trigger1_we,
	     digpot0_we;


wire         lm32i_cyc,
             lm32d_cyc,
//             timer1_cyc,
             spi0_cyc,
             i2c0_cyc,
             timer0_cyc,
             gpio0_cyc,
             bram0_cyc,
             sram0_cyc,
             ddr0_cyc,
	     trigger0_cyc,
	     trigger1_cyc,
	     digpot0_cyc;


wire         lm32i_stb,
             lm32d_stb,
//             timer1_stb,
             spi0_stb,
             i2c0_stb,
             timer0_stb,
             gpio0_stb,
             bram0_stb,
             sram0_stb,
             ddr0_stb,
	     trigger0_stb,
	     trigger1_stb,
	     digpot0_stb;

wire         lm32i_ack,
             lm32d_ack,
//             timer1_ack,
             spi0_ack,
             i2c0_ack,
             timer0_ack,
             gpio0_ack,
             bram0_ack,
             sram0_ack,
             ddr0_ack,
	     trigger0_ack,
	     trigger1_ack,
	     digpot0_ack;


wire         lm32i_rty,
             lm32d_rty;

wire         lm32i_err,
             lm32d_err;

wire         lm32i_lock,
             lm32d_lock;

wire [2:0]   lm32i_cti,
             lm32d_cti;

wire [1:0]   lm32i_bte,
             lm32d_bte;

//---------------------------------------------------------------------------
// Interrupts
//---------------------------------------------------------------------------
wire [31:0]  intr_n;
wire         uart0_intr = 0;
wire   [1:0] timer0_intr;
wire         gpio0_intr=0;

assign intr_n = { 28'hFFFFFFF, ~timer0_intr[1], ~gpio0_intr, ~timer0_intr[0], ~uart0_intr };

//---------------------------------------------------------------------------
// Wishbone Interconnect
//---------------------------------------------------------------------------
conbus #(
	.s_addr_w(3),
	.s0_addr(3'b000),	// bram     0x00000000 
//	.s1_addr(3'b010),	// timer1   0x10000000 
	.s1_addr(3'b010),	// timer    0x20000000 
	.s2_addr(3'b011),   	// gpio     0x30000000 
	.s3_addr(3'b100),	// digpot   0x40000000 
	.s4_addr(3'b101),	// trigger0  0x50000000 
        .s5_addr(3'b110)	// trigger1  0x60000000 
) conbus0(
	.sys_clk( clk ),
	.sys_rst( rst ),
	// Master0
	.m0_dat_i(  lm32i_dat_w  ),
	.m0_dat_o(  lm32i_dat_r  ),
	.m0_adr_i(  lm32i_adr    ),
	.m0_we_i (  lm32i_we     ),
	.m0_sel_i(  lm32i_sel    ),
	.m0_cyc_i(  lm32i_cyc    ),
	.m0_stb_i(  lm32i_stb    ),
	.m0_ack_o(  lm32i_ack    ),
	// Master1
	.m1_dat_i(  lm32d_dat_w  ),
	.m1_dat_o(  lm32d_dat_r  ),
	.m1_adr_i(  lm32d_adr    ),
	.m1_we_i (  lm32d_we     ),
	.m1_sel_i(  lm32d_sel    ),
	.m1_cyc_i(  lm32d_cyc    ),
	.m1_stb_i(  lm32d_stb    ),
	.m1_ack_o(  lm32d_ack    ),

	// Slave0  bram
	.s0_dat_i(  bram0_dat_r ),
	.s0_dat_o(  bram0_dat_w ),
	.s0_adr_o(  bram0_adr   ),
	.s0_sel_o(  bram0_sel   ),
	.s0_we_o(   bram0_we    ),
	.s0_cyc_o(  bram0_cyc   ),
	.s0_stb_o(  bram0_stb   ),
	.s0_ack_i(  bram0_ack   ),
/*	// Slave1  timer1
	.s1_dat_i(  timer1_dat_r ),
	.s1_dat_o(  timer1_dat_w ),
	.s1_adr_o(  timer1_adr   ),
	.s1_sel_o(  timer1_sel   ),
	.s1_we_o(   timer1_we    ),
	.s1_cyc_o(  timer1_cyc   ),
	.s1_stb_o(  timer1_stb   ),
	.s1_ack_i(  timer1_ack   ), */
	// Slave1  timer
	.s1_dat_i(  timer0_dat_r ),
	.s1_dat_o(  timer0_dat_w ),
	.s1_adr_o(  timer0_adr   ),
	.s1_sel_o(  timer0_sel   ),
	.s1_we_o(   timer0_we    ),
	.s1_cyc_o(  timer0_cyc   ),
	.s1_stb_o(  timer0_stb   ),
	.s1_ack_i(  timer0_ack   ),
	// Slave2  gpio
	.s2_dat_i(  gpio0_dat_r ),
	.s2_dat_o(  gpio0_dat_w ),
	.s2_adr_o(  gpio0_adr   ),
	.s2_sel_o(  gpio0_sel   ),
	.s2_we_o(   gpio0_we    ),
	.s2_cyc_o(  gpio0_cyc   ),
	.s2_stb_o(  gpio0_stb   ),
	.s2_ack_i(  gpio0_ack   ),
	// Slave3  digpot
	.s3_dat_i(  digpot0_dat_r ),
	.s3_dat_o(  digpot0_dat_w ),
	.s3_adr_o(  digpot0_adr   ),
	.s3_sel_o(  digpot0_sel   ),
	.s3_we_o(   digpot0_we    ),
	.s3_cyc_o(  digpot0_cyc   ),
	.s3_stb_o(  digpot0_stb   ),
	.s3_ack_i(  digpot0_ack   ),
	// Slave4   trigger0
	.s4_dat_i(  trigger0_dat_r ),
	.s4_dat_o(  trigger0_dat_w ),
	.s4_adr_o(  trigger0_adr   ),
	.s4_sel_o(  trigger0_sel   ),
	.s4_we_o(   trigger0_we    ),
	.s4_cyc_o(  trigger0_cyc   ),
	.s4_stb_o(  trigger0_stb   ),
	.s4_ack_i(  trigger0_ack   ),
	// Slave5   trigger1
	.s5_dat_i(  trigger1_dat_r ),
	.s5_dat_o(  trigger1_dat_w ),
	.s5_adr_o(  trigger1_adr   ),
	.s5_sel_o(  trigger1_sel   ),
	.s5_we_o(   trigger1_we    ),
	.s5_cyc_o(  trigger1_cyc   ),
	.s5_stb_o(  trigger1_stb   ),
	.s5_ack_i(  trigger1_ack   )
	
);


//---------------------------------------------------------------------------
// LM32 CPU 
//---------------------------------------------------------------------------
lm32_cpu lm0 (
	.clk_i(  clk  ),
	.rst_i(  rst  ),
	.interrupt_n(  intr_n  ),
	//
	.I_ADR_O(  lm32i_adr    ),
	.I_DAT_I(  lm32i_dat_r  ),
	.I_DAT_O(  lm32i_dat_w  ),
	.I_SEL_O(  lm32i_sel    ),
	.I_CYC_O(  lm32i_cyc    ),
	.I_STB_O(  lm32i_stb    ),
	.I_ACK_I(  lm32i_ack    ),
	.I_WE_O (  lm32i_we     ),
	.I_CTI_O(  lm32i_cti    ),
	.I_LOCK_O( lm32i_lock   ),
	.I_BTE_O(  lm32i_bte    ),
	.I_ERR_I(  lm32i_err    ),
	.I_RTY_I(  lm32i_rty    ),
	//
	.D_ADR_O(  lm32d_adr    ),
	.D_DAT_I(  lm32d_dat_r  ),
	.D_DAT_O(  lm32d_dat_w  ),
	.D_SEL_O(  lm32d_sel    ),
	.D_CYC_O(  lm32d_cyc    ),
	.D_STB_O(  lm32d_stb    ),
	.D_ACK_I(  lm32d_ack    ),
	.D_WE_O (  lm32d_we     ),
	.D_CTI_O(  lm32d_cti    ),
	.D_LOCK_O( lm32d_lock   ),
	.D_BTE_O(  lm32d_bte    ),
	.D_ERR_I(  lm32d_err    ),
	.D_RTY_I(  lm32d_rty    )
);
	
//---------------------------------------------------------------------------
// Block RAM  SLAVE0
//---------------------------------------------------------------------------
wb_bram #(
	.adr_width( 12 ),
	.mem_file_name( bootram_file )
) bram0 (
	.clk_i(  clk  ),
	.rst_i(  rst  ),
	//
	.wb_adr_i(  bram0_adr    ),
	.wb_dat_o(  bram0_dat_r  ),
	.wb_dat_i(  bram0_dat_w  ),
	.wb_sel_i(  bram0_sel    ),
	.wb_stb_i(  bram0_stb    ),
	.wb_cyc_i(  bram0_cyc    ),
	.wb_ack_o(  bram0_ack    ),
	.wb_we_i(   bram0_we     )
);



//---------------------------------------------------------------------------
// Block DIGPOT SLAVE3
//---------------------------------------------------------------------------
wire digpot0_INC;
wire digpot0_UDn;
wire digpot0_CSn;

wb_digpot digpot0 (
	.clk( clk ),
	.reset( rst ),
	//
	.wb_adr_i( digpot0_adr ),
	.wb_dat_i( digpot0_dat_w ),
	.wb_dat_o( digpot0_dat_r ),
	.wb_stb_i( digpot0_stb ),
	.wb_cyc_i( digpot0_cyc ),
	.wb_we_i(  digpot0_we ),
	.wb_sel_i( digpot0_sel ),
	.wb_ack_o( digpot0_ack ), 

	.INC_o( digpot0_INC ),
	.UDn_o( digpot0_UDn ),
	.CSn_o( digpot0_CSn )
);

//---------------------------------------------------------------------------
// Block TIMER0 SLAVE1
//---------------------------------------------------------------------------
wb_timer #(
	.clk_freq(   clk_freq  )
) timer0 (
	.clk(      clk          ),
	.reset(    rst          ),
	//
	.wb_adr_i( timer0_adr   ),
	.wb_dat_i( timer0_dat_w ),
	.wb_dat_o( timer0_dat_r ),
	.wb_stb_i( timer0_stb   ),
	.wb_cyc_i( timer0_cyc   ),
	.wb_we_i(  timer0_we    ),
	.wb_sel_i( timer0_sel   ),
	.wb_ack_o( timer0_ack   ), 
	.intr(     timer0_intr  )
);

//---------------------------------------------------------------------------
// Block General Purpose IO1 SLAVE2
//---------------------------------------------------------------------------

wire [8:0] gpio0_io;
//wire       gpio0_irq;

wb_gpio gpio0 (
	.clk(      clk          ),
	.rst(    rst          ),
	//
	.wb_adr_i( gpio0_adr    ),
	.wb_dat_i( gpio0_dat_w  ),
	.wb_dat_o( gpio0_dat_r  ),
	.wb_stb_i( gpio0_stb    ),
	.wb_cyc_i( gpio0_cyc    ),
	.wb_we_i(  gpio0_we     ),
	.wb_ack_o( gpio0_ack    ), 
	// GPIO
	.gpio_io(gpio0_io)
);
//---------------------------------------------------------------------------
// Block trigger0  SLAVE4
//---------------------------------------------------------------------------
wire trig0_o;
wire echo0_i;

wb_trigger trigger_0 (
	.clk( clk ),
	.reset( rst ),
	//
	.wb_adr_i( trigger0_adr ),
	.wb_dat_i( trigger0_dat_w ),
	.wb_dat_o( trigger0_dat_r ),
	.wb_stb_i( trigger0_stb ),
	.wb_cyc_i( trigger0_cyc ),
	.wb_we_i(  trigger0_we ),
	.wb_sel_i( trigger0_sel ),
	.wb_ack_o( trigger0_ack ), 

	.trig_o( trig0_o ),
	.echo_i( echo0_i )

);
//---------------------------------------------------------------------------
// Block trigger1  SLAVE5
//---------------------------------------------------------------------------
wire trig1_o;
wire echo1_i;

wb_trigger trigger_1 (
	.clk( clk ),
	.reset( rst ),
	//
	.wb_adr_i( trigger1_adr ),
	.wb_dat_i( trigger1_dat_w ),
	.wb_dat_o( trigger1_dat_r ),
	.wb_stb_i( trigger1_stb ),
	.wb_cyc_i( trigger1_cyc ),
	.wb_we_i(  trigger1_we ),
	.wb_sel_i( trigger1_sel ),
	.wb_ack_o( trigger1_ack ), 

	.trig_o( trig1_o ),
	.echo_i( echo1_i )

);




//----------------------------------------------------------------------------
// Mux UART wires according to sw[0]
//----------------------------------------------------------------------------

assign digpot_INC = digpot0_INC;
assign digpot_UDn = digpot0_UDn;
assign digpot_CSn = digpot0_CSn;

assign trigger_o0 = trig0_o;
assign echo0_i = echo_in0;

assign trigger_o1 = trig1_o;
assign echo1_i = echo_in1;

assign gpio_io= gpio0_io;

endmodule 
