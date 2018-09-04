/*
 * kernel.h -- Defines typdefs and some global functions
 */

#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

#define DISABLE_INT() asm volatile("cli")
#define ENABLE_INT() asm volatile("sti")

#define PANIC(msg) panic(msg, __FILE__, __LINE__)
#define ASSERT(msg, b)                                                         \
  ((b) ? (void)0 : panic_assert(msg, #b, __FILE__, __LINE__))

void panic(const char *message, const char *file, uint32_t line);
void panic_assert(const char *message, const char *desc, const char *file,
                  uint32_t line);

#endif // KERNEL_H
