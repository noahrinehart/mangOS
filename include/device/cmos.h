#ifndef CMOS_H
#define CMOS_H

#include <types.h>

#define CURRENT_YEAR 2018

uint8_t second;
uint8_t minute;
uint8_t hour;
uint8_t day;
uint8_t month;
uint32_t year;

enum {
  cmos_address = 0x70,
  cmos_data = 0x71,
};

/**
 * Read real time clock
 */
void read_rtc(void);

#endif // CMOS_H
