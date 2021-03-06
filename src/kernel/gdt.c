#include <kernel/gdt.h>

/**
 * GDT entry array
 */
struct gdt_entry gdt_entries[5];

/**
 * GDT pointer
 */
struct gdt_ptr gdt_ptr;

static void create_descriptor(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
  gdt_entries[num].base_low = (base & 0xFFFF);
  gdt_entries[num].base_middle = (base >> 16) & 0xFF;
  gdt_entries[num].base_high = (base >> 24) & 0xFF;

  gdt_entries[num].limit_low = (limit & 0xFFFF);
  gdt_entries[num].granularity = (limit >> 16) & 0x0F;

  gdt_entries[num].granularity |= gran & 0xF0;
  gdt_entries[num].access = access;
}

void init_gdt(void) {
  gdt_ptr.limit = (sizeof(struct gdt_entry) * 5) - 1;
  gdt_ptr.base = (uint32_t) &gdt_entries;

  create_descriptor(0, 0, 0, 0, 0);                // Null segment
  create_descriptor(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel mode code segment
  create_descriptor(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel mode data segment
  create_descriptor(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
  create_descriptor(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

  set_gdt((uint32_t) &gdt_ptr);
}
