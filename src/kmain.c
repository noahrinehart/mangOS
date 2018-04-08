#include <kernel.h>
#include <vga.h>
#include <descriptors.h>
#include <timer.h>
#include <keyboard.h>

void kmain(void)
{
  init_descriptors();

  vga_clear();

  asm volatile("sti");
  init_keyboard();


  for(;;);
}
