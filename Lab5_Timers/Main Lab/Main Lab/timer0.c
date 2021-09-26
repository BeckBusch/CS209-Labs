#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

ISR(TIMER0_COMPA_vect) { //This ISR function is called when timer0 reaches
	//compare value, compare flag is automatically cleared
	led_toggle();
}

void timer0_init(){
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	OCR0A = 79;
	
	TIMSK0 |= (1 << OCIE0A);
}

/*uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << OCF0A )){ // Check compare flag
		
		TIFR0 &= ~(1 << TIFR0); // Clear compare flag.
		
		return 1;
	}
	return 0;
}*/