#include <device/timer.h>
#include <device/port.h>
#include <kernel/isr.h>
#include <device/vga.h>

uint32_t clktick = 0;

/* Can take registers_t regs as parameter */
static void timer_callback() {
  static int clock1000 = 1000;
  if ((--clock1000) <= 0) {
    clktick++;
    clock1000 = 1000;
  }
}

void init_timer(void) {
  register_interrupt_handler(IRQ0, &timer_callback);

  uint32_t divisor = 1193182 / CLOCK_FREQUENCY;

  outb(0x43, 0x36);

  uint8_t l = (uint8_t)(divisor & 0xFF);
  uint8_t h = (uint8_t)((divisor >> 8) & 0xFF);

  outb(0x40, l);
  outb(0x40, h);
}

