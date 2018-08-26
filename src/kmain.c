#include <cmos.h>
#include <descriptors.h>
#include <kernel.h>
#include <keyboard.h>
#include <mem.h>
#include <multiboot.h>
#include <timer.h>
#include <vga.h>

void kmain() {
  init_descriptors();
  init_keyboard();
  init_timer();

  ENABLE_INT();
  
  read_rtc();

  vga_printf("                              ___  ____  \n");
  vga_printf(" _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n");
  vga_printf("| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n");
  vga_printf("| | | | | | (_| | | | | (_| | |_| |___) |\n");
  vga_printf("|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n");
  vga_printf("                       |___/             \n");

  vga_printf("\nCurrent time: %d/%d/%d\t%d:%d:%d\n\n", month, day, year, hour,
             minute, second);
  print_mem_values();
}
