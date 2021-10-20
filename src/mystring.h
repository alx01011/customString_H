/* File : mystring.h
 *
 * Author : @csd4802
 *
 * This file contains function prototypes for custom string.h functions
 *
 *
 */
 
#ifndef MYSTRING_H /* include guard */
#define MYSTRING_H

#include <stddef.h>

/* Get the length of string s */
size_t ms_length(const char *s);

/* Copy src to dst */
char *ms_copy(char *dest,const char *src);

/* Copy up to N bytes from src onto dst */
char *ms_ncopy(char *dest,const char *src,size_t n);

/* Append src onto dest */
char *ms_concat(char *dest,const char *src);

/* Append up to N bytes from src onto dest */
char *ms_nconcat(char *dest,const char *src,size_t n);

/* Compare strings s1 and s2 */
int ms_compare(const char *s1,const char *s2);

/* Compare s1 and s2 up to N bytes */
int ms_ncompare(const char *s1,const char *s2,size_t n);

/* Find first occurence of needle in haystack */ 
char *ms_search(const char *haystack,const char *needle);

#endif
