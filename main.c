#include <msp430.h>

#include "qrencode.h"
#include "pcd8544.h"

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // stop watchdog

	CSCTL0_H = 0xA5;
	CSCTL1 |= DCORSEL + DCOFSEL0 + DCOFSEL1;   // Set max. DCO setting
	CSCTL2 = SELA_3 + SELS_3 + SELM_3;        // set ACLK = MCLK = DCO
	CSCTL3 = DIVA_0 + DIVS_0 + DIVM_0;        // set all dividers to 0

	strinbuf[0] = 'y';
	strinbuf[1] = 'o';
	strinbuf[2] = '!';
	strinbuf[3] = '\0';	

	qrencode();

	LCD_init();
	LCD_gotoXY(0,0);
	LCD_writeString("BSidesWpg 13");
	
	for(;;);
}

