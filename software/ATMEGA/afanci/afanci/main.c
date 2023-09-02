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

double pwm_signal_percent = 0; 

int main(void){
	//TCCR0A – Timer/Counter Control Register A; sets timer as "PWM Timer"
	TCCR0A = (1 << WGM00) | (1 << COM0A1);
	TCCR0B = (1 << CS01); //00000010 clk/8
	DDRD = 0xFF;
	sei();
	
	OCR0A = (pwm_signal_percent/100)*255;
	
	while(1)
	{
		
		OCR0A = 100;
		_delay_ms(500);
		OCR0A = 0;
		_delay_ms(500);
	}
}