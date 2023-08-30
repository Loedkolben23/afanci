/*
 * main.c
 *
 * Created: 8/30/2023 8:13:33 AM
 *  Author: paulb
 */ 

#include <avr/io.h>

int main(void) {
PORTB = 000000001;	
DDRB = 000000001;
	while(1) {}
	return 0;
	}

//8 -> PB0
// 3 Register für Ports