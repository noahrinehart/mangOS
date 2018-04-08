#include <isr.h>
#include <vga.h>

void isr_handler(registers_t regs)
{
  vga_write("received interrupt: ");
  vga_write_dec(regs.int_no);
  vga_put('\n');
}
