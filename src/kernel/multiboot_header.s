;
; multiboot_header.s - Header for multiboot
;

MBOOT_ALIGN equ 1<<0
MBOOT_MEMINFO equ 1<<1
MBOOT_FLAGS equ MBOOT_ALIGN | MBOOT_MEMINFO
MBOOT_MAGIC equ 0x1BADB002
MBOOT_CHECKSUM equ -(MBOOT_MAGIC + MBOOT_FLAGS)

section .multiboot
multiboot_start:
align 4

dd MBOOT_MAGIC
dd MBOOT_FLAGS
dd MBOOT_CHECKSUM

multiboot_end:
