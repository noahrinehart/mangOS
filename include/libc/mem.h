/*
 * mem.h -- Defines fuctions of memory manipulation.
 */

#ifndef MEM_H
#define MEM_H

#include <types.h>

/**
 * Set memory at destination with value of length
 * @param dest destination address
 * @param val value to set
 * @param len length of words to set
 */
void memset(uint8_t *dest, uint8_t val, uint32_t len);

/**
 * Copy memory from one place to another
 * @param des destination address
 * @param src source address
 * @param len length to copy
 */
void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);

#endif // MEM_H
