<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 3

## Pre-Lab: Using Atmel Studio

Q P.1: What was the largest number stored in the array, in decimal and in hex?

> Add answer here 

Q P.2: Why did the memory window show a lot of 00 elements between some of the numbers in the array?

> Add answer here 

## Part 1: What is UART? 

Q 1.1: What is the purpose of each of the following parameters and bits?

> The start bit:

> The parity bit:

> The number of stop bits:

> The baud rate:

## Part 2: How do we control the microcontroller?

Q 2.1: Using the datasheet, state the register and bits that control each of the settings below, and describe the purpose of each of these settings. Identify whether or not we need this setting, and if we do, determine if the setting is set at initialisation or if it is used at runtime:

| Setting Name              | Register & Bits        | Purpose                    | Needed?  | Innit or Runtime  |
| --------------------------|------------------------|----------------------------|----------|-------------------|
| Receive Complete          | UCSR0A RXC0(Bit 7)     | USART Rx complete flag     | No       | Runtime           |
| Data (Tx) Register Empty  | UCSR0A UDRE0(Bit 5)    | USART ready to Tx flag     | Yes      | Runtime           |
| Tx Complete               |                        |                            |          |                   |
| Mode Selection            |                        |                            |          |                   |
| Character Size            |                        |                            |          |                   |
| Clock Polarity            |                        |                            |          |                   |
| Baud Rate                 |                        |                            |          |                   |
| Receiver Enable           |                        |                            |          |                   |
| Transmitter Enable        |                        |                            |          |                   |
| Parity Mode               |                        |                            |          |                   |
| Parity Error              |                        |                            |          |                   |

Q 2.2: Using the datasheet, what is the appropriate UBRR value, assuming that our system clock is 2MHz?	

> Add answer here 

Q 2.3: On the ATMega328P, the UBRR is divided up between two registers, UBRR0H and UBRR0L. Why do you think this is the case?

> Add answer here 

Q 2.4: Using your answers from Q 2.1 and the datasheet, for each of the three control registers below, fill out the table with the short name for each bit, and the value we need to set it to during initialisation. Your options are 0 or 1 – if you don’t care what the value is, set it to 0.

> UCSR0A

| RXC0   |        |        |        |        |        |        |        |
|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
| 0      |        |        |        |        |        |        |        |

> UCSR0B

|        |        |        |        |        |        |        |        |
|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|        |        |        |        |        |        |        |        |

> UCSR0C

|        |        |        |        |        |        |        |        |
|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|        |        |        |        |        |        |        |        |

Q 2.5: For each of these instructions, finish the C macro expression:

> Test if the UDRE0 bit is 1:

```c
if( ___ & (1 << ___ )) { 
   //Code...
} 
```

> Write a 1 (set) to the TXEN0 bit: 

```c
___ |= ( __ << ___ );
```

> Write a 0 (clear) to the UCPOL0 bit: 

```c
___________
```

## Part 3: What data are we sending? 

Q 3.1: On the ATMega328P, how many bits of data can be stored in a variable of each of these types:

> char: 		

> uint8_t: 

> int:		

> uint16_t: 

> int8_t: 

> float: 

Q 3.2: What is the size of the UDR0 register?

> Add answer here 

Q 3.3: What is the largest number we can transmit?

> Add answer here 

Q 3.4: What numbers would correspond to the word “HELLO”?

> Add answer here 

Q 3.5: Fill in the blanks below to describe how to send a number to a terminal:

> We can extract the individual digits of a number by using the ______________ operator. Then we encode an individual digit into its ASCII equivalent by simply adding the number _________. Then we iterate through each digit of the number using a ____________, writing each character to the _______ register.


## Part 4: It’s time to transmit data!  

Q 4.1: Assuming that we can begin transmitting a UART packet immediately after the previous one ends, work out the length of time required to send each of these:

> A single character: 

> A 3-digit number: 

Q 4.2: Now, also assuming that we need to send a comma character and a space character between each number, work out the length of time to send each of these:

> Three 3-digit numbers: 

> The entire primes list from pre-lab (assume all 3-digits):

Q 4.3: Write a **_usart_init(uint16_t ubrr)_** function which sets up the USART peripheral as determined in Part 2. Of the five control registers, how many could be left with their initial values? 

> Add answer here 

Q 4.4: Write a **_usart_transmit(uint8_t data)_** function which handles transmission of a single number through the USART peripheral. The important steps are to:

> Step 1: Check bit _____ of register ___________ and wait if _____________

> Step 2: Load _______________ into the ___________________ register

Q 4.7: Modify your program so that it follows these steps:

> Step 1: Call **_usart_init(ubrr)_** using the UBRR value calculated in Q2.2

> Step 2: Put the list of primes from the pre-lab into memory (in an array)

> Step 3: Inside the while(1) loop, set up a ___________________
>
> a.	Extract the individual characters of your prime numbers
> 
> b.	Call usart_transmit(character) as needed
> 
> c.	Call usart_transmit(character) for the comma and space as needed
>
> d.	Increment ____________

Q 4.8: Complete the flowchart below that describes the flow of your program code:

> Replace **_Lab3_Images/flowchart.png_** with image of your flowchart (adjust width as needed)

<img src="Lab3_Images/flowchart.png" width="150">

## Optional Task: Advanced String Processing

Q O.2) Compile both the sprintf and the original version of your code. Now, compare the size of the generated “.hex” (a better measure of the code size than the “elf”. 

> Which is larger? 
 
> By how many times is it larger?