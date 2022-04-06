#include <stdint.h>
#include "builtin_led.h"
#include "builtin_switch.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"


int main(void){

	Switch_Configure(SW1);
	LED_Configure(BLUE);
	LED_Configure(GREEN);
	
	while(1){
		
		if (Switch_isPressed(SW1)){
			LED_Enable(BLUE);
			
		}else if (Switch_isPressed(SW2)){
			LED_Enable(GREEN);
			
		}else{
			LED_Disable();
		}
	
	}
}