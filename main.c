#include <msp430.h>

#include "qrencode.h"
#include "pcd8544.h"

int main(void)
{
	int i, j, k;
	unsigned char data;
	WDTCTL = WDTPW + WDTHOLD; // stop watchdog

	CSCTL0_H = 0xA5;
	CSCTL1 |= DCORSEL + DCOFSEL0 + DCOFSEL1;   // Set max. DCO setting
	CSCTL2 = SELA_3 + SELS_3 + SELM_3;        // set ACLK = MCLK = DCO
	CSCTL3 = DIVA_0 + DIVS_0 + DIVM_0;        // set all dividers to 0

	strcpy(strinbuf, "http://www.skullspace.ca/");

	qrencode();

	LCD_init();

	for (i = 0; i < 6; i++) {
		// 6 rows
		LCD_gotoXY(0, i);
		for (j = 0; j < WD; j++) {
			// WD = number of columns
			data = 0;
			for (k = 0; k < 8; k++) {
				// 8 pixels
				data |= QRBIT(j, ((i*8)+k)) << k;
			}
			LCD_write(LCD_DATA, data);
		}
	}

	for(;;);
}

