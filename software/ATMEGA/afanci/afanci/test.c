/*
 * main.c
 *
 * Created: 8/30/2023 8:13:33 AM
 *  Author: paulb
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU	160000000
#define BUAD	9600
#define BRC		((F_CPU/16/BUAD) -1)


#include <util/delay.h>

void initPWM() {
	// Configure Timer0 for Fast PWM on OC0A (Pin 6) and OC0B (Pin 5)
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1); // Fast PWM mode
	TCCR0B = (1 << CS00);  //clk

	// Configure Timer1 for Fast PWM on OC1A (Pin 9) and OC1B (Pin 10)
	TCCR1A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1); // Fast PWM mode
	TCCR1B = (1 << CS00);  //clk

	// Configure Timer2 for Fast PWM on OC2A (Pin 11) and OC2B (Pin 3)
	TCCR2A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1);
	TCCR2B = (1 << CS00);  //clk

	// Set PWM pins as output
	DDRD = (1 << PD6) | (1 << PD5)| (1 << PD3); // OC0A (Pin 6) and OC0B (Pin 5),  OC2B (Pin 3)
	DDRB = (1 << PB1) | (1 << PB2)| (1 << PB3); // OC1A (Pin 9) and OC1B (Pin 10) (PIN 11) 
	

}

int main() {
	initPWM();
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;
		
	UCSR0B = (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);


	while (1) {
		// Adjust PWM duty cycles as needed
		OCR0A = 100; // Duty cycle for OC0A (Pin 6)
		OCR0B = 100;  // Duty cycle for OC0B (Pin 5)
		OCR1A = 100; // Duty cycle for OC1A (Pin 9)
		OCR1B = 100;  // Duty cycle for OC1B (Pin 10)
		OCR2A = 100;  // Duty cycle for OC2A (Pin 11)
		OCR2B = 100; // Duty cycle for OC2B (Pin 3)
		//writes into data register
		UDR0  = '8';
		_delay_ms(1000); // Delay for demonstration
	}
}

 