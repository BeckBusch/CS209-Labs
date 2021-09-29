#include "timer0.h"
#include "led.h"
#include "usart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

uint32_t clockCount;

ISR(INT0_vect) {
	if (PIND & (1 << PIND2)) {
		TCNT0 = 0;
	}
	else {
		clockCount = 2000000 / ((uint32_t)TCNT0 * 256);
		clockTransmit(clockCount);
	}
}

/*
ISR(TIMER0_COMPA_vect) {	//This ISR function is called when timer0 reaches
							//compare value, compare flag is automatically cleared
	if (counter >= 10){
		counter = 0;
		led_toggle();
	}
	else {
		counter++;
	}
	
}
*/

void timer0_init(){ //uint8_t prescale
	//TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	//TCCR0B = (TCCR0B & 0x1F8) | (prescale & 0x7);

	//OCR0A = 78;
	
	//TIMSK0 |= (1 << OCIE0A);
}

/*uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << OCF0A )){ // Check compare flag
		
		TIFR0 &= ~(1 << TIFR0); // Clear compare flag.
		
		return 1;
	}
	return 0;
}*/