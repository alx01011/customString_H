/* File : mystring_ptrs.c
 *
 * Author : @csd4802
 *
 * This file contains function definitions for functions found in mystring.h
 *
 * C pointer syntax and arithmetic is being used here.
 *
 *
 */

#include "mystring.h"
#include <assert.h>
#include <stddef.h>

/* All assertion checks are for NULL pointers, in which no operations can be perfomed */

/* returns the length of pcStr */

size_t ms_length(const char *pcStr)
{
  const char *pcStrEnd = pcStr;

  assert(pcStr);

  while (*pcStrEnd) /* checking for NULL byte */
  {
    pcStrEnd++;
  }

  return pcStrEnd - pcStr;
}

/* copies src to dest string */

char *ms_copy(char *dest,const char *src)
{
  char *tmp = dest; /* Saving the address of the first char */

  assert(dest && src);

  while ((*dest++ = *src++)) /* copying src to dest until NULL byte is found */
    ;

  return tmp; /* Returning the first byte, not the last (return dest) */
}

/* copies N bytes from src to dest */

char *ms_ncopy(char *dest,const char *src,size_t n)
{
  char *tmp = dest;

  assert(dest && src);

  while(n-- && (*dest++ = *src++)) /* while n is not 0 */
    ;

  return tmp;
}

/* Appends src at the end of dest */

char *ms_concat(char *dest,const char *src)
{
  char *tmp = dest;

  assert(dest && src);

  dest += ms_length(dest); /* reaching the end of dest */

  while ((*dest++ =*src++)) /* appending src to the end of dest */
    ;

  return tmp; /* returning a pointer,pointing at the start of dest */
}

/* Appends N bytes of src at the end of destination */
char *ms_nconcat(char *dest,const char *src,size_t n)
{
  char *tmp = dest;

  assert(dest && src);

  dest += ms_length(dest);

  while (n-- && *src) /* while src is not NULL and n is not 0 */
  {
    *dest++ = *src++;
  }

  *dest = 0; /* NULL terminating destination string */

  return tmp;
}

/* compares string s1 with s2 */

int ms_compare(const char *s1, const char *s2)
{
  assert(s1 && s2);

  for (; *s1 == *s2; s1++,s2++)
  {
    if (*s1 == 0) /* reached the end of s1 and s2 */
    {
      return 0;
    }
  }

  return ((*s1 > *s2) ? 1 : -1); /* conditional expression, for the return value */

  /* if last char of s1 is greater than the last char of s2 ,return 1 else return -1 */
}

/*compares n bytes of s1 with s2 */

int ms_ncompare(const char *s1, const char *s2,size_t n)
{
  assert(s1 && s2);

  for (; n--; s1++,s2++)
  {
    if (*s1 != *s2) /* if an unmatched character is found, return */
    {
      return (*s1 > *s2 ? 1 : -1);
    }
  }
  return 0; /* if no unmatched character is found */
}

/* searches for string needle in haystack, and returns a pointer to its first occurence */

char *ms_search(const char *haystack, const char *needle)
{
  size_t needle_len =  0U;

  assert(haystack && needle);

  needle_len = ms_length(needle);

  for (; haystack; haystack++)
  {
    if (ms_ncompare(haystack,needle,needle_len) == 0) /* all characters of needle are found at haystack */
    {
      return (char*)haystack; /* return a pointer to the first character of needle found in haystack */
    }
  }

  return NULL; /* if no matches, return NULL */
}
