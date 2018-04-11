/*
 * kernel.h -- Defines typdefs and some global functions
 */

#ifndef KERNEL_H
#define KERNEL_H

#include <types.h>


#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(#b, __FILE__, __LINE__))

void panic(const char *message, const char *file, uint32 line);
void panic_assert(const char *desc, const char *file, uint32 line);

#endif // KERNEL_H
