SOURCEDIR  	=	src
INCLUDEDIR 	=	include
BUILDDIR 		=	build

S_SOURCES = $(wildcard $(SOURCEDIR)/*.s)
C_SOURCES = $(wildcard $(SOURCEDIR)/*.c)
H_SOURCES = $(wildcard $(INCLUDEDIR)/*.h)
S_OBJECTS = $(patsubst $(SOURCEDIR)/%.s,$(BUILDDIR)/%.o, $(S_SOURCES))
C_OBJECTS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(C_SOURCES))
OBJECTS   = $(S_OBJECTS) $(C_OBJECTS)

KERNEL   = $(BUILDDIR)/mangOS.elf
ISO 		 = $(BUILDDIR)/mangOS.iso
GRUB_CFG = $(SOURCEDIR)/grub.cfg

CC = clang
LD = ld.lld
AS = nasm

CFLAGS  = -I ./include -ffreestanding -fno-builtin -nostdlib -nostdinc --target=i686-pc-none-elf -march=i686 -m32 -Wall -Wextra -g
LDFLAGS = -T src/link.ld
ASFLAGS = -f elf32

.PHONY: all clean run debug format
.SUFFIXES: .o .s. c

all: $(KERNEL)

clean:
	rm -rf $(BUILDDIR)

$(KERNEL): $(BUILDDIR) $(OBJECTS)
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJECTS)

$(BUILDDIR):
	mkdir -p build

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c $(H_SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(ISO)
	qemu-system-x86_64 -cdrom $(ISO)


$(ISO): $(KERNEL)
	mkdir -p $(BUILDDIR)/isofiles/boot/grub
	cp $(KERNEL) $(BUILDDIR)/isofiles/boot/kernel.bin
	cp $(GRUB_CFG) $(BUILDDIR)/isofiles/boot/grub
	grub-mkrescue -o $(ISO) $(BUILDDIR)/isofiles 2> /dev/null

debug: $(ISO)
	@echo "Run gdb in this directory"
	qemu-system-x86_64 -cdrom $(ISO) -S -s


format:
	clang-format -i $(C_SOURCES)
	clang-format -i $(H_SOURCES)
