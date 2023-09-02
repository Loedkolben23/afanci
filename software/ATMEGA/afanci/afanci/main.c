/*
 * main.c
 *
 * Created: 8/30/2023 8:13:33 AM
 *  Author: paulb, Qualspirale
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_OVR_vect)
{
	PORTB = 000000001;	
}

int main(void) {
	// PIN CONFIG
	DDRB = 000000001;
	
	TCNT1 = 0; 
	TCCR1B = (1 << CS10) | (1 << CS12);
	
	TCCR1A = 00x0;
	
	TIMSK1 = (1 << TOIE1);
	
	sei():
	
	
PORTB = 000000001;	

	while(1) {}
	return 0;
	}

//8 -> PB0
