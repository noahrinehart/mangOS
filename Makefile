SOURCEDIR=src
BUILDDIR=build

S_SOURCES=$(wildcard $(SOURCEDIR)/*.s)
C_SOURCES=$(wildcard $(SOURCEDIR)/*.c)
S_OBJECTS=$(patsubst $(SOURCEDIR)/%.s,$(BUILDDIR)/%.o, $(S_SOURCES))
C_OBJECTS=$(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(C_SOURCES))
OBJECTS=$(S_OBJECTS) $(C_OBJECTS)

KERNEL=$(BUILDDIR)/mangOS.elf
ISO=$(BUILDDIR)/mangOS.iso
GRUB_CFG=$(SOURCEDIR)/grub.cfg

CC=clang
LD=ld.lld
AS=nasm

CFLAGS=-I ./include -ffreestanding -fno-builtin -nostdlib -nostdinc --target=i686-pc-none-elf -march=i686 -Wall -Wextra -g
LDFLAGS=-T src/link.ld
ASFLAGS=-f elf

.PHONY: all clean link run
.SUFFIXES: .o .s. c

all: $(BUILDDIR) $(OBJECTS) $(KERNEL)

clean:
	rm -rf $(BUILDDIR)

$(KERNEL):
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJECTS)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p build

run: $(ISO)
	qemu-system-x86_64 -cdrom $(ISO)

$(ISO): all
	mkdir -p $(BUILDDIR)/isofiles/boot/grub
	cp $(KERNEL) $(BUILDDIR)/isofiles/boot/kernel.bin
	cp $(GRUB_CFG) $(BUILDDIR)/isofiles/boot/grub
	grub-mkrescue -o $(ISO) $(BUILDDIR)/isofiles 2> /dev/null
	rm -r $(BUILDDIR)/isofiles
