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

#ifndef _LIB_STRING_H
#define _LIB_STRING_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define HUGE_STRING  8192
#define LONG_STRING  1024
#define STRING       256
#define SHORT_STRING 128

#define NONULL(x) x ? x : ""

#define ISSPACE(c) isspace((unsigned char) c)

/* this macro must check for *c == 0 since isspace(0) has unreliable behavior
   on some systems */
#define SKIPWS(c)                                                              \
  while (*(c) && isspace((unsigned char) *(c)))                                \
    c++;

#define EMAIL_WSP " \t\r\n"

/**
 * skip_email_wsp - Skip over whitespace as defined by RFC5322
 *
 * This is used primarily for parsing header fields.
 */
static inline char *skip_email_wsp(const char *s)
{
  if (s)
    return (char *) (s + strspn(s, EMAIL_WSP));
  return (char *) s;
}

static inline int is_email_wsp(char c)
{
  return c && (strchr(EMAIL_WSP, c) != NULL);
}

char *safe_strcat(char *d, size_t l, const char *s);
char *safe_strncat(char *d, size_t l, const char *s, size_t sl);
char *safe_strdup(const char *s);
void mutt_str_replace(char **p, const char *s);
void mutt_str_adjust(char **p);
char *mutt_strlower(char *s);
const char *mutt_strchrnul(const char *s, char c);
char *mutt_substrcpy(char *dest, const char *beg, const char *end, size_t destlen);
char *mutt_substrdup(const char *begin, const char *end);
int mutt_strcasecmp(const char *a, const char *b);
int mutt_strcmp(const char *a, const char *b);
int mutt_strncasecmp(const char *a, const char *b, size_t l);
int mutt_strncmp(const char *a, const char *b, size_t l);
int mutt_strcoll(const char *a, const char *b);
size_t mutt_strlen(const char *a);
const char *mutt_stristr(const char *haystack, const char *needle);
char *mutt_skip_whitespace(char *p);
char *strfcpy(char *dest, const char *src, size_t dlen);
void mutt_remove_trailing_ws(char *s);

/* strtol() wrappers with range checking; they return
 *       0 success
 *      -1 format error
 *      -2 overflow (for int and short)
 * the int pointer may be NULL to test only without conversion
 */
int mutt_atos(const char *str, short *dst);
int mutt_atoi(const char *str, int *dst);

#endif /* _LIB_STRING_H */
