#include <stdint.h>
#include "builtin_led.h"
#include "basic_gpio.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"


void busyWait(void){
	uint32_t i;
	for (i=0; i< 100000; i++);
}

int main(void)
{
  LED_Configure(BLUE);
  LED_Configure(RED);

	GPIO_Configuration testConfig = {PORTE,Pin_5 , LOGIC_HIGH, Digital,GPIO, Output, Disable_internal_resistor};
	GPIO_init(&testConfig);

    while (1)
    {
			if (GPIO_readData(PORTE, Pin_5)){
				busyWait();
				LED_Enable(BLUE);
				busyWait();
				LED_Enable(RED);
			}else{
				LED_Disable();
			}
    }

}
