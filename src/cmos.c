#include <cmos.h>

static uint32 get_update_in_progress_flag() {
  outb(cmos_address, 0x0A);
  return (inb(cmos_data) & 0x80);
}

static uint8 get_RTC_register(int reg) {
  outb(cmos_address, reg);
  return inb(cmos_data);
}

void read_rtc() {
  uint8 century = 0;
  uint8 last_second;
  uint8 last_minute;
  uint8 last_hour;
  uint8 last_day;
  uint8 last_month;
  uint8 last_year;
  uint8 last_century;
  uint8 registerB;

  while (get_update_in_progress_flag())
    ;
  second = get_RTC_register(0x00);
  minute = get_RTC_register(0x02);
  hour = get_RTC_register(0x04);
  day = get_RTC_register(0x07);
  month = get_RTC_register(0x08);
  year = get_RTC_register(0x09);
  if (century_register != 0) {
    century = get_RTC_register(century_register);
  }

  do {
    last_second = second;
    last_minute = minute;
    last_hour = hour;
    last_day = day;
    last_month = month;
    last_year = year;
    last_century = century;

    while (get_update_in_progress_flag())
      ;
    second = get_RTC_register(0x00);
    minute = get_RTC_register(0x02);
    hour = get_RTC_register(0x04);
    day = get_RTC_register(0x07);
    month = get_RTC_register(0x08);
    year = get_RTC_register(0x09);
    if (century_register != 0) {
      century = get_RTC_register(century_register);
    }
  } while ((last_second != second) || (last_minute != minute) ||
           (last_hour != hour) || (last_day != day) || (last_month != month) ||
           (last_year != year) || (last_century != century));

  registerB = get_RTC_register(0x0B);

  if (!(registerB & 0x04)) {
    second = (second & 0x0F) + ((second / 16) * 10);
    minute = (minute & 0x0F) + ((minute / 16) * 10);
    hour = ((hour & 0x0F) + (((hour & 0x70) / 16) * 10)) | (hour & 0x80);
    day = (day & 0x0F) + ((day / 16) * 10);
    month = (month & 0x0F) + ((month / 16) * 10);
    year = (year & 0x0F) + ((year / 16) * 10);
    if (century_register != 0) {
      century = (century & 0x0F) + ((century / 16) * 10);
    }
  }

  if (!(registerB & 0x02) && (hour & 0x80)) {
    hour = ((hour & 0x7F) + 12) % 24;
  }

  if (century_register != 0) {
    year += century * 100;
  } else {
    year += (CURRENT_YEAR / 100) * 100;
    if (year < CURRENT_YEAR)
      year += 100;
  }
}
