#include "basic_timer.h"
#include <stdint.h>
#include "common_macros.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"


#define PORTB	1
/* Global pointers to call-back functions of the 4 timers supported by this driver */
static volatile void (*g_Timer0CallBackPtr)(void) = 0;
static volatile void (*g_Timer1CallBackPtr)(void) = 0;
static volatile void (*g_Timer2CallBackPtr)(void) = 0;
static volatile void (*g_Timer3CallBackPtr)(void) = 0;

void Timer_init(const Timer_configuration *timer_config) {

	SET_BIT(SYSCTL_RCGCTIMER_R, timer_config->timer_ID); /* enable clock for timer*/
	SET_BIT(SYSCTL_RCGCGPIO_R, PORTB); /* enable clock for port B */
	GPIO_PORTB_PCTL_R |= 7; /* set alternate function [from table]*/

	if (timer_config->timer_ID == Timer0) {

		CLEAR_BIT(TIMER0_CTL_R, 0); /* disable timer0 */
		TIMER0_CFG_R = 0; /* configuration register */
		TIMER0_TAMR_R = timer_config->mode; /* set timer mode */
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER0_TAMR_R, TIMER_TAMR_TACDIR); /* config to count down [Pin 4] */
		} else {
			SET_BIT(TIMER0_TAMR_R, TIMER_TAMR_TACDIR);
		}
	
		SET_BIT(TIMER0_IMR_R, 0);/* Timer A Time-Out Interrupt Mask */
		SET_BIT(NVIC_EN0_R ,19); /* enable timer 2A interrupt in NVIC table */
		TIMER0_TAILR_R = timer_config->compareValue; /* set compare value */

		TIMER0_CTL_R = 1; /* enable timer to start counting */
		g_Timer0CallBackPtr = timer_config->callBack; /* set the call-back function */

	} else if (timer_config->timer_ID == Timer1) {

		CLEAR_BIT(TIMER1_CTL_R, 0);
		TIMER1_CFG_R = 0;
		TIMER1_TAMR_R = timer_config->mode;
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER1_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER1_TAMR_R, TIMER_TAMR_TACDIR);
		}

		SET_BIT(TIMER1_IMR_R, 0);/* Timer A Time-Out Interrupt Mask */
		SET_BIT(NVIC_EN0_R ,21); /* enable timer 2A interrupt in NVIC table */
		TIMER1_TAILR_R = timer_config->compareValue;

		TIMER1_CTL_R = 1;
		g_Timer1CallBackPtr = timer_config->callBack;

	} else if (timer_config->timer_ID == Timer2) {

		CLEAR_BIT(TIMER2_CTL_R, 0);
		TIMER2_CFG_R = 0;
		TIMER2_TAMR_R = timer_config->mode;
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER2_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER2_TAMR_R, TIMER_TAMR_TACDIR);
		}
		SET_BIT(TIMER2_IMR_R, 0); /* enable time-out interrupt */
		SET_BIT(NVIC_EN0_R ,23); /* enable timer 2A interrupt in NVIC table */
		TIMER2_TAILR_R = timer_config->compareValue;

		TIMER2_CTL_R = 1;
		g_Timer2CallBackPtr = timer_config->callBack;

	} else if (timer_config->timer_ID == Timer3) {

		CLEAR_BIT(TIMER3_CTL_R, 0);
		TIMER3_CFG_R = 0;
		TIMER3_TAMR_R = timer_config->mode;
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER3_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER3_TAMR_R, TIMER_TAMR_TACDIR);
		}
		
		SET_BIT(TIMER3_IMR_R, 0);/* Timer A Time-Out Interrupt Mask */
		SET_BIT(NVIC_EN1_R ,3); /* enable timer3 2A interrupt in NVIC table */
		TIMER3_TAILR_R = timer_config->compareValue;

		TIMER3_CTL_R = 1;
		g_Timer3CallBackPtr = timer_config->callBack;
	}
}

void TIMER0A_Handler(void){
	if (g_Timer0CallBackPtr != 0){
		(*g_Timer0CallBackPtr)();
		SET_BIT(TIMER0_ICR_R, 0); /* clear the count flag */
	}
}

void TIMER1A_Handler(void){
	if (g_Timer1CallBackPtr != 0){
		(*g_Timer1CallBackPtr)();
		SET_BIT(TIMER1_ICR_R, 0); /* clear the count flag */
	}
}

void TIMER2A_Handler(void){
	if (g_Timer2CallBackPtr != 0){
		(*g_Timer2CallBackPtr)();
		SET_BIT(TIMER2_ICR_R, 0); /* clear the count flag */
	}
}

void TIMER3A_Handler(void){
	if (g_Timer3CallBackPtr != 0){
		(*g_Timer3CallBackPtr)();
		SET_BIT(TIMER3_ICR_R, 0); /* clear the count flag */
	}
}
