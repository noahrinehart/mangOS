#include <io.h>
#include <isr.h>
#include <timer.h>
#include <vga.h>

uint32 clktick = 0;

/* Can take registers_t regs as parameter */
static void timer_callback() {
  static int clock1000 = 1000;
  if ((--clock1000) <= 0) {
    clktick++;
    vga_printf("Tick: %d\n", clktick);
    clock1000 = 1000;
  }
}

void init_timer() {
  register_interrupt_handler(IRQ0, &timer_callback);

  uint32 divisor = 1193180 / CLOCK_FREQUENCY;

  outb(0x43, 0x36);

  uint8 l = (uint8)(divisor & 0xFF);
  uint8 h = (uint8)((divisor >> 8) & 0xFF);

  outb(0x40, l);
  outb(0x40, h);
}
