#ifndef IO_H
#define IO_H

#include <kernel.h>

/**
 * Read a byte from the specified port
 */
uint8 inb(uint16 port);

/**
 * Send a byte to the specified port
 */
void outb(uint16 port, uint8 value);


/**
 * Read a word from the specified port
 */
uint16 inw(uint16 port);

/**
 * Send a word to the specified port
 */
void outw(uint16 port, uint16 value);

#endif // IO_H
