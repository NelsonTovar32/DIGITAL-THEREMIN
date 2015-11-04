#include "soc-hw.h"


//#define DEBUG

void hexprint(unsigned int hexval)
{
  unsigned char digit[8];
  int pos;
  uart_putstr("0x");
  for(pos = 0; pos < 8; pos++)
    {
      digit[pos] = (hexval & 0x0F);  /* last hexit */
      hexval = hexval >> 4;
    }
  for(pos = 7; pos > -1; pos--)
    {
      if( digit[pos] < 0x0A)
        uart_putchar(digit[pos] + '0' );
      else
        uart_putchar(digit[pos] + 'A' - 10);
    }
  uart_putchar('.');
}

int main()
{
	uint8_t tmp_var=0;
	uint8_t tmp_num=0;
	uint8_t channel=0;
	uint8_t w_c=0;

	uint8_t valor= 0;


	gpio0->dir=(0x01);
	/*for (;;){
	valor=gpio0->read;
	uart_putchar(valor );
	}*/



	gpio0->dir = 0x01;
	uart_putchar('0' );
	
for(;;)
{
valor=gpio0->read;
valor=valor>>1;
if(valor==1)
{pin_inv(1);
	msleep1(2000);
	}
else
{pin_inv(1);
	msleep1(500);}

}

	
	


tic_init0();

	irq_enable();
	irq_set_mask(0x02);
	v_ch1=0xAA;
	for(;;)	{
		while(tmp_var!='<')
			tmp_var=uart_getchar();
		#ifdef DEBUG
			uart_putstr("\nok <\n");
	     #endif

		tmp_num=uart_getchar();
		#ifdef DEBUG
			uart_putstr("\ndebug numero: ");
			uart_putchar(tmp_num);

	     #endif
		tmp_var=uart_getchar();
		#ifdef DEBUG
			uart_putstr("\ndebug variable ");
			uart_putchar(tmp_var);
	     #endif
		if (tmp_var == 'c')
		{	if (tmp_num <= 3)
				channel = tmp_num;
		}
		else if (tmp_var == 'w')
		{
			w_c = tmp_num;
		#ifdef DEBUG
			uart_putstr("\ndebug asignacion\n");
			uart_putchar(w_c);
	     #endif

	   		if (channel==1)
				v_ch1 = w_c;
			else if (channel==2)
				v_ch2 = w_c;
			else if (channel==3)
				v_ch3 = w_c;
		#ifdef DEBUG
			uart_putstr("\ndebug case\n");
			uart_putchar(v_ch1);
			uart_putchar(v_ch2);
			uart_putchar(v_ch3);
	     #endif
		}
	}


}

