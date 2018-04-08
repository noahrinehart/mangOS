OBJECTS=src/boot.o src/kmain.o src/mem.o src/string.o src/vga.o src/kernel.o src/descriptors.o src/gdt.o src/idt.o src/isr.o src/interrupt.o src/io.o src/timer.o src/keyboard.o
KERNEL=mangOS.elf

CC=clang
LD=$(HOME)/bin/cross/bin/i686-elf-ld
AS=nasm

CFLAGS=-I ./include -ffreestanding -fno-builtin -nostdlib -nostdinc --target=i686-pc-none-elf -march=i686 -Wall -Wextra -g
LDFLAGS=-T src/link.ld
ASFLAGS=-f elf

.PHONY: all clean link
.SUFFIXES: .o .s. c

all: $(OBJECTS) link

clean:
	rm -f src/*.o $(KERNEL)

link:
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJECTS)

.s.o:
	$(AS) $(ASFLAGS) $<

run: all
	qemu-system-x86_64 -kernel $(KERNEL)
