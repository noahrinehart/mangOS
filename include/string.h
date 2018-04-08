/*
 * string.h -- Gives several string functions
 */

#ifndef STRING_H
#define STRING_H

#include <kernel.h>

int strcmp(char *str1, char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strlen(char *src);

#endif // STRING_H
