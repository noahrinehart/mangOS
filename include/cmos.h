#ifndef CMOS_H
#define CMOS_H

#include <kernel.h>
#include <io.h>

#define CURRENT_YEAR 2018

static uint32  century_register = 0x00;

uint8   second;
uint8   minute;
uint8   hour;
uint8   day;
uint8   month;
uint32  year;

enum {
  cmos_address  = 0x70,
  cmos_data     = 0x71,
};

static uint32 get_update_in_progress_flag();
static uint8 get_RTC_register(int reg);
void read_rtc();

#endif // CMOS_H
