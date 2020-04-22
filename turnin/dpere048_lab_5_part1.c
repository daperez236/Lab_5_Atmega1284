/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //port a input
    DDRB = 0x00; PORTB = 0xFF; //port b input
    DDRC = 0xFF; PORTC = 0x00; //port C output
	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpC = 0x00;
	tmpA = PINA&0x0F;
	tmpB = PINA&0x70;
	if(tmpA == 0x01 || tmpA ==  0x02){
	tmpC = 0x20;
	}
	else if(tmpA == 0x03 || tmpA == 0x04){
	tmpC = 0x30;
	}
	else if(tmpA == 0x05 || tmpA == 0x06){
	tmpC = 0x38;
	}
	else if(tmpA == 0x07 || tmpA == 0x08 || tmpA == 0x09){
	tmpC = 0x3C;
	}
	else if(tmpA == 0x0A || tmpA == 0x0B || tmpA == 0x0C){
	tmpC = 0x3E;
	}
	else if(tmpA == 0x0D || tmpA == 0x0E || tmpA == 0x0F){
	tmpC = 0x3F;
	}
	else{
	tmpC = 0x00;
	}
	if(tmpA <= 0x04){
	tmpC = tmpC | 0x40;
	}
	tmpB = tmpB >> 4; //shifts to 0000 0111
	if(tmpB == 3){
	tmpC == tmpC | 0x80;
	}
	PORTC = tmpC;
    }
    return 1;
}
