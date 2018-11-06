/*
 * mem.h -- Defines fuctions of memory manipulation.
 */

#ifndef MEM_H
#define MEM_H

#include <types.h>
#include <kernel/kernel.h>

void memset(uint8_t *dest, uint8_t val, uint32_t len);
void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);
void print_mem_values();

extern char base[];  /* Start of memory */
extern char text[];  /* Start of text segment  */
extern char etext[]; /* End of text segment    */
extern char data[];  /* Start of data segment  */
extern char edata[]; /* End of data segment    */
extern char bss[];   /* Start of bss segment   */
extern char ebss[];  /* End of bss segment   */
extern char end[];   /* End of program   */

#endif // MEM_H
