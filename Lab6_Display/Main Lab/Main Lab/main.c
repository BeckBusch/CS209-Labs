/*
 * Main Lab.c
 *
 * Created: 3/10/2021 12:49:03 am
 * Author : GGPC
 */ 

#define F_CPU 2000000 // Need to define clock speed for delay.h

#include "timer0.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> // Time delay
#include <stdbool.h>
#include <stdio.h>

int segmentArray[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x67};
int counter = 0;

void main_init(){
	// PB7 = INPUT		PB0, PB1, PB4 = OUTPUT
	DDRB = (1 << PB0) | (1 << PB1) | (1 << PB4);
	// PC0, PC1, PC2, PC3, PC4, PC5 = OUTPUT
	DDRC = (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5);
	DDRD = 0;
}

int main(void) {
	
	main_init();
	timer0_init(10, 256);
	sei();
	
	while (1) {
			
			if (counter > 99) {
				counter = 0;
			} else {
				counter ++;
			}
			
			_delay_ms(1000);
			
			/*for (int j=0; j < 10; j++) {
				if ( !(PINB & (1 << PB7)) ) {
					i = -1;
					break;
				}
				
				_delay_ms(100);
			}*/
		
	} // Main Loop end
}

