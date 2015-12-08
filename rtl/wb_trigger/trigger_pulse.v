//-----------------------------------------------------
// Design Name : trigger_pulse
// Description: Generador de estimulo para sensores
// File Name   : trigger_pulse.v
//-----------------------------------------------------
module trigger_pulse(
   input t_long,        //Entrada del pulso de periodo mas largo
   input t_short,       //Entrada del pulso de periodo mas corto
   input clr,           //Clear
   output t_out         //Salida
   );

reg [2:0] delay;     //Declaramos el registro auxiliar de 3 bits delay

always @(posedge t_short or posedge clr)
   if(clr) delay<=0;                   //Si se activa clr el proximo valor de delay sera 0.
   else delay[2:0]<={delay[1:0],t_long};  //de lo contrario el proximo valor de delay[2] sera delay[1]
                                       //el proximo valor de delay[1] sera delay[0] y
                                       //el proximo valor de delay[0] sera imp.

//Si imp permanece activo durante 2 ciclos de reloj outp se activara y en el siguente ciclo se desactivara
assign t_out = delay[0] & delay[1] & ~delay[2];//outp sera 1 si delay[0] y delay[1] son 1 y delay[2] es 0.

endmodule
