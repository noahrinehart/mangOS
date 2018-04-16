#include <io.h>
#include <isr.h>
#include <keyboard.h>
#include <vga.h>

uint8
    kbdus[128] =
        {
            0,   /* None */
            0,   /* Esc  */
            '1', /* 1    */
            '2', /* 2    */
            '3',  '4',  '5',  '6', '7', '8', '9',  '0', '-',
            '=',  '\b', '\t', 'q', 'w', 'e', 'r',  't', 'y',
            'u',  'i',  'o',  'p', '[', ']', '\n', 0, /* Left control */
            'a',  's',  'd',  'f', 'g', 'h', 'j',  'k', 'l',
            ';',  '\'', '`',  0, /* Left Shift */
            '\\', 'z',  'x',  'c', 'v', 'b', 'n',  'm', ',',
            '.',  '/',  0, /* Right Shift */
            '*',  0,       /* Left alt */
            ' ',  0,       /* CapsLock */
            0,             /* F1 */
            0,             /* F2 */
            0,             /* F3 */
            0,             /* F4 */
            0,             /* F5 */
            0,             /* F6 */
            0,             /* F7 */
            0,             /* F8 */
            0,             /* F9 */
            0,             /* F10 */
            0,             /* NumLock */
            0,             /* ScrollLock */
            '7',           /* Keypad 7 */
            '8',  '9',  '-',  '4', '5', '6', '+',  '1', '2',
            '3',  '0',  '.',  0,   0,   0,   0, /* F11 */
            0                                   /* F12 */
};

/* Can take registers_t regs as parameter */
static void keyboard_handler() {
  uint8 scancode = inb(0x60);

  if (scancode & 0x80) {
  } else {
    vga_put(kbdus[scancode]);
  }
}

void init_keyboard() { register_interrupt_handler(IRQ1, &keyboard_handler); }
