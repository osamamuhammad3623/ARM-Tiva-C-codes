#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include <stdint.h>

/********************************************************/
/* Function Prototypes */
/********************************************************/

/*
Description: Initialize the SysTick timer with given value and a pointer to call-back function for the ISR
					- using system clock & interrupts 
*/
void SYSTICK_init(uint32_t value, void (* callBackFunction )());

/*
Description: Enable SysTick timer to start counting
*/
void SYSTICK_start(void);

/*
Description: Disable SysTick timer
*/
void SYSTICK_stop(void);

#endif /* SYS_TICK_H_ */
