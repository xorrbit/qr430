#include <msp430.h>

#include "qrencode.h"

int main(void)
{
	int i;

	WDTCTL = WDTPW + WDTHOLD; // stop watchdog
	P1DIR |= BIT0; //p1.0 is output pin

	for (;;) { // loop forever
		P1OUT ^= BIT0; // toggle
		
		i = 5000; // delay
		do (i--);
		while (i != 0);

	}
}

