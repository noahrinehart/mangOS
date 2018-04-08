#include <kernel.h>
#include <vga.h>
#include <descriptors.h>
#include <timer.h>
#include <keyboard.h>
#include <multiboot.h>

void kmain(multiboot_info_t *mboot_ptr)
{
  init_descriptors();

  vga_clear();

  asm volatile("sti"); // Enable interrupts
  init_keyboard();

  vga_write(mboot_ptr->boot_loader_name);

  for(;;);
}
