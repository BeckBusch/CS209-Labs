#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <stdint.h>

//Toggles the LED
void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);
void clockTransmit(uint32_t clockCount);

#endif