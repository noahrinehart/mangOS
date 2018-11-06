#ifndef PAGING_H
#define PAGING_H

#include <types.h>

extern void load_page_directory(uint32_t*);
extern void enable_paging();

void init_paging();

#endif