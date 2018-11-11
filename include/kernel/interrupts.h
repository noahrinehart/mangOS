
#define DISABLE_INT() asm volatile("cli")
#define ENABLE_INT() asm volatile("sti")

