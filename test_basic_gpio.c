#include <stdint.h>
#include "builtin_led.h"
#include "basic_gpio.h"
#include "builtin_switch.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"


void busyWait(void){
	uint32_t i;
	for (i=0; i< 100000; i++);
}

int main(void)
{
  LED_Configure(BLUE);
  Switch_Configure(SW1);

	GPIO_Configuration testConfig = {PORTE,Pin_5 , LOGIC_LOW, Digital,GPIO, Output, Disable_internal_resistor};
	GPIO_init(&testConfig);

    while (1)
    {
			if (GPIO_readData(PORTE, Pin_5)){
				busyWait();
				LED_Enable(BLUE);

			}else{
				LED_Disable();
			}

			/* Turn on LED as long as user switch 1 is pressed */
			if (Switch_isPressed(SW1)){
			    GPIO_writeData(PORTE, Pin_5, LOGIC_HIGH);
			}else{
			    GPIO_writeData(PORTE, Pin_5, LOGIC_LOW);
			}
    }

}
