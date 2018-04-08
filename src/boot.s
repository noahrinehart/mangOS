;
; boot.s -- Start of kernl. Defines multboot header
;

MBOOT_ALIGN         equ 1 << 0
MBOOT_MEMINFO       equ 1 << 1
MBOOT_FLAGS         equ MBOOT_ALIGN | MBOOT_MEMINFO
MBOOT_MAGIC_NUMBER  equ 0x1BADB002
MBOOT_CHECKSUM      equ -(MBOOT_MAGIC_NUMBER + MBOOT_FLAGS)

bits 32

section .multiboot
align 4
  dd MBOOT_MAGIC_NUMBER
  dd MBOOT_FLAGS
  dd MBOOT_CHECKSUM

KERNEL_STACK_SIZE equ 16384

section .bss
align 4
stack_bottom:
  resb KERNEL_STACK_SIZE
stack_top:

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
