#include <device/vga.h>
#include <libc/mem.h>

void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len) {
  const uint8_t *sp = (const uint8_t *)src;
  uint8_t *dp = (uint8_t *)dest;
  for (; len != 0; len--)
    *dp++ = *sp++;
}

void memset(uint8_t *dest, uint8_t val, uint32_t len) {
  uint8_t *temp = (uint8_t *)dest;
  for (; len != 0; len--)
    *temp++ = val;
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
