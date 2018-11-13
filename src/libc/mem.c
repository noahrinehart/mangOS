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
