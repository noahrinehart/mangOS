#ifndef TIMER_H
#define TIMER_H

#include <kernel.h>

extern uint32 clktick;
void init_timer(uint32 frequency);

#endif // TIMER_H
