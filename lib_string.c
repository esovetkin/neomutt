/**
 * @file
 * String manipulation functions
 *
 * @authors
 * Copyright (C) 2017 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "lib_string.h"
#include "lib_memory.h"

char *safe_strdup(const char *s)
{
  char *p = NULL;
  size_t l;

  if (!s || !*s)
    return 0;
  l = strlen(s) + 1;
  p = safe_malloc(l);
  memcpy(p, s, l);
  return p;
}

char *safe_strcat(char *d, size_t l, const char *s)
{
  char *p = d;

  if (!l)
    return d;

  l--; /* Space for the trailing '\0'. */

  for (; *d && l; l--)
    d++;
  for (; *s && l; l--)
    *d++ = *s++;

  *d = '\0';

  return p;
}

char *safe_strncat(char *d, size_t l, const char *s, size_t sl)
{
  char *p = d;

  if (!l)
    return d;

  l--; /* Space for the trailing '\0'. */

  for (; *d && l; l--)
    d++;
  for (; *s && l && sl; l--, sl--)
    *d++ = *s++;

  *d = '\0';

  return p;
}

void mutt_str_replace(char **p, const char *s)
{
  FREE(p);
  *p = safe_strdup(s);
}

void mutt_str_adjust(char **p)
{
  if (!p || !*p)
    return;
  safe_realloc(p, strlen(*p) + 1);
}

/**
 * mutt_strlower - convert all characters in the string to lowercase
 */
char *mutt_strlower(char *s)
{
  char *p = s;

  while (*p)
  {
    *p = tolower((unsigned char) *p);
    p++;
  }

  return s;
}

/**
 * mutt_strchrnul - find first occurrence of character in string
 * @param s Haystack
 * @param c Needle
 * @retval ptr First occurrence if found or to the NULL character
 *
 * This function is like GNU's strchrnul, which is similar to the standard
 * strchr function: it looks for the c character in the NULL-terminated string
 * s and returns a pointer to its location. If c is not in s, instead of
 * returning NULL like its standard counterpart, this function returns a
 * pointer to the terminating NULL character.
 */
const char *mutt_strchrnul(const char *s, char c)
{
  for (; *s && (*s != c); s++)
    ;
  return s;
}

char *mutt_substrcpy(char *dest, const char *beg, const char *end, size_t destlen)
{
  size_t len;

  len = end - beg;
  if (len > destlen - 1)
    len = destlen - 1;
  memcpy(dest, beg, len);
  dest[len] = 0;
  return dest;
}

char *mutt_substrdup(const char *begin, const char *end)
{
  size_t len;
  char *p = NULL;

  if (end)
    len = end - begin;
  else
    len = strlen(begin);

  p = safe_malloc(len + 1);
  memcpy(p, begin, len);
  p[len] = 0;
  return p;
}

int mutt_strcmp(const char *a, const char *b)
{
  return strcmp(NONULL(a), NONULL(b));
}

int mutt_strcasecmp(const char *a, const char *b)
{
  return strcasecmp(NONULL(a), NONULL(b));
}

int mutt_strncmp(const char *a, const char *b, size_t l)
{
  return strncmp(NONULL(a), NONULL(b), l);
}

int mutt_strncasecmp(const char *a, const char *b, size_t l)
{
  return strncasecmp(NONULL(a), NONULL(b), l);
}

size_t mutt_strlen(const char *a)
{
  return a ? strlen(a) : 0;
}

int mutt_strcoll(const char *a, const char *b)
{
  return strcoll(NONULL(a), NONULL(b));
}

const char *mutt_stristr(const char *haystack, const char *needle)
{
  const char *p = NULL, *q = NULL;

  if (!haystack)
    return NULL;
  if (!needle)
    return haystack;

  while (*(p = haystack))
  {
    for (q = needle;
         *p && *q && tolower((unsigned char) *p) == tolower((unsigned char) *q); p++, q++)
      ;
    if (!*q)
      return haystack;
    haystack++;
  }
  return NULL;
}

char *mutt_skip_whitespace(char *p)
{
  SKIPWS(p);
  return p;
}

void mutt_remove_trailing_ws(char *s)
{
  char *p = NULL;

  for (p = s + mutt_strlen(s) - 1; p >= s && ISSPACE(*p); p--)
    *p = 0;
}

static int mutt_atol(const char *str, long *dst)
{
  long r;
  long *res = dst ? dst : &r;
  char *e = NULL;

  /* no input: 0 */
  if (!str || !*str)
  {
    *res = 0;
    return 0;
  }

  *res = strtol(str, &e, 10);
  if ((*res == LONG_MAX && errno == ERANGE) || (e && *e != '\0'))
    return -1;
  return 0;
}

int mutt_atos(const char *str, short *dst)
{
  int rc;
  long res;
  short tmp;
  short *t = dst ? dst : &tmp;

  *t = 0;

  if ((rc = mutt_atol(str, &res)) < 0)
    return rc;
  if ((short) res != res)
    return -2;

  *t = (short) res;
  return 0;
}

int mutt_atoi(const char *str, int *dst)
{
  int rc;
  long res;
  int tmp;
  int *t = dst ? dst : &tmp;

  *t = 0;

  if ((rc = mutt_atol(str, &res)) < 0)
    return rc;
  if ((int) res != res)
    return -2;

  *t = (int) res;
  return 0;
}

char *strfcpy(char *dest, const char *src, size_t dlen)
{
  char *dest0 = dest;
  while ((--dlen > 0) && (*src != '\0'))
    *dest++ = *src++;

  *dest = '\0';
  return dest0;
}

