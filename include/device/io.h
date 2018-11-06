#ifndef IO_H
#define IO_H

#include <types.h>
#include <kernel/kernel.h>

/**
 * Read a byte from the specified port
 */
uint8_t inb(uint16_t port);

/**
 * Send a byte to the specified port
 */
void outb(uint16_t port, uint8_t value);

/**
 * Read a word from the specified port
 */
uint16_t inw(uint16_t port);

/**
 * Send a word to the specified port
 */
void outw(uint16_t port, uint16_t value);

#endif // IO_H
