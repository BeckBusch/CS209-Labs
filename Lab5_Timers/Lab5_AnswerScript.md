<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 5

## Part 1: What is a Timer Peripheral?

Q 1.1: Based on the diagram above and the information provided in the datasheet, are the two OCRnX registers (i.e. ORCnA and OCRnB) needed for all timer configurations?

> No. OCCRnX registers are not used in Normal Mode

Q 1.2: Based on the lecture slides, datasheet, COMPSYS201 notes, and other online resources, find and then state in your own words the difference between the **range** and **resolution** of a given timer:

> Range: The maximum amount of time that a timer can keep track of.

> Resolution: the minimum time interval a timer can measure.

Q 1.3: What is the purpose of the prescaler used with the clock source?

> to slow down the counting speed so that the timer does not increase at the same rate as the system clock, making it more versatile and useful.

Q 1.4: If the clock rate of the ATmega328P is 2MHz, and the clock selection bits in TCCR0B are set to “100”,

> The prescaler is: /256

> Resolution of TIMER0 is: 0.128 ms

> Maximum range of TIMER0 is: 0.128 * ( (2^8) - 1) = 32.64 ms

Q 1.5: We want TIMER0 to use CTC mode to set the “output compare A match” flag every 10 milliseconds. What should the following registers be set to (some bits have already been filled in for you)?

> TCCR0A

| COM0A1  |  COM0A0 | COM0B1  | COM0B0  |    -    |     -   |  WGM01  |  WGM00  |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| 0       | 0       |    0    |   0     |   -     |    -    |   1     |   0     |

> TCCR0B

| FOC0A   | FOC0B   |    –    |    –    |   WGM02 | CS02    | CS01    | CS00    |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
|    0    |    0    |         |         |   0     | 1       | 0       | 0       |

> OCR0A

| OCR0A7  | OCR0A7  | OCR0A7  | OCR0A7  | OCR0A7  | OCR0A7  | OCR0A7  | OCR0A7  |
|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
|        0|     1   |     0   |    0    |    1    |    1    |    1    |    0    |

Q 1.6: In which bit of which register is the “output compare match A” flag?

> TIFR0 - OCF0A

## Part 2: Controlling the TIMER0

Q 2.1: Using your answers thus far, create an Atmel Studio Project to toggle the LED that is connected to the ATmega328P in the proteus project “Lab5_Proteus_All.pdsprj”. It should toggle every 10ms, and you should be using Timer0. Use polling to check the compare match flag. Provide the completed skeleton code below (see word document for header file examples):

> main.c

```c
#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt>

int main(void)
{

//TODO: set direction of LED port to OUTPUT

timer0_init();

 	while (1) {
   		if(timer0_check_clear_compare()) {
	    		led_toggle();
		}
    }
}
```

> timer0.c

```c
#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer0_init()
{
	//TODO: initialize and configure timer0 to count to 10ms
}

bool timer0_check_clear_compare()
{
	if( ?????? & (1 << ?????? )) { //TODO: check compare flag
		//TODO: clear compare flag
        //This is done by writing 1 to the compare flag
		//Refer to the datasheet    
		return 1;
	}
	return 0;
}
```

> led.c

```c
#include "led.h"

#include <avr/io.h>

void led_toggle() {
	//TODO: LED toggle code
}
```

## Part 3: Timer Interrupts

Q 3.1: Change the embedded program you developed previously to toggle the LED using an Output Compare A match interrupt. To do this, firstly, enable the timer0 interrupt in your timer0_init(), add the ISR function to your timer0.c, and in here toggle the LED. Finally, enable global interrupts. Provide the completed skeleton code below:

> Note: OCR0A is a problem. my original value of 79 was calculated by hand and has always produced an offset. With a count of 10 this offset is amplified so OCR0A was adjusted.

> timer0.c

```c
ISR(TIMER0_COMPA_vect) {
    //this special ISR function is called when timer0 reaches
	//compare flag is automatically cleared
	led_toggle();
}

void timer0_init() {
	//TODO: initialise and configure timer0 to interrupt every 10ms
}
```
> main.c

```c
int main(void)
{

//TODO: set direction of LED port to OUTPUT

timer0_init();
sei();        // Special function call that enables the use of interrupts

 	while (1) {}

}
```


Q 3.4: What is the maximum range of Timer1? Assume the system clock frequency is 2MHz

> (1/2000000) * (2^16 -1) * 1024 = 33.55 Seconds

## Part 4: Measuring Time

Q 4.1: Modify your code so that the timer is started on the rising edge of INT0, and stopped on the falling edge of INT0. You can poll the input at INT0, or you can use interrupts. Calculate the frequency of the waveform and send the result over the UART to be displayed on a terminal window. Compile the Atmel Studio project and simulate your program in Proteus. What frequency is the waveform on INT0?

> 500Hz

Q 4.2: What is the lowest frequency waveform the timer could measure? Why?

> 1 / (2^8 / 1024) = 4Hz

Q 4.3: Change the processor to an ATmega328PB, recompile your code and load on to the Xplained Mini. Make sure the Xplained Mini is plugged on to the Emulator Board. On PuTTY or other terminal program observe the messages printed. What frequency is the waveform on INT0?

> Add answer here
