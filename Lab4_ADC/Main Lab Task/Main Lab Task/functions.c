#include "headers.h"

#include <avr/io.h>
#include <stdio.h>

void adc_init() {
	
	ADMUX = 64 + 7; // plus 0 to 7 depending on the channel being read
	ADCSRA = 4;
	ADCSRB = 0;

}

