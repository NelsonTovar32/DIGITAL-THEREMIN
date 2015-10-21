`timescale 1ns / 1ps

module trigger_pulse(
   input inp,        //Declaramos la entrada inp
   input cclk,       //Declaramos la entrada cclk
   input clr,        //Declaramos la entrada 
   output outp       //Declaramos la salida outp
   );

reg [2:0] delay;     //Declaramos el registro auxiliar de 3 bits delay

always @(posedge cclk or posedge clr)
   if(clr) delay<=0;                   //Si se activa clr el proximo valor de delay sera 0.
   else delay[2:0]<={delay[1:0],inp};  //de lo contrario el proximo valor de delay[2] sera delay[1]
                                       //el proximo valor de delay[1] sera delay[0] y
                                       //el proximo valor de delay[0] sera imp.
         
//Si imp permanece activo durante 2 ciclos de reloj outp se activara y en el siguente ciclo se desactivara
assign outp = delay[0] & delay[1] & ~delay[2];//outp sera 1 si delay[0] y delay[1] son 1 y delay[2] es 0.

endmodule
