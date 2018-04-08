MBOOT_MAGIC_NUMBER  equ 0xe85250d6
MBOOT_ARCH          equ 0
MBOOT_LENGTH        equ multiboot_end - multiboot_start
MBOOT_CHECKSUM      equ 0x100000000 - (MBOOT_MAGIC_NUMBER + MBOOT_LENGTH)

section .multiboot
multiboot_start:
  dd MBOOT_MAGIC_NUMBER
  dd MBOOT_ARCH
  dd MBOOT_LENGTH
  dd MBOOT_CHECKSUM

  dw 0
  dw 0
  dd 8
multiboot_end:

