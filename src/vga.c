#include <vga.h>
#include <io.h>

uint16 *vga_memory = (uint16 *)0xB8000;

uint8 cursor_x = 0;
uint8 cursor_y = 0;

static void move_cursor()
{
  uint16 cursor_location = cursor_y * 80 + cursor_x;
  outb(0x3D4, 14);                    // Tell vga setting high cursor byte
  outb(0x3D5, cursor_location >> 8);  // Send high cursor byte
  outb(0x3D4, 15);                    // Tell vga setting low cursor byte
  outb(0x3D5, cursor_location);       // Send low cursor byte
}

static void scroll()
{
  uint16 blank = vga_entry(' ', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK));

  if (cursor_y >= 25)
  {
    int i;
    for (i = 0*80; i < 24*80; i++)
    {
      vga_memory[i] = vga_memory[i+80];
    }
    for (i = 24*80; i < 25*80; i++)
    {
      vga_memory[i] = blank;
    }
    cursor_y = 24;
  }
}

void vga_clear()
{
  uint16 blank = vga_entry(' ', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK));

  int i;
  for (i = 0; i < 80*25; i++)
  {
    vga_memory[i] = blank;
  }

  cursor_x = 0;
  cursor_y = 0;
  move_cursor();
}

void vga_put(const char c)
{
  uint8 color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  vga_put_color(c, color);
}

void vga_put_color(const char c, uint8 color)
{
  uint16 *location;

  // Backspace
  if (c == 0x08 && cursor_x)
  {
    cursor_x--;
  }
  // Tab
  else if (c == 0x09)
  {
    cursor_x = (cursor_x+8) & ~(8-1);
  }
  // Carriage Return
  else if (c == '\r')
  {
    cursor_x = 0;
  }
  // Newline
  else if (c == '\n')
  {
    cursor_x = 0;
    cursor_y++;
  }
  // All other chars
  else if(c >= ' ')
  {
    location = vga_memory + (cursor_y*80 + cursor_x);
    *location = vga_entry(c, color);
    cursor_x++;
  }
  if (cursor_x >= 80)
  {
    cursor_x = 0;
    cursor_y ++;
  }

  scroll();
  move_cursor();
}

void vga_write(const char *c)
{
  uint8 color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  vga_write_color(c, color);
}

void vga_write_color(const char *c, uint8 color)
{
  int i = 0;
  while (c[i])
    vga_put_color(c[i++], color);
}

void vga_put_hex(uint32 n)
{
  uint8 color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  vga_put_hex_color(n, color);
}

void vga_put_hex_color(uint32 n, uint8 color)
{
  sint32 tmp;
  vga_write_color("0x", color);
  char noZeroes = 1;

  int i;
  for (i = 28; i > 0; i -= 4)
  {
    tmp = (n >> i) & 0xF;
    if (tmp == 0 && noZeroes != 0)
    {
      continue;
    }

    if (tmp >= 0xA)
    {
      noZeroes = 0;
      vga_put_color(tmp-0xA+'a', color);
    }
    else
    {
      noZeroes = 0;
      vga_put_color(tmp+'0', color);
    }
  }

  tmp = n & 0xF;
  if (tmp >= 0xA)
  {
    vga_put_color(tmp-0xA+'a', color);
  }
  else
  {
    vga_put_color(tmp+'0', color);
  }
}

void vga_put_dec(uint32 n)
{
  uint8 color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  vga_put_dec_color(n, color);
}

void vga_put_dec_color(uint32 n, uint8 color)
{
  if (n == 0)
  {
    vga_put_color('0', color);
    return;
  }

  sint32 acc = n;
  char c[32];
  int i = 0;
  while (acc > 0)
  {
    c[i] = '0' + acc%10;
    acc /= 10;
    i++;
  }
  c[i] = 0;

  char c2[32];
  c2[i--] = 0;
  int j = 0;
  while(i >= 0)
  {
    c2[i--] = c[j++];
  }
  vga_write_color(c2, color);
}

void vga_put_at(const char c, uint8 x, uint8 y)
{
  uint8 color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  vga_put_at_color(c, x, y, color);
}

void vga_put_at_color(const char c, uint8 x, uint8 y, uint8 color)
{
  // TODO
}

void vga_printf(const char* format, ...)
{
  uint32* arg = (uint32 *)&format; 
  arg++;

  const char *str;
  char *s;

  for (str = format; *str != '\0'; str++) {
    if (*str != '%') {
      vga_put(*str);
    } else {
      switch (*++str) {
      case 'c':
        vga_put(*arg++);
        break;
      
      case 's':
        for (s = *(char **)arg++; *s != '\0'; s++)
          vga_put(*s);
        break;
      case 'x':
        vga_put_hex(*arg++);
        break;
      case 'd':
        vga_put_dec(*arg++);
        break;
      case '%':
        vga_put('%');
        break;
      }
    }
  }
}

