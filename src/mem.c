#include <mem.h>

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

