<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 6

## Pre-lab: Basics of a 7-segment display

Q P.1) Given the above component, and assuming “dp” is the MSB and “a” is the LSB, complete the table to indicate what segments should light for each digit:

> Segments to be turned on for "0" in binary / hex: 0b00111111 / 0x3F

> Segments to be turned on for "1" in binary / hex: 0b00000110 / 0x6

> Segments to be turned on for "2" in binary / hex: 0b01011011 / 0x5B

> Segments to be turned on for "3" in binary / hex: 0b01001111 / 0x4F

> Segments to be turned on for "4" in binary / hex: 0b01100110 / 0x66

> Segments to be turned on for "5" in binary / hex: 0b01101101 / 0x6D

> Segments to be turned on for "6" in binary / hex: 0b01111101 / 0x7D

> Segments to be turned on for "7" in binary / hex: 0b00000111 / 0x7

> Segments to be turned on for "8" in binary / hex: 0b01111111 / 0x7F

> Segments to be turned on for "9" in binary / hex: 0b01100111 / 0x67

## Part 1: Multiplexing LEDs

Q 1.2: In the pseudo-code steps given, why do you think that we output the segments before we enable the display (i.e. why is Step 5 before Step 4)?

> to avoid displaying an incorrect value, which is a bigger problem now that we are using multiplexing

Q 1.3: In the pseudo-code steps given, why do you think that we alternate the digit we update every 10ms?

> we alternate the digits at a rate of every 10ms since that is the fastest we can go while still allowing time for the code that manages the ports.

## Part 2: Shift registers

Q 2.1: If only using multiplexing, how many I/O pins are needed to drive a display that has N number of 7-segment digits where each digit also has a decimal point?

> 8 + N since there are 8 segment pins and N common ground pins

Code for Question 2.2:

```c
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
```
