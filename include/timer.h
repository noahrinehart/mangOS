#ifndef TIMER_H
#define TIMER_H

#include <kernel.h>

#define CLOCK_FREQUENCY 1000

/**
 * Current tick of clock
 */
extern uint32 clktick;

/**
 * Initialize timer
 */
void init_timer();

#endif // TIMER_H
