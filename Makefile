CC := clang
AS := nasm
LD := ld.lld

QEMU := qemu-system-x86_64

SOURCE_DIR	:= src
BUILD_DIR	:= build
INCLUDE_DIR	:= include
ISO_DIR		:= $(SOURCE_DIR)/iso

MODULES := device kernel libc

SOURCE_MOD 	:= $(addprefix $(SOURCE_DIR)/,$(MODULES))
INCLUDE_MOD	:= $(addprefix $(BUILD_DIR)/,$(MODULES))
BUILD_MOD	:= $(addprefix $(BUILD_DIR)/,$(MODULES))

SOURCE_C	:= $(foreach sdir,$(SOURCE_MOD),$(wildcard $(sdir)/*.c))
SOURCE_S	:= $(foreach sdir,$(SOURCE_MOD),$(wildcard $(sdir)/*.s))
SOURCE_H	:= $(foreach sdir,$(SOURCE_MOD),$(wildcard $(sdir)/*.h))
OBJECT_C	:= $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE_C))
OBJECT_S	:= $(patsubst $(SOURCE_DIR)/%.s,$(BUILD_DIR)/%.o,$(SOURCE_S))
OBJECTS		:= $(OBJECT_C) $(OBJECT_S)

LINK_SCRIPT	:= $(SOURCE_DIR)/kernel/link.ld

CFLAGS	:= -Iinclude -Iinclude/common -m32 -ffreestanding -nostdlib -nostdinc -fno-builtin \
         	-Wall -Wextra --target=i686-pc-none-elf -march=i686
LDFLAGS	:= -T $(LINK_SCRIPT)
ASFLAGS	:= -f elf32

KERNEL	:= $(BUILD_DIR)/mangOS.elf
ISO		:= $(BUILD_DIR)/mangOS.iso

.PHONY: all run clean
.SUFFIXES: .o .s. c

all: $(KERNEL)

$(KERNEL): $(BUILD_MOD) $(OBJECTS)
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJECTS)

$(BUILD_MOD):
	mkdir -p $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(SOURCE_H)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@

run: $(ISO)
	$(QEMU) -cdrom $<

$(ISO): $(KERNEL)
	mkdir -p $(BUILD_DIR)/iso/boot/grub
	cp $(ISO_DIR)/stage2_eltorito $(BUILD_DIR)/iso/boot/grub
	cp $(KERNEL) $(BUILD_DIR)/iso/boot/
	cp $(ISO_DIR)/menu.lst $(BUILD_DIR)/iso/boot/grub
	mkisofs -R							\
          -b boot/grub/stage2_eltorito	\
          -no-emul-boot					\
          -boot-load-size 4				\
          -A os							\
          -input-charset utf8			\
          -quiet						\
          -boot-info-table				\
          -o $(ISO)						\
          $(BUILD_DIR)/iso

clean:
	rm -rf build
