#include <msp430.h>

#include "qrencode.h"
#include "pcd8544.h"

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // stop watchdog
	
	LCD_init();
	LCD_gotoXY(0,0);
	LCD_writeString("BSidesWpg 13");
	
	for(;;);
}

