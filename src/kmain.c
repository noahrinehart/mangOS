#include <kernel.h>
#include <vga.h>

void kmain(void)
{
  vga_clear();
  vga_write("Hello, World!");
  for(;;);
}
