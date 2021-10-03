/*
 * Task 2.c
 *
 * Created: 3/10/2021 7:01:52 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000 // Need to define clock speed for delay.h

#include "display.h"
#include "timer0.h"

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h> // Time delay

int main(void) {
    init_display();
	timer0_init(10, 256);
	sei();
	
    while (1) {
		if (counter > 9999) {
			counter = 0;
		}
		else {
			counter ++;
			seperate_and_load_characters(counter, 3);
		}
		
		_delay_ms(400);
    }
}

