/*
 * Link.ld -- Linker script for the kernel
*/

OUTPUT_FORMAT(elf32-i386)
ENTRY(boot)
phys_base = 0x100000;
offset = 0xC0000000;
virtual = phys_base + offset;

SECTIONS
{
  . = virtual;
  .text : AT(ADDR(.text) - offset)
  {
    text = .;
    KEEP(*(.multiboot))
    *(.text .text.*)
    *(.rodata .rodata.*) 
    etext = .;
  }

  .data ALIGN(0x1000) : AT(ADDR(.data) - offset)
  {
    data = .;
    *(.data .data.*)
    edata = .;
  }

  .bss ALIGN(0x1000) : AT(ADDR(.bss) - offset)
  {
    bss = .;
    *(COMMON)
    *(.bss .bss.*)
    ebss = .;
  }

  end = .;

  /DISCARD/ : {
      *(.comment)
      *(.eh_frame)
      *(.note.gnu.build-id)
  }
}
