OBJECTS=src/multiboot.o src/boot.o src/kmain.o src/mem.o src/string.o src/vga.o src/kernel.o src/descriptors.o src/gdt.o src/idt.o src/isr.o src/interrupt.o src/io.o src/timer.o src/keyboard.o
KERNEL=mangOS.elf
ISO=mangOS.iso
GRUB_CFG=src/grub.cfg

CC=clang
LD=ld.lld
AS=nasm

CFLAGS=-I ./include -ffreestanding -fno-builtin -nostdlib -nostdinc --target=i686-pc-none-elf -march=i686 -Wall -Wextra -g
LDFLAGS=-T src/link.ld
ASFLAGS=-f elf

.PHONY: all clean link
.SUFFIXES: .o .s. c

all: $(OBJECTS) link

clean:
	rm -f $(OBJECTS) $(KERNEL) $(ISO)

link:
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJECTS)

.s.o:
	$(AS) $(ASFLAGS) $<

run: $(ISO)
	qemu-system-x86_64 -cdrom $(ISO)

$(ISO): all
	mkdir -p build/isofiles/boot/grub
	cp $(KERNEL) build/isofiles/boot/kernel.bin
	cp $(GRUB_CFG) build/isofiles/boot/grub
	grub-mkrescue -o $(ISO) build/isofiles 2> /dev/null
	rm -r build/isofiles
