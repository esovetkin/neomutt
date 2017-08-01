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

/**
 * safe_strdup - YYY
 * @param s -- const char *
 * @retval char *
 */
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

/**
 * safe_strcat - YYY
 * @param d -- char *
 * @param l -- size_t
 * @param s -- const char *
 * @retval char *
 */
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

/**
 * safe_strncat - YYY
 * @param d  -- char *
 * @param l  -- size_t
 * @param s  -- const char *
 * @param sl -- size_t
 * @retval char *
 */
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

/**
 * mutt_str_replace - YYY
 * @param p -- char **
 * @param s -- const char *
 * @retval void 
 */
void mutt_str_replace(char **p, const char *s)
{
  FREE(p);
  *p = safe_strdup(s);
}

/**
 * mutt_str_adjust - YYY
 * @param p -- char **
 * @retval void 
 */
void mutt_str_adjust(char **p)
{
  if (!p || !*p)
    return;
  safe_realloc(p, strlen(*p) + 1);
}

/**
 * mutt_strlower - convert all characters in the string to lowercase
 */
/**
 * mutt_strlower - YYY
 * @param s -- char *
 * @retval char *
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
/**
 * mutt_strchrnul - YYY
 * @param s -- const char *
 * @param c -- char
 * @retval const char *
 */
const char *mutt_strchrnul(const char *s, char c)
{
  for (; *s && (*s != c); s++)
    ;
  return s;
}

/**
 * mutt_substrcpy - YYY
 * @param dest    -- char *
 * @param beg     -- const char *
 * @param end     -- const char *
 * @param destlen -- size_t
 * @retval char *
 */
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

/**
 * mutt_substrdup - YYY
 * @param begin -- const char *
 * @param end   -- const char *
 * @retval char *
 */
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

/**
 * mutt_strcmp - YYY
 * @param a -- const char *
 * @param b -- const char *
 * @retval int 
 */
int mutt_strcmp(const char *a, const char *b)
{
  return strcmp(NONULL(a), NONULL(b));
}

/**
 * mutt_strcasecmp - YYY
 * @param a -- const char *
 * @param b -- const char *
 * @retval int 
 */
int mutt_strcasecmp(const char *a, const char *b)
{
  return strcasecmp(NONULL(a), NONULL(b));
}

/**
 * mutt_strncmp - YYY
 * @param a -- const char *
 * @param b -- const char *
 * @param l -- size_t
 * @retval int 
 */
int mutt_strncmp(const char *a, const char *b, size_t l)
{
  return strncmp(NONULL(a), NONULL(b), l);
}

/**
 * mutt_strncasecmp - YYY
 * @param a -- const char *
 * @param b -- const char *
 * @param l -- size_t
 * @retval int 
 */
int mutt_strncasecmp(const char *a, const char *b, size_t l)
{
  return strncasecmp(NONULL(a), NONULL(b), l);
}

/**
 * mutt_strlen - YYY
 * @param a -- const char *
 * @retval size_t 
 */
size_t mutt_strlen(const char *a)
{
  return a ? strlen(a) : 0;
}

/**
 * mutt_strcoll - YYY
 * @param a -- const char *
 * @param b -- const char *
 * @retval int 
 */
int mutt_strcoll(const char *a, const char *b)
{
  return strcoll(NONULL(a), NONULL(b));
}

/**
 * mutt_stristr - YYY
 * @param haystack -- const char *
 * @param needle   -- const char *
 * @retval const char *
 */
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

/**
 * mutt_skip_whitespace - YYY
 * @param p -- char *
 * @retval char *
 */
char *mutt_skip_whitespace(char *p)
{
  SKIPWS(p);
  return p;
}

/**
 * mutt_remove_trailing_ws - YYY
 * @param s -- char *
 * @retval void 
 */
void mutt_remove_trailing_ws(char *s)
{
  char *p = NULL;

  for (p = s + mutt_strlen(s) - 1; p >= s && ISSPACE(*p); p--)
    *p = 0;
}

/**
 * mutt_atol - YYY
 * @param str -- const char *
 * @param dst -- long *
 * @retval int 
 */
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

/* strtol() wrappers with range checking; they return
 *       0 success
 *      -1 format error
 *      -2 overflow (for int and short)
 * the int pointer may be NULL to test only without conversion
 */
/**
 * mutt_atos - YYY
 * @param str -- const char *
 * @param dst -- short *
 * @retval int 
 */
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

/* strtol() wrappers with range checking; they return
 *       0 success
 *      -1 format error
 *      -2 overflow (for int and short)
 * the int pointer may be NULL to test only without conversion
 */
/**
 * mutt_atoi - YYY
 * @param str -- const char *
 * @param dst -- int *
 * @retval int 
 */
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

/**
 * strfcpy - YYY
 * @param dest -- char *
 * @param src  -- const char *
 * @param dlen -- size_t
 * @retval char *
 */
char *strfcpy(char *dest, const char *src, size_t dlen)
{
  char *dest0 = dest;
  while ((--dlen > 0) && (*src != '\0'))
    *dest++ = *src++;

  *dest = '\0';
  return dest0;
}

/**
 * skip_email_wsp - Skip over whitespace as defined by RFC5322
 *
 * This is used primarily for parsing header fields.
 */
/**
 * skip_email_wsp - YYY
 * @param s -- const char *
 * @retval char *
 */
char *skip_email_wsp(const char *s)
{
  if (s)
    return (char *) (s + strspn(s, EMAIL_WSP));
  return (char *) s;
}

/**
 * is_email_wsp - YYY
 * @param c -- char
 * @retval int 
 */
int is_email_wsp(char c)
{
  return c && (strchr(EMAIL_WSP, c) != NULL);
}
