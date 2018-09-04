#include <multiboot.h>
#include <vga.h>

void check_multiboot(const uint32_t eax, const uint32_t ebx) {
  // Check bootloader magic
  ASSERT("Multiboot bootloader magic", eax == MULTIBOOT2_BOOTLOADER_MAGIC);

  // struct multiboot_header *header = (struct multiboot_header*) ebx;
  // ASSERT("Multiboot magic", header->magic == MULTIBOOT2_HEADER_MAGIC);
}