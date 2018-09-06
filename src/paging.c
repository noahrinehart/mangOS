#include <stdint.h>


extern void load_page_directory(uint32_t *);
extern void enable_paging();

void init_paging() {
    uint32_t page_directory[1024] __attribute((aligned(4096)));

    for (int i = 0; i < 1024; i++) {
      page_directory[i] = 0x00000002;
    }

    uint32_t first_page_table[1024] __attribute((aligned(4096)));
    for (int i = 0; i < 1024; i++) {
      first_page_table[i] = (i * 0x1000) | 3;
    }

    page_directory[0] = ((unsigned int) first_page_table) | 3;

    load_page_directory(page_directory);
    enable_paging();
}
