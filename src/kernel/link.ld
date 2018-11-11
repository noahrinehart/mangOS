/*
 * Link.ld -- Linker script for the kernel
 */

ENTRY(start)

base = 0xC0100000;

SECTIONS
{
  . = base;

  kernel_virtual_start = .;
  kernel_physical_start = . - 0xC0000000;

  /* Align at 4KB (conveniently the size of a page) */
  .text ALIGN (0x1000) : AT(ADDR(.text)-0xC0000000)
  {
    text = ABSOLUTE(.);
    KEEP(*(.multiboot))
    *(.text .text.*) /* text sections from all files in kernel */
    etext = ABSOLUTE(.);
  }

  .rodata ALIGN (0x1000) : AT(ADDR(.rodata)-0xC0000000)
  {
    rodata = ABSOLUTE(.);   
    *(.rodata .rodata.*) /* read-only data from all files in kernel */
    erodata = ABSOLUTE(.);
  }

  .data ALIGN (0x1000) : AT(ADDR(.data)-0xC0000000)
  {
    data = ABSOLUTE(.);
    *(.data .data.*)
    edata = ABSOLUTE(.);
  }

  .bss ALIGN (0x1000) : AT(ADDR(.bss)-0xC0000000)
  {
    bss = ABSOLUTE(.);
    *(COMMON)
    *(.bss .bss.*)
    ebss = ABSOLUTE(.);
  }

  kernel_virtual_end = .;
  kernel_phsycial_end = . - 0xC0000000;
}
