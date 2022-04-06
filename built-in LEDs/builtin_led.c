#include "builtin_led.h"
#include <stdint.h>
#include "common_macros.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"

void LED_Configure(LED_Color color)
{
    SYSCTL_RCGCGPIO_R |= (1 << 5); /* enable clock for port F */
    SET_BIT(GPIO_PORTF_DIR_R , color);
    CLEAR_BIT(GPIO_PORTF_AFSEL_R , color);
    SET_BIT(GPIO_PORTF_DEN_R , color);
    CLEAR_BIT(GPIO_PORTF_DATA_R , color);
}

void LED_Enable(LED_Color color)
{
    GPIO_PORTF_DATA_R = (1<<color);
}

void LED_Toggle(LED_Color color){
		GPIO_PORTF_DATA_R ^= (1<<color);
}

void LED_Disable(void)
{
    GPIO_PORTF_DATA_R &= (~(0xE));  // clear bits 1,2 and 3 -> 0b1110
}
