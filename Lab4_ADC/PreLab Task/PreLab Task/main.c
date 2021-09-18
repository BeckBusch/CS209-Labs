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
	DDRB = (1<<PB5);
	DDRC = 0;
	DDRD = 0;
    /* Replace with your application code */
    while (1) 
    {
		if (PINB & (1<<PB7)) { // If button pressed
			PORTB &= (0<<PB5); // Turn off
		} else {
			PORTB = (1<<PB5); // turn on
		}
		
    }
}

