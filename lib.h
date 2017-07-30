/**
 * @file
 * Some very miscellaneous functions
 *
 * @authors
 * Copyright (C) 1996-2000,2007,2010,2012 Michael R. Elkins <me@mutt.org>
 * Copyright (C) 1999-2005,2007 Thomas Roessler <roessler@does-not-exist.org>
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

/* mutt functions which are generally useful. */

#ifndef _MUTT_LIB_H
#define _MUTT_LIB_H

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

/* Use this with care.  If the compiler can't see the array
 * definition, it obviously won't produce a correct result. */
#define mutt_array_size(x) (sizeof(x) / sizeof((x)[0]))

/* For mutt_simple_format() justifications */
/* Making left 0 and center -1 is of course completely nonsensical, but
 * it retains compatibility for any patches that call mutt_simple_format.
 * Once patches are updated to use FMT_*, these can be made sane. */
#define FMT_LEFT   0
#define FMT_RIGHT  1
#define FMT_CENTER -1

/* Exit values used in send_msg() */
#define S_ERR 127
#define S_BKG 126

int safe_asprintf(char **, const char *, ...);

void mutt_nocurses_error(const char *, ...);
int mutt_inbox_cmp(const char *a, const char *b);

const char *mutt_strsysexit(int e);

#endif /* _MUTT_LIB_H */
