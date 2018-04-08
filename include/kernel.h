/*
 * kernel.h -- Defines typdefs and some global functions
 */

#ifndef KERNEL_H
#define KERNEL_H

typedef unsigned int   uint32;
typedef          int   sint32; 
typedef unsigned short uint16;
typedef          short sint16;
typedef unsigned char  uint8;
typedef          char  sint8;

void outb(uint16 port, uint8 value);
uint8 inb(uint16 port);
uint16 inw(uint16 port);

#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(#b, __FILE__, __LINE__))

void panic(const char *message, const char *file, uint32 line);
void panic_assert(const char *desc, const char *file, uint32 line);

#endif // KERNEL_H
