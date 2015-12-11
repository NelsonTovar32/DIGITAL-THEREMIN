//////////////////////////////////////////////////////////////////////
////                                                              ////
////                   DIGITAL - THEREMIN                         ////
////                         main.c                               ////
////                                                              ////
////  Este archivo hace parte del trabajo realizado para el       ////
////  proyecto de curso de Electronica Digital II		  ////
////  Universidad Nacional de Colombia - 2015 -2        	  ////
////                                                              ////
////  Autores:                                                    ////
////    *Nelson Leonardo Tovar (nltovar@unal.edu.co)		  ////
////    *Manuel Alejandro Barreto (mabarretor@unal.edu.co)        ////
////    *Daniel Camilo Beltrán (dcbeltrans@unal.edu.co)           ////
////                                                              ////
////  Información adicional en: 				  ////
////  https://sites.google.com/site/edigital2unal/proyectos/      ////
////  	     proyectosii-015/grupo02                              ////
////                                                              ////
//////////////////////////////////////////////////////////////////////

#include "soc-hw.h"

//********************************************************************************************
// Funciones Volumen - Potenciometro
//********************************************************************************************

uint8_t vsig_pot(uint16_t tvol, uint8_t vm)
{
    uint16_t tmax=4000; //4ms - 4000ns - 70 cms aprox
    uint16_t mdiv7=872; //Pent(tmax/7)
    if(tvol>=300 && tvol<(mdiv7)){if(vm==0){return 0;}else if(vm>0){return vm;}}
    else if(tvol>=mdiv7 && tvol<(mdiv7*2)){if(vm<=15){return 15;}else if(vm>15){return vm;}}
    else if(tvol>=(mdiv7*2) && tvol<(mdiv7*3)){if(vm<=30){return 30;}else if(vm>30){return vm;}}
    else if(tvol>=(mdiv7*3) && tvol<(mdiv7*4)){if(vm<=45){return 45;}else if(vm>45){return vm;}}
    else if(tvol>=(mdiv7*4) && tvol<(mdiv7*5)){if(vm<=60){return 60;}else if(vm>60){return vm;}}
    else if(tvol>=(mdiv7*5) && tvol<(mdiv7*6)){if(vm<=75){return 75;}else if(vm>75){return vm;}}
    else if(tvol>=(mdiv7*6) && tvol<(mdiv7*7)){if(vm<=99){return 99;}else if(vm>99){return vm;}}
    else {return vm;}
}

void volumen(uint8_t va, uint8_t vs)
{
    int r1=va-vs;
    int r2=vs-va;
    uint32_t set=0;

    if(r1<0)
        {
            set=r2+128-1;
            set_digpot(set);
        }
    else if(r1>0)
        {
            set=r1-1;
            set_digpot(set);
        }
    else if(r1==0){;}
}

//**************************************************************************************************
// Función principal del codigo - Inicialización de Perifericos
//**************************************************************************************************

uint8_t sel_nota(uint32_t dist, uint8_t mode)
{
    uint16_t mdiv7;
    if(mode==1)
        {
            mdiv7=2000; //(4000/7)
                if(dist>=300 && dist<(mdiv7)){return 1;}//Do4}
                else if(dist>=mdiv7 && dist<(mdiv7*2)){return 2;}//Re4}
                else if(dist>=(mdiv7*2) && dist<(mdiv7*3)){return 3;}//Mi4}
                else if(dist>=(mdiv7*3) && dist<(mdiv7*4)){return 4;}//Fa4}
                else if(dist>=(mdiv7*4) && dist<(mdiv7*5)){return 5;}//Sol4}
                else if(dist>=(mdiv7*5) && dist<(mdiv7*6)){return 6;}//La4}
                else if(dist>=(mdiv7*6) && dist<(mdiv7*7)){return 7;}//Si4}
                else {return 0;}
        }
    else if(mode==2)
        {
            mdiv7=658; //(5000/14)
                if(dist>=300 && dist<(mdiv7)){return 1;}//Do4}
                else if(dist>=mdiv7 && dist<(mdiv7*2)){return 2;}//Re4}
                else if(dist>=(mdiv7*2) && dist<(mdiv7*3)){return 3;}//Mi4}
                else if(dist>=(mdiv7*3) && dist<(mdiv7*4)){return 4;}//Fa4}
                else if(dist>=(mdiv7*4) && dist<(mdiv7*5)){return 5;}//Sol4}
                else if(dist>=(mdiv7*5) && dist<(mdiv7*6)){return 6;}//La4}
                else if(dist>=(mdiv7*6) && dist<(mdiv7*7)){return 7;}//Si4}
                else if(dist>=(mdiv7*7) && dist<(mdiv7*8)){return 8;}//Do5}
                else if(dist>=(mdiv7*8) && dist<(mdiv7*9)){return 9;}//Re5}
                else if(dist>=(mdiv7*9) && dist<(mdiv7*10)){return 10;}//Mi5}
                else if(dist>=(mdiv7*10) && dist<(mdiv7*11)){return 11;}//Fa5}
                else if(dist>=(mdiv7*11) && dist<(mdiv7*12)){return 12;}//Sol5}
                else if(dist>=(mdiv7*12) && dist<(mdiv7*13)){return 13;}//La5}
                else if(dist>=(mdiv7*13) && dist<(mdiv7*14)){return 14;}//Si5}
                else {return 0;}
        }
}


int main()
{

    //Declaracion de variables:

	uint8_t j, i, l, k, va, v, vs, vol;
	uint32_t rc_nota, rc_vol;
 	uint16_t boton;
	uint8_t note;

        uint32_t t2, c1;
        uint16_t b1, b2, b3, b4;
	uint8_t c2, c3, c4, c5, c6, valor;
	
    


	//Inicializacion de perifericos

	gpio_init(0x01); //9BITS  6 ENTRADAS(BOTONES) 3 SALIDAS(2 LEDS Y PWM) PIN1:PWM - PIN2:MODO - PIN3: LEDBLANCO
	v=1; //Volumen actual
	vol=0;
	for(;;)
	{
		rc_vol=read_count1(); //Obtiene el valor de tiempo de lectura del sensor de volumen
		vs=vsig_pot(rc_vol, vol); //Calcula el valor siguiente del potenciometro
		volumen(va, vs); //Asigna el potenciometro al valor siguiente
		va=vs; //Actualiza el valor presente

	
		c1 = read_count0();
		c6 = sel_nota(c1,v);	
	
		if (c6 == 1){b1 = 180; b3 = 0; c3 = 118; c2 = 20987;
		for (i=1; i<10;i++)
	    	{
	        	b2 = b1+76;

			for (j=75; j<b2; j++)			
		        {
		            c4 = j*c3;
		            c5 = c2-c4;
		 
		            set_pin(1,1);			
	   	            nsleep(c4);
			    set_pin(0,1);
			    nsleep(c5);
		        }
             }
	}
		
        else if (c6 == 2){b1 = 162; b3 = 18; c3 = 130; c2 = 20987;
	for (i=1; i<10;i++)
    	{
		b2 = b1+76;

		for (j=75; j<b2; j++)			
		{
		    c4 = j*c3;
		    c5 = c2-c4;
	 
		    set_pin(1,1);			
		    nsleep(c4);
		    set_pin(0,1);
		    nsleep(c5);
		}
	}
    }

	else if (c6 == 3){b1 = 144; b3 = 36; c3 = 146; c2 = 20741;
	for (i=1; i<10;i++)
	{
		b2 = b1+76;

	        for (j=75; j<b2; j++)			
                {
                    c4 = j*c3;
                    c5 = c2-c4;
	 
                    set_pin(1,1);			
   	            nsleep(c4);
	            set_pin(0,1);
	            nsleep(c5);
                }
	}
    }
	
	else if (c6 == 4){b1 = 138; b3 = 42; c3 = 150; c2 = 20741;
	for (i=1; i<10;i++)
	{
		b2 = b1+76;

	        for (j=75; j<b2; j++)			
                {
                    c4 = j*c3;
                    c5 = c2-c4;
	 
                    set_pin(1,1);			
   	            nsleep(c4);
	            set_pin(0,1);
	            nsleep(c5);
                }
            }
	}

	else if (c6 == 5){b1 = 124; b3 = 56; c3 = 166; c2 = 20741;
	for (i=1; i<10;i++)
	{
	        b2 = b1+76;

	        for (j=75; j<b2; j++)			
                {
                    c4 = j*c3;
                    c5 = c2-c4;
	 
                    set_pin(1,1);			
   	            nsleep(c4);
	            set_pin(0,1);
	            nsleep(c5);
                }
            }
	}
	
	else if (c6 == 6){b1 = 112; b3 = 68; c3 = 181; c2 = 20495;
	for (i=1; i<10;i++)
	{
		b2 = b1+76;

	        for (j=75; j<b2; j++)			
                {
                    c4 = j*c3;
                    c5 = c2-c4;
	 
                    set_pin(1,1);			
   	            nsleep(c4);
	            set_pin(0,1);
	            nsleep(c5);
                }
            }
	}

	else if (c6 == 7){b1 = 100; b3 = 80; c3 = 202; c2 = 20495;
	for (i=1; i<10;i++)
	{
		b2 = b1+76;

	        for (j=75; j<b2; j++)			
                {
                    c4 = j*c3;
                    c5 = c2-c4;
	 
                    set_pin(1,1);			
   	            nsleep(c4);
	            set_pin(0,1);
	            nsleep(c5);
                }
            }
	}
	else if(c6==0){msleep(100);}
    
    }

}


