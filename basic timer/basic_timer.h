#ifndef BASIC_TIMER_H_
#define BASIC_TIMER_H_
#include <stdint.h>

/********************************************************/
/* Type definitions */
/********************************************************/

typedef enum {
    one_shot = 0x1, periodic = 0x2
} Timer_mode;

typedef enum{
    Timer0 = 0,
    Timer1 = 1,
    Timer2 = 2,
    Timer3 = 3
} Timer_ID;

typedef enum{
    Count_down=0, Count_up=1
}Timer_Direction;

typedef struct{
	Timer_ID timer_ID;
	Timer_mode mode;
    Timer_Direction dir;
	uint16_t compareValue;
}Timer_configuration;


/********************************************************/
/* Function Prototypes */
/********************************************************/

/*
Description: A function to intialize the timer, supports One-shot and Periodic modes
                - Enable timer clock and its port clock
                - set alternate function
                - configure counting up or counting down
                - set compare value 
                - Enable the timer to start counting!

*/
void Timer_init(const Timer_configuration* timer_config);

/*
Description: A function to check whether the timer is timed-out or not
            - return 1 if it's timed-out, 0 otherwise
            - if it's timed-out, clear time-out flag
*/
uint8_t Timer_is_time_out(Timer_ID timer_id);

#endif /* BASIC_TIMER_H_ */
