#include <device/keyboard.h>
#include <device/timer.h>
#include <device/vga.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/interrupts.h>
#include <libc/mem.h>
#include <multiboot.h>
#include <types.h>

const char *logo = "                              ___  ____  \n"
                   " _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n"
                   "| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n"
                   "| | | | | | (_| | | | | (_| | |_| |___) |\n"
                   "|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n"
                   "                       |___/             \n";

int kmain(uint32_t multiboot_magic, void *multiboot_info) {

  vga_clear();

  check_multiboot(multiboot_magic, multiboot_info);

  init_gdt();
  init_idt();

  init_keyboard();
  init_timer();

  // vga_puts(logo);

  ENABLE_INT();

  // print_mem_values();

  return 0;
}
