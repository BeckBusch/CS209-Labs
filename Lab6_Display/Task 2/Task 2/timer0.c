#include "display.h"

#define F_CPU 2000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool digit1Flag = true;

ISR(TIMER0_COMPA_vect) {
	send_next_character_to_display();
}

void timer0_init(uint32_t time, uint32_t prescaler){
	// Setting CTC mode. Clear on Compare mode resets the counter when it matches OCR0A
	TCCR0A |= (1 << WGM01);
	
	// Setting prescaler to 256
	switch (prescaler)
	{
		case 256:
		TCCR0B = (TCCR0B & 0xF8) | ((1 << CS02) & 0x7);
		break;
		
		default:
		TCCR0B = (TCCR0B & 0xF8) | ((1 << CS00) & 0x7);
		break;
	}
	
	// generate and set OCR0A value
	uint32_t targetReg = (time * 2000000)/(1000 * prescaler);
	//uint8_t targetReg = 78;
	OCR0A = (uint8_t)targetReg;
	
	// Enable interrupt flag
	TIMSK0 |= (1 << OCIE0A);
}
