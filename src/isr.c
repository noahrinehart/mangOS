#include <isr.h>
#include <vga.h>
#include <io.h>

void register_interrupt_handler(uint8 n, isr_t handler)
{
  interrupt_handlers[n] = handler;
}

void isr_handler(registers_t regs)
{
  vga_write("received interrupt: ");
  vga_put_dec(regs.int_no);
  vga_put('\n');
}

void irq_handler(registers_t regs)
{
  if (regs.int_no >= 40)
  {
    outb(0xA0, 0x20);
  }

  outb(0x20, 0x20);

  if (interrupt_handlers[regs.int_no] != 0)
  {
    isr_t handler = interrupt_handlers[regs.int_no];
    handler(regs);
  }
}

