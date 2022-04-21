#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include <stdint.h>
#include "sys_tick.h"
#include "common_macros.h"

static volatile void (*g_CallBackPtr)(void) = 0;

void SYSTICK_init(uint32_t value, void (* callBackFunction )()){
	CLEAR_BIT(NVIC_ST_CTRL_R, NVIC_ST_CTRL_ENABLE); /* disable the timer */
	NVIC_ST_RELOAD_R = value-1; /* set compare value */
	NVIC_ST_CURRENT_R = 0; /* clear current ticks */
	SET_BIT(NVIC_ST_CTRL_R, 2);  /* set clock source to System Clock */
	SET_BIT(NVIC_ST_CTRL_R, 1);  /* enable sys tick interrupts */
	g_CallBackPtr = callBackFunction; /* set the call-back function */
}

void SYSTICK_start(void){
	SET_BIT(NVIC_ST_CTRL_R, 0); /* enable timer [start counting] */
}

void SYSTICK_stop(void){
	CLEAR_BIT(NVIC_ST_CTRL_R, 0); /* disable sys tick timer */
}

void SysTick_Handler(void){
	if (g_CallBackPtr != 0){
		(*g_CallBackPtr)();
		NVIC_ST_CURRENT_R = 0; /* clear the count flag */
	}
}