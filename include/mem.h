/*
 * mem.h -- Defines fuctions of memory manipulation.
 */

#ifndef MEM_H
#define MEM_H

#include <kernel.h>

void memset(uint8 *dest, uint8 val, uint32 len);
void memcpy(uint8 *dest, const uint8 *src, uint32 len);

extern int text;  /* Start of text segment  */
extern int etext; /* End of text segment    */
extern int data;  /* Start of data segment  */
extern int edata; /* End of data segment    */
extern int bss;   /* Start of bss segment   */
extern int ebss;  /* End of bss segment   */
extern int end;   /* End of program   */

#endif // MEM_H
