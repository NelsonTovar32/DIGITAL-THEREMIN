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

//********************************************************************************************
// Funciones GPIO
//********************************************************************************************


void ajustment(int *p, int *v, int *m)
{
    uint16_t seteo=0;
    uint8_t aux;
    while(seteo!=PAUSE)
        {
	    set_pin(1,3); //Prender el LED BLANCO
            if(seteo==MODO){
                if(*m==1){*m=2;set_pin(0,2);}
                else if(*m==2){*m=1;set_pin(1,2);}
                            }
            else if(seteo==VOLUP){
                    aux=*v;
                    if(aux>=0 && aux<=60){aux=aux+15;}
                    else if(aux==75){aux=99;}
                    else if(aux==99){;}
                    *v=aux;
                    aux=0;
                                }
            else if(seteo==VOLDW){
                    aux=*v;
                    if(aux==99){aux=75;}
                    else if(aux<=75 && aux>=15){aux=aux-15;}
                    else if(aux==0){;}
                    *v=aux;
                    aux=0;
                                }
            else if(seteo==PITCHUP){
                    aux=*p;
                    if(aux>=0x002 && aux<=0x00E){aux++;}
                    else if(aux==0x00F){;}
                    *p=aux;
                    trigger_set0(aux);
                    aux=0;
                                }
            else if(seteo==PITCHDW){
                    aux=*p;
                    if(aux>0x002 && aux<=0x00F){aux--;}
                    else if(aux==0x002){;}
                    *p=aux;
                    trigger_set0(aux);
                    aux=0;
                                }
            nsleep(2000);        //Para el rebote
            seteo=gpio0->read;
            seteo=seteo>>3;
            nsleep(2000);       //Para el rebote

        }
		set_pin(0,3); //Apagar el LED BLANCO

}

//********************************************************************************************
// Funciones Musicales
//********************************************************************************************



uint8_t sel_nota(uint32_t dist, uint8_t mode)
{
    uint16_t mdiv7;
    if(mode==1)
        {
            mdiv7=872; //(4000/7)
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

uint16_t t_muestra(uint8_t nota)
{
    uint16_t T1=20987;
    uint16_t T2=20741;
    uint16_t T3=20495;

        if(nota==0){return 0;}
        else if(nota==1){return T1;}
        else if(nota==2){return T1;}
        else if(nota==3){return T2;}
        else if(nota==4){return T2;}
        else if(nota==5){return T2;}
        else if(nota==6){return T3;}
        else if(nota==7){return T3;}
        else if(nota==8){return T1;}
        else if(nota==9){return T1;}
        else if(nota==10){return T2;}
        else if(nota==11){return T2;}
        else if(nota==12){return T2;}
        else if(nota==13){return T3;}
        else if(nota==14){return T3;}
}

uint8_t n_muestra(uint8_t nota)
{
        if(nota==0){return 0;}
        else if(nota==1){return 180;}
        else if(nota==2){return 162;}
        else if(nota==3){return 144;}
        else if(nota==4){return 138;}
        else if(nota==5){return 124;}
        else if(nota==6){return 112;}
        else if(nota==7){return 100;}
        else if(nota==8){return 90;}
        else if(nota==9){return 81;}
        else if(nota==10){return 72;}
        else if(nota==11){return 69;}
        else if(nota==12){return 62;}
        else if(nota==13){return 56;}
        else if(nota==14){return 50;}
}

uint16_t step(uint8_t nota) // =t/n muestra
{
        if(nota==0){return 0;}
        else if(nota==1){return 118;}
        else if(nota==2){return 130;}
        else if(nota==3){return 146;}
        else if(nota==4){return 150;}
        else if(nota==5){return 166;}
        else if(nota==6){return 181;}
        else if(nota==7){return 202;}
        else if(nota==8){return 236;}
        else if(nota==9){return 260;}
        else if(nota==10){return 293;}
        else if(nota==11){return 301;}
        else if(nota==12){return 332;}
        else if(nota==13){return 362;}
        else if(nota==14){return 405;}
}

uint8_t time_for(uint8_t nota) //
{
        if(nota==0){return 0;}
        else if(nota==1){return 63;}
        else if(nota==2){return 81;}
        else if(nota==3){return 99;}
        else if(nota==4){return 105;}
        else if(nota==5){return 119;}
        else if(nota==6){return 131;}
        else if(nota==7){return 143;}
        else if(nota==8){return 153;}
        else if(nota==9){return 162;}
        else if(nota==10){return 171;}
        else if(nota==11){return 174;}
        else if(nota==12){return 181;}
        else if(nota==13){return 187;}
        else if(nota==14){return 193;}
}

void play_note(uint8_t n_mt, uint16_t sp, uint16_t t_mt, uint8_t t_f) //mt := muestra ....
{
    uint8_t i;
    uint16_t j;
    for (i=0; i<t_f ;i++)
	    {
	        for (j=75; j<(n_mt+76); j++)			//recorre cada una de las muestras (b1 tercera octava)
                {
                set_pin(1,1);			                    //se asigna el ciclo util por tiempo
   	            nsleep(j*sp);
	            set_pin(0,1);
	            nsleep(t_mt-(j*sp));
                }
        }
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

gpio_init(0x0000001); //9BITS  6 ENTRADAS(BOTONES) 3 SALIDAS(2 LEDS Y PWM) PIN1:PWM - PIN2:MODO - PIN3: LEDBLANCO
set_digpot(0x64); //0  Ohms
va=0; //Volumen actual

for(;;)
{
	b1=gpio0->read;
	b1=b1>>3;
	if(b1==PAUSE)
	{
		trigger_set0(0x02);
	}
	else if(b1==MODO)
	{
		trigger_set0(0x06);
	}
	else if(b1==VOLUP)
	{
		trigger_set0(0x10);
	}
	else if(b1==VOLDW)
	{
		trigger_set0(0x03);
	}
	else if(b1==PITCHUP)
	{
		trigger_set0(0x04);
	}
	else if(b1==PITCHDW)
	{
		trigger_set0(0x05);
	}

}


}


