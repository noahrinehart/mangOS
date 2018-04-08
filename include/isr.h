#ifndef ISR_H
#define ISR_H

#include <kernel.h>

typedef struct registers
{
  uint32 ds;
  uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32 int_no, err_code;
  uint32 eip, cs, eflags, useresp, ss;
} registers_t;

#endif
