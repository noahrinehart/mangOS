;
; boot.s -- Start of kernel.
;

global _start
extern kmain

section .text
bits 32
_start:
  cli                   ; Disable interrupts
  mov esp, stack_top    ; Setup stack

  push ebx              ; Load multiboot info
  push eax              ; Load multiboot magic

  call kmain            ; Start Kernel
  
.halt:
  hlt
  jmp .halt
.end:


KERNEL_STACK_SIZE equ 0x4000

section .bss
align 32
stack_bottom:
  resb KERNEL_STACK_SIZE
stack_top:

