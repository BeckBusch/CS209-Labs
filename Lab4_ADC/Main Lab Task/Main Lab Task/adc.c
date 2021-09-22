#include "adc.h"

#include <avr/io.h>

void adc_init() {
	// Set reference voltage to AVcc
	ADMUX |= (1<<REFS0);
	// Set ADC Prescaler to 16 and turn on the ADC
	ADCSRA |= (1<<ADPS2) | (1<<ADEN);
	/*ADCSRB = 0;*/

}

uint16_t adc_read(uint8_t channel){
	// Set the channel to read from while not changing the other values in ADMUX
	ADMUX |= (channel & 0x0F);
	
	// Set ADSC to 1 to start the conversion
	ADCSRA |= (1<<ADSC);
	
	// Check ADSC to tell when the conversion finishes
	while( ADCSRA & (1<<ADSC) );
	
	return ADC;
}

float adc_convert_mv(uint16_t value){
	float result = ((float)value * 5) / 1024;
	return result;
}


