#ifndef TIMER_H
#define TIMER_H

#include <kernel.h>

#define CLOCK_FREQUENCY 1000


extern uint32 clktick;
void init_timer();

#endif // TIMER_H
