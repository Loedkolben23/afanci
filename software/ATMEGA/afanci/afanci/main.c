/*
 * main.c
 *
 * Created: 8/30/2023 8:13:33 AM
 *  Author: paulb
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int extraTime = 0;

int main(void) {
	
	TCCR0A = 0b00000010;    // C1:: timer 0 mode 2 - CTC
	TCCR0B = 0b00000100;    // C2:: set prescaler to 256
	OCR0A = 250;            // C3:: number of ticks in Output Compare Register
	TIMSK0 = 0b00000010;    // C4:: trigger interrupt when ctr (TCNT0) >= OCR0A

	DDRB = 0b00100000;      // C5:: set onboard LED (D13) as an output
	sei();                  // C6:: Enable interrupts
	
	while(1) {}
	return 0;
}

ISR(TIMER0_COMPA_vect) {
	extraTime++;
	
	if (extraTime > 100) {
		PORTB ^= (1<<PORTB5); // C7:: toggle LED
		extraTime = 0;
	}
}