#include "main.h"

#define F_CPU 2000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool digit1Flag = true;

ISR(TIMER0_COMPA_vect) {
	
	PORTB |= (1 << PB0) | (1 << PB1); // turn off digits
	
	if (digit1Flag) {
		
		uint8_t digit1 = counter / 10;
		
		PORTC = (PORTC & 0xC0) | (segmentArray[digit1] & 0x3F);
		if (segmentArray[digit1] & 0X40) {
			PORTB |= (1 << PB4);
			} else {
			PORTB &= ~(1 << PB4);
		}
		PORTB &= ~(1 << PB0);
		
		digit1Flag = false;
		
		} else {
			
		uint8_t digit2 = counter % 10;
		
		PORTC = (PORTC & 0xC0) | (segmentArray[digit2] & 0x3F);
		if (segmentArray[digit2] & 0X40) {
			PORTB |= (1 << PB4);
			} else {
			PORTB &= ~(1 << PB4);
		}
		
		PORTB &= ~(1 << PB1);
		
		digit1Flag = true;
		
	}
	
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
