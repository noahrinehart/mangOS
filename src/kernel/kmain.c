#include <device/cmos.h>
#include <device/keyboard.h>
#include <device/timer.h>
#include <device/vga.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/interrupts.h>
#include <kernel/kmem.h>
#include <multiboot.h>
#include <types.h>

const char *logo = "                              ___  ____  \n"
                   " _ __ ___   __ _ _ __   __ _ / _ \\/ ___| \n"
                   "| '_ ` _ \\ / _` | '_ \\ / _` | | | \\___ \\ \n"
                   "| | | | | | (_| | | | | (_| | |_| |___) |\n"
                   "|_| |_| |_|\\__,_|_| |_|\\__, |\\___/|____/ \n"
                   "                       |___/             \n";

void print_mem_values();
int kmain(uint32_t multiboot_magic, void *multiboot_info) {

  vga_clear();

  // check_multiboot(multiboot_magic, multiboot_info);

  init_gdt();
  init_idt();

  init_keyboard();
  init_timer();

  // vga_puts(logo);

  read_rtc();
  print_rtc();

  ENABLE_INT();

  // print_mem_values();

  return 0;
}

void print_mem_values() {
  vga_printf("Base: 0x%x\n", (uint32_t)base);
  vga_printf("Virtual start: 0x%x\n", (uint32_t)kernel_virtual_start);
  vga_printf("Physical start: 0x%x\n", (uint32_t)kernel_physical_start);
  vga_printf("Start of text: 0x%x\n", (uint32_t)text);
  vga_printf("End of text: 0x%x\n", (uint32_t)etext);
  vga_printf("Start of rodata: 0x%x\n", (uint32_t)rodata);
  vga_printf("End of rodata: 0x%x\n", (uint32_t)erodata);
  vga_printf("Start of data: 0x%x\n", (uint32_t)data);
  vga_printf("End of data: 0x%x\n", (uint32_t)edata);
  vga_printf("Start of bss: 0x%x\n", (uint32_t)bss);
  vga_printf("End of bss: 0x%x\n", (uint32_t)ebss);
  vga_printf("Virtual end: 0x%x\n", (uint32_t)kernel_virtual_end);
  vga_printf("Physical end: 0x%x\n", (uint32_t)kernel_physical_end);
}