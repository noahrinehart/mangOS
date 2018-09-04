
#include <kernel.h>
#include <vga.h>

void panic(const char *message, const char *file, uint32_t line) {
  asm volatile("cli"); // Disable interrupts
  vga_write("PANIC(");
  vga_write(message);
  vga_write(") at ");
  vga_write(file);
  vga_write(":");
  vga_put_dec(line);
  vga_write("\n");
  for (;;)
    ; // Infinite loop
}

void panic_assert(const char *message, const char *desc, const char *file,
                  uint32_t line) {
  asm volatile("cli"); // Disable interrupts
  vga_write("ASSERTION FAILED ");
  vga_write(message);
  vga_write(" (");
  vga_write(desc);
  vga_write(") at ");
  vga_write(file);
  vga_write(":");
  vga_put_dec(line);
  vga_write("\n");
  for (;;)
    ; // Infinite loop
}
