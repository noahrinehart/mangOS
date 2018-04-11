/*
 * vga.h -- Functions that interface with vga
 */

#ifndef VGA_H
#define VGA_H

#include <kernel.h>

enum vga_color {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE = 1,
  VGA_COLOR_GREEN = 2,
  VGA_COLOR_CYAN = 3,
  VGA_COLOR_RED = 4,
  VGA_COLOR_MAGENTA = 5,
  VGA_COLOR_BROWN = 6,
  VGA_COLOR_LIGHT_GREY = 7,
  VGA_COLOR_DARK_GREY = 8,
  VGA_COLOR_LIGHT_BLUE = 9,
  VGA_COLOR_LIGHT_GREEN = 10,
  VGA_COLOR_LIGHT_CYAN = 11,
  VGA_COLOR_LIGHT_RED = 12,
  VGA_COLOR_LIGHT_MAGENTA = 13,
  VGA_COLOR_LIGHT_BROWN = 14,
  VGA_COLOR_WHITE = 15,
};

static inline uint8 vga_entry_color(enum vga_color fg, enum vga_color bg)
{
  return (bg << 4) | (fg & 0x0F);
}

static inline uint16 vga_entry(unsigned char c, uint8 color)
{
  return c | color << 8;
}

void vga_clear();

void vga_put(const char c);

void vga_put_color(const char c, uint8 color);

void vga_write(const char *c);

void vga_write_color(const char *c, uint8 color);

void vga_put_hex(uint32 n);

void vga_put_hex_color(uint32 n, uint8 color);

void vga_put_dec(uint32 n);

void vga_put_dec_color(uint32 n, uint8 color);

void vga_put_at(const char c, uint8 x, uint8 y);

void vga_put_at_color(const char c, uint8 x, uint8 y, uint8 color);

void vga_printf(const char* format, ...);

#endif // VGA_H
