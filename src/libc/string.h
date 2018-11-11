/*
 * string.h -- Gives several string functions
 */

#ifndef STRING_H
#define STRING_H

/**
 * Compare two strings
 * @param str1 the first string
 * @param str2 the second string
 * @returns 0 if match, not 0 if not
 */
int strcmp(char *str1, char *str2);

/**
 * Copy a string from one place to another
 * @param dest destion to copy to
 * @param src source to copy from
 * @returns the destination string
 */
char *strcpy(char *dest, const char *src);

/**
 * Concatonate src string onto dest
 * @param dest destinat on strint to concat too
 * @param src source string to copy from
 * @returns the destination string
 */
char *strcat(char *dest, const char *src);


/**
 * Return length of string
 * @param src source string
 * @returns src source string to measure
 */
int strlen(char *src);

#endif // STRING_H

