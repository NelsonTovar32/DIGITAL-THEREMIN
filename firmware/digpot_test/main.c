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


//**************************************************************************************************
// Función principal del codigo - Inicialización de Perifericos
//**************************************************************************************************

int main()
{

    //Declaracion de variables:

	uint8_t j, i, l, k, va, vs;

    

//Inicializacion de perifericos


set_digpot(0x63); //100K  Ohms
msleep(1000);

for(i=0;i<10;i++)
{
set_digpot(0x89);
msleep(1000);
}



}
