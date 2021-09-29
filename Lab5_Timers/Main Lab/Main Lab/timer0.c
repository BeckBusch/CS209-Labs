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
		clockConvert(TCNT0);
	}
}

void timer0_init(uint8_t prescale) {
	TCCR0B = (TCCR0B & 0x1F8) | (prescale & 0x7);
}