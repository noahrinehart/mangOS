#include <kernel.h>
#include <vga.h>
#include <descriptors.h>
#include <timer.h>
#include <keyboard.h>
#include <multiboot.h>
#include <mem.h>
#include <cmos.h>

void kmain(struct multiboot_header *mboot_ptr)
{
  init_descriptors();

  vga_clear();

  vga_write("                              ___  ____  \n");
  vga_write(" _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n");
  vga_write("| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n");
  vga_write("| | | | | | (_| | | | | (_| | |_| |___) |\n");
  vga_write("|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n");
  vga_write("                       |___/             \n");

  print_mem_values();

  asm volatile("sti"); // Enable interrupts
  init_keyboard();

  read_rtc();

  for(;;);
}
