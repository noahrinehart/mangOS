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

  vga_printf("                              ___  ____  \n");
  vga_printf(" _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n");
  vga_printf("| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n");
  vga_printf("| | | | | | (_| | | | | (_| | |_| |___) |\n");
  vga_printf("|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n");
  vga_printf("                       |___/             \n");

  print_mem_values();

  asm volatile("sti"); // Enable interrupts
  init_keyboard();

  read_rtc();
  vga_printf("Current time: %d/%d/%d\t%d:%d:%d", month, day, year, hour, minute, second);

  for(;;);
}
