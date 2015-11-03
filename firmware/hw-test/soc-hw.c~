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




//***************************************************************************
// Estructura del periferico TIMER
//**************************************************************************

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
void init_digpot(){}

void set_digpot(uint32_t dp)
{
    digpot0->set_digpot = dp;

}

