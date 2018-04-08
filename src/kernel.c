
#include <kernel.h>
#include <vga.h>

void outb(uint16 port, uint8 value)
{
  asm volatile("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8 inb(uint16 port)
{
  uint8 ret;
  asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

uint16 inw(uint16 port)
{
  uint16 ret;
  asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

void panic(const char *message, const char *file, uint32 line)
{
  asm volatile("cli");  // Disable interrupts
  vga_write("PANIC(");
  vga_write(message);
  vga_write(") at ");
  vga_write(file);
  vga_write(":");
  vga_write_dec(line);
  vga_write("\n");
  for(;;); // Infinite loop
}

void panic_assert(const char *desc, const char *file, uint32 line)
{
  asm volatile("cli");  // Disable interrupts
  vga_write("ASSERTION FAILED(");
  vga_write(desc);
  vga_write(") at ");
  vga_write(file);
  vga_write(":");
  vga_write_dec(line);
  vga_write("\n");
  for(;;); // Infinite loop
}

