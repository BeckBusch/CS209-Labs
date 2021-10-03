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

> Add answer here

Q 1.3: In the pseudo-code steps given, why do you think that we alternate the digit we update every 10ms?

> Add answer here

## Part 2: Shift registers

Q 2.1: If only using multiplexing, how many I/O pins are needed to drive a display that has N number of 7-segment digits where each digit also has a decimal point?

> Add answer here
