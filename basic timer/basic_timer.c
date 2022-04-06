#include "basic_timer.h"
#include <stdint.h>
#include "common_macros.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"

#define PORTB	1

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

		TIMER0_TAILR_R = timer_config->compareValue; /* set compare value */

		TIMER0_CTL_R = 1; /* enable timer to start counting */

	} else if (timer_config->timer_ID == Timer1) {

		CLEAR_BIT(TIMER1_CTL_R, 0);
		TIMER1_CFG_R = 0;
		TIMER1_TAMR_R = timer_config->mode;
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER1_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER1_TAMR_R, TIMER_TAMR_TACDIR);
		}

		TIMER1_TAILR_R = timer_config->compareValue;

		TIMER1_CTL_R = 1;

	} else if (timer_config->timer_ID == Timer2) {

		CLEAR_BIT(TIMER2_CTL_R, 0);
		TIMER2_CFG_R = 0;
		TIMER2_TAMR_R = timer_config->mode;
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER2_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER2_TAMR_R, TIMER_TAMR_TACDIR);
		}

		TIMER2_TAILR_R = timer_config->compareValue;

		TIMER2_CTL_R = 1;

	} else if (timer_config->timer_ID == Timer3) {

		CLEAR_BIT(TIMER3_CTL_R, 0);
		TIMER3_CFG_R = 0;
		TIMER3_TAMR_R = timer_config->mode;
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER3_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER3_TAMR_R, TIMER_TAMR_TACDIR);
		}

		TIMER3_TAILR_R = timer_config->compareValue;

		TIMER3_CTL_R = 1;
	}
}

uint8_t Timer_is_time_out(Timer_ID timer_id) {

	if (timer_id == Timer0) {
		if (BIT_IS_CLEAR(TIMER0_RIS_R, timer_id)) {
			TIMER0_ICR_R = 1; /* clear time-out flag */
			return 1;
		}

	} else if (timer_id == Timer1) {
		if (BIT_IS_CLEAR(TIMER1_RIS_R, timer_id)) {
			TIMER1_ICR_R = 1;
			return 1;
		}

	} else if (timer_id == Timer2) {
		if (BIT_IS_CLEAR(TIMER2_RIS_R, timer_id)) {
			TIMER2_ICR_R = 1;
			return 1;
		}

	} else if (timer_id == Timer3) {
		if (BIT_IS_CLEAR(TIMER3_RIS_R, timer_id)) {
			TIMER3_ICR_R = 1;
			return 1;
		}
	}
	return 0;
}
