/*
 * Link.ld -- Linker script for the kernel
*/

ENTRY(_start)
SECTIONS
{
    . = 1M;

    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(0x1000)
    {
        *(.rodata) 
    }

    .data BLOCK(4K) : ALIGN(0x1000)
    {
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(0x1000)
    {
        *(COMMON)
        *(.bss)
    }
}
