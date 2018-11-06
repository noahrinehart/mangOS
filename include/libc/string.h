/*
 * string.h -- Gives several string functions
 */

#ifndef STRING_H
#define STRING_H

#include <kernel/kernel.h>

/**
 * Compare two strings
 */
int strcmp(char *str1, char *str2);

/**
 * Copy a string from one place to another
 */
char *strcpy(char *dest, const char *src);

/**
 * Concatonate src string onto dest
 */
char *strcat(char *dest, const char *src);

/**
 * Return length of string
 */
int strlen(char *src);

#endif // STRING_H
