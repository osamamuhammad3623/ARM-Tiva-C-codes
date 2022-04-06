#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include <stdint.h>
#include "builtin_led.h"
#include "basic_timer.h"

int main(void){
		
		LED_Configure(RED);
		LED_Disable();
		
		Timer_configuration timer_config = {Timer0, one_shot, Count_down, 0x10};
		Timer_init(&timer_config);	
	
		while(1){
			if (Timer_is_time_out(Timer0)){
				LED_Toggle(RED);
			}

		}
}
