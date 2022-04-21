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
	void (* callBack) (void); /* pointer to call-back function */
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

#endif /* BASIC_TIMER_H_ */
