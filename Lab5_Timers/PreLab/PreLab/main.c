/*
 * PreLab.c
 *
 * Created: 26/09/2021 3:25:04 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000

#include <avr/io.h>
#include <util/delay.h>


int main(void) {
	// Port B Output
	DDRB = 0;
	// Port C&D Input
	DDRC = 1;
	DDRD = 1;

    while (1) {
		PORTB |= (1<<PB5); // Turn on
		_delay_ms(375);
		PORTB &= ~(1<<PB5); // Turn off
		_delay_ms(125);
    }
}

