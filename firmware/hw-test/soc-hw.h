//////////////////////////////////////////////////////////////////////
////                                                              ////
////                   DIGITAL - THEREMIN                         ////
////                        soc-hw.h                              ////
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


#ifndef SPIKEHW_H
#define SPIKEHW_H

#define PROMSTART 0x00000000
#define RAMSTART  0x00000800
#define RAMSIZE   0x400
#define RAMEND    (RAMSTART + RAMSIZE)

#define RAM_START 0x40000000
#define RAM_SIZE  0x04000000

#define FCPU      100000000
//#define FCPU      50000000

#define UART_RXBUFSIZE 32

/****************************************************************************
 * Types
 */
typedef unsigned int  uint32_t;    // 32 Bit
typedef signed   int   int32_t;    // 32 Bit

typedef unsigned char  uint16_t;    // 16 Bit
typedef signed   char   int16_t;    // 16 Bit

typedef unsigned char  uint8_t;    // 8 Bit
typedef signed   char   int8_t;    // 8 Bit

/****************************************************************************
 * Interrupt handling
 */
typedef void(*isr_ptr_t)(void);

void     irq_enable();
void     irq_disable();
void     irq_set_mask(uint32_t mask);
uint32_t irq_get_mak();

void     isr_init();
void     isr_register(int irq, isr_ptr_t isr);
void     isr_unregister(int irq);

/****************************************************************************
 * General Stuff
 */
void     halt();
void     jump(uint32_t addr);


/****************************************************************************
 * Timer
 */
#define TIMER_EN     0x08    // Enable Timer
#define TIMER_AR     0x04    // Auto-Reload
#define TIMER_IRQEN  0x02    // IRQ Enable
#define TIMER_TRIG   0x01    // Triggered (reset when writing to TCR)

typedef struct {
	volatile uint32_t tcr0;
	volatile uint32_t compare0;
	volatile uint32_t counter0;
	volatile uint32_t tcr1;
	volatile uint32_t compare1;
	volatile uint32_t counter1;
} timer_t;

void msleep(uint32_t msec);
void nsleep(uint32_t nsec);

void prueba();
void tic_init();
void tic_isr();

int counter();

/***************************************************************************
 * GPIO0
 ***************************************************************************/

#define PAUSE 0x01 //Pause
#define MODO 0x02 //Modo
#define VOLUP 0x04 //VolUP
#define VOLDW 0x08 //VolDW
#define PITCHUP 0x10 //PitchUp
#define PITCHDW 0x20 //PitchDw

typedef struct {
	volatile uint32_t read;
	volatile uint32_t write;
	volatile uint32_t dir;
} gpio_t;

void gpio_init();
uint32_t gpio_read();
void gpio_write();

void set_pin(uint8_t value, uint8_t npin);
uint8_t get_pin(uint8_t npin);
void pin_inv(uint8_t npin);

/***************************************************************************
* Trigger-Echo 0 NOTA
 */
typedef struct {
	volatile uint32_t set_trig;
	volatile uint32_t c_out;
		} trigger_t0;

void trigger_set0();
uint32_t read_count0();

/***************************************************************************
* Trigger-Echo 1 VOLUMEN
 */
typedef struct {
	volatile uint32_t set_trig;
	volatile uint32_t c_out;
		} trigger_t1;

void trigger_set1();
uint32_t read_count1();


/***************************************************************************
* DigitalPot
 */
typedef struct {
	volatile uint32_t set_digpot;
	volatile uint32_t set2;
		} digpot_t;

void set_digpot();

/***************************************************************************
 * Pointer to actual components
 */
extern timer_t   *timer0;
//extern timer1_t  *timer10;
extern gpio_t    *gpio0;
extern trigger_t0 *trigger0;
extern trigger_t1 *trigger1;
extern digpot_t  *digpot0;
extern uint32_t  *sram0;


#endif // SPIKEHW_H

