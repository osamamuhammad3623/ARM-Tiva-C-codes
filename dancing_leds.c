#include <stdint.h>
#include "builtin_led.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"


void busyWait(void){
	uint32_t i;
	for (i=0; i< 100000; i++);
}

int main(void)
{
    LED_Configure(BLUE);
    LED_Configure(RED);

    while (1)
    {
      busyWait();
			LED_Enable(BLUE);
			busyWait();
			LED_Enable(RED);
    }

}
