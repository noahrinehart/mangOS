#ifndef GDT_H
#define GDT_H

#include <kernel.h>

// Contains value of one GDT entry
struct gdt_entry
{
  uint16 limit_low;   // Lower 16 bits of limit
  uint16 base_low;    // Lower 16 bits of base
  uint8  base_middle; // Next 8 bits of base
  uint8  access;      // Access flags
  uint8  granularity;
  uint8  base_high;   // Last 8 bits of base
} __attribute__((packed));
typedef struct gdt_entry gdt_entry_t;


// Describes GDT pointer. POints to start of array of GDT entires
struct gdt_ptr
{
  uint16 limit; // Upper 16 bits of selector limits
  uint32 base;  // Address of first gdt_entry_t
} __attribute__((packed));
typedef struct gdt_ptr gdt_ptr_t;

gdt_entry_t gdt_entries[5];
gdt_ptr_t   gdt_ptr;

extern void gdt_flush(uint32);

static void init_gdt();
static void gdt_set_gate(sint32, uint32, uint32, uint8, uint8);


#endif // GDT_H
