#include "display.h"

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>

#define Ds1 PD4
#define Ds2 PD5
#define Ds3 PD6
#define Ds4 PD7
#define SH_ST PC5
#define SH_DS PC4
#define SH_CP PC3

volatile uint16_t counter = 0;

//Array containing which segments to turn on to display a number between 0 to 9
//As an example seg_pattern[0] is populated with pattern to display number ‘0’
const uint8_t segmentArray[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x67};

//4 characters to be displayed on Ds1 to Ds 4
static volatile uint8_t disp_characters[4]={0,0,0,0};

//The current digit (e.g. the 1's, the 10's) of the 4-digit number we're displaying
static volatile uint8_t disp_position=0;

uint8_t thousands; uint8_t hundreds; uint8_t tens; uint8_t ones;
uint8_t currentDigit;

void init_display() {
	// SH_ST, SH_DS, SH_CP as outputs
	DDRC |= (1 << SH_ST) | (1 << SH_DS) | (1 << SH_CP);
	// Ds1, Ds2, Ds3, Ds4 as outputs
	DDRD |= (1 << Ds1) | (1 << Ds2) | (1 << Ds3) | (1 << Ds4);
}

//Populate the array ‘disp_characters[]’ by separating the four digits of ‘number’
//and then looking up the segment pattern from ‘seg_pattern[]’
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	thousands = number / 1000;
	hundreds = (number / 100) % 10;
	tens = (number / 10) % 10;
	ones = number % 10;
	
	disp_characters[0] = segmentArray[thousands];
	disp_characters[1] = segmentArray[hundreds];
	disp_characters[2] = segmentArray[tens];
	disp_characters[3] = segmentArray[ones];

	//3. For the project you may modify this pattern to add decimal point at
	// the position ‘decemal_pos’
}

//Render a single digit from ‘disp_characters[]’ on the display at ‘disp_positon’
void send_next_character_to_display(){//uint8_t digit
	
	//1. Based on ‘disp_position’, load the digit to send to a local variable
	/*switch (disp_position) {
	case 0:
		currentDigit = digit / 1000;
		break;
	case 1:
		currentDigit = (digit / 100) % 10;
		break;
	case 2:
		currentDigit = (digit / 10) % 10;
		break;
	case 3:
		currentDigit = digit % 10;
		break;
	}*/
	
	currentDigit = disp_characters[disp_position];
	
	//2. Send this bit pattern to the shift-register as in Q2.2
	// Turn off SH_CP and SH_ST
	PORTC &= ~((1 << SH_CP) | (1 << SH_ST));
	
	// Send each digit to the shift reg
	for (int i=7; i>=0; i--) {
		//PORTC |= (((segmentArray[digit] & (1 << i)) >> i) << SH_DS);
		if (currentDigit & (1 << i)){
			PORTC |= (1 << SH_DS);
			} else {
			PORTC &= ~(1 << SH_DS);
		}
		
		PORTC |= (1 << SH_CP);
		PORTC &= ~(1 << SH_CP);
	}
	
	//3. Disable all digits
	PORTD |= (1 << Ds1) | (1 << Ds2) | (1 << Ds3) | (1 << Ds4);
	
	//4. Latch the output by toggling SH_ST pin as in Q2.2
	// latch the output
	PORTC |= (1 << SH_ST);
	PORTC &= (1 << SH_ST);
	
	//5. Now, depending on the value of pos, enable the correct digit
	// (i.e. set Ds1, Ds2, Ds3 and Ds4 appropriately)
	switch (disp_position) {
		case 0:
		PORTD &= ~(1 << Ds1);
		break;
		case 1:
		PORTD &= ~(1 << Ds2);
		break;
		case 2:
		PORTD &= ~(1 << Ds3);
		break;
		case 3:
		PORTD &= ~(1 << Ds4);
		break;
	}
	
	//6. Increment ‘disp_position’ so the next of the 4 digits will be displayed
	// when function is called again from ISR (reset ‘disp_position’ after 3)
	if (disp_position > 4) {
		disp_position = 0;
	} else {
		disp_position++;
	}
}

void numberDisplay() {
	// variable for number 7
	uint8_t sevenPattern = 0x7;
	
	PORTD |= (1 << Ds1) | (1 << Ds2) | (1 << Ds3);
	PORTD &= ~(1 << Ds4);
	
	// Ensure SH_CP and SH_ST are both set to logic 0
	PORTC &= ~((1 << SH_CP) | (1 << SH_ST));
	
	// Send each digit to the shift reg
	for (int i=7; i>=0; i--) {
		// Set the SH_DS pin to be either “0” or “1” as per the bit being transferred to the shift register
		if (sevenPattern & (1 << i)){
			PORTC |= (1 << SH_DS);
			} else {
			PORTC &= ~(1 << SH_DS);
		}
		
		// Toggle the SH_CP pin on (i.e., “1”) and off (i.e., “0”) to “shift in” this bit to the shift register
		PORTC |= (1 << SH_CP);
		PORTC &= ~(1 << SH_CP);
		
		// Toggle the SH_ST pin on (i.e., “1”) and off (i.e., “0”) to latch the output
		PORTC |= (1 << SH_ST);
		PORTC &= (1 << SH_ST);
	}
}