/*
 * Main Lab Task.c
 *
 * Created: 20/09/2021 12:59:27 pm
 * Author : GGPC
 */ 

#define F_CPU 2000000

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>
#include <string.h>
#include "adc.h"
#include "usart.h"

#define PERIOD 0x2E
#define NEWLINE 0xA
#define RETURN 0xD


int main(void)
{
	usart_init(12);
	adc_init();
	
    while (1) {
		uint16_t adcReturn = adc_read(2);
		float adcRead = adc_convert_mv(adcReturn);
		
		float f1,f2;
		int i1,i2;
		char string_buffer[10];
		
		f1=floor(adcRead);
		f2=adcRead - f1;
		i1 = (int)f1;
		i2 = (int)10000*f2;
		sprintf(string_buffer,"%d,%d", i1,i2);
		
		//char string_buffer[32];
		//sprintf(string_buffer, "%f", test);
		
		for (int i=0; i < strlen(string_buffer); i++){
			usart_transmit(string_buffer[i]);	
		}
		
		usart_transmit(NEWLINE);
		usart_transmit(RETURN);
		
		_delay_ms(1000);
    }
}

