#ifndef TIMER_H
#define TIMER_H

#include <types.h>

#define CLOCK_FREQUENCY 1000

/**
 * Current tick of clock
 */
extern uint32_t clktick;

/**
 * Initialize timer
 */
void init_timer(void);

#endif // TIMER_H

