/*
 * mem.h -- Defines fuctions of memory manipulation.
 */

#ifndef MEM_H
#define MEM_H

#include <kernel.h>

void memset(uint8 *dest, uint8 val, uint32 len);
void memcpy(uint8 *dest, const uint8 *src, uint32 len);

extern char base[];  /* Start of memory */
extern char text[];  /* Start of text segment  */
extern char etext[]; /* End of text segment    */
extern char data[];  /* Start of data segment  */
extern char edata[]; /* End of data segment    */
extern char bss[];   /* Start of bss segment   */
extern char ebss[];  /* End of bss segment   */
extern char end[];   /* End of program   */

#endif // MEM_H
