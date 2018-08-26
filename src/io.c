#include <io.h>

uint8 inb(uint16 port) {
  uint8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
  return ret;
}

void outb(uint16 port, uint8 value) {
  asm volatile("outb %1, %0" : : "dN"(port), "a"(value));
}


uint16 inw(uint16 port) {
  uint16 ret;
  asm volatile("inw %1, %0" : "=a"(ret) : "dN"(port));
  return ret;
}

void outw(uint16 port, uint16 value) {
  asm volatile("outw %1, %0" : : "dN"(port), "a"(value));
}
