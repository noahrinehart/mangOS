#ifndef GDT_H
#define GDT_H

#include <types.h>

/**
 * Contains the value of one GDT entry
 */
struct gdt_entry {
  uint16_t limit_low;  // Lower 16 bits of limit
  uint16_t base_low;   // Lower 16 bits of base
  uint8_t base_middle; // Next 8 bits of base
  uint8_t access;      // Access flags
  uint8_t granularity; // Limit and flags
  uint8_t base_high;   // Last 8 bits of base
} __attribute__((packed));

/**
 * Contains the GDT pointer that points to the start of a GDT entry array
 */
struct gdt_ptr {
  uint16_t limit; // Upper 16 bits of selector limits
  uint32_t base;  // Address of first gdt_entry_t
} __attribute__((packed));

/**
 * Sets new GDT with pointer to new array
 * @param addr address of gdt table
 */
extern void set_gdt(uint32_t addr);

/**
 * Initializes GDT array
 */
void init_gdt(void);

#endif // GDT_H
