#ifndef GDT_H
#define GDT_H

#include <kernel.h>

/**
 * Contains the value of one GDT entry
 */
struct gdt_entry {
  uint16_t limit_low;  // Lower 16 bits of limit
  uint16_t base_low;   // Lower 16 bits of base
  uint8_t base_middle; // Next 8 bits of base
  uint8_t access;      // Access flags
  uint8_t granularity;
  uint8_t base_high; // Last 8 bits of base
} __attribute__((packed));
typedef struct gdt_entry gdt_entry_t;

/**
 * Contains the GDT pointer that points to the start of a GDT entry array
 */
struct gdt_ptr {
  uint16_t limit; // Upper 16 bits of selector limits
  uint32_t base;  // Address of first gdt_entry_t
} __attribute__((packed));
typedef struct gdt_ptr gdt_ptr_t;

/**
 * GDT entry array
 */
gdt_entry_t gdt_entries[5];

/**
 * GDT pointer
 */
gdt_ptr_t gdt_ptr;

/**
 * Sets new GDT with pointer to new array
 */
extern void gdt_flush(uint32_t);


/**
 * Initializes GDT array
 */
static void init_gdt();

/**
 * Set GDT entry
 */
static void gdt_set_gate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);

#endif // GDT_H
