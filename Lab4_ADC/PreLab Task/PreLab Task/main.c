/*
 * PreLab Task.c
 *
 * Created: 19/09/2021 2:18:03 am
 * Author : GGPC
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xFF;
	DDRC = 0;
	DDRD = 0;
    /* Replace with your application code */
    while (1) 
    {
		PORTB = (1<<PB5); // turn on
		_delay_ms(1000); // wait half a second
		PORTB &= (0<<PB5); // turn off
		_delay_ms(1000); // wait half a second
    }
}

