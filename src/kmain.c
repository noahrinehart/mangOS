#include <kernel.h>
#include <vga.h>
#include <descriptors.h>
#include <timer.h>
#include <keyboard.h>
#include <multiboot.h>

void kmain(struct multiboot_header *mboot_ptr)
{
  init_descriptors();

  vga_clear();

  asm volatile("sti"); // Enable interrupts
  init_keyboard();

  for(;;);
}
