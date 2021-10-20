/* File : mystring_ars.c
 *
 * Author : @csd4802
 *
 * This file contains function definitions for functions found in mystring.h
 *
 * C array syntax is being used here.
 *
 *
 */

#include "mystring.h"
#include <stddef.h>
#include <assert.h>

/* Get the length of string s */
size_t ms_length(const char s[])
{
  size_t uiLength = 0U;

  assert(s); /* Works because NULL and FALSE are identical. */

  while (s[uiLength++]) /* Works because end-of-string and FALSE are identical. */
    ;

  return --uiLength; /* pre decriment, condition always adds one more byte */
}

/* Copy src to dst */
char *ms_copy(char dest[],const char src[])
{
  size_t i = 0U;

  assert(dest && src);

  for (; (dest[i] = src[i]); i++)
    ;

  return dest;
}

/* Copy up to N bytes from src onto dst */
char *ms_ncopy(char dest[],const char src[],size_t n)
{
  size_t i = 0U;

  assert(dest && src);

  for (; i < n && (dest[i] = src[i]); i++)
    ;

  return dest;
}

/* Append src onto dest */
char *ms_concat(char dest[],const char src[])
{
  size_t i = ms_length(dest), j = 0U; /* reaching the end of the dest string */

  assert(dest && src);

  for (; (dest[i] = src[j]); j++,i++) /* while the result of the assignment is not 0 */
    ;

  return dest;
}

/* Append up to N bytes from src onto dest */
char *ms_nconcat(char dest[],const char src[],size_t n)
{
  size_t i = 0U, len_dest = ms_length(dest);
  size_t j = 0U;

  assert(dest && src);

  for (i = len_dest; j < n && src[j]; j++,i++)
  {
    dest[i] = src[j];
  }

  dest[i] = 0; /* NULL terminating the destination string */

  return dest;
}

/* Compare strings s1 and s2 */
int ms_compare(const char s1[],const char s2[])
{
  size_t i = 0U;

  assert(s1 && s2);

  for (; s1[i] == s2[i]; i++)
  {
    if (s1[i] == 0)
    {
      return 0;
    }
  }
  return (s1[i] > s2[i] ? 1 : -1);
}

/* Compare s1 and s2 up to N bytes */
int ms_ncompare(const char s1[],const char s2[],size_t n)
{
  size_t i = 0U;

  assert(s1 && s2);

  for (; i < n; i++)
  {
    if (s1[i] != s2[i])
    {
      return (s1[i] > s2[i] ? 1 : -1);
    }
  }
  return 0;
}

/* Find first occurence of needle in haystack */
char *ms_search(const char haystack[],const char needle[])
{
  size_t i = 0U;
  size_t needle_len = 0U;

  assert(haystack && needle);

  for (needle_len = ms_length(needle); haystack[i]; i++)
  {
    if (!ms_ncompare(&haystack[i],needle,needle_len))
    {
      return (char*)&haystack[i];
    }
  }

  return NULL;
}
