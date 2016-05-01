#include <stdint.h>
#include <msp430.h>
#include "header.h"

//Function to allow serial communication with shift register
void serial_com(uint8_t data_pin, uint8_t clk_pin, uint8_t value){

	// Definitions of variables
	uint8_t bytemask = 0b00000001, k;

	// Loop that iterates through value to send it
	for(k = 8; k > 0; k--){

		// Set data_pin to output current 1/8th of value
		P1OUT &= !data_pin;
		P1OUT |= (value & bytemask) >> (7 - k);

		// Set clk_pin to high then back to low in order to send the data to the register
		P1OUT ^= clk_pin;
		P1OUT ^= clk_pin;

		// Increment output to next 1/8th of value
		bytemask <<= 1;
	}
}
