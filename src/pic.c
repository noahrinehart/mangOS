#include <io.h>
#include <pic.h>

void pic_init(void) {
  unsigned char a1, a2;

  // Save masks
  a1 = inb(PIC1_DATA);
  a2 = inb(PIC2_DATA);

  // Start init sequence
  outb(PIC1_COMMAND, ICW1_INIT + ICW1_ICW4);
  outb(PIC2_COMMAND, ICW1_INIT + ICW1_ICW4);

  // ICW2: Master PIC vector offset
  outb(PIC1_DATA, 0x20);
  // ICW2: Slave PIC vector offset
  outb(PIC2_DATA, 0x28);

  // ICW3: tell Master PIC that there is a slave PIC at IRQ2
  outb(PIC1_DATA, 0x04);
  // ICW3: tell Slave PIC its cascade identity
  outb(PIC2_DATA, 0x02);

  outb(PIC1_DATA, ICW4_8086);
  outb(PIC2_DATA, ICW4_8086);

  outb(PIC1_DATA, a1);
  outb(PIC2_DATA, a2);
}