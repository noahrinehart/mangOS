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

  mov word [0x000B8000], 0x2848               ; H
  mov word [0x000B8002], 0x2845               ; E
  mov word [0x000B8004], 0x284C               ; L
  mov word [0x000B8006], 0x284C               ; L
  mov word [0x000B8008], 0x284F               ; O
  mov word [0x000B800A], 0x2821               ; !

  
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
