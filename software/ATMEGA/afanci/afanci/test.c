/*
 * main.c
 *
 * Created: 8/30/2023 8:13:33 AM
 *  Author: paulb
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

const uint8_t fanCurve[][2] = {
	{25, 0},  // Temperature (°C), Fan Percentage
	{30, 25},
	{35, 50},
	{40, 75},
	{45, 100}
};

#define FAN_CURVE_SIZE (sizeof(fanCurve) / sizeof(fanCurve[0]))


void initPWM() {
	// Configure Timer0 for Fast PWM on OC0A (Pin 6) and OC0B (Pin 5)
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1); // Fast PWM mode
	TCCR0B = (1 << CS00);  //clk

	// Configure Timer1 for Fast PWM on OC1A (Pin 9) and OC1B (Pin 10)
	TCCR1A = (1 << WGM10) | (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1); // Fast PWM mode
	TCCR1B = (1 << CS10);  //clk

	// Configure Timer2 for Fast PWM on OC2A (Pin 11) and OC2B (Pin 3)
	TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << COM2A1) | (1 << COM2B1);
	TCCR2B = (1 << CS20);  //clk

	// Set PWM pins as output
	DDRD = (1 << PD6) | (1 << PD5)| (1 << PD3); // OC0A (Pin 6) and OC0B (Pin 5),  OC2B (Pin 3)
	DDRB = (1 << PB1) | (1 << PB2)| (1 << PB3); // OC1A (Pin 9) and OC1B (Pin 10) (PIN 11) 
}

uint8_t CalculateFanPercentage(uint16_t temperature) {
	uint8_t closestPercentage = 0;
	uint16_t closestTempDiff = UINT16_MAX;

	for (int i = 0; i < FAN_CURVE_SIZE; i++) {
		uint16_t tempDiff = abs(temperature - fanCurve[i][0]);
		if (tempDiff < closestTempDiff) {
			closestTempDiff = tempDiff;
			closestPercentage = fanCurve[i][1];
		}
	}

	return closestPercentage;
}

int main() {
	initPWM();
	while (1) {
		// Adjust PWM duty cycles as needed
		//OCR0A = 255; // Duty cycle for OC0A (Pin 6)
		//OCR0B = 255;  // Duty cycle for OC0B (Pin 5)
		//OCR1A = 255; // Duty cycle for OC1A (Pin 9)
		//OCR1B = 255;  // Duty cycle for OC1B (Pin 10)
		//OCR2A = 255;  // Duty cycle for OC2A (Pin 11)
		//OCR2B = 255; // Duty cycle for OC2B (Pin 3)
		uint16_t temperature = 46;

		// Calculate fan percentage using the fan curve
		uint8_t fanPercentage = CalculateFanPercentage(temperature);

		// Convert fan percentage to PWM value (assuming linear mapping from 0-100% to 0-255)
		uint8_t pwmValue = (fanPercentage * 255) / 100;

		OCR0A = pwmValue; // Duty cycle for OC0A (Pin 6)
		OCR0B = pwmValue;  // Duty cycle for OC0B (Pin 5)
		OCR1A = pwmValue; // Duty cycle for OC1A (Pin 9)
		OCR1B = pwmValue;  // Duty cycle for OC1B (Pin 10)
		OCR2A = pwmValue;  // Duty cycle for OC2A (Pin 11)
		OCR2B = pwmValue; // Duty cycle for OC2B (Pin 3)

		_delay_ms(100); // Delay for demonstration
	}
}

 
 
 