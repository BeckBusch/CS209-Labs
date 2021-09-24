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
	sprintf(formatText, "%s", ", ");
	
	uint16_t pin0Array[40]; uint16_t pin1Array[40];
	
	
	for(int count=0; count < 40; count++){
		uint16_t adcReturn = adc_read(0);
		uint16_t adcReadmv = adc_convert_mv(adcReturn);
		pin0Array[count] = adcReadmv;
		
		adcReturn = adc_read(1);
		adcReadmv = adc_convert_mv(adcReturn);
		pin1Array[count] = adcReadmv;
	}
	
	for(int count=0; count < 40; count++){
		char string_buffer[8];
		sprintf(string_buffer, "%d", pin0Array[count]);
		
		for (int i=0; i < strlen(string_buffer); i++){
			usart_transmit(string_buffer[i]);
		}
		
		for (int i=0; i < strlen(formatText); i++){
			usart_transmit(formatText[i]);
		}
	}
	
	usart_transmit(NEWLINE);
	usart_transmit(RETURN);
	
	for(int count=0; count < 40; count++){
		char string_buffer[8];
		sprintf(string_buffer, "%d", pin1Array[count]);
		
		for (int i=0; i < strlen(string_buffer); i++){
			usart_transmit(string_buffer[i]);
		}
		
		for (int i=0; i < strlen(formatText); i++){
			usart_transmit(formatText[i]);
		}
	}
}

