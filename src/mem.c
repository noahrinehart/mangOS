#include <mem.h>
#include <vga.h>

void memcpy(uint8 *dest, const uint8 *src, uint32 len) {
  const uint8 *sp = (const uint8 *)src;
  uint8 *dp = (uint8 *)dest;
  for (; len != 0; len--)
    *dp++ = *sp++;
}

void memset(uint8 *dest, uint8 val, uint32 len) {
  uint8 *temp = (uint8 *)dest;
  for (; len != 0; len--)
    *temp++ = val;
}

void print_mem_values() {
  vga_write("Start: ");
  vga_put_hex((uint32)base);
  vga_put('\n');

  vga_write("Start of text: ");
  vga_put_hex((uint32)text);
  vga_put('\n');

  vga_write("End of text: ");
  vga_put_hex((uint32)etext);
  vga_put('\n');

  vga_write("Start of data: ");
  vga_put_hex((uint32)data);
  vga_put('\n');

  vga_write("End of data: ");
  vga_put_hex((uint32)edata);
  vga_put('\n');

  vga_write("Start of bss: ");
  vga_put_hex((uint32)bss);
  vga_put('\n');

  vga_write("End of bss: ");
  vga_put_hex((uint32)ebss);
  vga_put('\n');

  vga_write("End: ");
  vga_put_hex((uint32)end);
  vga_put('\n');
}
