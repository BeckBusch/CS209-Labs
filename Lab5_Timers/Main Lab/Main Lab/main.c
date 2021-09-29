/*
 * Main Lab.c
 *
 * Created: 26/09/2021 9:15:13 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"
#include "usart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	// Set LED pin to output
	DDRB &= ~(1 << PB5);
	
	// Setup INT0
	EICRA &= ~(1 << ISC01);
	EICRA |= (1 << ISC00);
	EIMSK |= (1 << INT0);

	timer0_init(4);
	usart_init(12);
	sei(); //This special function call enables the use of interrupts
	
	while(1){
		clockTransmit();	
	}
}