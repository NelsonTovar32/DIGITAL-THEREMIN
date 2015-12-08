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
// Función de lectura de SPI, lectura de GPIO, y envío de información por UART
//********************************************************************************************

/*
void midi(int cs)
{
	uint32_t b[80], max=0;
	int i, sel_p, nota;
	uint8_t c3;

	for (i=0;i<=79;i++) // Captura de información proveniente de ADC en vector de 80 posiciones
	{
		b[i]=spi_readByte(cs);
	        nsleep(100);
	}
	for (i=0;i<=79;i++) // Busqueda del valor maximo de la señal recibida, determina el velocity en el mensaje MIDI
	{
		if(b[i] > max)

		max=b[i];

	}
	c3 = gpio_read(); // Lectura de GPIO para determinación de c3umento musical

// El controlador cuenta con dos modos: 1) Modo Bateria, 2) Modo General MIDI

// El Modo Bateria asigna el canal 10 para el envío de información y sonidos de bateria
// El modo General MIDI asigna el canal 1 para el envío de información y notas musicales de la octava 3
// Para ambos modos se utiliza una funciónde corrección que permite ajustar la sensibilidad de los piezoelectricos (i.e. max=max*k)

} */

/*
	if c3 > 127)
	{
		if (cs==1)
		{
		 sel_p = 35; // Bombo
		 max=max*4;
		}
		if (cs==2)
		{
	 sel_p = 38; // Redoblante
		max=max*4;
		}
		if (cs==4)
		{
		 sel_p = 49; // Hi-Hat
		 max=max*4;
		}
		if (cs==8)
		{
		 sel_p = 42; // Crash
		max=max*12;
		}
		if (max>127)
		{
		max=127;
		}

// El mensaje MIDI cuenta con dos partes: 1)Mensaje de activación de nota, 2) Mensaje de descativación de nota

		//Mensaje de activación de nota
		uart_putchar(153); //Activacion de nota por canal 10
		uart_putchar(sel_p); // Selección de sección de bateria (bombo, redoblante, platillo, etc)
		uart_putchar(max); //Velocity del golpe
		msleep(20);
		// Mensaje de desactivacion de nota
		uart_putchar(137); //Activacion de nota pr canal 10
		uart_putchar(sel_p); // Selección de sección de bateria
		uart_putchar(0); //Velocity del golpe
	}
	if (c3 <= 127) // Indica que es un c3umento General MIDI (Envio por el canal 1) - Notas de la octava 3
	{
		if (cs==1)
		{
		 nota = 72; // DO
		 max=max*4;
		}
		if (cs==2)
		{
		 nota = 74; // RE
		 max=max*4;
		}
		if (cs==4)
		{
		 nota = 76; // MI
		max=max*4;
		}
		if (cs==8)
		{
		 nota = 77; // FA
		max=max*12;
		}
		if (max>127)
		{
		max=127;
		}
	
*/

//**************************************************************************************************
// Función principal del codigo - Inicialización de SPI y lectura //
//**************************************************************************************************

int main()
{
	//uint32_t a1, a2, a3, a4; // Cuatro esclavos (ADC) son seleccionados

	uint8_t j, i, l, k;

	uint32_t rc, t2;

 	uint16_t b1, b2, b3, b4;

	uint8_t c1, c2, c3, c4, c5, p, valor;
	

	
gpio_init(0x01);

//rc=0;
//t2=0x024;
//trigger_set(t2);
//set_digpot(0x64);
//msleep(5000);

p = 1;


//for(;;){

    valor=gpio0->read;
    valor=valor>>1;    

    //rc = read_count();
    
    /*
    set_digpot(0xB2);
    
    msleep(5000);

    set_digpot(0x14);
    */

    //if(valor==1){set_pin(1,1);}
    //else {set_pin(0,1);}
    //msleep(10);
    
//}



    if (p == 1)				//selección tercera octava 
    {	
        
	for (l = 0; l < 14; l++)
	{
	    //c1 = 6+(l*10);		//Escala a una octava (7)	     
	    c1 = 4+(l*6);		//Escala a dos octavas (14)
	    msleep(1000);	
	
	if (c1 > 2 && c1 < 8){b1 = 180; c3 = 118; c2 = 20987;}		//selección de la nota dependiendo la distancia
        else if (c1 > 8 && c1 < 14){b1 = 162; c3 = 130; c2 = 20987;}
	else if (c1 > 14 && c1 < 20){b1 = 144; c3 = 146; c2 = 20741;}
	else if (c1 > 20 && c1 < 26){b1 = 138; c3 = 150; c2 = 20741;}
	else if (c1 > 26 && c1 < 32){b1 = 124; c3 = 166; c2 = 20741;}
	else if (c1 > 32 && c1 < 38){b1 = 112; c3 = 181; c2 = 20495;}
        else if (c1 > 38 && c1 < 44){b1 = 100; c3 = 202; c2 = 20495;}
	else if (c1 > 44 && c1 < 50){b1 = 90; c3 = 236; c2 = 20987;}
        else if (c1 > 50 && c1 < 56){b1 = 81; c3 = 260; c2 = 20987;}
	else if (c1 > 56 && c1 < 62){b1 = 72; c3 = 293; c2 = 20741;}
	else if (c1 > 62 && c1 < 68){b1 = 69; c3 = 301; c2 = 20741;}
	else if (c1 > 68 && c1 < 74){b1 = 62; c3 = 332; c2 = 20741;}
	else if (c1 > 74 && c1 < 80){b1 = 56; c3 = 362; c2 = 20495;}
        else if (c1 > 80 && c1 < 86){b1 = 50; c3 = 405; c2 = 20495;}
    
    	for (i=0; i<63;i++)
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
}

/*
gpio_init(0x01);
c2=0x002;
trigger_set(c2);

msleep(1000);
set_digpot(0x64);

c3=counter();


for(;;)
{
	valor=gpio0->read;
	valor=valor>>1;
	if(valor==1)
	{
		trigger_set(0x13);
		pin_inv(1);
		msleep(2000);
	}
	else if(valor==2)
	{
		trigger_set(0x001);		
		pin_inv(1);
		msleep(200);
	}
	else if(valor==4)
	{
		trigger_set(0x28);
		pin_inv(1);
		msleep(5000);
	}
	else
	{
		pin_inv(1);
		msleep(500);
	}

}

*/


/*for (;;)
{
	c1=gpio0->read;
	c1=c1>4;
	if(c1==0x10 && !c2==0x00F)	
	{
		c2=c2+1;
		trigger_set(c2);
	}
	else if(c1=0x20 && !c2==0x002)
	{
		c2=c2-1;
		trigger_set(c2);
	}
	
	if(c1==0x40)
	{
		set_pin(1,5);		
		msleep(2000);		
		pin_inv(5);		
	}
	else if (c1=0x80)
	{
		set_pin(1,5);		
		msleep(500);
		pin_inv(5);
	}	
}

*/




/*

	spi_init(255); // Constante de división para generación de reloj del SPI - Freq(sclk)=192KHz
	for(;;)
	{	nsleep(100);
		//Ciclo de Lectura de SPI para los cuatro esclavos
		//Si el valor de lectura equivale a un valor decimal mayor a 5 (aproximadamente 65mV)
		//Se ingresa a la función MIDI para captura de información, analisis, y envío.

		for (j=0;j<=3;j++)
		{
			if(j==0)
			{
				a1=spi_readByte(1);
				if(a1>5)
				midi(1);
			}
			if(j==1)
			{
				a2=spi_readByte(2);
				if(a2>5)
				midi(2);
			}

			if(j==2)
			{
				a3=spi_readByte(4);
				if(a3>5)
				midi(4);
			}

			if(j==3)
			{
				a4=spi_readByte(8);
				if(a4>5)
				midi(8);
			}



		}

}

*/


