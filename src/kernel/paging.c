#include <paging.h>
#include <stdint.h>

extern uint32_t read_cr0(void);
extern void write_cr0(uint32_t);
extern void write_cr3(void *);

void init_paging() {
  uint32_t page_directory[1024] __attribute((aligned(4096)));

  for (int i = 0; i < 1024; i++) {
    page_directory[i] = 0x00000002;
  }

  uint32_t first_page_table[1024] __attribute((aligned(4096)));
  for (int i = 0; i < 1024; i++) {
    first_page_table[i] = (i * 0x1000) | 3;
  }

  page_directory[0] = ((unsigned int)first_page_table) | 3;

  // Put page directory into cr3
  write_cr3(page_directory);
  // Inable paging bit in cr0
  write_cr0(read_cr0() | 0x80000000);
}
