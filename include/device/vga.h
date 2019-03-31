/*
 * vga.h -- Functions that interface with vga
 */

#ifndef VGA_H
#define VGA_H

#include <types.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

/**
 * Colors in the vga driver spectrum
 */
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

/**
 * Get a color from foreground to background
 * @param fg foreground color
 * @param bg background color
 * @return The vga entry color
 */
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) { return (bg << 4) | (fg & 0x0F); }

/**
 * Get an entry from a color and a character
 * @param c the character to make an entry out of
 * @param color the color to add to the character
 * @return the vga entry with color and character
 */
static inline uint16_t vga_entry(unsigned char c, uint8_t color) { return c | color << 8; }

/**
 * Clear the vga output
 */
void vga_clear(void);

/**
 * Put character in next spot
 * @param c the character to print at the cursor
 */
void vga_put(const char c);

/**
 * Put character with color in next spot
 * @param c the character to print at the cursor
 * @param color the color of the character
 */
void vga_put_color(const char c, uint8_t color);

/**
 * Write a string to vga
 * @param str the string to print at the cursor
 */
void vga_write(const char *str);

/**
 * Write a string with color to vga
 * @param str the string to print at the cursor
 * @param color the color
 */
void vga_write_color(const char *str, uint8_t color);

/**
 * Put an int in hex to next spot
 * @param n prints hex at the cursor
 */
void vga_put_hex(uint32_t n);

/**
 * Put an int in hex with color to next spot
 * @param n prints hex at the cursor
 * @param color prints in specified color
 */
void vga_put_hex_color(uint32_t n, uint8_t color);

/**
 * Put a decimal to next spot
 * @param n prints decimal at cursor
 */
void vga_put_dec(uint32_t n);

/**
 * Put a decimal with color to next spot
 * @param n prints decimal at cursor
 * @param color prints in specified color
 */
void vga_put_dec_color(uint32_t n, uint8_t color);

/**
 * Put a character at specified spot
 * @param c the character to print
 * @param x the x coordinate to print at
 * @param y the y coordinate to print at
 */
void vga_put_at(const char c, uint8_t x, uint8_t y);

/**
 * Put a character with color at specified spot
 * @param c the character to print
 * @param x the x coordinate to print at
 * @param y the y coordinate to print at
 * @param color prints in specified color
 */
void vga_put_at_color(const char c, uint8_t x, uint8_t y, uint8_t color);

/**
 * Put string and newline
 * @param str string to print
 */
void vga_puts(const char *str);

/**
 * Printf to vga
 * @param format format to print as
 */
void vga_printf(const char *format, ...);

#endif // VGA_H
