#include <kernel.h>
#include <vga.h>
#include <descriptors.h>

void kmain(void)
{
  init_descriptors();
  
  vga_clear();
  vga_write("Hello, World!");

  for(;;);
}
