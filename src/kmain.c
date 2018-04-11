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
  if (!check_multiboot(mboot_ptr)) {
    PANIC("Multiboot check failed!");
  }

  init_descriptors();

  ENABLE_INT();

  init_keyboard();
  read_rtc();

  vga_clear();
  vga_printf("                              ___  ____  \n");
  vga_printf(" _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n");
  vga_printf("| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n");
  vga_printf("| | | | | | (_| | | | | (_| | |_| |___) |\n");
  vga_printf("|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n");
  vga_printf("                       |___/             \n");

  vga_printf("\nCurrent time: %d/%d/%d\t%d:%d:%d\n\n", month, day, year, hour, minute, second);

  print_mem_values();

  for(;;);
}
