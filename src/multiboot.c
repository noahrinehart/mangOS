#include <stddef.h>
#include <multiboot.h>
#include <vga.h>

#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

void check_multiboot(const uint32_t mboot_magic, void* mboot_info) {
  // Check multiboot magic
  ASSERT("Multiboot bootloader magic", mboot_magic == MULTIBOOT_BOOTLOADER_MAGIC);
  // Check multiboot header
  multiboot_info_t *mbi = (multiboot_info_t *)mboot_info;
  ASSERT("Multiboot info flags nonnull", mbi->flags != 0);
}
