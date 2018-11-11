#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#define DISABLE_INT() asm volatile("cli")
#define ENABLE_INT() asm volatile("sti")

#endif // INTERRUPTS_H