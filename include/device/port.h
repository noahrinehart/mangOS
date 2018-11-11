#ifndef IO_H
#define IO_H

#include <types.h>

/**
 * Read a byte from the specified port
 * @param port the port to read from
 */
uint8_t inb(uint16_t port);

/**
 * Send a byte to the specified port
 * @param port the port to write to
 * @param value to the value to write
 */
void outb(uint16_t port, uint8_t value);

/**
 * Read a word from the specified port
 * @param port the port to read from
 */
uint16_t inw(uint16_t port);

/**
 * Send a word to the specified port
 * @param port the port to write to
 * @param value the value to write
 */
void outw(uint16_t port, uint16_t value);

#endif // IO_H
