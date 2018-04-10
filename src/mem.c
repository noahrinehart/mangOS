#include <mem.h>
#include <vga.h>

void memcpy(uint8 *dest, const uint8 *src, uint32 len)
{
  const uint8 *sp = (const uint8 *)src;
  uint8 *dp = (uint8 *)dest;
  for(; len != 0; len--) *dp++ = *sp++;
}

void memset(uint8 *dest, uint8 val, uint32 len)
{   
  uint8 *temp = (uint8 *)dest;
  for ( ; len != 0; len--) *temp++ = val;
}

void print_mem_values()
{
  vga_write("Start: ");
  vga_write_hex(base);
  vga_put('\n');

  vga_write("Start of text: ");
  vga_write_hex(text);
  vga_put('\n');

  vga_write("End of text: ");
  vga_write_hex(etext);
  vga_put('\n');

  vga_write("Start of data: ");
  vga_write_hex(data);
  vga_put('\n');

  vga_write("End of data: ");
  vga_write_hex(edata);
  vga_put('\n');

  vga_write("Start of bss: ");
  vga_write_hex(bss);
  vga_put('\n');

  vga_write("End of bss: ");
  vga_write_hex(ebss);
  vga_put('\n');

  vga_write("End: ");
  vga_write_hex(end);
  vga_put('\n');
}
