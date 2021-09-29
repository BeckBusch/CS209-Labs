#include "timer0.h"
#include "led.h"
#include "usart.h"

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define NEWLINE 0xA
#define RETURN 0xD

void clockTransmit(uint32_t clockCount){
	char string_buffer[8];
	
	sprintf(string_buffer, "%d", clockCount);
	
	for (int i=0; i < strlen(string_buffer); i++){
		usart_transmit(string_buffer[i]);
	}
	usart_transmit(NEWLINE);
	usart_transmit(RETURN);
}

void usart_init(uint16_t ubrr) {
	UCSR0B |= (1 << TXCIE0) | (1 << TXEN0);
	UBRR0 = ubrr;
}

void usart_transmit(uint8_t data) {
	while ((UCSR0A & (1 << UDRE0)) == 0) {}
	UDR0 = data;
}