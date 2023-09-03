/*
 * main.c
 *
 * Created: 8/30/2023 8:13:33 AM
 *  Author: paulb
 */ 

#define F_CPU  160000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/*
double pwm_signal_percent = 0; 

int main(void){
	//TCCR0A – Timer/Counter Control Register A; sets timer as "PWM Timer"
	TCCR0A = (1 << WGM00) | (1 << COM0A1);
	//Timer/Counter Control Register B, pwm function from above needs this timer??
	TCCR0B = (1 << CS02);  //clk256
	//configured the output
	DDRD = 0x40;
	//Timer/Counter Interrupt Mask Register
	//TIMSK0 = 
	sei();
	
	OCR0A = (pwm_signal_percent/100)*255;
	
	while(1)
	{
		
		pwm_signal_percent = 100;
		_delay_ms(50);
		pwm_signal_percent = 10;
		_delay_ms(50);
		pwm_signal_percent = 00;
		_delay_ms(50);
	}
}*/

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

	while (1) {
		// Adjust PWM duty cycles as needed
		OCR0A = 0; // Duty cycle for OC0A (Pin 6)
		OCR0B = 255;  // Duty cycle for OC0B (Pin 5)
		OCR1A = 0; // Duty cycle for OC1A (Pin 9)
		OCR1B = 255;  // Duty cycle for OC1B (Pin 10)
		OCR2A = 0;  // Duty cycle for OC2A (Pin 11)
		OCR2B = 255; // Duty cycle for OC2B (Pin 3)

		_delay_ms(1000); // Delay for demonstration
	}

	return 0;
}

 