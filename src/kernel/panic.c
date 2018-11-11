#include <device/vga.h>
#include <kernel/panic.h>

void panic(const char *message, const char *file, uint32_t line) {
  asm volatile("cli"); // Disable interrupts
  vga_printf("PANIC(%s) at %s: %d\n", message, file, line);
  while (true)
    ; // Infinite loop
}

void panic_assert(const char *message, const char *desc, const char *file,
                  uint32_t line) {
  asm volatile("cli"); // Disable interrupts
  vga_printf("ASSERTION FAILED %s (%s) at %s: %d\n", message, desc, file, line);
  while (true)
    ; // Infinite loop
}