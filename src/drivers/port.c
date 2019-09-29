#include <drivers/port.h>

uint8_t inb(uint16_t port) {
  uint8_t ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
  return ret;
}

void outb(uint16_t port, uint8_t value) { asm volatile("outb %1, %0" : : "dN"(port), "a"(value)); }

uint16_t inw(uint16_t port) {
  uint16_t ret;
  asm volatile("inw %1, %0" : "=a"(ret) : "dN"(port));
  return ret;
}

void outw(uint16_t port, uint16_t value) { asm volatile("outw %1, %0" : : "dN"(port), "a"(value)); }
