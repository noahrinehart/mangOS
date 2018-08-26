#include <io.h>
#include <isr.h>
#include <keyboard.h>
#include <vga.h>

uint8 kbdus[128] = {
                    0, /* None */
                    0, /* Esc  */
                    '1',  '2',  '3',  '4',  '5',  '6', '7', '8', '9', '0',
                    '-',  '=',  '\b', '\t', 'q', 'w', 'e', 'r',  't', 'y',
                    'u',  'i',  'o',  'p', '[', ']', '\n',
                    0, /* Left control */
                    'a',  's',  'd',  'f', 'g', 'h', 'j',  'k', 'l',
                    ';',  '\'', '`',
                    0, /* Left Shift */
                    '\\', 'z',  'x',  'c', 'v', 'b', 'n',  'm', ',',
                    '.',  '/',
                    0, /* Right Shift */
                    '*',
                    0, /* Left alt */
                    ' ',
                    0, /* CapsLock */
                    0, /* F1 */
                    0, /* F2 */
                    0, /* F3 */
                    0, /* F4 */
                    0, /* F5 */
                    0, /* F6 */
                    0, /* F7 */
                    0, /* F8 */
                    0, /* F9 */
                    0, /* F10 */
                    0, /* NumLock */
                    0, /* ScrollLock */
                    '7', '8',  '9',  '-',  '4', '5', '6', '+',
                    '1', '2', '3',  '0',  '.',
                    0, /* None */
                    0, /* None */
                    0, /* None */
                    0, /* F11 */
                    0, /* F12 */
};

bool scroll_lock = false;
bool num_lock = false;
bool caps_lock = false;
bool left_shift = false;
bool left_ctrl = false;
bool left_alt = false;
bool right_shift = false;
bool right_ctrl = false;
bool right_alt = false;

uint8 prev_scancode = 0;

static uint32 build_keycode(uint8 scancode) {
  /*
   * bits 0-8  - ASCII value
   * bits 8-15 - scancode
   * bit 16 - scroll lock
   * bit 17 - num lock
   * bit 18 - caps lock
   * bit 19 - left shift
   * bit 20 - left ctrl
   * bit 21 - left alt
   * bit 22 - right shift
   * bit 23 - right ctrl
   * bit 24 - right alt
   * bit 25 - repeat key
   * bit 26 - key released
   * bits 27-31 - unused
   */
  uint32 keycode = 0; 

  keycode |= kbdus[scancode];
  keycode |= scancode << 8;
  keycode |= scroll_lock << 16;
  keycode |= num_lock << 17;
  keycode |= caps_lock << 18;
  keycode |= left_shift << 19;
  keycode |= left_ctrl << 20;
  keycode |= left_alt << 21;
  keycode |= right_shift << 22;
  keycode |= right_ctrl << 23;
  keycode |= right_alt << 24;
  if (prev_scancode == scancode) keycode |= 1 << 25;
  if (scancode & 0x80) keycode |= 1 << 26;

  return keycode;
}


void handle_modifiers(uint8 scancode) {
  switch (scancode) {
  case 0x46: /* Scroll lock pressed */
    scroll_lock = true;
    break;
  case 0x45: /* Num lock pressed */
    num_lock = true;
    break;
  case 0x3A: /* Caps lock pressed */
    caps_lock = true;
    break;
  case 0x2A: /* Left shift pressed */
    left_shift = true;
    break;
  case 0x1D: /* Left ctrl pressed */
    left_ctrl = true;
    break;
  case 0x38: /* Left alt pressed */
    left_alt = true;
    break;
  case 0xC6: /* Scroll lock released */ 
    scroll_lock = false;
    break;
  case 0xC5: /* Num lock released */
    num_lock = false;
    break;
  case 0xBA: /* Caps lock released */
    caps_lock = false;
    break;
  case 0xAA: /* Left shift released */
    left_shift = false;
    break;
  case 0x9D: /* Left ctrl released */
    left_ctrl = false;
    break;
  case 0xB8: /* Left alt released */
    left_alt = false;
    break;
  }
}

/* Can take registers_t regs as parameter */
/* TODO locks, right side */
static void keyboard_handler() {
  uint8 scancode = inb(0x60);

  uint32 keycode = build_keycode(scancode);

  handle_modifiers(scancode);

  if (scancode & 0x80) {
  } else {
    vga_put(keycode & 0xFF);
  }
}

void init_keyboard() { register_interrupt_handler(IRQ1, &keyboard_handler); }
