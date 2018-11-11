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

/* void print_mem_values() { */
/*   vga_write("Start: "); */
/*   vga_put_hex((uint32_t)base); */
/*   vga_put('\n'); */

/*   vga_write("Start of text: "); */
/*   vga_put_hex((uint32_t)text); */
/*   vga_put('\n'); */

/*   vga_write("End of text: "); */
/*   vga_put_hex((uint32_t)etext); */
/*   vga_put('\n'); */

/*   vga_write("Start of data: "); */
/*   vga_put_hex((uint32_t)data); */
/*   vga_put('\n'); */

/*   vga_write("End of data: "); */
/*   vga_put_hex((uint32_t)edata); */
/*   vga_put('\n'); */

/*   vga_write("Start of bss: "); */
/*   vga_put_hex((uint32_t)bss); */
/*   vga_put('\n'); */

/*   vga_write("End of bss: "); */
/*   vga_put_hex((uint32_t)ebss); */
/*   vga_put('\n'); */

/*   vga_write("End: "); */
/*   vga_put_hex((uint32_t)end); */
/*   vga_put('\n'); */
/* } */

