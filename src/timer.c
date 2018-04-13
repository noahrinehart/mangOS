#include <io.h>
#include <isr.h>
#include <timer.h>
#include <vga.h>

uint32 clktick = 0;

/* Can take registers_t regs as parameter */
static void timer_callback() {
  clktick++;
  /* vga_write("Tick: "); */
  /* vga_put_dec(tick); */
  /* vga_write("\n"); */
}

void init_timer(uint32 frequency) {
  register_interrupt_handler(IRQ0, &timer_callback);

  uint32 divisor = 1193180 / frequency;

  outb(0x43, 0x36);

  uint8 l = (uint8)(divisor & 0xFF);
  uint8 h = (uint8)((divisor >> 8) & 0xFF);

  outb(0x40, l);
  outb(0x40, h);
}
