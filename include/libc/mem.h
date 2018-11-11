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

/**
 * Print memory values of linked elf
 */
void print_mem_values(void);


extern void *base;    /* Start of memory         */
extern void *text;    /* Start of text segment   */
extern void *etext;   /* End of text segment     */
extern void *rodata;  /* Start of rodata segment */
extern void *erodata; /* End of rodata segment   */
extern void *data;    /* Start of data segment   */
extern void *edata;   /* End of data segment     */
extern void *bss;     /* Start of bss segment    */
extern void *ebss;    /* End of bss segment      */

extern void *kernel_virtual_start;  /* Start of virtual memory          */
extern void *kernel_physical_start; /* Start of physical memory         */
extern void *kernel_virtual_end;    /* End of virtual memory of kernel  */
extern void *kernel_physical_end;   /* End of physical memory of kernel */

#endif // MEM_H

