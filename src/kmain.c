#include <gdt.h>
#include <idt.h>
#include <cmos.h>
#include <kernel.h>
#include <keyboard.h>
#include <mem.h>
#include <multiboot.h>
#include <timer.h>
#include <vga.h>

void kmain(const uint32_t eax, const uint32_t ebx) {
  init_gdt();
  init_idt();
  init_keyboard();
  init_timer();

  ENABLE_INT();

  read_rtc();

  vga_clear();

  check_multiboot(eax, ebx);

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
