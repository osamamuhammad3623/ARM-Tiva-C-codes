#include <stdio.h>
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include "basic_timer.h"
#include "builtin_led.h"


void turnOnLED(void){
	LED_Toggle(RED);
}

int main(void){
		
	LED_Configure(RED);
	
	Timer_configuration timer_config = {Timer2, periodic, Count_down, 0x1F, turnOnLED};
	Timer_init(&timer_config);	

	while(1);
	
	return 0;
}
