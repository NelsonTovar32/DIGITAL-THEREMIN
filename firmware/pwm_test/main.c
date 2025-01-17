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
    uint8_t set=0;

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

int main()
{

    //Declaracion de variables:

	uint8_t j, i, l, k, va, vs;
	uint32_t rc_nota, rc_vol;
 	uint16_t boton;
	uint8_t note;

        uint32_t t2;
        uint16_t b1, b2, b3, b4;
	uint8_t c1, c2, c3, c4, c5, valor;
    


//Inicializacion de perifericos

gpio_init(0x01); //9BITS  6 ENTRADAS(BOTONES) 3 SALIDAS(2 LEDS Y PWM) PIN1:PWM - PIN2:MODO - PIN3: LEDBLANCO
set_digpot(0x64); //0  Ohms
va=0; //Volumen actual



        
	for (l = 1; l < 15; l++)
	{
	    //c1 = 6+(l*10);		//Escala a una octava (7)	     
	   
	    c1 = 4+(l*6);			//Escala a dos octavas (14)
	    msleep(500);
	
	if (c1 > 2 && c1 < 8){b1 = 180; b3 = 0; c3 = 118; c2 = 20987;}		//selección de la nota dependiendo la distancia
        else if (c1 > 8 && c1 < 14){b1 = 162; b3 = 18; c3 = 130; c2 = 20987;}
	else if (c1 > 14 && c1 < 20){b1 = 144; b3 = 36; c3 = 146; c2 = 20741;}
	else if (c1 > 20 && c1 < 26){b1 = 138; b3 = 42; c3 = 150; c2 = 20741;}
	else if (c1 > 26 && c1 < 32){b1 = 124; b3 = 56; c3 = 166; c2 = 20741;}
	else if (c1 > 32 && c1 < 38){b1 = 112; b3 = 68; c3 = 181; c2 = 20495;}
        else if (c1 > 38 && c1 < 44){b1 = 100; b3 = 80; c3 = 202; c2 = 20495;}
	else if (c1 > 44 && c1 < 50){b1 = 90; b3 = 90; c3 = 236; c2 = 20987;}
        else if (c1 > 50 && c1 < 56){b1 = 81; b3 = 99; c3 = 260; c2 = 20987;}
	else if (c1 > 56 && c1 < 62){b1 = 72; b3 = 108; c3 = 293; c2 = 20741;}
	else if (c1 > 62 && c1 < 68){b1 = 69; b3 = 111; c3 = 301; c2 = 20741;}
	else if (c1 > 68 && c1 < 74){b1 = 62; b3 = 118; c3 = 332; c2 = 20741;}
	else if (c1 > 74 && c1 < 80){b1 = 56; b3 = 124; c3 = 362; c2 = 20495;}
        else if (c1 > 80 && c1 < 86){b1 = 50; b3 = 130; c3 = 405; c2 = 20495;}
	
	b4 = 21 + b3;
    
    	for (i=1; i<b4;i++)
	    {
	        b2 = b1+76;

	        for (j=75; j<b2; j++)			//recorre cada una de las muestras (b1 tercera octava)
                {
                    c4 = j*c3;
                    c5 = c2-c4;
	 
                    set_pin(1,1);			//se asigna el ciclo util por tiempo
   	            nsleep(c4);
	            set_pin(0,1);
	            nsleep(c5);
                }
            }
	}
    



}


