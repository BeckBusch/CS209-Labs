#include "usart.h"

#include <avr/io.h>

void usart_init(uint16_t ubrr) {

	UCSR0B |= (1 << TXCIE0) | (1 << TXEN0);
	UBRR0 = ubrr;

}

void usart_transmit(uint8_t data) {

	while ((UCSR0A & (1 << UDRE0)) == 0) {

	}
	UDR0 = data;

}