#include <kernel.h>
#include <vga.h>
#include <descriptors.h>
#include <timer.h>
#include <keyboard.h>
#include <multiboot.h>
#include <mem.h>

void kmain(struct multiboot_header *mboot_ptr)
{
  init_descriptors();

  vga_clear();
  vga_write("test");

  asm volatile("sti"); // Enable interrupts
  init_keyboard();

  vga_write("Start of text: ");
  vga_write_hex(text);
  vga_put('\n');



  for(;;);
}
