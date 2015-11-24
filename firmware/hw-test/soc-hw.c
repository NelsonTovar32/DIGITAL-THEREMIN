//////////////////////////////////////////////////////////////////////
////                                                              ////
////                   DIGITAL - THEREMIN                         ////
////                        soc-hw.c                              ////
////                                                              ////
////  Este archivo hace parte del trabajo realizado para el       ////
////  proyecto de curso de Electronica Digital II		          ////
////  Universidad Nacional de Colombia - 2015 -2        		  ////
////                                                              ////
////  Autores:                                                    ////
////    *Nelson Leonardo Tovar (nltovar@unal.edu.co)		      ////
////    *Manuel Alejandro Barreto (mabarretor@unal.edu.co)        ////
////    *Daniel Camilo Beltrán (dcbeltrans@unal.edu.co)           ////
////                                                              ////
////  Información adicional en: 				                  ////
////  https://sites.google.com/site/edigital2unal/proyectos/      ////
////  	     proyectosii-015/grupo02                              ////
////                                                              ////
//////////////////////////////////////////////////////////////////////


#include "soc-hw.h"

// Direcciones de los perifericos utilizados

uart_t  *uart0  = (uart_t *)   0x20000000;
timer_t *timer0 = (timer_t *)  0x30000000;
gpio_t  *gpio0  = (gpio_t *)   0x40000000;
digpot_t   *digpot0   = (digpot_t *)    0x50000000;
trigger_t *trigger0 = (trigger_t *) 0x60000000;

isr_ptr_t isr_table[32];

void tic_isr();
/***************************************************************************
 * IRQ handling
 */
void isr_null()
{
}

void irq_handler(uint32_t pending)
{
	int i;

	for(i=0; i<32; i++) {
		if (pending & 0x01) (*isr_table[i])();
		pending >>= 1;
	}
}

void isr_init()
{
	int i;
	for(i=0; i<32; i++)
		isr_table[i] = &isr_null;
}

void isr_register(int irq, isr_ptr_t isr)
{
	isr_table[irq] = isr;
}

void isr_unregister(int irq)
{
	isr_table[irq] = &isr_null;
}


//*************************************************************************
// Estructura del periferico GPIO
//*************************************************************************

void gpio_init(uint32_t k)
{
	gpio0->dir=k; //todo lo que sea 0 es puerto lectura
}

uint32_t gpio_read()
{
	return gpio0->read;
}

void gpio_write(uint32_t k)
{
	gpio0->write=k;
}


void set_pin(uint8_t value, uint8_t npin)
{
     if (value)
		gpio0->write = gpio0->read | npin;
	else
		gpio0->write = gpio0->read & (~npin);

}

void pin_inv(uint8_t npin)
{
	uint32_t val;
	val = (~gpio0->read) & npin;
    set_pin(val,npin);
}




//***************************************************************************
// Estructura del periferico TIMER
//**************************************************************************
int counter()
{
	uint32_t tcr;
	int msec=0xFFFFFFFF;
	timer0->compare1 = (FCPU/1000)*msec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	return timer0->counter1;
}


void msleep(uint32_t msec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000)*msec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}

void nsleep(uint32_t nsec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000000)*nsec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}


uint32_t tic_msec;

void tic_isr()
{
	tic_msec++;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;
}

void tic_init()
{
	tic_msec = 0;

	// Setup timer0.0
	timer0->compare0 = (FCPU/10000);
	timer0->counter0 = 0;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;

	isr_register(1, &tic_isr);
}


//***************************************************************************
// Estructura del periferico UART
//***************************************************************************
void uart_init(){}

char uart_getchar()
{
	while (! (uart0->ucr & UART_DR)) ;
	return uart0->rxtx;
}

void uart_putchar(char c)
{
	while (uart0->ucr & UART_BUSY) ;
	uart0->rxtx = c;
}

void uart_putstr(char *str)
{
	char *c = str;
	while(*c) {
		uart_putchar(*c);
		c++;
	}
}


//***************************************************************************
// Estructura del periferico TRIGGER
//***************************************************************************
void trigger_set(uint32_t st)
{
    trigger0->set_trig = st;

}

//***************************************************************************
// Estructura del periferico DIGPOT
//***************************************************************************

void set_digpot(uint32_t dp)
{
    digpot0->set_digpot = dp;

}

//***************************************************************************
// Estructura del periferico PWM
//***************************************************************************
/*
void asig_pwm ()

{

    //double x, y, t, d, f, r, p;

    if ( p == 1)				//selección tercera octava 
    {	
        cin >> d;
        if ( d > 2 && d < 10){ f = 262;}	//selección de la nota dependiendo la distancia
        else if ( d > 10 && d < 20){ f = 294;}
	else if ( d > 20 && d < 30){ f = 330;}
	else if ( d > 30 && d < 40){ f = 349;}
	else if ( d > 40 && d < 50){ f = 392;}
	else if ( d > 50 && d < 60){ f = 440;}
        else if ( d > 60 && d < 70){ f = 494;}
	
	for (int i = 0; i < 251; i++)
	{
	    for (int i = 0; i < 86; i++)		//recorre cada una de las muestras (85 tercera octava)
            {
                t = ((1/f)/85)*1e9;
                r = t/85;
                x = i*r;
                y = t-x;

    	        set_pin(1,8);			//se asigna el ciclo util por tiempo
   	        nsleep(x);
	        set_pin(0,8);
	        nsleep(y);

            }
        }
    }
    else if ( p == 2)				//selección cuarta octava
    {
        if ( d > 2 && d < 10){ f = 262;}	//selección de la nota dependiendo la distancia
        else if ( d > 10 && d < 20){ f = 294;}
	else if ( d > 20 && d < 30){ f = 330;}
	else if ( d > 30 && d < 40){ f = 349;}
	else if ( d > 40 && d < 50){ f = 392;}
	else if ( d > 50 && d < 60){ f = 440;}
        else if ( d > 60 && d < 70){ f = 494;}

	for (int i = 0; i < 251; i++)
	{        
	    for (int i = 0; i < 171; i++)		//recorre cada una de las muestras (170 cuarta octava)
            {
                t = ((1/f)/170)*1e9;
                r = t/170;
                x = i*r;
                y = t-x;

	        set_pin(1,8);			//se asigna el ciclo util por tiempo
	        nsleep(x);
	        set_pin(0,8);
	        nsleep(y);

            }
        }
    }
}
*/
