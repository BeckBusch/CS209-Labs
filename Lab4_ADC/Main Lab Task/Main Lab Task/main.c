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
	
	char formatText[8];
	sprintf(formatText, "%s", "mV");
	
    while (1) {
		uint16_t adcReturn = adc_read(2);
		uint16_t adcReadmv = adc_convert_mv(adcReturn);
		
		char string_buffer[8];
		sprintf(string_buffer, "%d", adcReadmv);

		for (int i=0; i < strlen(string_buffer); i++){
			usart_transmit(string_buffer[i]);	
		}
		for (int i=0; i < strlen(formatText); i++){
			usart_transmit(formatText[i]);
		}
		
		usart_transmit(NEWLINE);
		usart_transmit(RETURN);
		
		_delay_ms(1000);
    }
}

