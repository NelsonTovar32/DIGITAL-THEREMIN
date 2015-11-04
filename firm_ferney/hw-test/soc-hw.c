#include "soc-hw.h"

uart_t  *uart0  = (uart_t *)   0x20000000;
timer_t *timer0 = (timer_t *)  0x30000000;
gpio_t  *gpio0  = (gpio_t *)   0x40000000;
spi_t   *spi0   = (spi_t *)    0x50000000;
i2c_t   *i2c0   = (i2c_t *)    0x60000000;

uint8_t v_ch1=0;
uint8_t v_ch2=0;
uint8_t v_ch3=0;
uint8_t estado_actual=0;


void irq_handler(uint32_t pending)
{
//	timer0->tcr0     =  TIMER_EN | TIMER_AR | TIMER_IRQEN;
//	timer0->tcr0     =  14;
	tic_isr();
}


/***************************************************************************
 * GPIO Functions
 */



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


/***************************************************************************
 * TIMER Functions
 */
void msleep1(uint32_t msec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000)*msec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}

void usleep1(uint32_t usec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000000)*usec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN   ;

	do {
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}



void tic_isr()
{
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;
//	pin_inv(PIN1);
	uint8_t bit;
	bit=(v_ch1 >> estado_actual) & 0x01;
	estado_actual=estado_actual+1;
	if (estado_actual>7)
		estado_actual=0;
	set_pin(bit, PIN1);
}

void tic_init0()
{
	timer0->compare0 = (FCPU/1000000)*10;
	//timer0->compare0 = 2;
	timer0->counter0 = 0;
	timer0->tcr0     = TIMER_EN | TIMER_AR| TIMER_IRQEN;
}


/***************************************************************************
 * UART Functions
 */

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


