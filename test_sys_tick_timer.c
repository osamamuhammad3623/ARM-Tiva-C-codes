#include <stdio.h>
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include "sys_tick.h"
#include "builtin_led.h"

uint16_t i =1;
void turnOnLED(void){
	i++;
	if (i%2){ LED_Enable(BLUE);}
	else {LED_Disable();}
}

int main(void){

	SYSTICK_init(0xFF, turnOnLED);
	LED_Configure(BLUE);
	
	SYSTICK_start();
	
	while (1);
		/* do nothing */

}

