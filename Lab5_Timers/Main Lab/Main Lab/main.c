/*
 * Main Lab.c
 *
 * Created: 26/09/2021 9:15:13 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
	// Set LED pin to output
	DDRB &= ~(1<<PB5);

	timer0_init();
	
	while(1){
		
		if(timer0_check_clear_compare()) {
			led_toggle();
		}
		
	}
}