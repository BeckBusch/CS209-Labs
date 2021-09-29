#include "timer0.h"
#include "led.h"
#include "usart.h"

#include <avr/io.h>

void led_toggle(){
	if (PORTB & (1 << PB5)) {
		PORTB &= ~(1 << PB5);
	}
	else {
		PORTB |= (1 << PB5);
	}
}