/*
 * mem.h -- Defines fuctions of memory manipulation.
 */

#ifndef MEM_H
#define MEM_H

#include <kernel.h>

void memset(uint8 *dest, uint8 val, uint32 len);
void memcpy(uint8 *dest, const uint8 *src, uint32 len);

#endif // MEM_H
