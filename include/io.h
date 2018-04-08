#ifndef IO_H
#define IO_H

#include <kernel.h>

void outb(uint16 port, uint8 value);
uint8 inb(uint16 port);
uint16 inw(uint16 port);

#endif
