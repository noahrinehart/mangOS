OBJECTS=src/boot.o src/kmain.o src/mem.o src/string.o src/vga.o src/kernel.o src/descriptors.o src/gdt.o src/idt.o src/isr.o src/interrupt.o src/io.o src/timer.o src/keyboard.o
KERNEL=mangOS.elf

CC=$(HOME)/bin/cross/bin/i686-elf-gcc
LD=$(HOME)/bin/cross/bin/i686-elf-ld
AS=nasm

CFLAGS=-I./include -nostdlib -nostdinc -fno-builtin -Wall -Wextra
LDFLAGS=-Tsrc/link.ld
ASFLAGS=-felf

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
