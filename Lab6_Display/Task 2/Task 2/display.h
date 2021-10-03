#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

extern volatile uint16_t counter;
const uint8_t segmentArray[10];
static volatile uint8_t disp_characters[4];
static volatile uint8_t disp_position;
uint8_t thousands; uint8_t hundreds; uint8_t tens; uint8_t ones;

void init_display();
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos);
void send_next_character_to_display();//uint8_t digit
void numberDisplay(uint8_t number);

#endif /* DISPLAY_H_ */