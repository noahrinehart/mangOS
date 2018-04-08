;
; boot.s -- Start of kernel.
;

bits 32

extern kmain
global _start
section .text
_start:
  mov esp, stack_top  ; Setup stack
  push ebx            ; Load multiboot info

  cli                 ; Disable interrupts
  call kmain          ; Start Kernel
  jmp $
.end


KERNEL_STACK_SIZE equ 16384

section .bss
align 4
stack_bottom:
  resb KERNEL_STACK_SIZE
stack_top:

