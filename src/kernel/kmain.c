#include <device/cmos.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/kernel.h>
#include <device/keyboard.h>
#include <libc/mem.h>
#include <kernel/multiboot.h>
#include <device/timer.h>
#include <device/vga.h>

const char *logo = "                              ___  ____  \n"
                   " _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n"
                   "| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n"
                   "| | | | | | (_| | | | | (_| | |_| |___) |\n"
                   "|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n"
                   "                       |___/             \n";

extern void init_paging();

void kmain(const uint32_t mboot_magic, void *mboot_info) {

  init_gdt();
  init_idt();

  init_paging();

  init_keyboard();
  init_timer();

  ENABLE_INT();

  read_rtc();

  vga_clear();

  check_multiboot(mboot_magic, mboot_info);

  vga_printf(logo);

  vga_printf("\nCurrent time: %d/%d/%d\t%d:%d:%d\n\n", month, day, year, hour,
             minute, second);
  print_mem_values();
}
