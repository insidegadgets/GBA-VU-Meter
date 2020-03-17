/*
 GBA VU Meter
 Version: 1.0
 Author: Alex from insideGadgets (http://www.insidegadgets.com)
 Created: 17/03/2020
 Last Modified: 17/03/2020
 
 Connect to the GBA SP pin with 0.1uF and 10K resistor to PC3. Values can be adjusted to suit.
 
*/

#define F_CPU 1000000 // 1 MHz

#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include "setup.c"

int main (void) {
	setup();
	
	while(1) {
		
		uint16_t vuResult = adc_read(ADCPin, REF_1_1V);
		//_delay_ms(1);
		
		uint16_t startCompare = 560; // Play around with this to suit your needs
		
		
		// Red
		if (vuResult >= startCompare) {
			PORTD |= (1<<LED1);
		}
		else {
			PORTD &= ~(1<<LED1);
		}
		if (vuResult >= startCompare + 20) {
			PORTD |= (1<<LED2);
		}
		else {
			PORTD &= ~(1<<LED2);
		}
		if (vuResult >= startCompare + 30) {
			PORTD |= (1<<LED3);
		}
		else {
			PORTD &= ~(1<<LED3);
		}
		
		// Blue
		if (vuResult >= startCompare + 40) {
			PORTD |= (1<<LED4);
		}
		else {
			PORTD &= ~(1<<LED4);
		}
		if (vuResult >= startCompare + 50) {
			PORTB |= (1<<LED5);
		}
		else {
			PORTB &= ~(1<<LED5);
		}
		if (vuResult >= startCompare + 60) {
			PORTD |= (1<<LED6);
		}
		else {
			PORTD &= ~(1<<LED6);
		}
		if (vuResult >= startCompare + 70) {
			PORTD |= (1<<LED7);
		}
		else {
			PORTD &= ~(1<<LED7);
		}
		
		// Green
		if (vuResult >= startCompare + 80) {
			PORTD |= (1<<LED8);
		}
		else {
			PORTD &= ~(1<<LED8);
		}
		if (vuResult >= startCompare + 90) {
			PORTB |= (1<<LED9);
		}
		else {
			PORTB &= ~(1<<LED9);
		}
		if (vuResult >= startCompare + 100) {
			PORTB |= (1<<LED10);
		}
		else {
			PORTB &= ~(1<<LED10);
		}
		
	}
	
	return 0;
}

EMPTY_INTERRUPT(ADC_vect);
EMPTY_INTERRUPT(WDT_vect);
