#include "soc-hw.h"


//#define DEBUG

int main()
{
	gpio0->dir = 0xFF;

	tic_init0();

	irq_set_mask(0x03);
	irq_enable();
	for(;;)
		usleep1(1);
}

