/*
 * Pre Lab.c
 *
 * Created: 2/10/2021 6:36:58 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000 // Need to define clock speed for delay.h

#include <avr/io.h>
#include <util/delay.h> // Time delay


int segmentArray[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x67};

int main(void) {
	// PB7 = INPUT		PB0, PB1, PB4 = OUTPUT
	DDRB = (1 << PB0) | (1 << PB1) | (1 << PB4);
	// PC0, PC1, PC2, PC3, PC4, PC5 = OUTPUT
	DDRC = (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5);
	DDRD = 0;
	
	PORTB |= (1 << PB0);
	
    while (1) {
		for (int i=0; i<=9; i++) {
			
			PORTC = (PORTC & 0xC0) | (segmentArray[i] & 0x3F);
			
			if (segmentArray[i] & 0X40) {
				PORTB |= (1 << PB4);
			} else {
				PORTB &= ~(1 << PB4);
			}
			
			for (int j=0; j < 10; j++) {
				if ( !(PINB & (1 << PB7)) ) {
					i = -1;
					break;
				}
				
				_delay_ms(100);
			}
			
		}
		
    }
}

