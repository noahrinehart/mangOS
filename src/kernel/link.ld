/*
 * Link.ld -- Linker script for the kernel
 */

OUTPUT_ARCH(i386)
ENTRY(_start)
base = 0x100000;
SECTIONS
{
  . = base;
  . = ALIGN(4096);
  .text :
  {
    text = ABSOLUTE(.);
    KEEP(*(.multiboot))
    *(.text .text.*)
    *(.rodata .rodata.*) 
    etext = ABSOLUTE(.);
    . = ALIGN(4096);
  }

  .data :
  {
    data = ABSOLUTE(.);
    *(.data .data.*)
    edata = ABSOLUTE(.);
    . = ALIGN(4096);
  }

  .bss :
  {
    bss = ABSOLUTE(.);
    *(COMMON)
    *(.bss .bss.*)
    ebss = ABSOLUTE(.);
    . = ALIGN(4096);
    end = ABSOLUTE(.);
  }
}